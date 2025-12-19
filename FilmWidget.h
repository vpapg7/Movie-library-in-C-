#pragma once

#include <string>

#include "Widget.h"
#include "PlaceableTrait.h"
#include "RenderableTrait.h"
#include "SizableTrait.h"
#include "ClickableTrait.h"
#include "Database.h"

#include "Widget.h"

#include <sgg/graphics.h>

/// <summary>
/// FilmWidget displays the cover of a movie
/// </summary>
class FilmWidget : public Widget, public ClickableTrait, public RenderableTrait {
private:
	const Database& database;
	graphics::Brush mirrorBrush;

	int offset = 0;
public:

	FilmWidget(const Database& database, int offset);

	virtual void draw();
	virtual void update(float ms);

	/// <summary>
	/// Returns the offset of the selected movie
	/// </summary>
	/// <returns>offset (excluding shift)</returns>
	int getOffset() const;
};

