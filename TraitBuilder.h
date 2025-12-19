#pragma once

#include <string>

#include "Widget.h"
#include "PlaceableTrait.h"
#include "SizableTrait.h"
#include "ClickableTrait.h"
#include "ReadableTrait.h"

/// <summary>
/// Builder for all widgets based on their traits
/// </summary>
class TraitBuilder {
public:
	const TraitBuilder& place(PlaceableTrait& trait, float x, float y) const;
	const TraitBuilder& scale(SizableTrait& trait, float width, float height) const;
	const TraitBuilder& activate(ClickableTrait& trait, void (*callback)(Widget* src, void* source), std::string sound = "assets/close.wav") const;

	const TraitBuilder& scribe(ReadableTrait& trait, std::string text, std::string font, int size) const;

	const TraitBuilder& scribe(ReadableTrait& trait, std::string font, int size) const;
};