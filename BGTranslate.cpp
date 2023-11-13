#include "BGTranslate.h"
#include <Novice.h>

void BGTranslate(Box* box, float &playerLeftX, float &playerRightX, float &BoxLeftX, float &BoxRightX,char keys[] ,char prekeys[] ,int istranslate[40]) {

	if (istranslate[0] == 2) {
		if (playerLeftX <= BoxRightX && BoxLeftX <= playerRightX) {
			box->color = RED;
		}
		else {
			box->color = BLUE;
		}
		if (box->color == RED) {
			if (keys[DIK_SPACE] && prekeys[DIK_SPACE] == false) {
				istranslate[1] = 1;
			}
		}
	}
}