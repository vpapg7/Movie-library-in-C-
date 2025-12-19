#pragma once

#include <string>
#include <set>
#include <vector>

/// <summary>
/// Film structure
/// </summary>
struct Film {
	std::string title = "";
	unsigned int year = 0;
	std::set<std::string> genres;
	std::set<std::string> directors;
	std::set<std::string> cast;
	std::vector<std::string> synopsis;

	std::string genres_str;
	std::string directors_str;
	std::string cast_str;

	std::string texture;
};

