
#pragma once
#include "Common.h"

typedef short M_INT;
class MapPoint {

public:

	M_INT x;

	M_INT z;

public:

	MapPoint();

	MapPoint(M_INT x, M_INT z);

	virtual ~MapPoint();

	MapPoint(const CCPoint& point);

	CCPoint getCCPointValue() const;

	CCSize getCCSizeValue() const;

	MapPoint(int value);

	int getValue() const;

	MapPoint& operator= (const MapPoint& other);

	MapPoint operator+(const MapPoint& right) const;

	MapPoint operator-(const MapPoint& right) const;

	MapPoint operator-() const;

	MapPoint operator*(M_INT a) const;

	MapPoint operator/(M_INT a) const;

	bool operator< (const MapPoint& other) const;

	bool operator== (const MapPoint& other) const;

	bool equals(const MapPoint& target) const;

	inline M_INT getLength() const
	{
		return (M_INT)MAX(fabsf(x), fabsf(z));
	}

	inline M_INT getDistance(const MapPoint& other) const
	{
		return (M_INT)MAX(fabsf(other.x - this->x), fabsf(other.z - this->z));
	}

	std::vector<MapPoint> getMapPointVectorForDistance(M_INT lenght) const;

public:

	static void setGridSize(CCSize size);

};

const MapPoint MapPointZero = MapPoint();

#define mapAdd(_A_, _B_) MapPoint(((_A_).x + (_B_).x), ((_A_).z + (_B_).z))
#define mapSub(_A_, _B_) MapPoint(((_A_).x - (_B_).x), ((_A_).z - (_B_).z))

