
#include "Character.h"
#include "state\CharacterRun.h"

Character::Character()
{
	roleId = -1;
}
Character::~Character()
{

}

bool Character::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	//һЩ�����ĳ�ʼ��
	m_pState = CharacterState::CharacterStateProvider::getInstance()->getStateFromType(CharacterStateType::FStateStand);
	m_directionType = FDirRight;

	//��ʼ������IFigure
	pBody = FigureBody::create();
	pHair = FigureHair::create();
	pWeapon = FigureWeapon::create();

	figures.push_back(pBody);
	this->addChild(pBody);

	figures.push_back(pHair);
	this->addChild(pHair);

	figures.push_back(pWeapon);
	this->addChild(pWeapon);

	return true;
}

void Character::updateFigureActions()
{
	//����figureִ�ж���
	list<IFigure *>::iterator figuresIterator;
	for (figuresIterator = figures.begin(); figuresIterator != figures.end(); figuresIterator++)
	{
		IFigure * iFigure = *figuresIterator;

		//����ֹͣ���ж���
		iFigure->stopActionByTag(TAG_ANIMATE);

		//��ȡ����
		CCActionInterval * figureAnimate = this->createFigureActionsFromCache(iFigure->getPath());
		Action * actions = m_pState->createActionFromAnimate(figureAnimate);
		
		//ִ�У����Ҽ��ϱ�־
		if (NULL != actions)
		{

			//ִ���궯���󱣳�վ��
			if (this->getIState() == CharacterState::CharacterStateProvider::getInstance()->getStateFromType(CharacterStateType::FStateAttack)
				|| this->getIState() == CharacterState::CharacterStateProvider::getInstance()->getStateFromType(CharacterStateType::FStateHurt)
				)
			{
				actions = CCSequence::create((ActionInterval *)actions, CallFunc::create([this](){
					this->setIState(CharacterStateType::FStateStand);
				}), NULL);
			}

			actions->setTag(TAG_ANIMATE);
			iFigure->runAction(actions);
		}

	}

}

void Character::runActions(ActionInterval * moveAction)
{
	list<IFigure *>::iterator figuresIterator;
	for (figuresIterator = figures.begin(); figuresIterator != figures.end(); figuresIterator++)
	{
		IFigure * iFigure = *figuresIterator;
		iFigure->runAction(moveAction);
	}
}

void Character::setIState(CharacterStateType stateType)
{
	m_pState = CharacterState::CharacterStateProvider::getInstance()->getStateFromType(stateType);
	this->updateFigureActions();	//����֫�嶯��

	CCLOG("[player state changed] state=%d", stateType);
}

void Character::setDirectionType(CharacterDirectionType dirType)
{
	do
	{
		//���Ƿ����Ƿ�ı�
		CC_BREAK_IF(m_directionType == dirType);

		//�����Ƿ���Ҫ�Գ���ʾ����֡
		list<IFigure *>::iterator figuresIterator;
		for (figuresIterator = figures.begin(); figuresIterator != figures.end(); figuresIterator++)
		{
			bool needFlipX = (8 > dirType) && (dirType > 4);
			IFigure * iFigure = * figuresIterator;
			iFigure->setFlippedX(needFlipX);
		}
		this->m_directionType = dirType;
		this->updateFigureActions();

		CCLOG("[player direction changed] direction=%d", dirType);

	} while (0);
	
}


CCActionInterval * Character::createFigureActionsFromCache(std::string path)
{
	Vector<SpriteFrame *> spriteFrames;
	int flag = 0;
	do
	{
		//����Ϊ�������֡ȫ�����Ҽ���
		int dirType = m_directionType;
		if (8 > dirType && dirType > 4)
		{
			dirType = 8 - dirType;
		}

		CCString * string = CCString::createWithFormat("%s_%d_%d_%02d.png", path.c_str(), m_pState->getStateType(), dirType, flag);
		CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(string->getCString());
		CC_BREAK_IF(spriteFrame == NULL);

		spriteFrames.pushBack(spriteFrame);
		flag++;
	} while (1);
	
	CCAnimation* movie = CCAnimation::createWithSpriteFrames(spriteFrames, m_pState->getFrameRate());
	CCAnimate* animate = CCAnimate::create(movie);
	return animate;
}

Vector<FiniteTimeAction *> Character::actionsWithMoveTo(std::deque<MapPoint> & pArray)
{
	Vector<FiniteTimeAction *> array;
	do
	{
		CC_BREAK_IF(pArray.size() <= 1);

		//����һ������
		for (std::deque<MapPoint>::iterator itr = (pArray.begin() + 1); itr != pArray.end(); itr++)
		{
			MapPoint pStart = *(itr - 1);
			MapPoint pFinish = *itr;
			array.pushBack(this->actionsWithPoint(pStart, pFinish));
		}

		//֮����վ��
		array.pushBack(CCCallFunc::create([this](){
			this->setIState(CharacterStateType::FStateStand);
		}));

	} while (0);

	return array;
}


Vector<FiniteTimeAction *> Character::actionsWithPoint(MapPoint& pStart, MapPoint& pFinish)
{
	Vector<FiniteTimeAction *> array;

	if (pStart.equals(pFinish))
		return array;

	M_INT lenghtX = pFinish.x - pStart.x;
	M_INT lenghtY = pFinish.z - pStart.z;
	float lenght = sqrtf(lenghtX * lenghtX + lenghtY * lenghtY);

	float pointX = lenghtX / lenght;
	float pointY = lenghtY / lenght;

	float angle_X = acosf(pointX) * 180 / M_PI;
	float angle_Y = acosf(pointY) * 180 / M_PI;

	float angle = angle_X;
	if (angle_Y > 90)
	{
		angle = 360 - angle_X;
	}

	//������
	int type = (((int)(angle + 22.5)) % 360) / 45.0f;
	array.pushBack(CCCallFunc::create([this,type](){
		int dt = 10 - type;
		if (dt > 8)	dt -= 8;
		CharacterDirectionType ct = CharacterDirectionType(dt);
		this->setDirectionType(ct);
		
	}));

	//�ƶ�����
	float time = lenght * m_pState->getFrameRate() * 8;
	CCMoveTo * moveTo = CCMoveTo::create(time, pFinish.getCCPointValue());
	array.pushBack(moveTo);

	//���½�ɫ����
	array.pushBack(CCCallFunc::create([this, pFinish](){
		this->setPosition(pFinish.getCCPointValue());

		CCLOG("[player moving] mappoint={%d,%d}", pFinish.x, pFinish.z);
	}));

	return array;
}