#include "translate.h"

void PlayerTranslate3(Player* player, int istranslate[1]) {
	if (istranslate[0] == 7) {

		if (player->position.x >= 1224) {
			istranslate[0] = 8;
			player->position.x = 13.0f;
		}

		if (player->position.x <= 0) {
			istranslate[0] = 6;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 8) {
		if (player->position.x <= 0) {
			istranslate[0] = 7;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 6) {

		if (player->position.x >= 1224) {
			istranslate[0] = 7;
			player->position.x = 13.0f;
		}
	}
}