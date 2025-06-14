#pragma once
#include "Float2.h"
#include "base.h"

class Map :
	public Base {

public:

	//���^�C���̃T�C�Y
#define GROUND_SIZE 35


	int Ground_image_;          //�n�ʂ̉摜
	int Ground1_image_;
	int Wall_image_;            //�ǂ̉摜
	int Box_image_;             //���̉摜
	int Coin_image_;            //�R�C���̉摜

	int Map_image_;             //�����p�摜

	//�����p�摜�̃T�C�Y
#define IMAGE_W  7070


#define MAP_H 15
#define MAP_W 202     

int image_x[MAP_H][MAP_W];
int image_y[MAP_H][MAP_W];


	int map[MAP_H][MAP_W];
	int data_count_w;
	int data_count_h;

	//�v���C���[���n�ʂɂ��邩�ǂ���
	bool is_on_ground;


	//�ǂɓ���������A�ǂ̃A�j���[�V����
	bool is_hit;
	//���̕ǂ̍��W���L�^����p�ϐ�
	int wall_x;
	int wall_y;


	//���̕\�������̍��W
	int box_image_x[MAP_H][MAP_W];
	int box_image_y[MAP_H][MAP_W];

	//�v���C���[�ƃL�m�R���܂ޔ��������邩�ǂ���
	bool agaric_is_hit;

	void Init();     //	����������
	void Update();	//	�X�V����
	void Render();	//	�`�揈��
	void Exit();		//	�I������
	void Agaric_hit(Float2& agaric_pos,float& agaric_speed, int agaric_mode);         //	�L���R�ƕǂ̓����蔻��
	void Player_hit(Float2& player_pos, bool& jump_mode, int jump_frame, int player_size, int player_size_w,int& game_mode); //�v���C���[�ƕǂ̓����蔻��


private:




};
