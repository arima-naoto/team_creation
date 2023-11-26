#include "translate.h"

void PlayerTranslate2(Player* player, int istranslate[1]) {
	if (istranslate[0] == 4) {

		if (player->position.x >= 1224) {
			istranslate[0] = 5;
			player->position.x = 13.0f;
		}

		if (player->position.x <= 0) {
			istranslate[0] = 3;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 5) {
		if (player->position.x <= 0) {
			istranslate[0] = 4;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 3) {

		if (player->position.x >= 1224) {
			istranslate[0] = 4;
			player->position.x = 13.0f;
		}
	}
}

