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
	SetFontSize(30);//フォントサイズの変更
	PlayMovieToGraph(Move.handle);//動画を再生状態にする
	SELECT.handle = LoadSoundMem("セレクト.mp3");
}

void Title_Update(int *Scene_Change,int *alpha,bool *alpha_flg) {

	//------透過設定-----
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
		PlaySoundFile("決定音.mp3", DX_PLAYTYPE_BACK);
		SeekMovieToGraph(Move.handle, 0);
		PlayMovieToGraph(Move.handle);
		PlaySoundMem(SELECT.handle,DX_PLAYTYPE_BACK);
		*Scene_Change = STAGE_SELTCT;//シーン切り替え
	}
}

void Title_Draw(int *alpha) {

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	DrawGraph(0, 0, Move.handle,false);
	if (GetMovieStateToGraph(Move.handle) == 0) {//動画が再生終了したら
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, *alpha);
		DrawGraph(200, 310, Start_txt.handle, true);//テキストの表示
	}
}