#include "TextField.h"

TextField::TextField() {
	RenderableTrait::brush.fill_color[0] = 1.0f;
	RenderableTrait::brush.fill_color[1] = 1.0f;
	RenderableTrait::brush.fill_color[2] = 1.0f;

	RenderableTrait::brush.fill_secondary_color[0] = 1.0f;
	RenderableTrait::brush.fill_secondary_color[1] = 1.0f;
	RenderableTrait::brush.fill_secondary_color[2] = 1.0f;

	RenderableTrait::brush.fill_opacity = 1.0f;
	RenderableTrait::brush.fill_secondary_opacity = 1.0f;

	RenderableTrait::brush.outline_opacity = 1.0f;
}

void TextField::draw() {
	graphics::setFont(ReadableTrait::font);

	graphics::drawText(PlaceableTrait::coordinates.x, PlaceableTrait::coordinates.y, ReadableTrait::size, ReadableTrait::text, RenderableTrait::brush);
}

void TextField::update(float ms) {

}
