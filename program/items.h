#pragma once
#pragma once
#include "Float2.h"
#include "Object.h"
namespace __Items {
	class _Items :public __Obj::_Object {

	public:
		int image;



		void ItemsInit();
		void ItemsUpdate();
		void ItemsRender();
		void ItemsExit();

	private:




	};
}