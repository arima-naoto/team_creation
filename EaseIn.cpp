#include "EaseIn.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

float EaseIn(float position) {
	return 1 -cosf((position * float(M_PI) / 1 * 2));
}

float EaseInExpo(float x) {

	return x * x * x;

}

float EaseIn2(float x) {

	return 1 - cosf((x * float(M_PI) / 1 * 2));

}