#pragma once

#include "Widget.h"
#include "PlaceableTrait.h"
#include "RenderableTrait.h"
#include "SizableTrait.h"
#include "ClickableTrait.h"
#include "ReadableTrait.h"

/// <summary>
/// EditText widget
/// </summary>
class EditText : public Widget, public ClickableTrait, public RenderableTrait, public ReadableTrait {
private:
	graphics::Brush textbox_brush;
public:

	EditText();

	virtual void draw();
	virtual void update(float ms);

	/// <summary>
	/// Method called then the widget is clicked
	/// </summary>
	bool selfUpdate(Widget* src, const Point& origin);

	/// <summary>
	/// Method called when a key is pressed
	/// </summary>
	void key_press(string key);
};

/// <summary>
/// Returns the focused widget
/// </summary>
EditText* getFocusedEditText();

