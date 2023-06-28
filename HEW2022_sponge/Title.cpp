#include"Title.h"
#include"DxLib.h"
#include"main.h"

Handle Move;
Handle Start_txt;
unsigned int White = GetColor(255, 255, 255);
Handle SELECT;
Handle title;

void Title_init(void) {

	Move.handle = LoadGraph("Title.mov");
	Start_txt.handle = LoadGraph("starttxt.png");
	SetFontSize(30);//�t�H���g�T�C�Y�̕ύX
	PlayMovieToGraph(Move.handle);//������Đ���Ԃɂ���
	SELECT.handle = LoadSoundMem("�Z���N�g.mp3");
}

void Title_Update(int *Scene_Change,int *alpha,bool *alpha_flg) {

	//------���ߐݒ�-----
	if (*alpha_flg) {
		*alpha += 3;
	}
	if (!*alpha_flg) {
		*alpha -= 3;
	}
	if (*alpha == 0) {
		*alpha_flg = true;
	}
	if (*alpha == 255) {
		*alpha_flg = false;
	}

	if ((Key[KEY_INPUT_RETURN] == 1 || Key[KEY_INPUT_SPACE] == 1)&& GetMovieStateToGraph(Move.handle) == 0) {
		PlaySoundFile("���艹.mp3", DX_PLAYTYPE_BACK);
		SeekMovieToGraph(Move.handle, 0);
		PlayMovieToGraph(Move.handle);
		PlaySoundMem(SELECT.handle,DX_PLAYTYPE_BACK);
		*Scene_Change = STAGE_SELTCT;//�V�[���؂�ւ�
	}
}

void Title_Draw(int *alpha) {

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	DrawGraph(0, 0, Move.handle,false);
	if (GetMovieStateToGraph(Move.handle) == 0) {//���悪�Đ��I��������
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, *alpha);
		DrawGraph(200, 310, Start_txt.handle, true);//�e�L�X�g�̕\��
	}
}