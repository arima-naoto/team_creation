#include "translate.h"

void PlayerTranslate4(Player* player, int istranslate[1]) {
	if (istranslate[0] == 32) {

		if (player->position.x >= 1246) {
			istranslate[0] = 33;
			player->position.x = 45.0f;
		}

		if (player->position.x <= 32) {
			istranslate[0] = 31;
			player->position.x = 1235.0f;
		}
	}

	if (istranslate[0] == 33) {
		if (player->position.x <= 32) {
			istranslate[0] = 32;
			player->position.x = 1235.0f;
		}
	}

	if (istranslate[0] == 31) {

		if (player->position.x >= 1246) {
			istranslate[0] = 32;
			player->position.x = 32.0f;
		}
	}
}