

#pragma once
#include "Common.h"
#include "figure\IFigure.h"
#include "state\IState.h"

class Monster : public IFigure
{

public:

	//״̬��������
	CC_SYNTHESIZE(IState *, m_pState, IState);
	void setIState(CharacterStateType stateType);

	//����������
	CC_SYNTHESIZE_READONLY(CharacterDirectionType, m_directionType, DirectionType);	//����
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
	CCActionInterval * createFigureActionsFromCache(std::string path);	//����֫�嶯��, pathΪ·��/�ļ�
};