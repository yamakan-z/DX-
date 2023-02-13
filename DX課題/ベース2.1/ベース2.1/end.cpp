//エンド画面
#pragma once
#include "main.h"
#include "Manager.h"
#include "end.h"
#include "Title.h"

//初期化
void CEnd::Init(list<unique_ptr<Base>>& _base) {
	_base.swap(base);
	img = LoadGraph("image\\clear.png");
}

//更新処理
int CEnd::Update() {
	for (auto i = base.begin(); i != base.end(); i++)
		(*i)->Action(base);

	if (CheckHitKey(KEY_INPUT_A)) {
		//タイトルシーンに移行
		manager->Scene_Delete();
		manager->scene = new CTitle(manager);
	}

	return 0;
}

//描画処理
void CEnd::Draw() {
	DrawGraphF(0.0f, 0.0f, img, true);

	DrawFormatStringF(0, 0, GetColor(255, 255, 255), "エンドシーン\nAキーでタイトルへ");
	/*for (auto i = base.begin(); i != base.end(); i++)
		(*i)->Draw();*/
}