#include "ToggleButton.h"

ToggleButton::ToggleButton() {
	RenderableTrait::brush.fill_color[0] = 1.0f;
	RenderableTrait::brush.fill_color[1] = 1.0f;
	RenderableTrait::brush.fill_color[2] = 1.0f;

	RenderableTrait::brush.fill_secondary_color[0] = 1.0f;
	RenderableTrait::brush.fill_secondary_color[1] = 1.0f;
	RenderableTrait::brush.fill_secondary_color[2] = 1.0f;

	RenderableTrait::brush.fill_opacity = 1.0f;
	RenderableTrait::brush.fill_secondary_opacity = 1.0f;

	RenderableTrait::brush.outline_opacity = 1.0f;

	scale_clickable_area_right = 10.0f;
	scale_clickable_area_top = 2.0f;
	scale_clickable_area_bottom = 2.0f;
}

void ToggleButton::draw() {
	graphics::setFont(ReadableTrait::font);

	graphics::drawText(PlaceableTrait::coordinates.x + 0.8f, PlaceableTrait::coordinates.y + 0.5f, ReadableTrait::size, ReadableTrait::text, RenderableTrait::brush);

	graphics::drawRect(PlaceableTrait::coordinates.x, PlaceableTrait::coordinates.y, SizableTrait::width, SizableTrait::height, RenderableTrait::brush);
}

void ToggleButton::update(float ms) {
	if (enabled) {
		RenderableTrait::brush.fill_color[0] = 0.0f;
		RenderableTrait::brush.fill_color[1] = 1.0f;
		RenderableTrait::brush.fill_color[2] = 0.0f;
	} else {
		RenderableTrait::brush.fill_color[0] = 1.0f;
		RenderableTrait::brush.fill_color[1] = 1.0f;
		RenderableTrait::brush.fill_color[2] = 1.0f;

	}
}

bool ToggleButton::selfUpdate(Widget* src, const Point& origin) {
	enabled = !enabled;
	return enabled;
}
