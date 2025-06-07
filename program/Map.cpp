#include "Main.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;




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
	pos_ = { 0.0f,0.0f };


	for (int h = 0; h < MAP_H; ++h)
	{
		for (int w = 0; w < MAP_W; ++w)
		{
			image_x[h][w] = w * GROUND_SIZE;
			image_y[h][w] = h * GROUND_SIZE;

		}
	}

	//�ŏ��͒n�ʂɓ������Ă���
	is_on_ground = true;

	is_wall_have = false;
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

		if (jump_frame>20)
		{
			jump_mode = false;
		}

	}

	//�ǂɂԂ���ƑO�ɐi�߂Ȃ�
	if (map[((int)player_pos.y / GROUND_SIZE)][((int)(player_pos.x - pos_.x) / GROUND_SIZE) + 1] != 0)   //��
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

}

//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void Map::Render()
{

	//DrawGraphF(pos_.x, pos_.y, Map_image_, TRUE);    //�Q�Ɨp�}�b�v

	DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(97, 124, 182), TRUE);   //�w�i

	//DrawFormatString(10 + 10, 10, GetColor(255, 255, 255), "%d", map[-2][1]);



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
				DrawGraph(image_x[h][w], image_y[h][w], Box_image_, TRUE);
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





