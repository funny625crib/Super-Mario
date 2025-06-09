#pragma once
#include "Float2.h"
#include "base.h"

class Agaric :
	public Base {

public:

	//�L���R�摜�̃T�C�Y
#define AGARIC_IMAGE_SIZE 35



	void Init();     //	����������
	void Update(int pos, int pos_y, bool is_hit, int map_pos_x);	//	�X�V����
	void Render();	//	�`�揈��
	void Exit();		//	�I������

	//�L�m�R�̈ړ����[�h
	enum
	{
		MODE_WAIT,
		MODE_APPEAR,
		MODE_MOVE,
		MODE_DISAPPEAR,   //�v���C���[���L���R��H�ׂ���
	};
	int mode_;

	//�L�m�R�̈ړ��X�s�[�h
	float speed;
};