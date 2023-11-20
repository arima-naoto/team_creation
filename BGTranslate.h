#pragma once
#include <Novice.h>
#include "MyTypedef.h"

void BGTranslate(Box* box, float& playerLeftX, float& playerRightX, float& BoxLeftX, float& BoxRightX, char keys[], char prekeys[], int istranslate[1],int &count) {

	if (istranslate[0] == 2) {
		if (playerLeftX <= BoxRightX && BoxLeftX <= playerRightX) {
			box->color = RED;
		}
		else {
			box->color = WHITE;
		}
		if (box->color == RED) {
			if (keys[DIK_C] && prekeys[DIK_C] == false) {
				istranslate[0] = 4;
				count++;
			}
		}
	}

	if (istranslate[0] == 4) {
		if (playerLeftX <= BoxRightX && BoxLeftX <= playerRightX) {
			box->color = RED;
		}
		else {
			box->color = WHITE;
		}
		if (box->color == RED) {
			if (keys[DIK_Z] && prekeys[DIK_Z] == false) {
				istranslate[0] = 2;
				count++;
			}
		}
	}
}


void BGTranslate2(Box* box, float& playerLeftX, float& playerRightX, float& BoxLeftX, float& BoxRightX, char keys[], char prekeys[], int istranslate[1], int &count) {

	if (istranslate[0] == 1) {
		if (playerLeftX <= BoxRightX && BoxLeftX <= playerRightX) {
			box->color = RED;
		}
		else {
			box->color = WHITE;
		}
		if (box->color == RED) {
			if (keys[DIK_C] && prekeys[DIK_C] == false) {
				istranslate[0] = 7;
				count++;
			}
		}
	}

	if (istranslate[0] == 7) {
		if (playerLeftX <= BoxRightX && BoxLeftX <= playerRightX) {
			box->color = RED;
		}
		else {
			box->color = WHITE;
		}
		if (box->color == RED) {
			if (keys[DIK_Z] && prekeys[DIK_Z] == false) {
				istranslate[0] = 1;
				count++;
			}
		}
	}
}

