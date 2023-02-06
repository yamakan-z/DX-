//タイトルシーンヘッダ
#pragma once

class CTitle :public CScene {
public:
	//コンストラクタ
	CTitle(CManager* pManager) :CScene(pManager) { Init(); };

	int img{ -1 };	//画像ハンドル

	void Init();//初期化
	int Update();
	void Draw();

	//デストラクタ
	~CTitle() {};
};