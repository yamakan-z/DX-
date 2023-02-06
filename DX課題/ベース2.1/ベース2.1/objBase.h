//オブジェクトベースヘッダ
#pragma once
#include "DxLib.h"
#include "main.h"
#include <list>
#include <memory>

using namespace std;

class Base;

class Base {
public:
	int img{ -1 };//画像
	int pri{ 0 };//描画の順番
	int ID{ -1 };//オブジェクトID
	bool FLAG{ true };//オブジェクト存在フラグ
	bool draw_flag{ true };//描画のon/off

	virtual int Action(list<unique_ptr<Base>>& base) = 0;
	virtual void Draw() = 0;
	virtual Point Pos() = 0;//オブジェクトの位置取得
	virtual ~Base() { DeleteGraph(img); };

	// 位置
	VECTOR size = { 0, 0 };

};

//オブジェクトのソートクラス
class sort
{
private:
public:
	bool operator()(const unique_ptr<Base>& x, const unique_ptr<Base>& y) const
	{
		return x.get()->pri < y.get()->pri;
	}
};