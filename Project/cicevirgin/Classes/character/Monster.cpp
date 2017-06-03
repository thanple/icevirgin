
#include "Monster.h"
#include "state\CharacterStateProvider.h"

Monster::Monster()
{

}
Monster::~Monster()
{

}

bool Monster::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	//һЩ�����ĳ�ʼ��
	m_pState = CharacterState::CharacterStateProvider::getInstance()->getStateFromType(CharacterStateType::FStateStand);
	m_directionType = FDirRight;

	return true;
}

void Monster::updateFigureActions()
{

	//����ֹͣ���ж���
	this->stopActionByTag(TAG_ANIMATE);

	//��ȡ����
	CCActionInterval * actions = this->createFigureActionsFromCache(this->getPath());
	//ִ�У����Ҽ��ϱ�־
	if (NULL != actions)
	{
		//ִ���궯���󱣳�վ��
		if (this->getIState() == CharacterState::CharacterStateProvider::getInstance()->getStateFromType(CharacterStateType::FStateAttack)
			 )
		{
			actions = CCSequence::create((ActionInterval *)actions, CallFunc::create([this](){
				this->setIState(CharacterStateType::FStateStand);
			}), NULL);
		}
		else if (this->getIState() == CharacterState::CharacterStateProvider::getInstance()->getStateFromType(CharacterStateType::FStateRun)
			|| this->getIState() == CharacterState::CharacterStateProvider::getInstance()->getStateFromType(CharacterStateType::FStateHurt))
		{
			actions = RepeatForever::create(actions);
		}

		actions->setTag(TAG_ANIMATE);
		this->runAction(actions);
	}


}



CCActionInterval * Monster::createFigureActionsFromCache(std::string path)
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


void Monster::setIState(CharacterStateType stateType)
{
	m_pState = CharacterState::CharacterStateProvider::getInstance()->getStateFromType(stateType);
	this->updateFigureActions();	//����֫�嶯��
}

void Monster::setDirectionType(CharacterDirectionType dirType)
{
	do
	{
		//���Ƿ����Ƿ�ı�
		CC_BREAK_IF(m_directionType == dirType);

		//�����Ƿ���Ҫ�Գ���ʾ����֡
		bool needFlipX = (8 > dirType) && (dirType > 4);
		this->setFlippedX(needFlipX);

		this->m_directionType = dirType;
		this->updateFigureActions();

	} while (0);

}


string Monster::getPath()
{
	return ResourceProvider::Monster::PATH(figureId);
}

void Monster::setFigureId(int figureId)
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Monster::PLIST_PATH(figureId));
	this->figureId = figureId;
}