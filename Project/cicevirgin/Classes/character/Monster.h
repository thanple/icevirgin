

#pragma once
#include "Common.h"
#include "figure\IFigure.h"
#include "state\IState.h"

class Monster : public IFigure
{

public:

	//状态及其设置
	CC_SYNTHESIZE(IState *, m_pState, IState);
	void setIState(CharacterStateType stateType);

	//方向及其设置
	CC_SYNTHESIZE_READONLY(CharacterDirectionType, m_directionType, DirectionType);	//方向
	void setDirectionType(CharacterDirectionType dirType);

public:
	CREATE_FUNC(Monster);
	bool init();
	Monster();
	~Monster();
	void Monster::updateFigureActions();
	virtual string getPath();
	virtual void setFigureId(int figureId);

private:
	CCActionInterval * createFigureActionsFromCache(std::string path);	//创建肢体动作, path为路径/文件
};