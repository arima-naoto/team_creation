#include "KeyAcquisition.h"

void KeyAcquisition(Kagi *kagi,float& playerLeftX, float& playerRightX, float& KeyLeftX, float& KeyRightX, int istranslate[1]) {

	if (istranslate[0] == 3) {
		if (playerLeftX <= KeyRightX && KeyLeftX <= playerRightX) {
			kagi->Acquisition = true;
			kagi->position.x = -10;
			kagi->position.y = 0;
		}
	}
}
void KeyAcquisition2(Kagi* kagi2, float& playerLeftX, float& playerRightX, float& KeyLeftX2, float& KeyRightX2, int istranslate[1]) {

	if (istranslate[0] == 8) {
		if (playerLeftX <= KeyRightX2 && KeyLeftX2 <= playerRightX) {
			kagi2->Acquisition = true;
			kagi2->position.x = 30;
			kagi2->position.y = 0;
		}
	}
}