#include "Main.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "agaric.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//---------------------------------------------------------------------------------
//	�L���R�ƃ}�b�v�̓����蔻��
//---------------------------------------------------------------------------------
void Map::agaric_hit(Float2& agaric_pos, float& agaric_speed,int agaric_mode)
{
	//�L���R�̉E�͕ǂȂ�,���ɍs���܂�
	if (map[((int)agaric_pos.y / GROUND_SIZE)][((int)(agaric_pos.x - pos_.x) / GROUND_SIZE)] == 5&& agaric_mode == Agaric::MODE_MOVE)
	{
		agaric_speed = -agaric_speed;
	}

	//�L���R���n�ʂɐG���ƁA�������Ȃ��Ȃ�܂�
	if (map[((int)agaric_pos.y / GROUND_SIZE) + 1][((int)(agaric_pos.x - pos_.x) / GROUND_SIZE)] != 0)    //�n��
	{

	}
	else if(agaric_mode == Agaric::MODE_MOVE)
	{
		//�L���R�͏d�͂��󂯂�
		agaric_pos.y += 5.0f;
		
	}

}

//---------------------------------------------------------------------------------
//	�v���C���[�ƃ}�b�v�̓����蔻��
//---------------------------------------------------------------------------------



//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void Map::Init()
{

	Map_image_ = LoadGraph("data/map/map1.png");  //�Ƃ肠�����}�b�v�̉摜�����

	//���낢��ȉ摜������������
	Ground_image_ = LoadGraph("data/map/Ground.png");
	Ground1_image_ = LoadGraph("data/map/Ground1.png");
	Box_image_ = LoadGraph("data/map/Box.png");
	Wall_image_ = LoadGraph("data/map/Wall.png");


	// �t�@�C������ǂݍ���
	ifstream file("data/map/txt/map1.txt", ios::in);

	//�t�@�C�����J���邩�ǂ���
	if (!file.is_open()) {
		printfDx("�t�@�C�����J���܂���ł���\n");
		return;
	}

	for (int h = 0; h < MAP_H; ++h) {

		//�}�b�v���������
		string str;

		getline(file, str);

		//������̕���
		stringstream sstr(str);

		for (int w = 0; w < MAP_W; ++w) {

			//��������������ۑ�����p�ϐ�
			int num = 0;

			//�ϐ��ɑ��
			sstr >> num;

			//�}�b�v�ɑ��
			map[h][w] = num;
		}
	}


	//�t�@�C����߂�
	file.close();

	//�}�b�v�̍��W������������
	pos_ = { -10.0f,0.0f };


	for (int h = 0; h < MAP_H; ++h)
	{
		for (int w = 0; w < MAP_W; ++w)
		{
			image_x[h][w] = w * GROUND_SIZE;
			image_y[h][w] = h * GROUND_SIZE;
			box_image_x[h][w] = 0;
			box_image_y[h][w] = 0;
		}
	}

	//�ŏ��͒n�ʂɓ������Ă���
	is_on_ground = true;

	is_wall_have = false;

	is_hit = false;

	agaric_is_hit = false;
}


//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void Map::Update(Float2& player_pos, bool& jump_mode, int jump_frame)
{

	//�v���C���[���n�ʂɐG���ƁA�������Ȃ��Ȃ�܂�
	if (map[((int)player_pos.y / GROUND_SIZE) + 1][((int)(player_pos.x - pos_.x) / GROUND_SIZE)] != 0)    //�n��
	{
		is_on_ground = true;
	}
	else
	{
		//�v���C���[�͏d�͂��󂯂�
		player_pos.y += 5.0f;
		is_on_ground = false;

		if (jump_frame > 20)
		{
			jump_mode = false;
		}

	}

	//�ǂɂԂ���ƑO�ɐi�߂Ȃ�
	if (map[((int)player_pos.y / GROUND_SIZE)][((int)(player_pos.x - pos_.x) / GROUND_SIZE) + 1] != 0
		|| map[((int)player_pos.y / GROUND_SIZE)][((int)(player_pos.x - pos_.x) / GROUND_SIZE) - 1] != 0)   //��
	{
		is_wall_have = true;
	}
	else
	{
		is_wall_have = false;
	}

	//�ǂɂԂ���Ə�ɐi�߂Ȃ�
	if (map[((int)player_pos.y / GROUND_SIZE)][((int)(player_pos.x - pos_.x) / GROUND_SIZE)] != 0)
	{
		jump_mode = false;
	}

	//�ǂɂԂ���ƕǂ͏�ɐi�߂�
	if (map[((int)player_pos.y / GROUND_SIZE)][((int)(player_pos.x - pos_.x) / GROUND_SIZE)] == 4)
	{
		is_hit = true;
		wall_x = ((int)player_pos.y / GROUND_SIZE);
		wall_y = ((int)(player_pos.x - pos_.x) / GROUND_SIZE);
	}
	else if (map[((int)player_pos.y / GROUND_SIZE)][((int)(player_pos.x - pos_.x) / GROUND_SIZE)] == 3)   //���ɓ���������
	{
		is_hit = true;
		wall_x = ((int)player_pos.y / GROUND_SIZE);
		wall_y = ((int)(player_pos.x - pos_.x) / GROUND_SIZE);
		box_image_x[((int)player_pos.y / GROUND_SIZE)][((int)(player_pos.x - pos_.x) / GROUND_SIZE)] = 3 * GROUND_SIZE;

		//�L�m�R���܂ޔ��ɓ���������
		if (((int)player_pos.y / GROUND_SIZE) == 8 && ((int)(player_pos.x - pos_.x) / GROUND_SIZE) == 20)
		{
			agaric_is_hit = true;
		}
	}

	if (is_hit == true)
	{
		static int speed = 5.0f;
		speed--;
		image_y[wall_x][wall_y] -= speed;
		if (speed <= -4.0f)
		{
			is_hit = false;
			speed = 5.0f;
		}
	}

	//�v���C���[�̈ړ��ɔ����Ēn�}���ړ�����(�v���C���[�̈ʒu���n�}�̐^�񒆂ɂ���ꍇ)
	if (CheckHitKey(KEY_INPUT_D) && player_pos.x >= SCREEN_W / 2)
	{
		pos_.x -= 3.0f;   //�v���C���[�̈ړ��������L�^����
		for (int h = 0; h < MAP_H; ++h)
		{
			for (int w = 0; w < MAP_W; ++w)
			{
				image_x[h][w] -= 3;

			}
		}
	}

	if (pos_.x < -IMAGE_W + SCREEN_W)
	{
		pos_.x = -IMAGE_W + SCREEN_W;
	}


	//���̃A�j���[�V����
	static int frame;
	frame++;
	static int box_speed = 35;
	if (frame % 10 == 0 && frame != 0)
	{
		for (int h = 0; h < MAP_H; ++h)
		{
			for (int w = 0; w < MAP_W; ++w)
			{
				if (box_image_x[h][w] != 3 * GROUND_SIZE)
				{
					box_image_x[h][w] += box_speed;
					if (box_image_x[h][w] > 2 * GROUND_SIZE || box_image_x[h][w] < 0)
					{
						box_speed = -box_speed;
					}
				}

			}
		}
	}




}

//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void Map::Render()
{

	DrawGraphF(pos_.x, pos_.y, Map_image_, TRUE);    //�w�i


	//�񎟌��z��Ń}�b�v��`�悷��
	for (int h = 0; h < MAP_H; ++h)
	{
		for (int w = 0; w < MAP_W; ++w)
		{
			if (map[h][w] == 1)    //Ground
			{
				DrawGraph(image_x[h][w], image_y[h][w], Ground_image_, TRUE);
			}
			if (map[h][w] == 2)      //Ground1
			{
				DrawGraph(image_x[h][w], image_y[h][w], Ground1_image_, TRUE);
			}
			if (map[h][w] == 3)      //box
			{
				DrawRectGraph(image_x[h][w], image_y[h][w], box_image_x[h][w], box_image_y[h][w], GROUND_SIZE, GROUND_SIZE, Box_image_, TRUE);
			}
			if (map[h][w] == 4)      //wall
			{
				DrawGraph(image_x[h][w], image_y[h][w], Wall_image_, TRUE);
			}
		}
	}

}


//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------

void Map::Exit()
{
	DeleteGraph(Ground_image_);
	DeleteGraph(Ground1_image_);
}







