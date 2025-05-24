#pragma once
#include "Float2.h"
namespace __Obj {
	class _Object {

	public:
		Float2 pos;
		float r;
		float rot;
		
		void ObjectInit();
		void ObjectUpdate();
		void ObjectRender();
		void ObjectExit();

	private:




	};
}
