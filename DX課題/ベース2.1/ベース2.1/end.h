//タイトルシーンヘッダ
#pragma once
#include "objBase.h"

class CEnd :public CScene {
public:
	list<unique_ptr<Base>> base;//オブジェクトリスト

	//コンストラクタ
	CEnd(CManager* pManager,list<unique_ptr<Base>>& _base) :CScene(pManager) { Init(_base); };

	int img{ -1 };	//画像ハンドル

	void Init(list<unique_ptr<Base>>& _base);//初期化
	int Update();
	void Draw();

	//デストラクタ
	~CEnd() {};
};