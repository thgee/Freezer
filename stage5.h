#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage5_initPos() {

	// ���ӿ� ���̴� NPC�� �����ϰ��� ���� ȭ���� �ٱ��ʿ� �׷���
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

	door.posX = -100;
	door.posY = -100;
	door.arrX = -1;
	door.arrY = -1;

	// pc
	pc.posX = 650;
	pc.posY = 40;
	pc.arrX = 3;
	pc.arrY = 1;

	// �浿
	gildongs[0].posX = pc.posX - CELL_WIDTH * 1;
	gildongs[0].posY = pc.posY + CELL_WIDTH * 4;
	gildongs[0].arrX = pc.arrX - 1;
	gildongs[0].arrY = pc.arrY + 4;

	gildongs[1].posX = pc.posX + CELL_WIDTH * 3;
	gildongs[1].posY = pc.posY + CELL_WIDTH * 5;
	gildongs[1].arrX = pc.arrX + 3;
	gildongs[1].arrY = pc.arrY + 5;


	// ����
	rocks[0].posX = pc.posX - CELL_WIDTH * 1;
	rocks[0].posY = pc.posY + CELL_WIDTH * 1;
	rocks[0].arrX = pc.arrX - 1;
	rocks[0].arrY = pc.arrY + 1;


	rocks[1].posX = pc.posX + CELL_WIDTH * 1;
	rocks[1].posY = pc.posY + CELL_WIDTH * 1;
	rocks[1].arrX = pc.arrX + 1;
	rocks[1].arrY = pc.arrY + 1;

	rocks[3].posX = pc.posX + CELL_WIDTH * 0;
	rocks[3].posY = pc.posY + CELL_WIDTH * 3;
	rocks[3].arrX = pc.arrX + 0;
	rocks[3].arrY = pc.arrY + 3;


	rocks[4].posX = pc.posX + CELL_WIDTH * 1;
	rocks[4].posY = pc.posY + CELL_WIDTH * 4;
	rocks[4].arrX = pc.arrX + 1;
	rocks[4].arrY = pc.arrY + 4;


	rocks[5].posX = pc.posX + CELL_WIDTH * 2;
	rocks[5].posY = pc.posY + CELL_WIDTH * 4;
	rocks[5].arrX = pc.arrX + 2;
	rocks[5].arrY = pc.arrY + 4;


	rocks[6].posX = pc.posX + CELL_WIDTH * 1;
	rocks[6].posY = pc.posY + CELL_WIDTH * 5;
	rocks[6].arrX = pc.arrX + 1;
	rocks[6].arrY = pc.arrY + 5;


	rocks[7].posX = pc.posX + CELL_WIDTH * 3;
	rocks[7].posY = pc.posY + CELL_WIDTH * 6;
	rocks[7].arrX = pc.arrX + 3;
	rocks[7].arrY = pc.arrY + 6;


	// �����
	refrigerator.posX = pc.posX + CELL_WIDTH * 3;
	refrigerator.posY = pc.posY + CELL_WIDTH * 7;
	refrigerator.arrX = pc.arrX + 3;
	refrigerator.arrY = pc.arrY + 7;


	// ��
	crabs[0].posX = pc.posX + CELL_WIDTH * 0;
	crabs[0].posY = pc.posY + CELL_WIDTH * 3;
	crabs[0].arrX = pc.arrX + 0;
	crabs[0].arrY = pc.arrY + 3;

	crabs[1].posX = pc.posX - CELL_WIDTH * 1;
	crabs[1].posY = pc.posY + CELL_WIDTH * 3;
	crabs[1].arrX = pc.arrX - 1;
	crabs[1].arrY = pc.arrY + 3;


	// �ڹ���
	door.posX = pc.posX + CELL_WIDTH * 2;
	door.posY = pc.posY + CELL_WIDTH * 6;
	door.arrX = pc.arrX + 2;
	door.arrY = pc.arrY + 6;


	// Ű
	key.posX = pc.posX + CELL_WIDTH * 1;
	key.posY = pc.posY + CELL_WIDTH * 2;
	key.arrX = pc.arrX + 1;
	key.arrY = pc.arrY + 2;



	walkCnt = 43;
}

void stage5() {

	curStage = 5;
	walkForcrab = 43;

	stage5_initPos();

	while (1) {

		SDL_RenderClear(renderer);

		if (processKeyInput() == -1) { // RŰ ������ �����
			stage5();
		}


		if (walkForcrab % 2 == 0) {
			crab_img = loadTexture("./assets/crab_up.png");
			for (int i = 0; i < MAX_NUM_NPC; i++) {
				drawTexture(crab_img, crabs[i].posX, crabs[i].posY);
			}
		}
		else {
			crab_img = loadTexture("./assets/crab_down.png");
			for (int i = 0; i < MAX_NUM_NPC; i++) {
				drawTexture(crab_img, crabs[i].posX, crabs[i].posY);
			}
		}

		drawStage(0, -1);

		SDL_RenderPresent(renderer);


		if (collision_pc_refrigerator()) {
			gameClear();
			break;
		}

		if (walkCnt <= 0) {
			pc_melting();
			gameOver();
			stage5();
		}
	}
}