#pragma once

#include <string>

#include "Widget.h"
#include "PlaceableTrait.h"
#include "RenderableTrait.h"
#include "SizableTrait.h"
#include "ClickableTrait.h"

/// <summary>
/// ImageButtonWidget.
/// Displays any image that can be clicked
/// </summary>
class ImageButtonWidget : public Widget, public ClickableTrait, public RenderableTrait {
public:
	ImageButtonWidget(std::string texture);

	virtual void draw();
	virtual void update(float ms);
};

