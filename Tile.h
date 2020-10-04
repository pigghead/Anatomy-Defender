#pragma once
#include <SDL.h>
class Tile
{
public:
	//Parameters: x - width, y - height, type - what type of tile is this
	Tile(int x, int y, int type);
	// Get the collision box of the tile
	SDL_Rect GetBox();
	// Get the type of tile this is
	int GetType();
	// Put the tile on the screen
	void Render(SDL_Rect& camera);
	// check collisions with this tile
	bool checkCollision(SDL_Rect& a, SDL_Rect& b);
private:
	// what type of tile is this
	int type;
	// collision box
	SDL_Rect colBox;
	// width & height (const)
	const int TILE_WIDTH = 50;
	const int TILE_HEIGHT = 50;
};

