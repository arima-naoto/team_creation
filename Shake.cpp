#include "Player.h"
#include <stdlib.h>

void PlayerShake(Player* player ,int istranslate[1]) {

	if (istranslate[0] == 2|| istranslate[0] == 3 || istranslate[0] == 6) {

		if (player->position.x <= 33) {
			player->position.x = 33.0f;
			player->Shake = true;
		}

		if (player->Shake == true) {
			player->ShakeTimer += 1.0f;
		}

		if (player->ShakeTimer > 1 && player->ShakeTimer < 70) {
			player->rand.x = rand() % 25 - 12.0f;
			player->rand.y = rand() % 25 - 12.0f;
		}

		if (player->ShakeTimer > 10) {
			player->rand.x = rand() % 21 - 10.0f;
			player->rand.y = rand() % 21 - 10.0f;
		}

		if (player->ShakeTimer > 20) {
			player->rand.x = rand() % 17 - 8.0f;
			player->rand.y = rand() % 17 - 8.0f;
		}

		if (player->ShakeTimer > 30) {
			player->rand.x = rand() % 13 - 6.0f;
			player->rand.y = rand() % 13 - 6.0f;
		}

		if (player->ShakeTimer > 40) {
			player->rand.x = rand() % 9 - 4.0f;
			player->rand.y = rand() % 9 - 4.0f;
		}

		if (player->ShakeTimer > 50) {
			player->rand.x = rand() % 5 - 2.0f;
			player->rand.y = rand() % 5 - 2.0f;
		}

		if (player->ShakeTimer > 60) {
			player->rand.x = rand() % 1 - 1.0f;
			player->rand.y = rand() % 1 - 1.0f;
		}

		if (player->ShakeTimer >= 70) {
			player->ShakeTimer = 0;
			player->Shake = false;
			player->rand.x = 0;
			player->rand.y = 0;
		}

	}
}