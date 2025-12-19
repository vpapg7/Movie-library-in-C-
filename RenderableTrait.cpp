#include "RenderableTrait.h"

RenderableTrait::RenderableTrait() {
	brush.fill_color[0] = 1.0f;
	brush.fill_color[1] = 1.0f;
	brush.fill_color[2] = 1.0f;
	brush.fill_opacity = 1.0f;
	brush.outline_opacity = 0.0f;
}
