#pragma once
#include "MyTypedef.h"

void EaseIn(Player* player,Box *box, Box2* box2, float &Timer);

void EaseInDraw(Box *box);

void EaseIn2(Box2* box2, bool istranslate[40]);

void EaseInDraw2(Box2* box2);
