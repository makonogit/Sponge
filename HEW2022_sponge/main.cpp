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

	//SetGraphMode(MAP_HEIGHT, MAP_WIDTH, 32);//ウィンドウのサイズを設定
	SetBackgroundColor(255, 255, 255);

	SetFontSize(16);
	// ********** 初期化処理 **********
	ChangeWindowMode(TRUE);				// ウィンドウモードに設定

	if (DxLib_Init() == -100)				// ＤＸライブラリ初期化処理
	{
		return -100;						// エラーが起きたら直ちに終了
	}

	//*********変数宣言*************
	int Scene_Change = TITLE;//画面遷移用

	double ExtRate = 1.0f;//画像拡大率
	int Stage_num = 1;//ステージ番号
	int alpha = 0;//透過用a値
	float yadd = 0.0f;//ジャンプ用重力加速度
	bool Walk_flg = false, Jump_flg = false;//アニメーションフラグ
	bool alpha_flg;//点滅フラグ
	bool hitflg = false;//衝突フラグ

	int sponge = 0;//スポンジカウント
	int sponge_num = 0;
	int sponge_cnt = 0;
	int water = 0;
	int water_num = 0;


	title.handle = LoadSoundMem("タイトル.mp3");

	//*****初期化********
	Title_init();
	Select_init(&ExtRate);
	Stage1_init(&sponge_num,&water_num);
	Stage2_init(&sponge_num,&water_num);
	System_Init();
	Clear_init();
	Over_init();

	//--------------------------------------
	//↑をまとめる.hファイル
	//GameControl()あるとすっきりするかも
	//2022/03/07 更新
	//---------------------------------------


	PlaySoundFile("タイトル.mp3", DX_PLAYTYPE_BACK);

while (!ScreenFlip() && !ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE) && !ClearDrawScreen()) {//ゲームループ

	KeyInput();//キー入力

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

//WaitKey();//キーの入力待ち

// ********** 終了処理 **********
DxLib_End();			// ＤＸライブラリ使用の終了処理

return 0;
}