#pragma once
#include "objBase.h"
#include "main.h"

//playerクラス
class Player :public Base {
private:
	Point pos{ 0,0 };
	Vector vec{ 0,0 };
public:
	Player();

	enum STAT
	{
		IDLE = 0,
		DRAG,
		RELEASE,
		STOP,
	};


	int Action(list<unique_ptr<Base>>& base);
	void Draw();
	void DrawArrow(const Point& pos, const VECTOR& spd);

	Point Pos() { return pos; };

	// img を隠蔽するために用意
	void Load(const TCHAR* name)
	{
		// TODO: 一度確保したファイルはimgを同じものを返すべき。
		img = LoadGraph(name);
		// イメージのサイズを取得する
		int size_x, size_y;
		GetImageSize_File(name, &size_x, &size_y);
		size.x = (float)size_x;
		size.y = (float)size_y;
	}

	~Player() {};

protected:
	VECTOR spd = { 0,0,0 };
	int sx = 0, sy = 0;

	STAT mode = IDLE;
};

//enemhyクラス
class Enemy :public Base
{
private:
	Point pos{ 0,0 };
	Vector vec{ 0,0 };
public: 
	Enemy(float _x, float _y);//コンストラクタ

	int Action(list<unique_ptr<Base>>& base);

	void Draw();

	Point Pos() { return pos; };//位置を返す
};