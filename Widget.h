#pragma once

#include <list>

#include <sgg/graphics.h>

/// <summary>
/// Base class for all widgets.
///
/// </summary>
class Widget {
public:
	virtual void draw();
	virtual void update(float ms);

};

