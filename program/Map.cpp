#include "Main.h"
#include "Game.h"
#include "Map.h"
//# include <vector>
//#include <math.h>
//#include <algorithm>
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

}


//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void Map::Update(Float2& player_pos)
{


	//�v���C���[���n�ʂɐG���ƁA�������Ȃ��Ȃ�܂�
	if (map[((int)player_pos.y / GROUND_SIZE)][((int)player_pos.x / GROUND_SIZE) == 1])
	{

	}
	else
	{
		//�v���C���[�͏d�͂��󂯂�
		player_pos.y += 5.0f;
	}


	//�v���C���[�̈ړ��ɔ����Ēn�}���ړ�����(�b��)
	if (CheckHitKey(KEY_INPUT_D))
	{
		pos_.x -= 5.0f;
	}



}

//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void Map::Render()
{

	DrawGraphF(pos_.x, pos_.y, Map_image_, TRUE);

	//DrawFormatString(10 + 10, 10, GetColor(255, 255, 255), "%d", map[-2][1]);



	//�񎟌��z��Ń}�b�v��`�悷��
	/*for (int h = 0; h < MAP_H; ++h)
	{
		for (int w = 0; w < MAP_W; ++w)
		{
			if (map[h][w] == 1)
			{
				DrawGraph(w * GROUND_SIZE, h * GROUND_SIZE, Ground_image_, TRUE);
			}
		}
	}*/

}


//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------

void Map::Exit()
{


}





