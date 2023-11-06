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

typedef struct Box {
	Vector2 position;
	float width;
	float height;
	float t;
	float EasedT;
	float EasedX;
	float EasedX1;
	float EasedX2;
	unsigned int color;
	bool isEase;
	bool TransLate;
}Box;