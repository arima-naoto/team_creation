#include "translate.h"

void PlayerTranslate5(Player* player, int istranslate[1]) {
	if (istranslate[0] == 10) {

		if (player->position.x >= 1224) {
			istranslate[0] = 11;
			player->position.x = 13.0f;
		}

		if (player->position.x <= 0) {
			istranslate[0] = 9;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 11) {
		if (player->position.x <= 0) {
			istranslate[0] = 10;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 9) {

		if (player->position.x >= 1224) {
			istranslate[0] = 10;
			player->position.x = 13.0f;
		}
	}
}