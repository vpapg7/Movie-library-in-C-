#pragma once

#include "Trait.h"


/// <summary>
/// Sizeable widgets contain size
/// </summary>
class SizableTrait : public Trait {
public:
	float width, height;

	void scale(float width, float height);
};

