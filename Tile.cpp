#include "Tile.h"

Tile::Tile()
{

}

Tile::Tile(int x, int y, int tileType)
{
	vBox.x = x;
	vBox.y = y;

	vBox.w = 50;
	vBox.h = 50;

	vType = tileType;
};

void Tile::Render()
{
	// ..
};

int Tile::GetType()
{
	return vType;
};

SDL_Rect Tile::GetBox()
{
	return vBox;
};