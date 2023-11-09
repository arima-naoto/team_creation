#include "PlayerMove.h"

void PlayerTranslate(Player* player, int istranslate[40]) {
	if (istranslate[0] == 0) {

		if (player->position.x >= 1246) {
			istranslate[0] = 1;
			player->position.x = 45.0f;
		}

		if (player->position.x <= 32) {
			istranslate[0] = 2;
			player->position.x = 1235.0f;
		}
	}

	if (istranslate[0] == 1) {
		if (player->position.x <= 32) {
			istranslate[0] = 0;
			player->position.x = 1235.0f;
		}
	}

	if (istranslate[0] == 2) {

		if (player->position.x >= 1246) {
			istranslate[0] = 0;
			player->position.x = 32.0f;
		}
	}
}


