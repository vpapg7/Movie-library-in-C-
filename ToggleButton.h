#pragma once

#include "Widget.h"
#include "PlaceableTrait.h"
#include "RenderableTrait.h"
#include "SizableTrait.h"
#include "ClickableTrait.h"
#include "ReadableTrait.h"

/// <summary>
/// ToggleButton widget displays a toggle and a label
/// </summary>
class ToggleButton : public Widget, public ClickableTrait, public RenderableTrait, public ReadableTrait {
private:
	bool enabled = false;
public:

	ToggleButton();

	virtual void draw();
	virtual void update(float ms);

	virtual bool selfUpdate(Widget* src, const Point& origin);
};

