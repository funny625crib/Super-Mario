#pragma once
#include "Float2.h"
#include "Enemys.h"
const int GOOMBA_MAX = 2;
	class Goomba :public __Enenys::_Enemys {

	public://e
		int image[2];
		int goomba_flashing_flame;
		int image_index;
		float move = 0.5f;

		void GoombaInit();
		void GoombaUpdate();
		void GoombaRender();
		void GoombaExit();

	private:




	};
