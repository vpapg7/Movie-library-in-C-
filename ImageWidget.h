#pragma once

#include <string>
#include "Widget.h"
#include "PlaceableTrait.h"
#include "RenderableTrait.h"
#include "SizableTrait.h"

/// <summary>
/// Image widget displays a static image
/// </summary>
class ImageWidget : public Widget, public PlaceableTrait, public SizableTrait, public RenderableTrait {
public:
	ImageWidget(std::string texture);

	virtual void draw();
};

