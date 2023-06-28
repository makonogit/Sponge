#include"Title.h"
#include"Stage_Select.h"
#include"Stage_1.h"
#include"Stage_2.h"
#include"Stage_3.h"
#include"main.h"
#include"DxLib.h"

//---------画像ハンドル------
Handle Select_arrow;
Handle Select_txt;
Handle StageNum[3];
Handle select_wait;
Handle Select_con;

void Select_init(double *ExtRate) {
	
	//***********画像読み込み*************
	SelectMove.handle = LoadGraph("select.gif");//背景
	Select_txt.handle = LoadGraph("STAGESELECT.png");
	StageNum[0].handle = LoadGraph("STAGE1.png");//ステージ番号
	StageNum[1].handle = LoadGraph("STAGE2.png");
	StageNum[2].handle = LoadGraph("STAGE3.png");
	Select_arrow.handle = LoadGraph("Selectarrow.png");
	select_wait.handle = LoadGraph("Selectwait.png");
	Select_con.handle = LoadGraph("select_con.png");

	Enemy[0].handle = LoadGraph("Enemy1.png");
	Enemy[1].handle = LoadGraph("Enemy2.png");

	*ExtRate = 0.0f;//拡大率

	PlayMovieToGraph(SelectMove.handle);//Gif動画を再生状態にする

}

void Select_Update(double *ExtRate,int *Scene_Change,int *Stage_Num,int *sponge_num,int*water_num) {

	//ステージセレクト
	if (Key[KEY_INPUT_DOWN] == 1) {//下キーを入力したら
		PlaySoundFile("決定音.mp3", DX_PLAYTYPE_BACK);
		*Stage_Num += 1;
		*ExtRate = 0.0f;//拡大率の初期化
		if (*Stage_Num > 3) {
			*Stage_Num = 1;
		}
	}if (Key[KEY_INPUT_UP] == 1) {//上キーを入力したら
		PlaySoundFile("決定音.mp3", DX_PLAYTYPE_BACK);
		*Stage_Num -= 1;
		*ExtRate = 0.0f;//拡大率の初期化
		if (*Stage_Num < 1) {
			*Stage_Num = 3;
		}
	}

	//ステージセレクトUIを徐々に拡大する
	if (*Stage_Num == 1) {
		if (*ExtRate <= 1.5f) {
			*ExtRate += 0.1f;
		}
		if (Key[KEY_INPUT_RETURN] == 1 && *ExtRate >= 1.5f) {
			PlaySoundFile("キャンセル.mp3", DX_PLAYTYPE_BACK);
			PlaySoundMem(title.handle, DX_PLAYTYPE_BACK);
			StopSoundMem(SELECT.handle);
			Stage1_init(sponge_num,water_num);
			*Scene_Change = STAGE_1;//シーン遷移
			*ExtRate = 0.0f;
		}
	}
	if (*Stage_Num == 2) {
		if (*ExtRate <= 1.5f) {
			*ExtRate += 0.1f;
		}
		if (Key[KEY_INPUT_RETURN] == 1 && *ExtRate >= 1.5f) {
			PlaySoundFile("キャンセル.mp3", DX_PLAYTYPE_BACK);
			PlaySoundMem(title.handle, DX_PLAYTYPE_BACK);
			StopSoundMem(SELECT.handle);
			Stage1_init(sponge_num, water_num);
			Stage2_init(sponge_num,water_num);
			*Scene_Change = STAGE_2;//シーン遷移
			*ExtRate = 0.0f;
		}
		
	}if (*Stage_Num == 3) {
		if (*ExtRate <= 1.5f) {
			*ExtRate += 0.1f;
		}
		if (Key[KEY_INPUT_RETURN] == 1 && *ExtRate >= 1.5f) {
			PlaySoundFile("キャンセル.mp3", DX_PLAYTYPE_BACK);
			PlaySoundMem(title.handle, DX_PLAYTYPE_BACK);
			StopSoundMem(SELECT.handle);
			Stage1_init(sponge_num, water_num);
			Stage3_init(sponge_num, water_num);
			*Scene_Change = STAGE_3;//シーン遷移
			*ExtRate = 0.0f;
		}
	}

}

void Select_Draw(double *ExtRate,int *Stage_Num) {

	DrawGraph(0, 0, SelectMove.handle, false);//背景動画
	DrawGraph(380, 100, select_wait.handle, true);
	DrawGraph(200, 150, Select_arrow.handle, true);
	DrawGraph(200, 30, Select_txt.handle, true);
	DrawGraph(230, 160, Select_con.handle, true);

	//**************ステージ*******************
	if (*Stage_Num == 1) {
		DrawRotaGraph(Window_Width / 5, Window_Height / 4, *ExtRate, 0, StageNum[0].handle, true);
	}
	if (*Stage_Num == 2) {
		DrawRotaGraph(Window_Width / 5, Window_Height / 2, *ExtRate, 0, StageNum[1].handle, true);
	}if (*Stage_Num == 3) {
		DrawRotaGraph(Window_Width / 5, Window_Height / 1.3, *ExtRate, 0, StageNum[2].handle, true);
	}
}