#pragma once
#include"main.h"

//********************************
//�}�N����`
//********************************

//********************************
//�\���̒�`
//********************************
typedef struct {//�A�j���[�V�����p

	int anim_speed;//�Đ����x
	int anim_num;//�A�j���[�V�����v�Z�p�ϐ�
	int anim_max;//�A�j���[�V�����R�}��
	int anim_result;//�v�Z����
	int anim[10];//�Đ�����

}animation;

typedef struct {

	bool L_hit;
	bool R_hit;
	bool Ground_hit;

}hit;

extern hit Wall_hit;
extern animation Walk;


extern bool spongehitext[3];

//********************************
//�v���g�^�C�v�錾
//********************************
void System_Init(void);//�Q�[���V�X�e��������
void Animation(bool*,bool*);//�A�j���[�V����
void HitCheck_Init(int[][Stage_Width],int *,int *,int*,int*);//�����蔻����W�̏�����
void HitCheck(bool*,float*,int*,bool*,int*,int*);//�����蔻��
void KeyInput(void);//�L�[���͏���