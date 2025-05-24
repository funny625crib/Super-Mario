#include "Main.h"
#include "Game.h"
#include "Map.h"
#include <sstream>
# include <vector>
#include <math.h>
#include <fstream>
#include <algorithm>
using namespace std;

//ファイル操作-----------------------------------------------------------------------------
	// ファイルへの書き込み
	//	戻り値
	//		false: エラーが発生
	//		true : 正常に完了
	//	引数
	//		std::string fname	書き込みを行うファイル名
	//				int data	書き込むデータ
bool OutputFile(std::string fname, int data, std::ios_base::openmode flg = std::ios::out)
{
	std::ofstream file(fname, flg);
	if (file.is_open() == false)
	{
		return false;
	}
	
	//file << data << std::endl;
	
	file.close();
	return true;
}
// ファイルへの読み込み
//	戻り値
//		false: エラーが発生
//		true : 正常に完了
//	引数
//		std::string  fname	読み込みを行うファイル名
//				int& data	読み込まれたデータを入れるところ
int s_cou_w = 0;
int s_cou_h = 0;
int map_include[MAP_H][MAP_W];
 bool InputFile(std::string fname)
{
	std::ifstream file(fname);
	if (file.is_open() == false)
	{
		return false;
	}
	//s_cou = 0;
	while (!file.eof())
	{
		//file >> map_include[s_cou_h++][s_cou_w++];
	}

	

	file.close();
	return true;
}

std::string mes;




int tmp = 0;
void Map::Load()
{
	// ファイルから読み込み＆書き込み
	std::ifstream ifile("data/Map_Data");

	// 開くのに成功
	
	
	
	for (int h = 0; h < MAP_H; ++h) {
		for (int w = 0; w < MAP_W; ++w) {

			//map_data[h][w] = 0;


		}
	}
	if (ifile.is_open() == true)
	{

		while (true)
		{
			// ファイルからデータを読み込む
			
		
			
			if (ifile.eof() == true)
			{
				

			break;
			}
			// ファイルのデータを配列に入れる
			for (int w = 0; w < MAP_W; ++w) {
				string line;
				string file;// 


				string str, s;
				getline(ifile, line);
				str = line;
				stringstream ss{ str };
				getline(ss, s, ',');;
				tmp = std::stoi(s);
				map_data[s_cou_h++][w] = tmp;
				if (data_count_w >= MAP_W)
				{
					data_count_h++;
					data_count_w = 0;

					if (data_count_h >= MAP_H) {

						break;
					}
				}
			}

			//tmp += 1;
			
		}
		// ファイルを閉じる


	
	// 作ったデータをファイルへ書き出し
		std::ofstream ofile("data/Map_Data.txt");
		//
		if (ofile.is_open() == true)
		{
			for (int h = 0; h < MAP_H; ++h) {
				for (int w = 0; w < MAP_W; ++w) {

					ofile << map_data[h][w] << ",";

				}
				ofile << std::endl;
				// ファイルを閉じる

			}
			ofile.close();
		}
	}


}
\



//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void Map::Init()
{

	Map_image_ = LoadGraph("data/map/map1.png");
	Load();
}


//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Map::Update()
{

}

//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Map::Render()
{
	//
	//for (int h = 0; h < MAP_H; ++h) {
	//	for (int w = 0; w < MAP_W; ++w) {

	//		if (map_data[h][w] == 0) {
	//			//DrawRotaGraph(w * 50, h * (SCREEN_H / MAP_H),0.5f,0, blo_i, true);
	//			//DrawFormatString(w * 50, h * 50, GetColor(255, 255, 255), "%d", map_data[h][w]);

	//		}
	//	}
	//}
	DrawGraph(0, 0, Map_image_, TRUE);
}


//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------

void Map::Exit()
{
	

}





