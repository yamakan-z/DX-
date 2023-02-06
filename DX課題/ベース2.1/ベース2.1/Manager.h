//シーン管理用ヘッダ
#pragma once

class CManager;//シーン管理クラス

//シーンの基底クラス
class CScene {
protected:
	CManager* manager{ nullptr };
public:
	CScene(CManager* pManager) { manager = pManager; };

	//更新処理
	virtual int Update() { return 0; };
	//描画処理
	virtual void Draw() {};
	//デストラクタ
	virtual ~CScene() {};
};

//シーン管理クラス
class CManager {
public:
	//シーンポインタ
	CScene* scene{ nullptr };

	CManager() {};
	int Update() { scene->Update(); return 0; };
	void Draw() { scene->Draw(); };

	//シーンの削除
	void Scene_Delete() {
		scene->~CScene();
	}

	~CManager() { delete scene; };
};

