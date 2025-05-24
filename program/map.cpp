#include "main.h"
#include "map.h"

//---------------------------------------------------------------------------------
//	‰Šú‰»ˆ—
//---------------------------------------------------------------------------------

void Map::Init()
{
	//‚¢‚ë‚¢‚ë‚È‰æ‘œ‚Ì‰Šú‰»
	Ground_image_=LoadGraph("data/map/Graound.png");
	Wall_image_=  LoadGraph("data/map/Wall.png");
	box_image_=   LoadGraph("data/map/box.png");
	coin_image_=  LoadGraph("data/map/coin_image");
}
