#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


void stage4_initPos() {

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

	// pc
	pc.posX = 520;
	pc.posY = 225;
	pc.arrX = 1;
	pc.arrY = 3;

	// �浿
	gildongs[0].posX = pc.posX;
	gildongs[0].posY = pc.posY + CELL_WIDTH * 2;
	gildongs[0].arrX = pc.arrX;
	gildongs[0].arrY = pc.arrY + 2;

	// �����
	refrigerator.posX = pc.posX + CELL_WIDTH * 4;
	refrigerator.posY = pc.posY - CELL_WIDTH * 2;
	refrigerator.arrX = pc.arrX + 4;
	refrigerator.arrY = pc.arrY - 2;

	// ��
	crabs[0].posX = pc.posX;
	crabs[0].posY = pc.posY + CELL_WIDTH * 3;
	crabs[0].arrX = pc.arrX;
	crabs[0].arrY = pc.arrY + 3;

	crabs[1].posX = pc.posX + CELL_WIDTH * 2;
	crabs[1].posY = pc.posY + CELL_WIDTH * 3;
	crabs[1].arrX = pc.arrX + 2;
	crabs[1].arrY = pc.arrY + 3;

	crabs[2].posX = pc.posX + CELL_WIDTH * 5;
	crabs[2].posY = pc.posY + CELL_WIDTH * 3;
	crabs[2].arrX = pc.arrX + 5;
	crabs[2].arrY = pc.arrY + 3;

	crabs[3].posX = pc.posX + CELL_WIDTH * 2;
	crabs[3].posY = pc.posY;
	crabs[3].arrX = pc.arrX + 2;
	crabs[3].arrY = pc.arrY;

	crabs[4].posX = pc.posX + CELL_WIDTH * 3;
	crabs[4].posY = pc.posY + CELL_WIDTH * 1;
	crabs[4].arrX = pc.arrX + 3;
	crabs[4].arrY = pc.arrY + 1;

	crabs[5].posX = pc.posX + CELL_WIDTH * 5;
	crabs[5].posY = pc.posY + CELL_WIDTH * 1;
	crabs[5].arrX = pc.arrX + 5;
	crabs[5].arrY = pc.arrY + 1;

	// ����
	rocks[0].posX = pc.posX + CELL_WIDTH * 2;
	rocks[0].posY = pc.posY + CELL_WIDTH * 2;
	rocks[0].arrX = pc.arrX + 2;
	rocks[0].arrY = pc.arrY + 2;

	rocks[1].posX = pc.posX + CELL_WIDTH * 3;
	rocks[1].posY = pc.posY + CELL_WIDTH * 2;
	rocks[1].arrX = pc.arrX + 3;
	rocks[1].arrY = pc.arrY + 2;

	rocks[2].posX = pc.posX + CELL_WIDTH * 4;
	rocks[2].posY = pc.posY + CELL_WIDTH * 2;
	rocks[2].arrX = pc.arrX + 4;
	rocks[2].arrY = pc.arrY + 2;

	rocks[3].posX = pc.posX + CELL_WIDTH * 5;
	rocks[3].posY = pc.posY + CELL_WIDTH * 2;
	rocks[3].arrX = pc.arrX + 5;
	rocks[3].arrY = pc.arrY + 2;

	rocks[4].posX = pc.posX + CELL_WIDTH * 4;
	rocks[4].posY = pc.posY;
	rocks[4].arrX = pc.arrX + 4;
	rocks[4].arrY = pc.arrY;

	rocks[5].posX = pc.posX + CELL_WIDTH * 4;
	rocks[5].posY = pc.posY - CELL_WIDTH * 1;
	rocks[5].arrX = pc.arrX + 4;
	rocks[5].arrY = pc.arrY - 1;

	// �ڹ���
	door.posX = pc.posX + CELL_WIDTH * 3;
	door.posY = pc.posY - CELL_WIDTH * 1;
	door.arrX = pc.arrX + 3;
	door.arrY = pc.arrY - 1;

	// Ű
	key.posX = pc.posX + CELL_WIDTH * 5;
	key.posY = pc.posY + CELL_WIDTH * 4;
	key.arrX = pc.arrX + 5;
	key.arrY = pc.arrY + 4;

	walkCnt = 25;
}

void stage4() {

	curStage = 4;
	walkForcrab = 26;

	stage4_initPos();

	while (1) {

		SDL_RenderClear(renderer);

		if (processKeyInput() == -1) { // RŰ ������ �����
			stage4();
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
			stage4();
		}
	}
}