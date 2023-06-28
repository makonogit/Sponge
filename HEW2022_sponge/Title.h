#pragma once
#include"main.h"
//********************************
//マクロ定義
//********************************
#define Window_Height 480 //画面縦幅
#define Window_Width 640 //画面横幅

//********************************
//構造体定義
//********************************
typedef struct {
	int handle;
}Handle;

extern Handle Sponge[5];//キャラチップ
extern Handle Block[4];//マップチップ

extern Handle Goal;
extern Handle title;
extern Handle SELECT;
//********************************
//プロトタイプ宣言
//********************************
void Title_init(void);//タイトルの初期化
void Title_Update(int *,int*,bool*);//タイトル画面更新
void Title_Draw(int *);//タイトル画面描画