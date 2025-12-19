#pragma once

#include <ostream>
#include <set>
#include <list>
#include "Film.h"
#include "Filter.h"

using namespace std;

/// <summary>
/// Database of the application
/// Stores all films sorted by title and year
/// </summary>
class Database : public multiset<Film> {
public:
	const std::list<Filter<>*> defaultFilters;
	std::vector<const Film*> filtered;

	/// <summary>
	/// Shift is an amount that all movies have been shifted
	/// </summary>
	int shift = 0;

	/// <summary>
	/// If a movie is selected, it's index is stored in this variable
	/// </summary>
	int selected = -1;

	/// <summary>
	/// Loads the database from a txt file
	/// </summary>
	/// <param name="filename">absolute path to the filename</param>
	Database(const char* filename, const char * cover_path);
	
	/// <summary>
	/// Lists all films of the database to terminal
	/// </summary>
	void list();

	/// <summary>
	/// Applies all filters to the database
	/// </summary>
	/// <param name="filter">a collection of filters to be applied</param>
	void applyFilters(const std::list<Filter<> *>& filter);


	/// <summary>
	/// Retrieve filtered film
	/// </summary>
	/// <param name="offset">offset in the search results</param>
	/// <returns>The film or nullptr if it does not exist</returns>
	const Film * getFilm(int offset) const;

	/// <summary>
	/// Retrieve selected film
	/// </summary>
	/// <param name="offset">offset in the search results</param>
	/// <returns>The film or nullptr if it does not exist</returns>
	const Film* getSelectedFilm() const;

	/// <summary>
	/// Select a film
	/// </summary>
	/// <param name="offset">zero baseed offset</param>
	void selectFilm(int offset);

	/// <summary>
	/// Retrieve a set of all available years
	/// </summary>
	/// <returns>a set of all years of all movies</returns>
	std::set<std::string> years() const;

	/// <summary>
	/// Retrieve a set of all available genres
	/// </summary>
	/// <returns>a set of all genres of all movies</returns>
	std::set<std::string> genres() const;


	/// <summary>
	/// Navigate to next film
	/// </summary>
	void next();

	/// <summary>
	/// Navigate to previous film
	/// </summary>
	void previous();
};

/// <summary>
/// Outputs a film to an output stream
/// </summary>
/// <param name="os">the output stream</param>
/// <param name="right">the film to be serialized</param>
/// <returns>reference to the output stream used</returns>
bool operator<(const Film& left, const Film& right);

/// <summary>
/// Overload operator used for sorting the films
/// 
/// </summary>
/// <param name="left">Film 1</param>
/// <param name="right">Film 2</param>
/// <returns>true iif Film 1 is before File 2 in the order</returns>
std::ostream& operator<<(std::ostream& left, const Film& right);

/// <summary>
/// Outputs a database to an output stream
/// </summary>
/// <param name="os">the output stream</param>
/// <param name="right">the database to be serialized</param>
/// <returns>reference to the output stream used</returns>
std::ostream& operator<<(std::ostream& left, const Database& right);

