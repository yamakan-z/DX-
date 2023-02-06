//DX Library Copyright (C) 2001-2022 Takumi Yamada.
#pragma once
#include "DxLib.h"
#include <list>
#include <memory>

//�E�B���h�E�T�C�Y
constexpr auto WINDOW_WIDTH = 600;	//����
constexpr auto WINDOW_HEIGHT = 800;	//�c��

//�v���C���[�T�C�Y
constexpr auto PLAYER_SIZE = 96;
//64�T�C�Y
constexpr auto IMGSIZE64 = 64;

constexpr auto IMGSIZE32 = 32;

// ���R�Ɍ��������邽�߂̌W��
//----------------------------------------------------
const float PARAM_DEC = 0.99f;
//----------------------------------------------------
// �X�s�[�h������ȉ��ɂȂ�Ǝ~�܂�
//----------------------------------------------------
const float PARAM_STOP = 0.2f;

//�ʒu
typedef struct Point {
	float x, y;
}Point;

//�x�N�g��
typedef struct Vector {
	float x, y;
}Vector;

//�I�u�W�F�N�gID
enum
{
	PLAYER,//�v���C���[
	ENEMY,//�G
};