#pragma once
#include "func.h"

//ベクトル×スカラー
Vector Mul_Vector_Scaler(Vector v, float s)
{
	Vector r;
	r.x = v.x * s;
	r.y = v.y * s;

	return (r);
}

//ベクトルの長さ
float Vector_Length(Vector v) {
	float l = sqrtf((v.x * v.x + v.y * v.y));
	return l;
}

//ベクトルの正規化
Vector Vector_Normalize(Vector v) {
	float l = Vector_Length(v);
	Vector n;

	n.x = v.x / l;
	n.y = v.y / l;

	return n;
}

//内積
float Vector_Dot(Vector v0, Vector v1)
{
	float r;
	r = (v0.x * v1.x) + (v0.y * v1.y);
	return r;
}

//ベクトルの長さを設定
Vector Vector_SetLength(Vector v, float length)
{
	v = Vector_Normalize(v);
	v = Mul_Vector_Scaler(v, length);

	return (v);
}


//二点間距離
float DistanceF(float a, float b, float c, float d) {
	return sqrtf((a - c) * (a - c) + (b - d) * (b - d));
}

//指定したオブジェクト以外をリストから削除
void Del_SpecifiedObj(list<unique_ptr<Base>>& base, int ID) {
	for (auto i = base.begin(); i != base.end(); i++) {
		if ((*i)->ID != ID) {
			(*i)->FLAG = false;
			(*i)->ID = -1;
		}
	}
}

//指定オブジェクトをリストから削除(FLAGをfalseにする)
void Del_ListObj(list<unique_ptr<Base>>& base, int ID) {
	for (auto i = base.begin(); i != base.end(); i++) {
		if ((*i)->ID == ID) {
			(*i)->FLAG = false;
			(*i)->ID = -1;
		}
	}
}

//リストの指定オブジェクトの描画フラグを切り替え(base, FLG, objID)
void DrawFlgSwitch(list<unique_ptr<Base>>& base, bool flg, int ID) {
	for (auto i = base.begin(); i != base.end(); i++) {
		if ((*i)->ID == ID) {
			(*i)->draw_flag = flg;
		}
	}
}

//指定オブジェクトの座標取得
Point Get_Point(list<unique_ptr<Base>>& base, int ID) {
	Point p{ 0,0 };

	for (auto i = base.begin(); i != base.end(); i++) {
		if ((*i)->ID == ID) return (*i)->Pos();
	}

	return p;
}

//矩形判定(x1,y1,x2,y2,w,h)
int HitCheck_box(float x1, float y1, float x2, float y2, int w, int h) {
	if (x1 < x2 + w && x2 < x1 + w &&
		y1 < y2 + h && y2 < y1 + h) {
		return 1;
	}
	return 0;
}

//矩形判定２(x1,y1,x2,y2,w1,h1,w2,h2)
int HitCheck_box(float x1, float y1, float x2, float y2, int w1, int h1, int w2, int h2) {
	if (x1 < x2 + w2 && x2 < x1 + w1 &&
		y1 < y2 + h2 && y2 < y1 + h1) {
		return 1;
	}
	return 0;
}

//円判定(x1,y1,x2,y2,r1,r2)
bool HitCheck_Circle(float x1, float y1, float x2, float y2, float r1, float r2)
{
	float l = sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

	if (l < (r1 + r2)) return true;

	return false;
}