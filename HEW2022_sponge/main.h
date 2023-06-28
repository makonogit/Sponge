#pragma once
//********************************
//マクロ定義
//********************************
#define TIP_SIZE 32//チップサイズ
#define Stage_Height 15 //ステージ縦幅
#define Stage_Width 50 //ステージ横幅
#define Stage_RightEnd 960 //ステージ右端
#define Stage_LightEnd 0 //ステージ左端

//********************************
//構造体定義
//********************************

enum {//シーン遷移用
	TITLE,
	STAGE_SELTCT,
	STAGE_1,
	STAGE_2,
	STAGE_3,
	GAME_CLEAR,
	GAME_OVER
};

typedef struct {//座標

	int x;
	int y;

}pos;

typedef struct {//座標

	float x;
	float y;

}EXT;
extern int Key[256];//キー
extern pos camera;//カメラ
extern pos Chara;//キャラの座標
extern pos Old_Chara;//キャラの前回の座標

extern pos sponge_pos[10];

extern EXT Sponge_Ext[10];//スポンジ拡大
extern EXT Goal_Ext;//ゴール拡大

//********************************
//プロトタイプ宣言
//********************************
