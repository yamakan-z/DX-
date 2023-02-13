//ゲームシーン
#include "DxLib.h"
#include "Manager.h"
#include "Game.h"
#include "Title.h"
#include "end.h"
#include "char.h"


//初期化
void CGame::Init() {
	//player追加
	base.emplace_back((unique_ptr<Base>)new Player());

	e_count = 0;//初期化

	img = LoadGraph("image\\back.png");//背景

	int map[10][9] =
	{
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,3,0,0,0,0,0,3,0},
		{3,0,0,0,3,0,0,0,3},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{2,2,2,2,2,2,2,2,2},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
	};

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			switch (map[y][x])
			{
			case ENEMY:
				base.emplace_back((unique_ptr<Base>)new Enemy(x * PLAYER_SIZE, y * PLAYER_SIZE));
				break;
			case ONEENEMY:
				base.emplace_back((unique_ptr<Base>)new OneEnemy(x * PLAYER_SIZE, y * PLAYER_SIZE));
				break;
			case TWOENEMY:
				base.emplace_back((unique_ptr<Base>)new TwoEnemy(x * PLAYER_SIZE, y * PLAYER_SIZE));
				break;
			}
			
		}
	}
	
}

int CGame::Update() {

	//listオブジェクトの更新処理
	for (auto i = base.begin(); i != base.end(); i++)
		(*i)->Action(base);

	//listのソート
	sort pr;
	if (base.size() > 2) base.sort(pr);

	//リストから削除処理
	for (auto i = base.begin(); i != base.end(); i++) {
		if ((*i)->FLAG == false) {
			i = base.erase(i);
			break;
		}
	}

	for (auto i = base.begin(); i != base.end(); i++)
	{
		e_count = (*i)->enemy_counter;
	}

	//敵を全て倒すとシーン移行
	if(e_count==17)
	{
		//リストのバックアップ
		list<unique_ptr<Base>> tmp_base;
		tmp_base.swap(base);

		manager->Scene_Delete();
		manager->scene = new CEnd(manager, tmp_base);
	}

	return 0;
}

void CGame::Draw() {

	DrawGraphF(0.0f, 0.0f, img, true);
	//listオブジェクトの描画
	for (auto i = base.begin(); i != base.end(); i++)
		if ((*i)->FLAG) (*i)->Draw();

	//DrawFormatStringF(0, 0, GetColor(255, 255, 255), "エンターキーでタイトルへ");
}