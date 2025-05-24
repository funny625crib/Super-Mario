#pragma once
#include "Float2.h"
#include "Object.h"
#include "base.h"


class Map :
	public Base {

public:


	int Ground_image_;          //�n�ʂ̉摜
	int Wall_image_;            //�ǂ̉摜
	int Box_image_;             //���̉摜
	int Coin_image_;            //�R�C���̉摜

	int Map_image_;      //�����p�摜

    #define MAP_H 14
    #define MAP_W 191           

	int map_data[MAP_H][MAP_W];
	int data_count_w;
	int data_count_h;



	void Load();
	void Init();     //	����������
	void Update();	//	�X�V����
	void Render();	//	�`�揈��
	void Exit();		//	�I������


private:




};
