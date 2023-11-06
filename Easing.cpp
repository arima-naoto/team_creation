#include "Easing.h"

void EaseIn(Player* player, Box* box) {

	if (player->position.x >= 1248) {
		player->speed = 0;
		box->isEase = true;
	}

	if (box->isEase == true) {

		box->t += 0.1f;

		box->EasedT = box->t * box->t;

		box->EasedX = (1.0f - box->EasedT) * box->EasedX1 + box->EasedT * box->EasedX2;

	}

}