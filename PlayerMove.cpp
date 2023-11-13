#include <Novice.h>
#include "PlayerMove.h"

void PlayerMove(Player* player,char keys[],float &playerLeftX,float &playerRightX) {

	if (keys[DIK_RIGHT]) {
		player->position.x += player->speed;
	}

	if (keys[DIK_LEFT]) {
		player->position.x -= player->speed;
	}

	playerLeftX = (player->position.x - player->radius);
	playerRightX = (player->position.x + player->radius);

}