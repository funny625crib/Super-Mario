#pragma once
#include "base.h"

//---------------------------------------------------------------------------------
//	��{�N���X
//---------------------------------------------------------------------------------

class Map :
	public Base
{
public:

	void Init();		//	����������
	void Update();		//	�X�V����
	void Render();		//	�`�揈��
	void Exit();		//	�I������

private:

	int Ground_image_;          //�n�ʂ̉摜
	int Wall_image_;            //�ǂ̉摜
	int box_image_;             //���̉摜
	int coin_image_;

#define MAP_H
#define MAP_W
	//�}�b�v�p�ϐ�
	

};