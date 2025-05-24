#pragma once
#include "Float2.h"
#include "Object.h"
//#include <fstream>
const int MAP_MAX_H = 15;
const int MAP_MAX_W = 100;
namespace  __Map {
	class _Map :public __Obj::_Object {

	public:
		

		int image;
		int map_data[MAP_MAX_H][MAP_MAX_W];
		int data_count_w;
		int data_count_h;



		void MapLoad();
		void MapInit();
		void MapUpdate();
		void MapRender();
		void MapExit();
		//bool OutputFile(std::string fname, int data, std::ios_base::openmode flg = std::ios::out);
		//bool InputFile(std::string fname);

		//void Map_Load();
	private:




	};
}
