#pragma once
#include"MyTypedef.h"

void PlayerJump(Player* player, char keys[],char preKeys[]);

void PlayerMove(Player* player, char keys[], float& playerLeftX, float& playerRightX);

void PlayerShake(Player* player, int istranslate[1]);