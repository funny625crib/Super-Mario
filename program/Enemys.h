#pragma once
#include "Float2.h"
#include "Object.h"
namespace __Enenys {
	class _Enemys :public __Obj::_Object {

	public:
		int image;
		float move_ = 0.5f;
		float movey_ = 0.5f;
		Float2 move = { 0.5f,0.5f };
		//Float2 move_ = { 0.0f,0.0f };
		
		bool janp_hit;
		
		void EnemysInit();
		void EnemysUpdate();
		void EnemysRender();
		void EnemysExit();

	private:




	};
}
