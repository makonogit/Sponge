#include"GameClear.h"
#include"Stage_select.h"
#include"DxLib.h"

extern Handle SelectMove;
extern Handle ClearTxt[2];
extern Handle Clear_Sponge;
Handle Enemy[2];
void Clear_init(void) {
	//***************âÊëúì«Ç›çûÇ›**************
	ClearTxt[0].handle = LoadGraph("Clear.png");
	ClearTxt[1].handle = LoadGraph("Change.png");
	Clear_Sponge.handle = LoadGraph("Clear_sponge.png");
}

void Clear_Update(int *Scene_Change) {

	if (Key[KEY_INPUT_RETURN] == 1 ) {
		*Scene_Change = TITLE;
	}
}

void Clear_Draw(void) {

	DrawGraph(0, 0, SelectMove.handle, false);//îwåiìÆâÊ
	DrawGraph(0, 0, ClearTxt[0].handle, true);
	DrawGraph(0, 120, ClearTxt[1].handle, true);
	DrawGraph(300, 100, Clear_Sponge.handle, true);
	DrawRotaGraph(210, 400,2,0, Enemy[0].handle, true);
	DrawRotaGraph(150, 400, 2, 0, Enemy[0].handle, true);
	DrawRotaGraph(150, 340, 2, 0, Enemy[0].handle, true);

}