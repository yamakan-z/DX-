//ゲームシーンヘッダ
#pragma once
#include "objBase.h"

class CGame :public CScene
{
private:
public:
	list<unique_ptr<Base>> base;//オブジェクトリスト

	CGame(CManager* pManager) :CScene(pManager) { Init(); };
	~CGame() {};

	void Init();//初期化
	int Update();//更新処理
	void Draw();//描画処理
};