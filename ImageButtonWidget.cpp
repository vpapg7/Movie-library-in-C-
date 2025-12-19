#include "ImageButtonWidget.h"


ImageButtonWidget::ImageButtonWidget(std::string texture) {
	RenderableTrait::brush.texture = texture;
}

void ImageButtonWidget::draw() {
	graphics::drawRect(PlaceableTrait::coordinates.x, PlaceableTrait::coordinates.y, SizableTrait::width, SizableTrait::height, RenderableTrait::brush);
}

void ImageButtonWidget::update(float ms) {

}
