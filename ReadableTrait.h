#pragma once

#include <string>

#include "Trait.h"

using namespace std;

/// <summary>
/// Readable widgets contain text
/// </summary>
class ReadableTrait : public Trait {
public:
	std::string text;
	std::string font;
	float size;
};

