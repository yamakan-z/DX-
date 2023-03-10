/*
<Dxライブラリ用>
Dxライブラリ用にプロパティを変更する必要あり。
現在は、Dxライブラリで必要なファイルは、c:\dxlibに設定
*/
#pragma once
#include "main.h"
#include "Manager.h"
#include "Title.h"

constexpr auto FPS = 60;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdline, _In_ int nShowCmd) 
{
	//Dxライブラリのログ出力off
	SetOutApplicationLogValidFlag(false);

	//windowモード切り替え
	ChangeWindowMode(true);
	//windowサイズ
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	//バックグラウンド処理の許可
	SetAlwaysRunFlag(true);
	//多重起動の許可
	SetDoubleStartValidFlag(true);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1) return -1;

	//windowの名前
	SetWindowText("");

	//描画先をバックバッファに設定
	SetDrawScreen(DX_SCREEN_BACK);

	//シーン管理クラス
	CManager* manager = new CManager();
	
	//初回シーン
	manager->scene = new CTitle(manager);

	//ループ
	while (true) {
		ClearDrawScreen();	//画面クリア

		double nextTime = GetNowCount();	//現在時間の取得

		//シーンの更新と描画処理
		manager->Update();
		manager->Draw();

		//FPS処理
		nextTime += 1000 / FPS;	//1フレームにかかる時間を加算
		if (nextTime > GetNowCount()) {
			//処理時間が指定FPSの時間が経過していない場合、経過まで待機
			WaitTimer((int)nextTime - GetNowCount());
		}

		ScreenFlip();	//画面を更新

		//escキーでプログラム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) || (ProcessMessage() == -1)) break;
	}

	//シーンの削除
	delete manager;

	//Dxライブラリ終了処理
	DxLib_End();

	return 0;
}