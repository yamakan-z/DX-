#pragma once
#include "char.h"
#include "func.h"

//コンストラクタ
OneEnemy::OneEnemy(float _x, float _y) {
	img = LoadGraph("image\\enemy1.png");

	pos.x = _x;
	pos.y = _y;

	hitcount = 0;

	ID = ONEENEMY;
}

//処理
int OneEnemy::Action(list<unique_ptr<Base>>& base) {

	if (hitcount == 1)
	{
		FLAG = false;
	}


	return 0;
}


//描画
void OneEnemy::Draw() {
	DrawFormatStringF(pos.x, pos.y - 25, GetColor(255, 255, 255), "%d", hitcount);//プレイヤーに当たった回数表示
	DrawGraphF(pos.x, pos.y, img, TRUE);
}