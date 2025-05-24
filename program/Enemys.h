#pragma once
#include "Float2.h"
#include "Object.h"
namespace __Enenys {
	class _Enemys :public __Obj::_Object{

	public:
		 int image;



		void EnemysInit();
		void EnemysUpdate();
		void EnemysRender();
		void EnemysExit();

	private:




	};
}
