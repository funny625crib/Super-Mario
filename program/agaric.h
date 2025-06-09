#pragma once
#include "Float2.h"
#include "base.h"

class Agaric :
	public Base {

public:

	void Init();     //	����������
	void Update(int pos,int pos_y, bool is_hit,int map_pos_x);	//	�X�V����
	void Render();	//	�`�揈��
	void Exit();		//	�I������

	//�L�m�R�̈ړ����[�h
	enum
	{
		MODE_WAIT,
		MODE_APPEAR,
		MODE_MOVE,
		MODE_DISAPPEAR,
	};
	int mode_;

	//�L�m�R�̈ړ��X�s�[�h
	float speed;
};