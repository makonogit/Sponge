#include"DxLib.h"
#include"Title.h"
#include"Stage_Select.h"
#include"GameSystem.h"
#include"Stage_1.h"
#include"Stage_2.h"
#include"Stage_3.h"
#include"GameClear.h"
#include"Game_Over.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//SetGraphMode(MAP_HEIGHT, MAP_WIDTH, 32);//�E�B���h�E�̃T�C�Y��ݒ�
	SetBackgroundColor(255, 255, 255);

	SetFontSize(16);
	// ********** ���������� **********
	ChangeWindowMode(TRUE);				// �E�B���h�E���[�h�ɐݒ�

	if (DxLib_Init() == -100)				// �c�w���C�u��������������
	{
		return -100;						// �G���[���N�����璼���ɏI��
	}

	//*********�ϐ��錾*************
	int Scene_Change = TITLE;//��ʑJ�ڗp

	double ExtRate = 1.0f;//�摜�g�嗦
	int Stage_num = 1;//�X�e�[�W�ԍ�
	int alpha = 0;//���ߗpa�l
	float yadd = 0.0f;//�W�����v�p�d�͉����x
	bool Walk_flg = false, Jump_flg = false;//�A�j���[�V�����t���O
	bool alpha_flg;//�_�Ńt���O
	bool hitflg = false;//�Փ˃t���O

	int sponge = 0;//�X�|���W�J�E���g
	int sponge_num = 0;
	int sponge_cnt = 0;
	int water = 0;
	int water_num = 0;


	title.handle = LoadSoundMem("�^�C�g��.mp3");

	//*****������********
	Title_init();
	Select_init(&ExtRate);
	Stage1_init(&sponge_num,&water_num);
	Stage2_init(&sponge_num,&water_num);
	System_Init();
	Clear_init();
	Over_init();

	//--------------------------------------
	//�����܂Ƃ߂�.h�t�@�C��
	//GameControl()����Ƃ������肷�邩��
	//2022/03/07 �X�V
	//---------------------------------------


	PlaySoundFile("�^�C�g��.mp3", DX_PLAYTYPE_BACK);

while (!ScreenFlip() && !ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE) && !ClearDrawScreen()) {//�Q�[�����[�v

	KeyInput();//�L�[����

	if (Key[KEY_INPUT_BACK] == 1) {
		if (Scene_Change > 0) {
			Scene_Change -= 1;
		}
	}

	Animation(&Walk_flg, &Jump_flg);

	switch (Scene_Change) {
		case TITLE:
			Title_Update(&Scene_Change,&alpha,&alpha_flg);
			Title_Draw(&alpha);
			break;
		case STAGE_SELTCT:
			Select_Update(&ExtRate, &Scene_Change,&Stage_num,&sponge_num,&water_num);
			Select_Draw(&ExtRate,&Stage_num);
			break;
		case STAGE_1:
			Stage1_Update(&yadd,&Jump_flg,&sponge,&sponge_num,&Scene_Change,&hitflg,&water,&water_num);
			Stage1_Draw(&sponge_cnt,&sponge_num);
			break;
		case STAGE_2:
			Stage2_Update(&yadd, &Jump_flg, &sponge, &sponge_num, &Scene_Change, &hitflg, &water, &water_num);
			Stage2_Draw(&sponge_cnt,&sponge_num);
			break;
		case STAGE_3:
			Stage3_Update(&yadd, &Jump_flg, &sponge, &sponge_num, &Scene_Change, &hitflg, &water, &water_num);
			Stage3_Draw(&sponge_cnt, &sponge_num);
			break;
		case GAME_CLEAR:
			Clear_Update(&Scene_Change);
			Clear_Draw();
			break;
		case GAME_OVER:
			Over_Update(&Scene_Change);
			Over_Draw();
			break;
	}
	
}

//WaitKey();//�L�[�̓��͑҂�

// ********** �I������ **********
DxLib_End();			// �c�w���C�u�����g�p�̏I������

return 0;
}