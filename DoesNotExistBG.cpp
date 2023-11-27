#include <Novice.h>
#include "DoesNotExistBG.h"

void DoesNotExistBG::Draw(int istranslate[1]) {

	int DoseNotExistBG[3];
	DoseNotExistBG[0] = Novice::LoadTexture("./Resources/images/bg9.png");
	DoseNotExistBG[1] = Novice::LoadTexture("./Resources/images/bg10.png");
	DoseNotExistBG[2] = Novice::LoadTexture("./Resources/images/bg11.png");

	if (istranslate[0] == 31) {
		Novice::DrawSprite((int)position_.x, (int)position_.y, DoseNotExistBG[1], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 32) {
		Novice::DrawSprite((int)position_.x, (int)position_.y, DoseNotExistBG[0], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 33) {
		Novice::DrawSprite((int)position_.x, (int)position_.y, DoseNotExistBG[2], 1, 1, 0.0f, WHITE);
	}
}