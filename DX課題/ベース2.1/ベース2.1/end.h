//�^�C�g���V�[���w�b�_
#pragma once
#include "objBase.h"

class CEnd :public CScene {
public:
	list<unique_ptr<Base>> base;//�I�u�W�F�N�g���X�g

	//�R���X�g���N�^
	CEnd(CManager* pManager,list<unique_ptr<Base>>& _base) :CScene(pManager) { Init(_base); };

	int img{ -1 };	//�摜�n���h��

	void Init(list<unique_ptr<Base>>& _base);//������
	int Update();
	void Draw();

	//�f�X�g���N�^
	~CEnd() {};
};