
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

	//一些变量的初始化
	m_pState = CharacterState::CharacterStateProvider::getInstance()->getStateFromType(CharacterStateType::FStateStand);
	m_directionType = FDirRight;

	return true;
}

void Monster::updateFigureActions()
{

	//首先停止所有动作
	this->stopActionByTag(TAG_ANIMATE);

	//获取动作
	CCActionInterval * actions = this->createFigureActionsFromCache(this->getPath());
	//执行，并且加上标志
	if (NULL != actions)
	{
		//执行完动作后保持站立
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
		//朝向为左的序列帧全部按右加载
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
	this->updateFigureActions();	//更新肢体动作
}

void Monster::setDirectionType(CharacterDirectionType dirType)
{
	do
	{
		//考虑方向是否改变
		CC_BREAK_IF(m_directionType == dirType);

		//考虑是否需要对称显示序列帧
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