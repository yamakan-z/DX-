#pragma once
#include "objBase.h"

//�x�N�g���~�X�J���[
Vector Mul_Vector_Scaler(Vector v, float s);

//�x�N�g���̒���
float Vector_Length(Vector v);

//�x�N�g���̐��K��
Vector Vector_Normalize(Vector v);

//����
float Vector_Dot(Vector v0, Vector v1);

//�x�N�g���̒�����ݒ�
Vector Vector_SetLength(Vector v, float length);

//��_�ԋ���
float DistanceF(float a, float b, float c, float d);

//�w�肵���I�u�W�F�N�g�ȊO�����X�g����폜
void Del_SpecifiedObj(list<unique_ptr<Base>>& base, int ID);

//�w��I�u�W�F�N�g�����X�g����폜(FLAG��false�ɂ���)
void Del_ListObj(list<unique_ptr<Base>>& base, int ID);

//���X�g�̎w��I�u�W�F�N�g�̕`��t���O��؂�ւ�(base, FLG, objID)
void DrawFlgSwitch(list<unique_ptr<Base>>& base, bool flg, int ID);

//���X�g�̎w��I�u�W�F�N�g�̕`��t���O��؂�ւ�(base, FLG, objID)
void DrawFlgSwitch(list<unique_ptr<Base>>& base, bool flg, int ID);

//�w��I�u�W�F�N�g�̍��W�擾
Point Get_Point(list<unique_ptr<Base>>& base, int ID);

//��`����(x1,y1,x2,y2,w,h)
int HitCheck_box(float x1, float y1, float x2, float y2, int w, int h);

//��`����Q(x1,y1,x2,y2,w1,h1,w2,h2)
int HitCheck_box(float x1, float y1, float x2, float y2, int w1, int h1, int w2, int h2);

//�~����ix1,y1,x2,y2,r1,r2)
bool HitCheck_Circle(float x1, float y1, float x2, float y2, float r1, float r2);
