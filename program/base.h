#pragma once
#include "Float2.h"

//---------------------------------------------------------------------------------
//	��{�N���X
//---------------------------------------------------------------------------------

class Base
{
public:

	virtual void Init();		//	����������
	virtual void Update();		//	�X�V����
	virtual void Render();		//	�`�揈��
	virtual void Exit();		//	�I������



	int image_;    //�摜

	Float2	pos_;		//	���W
	float	rot_;		//	����

	float	radius_;	//	���a

	Base();

};