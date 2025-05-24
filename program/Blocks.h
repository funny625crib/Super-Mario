#pragma once
#include "Float2.h"
#include "Object.h"
namespace __Blocks {
	class _Blocks :public __Obj::_Object {

	public:
		int image;



		void BlocksInit();
		void BlocksUpdate();
		void BlocksRender();
		void BlocksExit();

	private:




	};
}
