#pragma once
#include "MyTypedef.h"

Vector2 ToScreen(Vector2 world) {

	const Vector2 ScreenTransLate = { 0,500 };
	const Vector2 ScreenScale = { 1 , -1 };

	return {
		(world.x * ScreenScale.x) + ScreenTransLate.x,
		(world.y * ScreenScale.y) + ScreenTransLate.y
	};
}