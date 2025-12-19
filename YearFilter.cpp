#include "YearFilter.h"


YearFilter::YearFilter() : Filter("year") {

}

bool YearFilter::apply(const Film& film) const {
	if (values.size() == 0) {
		return true;
	}

	for (string year : values) {
		int y = stoi(year);

		if (film.year == y) {
			return true;
		}
	}
	return false;
}