#include "Main.h"
#include "Game.h"
#include "Map.h"
#include <sstream>
# include <vector>
#include <math.h>
#include <fstream>
#include <algorithm>
using namespace std;

//�t�@�C������-----------------------------------------------------------------------------
	// �t�@�C���ւ̏�������
	//	�߂�l
	//		false: �G���[������
	//		true : ����Ɋ���
	//	����
	//		std::string fname	�������݂��s���t�@�C����
	//				int data	�������ރf�[�^
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
// �t�@�C���ւ̓ǂݍ���
//	�߂�l
//		false: �G���[������
//		true : ����Ɋ���
//	����
//		std::string  fname	�ǂݍ��݂��s���t�@�C����
//				int& data	�ǂݍ��܂ꂽ�f�[�^������Ƃ���
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
	// �t�@�C������ǂݍ��݁���������
	std::ifstream ifile("data/Map_Data");

	// �J���̂ɐ���
	
	
	
	for (int h = 0; h < MAP_H; ++h) {
		for (int w = 0; w < MAP_W; ++w) {

			//map_data[h][w] = 0;


		}
	}
	if (ifile.is_open() == true)
	{

		while (true)
		{
			// �t�@�C������f�[�^��ǂݍ���
			
		
			
			if (ifile.eof() == true)
			{
				

			break;
			}
			// �t�@�C���̃f�[�^��z��ɓ����
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
		// �t�@�C�������


	
	// ������f�[�^���t�@�C���֏����o��
		std::ofstream ofile("data/Map_Data.txt");
		//
		if (ofile.is_open() == true)
		{
			for (int h = 0; h < MAP_H; ++h) {
				for (int w = 0; w < MAP_W; ++w) {

					ofile << map_data[h][w] << ",";

				}
				ofile << std::endl;
				// �t�@�C�������

			}
			ofile.close();
		}
	}


}
\



//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void Map::Init()
{

	Map_image_ = LoadGraph("data/map/map1.png");
	Load();
}


//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void Map::Update()
{

}

//---------------------------------------------------------------------------------
//	�`�揈��
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
//	�I������
//---------------------------------------------------------------------------------

void Map::Exit()
{
	

}





