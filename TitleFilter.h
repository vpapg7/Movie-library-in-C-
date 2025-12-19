#pragma once

#include <string>

#include "Filter.h"

/// <summary>
/// Title filter matches films for specific titles
/// </summary>
class TitleFilter : public Filter<std::string> {
public:
	/// <summary>
	/// C-tor
	/// </summary>
	/// <param name="value">Value for the search field to be compared to</param>
	TitleFilter();

	/// <summary>
	/// Checks if a film matches with the filter
	/// </summary>
	/// <param name="film">Film to be checked</param>
	/// <returns>true if filter matches</returns>
	virtual bool apply(const Film& film) const;
};

