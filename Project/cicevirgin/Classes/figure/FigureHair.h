
#pragma once
#include "IFigure.h"

namespace CharacterFigure
{
	class FigureHair : public IFigure
	{
	public:
		CREATE_FUNC(FigureHair);

		virtual string getPath()
		{
			return ResourceProvider::Hair::PATH(figureId);
		}

		virtual void setFigureId(int figureId)
		{
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
				ResourceProvider::Hair::PLIST_PATH(figureId));
			this->figureId = figureId;
		}
	};
};
