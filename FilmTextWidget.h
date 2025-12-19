#pragma once

#include "Widget.h"

#include "Widget.h"
#include "PlaceableTrait.h"
#include "RenderableTrait.h"
#include "ReadableTrait.h"
#include "SizableTrait.h"
#include "ClickableTrait.h"
#include "Database.h"

/// <summary>
/// Film text widget. Displays the text of a film
/// </summary>
class FilmTextWidget : public Widget, public PlaceableTrait, public RenderableTrait, public ReadableTrait {
private:
	const Database& database;
	int attribute_id;
public:
	FilmTextWidget(const Database& database, int attribute_id);

	virtual void draw();
	virtual void update(float ms);
};

