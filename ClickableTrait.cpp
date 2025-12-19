#include "Widget.h"
#include "Point.h"
#include "ClickableTrait.h"

bool ClickableTrait::onClick(Widget* src, const Point& origin) {
	float x = origin.x;
	float y = origin.y;

	if (x >= this->coordinates.x - scale_clickable_area_left * this->width / 2 && x <= this->coordinates.x + scale_clickable_area_right * this->width / 2) {
		if (y >= this->coordinates.y - scale_clickable_area_top * this->height / 2 && y <= this->coordinates.y + scale_clickable_area_bottom * this->height / 2) {
			if (callback != nullptr) {
				graphics::playSound(sound, 1, false);
				callback(src, this);				
			}
			selfUpdate(src, origin);

			return true;
		}
	}
	return false;
}

bool ClickableTrait::selfUpdate(Widget* src, const Point& origin) {
	return false;
}
