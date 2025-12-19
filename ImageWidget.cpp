#include "ImageWidget.h"

ImageWidget::ImageWidget(std::string texture) {
	RenderableTrait::brush.texture = texture;
}

void ImageWidget::draw() {
	graphics::drawRect(PlaceableTrait::coordinates.x, PlaceableTrait::coordinates.y, SizableTrait::width, SizableTrait::height, RenderableTrait::brush);
}
