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

void BGTranslate3(Box* box, float& playerLeftX, float& playerRightX, float& BoxLeftX, float& BoxRightX, char keys[], char prekeys[], int istranslate[1], int& count) {

	if (istranslate[0] == 5) {
		if (playerLeftX <= BoxRightX && BoxLeftX <= playerRightX) {
			box->color = RED;
		}
		else {
			box->color = WHITE;
		}
		if (box->color == RED) {
			if (keys[DIK_C] && prekeys[DIK_C] == false) {
				istranslate[0] = 10;
				count++;
			}
		}
	}

	if (istranslate[0] == 10) {
		if (playerLeftX <= BoxRightX && BoxLeftX <= playerRightX) {
			box->color = RED;
		}
		else {
			box->color = WHITE;
		}
		if (box->color == RED) {
			if (keys[DIK_Z] && prekeys[DIK_Z] == false) {
				istranslate[0] = 5;
				count++;
			}
		}
	}
}

void BGTranslate4(Box* box, float& playerLeftX, float& playerRightX, float& BoxLeftX, float& BoxRightX, char keys[], char prekeys[], int istranslate[1], int& count) {

	if (istranslate[0] == 6) {
		if (playerLeftX <= BoxRightX && BoxLeftX <= playerRightX) {
			box->color = RED;
		}
		else {
			box->color = WHITE;
		}
		if (box->color == RED) {
			if (keys[DIK_C] && prekeys[DIK_C] == false) {
				istranslate[0] = 13;
				count++;
			}
		}
	}

	if (istranslate[0] == 13) {
		if (playerLeftX <= BoxRightX && BoxLeftX <= playerRightX) {
			box->color = RED;
		}
		else {
			box->color = WHITE;
		}
		if (box->color == RED) {
			if (keys[DIK_Z] && prekeys[DIK_Z] == false) {
				istranslate[0] = 6;
				count++;
			}
		}
	}
}

void BGTranslate5(Box* box2, float& playerLeftX, float& playerRightX, float& BoxLeftX2, float& BoxRightX2, char keys[], char prekeys[], int istranslate[1]) {

	if (istranslate[0] == 33) {
		if (playerLeftX <= BoxRightX2 && BoxLeftX2 <= playerRightX) {
			box2->color = RED;
		}
		else {
			box2->color = WHITE;
		}
		if (box2->color == RED) {
			if (keys[DIK_F] && prekeys[DIK_F] == false) {
				istranslate[0] = 0;
			}
		}
	}
}