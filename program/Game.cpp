#include "Main.h"
#include "Game.h"
#include "Float2.h"
#include "Random.h"
#include "Hit.h"
#include "Map.h"
#include "player.h"

Map map;

Player player;

//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void GameInit()
{
	map.Init();
	player.Init();
}
//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void GameUpdate()
{
	map.Update(player.pos_,player.is_jump,player.jump_frame);

	player.Update(map.is_on_ground,map.is_wall_have);
	
}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void GameRender()
{
	
	map.Render();
	player.Render();
	//DrawCircle(box.x, box.y, 10, GetColor(255, 255, 255), TRUE);

	//�m�F�p
	DrawFormatString(10 + 20, 10, GetColor(255, 255, 255), "%d", ((int)player.pos_.y / GROUND_SIZE));
	DrawFormatString(10 + 50, 10, GetColor(255, 255, 255), "%d", ((int)(player.pos_.x-map.pos_.x) / GROUND_SIZE));

	DrawFormatString(10 + 90, 10, GetColor(255, 255, 255), "%d", map.map[((int)player.pos_.y / GROUND_SIZE)][((int)(player.pos_.x - map.pos_.x) / GROUND_SIZE)]);
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void GameExit()
{
	map.Exit();
	player.Exit();
}
