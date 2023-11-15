#include "translate.h"

void PlayerTranslate3(Player* player, int istranslate[1]) {
	if (istranslate[0] == 7) {

		if (player->position.x >= 1246) {
			istranslate[0] = 8;
			player->position.x = 45.0f;
		}

		if (player->position.x <= 32) {
			istranslate[0] = 6;
			player->position.x = 1235.0f;
		}
	}

	if (istranslate[0] == 8) {
		if (player->position.x <= 32) {
			istranslate[0] = 7;
			player->position.x = 1235.0f;
		}
	}

	if (istranslate[0] == 6) {

		if (player->position.x >= 1246) {
			istranslate[0] = 7;
			player->position.x = 32.0f;
		}
	}
}