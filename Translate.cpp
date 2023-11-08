#include "PlayerMove.h"

void PlayerTranslate(Player* player, bool istranslate[40]) {
	if (istranslate[0] == false) {
		if (player->position.x >= 1246) {
			istranslate[1] = true;
			player->position.x = 100.0f;
		}
	}

	if (istranslate[1] == true) {
		if (player->position.x <= 32) {
			istranslate[1] = false;
			player->position.x = 1248.0f;
		}


	}

}


