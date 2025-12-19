#include "FilmTextWidget.h"

FilmTextWidget::FilmTextWidget(const Database& database, int attribute_id) : database(database), attribute_id(attribute_id) {
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

void FilmTextWidget::draw() {
	graphics::setFont(ReadableTrait::font);
	
	const Film* film = database.getSelectedFilm();

	if (film != nullptr) {
		string text = "unknown attribute id";

		if (attribute_id == 1) {
			text = film->title + " (" + std::to_string(film->year) + ")";
		}

		if (attribute_id == 2) {
			text = film->genres_str;
		}

		if (attribute_id == 3) {
			text = film->directors_str;
		}

		if (attribute_id == 4) {
			text = film->cast_str;
		}

		if (attribute_id >= 5) {
			int c = attribute_id - 5;

			text = "";

			if (c < film->synopsis.size()) {
				text = film->synopsis[c];
			}
		}
		
		graphics::drawText(PlaceableTrait::coordinates.x, PlaceableTrait::coordinates.y, ReadableTrait::size, text, RenderableTrait::brush);
	}	
}

void FilmTextWidget::update(float ms) {

}
