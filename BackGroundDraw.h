#pragma once
#include "MyTypedef.h"

void BackGroundShake(Player* player, float& BGRandX, float& BGRandY, float& BGShakeTimer, bool& BGShake, int istranslate[1]);

void BackGroundShake2(Player* player, float& BGRandX, float& BGRandY, float& BGShakeTimer, bool& BGShake, int istranslate[1]);

void Translate(int istranslate[1],float& BGRandX, float& BGRandY);

