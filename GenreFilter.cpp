#include <string>

#include "GenreFilter.h"

using namespace std;


GenreFilter::GenreFilter() : Filter("genre") {
}

bool GenreFilter::apply(const Film& film) const {
	if (values.size() == 0) {
		return true;
	}

	for (string s : film.genres) {
		for (string s2 : this->values) {
			if (s.find(s2) != -1) {
				return true;
			}
		}
	}
	return false;
}
