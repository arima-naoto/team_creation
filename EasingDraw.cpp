#include <Novice.h>
#include "Easing.h"

void EaseInDraw(Box* box) {

	if (box->isEase == true) {
		Novice::DrawBox((int)box->position.x, (int)box->position.y, (int)box->width + (int)box->EasedX, (int)box->height, 0.0f, (int)box->color, kFillModeSolid);
	}
}