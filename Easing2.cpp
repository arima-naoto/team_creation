#include "Easing.h"

void EaseIn2(Box2* box2, bool istranslate[40]) {

	if (box2->isEase == true) {
		istranslate[0] = true;

		box2->t += 0.05f;
		box2->EasedT = box2->t * box2->t;
		box2->EasedX = (1.0f - box2->EasedT) * box2->EasedX1 + box2->EasedT * box2->EasedX2;
	}

	if (box2->width + box2->EasedX >= 0) {
		box2->width = 1280.0f;
		box2->EasedX = 0.0f;
		box2->isEase = false;
	}
}