#include "Main.h"
#include "Game.h"
#include "Float2.h"
#include "Random.h"
#include "Hit.h"
#include "Goal.h"
int a;
void Goal::Init(int map, int h, int w)
{
	Pos_.x = 1.0f * w * GROUND_SIZE+ GROUND_SIZE/2;
	Pos_.y = 1.0f * h * GROUND_SIZE+ GROUND_SIZE/2;
	image_= LoadGraph("data/Super Mario/enemy/0.png");
}

void Goal::Update(Float2& player_pos, float player_r)
{
	Pos_.x -= map_move;
	if (CheckCircleBoxHit(player_pos.x, player_pos.y, 35/2, Pos_.x , Pos_.y,  35, 35)) {
		a = 10;
	}
}

void Goal::Render()
{	
	DrawRotaGraph(Pos_.x, Pos_.y, 2.0f, 0, image_, TRUE);
	DrawFormatString(100, 300, GetColor(255, 255, 255), "%d", a);
}

void Goal::Exit()
{
	DeleteGraph(image_);
}
