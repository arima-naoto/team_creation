#include "translate.h"

void PlayerTranslate2(Player* player, int istranslate[1]) {
	if (istranslate[0] == 4) {

		if (player->position.x >= 1246) {
			istranslate[0] = 5;
			player->position.x = 45.0f;
		}

		if (player->position.x <= 32) {
			istranslate[0] = 3;
			player->position.x = 1235.0f;
		}
	}

	if (istranslate[0] == 5) {
		if (player->position.x <= 32) {
			istranslate[0] = 4;
			player->position.x = 1235.0f;
		}
	}

	if (istranslate[0] == 3) {

		if (player->position.x >= 1246) {
			istranslate[0] = 4;
			player->position.x = 32.0f;
		}
	}
}

