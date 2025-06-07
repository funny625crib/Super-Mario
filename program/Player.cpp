#include "Player.h"
#include "map.h"
#include "Game.h"
#include "Main.h"


//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void Player::Init()
{
	//�v���C���[�̉摜�̏�����
	image_ = LoadGraph("data/player/Mario.png");

	//�v���C���[�̉摜�͍ŏ��͔��]���Ȃ�����
	is_overturn = false;

	//�v���C���[�̃��[�h�ŏ���IDLE
	mode_ = MODE_IDLE;

	//�ŏ��̓W�����v���Ă��Ȃ�
	is_jump = false;
	jump_frame = 0;
}

//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void Player::Update(bool& is_on_ground, bool is_wall_have,float& agaric_pos_x)
{

	//�t���[��
	static int player_frame;

	//�ꎞ�Ă��Ƀv���C���[�̑���ɑ��삷��
	if (PushHitKey(KEY_INPUT_SPACE) && is_on_ground == true)
	{
		is_jump = true;
		is_on_ground = false;
		jump_frame = 0;
	}

	if (CheckHitKey(KEY_INPUT_D) && is_wall_have == false)
	{
		agaric_pos_x -= 3.0f;
		mode_ = MODE_MOVE;
		pos_.x += PLAYER_MOVE_SPEED;     //RIGHT
		//�摜�𔽓]���܂���
		is_overturn = false;

	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		mode_ = MODE_MOVE;
		pos_.x -= PLAYER_MOVE_SPEED;     //LEFT
		//�摜�𔽓]���܂���
		is_overturn = true;
	}

	if (is_jump == true)
	{
		jump_frame++;
		if (jump_frame < 20)
		{
			pos_.y -= 15.0f;
		}

		//�W�����v�̉摜�ɕς���
		image_x = 5 * PLAYER_IMAGE_W;
	}



	//���̃L�[��������Ă��Ȃ��Ƃ�
	if (CheckHitKeyAll() == 0)
	{
		mode_ = MODE_IDLE;
	}



	if (pos_.x > SCREEN_W / 2)
	{
		pos_.x = SCREEN_W / 2;
	}

	//�v���C���[�̃��[�h�ɑ΂��鏈��
	switch (mode_)
	{
	case MODE_IDLE:
		if (is_jump == false)
		{
			image_x = 0;
		}

		break;
	case MODE_MOVE:
		//�v���C���[�̈ړ��ɔ����ĉ摜���ω�����
		player_frame++;
		if (player_frame % 10 == 0)
		{
			image_x += PLAYER_IMAGE_W;
			if (image_x >= 4 * PLAYER_IMAGE_W)
			{
				image_x = 0;
			}
		}
		break;

	}

}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void Player::Render()
{
	DrawRectGraphF(pos_.x, pos_.y, image_x, image_y, PLAYER_IMAGE_W, PLAYER_IMAGE_H, image_, TRUE, is_overturn);
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void Player::Exit()
{
	DeleteGraph(image_);
}
