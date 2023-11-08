#include "BackGroundDraw.h"
#include <Novice.h>

void Translate(bool istranslate[40]) {

	int BackGround[3];
	BackGround[0] = Novice::LoadTexture("./Resources/images/bg.png");
	BackGround[1] = Novice::LoadTexture("./Resources/images/bg1.png");
	BackGround[2] = Novice::LoadTexture("./Resources/images/bg2.png");

	if (istranslate[0] == false) {
		Novice::DrawSprite(0, 0, BackGround[0], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[1] == true) {
		Novice::DrawSprite(0, 0, BackGround[1], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[2] == true) {
		Novice::DrawSprite(0, 0, BackGround[2], 1, 1, 0.0f, WHITE);
	}
}

 