#include "translate.h"

void PlayerTranslate(Player* player, int istranslate[1]) {
	if (istranslate[0] == 0) {

		if (player->position.x >= 1224) {
			istranslate[0] = 1;
			player->position.x = 13.0f;
		}

		if (player->position.x <= 0) {
			istranslate[0] = 2;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 1) {
		if (player->position.x <= 0) {
			istranslate[0] = 0;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 2) {

		if (player->position.x >= 1224) {
			istranslate[0] = 0;
			player->position.x = 13.0f;
		}
	}
}


