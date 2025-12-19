#pragma once

#include "Config.h"
#include "Database.h"

using namespace std;

/// <summary>
/// Environment.
/// 
/// Config, database and the MediaStorm object (equivalent to game)
/// </summary>
class Environment {
public:
	const Config& config;	
	Database& database;
	class MovieStorm* storm = nullptr;

	Environment(const Config& config, Database& database);
};

