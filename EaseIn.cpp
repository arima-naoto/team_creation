#include "EaseIn.h"
#define _USE_MATH_DEFINES
#include <math.h>

float EaseIn(float position) {
	return 1 - cosf((position * float(M_PI) / 2));
}
