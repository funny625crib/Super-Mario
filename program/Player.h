#pragma once
#include "Float2.h"
#include "base.h"

class Player :
	public Base {

public:

	//�v���C���[�摜�̃T�C�Y
#define PLAYER_IMAGE_W 33
#define PLAYER_IMAGE_H 34

#define PLAYER_BIG_IMAGE_W 50
#define PLAYER_BIG_IMAGE_H 68

//�v���C���[�̈ړ��X�s�[�h
#define PLAYER_MOVE_SPEED    2.0f


	//�v���C���[�摜�̃T�C�Y
	int player_image_w;
	int player_image_h;

	//�}���I�̉摜
	int image_small;
	int image_big;

	//�`�悷���ʂ̍��W
	int image_x;
	int image_y;

	//�v���C���[�̉摜�����]���邩�ǂ���
	bool is_overturn;

	//�v���C���[�̈ړ����[�h
	enum
	{
		MODE_IDLE,
		MODE_MOVE,
		MODE_STOP,     //�ړ����ɋ}�ɋt�����Ɉړ�����ƁA�ꎞ��~���܂�
	};
	int mode_;

	//�v���C���[�̑傫��
	enum
	{
		SIZE_SMALL,
		SIZE_BIG,
		SIZE_SUPER,
	};
	int player_size;

	//�v���C���[���W�����v���Ă��邩�ǂ���
	bool is_jump;
	int jump_frame;

	bool player_enemy_hit = false;
	bool diy_jump = false;
	int diy_jump_count = 0;
	int image_diy_;
	bool enemy_hit = false;

	bool second_jump_player_enemy_hit = false;
	bool second_jump = false;
	int second_jump_count = 0;

	void Init();     //	����������
	void Update(bool& is_on_ground);	//	�X�V����
	void Render();	//	�`�揈��
	void Exit();		//	�I������
	void agaric_eat(Float2& agaric_pos, int& agaric_mode, Float2 map_pos, bool is_on_ground);  //	�v���C���[�ƃL���R�̓����蔻��

};