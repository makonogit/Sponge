#pragma once
//********************************
//�}�N����`
//********************************
#define TIP_SIZE 32//�`�b�v�T�C�Y
#define Stage_Height 15 //�X�e�[�W�c��
#define Stage_Width 50 //�X�e�[�W����
#define Stage_RightEnd 960 //�X�e�[�W�E�[
#define Stage_LightEnd 0 //�X�e�[�W���[

//********************************
//�\���̒�`
//********************************

enum {//�V�[���J�ڗp
	TITLE,
	STAGE_SELTCT,
	STAGE_1,
	STAGE_2,
	STAGE_3,
	GAME_CLEAR,
	GAME_OVER
};

typedef struct {//���W

	int x;
	int y;

}pos;

typedef struct {//���W

	float x;
	float y;

}EXT;
extern int Key[256];//�L�[
extern pos camera;//�J����
extern pos Chara;//�L�����̍��W
extern pos Old_Chara;//�L�����̑O��̍��W

extern pos sponge_pos[10];

extern EXT Sponge_Ext[10];//�X�|���W�g��
extern EXT Goal_Ext;//�S�[���g��

//********************************
//�v���g�^�C�v�錾
//********************************
