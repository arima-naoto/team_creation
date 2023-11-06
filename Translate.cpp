#include <Novice.h>
#include "Translate.h"

void Translate(bool istranslate[40]) {

	if (istranslate[0] == false) {
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLUE, kFillModeSolid);
	}

	if (istranslate[0] == true) {
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, RED, kFillModeSolid);
	}

}