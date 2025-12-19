#pragma once

#include "Point.h"
#include "Trait.h"

/// <summary>
/// Placable widgets have this trait if they can be placed in screen
/// </summary>
class PlaceableTrait : public Trait {
public:
	Point coordinates;	

	void place(float x, float y);
};

