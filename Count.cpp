#include "Count.h"

void ReturnCount(int& count, int istranslate[1]) {

	if (count >= 4) {
		count = 0;

		istranslate[0] = 32;
	}

}