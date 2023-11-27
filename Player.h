#pragma once
#include"MyTypedef.h"

void PlayerJump(Player* player, char keys[],char preKeys[]);

void PlayerMove(Player* player, char keys[], float& playerLeftX, float& playerRightX, int& direction);

void PlayerShake(Player* player, int istranslate[1]);

void PlayerShake2(Player* player, int istranslate[1]);