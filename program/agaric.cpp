#include "agaric.h"
#include "map.h"
#include "Game.h"
#include "Main.h"


//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void Agaric::Init()
{
	image_ = LoadGraph("data/map/agaric.png");   //�L���R�摜������������
	pos_ = { 20 * GROUND_SIZE,8 * GROUND_SIZE };  //���W������������
	mode_ = MODE_WAIT;                            //�L�m�R�̃��[�h������������
	speed = 1.0f;
}
//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void Agaric::Update(int pos_x, int pos_y, bool is_hit, int map_pos_x)
{


	switch (mode_)
	{
	case MODE_WAIT:
		//�v���C���[�̓L�m�R�����锠�ɓ�����O��
			//�L�m�R�Ɣ��̍��W������
		if (is_hit == false)
		{
			pos_.x = (float)(pos_x);
			pos_.y = (float)(pos_y);
		}
		else
		{
			mode_ = MODE_APPEAR;
		}
		break;
	case MODE_APPEAR:

		pos_.y--;
		if (pos_.y < (float)(pos_y - GROUND_SIZE))
		{
			pos_.y = (float)(pos_y - GROUND_SIZE);
			pos_.x = (float)(pos_x);
			mode_ = MODE_MOVE;
		}
		break;

	case MODE_MOVE:
		pos_.x += speed;
		
		break;

	case MODE_DISAPPEAR:

		break;
	}

}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void Agaric::Render()
{
	if (mode_ != MODE_DISAPPEAR)
	{
		DrawGraph(pos_.x, pos_.y, image_, TRUE);
	}

	DrawFormatString(10, 40, GetColor(255, 255, 255), "speed:%f", speed);
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void Agaric::Exit()
{
	DeleteGraph(image_);
}
