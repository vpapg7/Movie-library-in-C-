#pragma once

#include <sgg/graphics.h>

#include "Trait.h"

/// <summary>
/// Renderable traits contain textures
/// </summary>
class RenderableTrait : public Trait {
public:
	graphics::Brush brush;

	RenderableTrait();
};

