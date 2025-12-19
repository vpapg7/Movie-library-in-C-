#include "CastFilter.h"

CastFilter::CastFilter() : Filter("cast") {
}

bool CastFilter::apply(const Film& film) const {
	if (values.size() == 0) {
		return true;
	}

	string s = film.cast_str;
	for (string s2 : this->values) {
		if (match(s, s2)) {
			return true;
		}
	}
	
	return false;
}
