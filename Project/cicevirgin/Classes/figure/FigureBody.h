
#pragma once
#include "IFigure.h"


namespace CharacterFigure
{
	class FigureBody : public IFigure
	{
	public:
		CREATE_FUNC(FigureBody);

		virtual string getPath()
		{
			return ResourceProvider::Character::PATH(figureId);
		}

		virtual void setFigureId(int figureId)
		{
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
				ResourceProvider::Character::PLIST_PATH(figureId));
			this->figureId = figureId;
		}
	};
};
