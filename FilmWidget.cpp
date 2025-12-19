#include "FilmWidget.h"

FilmWidget::FilmWidget(const Database& database, int offset) : database(database), offset(offset) {
	const Film* film = database.getFilm(offset);

	if (film != nullptr) {
		RenderableTrait::brush.texture = film->texture;
	}

	RenderableTrait::brush.outline_width = 2;
	RenderableTrait::brush.outline_color[0] = 1.0f;
	RenderableTrait::brush.outline_color[1] = 1.0f;
	RenderableTrait::brush.outline_color[2] = 0.0f;

	mirrorBrush = RenderableTrait::brush;
	mirrorBrush.fill_opacity = 0.01f;
	mirrorBrush.gradient = true;
}

void FilmWidget::draw() {
	const Film* film = database.getFilm(offset);

	if (film != nullptr) {				
		graphics::setOrientation(180);		
		graphics::drawRect(PlaceableTrait::coordinates.x, PlaceableTrait::coordinates.y + SizableTrait::height + 1, SizableTrait::width, SizableTrait::height, mirrorBrush);

		graphics::setOrientation(0);

		graphics::drawRect(PlaceableTrait::coordinates.x, PlaceableTrait::coordinates.y, SizableTrait::width + 1, SizableTrait::height, RenderableTrait::brush);

	}

}

void FilmWidget::update(float ms) {
	const Film* film = database.getFilm(offset);

	if (film != nullptr) {		
		RenderableTrait::brush.texture = film->texture;		
		mirrorBrush.texture = film->texture;

		if (offset == database.selected) {
			RenderableTrait::brush.outline_opacity = 1.0f;
		} else {
			RenderableTrait::brush.outline_opacity = 0.0f;
		}

	}

}

int FilmWidget::getOffset() const {
	const Film* film = database.getFilm(offset);

	if (film != nullptr) {
		return offset;
	}

	return -1;
}


