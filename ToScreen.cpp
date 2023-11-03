#include "ToScreen.h"

Vector2 ToScreen(Vector2 world) {

	const Vector2 ScreenTransLate = { 0.0f,500.0f };
	const Vector2 ScreenScale = { 1.0f , -1.0f };

	return {
		(world.x * ScreenScale.x) + ScreenTransLate.x,
		(world.y * ScreenScale.y) + ScreenTransLate.y
	};
}