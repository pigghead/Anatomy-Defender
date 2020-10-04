#include "Tile.h"

Tile::Tile(int x, int y, int tileType)
{
	// Set the location of our box
	colBox.x = x;
	colBox.y = y;

	// set the bounds for our box
	colBox.w = TILE_WIDTH;
	colBox.h = TILE_HEIGHT;

	// assign the type
	type = tileType;
}

void Tile::Render(SDL_Rect& camera)
{
	// Check for tiles on screen
	if (checkCollision)
	{

	}
}