#include "translate.h"

void PlayerTranslate6(Player* player, int istranslate[1]) {
	if (istranslate[0] == 13) {

		if (player->position.x >= 1224) {
			istranslate[0] = 14;
			player->position.x = 13.0f;
		}

		if (player->position.x <= 0) {
			istranslate[0] = 12;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 14) {
		if (player->position.x <= 0) {
			istranslate[0] = 13;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 12) {

		if (player->position.x >= 1224) {
			istranslate[0] = 13;
			player->position.x = 13.0f;
		}
	}
}