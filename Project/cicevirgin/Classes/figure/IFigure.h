
#pragma once
#include "Common.h"

/**
* �����幹�����г��󣬱���ͷ��������������ȵ�
**/
class IFigure : public Sprite
{
public:
	CC_SYNTHESIZE_READONLY(int, figureId, FigureId);

	//�麯��-����figureId��ȡ·��
	virtual string getPath() = 0;

};