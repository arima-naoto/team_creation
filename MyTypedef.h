#pragma once

typedef struct Vector2 {
	float x;
	float y;
}Vector2;

typedef struct Player {
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	float speed;
	float radius;
	unsigned int color;
	bool isJump;
	bool JumpSystem;
	
}Player;