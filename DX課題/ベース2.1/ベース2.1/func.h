#pragma once
#include "objBase.h"

//ベクトル×スカラー
Vector Mul_Vector_Scaler(Vector v, float s);

//ベクトルの長さ
float Vector_Length(Vector v);

//ベクトルの正規化
Vector Vector_Normalize(Vector v);

//内積
float Vector_Dot(Vector v0, Vector v1);

//ベクトルの長さを設定
Vector Vector_SetLength(Vector v, float length);

//二点間距離
float DistanceF(float a, float b, float c, float d);

//指定したオブジェクト以外をリストから削除
void Del_SpecifiedObj(list<unique_ptr<Base>>& base, int ID);

//指定オブジェクトをリストから削除(FLAGをfalseにする)
void Del_ListObj(list<unique_ptr<Base>>& base, int ID);

//リストの指定オブジェクトの描画フラグを切り替え(base, FLG, objID)
void DrawFlgSwitch(list<unique_ptr<Base>>& base, bool flg, int ID);

//リストの指定オブジェクトの描画フラグを切り替え(base, FLG, objID)
void DrawFlgSwitch(list<unique_ptr<Base>>& base, bool flg, int ID);

//指定オブジェクトの座標取得
Point Get_Point(list<unique_ptr<Base>>& base, int ID);

//矩形判定(x1,y1,x2,y2,w,h)
int HitCheck_box(float x1, float y1, float x2, float y2, int w, int h);

//矩形判定２(x1,y1,x2,y2,w1,h1,w2,h2)
int HitCheck_box(float x1, float y1, float x2, float y2, int w1, int h1, int w2, int h2);

//円判定（x1,y1,x2,y2,r1,r2)
bool HitCheck_Circle(float x1, float y1, float x2, float y2, float r1, float r2);
