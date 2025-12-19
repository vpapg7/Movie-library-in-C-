#include <string>

#include "Environment.h"

/// <summary>
/// Controls key events  so that they activate only when needed
/// </summary>
class WindowManager {
private:
	const Environment& env;
	bool key_pressed[512];
public:
	WindowManager(const Environment& env);

	void initialize(std::string title, bool full_screen);

	void draw();
	void update(float ms);
};