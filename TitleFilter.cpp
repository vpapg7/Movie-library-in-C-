#include "TitleFilter.h"

TitleFilter::TitleFilter() : Filter("title") {
}

bool TitleFilter::apply(const Film& film) const {
	if (values.size() == 0) {
		return true;
	}

	string s = film.title;
	for (string s2 : this->values) {
		if (match(s, s2)) {
			return true;
		}
	}
	
	return false;
}
