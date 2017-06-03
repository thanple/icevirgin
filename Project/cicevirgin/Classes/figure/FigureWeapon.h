
#pragma once
#include "IFigure.h"

namespace CharacterFigure
{
	class FigureWeapon : public IFigure
	{
	public:
		CREATE_FUNC(FigureWeapon);

		virtual string getPath()
		{
			return ResourceProvider::Weapon::PATH(figureId);
		}

		virtual void setFigureId(int figureId)
		{
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
				ResourceProvider::Weapon::PLIST_PATH(figureId));
			this->figureId = figureId;
		}
	};

};