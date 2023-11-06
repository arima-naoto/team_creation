#include "Easing.h"

void EaseIn(Player* player, Box* box, Box2* box2, float &Timer) {

	if (player->position.x >= 1246) {
		player->speed = 0;
		box->isEase = true;
	}

	if (box->isEase == true) {
		box->t += 0.05f;
		box->EasedT = box->t * box->t;
		box->EasedX = (1.0f - box->EasedT) * box->EasedX1 + box->EasedT * box->EasedX2;
	}

	if (box->width + box->EasedX >= 1280) {
		box->width = 1280.0f;
		box->EasedX = 0.0f;
		Timer += 1.0f;
	}

	if (Timer >= 30) {
		Timer = 30.0f;
		box->isEase = false;
		box2->isEase = true;
	}

}