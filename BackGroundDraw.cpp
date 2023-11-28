#include "BackGroundDraw.h"
#include <Novice.h>

void Translate(int istranslate[1], float& BGRandX, float& BGRandY){

	int BGpositionX = 0;
	int BGpositionY = 0;

	int BackGround[15];
	BackGround[0] = Novice::LoadTexture("./Resources/images/bg.png");
	BackGround[1] = Novice::LoadTexture("./Resources/images/bg1.png");
	BackGround[2] = Novice::LoadTexture("./Resources/images/bg2.png");
	BackGround[3] = Novice::LoadTexture("./Resources/images/bg3.png");
	BackGround[4] = Novice::LoadTexture("./Resources/images/bg4.png");
	BackGround[5] = Novice::LoadTexture("./Resources/images/bg5.png");
	BackGround[6] = Novice::LoadTexture("./Resources/images/bg6.png");
	BackGround[7] = Novice::LoadTexture("./Resources/images/bg7.png");
	BackGround[8] = Novice::LoadTexture("./Resources/images/bg8.png");
	BackGround[9] = Novice::LoadTexture("./Resources/images/bg12.png");
	BackGround[10] = Novice::LoadTexture("./Resources/images/bg13.png");
	BackGround[11] = Novice::LoadTexture("./Resources/images/bg14.png");
	BackGround[12] = Novice::LoadTexture("./Resources/images/bg15.png");
	BackGround[13] = Novice::LoadTexture("./Resources/images/bg16.png");
	BackGround[14] = Novice::LoadTexture("./Resources/images/bg17.png");

	if (istranslate[0] == 0) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[0], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 1) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[2], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 2) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[1], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 3) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[4], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 4) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[3], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 5) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[5], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 6) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[7], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 7) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[6], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 8) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[8], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 9) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[11], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 10) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[9], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 11) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[10], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 12) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[12], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 13) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[13], 1, 1, 0.0f, WHITE);
	}

	if (istranslate[0] == 14) {
		Novice::DrawSprite(BGpositionX + (int)BGRandX, BGpositionY + (int)BGRandY, BackGround[14], 1, 1, 0.0f, WHITE);
	}
}

 