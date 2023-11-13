#pragma once

typedef struct Vector2 {
	float x;
	float y;
}Vector2;

typedef struct Player {
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 rand;
	float speed;
	float radius;
	float ShakeTimer;
	unsigned int color;
	bool isJump;
	bool JumpSystem;
	bool Shake;

}Player;

typedef struct Box {
	Vector2 position;
	float radius;
	unsigned int color;
}Box;