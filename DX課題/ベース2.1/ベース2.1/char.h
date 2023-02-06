#pragma once
#include "objBase.h"
#include "main.h"

//player�N���X
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

	// img ���B�����邽�߂ɗp��
	void Load(const TCHAR* name)
	{
		// TODO: ��x�m�ۂ����t�@�C����img�𓯂����̂�Ԃ��ׂ��B
		img = LoadGraph(name);
		// �C���[�W�̃T�C�Y���擾����
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

//enemhy�N���X
class Enemy :public Base
{
private:
	Point pos{ 0,0 };
	Vector vec{ 0,0 };
public: 
	Enemy(float _x, float _y);//�R���X�g���N�^

	int Action(list<unique_ptr<Base>>& base);

	void Draw();

	Point Pos() { return pos; };//�ʒu��Ԃ�
};