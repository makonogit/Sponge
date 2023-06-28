#pragma once
#include"Title.h"
//********************************
//マクロ定義
//********************************

//********************************
//構造体定義
//********************************
extern Handle SelectMove;
extern Handle Enemy[2];
//********************************
//プロトタイプ宣言
//********************************
void Select_init(double *);//初期化
void Select_Update(double *,int *,int *,int *,int*);//更新
void Select_Draw(double *,int *);//描画