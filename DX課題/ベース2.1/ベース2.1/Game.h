//�Q�[���V�[���w�b�_
#pragma once
#include "objBase.h"

class CGame :public CScene
{
private:
public:
	list<unique_ptr<Base>> base;//�I�u�W�F�N�g���X�g

	CGame(CManager* pManager) :CScene(pManager) { Init(); };
	~CGame() {};

	int e_count;//�G���j��

	int img{ -1 };	//�摜�n���h��

	void Init();//������
	int Update();//�X�V����
	void Draw();//�`�揈��
};