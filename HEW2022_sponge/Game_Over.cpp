#include"Game_Over.h"
#include"DxLib.h"
#include"main.h"
#include"Title.h"

Handle ClearTxt[2];
Handle Clear_Sponge;
Handle SelectMove;
Handle Over;

void Over_init(void) {
	Over.handle = LoadGraph("Over.png");
}

void Over_Update(int *Scene_Change) {

	if (Key[KEY_INPUT_RETURN] == 1) {
		*Scene_Change = TITLE;
		StopSoundMem(title.handle);
	}
}

void Over_Draw(void) {

	DrawGraph(0, 0, SelectMove.handle, false);//”wŒi“®‰æ
	//DrawGraph(0, 0, ClearTxt[0].handle, true);
	DrawGraph(300, 200, ClearTxt[1].handle, true);
	DrawGraph(0, 0, Over.handle, true);


}