//�G
#pragma once
#include "char.h"

//�R���X�g���N�^
Enemy::Enemy(float _x, float _y) {
	img = LoadGraph("image\\enemy.png");

	pos.x = _x;
	pos.y = _y;

	ID = ENEMY;
}

//����
int Enemy::Action(list<unique_ptr<Base>>& base) {


	return 0;
}

//�`��
void Enemy::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}