#include <string>

#include "DirectorFilter.h"

using namespace std;

DirectorFilter::DirectorFilter() : Filter("director") {
}

bool DirectorFilter::apply(const Film& film) const {
	if (values.size() == 0) {
		return true;
	}

	for (string s : film.directors) {
		for (string s2 : this->values) {
			if (match(s,s2)) {
				return true;
			}
		}
	}
	return false;
}
