#include <Novice.h>
#include "DoesNotExistBG.h"

void DoesNotExistBG::Draw(int istranslate[1]) {

	int DoseNotExistBG = Novice::LoadTexture("./Resources/images/bg6.png");

	if (istranslate[0] == 31) {
		Novice::DrawSprite((int)position_.x, (int)position_.y, DoseNotExistBG, 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 32) {
		Novice::DrawSprite((int)position_.x, (int)position_.y, DoseNotExistBG, 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 33) {
		Novice::DrawSprite((int)position_.x, (int)position_.y, DoseNotExistBG, 1, 1, 0.0f, WHITE);
	}
}