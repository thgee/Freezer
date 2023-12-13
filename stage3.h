#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage3_initPos() {

	// NPC, ������ ��ġ �ʱ�ȭ
	for (int i = 0; i < MAX_NUM_NPC; i++) {
		gildongs[i].posX = -100;
		gildongs[i].posY = -100;
		gildongs[i].arrX = -1;
		gildongs[i].arrY = -1;

		rocks[i].posX = -100;
		rocks[i].posY = -100;
		rocks[i].arrX = -1;
		rocks[i].arrY = -1;

		crabs[i].posX = -100;
		crabs[i].posY = -100;
		crabs[i].arrX = -1;
		crabs[i].arrY = -1;
	}
	key.posX = -100;
	key.posY = -100;
	key.arrX = -1;
	key.arrY = -1;

	lock.posX = -100;
	lock.posY = -100;
	lock.arrX = -1;
	lock.arrY = -1;

	shoe.posX = -100;
	shoe.posY = -100;
	shoe.arrX = -1;
	shoe.arrY = -1;

	poison.posX = -100;
	poison.posY = -100;
	poison.arrX = -1;
	poison.arrY = -1;

	shield.posX = -100;
	shield.posY = -100;
	shield.arrX = -1;
	shield.arrY = -1;
	
	bulkup.posX = -100;
	bulkup.posY = -100;
	bulkup.arrX = -1;
	bulkup.arrY = -1;

	// --------------------- ��ǥ��� ------------------------

	// pc
	pc.posX = 930;
	pc.posY = 200;
	pc.arrX = 8;
	pc.arrY = 3;

	// �浿
	gildongs[0].posX = pc.posX - CELL_WIDTH * 3;
	gildongs[0].posY = pc.posY + CELL_WIDTH * 2;
	gildongs[0].arrX = pc.arrX - 3;
	gildongs[0].arrY = pc.arrY + 2;

	gildongs[1].posX = pc.posX - CELL_WIDTH * 2;
	gildongs[1].posY = pc.posY + CELL_WIDTH * 4;
	gildongs[1].arrX = pc.arrX - 2;
	gildongs[1].arrY = pc.arrY + 4;


	// �����
	refrigerator.posX = pc.posX - CELL_WIDTH * 4;
	refrigerator.posY = pc.posY - CELL_WIDTH * 2;
	refrigerator.arrX = pc.arrX - 4;
	refrigerator.arrY = pc.arrY - 2;

	// ��
	crabs[0].posX = pc.posX - CELL_WIDTH * 4;
	crabs[0].posY = pc.posY;
	crabs[0].arrX = pc.arrX - 4;
	crabs[0].arrY = pc.arrY;

	crabs[1].posX = pc.posX - CELL_WIDTH * 3;
	crabs[1].posY = pc.posY;
	crabs[1].arrX = pc.arrX - 3;
	crabs[1].arrY = pc.arrY;

	crabs[2].posX = pc.posX - CELL_WIDTH * 5;
	crabs[2].posY = pc.posY + CELL_WIDTH * 1;
	crabs[2].arrX = pc.arrX - 5;
	crabs[2].arrY = pc.arrY + 1;

	crabs[3].posX = pc.posX - CELL_WIDTH * 3;
	crabs[3].posY = pc.posY + CELL_WIDTH * 1;
	crabs[3].arrX = pc.arrX - 3;
	crabs[3].arrY = pc.arrY + 1;

	crabs[4].posX = pc.posX - CELL_WIDTH * 2;
	crabs[4].posY = pc.posY + CELL_WIDTH * 2;
	crabs[4].arrX = pc.arrX - 2;
	crabs[4].arrY = pc.arrY + 2;

	crabs[5].posX = pc.posX - CELL_WIDTH * 1;
	crabs[5].posY = pc.posY + CELL_WIDTH * 2;
	crabs[5].arrX = pc.arrX - 1;
	crabs[5].arrY = pc.arrY + 2;

	crabs[6].posX = pc.posX - CELL_WIDTH * 5;
	crabs[6].posY = pc.posY + CELL_WIDTH * 3;
	crabs[6].arrX = pc.arrX - 5;
	crabs[6].arrY = pc.arrY + 3;

	crabs[7].posX = pc.posX - CELL_WIDTH * 3;
	crabs[7].posY = pc.posY + CELL_WIDTH * 3;
	crabs[7].arrX = pc.arrX - 3;
	crabs[7].arrY = pc.arrY + 3;


	// �ڹ���
	lock.posX = pc.posX - CELL_WIDTH * 1;
	lock.posY = pc.posY - CELL_WIDTH * 1;
	lock.arrX = pc.arrX - 1;
	lock.arrY = pc.arrY - 1;
	
	// Ű
	key.posX = pc.posX - CELL_WIDTH * 7;
	key.posY = pc.posY + CELL_WIDTH * 3;
	key.arrX = pc.arrX - 7;
	key.arrY = pc.arrY + 3;


	walkCnt = 35;
	shield_flag = 0;
	key_flag = 0;
	poison_flag = 0;
	poison_cnt = 0;
	bulkup_flag = 0;
	bulkup_cnt = 0;
	startTime = clock();

}

void stage3() {

	curStage = 3;

	stage3_initPos();

	while (1) {

		SDL_RenderClear(renderer);

		if (processKeyInput() == -1) 
			stage3_initPos();
		
		drawStage(0, -1);
		SDL_RenderPresent(renderer);

		if (collision_pc_refrigerator()) {
			gameClear();
			break;
		}



		if (walkCnt <= 0 || curTime > stageTime) {
			pc_melting();
			gameOver();
			stage3_initPos();

		}
	}
}