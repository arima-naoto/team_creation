#include "Count.h"
#include <Novice.h>

void ReturnCount(int& count, int istranslate[1]) {

	if (count >= 8) {
		count = 0;
		istranslate[0] = 32;
	}
}