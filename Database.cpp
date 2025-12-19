#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <list>

#include "Database.h"

using namespace std;


Database::Database(const char* filename, const char * cover_path) {
	ifstream fp(filename);
	
	if (!fp) {
		throw std::invalid_argument("Database file not found" + string(filename));
	}

	for (string buffer[7] { }; getline(fp, buffer[0]) && getline(fp, buffer[1]) && getline(fp, buffer[2]) && getline(fp, buffer[3]) && getline(fp, buffer[4]) && getline(fp, buffer[5]) && getline(fp, buffer[6]);) {
		Film film;
		film.title = buffer[0];
		film.year = stoi(buffer[1].substr(1, 4));


		char* temp;

		film.genres_str = buffer[2];
		
		temp = _strdup(buffer[2].c_str());

		for (char* saveptr = nullptr, *token = strtok_s(temp, ",", &saveptr); token != nullptr; token = strtok_s(nullptr, ",", &saveptr)) {
			film.genres.insert(token);
		}

		delete[] temp;

		film.directors_str = buffer[3] = buffer[3].substr(string("Director: ").length());

		temp = _strdup(buffer[3].c_str());

		for (char* saveptr = nullptr, *token = strtok_s(temp, ",", &saveptr); token != nullptr; token = strtok_s(nullptr, ",", &saveptr)) {
			film.directors.insert(token);
		}

		delete[] temp;

		film.cast_str = buffer[4] = buffer[4].substr(string("Main cast: ").length());

		temp = _strdup(buffer[4].c_str());

		for (char* saveptr = nullptr, *token = strtok_s(temp, ",", &saveptr); token != nullptr; token = strtok_s(nullptr, ",", &saveptr)) {
			film.cast.insert(token);
		}

		delete[] temp;

		temp = _strdup(buffer[5].c_str());

		int c = 0;

		string line = "";
		for (char* saveptr = nullptr, *token = strtok_s(temp, " ", &saveptr); token != nullptr; token = strtok_s(nullptr, " ", &saveptr), c++) {
			line += token;
			line += " ";
			if (c == 7) {
				c = 0;
				film.synopsis.push_back(line);
				line = "";
			}
		}

		if (c != 0) {
			film.synopsis.push_back(line);
		}

		delete[] temp;

		if (buffer[6][0] != '#') {
			throw std::runtime_error("File not in proper format" + string(filename));
		}
		
		film.texture = string(cover_path) + std::to_string(film.year) + "-" + film.title + ".png";

		this->insert(film);
	}
	
	applyFilters(defaultFilters);
}



void Database::list() {
	for (const Film& film : *this) {
		cout << film;
		cout << "---------------------------------------------------" << endl;
	}
}

void Database::applyFilters(const std::list<Filter<>*>& filters) {
	filtered.clear();

	for (const Film& film : *this) {
		bool matches = true;

		for (Filter<>* f : filters) {
			if (!f->apply(film)) {
				matches = false;
				break;
			}
		}

		if (matches) {
			filtered.push_back(&film);
		}
	}	

	shift = 0;
	selected = -1;
}

const Film* Database::getFilm(int offset) const {
	offset += shift;

	if (offset < filtered.size()) {
		return filtered[offset];
	} else {
		return nullptr;
	}
}

const Film* Database::getSelectedFilm() const {
	if (selected == -1) {
		return nullptr;
	}

	int offset = shift + selected;

	if (offset < filtered.size()) {
		return filtered[offset];
	} else {
		return nullptr;
	}
}

void Database::selectFilm(int offset) {
	selected = offset;
}

std::set<std::string> Database::years() const {
	std::set<std::string> collection;

	for (const Film& f : *this) {
		collection.insert(std::to_string(f.year));
	}

	return collection;
}

std::set<std::string> Database::genres() const {
	std::set<std::string> collection;

	for (const Film& f : *this) {
		for (string s : f.genres) {
			collection.insert(s);
		}
	}
	return collection;	
}

void Database::next() {
	if (shift < filtered.size() - 1) {
		shift++;
	}
}

void Database::previous() {
	if (shift > 0 && shift < filtered.size()) {
		shift--;
	}
}


std::ostream& operator<<(std::ostream& os, const Film& right) {
	os << setw(30) << left << right.title;
	os << setw(10) << left << right.year;
	os << setw(30) << left << right.genres_str << endl;
	os << setw(30) << left << right.texture << endl;
	os << left << right.directors_str << endl;
	os << left << right.cast_str << endl;

	for (string l : right.synopsis) {
		os << "# " << l << endl;
	}
	
	os << endl;
	//left << setw(20) << left << right.title;
	//left << setw(20) << left << right.title;
	return os;
}

bool operator<(const Film& left, const Film& right) {
	if (left.title != right.title) {
		return left.title < right.title;
	} else {
		return left.year < right.year;
	}
}

std::ostream& operator<<(std::ostream& os, const Database& right) {
	for (const Film& film : right) {
		os << film << endl;
	}
	return os;
}
