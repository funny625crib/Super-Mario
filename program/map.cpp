#include "main.h"
#include "map.h"

//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------

void Map::Init()
{
	//���낢��ȉ摜�̏�����
	Ground_image_=LoadGraph("data/map/Graound.png");
	Wall_image_=  LoadGraph("data/map/Wall.png");
	box_image_=   LoadGraph("data/map/box.png");
	coin_image_=  LoadGraph("data/map/coin_image");
}
