//敵
#pragma once
#include "char.h"
#include "func.h"

//コンストラクタ
Enemy::Enemy(float _x, float _y) {
	img = LoadGraph("image\\n_enemy.png");

	pos.x = _x;
	pos.y = _y;

	hitcount = 0;

	ID = ENEMY;
}

//処理
int Enemy::Action(list<unique_ptr<Base>>& base) {

	if (hitcount == 3)
	{
		FLAG = false;
	}


	return 0;
}


//描画
void Enemy::Draw() {
	DrawFormatStringF(pos.x, pos.y-25, GetColor(255, 255, 255), "%d",hitcount);//プレイヤーに当たった回数表示
	DrawGraphF(pos.x, pos.y, img, TRUE);
}