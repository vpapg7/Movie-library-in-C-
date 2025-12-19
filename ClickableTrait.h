#pragma once

#include <string>
#include "Trait.h"
#include "PlaceableTrait.h"
#include "SizableTrait.h"

#include <sgg/graphics.h>

/// <summary>
/// Clickable trait
/// 
/// A widget is clickable if it interacts with the mouse
/// </summary>
class ClickableTrait : public PlaceableTrait, public SizableTrait {
public:
	/// <summary>
	/// scale factors increase the live area
	/// </summary>
	float scale_clickable_area_left = 1.0f;
	float scale_clickable_area_right = 1.0f;
	float scale_clickable_area_top = 1.0f;
	float scale_clickable_area_bottom = 1.0f;

	/// <summary>
	/// Callback called when an item is clicked
	/// </summary>
	void (*callback)(Widget* src, void * source) = nullptr;

	/// <summary>
	/// sound effect of the click
	/// </summary>
	std::string sound = "assets/close.wav";

	/// <summary>
	/// Control method called by the movie storm
	/// </summary>
	/// <param name="src"></param>
	/// <param name="origin"></param>
	/// <returns></returns>
	virtual bool onClick(Widget* src, const Point& origin);

	/// <summary>
	/// Method called when an item is clicked. This method is called whether the item has a callback or not
	/// </summary>
	/// <param name="src">Widget that created the click</param>
	/// <param name="origin">screen coordinates</param>
	/// <returns>true if item was changed</returns>
	virtual bool selfUpdate(Widget* src, const Point& origin);
};

