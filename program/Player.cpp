#include "Player.h"
#include "map.h"
#include "Game.h"
#include "Main.h"
#include "agaric.h"
#include "Hit.h"

//---------------------------------------------------------------------------------
//	�v���C���[�ƃL���R�̓����蔻��
//---------------------------------------------------------------------------------
void Player::agaric_eat(Float2& agaric_pos, int& agaric_mode)
{
	if (CheckBoxHit(pos_.x, pos_.y, PLAYER_IMAGE_W, PLAYER_IMAGE_H, agaric_pos.x, agaric_pos.y, AGARIC_IMAGE_SIZE, AGARIC_IMAGE_SIZE)
		&& agaric_mode == Agaric::MODE_MOVE)
	{
		agaric_mode = Agaric::MODE_DISAPPEAR;

		//�}���I�̉摜�͑傫���Ȃ�
		player_image_h = PLAYER_BIG_IMAGE_H;
		player_image_w = PLAYER_BIG_IMAGE_W;
		image_ = image_big;
		image_x = 0;
		player_size = SIZE_BIG;
		
	}
}

//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void Player::Init()
{
	//�v���C���[�̉摜�̏�����
	image_small = LoadGraph("data/player/Mario.png");
	image_big = LoadGraph("data/player/Mario_big.png");

	//�v���C���[�̉摜�͍ŏ��͔��]���Ȃ�����
	is_overturn = false;

	//�v���C���[�̃��[�h�ŏ���IDLE
	mode_ = MODE_IDLE;

	//�ŏ��̓W�����v���Ă��Ȃ�
	is_jump = false;
	jump_frame = 0;

	//�ŏ��͏������}���I
	player_image_h = PLAYER_IMAGE_H;
	player_image_w = PLAYER_IMAGE_W;
	image_ = image_small;
	player_size = SIZE_SMALL;
}

//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void Player::Update(bool& is_on_ground, bool is_wall_have, float& agaric_pos_x)
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
		image_x = 5 * player_image_w;
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
		if (is_jump == false)
		{
			player_frame++;
			if (player_frame % 10 == 0)
			{
				image_x += player_image_w;
				if (image_x >= 4 * player_image_w)
				{
					image_x = 0;
				}
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
	DrawRectGraphF(pos_.x, pos_.y, image_x, image_y, player_image_w, player_image_h, image_, TRUE, is_overturn);
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void Player::Exit()
{
	DeleteGraph(image_);
	DeleteGraph(image_small);
	DeleteGraph(image_big);
}
