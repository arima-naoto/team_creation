#include <Novice.h>
#include "Easing.h"

void EaseInDraw(Box* box) {

	if (box->isEase == true) {
		Novice::DrawBox((int)box->position.x, (int)box->position.y, (int)box->width + (int)box->EasedX, (int)box->height, 0.0f, (int)box->color, kFillModeSolid);
	}
}

void EaseInDraw2(Box2* box2) {

	if (box2->isEase == true) {
		Novice::DrawBox((int)box2->position.x, (int)box2->position.y, (int)box2->width + (int)box2->EasedX, (int)box2->height, 0.0f, (int)box2->color, kFillModeSolid);
	}
}