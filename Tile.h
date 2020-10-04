#pragma once
#include <SDL.h>
class Tile
{
public:
	// Constructor for defining some tile attributes
	Tile(int x, int y, int tileType);

	// what helps show the tile
	void Render();

	// retrieve tile type
	int GetType();

	// Get the collision box
	SDL_Rect GetBox();
private:
	// Int denoting Tile's type
	int vType;

	// tile attributes (width, height, tile type)
	SDL_Rect vBox;

	// default width/ height for tiles
	//int TILE_WIDTH = 50, TILE_HEIGHT = 50;
};

