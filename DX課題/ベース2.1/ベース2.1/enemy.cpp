//敵
#pragma once
#include "char.h"

//コンストラクタ
Enemy::Enemy(float _x, float _y) {
	img = LoadGraph("image\\enemy.png");

	pos.x = _x;
	pos.y = _y;

	ID = ENEMY;
}

//処理
int Enemy::Action(list<unique_ptr<Base>>& base) {


	return 0;
}

//描画
void Enemy::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}