#include "Button.h"
#include <Novice.h>

void Button(int istranslate[1], Kagi* kagi, Kagi* kagi2) {

	int ButtonHandle[6];
	ButtonHandle[0] = Novice::LoadTexture("./Resources/images/RightKey.png");
	ButtonHandle[1] = Novice::LoadTexture("./Resources/images/LeftKey.png");
	ButtonHandle[2] = Novice::LoadTexture("./Resources/images/Spacekey.png");
	ButtonHandle[3] = Novice::LoadTexture("./Resources/images/CKey.png");
	ButtonHandle[4] = Novice::LoadTexture("./Resources/images/Zkey.png");
	ButtonHandle[5] = Novice::LoadTexture("./Resources/images/Fkey.png");

	Novice::DrawSprite(1195, 0, ButtonHandle[0], 1, 1, 0.0f, WHITE);

	Novice::DrawSprite(1147, 0, ButtonHandle[1], 1, 1, 0.0f, WHITE);

	Novice::DrawSprite(1147, 48, ButtonHandle[2], 1, 1, 0.0f, WHITE);

	if (istranslate[0] == 1 || istranslate[0] == 2 || istranslate[0] == 5 || istranslate[0] == 6) {
		Novice::DrawSprite(1041, 0, ButtonHandle[3], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 4 || istranslate[0] == 7 || istranslate[0] == 10 || istranslate[0] == 13) {
		Novice::DrawSprite(1041, 0, ButtonHandle[4], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 33) {
		Novice::DrawSprite(1041, 0, ButtonHandle[5], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 0) {
		if (kagi->Acquisition == true && kagi2->Acquisition == true) {
			Novice::DrawSprite(1041, 0, ButtonHandle[5], 1, 1, 0.0f, WHITE);
		}
	}
}