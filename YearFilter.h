#pragma once

#include <string>
#include <set>
#include "Filter.h"

using namespace std;

/// <summary>
/// Year filter matches films for specific year
/// </summary>
class YearFilter : public Filter<std::string> {
private:	
public:
	// <summary>
	/// C-tor
	/// </summary>
	/// <param name="value">Value for the search field to be compared to</param>
	YearFilter();

	/// <summary>
	/// Checks if a film matches with the filter
	/// </summary>
	/// <param name="film">Film to be checked</param>
	/// <returns>true if filter matches</returns>
	virtual bool apply(const Film& film) const;
};

