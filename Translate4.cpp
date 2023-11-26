#include "translate.h"

void PlayerTranslate4(Player* player, int istranslate[1]) {
	if (istranslate[0] == 32) {

		if (player->position.x >= 1224) {
			istranslate[0] = 33;
			player->position.x = 13.0f;
		}

		if (player->position.x <= 0) {
			istranslate[0] = 31;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 33) {
		if (player->position.x <= 0) {
			istranslate[0] = 32;
			player->position.x = 1200.0f;
		}
	}

	if (istranslate[0] == 31) {

		if (player->position.x >= 1224) {
			istranslate[0] = 32;
			player->position.x = 13.0f;
		}
	}
}