#include "BackGroundDraw.h"
#include <Novice.h>

void Translate(int istranslate[1]) {

	int BackGround[9];
	BackGround[0] = Novice::LoadTexture("./Resources/images/bg.png");
	BackGround[1] = Novice::LoadTexture("./Resources/images/bg1.png");
	BackGround[2] = Novice::LoadTexture("./Resources/images/bg2.png");
	BackGround[3] = Novice::LoadTexture("./Resources/images/bg3.png");
	BackGround[4] = Novice::LoadTexture("./Resources/images/bg4.png");
	BackGround[5] = Novice::LoadTexture("./Resources/images/bg5.png");
	BackGround[6] = Novice::LoadTexture("./Resources/images/bg6.png");
	BackGround[7] = Novice::LoadTexture("./Resources/images/bg7.png");
	BackGround[8] = Novice::LoadTexture("./Resources/images/bg8.png");

	if (istranslate[0] == 0) {
		Novice::DrawSprite(0, 0, BackGround[0], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 1) {
		Novice::DrawSprite(0, 0, BackGround[2], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 2) {
		Novice::DrawSprite(0, 0, BackGround[1], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 3) {
		Novice::DrawSprite(0, 0, BackGround[4], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 4) {
		Novice::DrawSprite(0, 0, BackGround[3], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 5) {
		Novice::DrawSprite(0, 0, BackGround[5], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 6) {
		Novice::DrawSprite(0, 0, BackGround[7], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 7) {
		Novice::DrawSprite(0, 0, BackGround[6], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 8) {
		Novice::DrawSprite(0, 0, BackGround[8], 1, 1, 0.0f, WHITE);
	}
}

 