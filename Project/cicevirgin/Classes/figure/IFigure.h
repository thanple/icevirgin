
#pragma once
#include "Common.h"

/**
* 对身体构建进行抽象，比如头发，武器，身体等等
**/
class IFigure : public Sprite
{
public:
	CC_SYNTHESIZE_READONLY(int, figureId, FigureId);

	//虚函数-根据figureId获取路径
	virtual string getPath() = 0;

};