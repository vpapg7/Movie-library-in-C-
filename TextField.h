#pragma once

#include "Widget.h"

#include "Widget.h"
#include "PlaceableTrait.h"
#include "RenderableTrait.h"
#include "ReadableTrait.h"
#include "SizableTrait.h"
#include "ClickableTrait.h"


/// <summary>
/// TextField widget displays simple text
/// </summary>
class TextField : public Widget, public PlaceableTrait, public RenderableTrait, public ReadableTrait {
public:
	TextField();

	virtual void draw();
	virtual void update(float ms);
};

