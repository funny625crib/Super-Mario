#pragma once
#include "Float2.h"
#include "Enemys.h"
namespace __Goomba {
	class _Goomba :public __Enenys::_Enemys {

	public:
		int image;



		void GoombaInit();
		void GoombaUpdate();
		void GoombaRender();
		void GoombaExit();

	private:




	};
}
