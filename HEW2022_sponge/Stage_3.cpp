#include"Stage_3.h"
#include"DxLib.h"
#include"Title.h"
#include"main.h"
#include"GameSystem.h"


int STAGE3[Stage_Height][Stage_Width] = {
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
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

};



void Stage3_init(int *sponge_num,int*water_num) {
	*sponge_num = 3;
	*water_num = 0;
}

void Stage3_Update(float *yadd, bool *Jump_flg, int*sponge, int *sponge_num, int*Scene_Change, bool *hit_flg, int* water, int*water_num) {

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
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		Chara.x--;
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

	HitCheck_Init(STAGE3, sponge, sponge_num,water,water_num);//当たり判定更新
	HitCheck(Jump_flg, yadd, Scene_Change, hit_flg,sponge_num,water_num);
}

void Stage3_Draw(int *sponge, int *sponge_num) {

	for (int i = 0; i < Stage_Height; i++) {
		for (int j = 0; j < Stage_Width; j++) {

			if (STAGE3[i][j] == 1 || STAGE3[i][j] == 5) {//タイル
				DrawGraph(j*TIP_SIZE - camera.x, i*TIP_SIZE - camera.y, Block[0].handle, true);
			}
			if (STAGE3[i][j] == 2) {//水
				DrawGraph(j*TIP_SIZE - camera.x, i*TIP_SIZE - camera.y, Block[2].handle, true);
			}
			if (STAGE3[i][j] == 3) {//スポンジ
				//DrawGraph(j*TIP_SIZE - camera.x, i*TIP_SIZE - camera.y, Block[3].handle, true);
				if (*sponge < *sponge_num) {
					DrawExtendGraph(j*TIP_SIZE - camera.x, i*TIP_SIZE - camera.y, sponge_pos[*sponge].x, sponge_pos[*sponge].y, Block[3].handle, true);
					*sponge += 1;
				}
			}
			if (STAGE3[i][j] == 4) {//ゴール
				DrawExtendGraph(j*TIP_SIZE - camera.x, i*TIP_SIZE - camera.y, (j*TIP_SIZE + TIP_SIZE - camera.x) + (int)Goal_Ext.x, (i*TIP_SIZE + TIP_SIZE - camera.y) + (int)Goal_Ext.y, Goal.handle, true);
			}
		}
	}

	*sponge = 0;

	DrawGraph(Chara.x - camera.x, Chara.y - camera.y, Sponge[Walk.anim_result].handle, true);
	
}