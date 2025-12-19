#pragma once

#include <string>

/// <summary>
/// Configuration
/// </summary>
struct Config {
	const int window_width = 1280;
	const int window_height = 960;
	const float canvas_width = 100.0f;
	const float canvas_height = 100.0f;
	const char * assets_path = "assets/";
	const char * database_path = "database/data.txt";
	const char * cover_path = "assets/covers/";
	const char * font_path = "assets/fonts/";
	bool preload = false;

	std::string asset(std::string name) const {
		return std::string(this->assets_path) + name;
	}

	std::string font(std::string name) const {
		return std::string(this->font_path) + name;
	}
};
