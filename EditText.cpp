#include "EditText.h"

static EditText* focused = nullptr;

EditText::EditText() {
	textbox_brush = RenderableTrait::brush;

	textbox_brush.fill_color[0] = 0.2f;
	textbox_brush.fill_color[1] = 0.2f;
	textbox_brush.fill_color[2] = 0.2f;

	textbox_brush.fill_secondary_color[0] = 1.0f;
	textbox_brush.fill_secondary_color[1] = 1.0f;
	textbox_brush.fill_secondary_color[2] = 1.0f;

	textbox_brush.fill_opacity = 1.0f;
	textbox_brush.fill_secondary_opacity = 1.0f;

	textbox_brush.outline_opacity = 1.0f;

	scale_clickable_area_right = 10.0f;
	scale_clickable_area_top = 2.0f;
	scale_clickable_area_bottom = 2.0f;


}

void EditText::draw() {
	graphics::setFont(ReadableTrait::font);

	graphics::drawText(PlaceableTrait::coordinates.x - SizableTrait::width/2+1, PlaceableTrait::coordinates.y + 0.5f, ReadableTrait::size, ReadableTrait::text, RenderableTrait::brush);

	graphics::drawRect(PlaceableTrait::coordinates.x, PlaceableTrait::coordinates.y, SizableTrait::width, SizableTrait::height, textbox_brush);
}

void EditText::update(float ms) {
	if (focused == this) {
		textbox_brush.outline_color[0] = 1.0f;
		textbox_brush.outline_color[1] = 1.0f;
		textbox_brush.outline_color[2] = 0.0f;
	} else {
		textbox_brush.outline_color[0] = 0.8f;
		textbox_brush.outline_color[1] = 0.8f;
		textbox_brush.outline_color[2] = 0.8f;

	}
}

bool EditText::selfUpdate(Widget* src, const Point& origin) {
	focused = this;
	return true;
}

void EditText::key_press(string key) {
	if (key == "#") {
		if (ReadableTrait::text == "") {
			return;
		} else {
			ReadableTrait::text = ReadableTrait::text.substr(0, ReadableTrait::text.length() - 1);
		}
	} else {
		ReadableTrait::text += key;
	}
}

EditText* getFocusedEditText() {
	return focused;
}
