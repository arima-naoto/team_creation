#include "Player.h"
#include "BackGroundDraw.h"
#include <stdlib.h>

void PlayerShake(Player* player ,int istranslate[1]) {

	if (istranslate[0] == 2|| istranslate[0] == 3 || istranslate[0] == 6 || istranslate[0] == 31) {

		if (player->position.x <= 28) {
			player->position.x = 28.0f;
			player->Shake = true;
		}

		if (player->Shake == true) {
			player->ShakeTimer += 1.0f;
		}

		if (player->ShakeTimer > 1 && player->ShakeTimer < 70) {
			player->rand.x = rand() % 11 - 5.0f;
			player->rand.y = rand() % 11 - 5.0f;
		}

		if (player->ShakeTimer > 10) {
			player->rand.x = rand() % 9 - 4.0f;
			player->rand.y = rand() % 9 - 4.0f;
		}

		if (player->ShakeTimer > 20) {
			player->rand.x = rand() % 5 - 2.0f;
			player->rand.y = rand() % 5 - 2.0f;
		}

		if (player->ShakeTimer > 30) {
			player->rand.x = rand() % 1 - 1.0f;
			player->rand.y = rand() % 1 - 1.0f;
		}

		if (player->ShakeTimer >= 40) {
			player->ShakeTimer = 0;
			player->Shake = false;
			player->rand.x = 0;
			player->rand.y = 0;
		}
	}
}

void PlayerShake2(Player* player, int istranslate[1]) {

	if (istranslate[0] == 1 || istranslate[0] == 5 || istranslate[0] == 8||istranslate[0] == 33) {

		if (player->position.x >= 1189) {
			player->position.x = 1189.0f;
			player->Shake = true;
		}

		if (player->Shake == true) {
			player->ShakeTimer += 1.0f;
		}

		if (player->ShakeTimer > 1 && player->ShakeTimer < 70) {
			player->rand.x = rand() % 11 - 5.0f;
			player->rand.y = rand() % 11 - 5.0f;
		}

		if (player->ShakeTimer > 10) {
			player->rand.x = rand() % 9 - 4.0f;
			player->rand.y = rand() % 9 - 4.0f;
		}

		if (player->ShakeTimer > 20) {
			player->rand.x = rand() % 5 - 2.0f;
			player->rand.y = rand() % 5 - 2.0f;
		}

		if (player->ShakeTimer > 30) {
			player->rand.x = rand() % 1 - 1.0f;
			player->rand.y = rand() % 1 - 1.0f;
		}

		if (player->ShakeTimer >= 40) {
			player->ShakeTimer = 0;
			player->Shake = false;
			player->rand.x = 0;
			player->rand.y = 0;
		}

	}
}

void BackGroundShake(Player* player, float& BGRandX, float& BGRandY, float& BGShakeTimer, bool &BGShake, int istranslate[1]) {

	if (istranslate[0] == 2 || istranslate[0] == 3 || istranslate[0] == 6 || istranslate[0] == 31) {

		if (player->position.x <= 28) {
			player->position.x = 28.0f;
			BGShake = true;
		}

		if (BGShake == true) {
			BGShakeTimer += 1.0f;
		}

		if (BGShakeTimer > 1 && BGShakeTimer < 40) {
			BGRandX = rand() % 11 - 5.0f;
			BGRandY = rand() % 11 - 5.0f;
		}

		if (BGShakeTimer > 10) {
			BGRandX = rand() % 9 - 4.0f;
			BGRandY = rand() % 9 - 4.0f;
		}

		if (BGShakeTimer > 20) {
			BGRandX = rand() % 5 - 2.0f;
			BGRandY = rand() % 5 - 2.0f;
		}

		if (BGShakeTimer > 30) {
			BGRandX = rand() % 1 - 0.0f;
			BGRandY = rand() % 1 - 0.0f;
		}

		if (BGShakeTimer >= 40) {
			BGShakeTimer = 0;
			BGShake = false;
			BGRandX = 0;
			BGRandY = 0;
		}
	}
}

void BackGroundShake2(Player* player, float& BGRandX, float& BGRandY, float& BGShakeTimer, bool& BGShake, int istranslate[1]) {

	if (istranslate[0] == 1 || istranslate[0] == 5 || istranslate[0] == 8 || istranslate[0] == 33) {

		if (player->position.x >= 1189) {
			player->position.x = 1189.0f;
			BGShake = true;
		}

		if (BGShake == true) {
			BGShakeTimer += 1.0f;
		}

		if (BGShakeTimer > 1 && BGShakeTimer < 40) {
			BGRandX = rand() % 11 - 5.0f;
			BGRandY = rand() % 11 - 5.0f;
		}

		if (BGShakeTimer > 10) {
			BGRandX = rand() % 9 - 4.0f;
			BGRandY = rand() % 9 - 4.0f;
		}

		if (BGShakeTimer > 20) {
			BGRandX = rand() % 5 - 2.0f;
			BGRandY = rand() % 5 - 2.0f;
		}

		if (BGShakeTimer > 30) {
			BGRandX = rand() % 1 - 0.0f;
			BGRandY = rand() % 1 - 0.0f;
		}

		if (BGShakeTimer >= 40) {
			BGShakeTimer = 0;
			BGShake = false;
			BGRandX = 0;
			BGRandY = 0;
		}
	}
}