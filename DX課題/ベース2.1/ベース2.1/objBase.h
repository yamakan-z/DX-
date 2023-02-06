//�I�u�W�F�N�g�x�[�X�w�b�_
#pragma once
#include "DxLib.h"
#include "main.h"
#include <list>
#include <memory>

using namespace std;

class Base;

class Base {
public:
	int img{ -1 };//�摜
	int pri{ 0 };//�`��̏���
	int ID{ -1 };//�I�u�W�F�N�gID
	bool FLAG{ true };//�I�u�W�F�N�g���݃t���O
	bool draw_flag{ true };//�`���on/off

	virtual int Action(list<unique_ptr<Base>>& base) = 0;
	virtual void Draw() = 0;
	virtual Point Pos() = 0;//�I�u�W�F�N�g�̈ʒu�擾
	virtual ~Base() { DeleteGraph(img); };

	// �ʒu
	VECTOR size = { 0, 0 };

};

//�I�u�W�F�N�g�̃\�[�g�N���X
class sort
{
private:
public:
	bool operator()(const unique_ptr<Base>& x, const unique_ptr<Base>& y) const
	{
		return x.get()->pri < y.get()->pri;
	}
};