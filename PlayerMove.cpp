#include <Novice.h>
#include "PlayerMove.h"

void PlayerMove(Player* player,char keys[]) {

	if (keys[DIK_RIGHT]) {
		player->position.x += player->speed;
	}

	if (keys[DIK_LEFT]) {
		player->position.x -= player->speed;
	}

}