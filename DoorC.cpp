#include "DoorC.h"
#include <Novice.h>

void DoorC(Kagi* kagi,Kagi* kagi2, float& playerLeftX, float& playerRightX, float& DoorLeftX, float& DoorRightX, char keys[], char prekeys[], int istranslate[1], int &doorChange) {

	if (istranslate[0] == 0 && doorChange == 0) {
		if (kagi->Acquisition == true && kagi2->Acquisition == true) {
			if (playerLeftX <= DoorRightX && DoorLeftX <= playerRightX) {
				if (keys[DIK_F] && prekeys[DIK_F] == false) {
					doorChange = 1;
					kagi->Acquisition = false;
					kagi2->Acquisition = false;
				}
			}
		}
	}
}