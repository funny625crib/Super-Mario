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
		pos_.x ++;
		if (pos_.x > (float)(pos_x + 4 * GROUND_SIZE))
		{
			pos_.x--;
			pos_.y+=2.0f;
		}
		if (pos_.y >= (float)(pos_y + 3 * GROUND_SIZE))
		{
			pos_.y = (float)(pos_y + 3 * GROUND_SIZE);
			pos_.x++;
		}
		break;
	}

}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void Agaric::Render()
{
	DrawGraph(pos_.x, pos_.y, image_, TRUE);
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void Agaric::Exit()
{
	DeleteGraph(image_);
}
