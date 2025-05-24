#pragma once
#include "Float2.h"
#include "Object.h"
namespace __Coins {
	class _Coins :public __Obj::_Object {

	public:
		int image;



		void CoinsInit();
		void CoinsUpdate();
		void CoinsRender();
		void CoinsExit();

	private:




	};
}