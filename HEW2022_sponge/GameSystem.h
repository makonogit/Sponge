#pragma once
#include"main.h"

//********************************
//マクロ定義
//********************************

//********************************
//構造体定義
//********************************
typedef struct {//アニメーション用

	int anim_speed;//再生速度
	int anim_num;//アニメーション計算用変数
	int anim_max;//アニメーションコマ数
	int anim_result;//計算結果
	int anim[10];//再生順序

}animation;

typedef struct {

	bool L_hit;
	bool R_hit;
	bool Ground_hit;

}hit;

extern hit Wall_hit;
extern animation Walk;


extern bool spongehitext[3];

//********************************
//プロトタイプ宣言
//********************************
void System_Init(void);//ゲームシステム初期化
void Animation(bool*,bool*);//アニメーション
void HitCheck_Init(int[][Stage_Width],int *,int *,int*,int*);//当たり判定座標の初期化
void HitCheck(bool*,float*,int*,bool*,int*,int*);//当たり判定
void KeyInput(void);//キー入力処理