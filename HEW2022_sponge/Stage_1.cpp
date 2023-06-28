#include"Stage_1.h"
#include"main.h"
#include"Title.h"
#include"GameSystem.h"
#include"DxLib.h"

Handle Sponge[5];
Handle Block[4];
pos camera;
pos Chara;
pos Old_Chara;
animation Walk;
hit Wall_hit;
EXT Sponge_Ext[10];//スポンジ拡大
EXT Goal_Ext;//ゴール拡大

pos sponge_pos[10];
Handle Goal;

unsigned int white = GetColor(255, 255, 0);

int STAGE1[Stage_Height][Stage_Width] = {
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1},
	{1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,5,5,5,5,5,5,2,2,2,2,5,5,5,5,5,5,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1},

};

void Stage1_init(int *sponge_num,int*water_num) {

	//*******キャラチップ*********
	Sponge[0].handle = LoadGraph("sponge1.png");
	Sponge[1].handle = LoadGraph("sponge2.png");
	Sponge[2].handle = LoadGraph("jump1.png");
	Sponge[3].handle = LoadGraph("jump2.png");
	Sponge[4].handle = LoadGraph("jump3.png");
	
	//*******ブロックチップ***********
	Block[0].handle = LoadGraph("tile.png");//タイル
	Block[1].handle = LoadGraph("water.png");//水(水中)
	Block[2].handle = LoadGraph("water2.png");//水(水上)
	Block[3].handle = LoadGraph("sponge.png");//スポンジ

	Goal.handle = LoadGraph("GOAL.png");//ゴール

	//カメラ座標
	camera.x = 0;
	camera.y = 0;

	//キャラ座標
	Chara.x = 64;
	Chara.y = 384;

	Old_Chara.x = 64;
	Old_Chara.y = 384;

	//ゴール拡大
	Goal_Ext.x = 0.0f;
	Goal_Ext.y = 0.0f;
	
	*sponge_num = 3;
	*water_num = 15;

	//スポンジ拡大率
	for (int i = 0; i < *sponge_num; i++) {
		Sponge_Ext[i].x = 0.0f;
		Sponge_Ext[i].y = 0.0f;
	}
}

void Stage1_Update(float *yadd,bool *Jump_flg,int*sponge,int *sponge_num,int*Scene_Change,bool *hit_flg, int* water, int*water_num) {

	/*Old_Chara.x = Chara.x;//前回の座標を記録
	Old_Chara.y = Chara.y;
	*/

	//*********ジャンプ処理************
	if (Key[KEY_INPUT_SPACE] == 1) {
		PlaySoundFile("ジャンプ.mp3", DX_PLAYTYPE_BACK);
		*yadd = -6.0f;
		*Jump_flg = true;
	}

	Chara.y += (int)*yadd;
	*yadd += 0.2f;

	if (*yadd > 30) {
		*yadd = 30;
	}


	if (Chara.y > 384) {
		Chara.y = 384;
	}

	//*********************************


	/*if (!CheckHitKey(KEY_INPUT_D)) {

		Wall_hit.R_hit = false;
	}

	if (!CheckHitKey(KEY_INPUT_A)) {
		Wall_hit.L_hit = false;
	}

	if (Wall_hit.L_hit) {
		Chara.x++;
	}
	if (Wall_hit.R_hit) {
		Chara.x--;
	}*/

	//**********キャラ移動*************
	if (CheckHitKey(KEY_INPUT_D)) {
		Chara.x++;
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			Chara.x++;
		}
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		Chara.x--;
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			Chara.x--;
		}
	}
	//*********************************


	//カメラ移動
	if (CheckHitKey(KEY_INPUT_D)) {
		camera.x++;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		camera.x--;
	}

	//カメラ移動制限
	if (camera.x < 0) {
		if (CheckHitKey(KEY_INPUT_A)) {
			camera.x++;
		}
	}
	if (camera.x > 960) {
		if (CheckHitKey(KEY_INPUT_D)) {
			camera.x--;
		}
	}

	HitCheck_Init(STAGE1,sponge,sponge_num, water, water_num);//当たり判定更新
	HitCheck(Jump_flg,yadd,Scene_Change,hit_flg,sponge_num,water_num);
}

void Stage1_Draw(int *sponge,int *sponge_num) {

	for (int i = 0; i < Stage_Height; i++) {
		for (int j = 0; j < Stage_Width; j++){

			if (STAGE1[i][j] == 1 || STAGE1[i][j] == 5) {//タイル
				DrawGraph(j*TIP_SIZE - camera.x, i*TIP_SIZE - camera.y, Block[0].handle, true);
			}
			if (STAGE1[i][j] == 2) {//水
				DrawGraph(j*TIP_SIZE - camera.x, i*TIP_SIZE - camera.y, Block[2].handle, true);
			}
			if (STAGE1[i][j] == 3) {//スポンジ
				//DrawGraph(j*TIP_SIZE - camera.x, i*TIP_SIZE - camera.y, Block[3].handle, true);
				if (*sponge < *sponge_num) {
					DrawExtendGraph(j*TIP_SIZE - camera.x, i*TIP_SIZE - camera.y, sponge_pos[*sponge].x, sponge_pos[*sponge].y, Block[3].handle, true);
					*sponge += 1;
				}
			}
			if (STAGE1[i][j] == 4) {//ゴール
				DrawExtendGraph(j*TIP_SIZE - camera.x, i*TIP_SIZE - camera.y, (j*TIP_SIZE + TIP_SIZE - camera.x) + (int)Goal_Ext.x, (i*TIP_SIZE + TIP_SIZE - camera.y) + (int)Goal_Ext.y, Goal.handle, true);
			}
		}
	}

	*sponge = 0;

	DrawGraph(Chara.x - camera.x, Chara.y - camera.y, Sponge[Walk.anim_result].handle, true);
	//DrawFormatString(0, 0, white, "camerax:%d,y:%d", camera.x, camera.y);
	//DrawFormatString(0, 64, white, "charax:%d,y:%d", Chara.x, Chara.y);
	//DrawFormatString(192, 200, white, "○");

}