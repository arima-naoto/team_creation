#include <Novice.h>
#include "Player.h"

void PlayerMove(Player* player, char keys[], float& playerLeftX, float& playerRightX) {

	if (keys[DIK_RIGHT]) {
		player->position.x += player->speed;
	}

	if (keys[DIK_LEFT]) {
		player->position.x -= player->speed;
	}

	playerLeftX = (player->position.x - player->radius);
	playerRightX = (player->position.x + player->radius);

}

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