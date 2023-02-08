//�G
#pragma once
#include "char.h"
#include "func.h"

//�R���X�g���N�^
Enemy::Enemy(float _x, float _y) {
	img = LoadGraph("image\\n_enemy.png");

	pos.x = _x;
	pos.y = _y;

	hitcount = 0;

	ID = ENEMY;
}

//����
int Enemy::Action(list<unique_ptr<Base>>& base) {

	if (hitcount == 3)
	{
		FLAG = false;
	}


	return 0;
}


//�`��
void Enemy::Draw() {
	DrawFormatStringF(pos.x, pos.y-25, GetColor(255, 255, 255), "%d",hitcount);//�v���C���[�ɓ��������񐔕\��
	DrawGraphF(pos.x, pos.y, img, TRUE);
}