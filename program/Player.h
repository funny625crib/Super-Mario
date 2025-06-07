#pragma once
#include "Float2.h"
#include "base.h"

class Player :
	public Base {

public:

	//�v���C���[�摜�̃T�C�Y
#define PLAYER_IMAGE_W 33
#define PLAYER_IMAGE_H 34

//�v���C���[�̈ړ��X�s�[�h
#define PLAYER_MOVE_SPEED    2.0f

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

	//�v���C���[���W�����v���Ă��邩�ǂ���
	bool is_jump;
	int jump_frame;

	void Init();     //	����������
	void Update(bool& is_on_ground, bool is_wall_have, float& agaric_pos_x);	//	�X�V����
	void Render();	//	�`�揈��
	void Exit();		//	�I������

};