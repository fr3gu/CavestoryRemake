#ifndef LEVEL_H
#define LEVEL_H

#include "globals.h"
#include "graphics.h"

using namespace std;

//struct SDL_Texture;

class Level {
public:
	Level();
	Level(string mapName, Vector2 spawnPoint, Graphics &graphics);
	~Level();
	void update(float elapsedTime);
	void draw(Graphics &graphics);

private:
	string _mapName;
	Vector2 _spawnPoint;
	Vector2 _size;
	SDL_Texture* _backgroundTexture;

	void loadMap(string mapName, Graphics &graphics);
};

#endif
