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
int map_include[MAP_MAX_H][MAP_MAX_W];
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

	//�X�R�A�f�[�^���\�[�g����
//for (int i = 0; i < 200 - 1; i++)
//{
//	for (int j = 0; j < 200 - 1; j++)
//	{
//		if (score_data[j + 1] > score_data[j])
//		{
//			keep_sco = score_data[j];
//			score_data[j] = score_data[j + 1];
//			score_data[j + 1] = keep_sco;
//		}
//	}
//}

	file.close();
	return true;
}

std::string mes;




int tmp = 0;
void __Map::_Map::MapLoad()
{
	// �t�@�C������ǂݍ��݁���������
	std::ifstream ifile("data/Map_Data");

	// �J���̂ɐ���
	
	
	// ���ׂẴf�[�^�𖢎g�p�̏�Ԃɂ���
	//for (int i = 0; i < 200; ++i)
	//{
	//	//datas[i] = -1;
	//}
	for (int h = 0; h < MAP_MAX_H; ++h) {
		for (int w = 0; w < MAP_MAX_W; ++w) {

			//map_data[h][w] = 0;


		}
	}
	if (ifile.is_open() == true)
	{

		while (true)
		{
			// �t�@�C������f�[�^��ǂݍ���
			
		
			//ifile >> __Map::_Map::map_data[s_cou_h++][s_cou_w++];;
			if (ifile.eof() == true)
			{
				//ifstream sstr;
				
				// �t�@�C���I�[�܂ōs�����疳�����[�v�𔲂���
				 //__Map::_Map::data_count_h++;
				//file >> score_data[s_cou++];

			break;
			}
			// �t�@�C���̃f�[�^��z��ɓ����
			for (int w = 0; w < MAP_MAX_W; ++w) {
				string line;
				string file;// 


				string str, s;
				getline(ifile, line);
				str = line;
				stringstream ss{ str };
				getline(ss, s, ',');;
				tmp = std::stoi(s);
				__Map::_Map::map_data[s_cou_h++][w] = tmp;
				if (__Map::_Map::data_count_w >= MAP_MAX_W)
				{
					__Map::_Map::data_count_h++;
					__Map::_Map::data_count_w = 0;

					if (__Map::_Map::data_count_h >= MAP_MAX_H) {

						break;
					}
				}
			}

			//tmp += 1;
			
		}
		// �t�@�C�������


	//a
	// ���̃f�[�^������
	//map_data[data_count_h][data_count_w] = score1;
	//++data_count;

	// ������f�[�^���t�@�C���֏����o��
		std::ofstream ofile("data/Map_Data.txt");
		//
		if (ofile.is_open() == true)
		{
			for (int h = 0; h < MAP_MAX_H; ++h) {
				for (int w = 0; w < MAP_MAX_W; ++w) {

					ofile << map_data[h][w] << ",";

				}
				ofile << std::endl;
				// �t�@�C�������

			}
			ofile.close();
		}
	}
//	}}}

}
int blo_i;


void __Map::_Map::MapInit()
{
	blo_i = LoadGraph("data/Block.png");
	MapLoad();
}

void __Map::_Map::MapUpdate()
{
}

void __Map::_Map::MapRender()
{
	//bool ret = InputFile("data/score.txt");
	for (int h = 0; h < MAP_MAX_H; ++h) {
		for (int w = 0; w < MAP_MAX_W; ++w) {

			if (map_data[h][w] == 0) {
				//DrawRotaGraph(w * 50, h * (SCREEN_H / MAP_MAX_H),0.5f,0, blo_i, true);
				//DrawFormatString(w * 50, h * 50, GetColor(255, 255, 255), "%d", map_data[h][w]);

			}
		}
	}
	//DrawFormatString(0, 0, GetColor(255,255,255), "%d", tmp);
}

void __Map::_Map::MapExit()
{
	DeleteGraph(blo_i);

}





