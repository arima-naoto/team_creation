#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <Mytypedef.h>
#include <Player.h>
#include <ToScreen.h>
#include <BackGroundDraw.h>
#include <BGTranslate.h>
#include <translate.h>
#include <DoesNotExistBG.h>
#include <EaseIn.h>
#include <Count.h>

const char kWindowTitle[] = "チーム制作";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int TitleHandle = Novice::LoadTexture("./Resources/images/TitleSprite.png");
	int WorpHandle = Novice::LoadTexture("./Resources/images/Worp.png");

	int TitleBackGround = Novice::LoadTexture("./Resources/images/bg.png");

	enum TeamCriate {
		TITLE,
		GAME,
	};

	TeamCriate Scene = TITLE;

	Player player = { 
		{640.0f,800.0f},
		{0.0f,-0.8f},
		{0.0f,-0.8f},
		{0.0f,0.0f},
		7.0f,32.0f,
		0.0f,
		RED,false,
		false
	};

	Box box = {
		{640.0f,0.0f},
		32.0f,
		WHITE
	};

	DoesNotExistBG* bg = new DoesNotExistBG();
	bg->position_.x = 0;
	bg->position_.y = 0;

	int istranslate[1];
	istranslate[0] = 0;

	float playerLeftX = (player.position.x - player.radius);
	float playerRightX = (player.position.x + player.radius);

	float BoxLeftX = (box.position.x - box.radius);
	float BoxRightX = (box.position.x + box.radius);

	int count = 0;

	Vector2 ScreenPlayerPosition = {};

	Vector2 ScreenBoxPosition = {};

	float EaseInX = 0.0f;
	float EaseInY = 0.0f;
	float width = 1280.0f;
	float height = 0.0f;
	bool easeIn = false;
	float x = 0.0f;

	float PosY = 0.0f;
	float Start = 0.0f;//開始位置
	float End = 550.0f;//終了位置
	float Frame = 0.0f;//現在の時間
	float EndFrame = 140.0f;//全体の時間、ゴールに到達するまでの時間

	bool SpriteChange = false;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (Scene) {

		case TITLE:

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == false) {
				easeIn = true;
				Frame = 0.0f;
			}

			if (easeIn == true) {
				Frame++;
			}

			if (Frame == EndFrame) {
				easeIn = false;
				Scene = GAME;
			}

			x = Frame / EndFrame;
			PosY = Start + (End - Start) * EaseIn(x);

			if (height + PosY >= 830) {
				SpriteChange = true;
			}

			break;

		case GAME:

			PlayerMove(&player, keys, playerLeftX, playerRightX);
			PlayerJump(&player, keys, preKeys);
			PlayerShake(&player, istranslate);

			PlayerTranslate(&player, istranslate);
			PlayerTranslate2(&player, istranslate);
			PlayerTranslate3(&player, istranslate);
			PlayerTranslate4(&player, istranslate);

			BGTranslate(&box, playerLeftX, playerRightX, BoxLeftX, BoxRightX, keys, preKeys, istranslate, count);
			BGTranslate2(&box, playerLeftX, playerRightX, BoxLeftX, BoxRightX, keys, preKeys, istranslate, count);

			ReturnCount(count, istranslate);

			ScreenPlayerPosition = ToScreen(player.position);
			ScreenBoxPosition = ToScreen(box.position);

			break;
		}

		///
		/// ↑更新処理ここまで
		///
		 
		///
		/// ↓描画処理ここから
		///


		switch (Scene) {

		case TITLE:

			if (SpriteChange == false) {
				Novice::DrawSprite(0, 0, TitleHandle, 1, 1, 0.0f, WHITE);
			}

			if (SpriteChange == true) {
				Novice::DrawSprite(0, 0, TitleBackGround, 1, 1, 0.0f, WHITE);
			}
			

			Novice::DrawBox((int)EaseInX, (int)EaseInY, (int)width, (int)height + (int)PosY, 0.0f, BLACK, kFillModeSolid);

			break;

		case GAME:

			Translate(istranslate);

			if (istranslate[0] == 1 || istranslate[0] == 2 || istranslate[0] == 4 || istranslate[0] == 7) {
				Novice::DrawSprite((int)box.position.x - (int)box.radius, (int)ScreenBoxPosition.y + 25, WorpHandle, 1, 1, 0.0f, (int)box.color);
			}

			bg->Draw(istranslate);

			Novice::DrawEllipse((int)player.position.x + (int)player.rand.x, (int)ScreenPlayerPosition.y + (int)player.rand.y + 90,
				(int)player.radius, (int)player.radius, 0.0f, player.color, kFillModeSolid);


			Novice::ScreenPrintf(0, 0, "isTranslate[0] = %d", istranslate[0]);
			Novice::ScreenPrintf(0, 20, "count = %d", count);
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
