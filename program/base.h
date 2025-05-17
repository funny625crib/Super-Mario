#pragma once
#include "Float2.h"

//---------------------------------------------------------------------------------
//	基本クラス
//---------------------------------------------------------------------------------

class Base
{
public:

	virtual void Init();		//	初期化処理
	virtual void Update();		//	更新処理
	virtual void Render();		//	描画処理
	virtual void Exit();		//	終了処理



	int image_;    //画像

	Float2	pos_;		//	座標
	float	rot_;		//	向き

	float	radius_;	//	半径

	Base();

};