#include "Main.h"
#include "Base.h"

void Base::Init()
{
}

void Base::Update()
{
}

void Base::Render()
{
}

void Base::Exit()
{
}

//---------------------------------------------------------------------------------
//	コンストラクタ
//---------------------------------------------------------------------------------
Base::Base()
{
	image_ = 0;

	pos_ = { 0,0 };

	rot_ = 0;

	radius_ = 0;
}
