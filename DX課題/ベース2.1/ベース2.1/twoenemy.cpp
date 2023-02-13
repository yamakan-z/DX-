#pragma once
#include "char.h"
#include "func.h"

//�R���X�g���N�^
TwoEnemy::TwoEnemy(float _x, float _y) {
	img = LoadGraph("image\\enemy2.png");

	pos.x = _x;
	pos.y = _y;

	hitcount = 0;

	ID = TWOENEMY;
}

//����
int TwoEnemy::Action(list<unique_ptr<Base>>& base) {

	if (hitcount == 2)
	{
		FLAG = false;
	}


	return 0;
}


//�`��
void TwoEnemy::Draw() {
	DrawFormatStringF(pos.x, pos.y - 25, GetColor(255, 255, 255), "%d", hitcount);//�v���C���[�ɓ��������񐔕\��
	DrawGraphF(pos.x, pos.y, img, TRUE);
}