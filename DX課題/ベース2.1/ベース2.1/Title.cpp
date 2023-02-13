//タイトル画面
#pragma once
#include "main.h"
#include "Manager.h"
#include "Title.h"
#include "Game.h"

//初期化
void CTitle::Init() {
	img = LoadGraph("image\\title.png");
}

//更新処理
int CTitle::Update() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		//ゲームシーンに移行
		manager->Scene_Delete();
		manager->scene = new CGame(manager);
	}

	return 0;
}

//描画処理
void CTitle::Draw() {
	DrawGraphF(0.0f, 0.0f, img, true);

	//DrawFormatStringF(0, 0, GetColor(255, 255, 255), "スペースキーでタイトルへ");
}