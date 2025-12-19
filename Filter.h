#pragma once

#include <string>
#include <set>

#include "Film.h"

using namespace std;

/// <summary>
/// Abstract Filter class
/// </summary>

template <typename T = std::string>
class Filter {
protected:
	/// <summary>
	/// Used for text searches
	/// </summary>
	/// <param name="s1">film attribute</param>
	/// <param name="s2">search key</param>
	/// <returns>true iff s1 contains s2 (case insensitive)</returns>
	bool match(string s1, string s2) const {
		for (auto& c : s1) {
			c = tolower(c);
		}

		for (auto& c : s2) {
			c = tolower(c);
		}

		return s1.find(s2) != -1;
	}
public:	
	const std::string key;
	set<T> values;

	/// <summary>
	/// C-tor
	/// </summary>
	/// <param name="key">Attribute of the film to be matched</param>
	/// <param name="value">Value for that field to be matched</param>
	Filter(std::string key) : key(key) {

	}
		
	/// <summary>
	/// Checks if a film matches with a filter
	/// </summary>
	/// <param name="film">Film to be checked</param>
	/// <returns>true if filter matches</returns>
	virtual bool apply(const Film& film) const = 0;

	virtual void toggle(T value) {		
		if (values.find(value) != values.end()) {
			values.erase(value);
		} else {
			values.insert(value);
		}
	}
};
