#include"GameSystem.h"
#include"DxLib.h"
#include"Title.h"
#include"main.h"
#include"Stage_1.h"

int Key[256];
RECT WALL[Stage_Height][Stage_Width];
RECT CHARA;
RECT GOAL;//ゴール
RECT SPONGE[10];
RECT Enemy;
RECT WATER[30];

unsigned int brack = GetColor(0, 0, 0);

bool spongehitext[3] = { false,false,false };

void System_Init(void) {

	//Walkアニメーションの初期化
	Walk = { 20,0,2,0,{0,1,0,1} };

	//衝突フラグの初期化
	Wall_hit.Ground_hit = true;
	Wall_hit.L_hit = false;
	Wall_hit.R_hit = false;
}

void HitCheck_Init(int STAGE_DATA[][Stage_Width],int *sponge,int *sponge_num,int *water,int *water_num) {

	for (int i = 0; i < Stage_Height; i++) {
		for (int j = 0; j < Stage_Width; j++) {

			//壁の当たり判定

			if (STAGE_DATA[i][j] == 1) {

				WALL[i][j].top = i * TIP_SIZE - camera.y;//y(上)
				WALL[i][j].left = j * TIP_SIZE - camera.x;//x(左)
				WALL[i][j].bottom = i * TIP_SIZE + TIP_SIZE - camera.y;//y+TIP_SIZE(下)
				WALL[i][j].right = j * TIP_SIZE + TIP_SIZE - camera.x;//x+TIP_SIZE(右)

			}
			else {

				WALL[i][j] = { 0,0,0,0 };

			}

			if (STAGE_DATA[i][j] == 3 && *sponge < *sponge_num) {//スポンジの初期化

				SPONGE[*sponge].top = i * TIP_SIZE - camera.y;
				SPONGE[*sponge].left = j * TIP_SIZE - camera.x;
				SPONGE[*sponge].right = j * TIP_SIZE + TIP_SIZE - camera.x;
				SPONGE[*sponge].bottom = i * TIP_SIZE + TIP_SIZE - camera.y;
				
				sponge_pos[*sponge].x = (j*TIP_SIZE + TIP_SIZE - camera.x) + (int)Sponge_Ext[*sponge].x;
				sponge_pos[*sponge].y = (i*TIP_SIZE + TIP_SIZE - camera.y) + (int)Sponge_Ext[*sponge].y;

				*sponge += 1;
			}
			if (STAGE_DATA[i][j] == 4) {//ゴールの初期化

				GOAL.top = i * TIP_SIZE - camera.y;
				GOAL.left = j * TIP_SIZE - camera.x;
				GOAL.right = j * TIP_SIZE + TIP_SIZE - camera.x;
				GOAL.bottom = i * TIP_SIZE + TIP_SIZE - camera.y;
			}
			if (STAGE_DATA[i][j] == 2 && *water < *water_num) {
				WATER[*water].bottom = i * TIP_SIZE + TIP_SIZE - camera.y;
				WATER[*water].left = j * TIP_SIZE - camera.x;
				WATER[*water].right= j * TIP_SIZE + TIP_SIZE - camera.x;
				WATER[*water].top = i * TIP_SIZE - camera.y;
				*water += 1;
			}

			if (CheckHitKey(KEY_INPUT_1)) {
				SPONGE[*sponge].right += (int)Sponge_Ext[*sponge].x;
				SPONGE[*sponge].bottom += (int)Sponge_Ext[*sponge].y;
			}

		}
	}

	//-----------2022/03/07 更新-------------
	if (spongehitext[0]) {
		SPONGE[0].right += (int)Sponge_Ext[*sponge].x;
	}
	if (spongehitext[1]) {
		SPONGE[1].right += (int)Sponge_Ext[*sponge].x;
	}
	if (spongehitext[2]) {
		SPONGE[2].right += (int)Sponge_Ext[*sponge].x;
	}
	//---------------------------------

	*water = 0;
	*sponge = 0;

	//キャラの当たり判定
	CHARA = { Chara.x - camera.x,Chara.y - camera.y,Chara.x + TIP_SIZE-camera.x,Chara.y + (TIP_SIZE * 2)-camera.y};

}

void HitCheck(bool *Jump_flg,float *yadd,int *Scene_Change,bool *hit_flg,int*sponge_num,int*water_num) {

	for (int i = 0; i < Stage_Height; i++) {
		for (int j = 0; j < Stage_Width; j++) {

			if (i < *sponge_num) {//スポンジの当たり判定
				if ((CHARA.left <= SPONGE[i].right) && (SPONGE[i].left <= CHARA.right) &&
					(CHARA.top <= SPONGE[i].bottom) && (SPONGE[i].top <= CHARA.bottom)) {

					DrawString(0, 0, "KEY 1 Push!!", brack);
					Chara.y = SPONGE[i].top -(TIP_SIZE*2);

					if (CheckHitKey(KEY_INPUT_1)) {//スポンジ拡大

						if ((CHARA.left <= SPONGE[0].right) && (SPONGE[0].left <= CHARA.right) &&
							(CHARA.top <= SPONGE[0].bottom) && (SPONGE[0].top <= CHARA.bottom)) {

							Sponge_Ext[0].x += 0.01f;
							spongehitext[0] = true;
							//SPONGE[0].right += (int)Sponge_Ext[0].x;

						}
						if ((CHARA.left <= SPONGE[1].right) && (SPONGE[1].left <= CHARA.right) &&
							(CHARA.top <= SPONGE[1].bottom) && (SPONGE[1].top <= CHARA.bottom)) {

							Sponge_Ext[1].x += 0.01f;
							spongehitext[1] = true;
							//Chara.y = SPONGE[0].top + (TIP_SIZE * 2);

						}
						if ((CHARA.left <= SPONGE[2].right) && (SPONGE[2].left <= CHARA.right) &&
							(CHARA.top <= SPONGE[2].bottom) && (SPONGE[2].top <= CHARA.bottom)) {

							Sponge_Ext[2].x += 0.01f;
							spongehitext[2] = true;
							//Chara.y = SPONGE[0].top + (TIP_SIZE * 2);

						}

					}
					else {
						spongehitext[0] = false;
						spongehitext[1] = false;
						spongehitext[2] = false;
					}

					//Chara.y -= (int)*yadd;

				}
			}

			//水
			if (i < *water_num) {
				if ((CHARA.left <= WATER[i].right) && (WATER[i].left <= CHARA.right) &&
					(CHARA.top <= WATER[i].bottom) && (WATER[i].top <= CHARA.bottom)) {

					//DrawString(200, 60, "whit", brack);

					Chara.y++;

					if (Chara.y > 480) {
						*Scene_Change = GAME_OVER;
					}

				}
			}

			//***********ゴールの当たり判定**************
			if ((CHARA.left <= GOAL.right) && (GOAL.left <= CHARA.right) &&
				(CHARA.top <= GOAL.bottom) && (GOAL.top <= CHARA.bottom)) {

				if (CheckHitKey(KEY_INPUT_1)) {

					if (Goal_Ext.x <= 32 && Goal_Ext.y <= 32) {
						Goal_Ext.x += 0.001f;
						Goal_Ext.y += 0.001f;
					}
				}
				if ((Goal_Ext.x >= 32 && Goal_Ext.y >= 32)) {
					DrawString(0, 0, "Enter Push!", brack);
					if (Key[KEY_INPUT_RETURN] == 1) {
						StopSoundMem(title.handle);
						*Scene_Change = GAME_CLEAR;//クリア
						Goal_Ext = { 0.0f,0.0f };//初期化
					}
				}

				//Chara.y -= (int)*yadd;

			}

			if (WALL[i][j].bottom != 0 && WALL[i][j].left != 0 && WALL[i][j].right != 0 && WALL[i][j].top != 0) {

				if ((CHARA.left <= WALL[i][j].right) && (WALL[i][j].left <= CHARA.right) &&
					(CHARA.top <= WALL[i][j].bottom) && (WALL[i][j].top <= CHARA.bottom)) {

					Chara.y = WALL[i][j].top - (TIP_SIZE * 2);

					//DrawString(200, 30, "hit", brack);
					//*hit_flg = true;

					/*if (CheckHitKey(KEY_INPUT_D)) {

						Wall_hit.R_hit = true;
					}

					if (CheckHitKey(KEY_INPUT_A)) {
						Wall_hit.L_hit = true;
					}*/
					

					//Chara.y -= (int)*yadd;

				}
				else {

					//*hit_flg = false;
					//DrawString(200, 0, "no hit!", brack);

				}



				/*if (CHARA.bottom == WALL[i][j].top) {
					
					Chara.y++;
					//Chara.y = ;
					*Jump_flg = false;
				}*/


				/*if ((CHARA.top <= WALL[i][j].bottom) && (WALL[i][j].top <= CHARA.bottom)) {

					Chara.y = Old_Chara.y;

				}*/

			}
		}
	}

}

void Animation(bool *Walk_flg,bool*Jump_Flg) {

	if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_D)) {
		*Walk_flg = true;
	}
	else {
		*Walk_flg = false;
	}


	/*if (Key[KEY_INPUT_SPACE] == 1) {
		*Jump_Flg = true;
	}
	else {
		*Jump_Flg = false;
	}*/

	if (Walk_flg) {
		if (--Walk.anim_speed == 0) {

			Walk.anim_num++;
			Walk.anim_num %= Walk.anim_max;
			Walk.anim_speed = 20;
			Walk.anim_result = Walk.anim[Walk.anim_num];

		}
	}

}

void KeyInput(void) {

	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			Key[i] ++;     // 加算
		}
		else {              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}
}

