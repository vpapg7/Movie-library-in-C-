#include <iostream>
#include <iomanip>

#include "MovieStorm.h"
#include "ImageWidget.h"
#include "ImageButtonWidget.h"
#include "FilmWidget.h"
#include "TextField.h"
#include "EditText.h"
#include "FilmTextWidget.h"
#include "ToggleButton.h"

using namespace std;


static MovieStorm * global_storm;

void MovieStorm::refreshFilters() {
	env.database.applyFilters(filters);
}

MovieStorm::MovieStorm(const Environment& env) : env(env), builder() {
	const Config& config = env.config;	
	global_storm = this;

	void (*onExit)(Widget * src, void* evt) = [](Widget * src, void* evt) { graphics::stopMessageLoop(); };
	void (*onNext)(Widget * src, void* evt) = [](Widget* src, void* evt) { global_storm->next(); };
	void (*onPrevious)(Widget * src, void* evt) = [](Widget* src, void* evt) { global_storm->previous(); };
	void (*onSelectMovie)(Widget * src, void* evt) = [](Widget* src, void* evt) { global_storm->selectMovie((FilmWidget*)src); };
	void (*onYearClick)(Widget * src, void* evt) = [](Widget* src, void* evt) { global_storm->toggleYear(((ToggleButton*)src)->text); };
	void (*onGenreClick)(Widget * src, void* evt) = [](Widget* src, void* evt) { global_storm->toggleGenre(((ToggleButton*)src)->text); };
	void (*onEditTextClick)(Widget * src, void* evt) = [](Widget* src, void* evt) { global_storm->toggleGenre(((ToggleButton*)src)->text); };
	void (*onSearch)(Widget * src, void* evt) = [](Widget* src, void* evt) { global_storm->search(); };

	ImageWidget * logo = new ImageWidget(config.asset("logo.png"));
	builder.place(*logo, 50, 6).scale(*logo, 75, 9);

	ImageButtonWidget* exitButton = new ImageButtonWidget(config.asset("exit.png"));
	builder.place(*exitButton, 98, 6).scale(*exitButton, 5, 5).activate(*exitButton, onExit, config.asset("close.wav"));

	ImageButtonWidget* previousButton = new ImageButtonWidget(config.asset("left.png"));
	builder.place(*previousButton, 10, 50).scale(*previousButton, 5, 5).activate(*previousButton, onPrevious, config.asset("close.wav"));

	ImageButtonWidget* nextButton = new ImageButtonWidget(config.asset("right.png"));
	builder.place(*nextButton, 90, 50).scale(*nextButton, 5, 5).activate(*nextButton, onNext, config.asset("close.wav"));

	ImageButtonWidget* searchButton = new ImageButtonWidget(config.asset("search.png"));
	builder.place(*searchButton, 98, 85).scale(*searchButton, 3, 3).activate(*searchButton, onSearch, config.asset("select_movie.wav"));

	for (int i = 0; i < 5; i++) {
		FilmWidget* widget = new FilmWidget(env.database, i);
		builder.place(*widget, 10 + 20.0f*i, 28).scale(*widget, 12, 16).activate(*widget, onSelectMovie, config.asset("select_movie.wav"));

		widgets.push_back(widget);
	}

	for (int i = 0, size = 3; i < 10; i++, size = 2) {
		FilmTextWidget* field = new FilmTextWidget(env.database, 1+i);
		builder.place(*field, 5, 58.0f + 5.0f + (i-1)*3).scribe(*field, config.font("OpenSans-Semibold.ttf"), size);
		widgets.push_back(field);
	}

	std::set<std::string> years = env.database.years();
	set<string>::iterator it = years.begin();

	for (int i = 0, size = 2, dy = 4, dx = 10, x = 0, y=0, newln=5; i < years.size(); ++it, x=x+dx) {
		ToggleButton* button = new ToggleButton();
		builder.place(*button, 55.0f + x, 60.0f + y).scale(*button, 1, 1).scribe(*button, *it, config.font("OpenSans-Regular.ttf"), size)
			.activate(*button, onYearClick, config.asset("checkbox.wav"));

		widgets.push_back(button);
		i++;

		if (i % newln == 0) {
			y = y + dy;
			x = -dx;
		}		
	}

	std::set<std::string> genres = env.database.genres();
	it = genres.begin();

	for (int i = 0, size = 2, dy = 4, dx = 12, x = 0, y = 0, newln = 4; i < years.size(); ++it, x = x + dx) {
		ToggleButton* button = new ToggleButton();
		builder.place(*button, 55.0f + x, 70.0f + y).scale(*button, 1, 1).scribe(*button, *it, config.font("OpenSans-Regular.ttf"), size)
			.activate(*button, onGenreClick, config.asset("checkbox.wav"));

		widgets.push_back(button);

		i++;

		if (i % newln == 0) {
			y = y + dy;
			x = -dx;
		}
	}

	TextField* t1 = new TextField();
	builder.place(*t1, 55.0f, 85.0f).scribe(*t1, "Title:", config.font("OpenSans-Regular.ttf"), 2);

	TextField* t2 = new TextField();
	builder.place(*t2, 55.0f, 90.0f).scribe(*t2, "Director:", config.font("OpenSans-Regular.ttf"), 2);

	TextField* t3 = new TextField();
	builder.place(*t3, 55.0f, 95.0f).scribe(*t3, "Cast:", config.font("OpenSans-Regular.ttf"), 2);

	EditText * e1 = new EditText();
	builder.place(*e1, 70.0f + 25/2, 85.0f - 0.5f).scale(*e1, 25, 3).scribe(*e1, "", config.font("OpenSans-Regular.ttf"), 2);

	EditText* e2 = new EditText();
	builder.place(*e2, 70.0f + 25 / 2, 90.0f - 0.5f).scale(*e2, 25, 3).scribe(*e2, "", config.font("OpenSans-Regular.ttf"), 2);

	EditText* e3 = new EditText();
	builder.place(*e3, 70.0f + 25 / 2, 95.0f - 0.5f).scale(*e3, 25, 3).scribe(*e3, "", config.font("OpenSans-Regular.ttf"), 2);

	edittextBoxes[0] = e1;
	edittextBoxes[1] = e2;
	edittextBoxes[2] = e3;

	widgets.push_back(logo);
	widgets.push_back(nextButton);
	widgets.push_back(previousButton);
	widgets.push_back(exitButton);
	widgets.push_back(searchButton);
	widgets.push_back(t1);
	widgets.push_back(t2);
	widgets.push_back(t3);
	widgets.push_back(e1);
	widgets.push_back(e2);
	widgets.push_back(e3);

	filters.push_back(&yearFilter);
	filters.push_back(&genreFilter);
	filters.push_back(&titleFilter);
	filters.push_back(&directorFilter);
	filters.push_back(&castFilter);
}

void MovieStorm::draw() {
	for (Widget* ptr : widgets) {
		ptr->draw();
	}
}

void MovieStorm::update(float ms) {
	graphics::MouseState mouse_state;
	graphics::getMouseState(mouse_state);

	for (Widget* ptr : widgets) {
		ptr->update(ms);		
	}
	
	if (mouse_state.button_left_pressed) {
		Point origin(graphics::windowToCanvasX((float)mouse_state.cur_pos_x, false), graphics::windowToCanvasY((float)mouse_state.cur_pos_y, false));

		for (Widget* ptr : widgets) {
			ClickableTrait* clickable = dynamic_cast<ClickableTrait*>(ptr);
			if (clickable) {
				clickable->onClick(ptr, origin);
			}
		}
	}
}

void MovieStorm::next() {
	env.database.next();
}

void MovieStorm::previous() {
	env.database.previous();
}

void MovieStorm::selectMovie(FilmWidget* src) {
	int offset = src->getOffset();
	if (offset == -1) {
		return;
	}
	cout << "Offset selected: " << src->getOffset() << endl;

	env.database.selectFilm(src->getOffset());

	const Film* f = env.database.getSelectedFilm();

	if (f) {
		cout << "Selected movie: " << *f << endl;
	} else {
		cout << "Selected movie: null " << endl;
	}
}

void MovieStorm::toggleYear(std::string year) {
	cout << "toggle year: " << year << endl;

	yearFilter.toggle(year);
		
	for (string y : yearFilter.values) {
		cout << y << endl;
	}

	refreshFilters();
}

void MovieStorm::toggleGenre(std::string genre) {
	cout << "toggle genre: " << genre << endl;

	genreFilter.toggle(genre);

	for (string y : genreFilter.values) {
		cout << y << endl;
	}

	refreshFilters();

}

void MovieStorm::key_press(std::set<graphics::scancode_t>& key_presses) {
	static int i = 0;
	cout << "Key press: " << setw(10) << i++ << " ";

	EditText* editText = getFocusedEditText();
	if (editText == nullptr) {
		return;
	}

	for (graphics::scancode_t code : key_presses) {
		int value = (int)code;
		if ((value >= 4 && value <= 39)) {
			char letter = 'a' + (value - 4);
			cout << letter << " ";

			string ascii;
			ascii = letter;

			editText->key_press(ascii);
		} else if (value == 32) {
			editText->key_press(" ");
		} else if (value == 42) {
			editText->key_press("#");
		}
	}
	
	titleFilter.values.clear();
	directorFilter.values.clear();
	castFilter.values.clear();

	string s1 = edittextBoxes[0]->text;

	if (s1 != "") {
		titleFilter.values.insert(s1);
	}

	string s2 = edittextBoxes[1]->text;

	if (s2 != "") {
		directorFilter.values.insert(s2);
	}

	string s3 = edittextBoxes[2]->text;

	if (s3 != "") {
		castFilter.values.insert(s3);
	}

	cout << endl;

	refreshFilters();	
}

void MovieStorm::search() {		
	env.database.applyFilters(filters);
}

