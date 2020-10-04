#pragma once
#include <SDL.h>
class Tile
{
public:

	// Default constructor
	Tile();

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

	// For rendering
	SDL_Rect source, destination;

	SDL_Texture* wall;
	SDL_Texture* floor;
	SDL_Texture* door;

	// 2d array to hold all spaces in the map
	int map[16][12];
};

