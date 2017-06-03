
#pragma once
#include "Common.h"
#include "state\IState.h"
#include "state\CharacterStateProvider.h"
#include "util\ResourceProvider.h"

#include "figure\FigureBody.h"
#include "figure\FigureHair.h"
#include "figure\FigureWeapon.h"
using namespace CharacterFigure;

#include "map\MapPoint.h"


#include "protocol\SRequestUserInfo.pb.h"

class Character : public Sprite
{

public:
	//所有Figure
	FigureBody * pBody;
	FigureHair * pHair;
	FigureWeapon * pWeapon;
	list<IFigure *> figures;

	CC_SYNTHESIZE(int, roleId, RoleId);

public:
	CREATE_FUNC(Character);
	Character();
	~Character();

	//状态及其设置
	CC_SYNTHESIZE(IState *, m_pState, IState);	
	void setIState(CharacterStateType stateType);

	//方向及其设置
	CC_SYNTHESIZE_READONLY(CharacterDirectionType, m_directionType, DirectionType);	//方向
	void setDirectionType(CharacterDirectionType dirType);

public:
	void updateFigureActions();		//更新肢体动作
	void runActions(ActionInterval *);	//执行动作
	virtual bool init();
	virtual Vector<FiniteTimeAction *> actionsWithMoveTo(std::deque<MapPoint> & pArray);
	virtual Vector<FiniteTimeAction *> actionsWithPoint(MapPoint& pStart, MapPoint& pFinish);

private:
	CCActionInterval * createFigureActionsFromCache(std::string path);	//创建肢体动作, path为路径/文件
};