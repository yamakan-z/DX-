//�G���h���
#pragma once
#include "main.h"
#include "Manager.h"
#include "end.h"
#include "Title.h"

//������
void CEnd::Init(list<unique_ptr<Base>>& _base) {
	_base.swap(base);
	img = LoadGraph("image\\clear.png");
}

//�X�V����
int CEnd::Update() {
	for (auto i = base.begin(); i != base.end(); i++)
		(*i)->Action(base);

	if (CheckHitKey(KEY_INPUT_A)) {
		//�^�C�g���V�[���Ɉڍs
		manager->Scene_Delete();
		manager->scene = new CTitle(manager);
	}

	return 0;
}

//�`�揈��
void CEnd::Draw() {
	DrawGraphF(0.0f, 0.0f, img, true);

	DrawFormatStringF(0, 0, GetColor(255, 255, 255), "�G���h�V�[��\nA�L�[�Ń^�C�g����");
	/*for (auto i = base.begin(); i != base.end(); i++)
		(*i)->Draw();*/
}