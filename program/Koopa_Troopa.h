#pragma once
#include "Float2.h"
#include "Enemys.h"
namespace __Koopa {
	class _Koopa :public __Enenys::_Enemys {

	public:
		int image;



		void KoopaInit();
		void KoopaUpdate();
		void KoopaRender();
		void KoopaExit();

	private:




	};
}
