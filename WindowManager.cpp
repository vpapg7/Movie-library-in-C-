#include <iostream>
#include <assert.h>
#include <vector>

#include "WindowManager.h"
#include "MovieStorm.h"

#include <sgg/graphics.h>
#include <sgg/scancodes.h>

using namespace std;

static void draw() {
	WindowManager* window = (WindowManager*)graphics::getUserData();
	assert(window != nullptr);
	window->draw();
}

static void update(float ms) {
	WindowManager* window = (WindowManager*)graphics::getUserData();
	assert(window != nullptr);
	window->update(ms);
}


WindowManager::WindowManager(const Environment& env) : env(env) {
	for (int i = 0; i < 512; i++) {
		key_pressed[i] = false;
	}
}

void WindowManager::initialize(std::string title, bool full_screen) {
	graphics::createWindow(env.config.window_width, env.config.window_height, title);
	graphics::setCanvasSize(env.config.canvas_width, env.config.canvas_height);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	if (full_screen) {
		graphics::setFullScreen(true);
	}

	if (env.config.preload) {
		string paths[2] = { env.config.cover_path, env.config.assets_path };

		for (int i = 0; i < 2; i++) {
			const auto assets = graphics::preloadBitmaps(paths[i]);
			for (const auto asset : assets) {
				std::cout << "PRELOADING : " << asset << std::endl;
			}
		}
	}

	graphics::setUserData(this);
	graphics::setDrawFunction(::draw);
	graphics::setUpdateFunction(::update);

	graphics::startMessageLoop();
	graphics::destroyWindow();
}

void WindowManager::draw() {
	if (env.storm) {
		env.storm->draw();
	}
}

void WindowManager::update(float ms) {
	if (graphics::getKeyState(graphics::scancode_t::SCANCODE_ESCAPE) ||
		(graphics::getKeyState(graphics::scancode_t::SCANCODE_Q) && graphics::getKeyState(graphics::scancode_t::SCANCODE_LCTRL))) {
		graphics::stopMessageLoop();
	}

	if (env.storm) {
		env.storm->update(ms);

		float now = graphics::getGlobalTime();

	
		set<graphics::scancode_t> codes;

		for (int i = 4; i <= 44; i++) {
			if (i == 43) {
				continue;
			}

			graphics::scancode_t code = (graphics::scancode_t)i;

			if (graphics::getKeyState(code)) {
				if (!key_pressed[i]) {
					key_pressed[i] = true;							
					codes.insert(code);
				} 
			} else {
				key_pressed[i] = false;
			}
		}

		if (codes.size() > 0) {
			env.storm->key_press(codes);
		}
	}
}
