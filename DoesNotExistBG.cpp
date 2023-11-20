#include <Novice.h>
#include "DoesNotExistBG.h"

void DoesNotExistBG::Draw(int& count) {

	width_ = 1280;
	Height_ = 720;

	if (count >= 4) {
		Novice::DrawBox(0, 0, width_, Height_, 0.0f, BLACK, kFillModeSolid);
	}
}