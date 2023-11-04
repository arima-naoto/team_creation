#include <Novice.h>
#include "Player.h"

void PlayerJump(Player* player, char keys[],char preKeys[]) {

	
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == false && player->position.y == player->radius) {
		player->velocity.y = 10.0f;
	}

	player->velocity.x += player->acceleration.x;
	player->velocity.y += player->acceleration.y;

	player->position.x += player->velocity.x;
	player->position.y += player->velocity.y;

	if (player->position.y <= player->radius) {
		player->position.y = player->radius;
	}

}