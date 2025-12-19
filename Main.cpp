#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "Environment.h"

#include "Config.h"
#include "Database.h"
#include "MovieStorm.h"
#include "WindowManager.h"

#define DEBUG true


int main() {
	string title = "MovieStorm";
	Config* config = new Config();
	Database* database = new Database(config->database_path, config->cover_path);
	
	Environment* env = new Environment(*config, *database);
	MovieStorm* storm = new MovieStorm(*env);	
	env->storm = storm;

	if (DEBUG) {
		database->list();
	}
	
	WindowManager* window = new WindowManager(*env);

	window->initialize(title, false);

	delete window;
	delete env;
	delete storm;
	delete database;
	delete config;

	return 0;
}
