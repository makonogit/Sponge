#pragma once
#include"main.h"
//********************************
//�}�N����`
//********************************
#define Window_Height 480 //��ʏc��
#define Window_Width 640 //��ʉ���

//********************************
//�\���̒�`
//********************************
typedef struct {
	int handle;
}Handle;

extern Handle Sponge[5];//�L�����`�b�v
extern Handle Block[4];//�}�b�v�`�b�v

extern Handle Goal;
extern Handle title;
extern Handle SELECT;
//********************************
//�v���g�^�C�v�錾
//********************************
void Title_init(void);//�^�C�g���̏�����
void Title_Update(int *,int*,bool*);//�^�C�g����ʍX�V
void Title_Draw(int *);//�^�C�g����ʕ`��