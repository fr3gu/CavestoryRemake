#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

#include "globals.h"
#include "tile.h"

class Graphics;
struct SDL_Texture;
struct SDL_Rect;
struct Tileset;

using namespace std;

class Level {
public:
	Level();
	Level(string mapName, Vector2 spawnPoint, Graphics &graphics);
	~Level();
	void update(int elapsedTime);
	void draw(Graphics &graphics);

private:
	string _mapName;
	Vector2 _spawnPoint;

	Vector2 _size;
	Vector2 _tileSize;

	SDL_Texture* _backgroundTexture;

	vector<Tile> _tileList;
	vector<Tileset> _tilesets;

	/* void loadMap
	 * Loads a map
	 */
	void loadMap(string mapName, Graphics &graphics);

};

//Tileset structure
struct Tileset {
	SDL_Texture* Texture;
	int FirstGid;
	Tileset() {
		this->FirstGid = -1;
	}
	Tileset(SDL_Texture* texture, int firstGid) {
		this->Texture = texture;
		this->FirstGid = firstGid;
	}
};




#endif
