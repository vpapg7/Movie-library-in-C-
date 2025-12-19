#pragma once

#include <vector>
#include <list>
#include <set>

#include "Widget.h"
#include "FilmWidget.h"	
#include "Config.h"
#include "Environment.h"
#include "TraitBuilder.h"

#include "YearFilter.h"
#include "GenreFilter.h"
#include "DirectorFilter.h"
#include "TitleFilter.h"
#include "CastFilter.h"
#include "EditText.h"

/// <summary>
/// Controller
/// </summary>
class MovieStorm {
private:
	const Environment& env;
	const TraitBuilder builder;

	std::vector<Widget*> widgets;
	std::list<Filter<>*> filters;
	
	YearFilter yearFilter;
	GenreFilter genreFilter;
	DirectorFilter directorFilter;
	TitleFilter titleFilter;
	CastFilter castFilter;

	EditText* edittextBoxes[3];

	void refreshFilters();
public:		
	MovieStorm(const Environment& env);

	void draw();
	void update(float ms);

	/// <summary>
	/// Next film
	/// </summary>
	void next();

	/// <summary>
	/// previous film
	/// </summary>
	void previous();

	/// <summary>
	/// Select a spefific movie
	/// </summary>
	/// <param name="src">Widget that activated thischange</param>
	void selectMovie(FilmWidget* src);

	/// <summary>
	/// Add or remove a year from the filter
	/// </summary>
	/// <param name="year">year</param>
	void toggleYear(std::string year);

	/// <summary>
	/// Add or remove a genre from the filter
	/// </summary>
	/// <param name="genre">genre</param>
	void toggleGenre(std::string genre);

	/// <summary>
	/// Callback to handle key presses
	/// </summary>
	/// <param name="key_presses"></param>
	void key_press(std::set<graphics::scancode_t> & key_presses);

	/// <summary>
	/// Search fields (autoactivated)
	/// </summary>
	void search();
};


