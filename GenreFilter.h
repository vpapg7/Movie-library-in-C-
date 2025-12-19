#pragma once

#include "Filter.h"

/// <summary>
/// Filter matches films for specific genres
/// </summary>
class GenreFilter : public Filter<std::string> {
public:	
	/// <summary>
	/// C-tor
	/// </summary>
	GenreFilter();

	/// <summary>
	/// Checks if a film matches with the filter
	/// </summary>
	/// <param name="film">Film to be checked</param>
	/// <returns>true if filter matches</returns>
	virtual bool apply(const Film& film) const;
};

