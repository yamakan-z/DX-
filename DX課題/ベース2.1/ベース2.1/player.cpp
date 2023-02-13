#pragma once
#include "char.h"
#include "func.h"

constexpr auto x_Speed = 4.0f;
constexpr auto y_Speed = 4.0f;

Player::Player() {
	//�摜�̓ǂݍ���
	img = LoadGraph("image\\player_a.png");

	//�����ʒu
	pos.x = WINDOW_WIDTH / 2;
	pos.y = WINDOW_HEIGHT - PLAYER_SIZE;

}

int Player::Action(list<unique_ptr<Base>>& base)
{

	unsigned int Cr;

	//�����J���[�ݒ�
	Cr = GetColor(255, 255, 255);
	
	int mouse = GetMouseInput();

	switch (mode)
	{
	case IDLE:
	{
		// �N���b�N����
		if (mouse & MOUSE_INPUT_LEFT)
		{
			GetMousePoint(&sx, &sy);

			// �}�E�X�h���b�O��Ԃ�
			mode = DRAG;
		}
		break;
	}
	case DRAG:
	{
		// �h���b�O�ʒu����u��������v�����X�s�[�h�̑傫���Ɋ��Z
		int x, y;
		GetMousePoint(&x, &y);
		spd.x = (sx - x) * 0.1f;
		spd.y = (sy - y) * 0.1f;

		// ���\��
		DrawArrow(pos, spd);

		// �}�E�X��b�������ԏ���
		if ((mouse & MOUSE_INPUT_LEFT) == 0)
		{
			mode = RELEASE;
		}
		break;
	}
	case RELEASE:
	{
		// �ړ���(�قƂ�ǎ~�܂���?)
		// �X�s�[�h��0.1�ȉ��Ȃ�Ύ~�߂� (���悩�画��)
		if (VSquareSize(spd) < 0.1f * 0.1f)
		{
			spd.x = 0;
			spd.y = 0;
			mode = STOP;
		}
		pos.x += spd.x;
		pos.y += spd.y;

		// �ǂɓ��������璵�˕Ԃ点��
		// �ǂł̃X�s�[�h�����͂Ȃ�

		// ���̕�
		if (pos.x < 0)
		{
			pos.x = -pos.x;
			spd.x = -spd.x;
		}
		// �E�̕�
		if (pos.x > WINDOW_WIDTH - PLAYER_SIZE)
		{
			pos.x = (WINDOW_WIDTH - PLAYER_SIZE) * 2 - pos.x;
			spd.x = -spd.x;
		}
		// ��̕�
		if (pos.y < 0)
		{
			pos.y = -pos.y;
			spd.y = -spd.y;
		}
		// ���̕� 
		if (pos.y > WINDOW_HEIGHT - PLAYER_SIZE)
		{
			pos.y = (WINDOW_HEIGHT - PLAYER_SIZE) * 2 - pos.y;
			spd.y = -spd.y;
		}

		spd.x *= PARAM_DEC;
		spd.y *= PARAM_DEC;



		break;
	}
	case 3:
	{
		mode = IDLE;
		break;
	}
	}

	//���菈��
	Point enemy_pos{ 0,0 };
	
	
	for (auto i = base.begin(); i != base.end(); i++)
	{
		//���肷��G�̍��W�擾
		if ((*i)->ID == ENEMY)
		{
			enemy_pos = (*i)->Pos();

			if (HitCheck_box(pos.x, pos.y, enemy_pos.x, enemy_pos.y, IMGSIZE32, IMGSIZE32, IMGSIZE64, IMGSIZE64))
			{

				(*i)->hitcount++;

				if ((*i)->hitcount == 3)
				{
					enemy_counter++;//�|���ƓG�J�E���^�[+1
				}
				
				spd.x = -spd.x;
				spd.y = -spd.y;
				
			}
		}

		if ((*i)->ID == ONEENEMY)
		{
			enemy_pos = (*i)->Pos();

			if (HitCheck_box(pos.x, pos.y, enemy_pos.x, enemy_pos.y, IMGSIZE32, IMGSIZE32, IMGSIZE64, IMGSIZE64))
			{

				(*i)->hitcount++;

				if ((*i)->hitcount == 1)
				{
					enemy_counter++;//�|���ƓG�J�E���^�[+1
				}
				
				spd.x = -spd.x;
				spd.y = -spd.y;

			}
		}

		if ((*i)->ID == TWOENEMY)
		{
			enemy_pos = (*i)->Pos();

			if (HitCheck_box(pos.x, pos.y, enemy_pos.x, enemy_pos.y, IMGSIZE32, IMGSIZE32, IMGSIZE64, IMGSIZE64))
			{

				(*i)->hitcount++;

				if ((*i)->hitcount == 2)
				{
					enemy_counter++;//�|���ƓG�J�E���^�[+1
				}
				
				spd.x = -spd.x;
				spd.y = -spd.y;

			}
		}
	}

	
	return 0;
}

void Player::Draw()
{
	//DrawFormatStringF(pos.x, pos.y - 90, GetColor(255, 255, 255), "spd.x:%d", enemy_counter);//�v���C���[�ɓ��������񐔕\��
	
	DrawGraphF(pos.x, pos.y, img, true);
	
}


// ���`��
void Player::DrawArrow(const Point& pos, const VECTOR& spd)
{
	int xx = (int)(pos.x + (int)(spd.x * 5));
	int yy = (int)(pos.y + (int)(spd.y * 5));

	// ���̑���
	int bar = (int)(sqrtf(spd.x * spd.x + spd.y * spd.y)) + 2;

	// �F�̐ݒ�
	int r = bar * 5 + 40 > 255 ? 255 : bar * 5 + 40;
	unsigned int color = GetColor(r, 64, 64);

	DrawLine((int)(pos.x + size.x * 0.5f),
		(int)(pos.y + size.y * 0.5f),

		(int)(xx + spd.x * 0.5f + size.x * 0.5f),
		(int)(yy + spd.y * 0.5f + size.y * 0.5f),

		color, bar);

	DrawTriangle((int)(xx + size.x * 0.5f + spd.y * 1), (int)(yy + size.y * 0.5f - spd.x * 1),
		(int)(xx + size.x * 0.5f - spd.y * 1), (int)(yy + size.y * 0.5f + spd.x * 1),
		(int)(xx + size.x * 0.5f + spd.x * 3), (int)(yy + size.y * 0.5f + spd.y * 3),

		color, 1);
}