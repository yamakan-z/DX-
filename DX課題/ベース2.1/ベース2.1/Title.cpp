//�^�C�g�����
#pragma once
#include "main.h"
#include "Manager.h"
#include "Title.h"
#include "Game.h"

//������
void CTitle::Init() {
	img = LoadGraph("image\\title.png");
}

//�X�V����
int CTitle::Update() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		//�Q�[���V�[���Ɉڍs
		manager->Scene_Delete();
		manager->scene = new CGame(manager);
	}

	return 0;
}

//�`�揈��
void CTitle::Draw() {
	DrawGraphF(0.0f, 0.0f, img, true);

	//DrawFormatStringF(0, 0, GetColor(255, 255, 255), "�X�y�[�X�L�[�Ń^�C�g����");
}