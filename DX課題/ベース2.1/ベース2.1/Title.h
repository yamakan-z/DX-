//�^�C�g���V�[���w�b�_
#pragma once

class CTitle :public CScene {
public:
	//�R���X�g���N�^
	CTitle(CManager* pManager) :CScene(pManager) { Init(); };

	int img{ -1 };	//�摜�n���h��

	void Init();//������
	int Update();
	void Draw();

	//�f�X�g���N�^
	~CTitle() {};
};