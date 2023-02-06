//DX Library Copyright (C) 2001-2022 Takumi Yamada.
#pragma once
#include "DxLib.h"
#include <list>
#include <memory>

//ウィンドウサイズ
constexpr auto WINDOW_WIDTH = 600;	//横幅
constexpr auto WINDOW_HEIGHT = 800;	//縦幅

//プレイヤーサイズ
constexpr auto PLAYER_SIZE = 96;
//64サイズ
constexpr auto IMGSIZE64 = 64;

constexpr auto IMGSIZE32 = 32;

// 自然に減速させるための係数
//----------------------------------------------------
const float PARAM_DEC = 0.99f;
//----------------------------------------------------
// スピードがこれ以下になると止まる
//----------------------------------------------------
const float PARAM_STOP = 0.2f;

//位置
typedef struct Point {
	float x, y;
}Point;

//ベクトル
typedef struct Vector {
	float x, y;
}Vector;

//オブジェクトID
enum
{
	PLAYER,//プレイヤー
	ENEMY,//敵
};