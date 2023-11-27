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
#include <KeyAcquisition.h>
#include <DoorC.h>

const char kWindowTitle[] = "5242_ワープレイヤー";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int TitleHandle = Novice::LoadTexture("./Resources/images/TitleSprite.png");
	int WorpHandle = Novice::LoadTexture("./Resources/images/Worp.png");
	int LetterHandle = Novice::LoadTexture("./Resources/images/TitleLetter.png");
	int GameExplain = Novice::LoadTexture("./Resources/images/GameExplain.png");
	int GameHandle = Novice::LoadTexture("./Resources/images/bg.png");

	int PlayerHandle[2];
	PlayerHandle[0] = Novice::LoadTexture("./Resources/images/Player.png");
	PlayerHandle[1] = Novice::LoadTexture("./Resources/images/Player1.png");

	int keyHandle = Novice::LoadTexture("./Resources/images/key.png");

	int DoorHandle[2];
	DoorHandle[0] = Novice::LoadTexture("./Resources/images/ClearDoor.png");
	DoorHandle[1] = Novice::LoadTexture("./Resources/images/ClearDoor1.png");

	int ClearHandle = Novice::LoadTexture("./Resources/images/ClearBackGround.png");
	int ClearLetter = Novice::LoadTexture("./Resources/images/ClearLetter.png");

	int TextureHandle = Novice::LoadTexture("./Resources/images/particle.png");

	enum TeamCriate {
		TITLE,
		GAMEEXPLAIN,
		GAME,
		GAMECLEAR,
	};

	TeamCriate Scene = TITLE;
	Player player = { 
		{600.0f,800.0f},
		{0.0f,-0.8f},
		{0.0f,-0.8f},
		{0.0f,0.0f},
		7.0f,32.0f,
		0.0f,
		RED,false,
		false
	};

	Box box = {
		{600.0f,0.0f},
		16.0f,
		WHITE
	};
	Box box2 = {
		{600.0f,0.0f},
		16.0f,
		WHITE
	};

	DoesNotExistBG* bg = new DoesNotExistBG();
	bg->position_.x = 0;
	bg->position_.y = 0;

	Kagi kagi = {
		{200.0f,500.0f},
		16.0f,
		WHITE,
		false,
	};
	Kagi kagi2 = {
		{1080.0f,500.0f},
		16.0f,
		WHITE,
		false
	};

	Door door = {
		{800.0f,5.0f},
		16.0f,
		WHITE
	};

	Vector2 ScreenPlayerPosition = {};
	Vector2 ScreenBoxPosition = {};
	Vector2 Screenkey = {};
	Vector2 Screenkey2 = {};
	Vector2 ScreenDoor = {};

	int istranslate[1];
	istranslate[0] = 0;

	float playerLeftX = (player.position.x - player.radius);
	float playerRightX = (player.position.x + player.radius);

	float BoxLeftX = (box.position.x - box.radius);
	float BoxRightX = (box.position.x + box.radius);

	float BoxLeftX2 = (box2.position.x - box2.radius);
	float BoxRightX2 = (box2.position.x + box2.radius);

	float keyLeftX = (kagi.position.x - kagi.radius);
	float keyRightX = (kagi.position.x - kagi.radius);

	float keyLeftX2 = (kagi2.position.x - kagi2.radius);
	float keyRightX2 = (kagi2.position.x - kagi2.radius);

	float DoorLeftX = (door.position.x - door.radius);
	float DoorRightX = (door.position.x - door.radius);

	int count = 0;

	float EaseInX = 0.0f;
	float EaseInY = 0.0f;
	float width = 1280.0f;
	float height = 0.0f;

	float Width2 = 0.0f;

	bool SpriteChange = false;
	bool SpriteChange2 = false;

	float posX = 0.0f;
	float start = -300.0f;
	float end = 0.0f;
	float Frame = 0.0f;
	float EndFrame = 75.0f;
	bool isExpo = true;

	float PosY = 0.0f;
	float Start2 = 0.0f;//開始位置
	float End2 = 500.0f;//終了位置
	float Frame2 = 0.0f;//現在の時間
	float EndFrame2 = 140.0f;//全体の時間、ゴールに到達するまでの時間

	float posX2 = 0.0f;
	float Start3 = 0.0f;//開始位置
	float End3 = 1500.0f;//終了位置
	float Frame3 = 0.0f;//現在の時間
	float EndFrame3 = 140.0f;//全体の時間、ゴールに到達するまでの時間
	bool isQuad = false;

	bool easeIn = false;

	int Direction = 1;

	int DoorChange = 0;

	//==================================================<クリア時に使うパーティクルの宣言と初期化>==========================================
	int positionX = 640;
	int positionY = 320;
	float RandX = 0;
	float RandY = 0;

	float Radius = 40;

	const int max = 300;
	Particle particle[max];
	for (int i = 0; i < max; i++) {
		particle[i].position.x = 0;
		particle[i].position.y = 0.0f;
		particle[i].speed = rand() % 6 - 0.5f;
		particle[i].color = 0xFFFFFF80;
		particle[i].isMove = false;
	}

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

			if (isExpo == true) {
				Frame++;
			}

			if (Frame >= EndFrame) {
				isExpo = false;
			}

			posX = start + (end - start) * EaseInExpo(Frame / EndFrame);

			//ゲーム画面に行く処理
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == false) {
				easeIn = true;
				Frame2 = 0.0f;
			}

			if (easeIn == true) {
				Frame2++;
			}

			if (Frame2 == EndFrame2) {
				easeIn = false;
				SpriteChange = false;
				Frame2 = 0.0f;
				Scene = GAMEEXPLAIN;
			}

			PosY = Start2 + (End2 - Start2) * EaseIn(Frame2 / EndFrame2);

			if (height + PosY >= 720) {
				SpriteChange = true;
			}

			break;

		case GAMEEXPLAIN:

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == false) {
				isQuad = true;
				Frame3 = 0.0f;
			}

			if (isQuad == true) {
				Frame3++;
			}


			if (Frame3 == EndFrame3) {
				isQuad = false;
				Frame3 = 0.0f;
				Scene = GAME;
			}

			posX2 = Start3 + (End3 - Start3) * EaseIn2(Frame3 / EndFrame3);

			if (Width2 + posX2 >= 1400) {
				SpriteChange2 = true;
			}

			break;

		case GAME:

			PlayerMove(&player, keys, playerLeftX, playerRightX,Direction);
			PlayerJump(&player, keys, preKeys);
			PlayerShake(&player, istranslate);
			PlayerShake2(&player, istranslate);

			PlayerTranslate(&player, istranslate);
			PlayerTranslate2(&player, istranslate);
			PlayerTranslate3(&player, istranslate);
			PlayerTranslate4(&player, istranslate);

			KeyAcquisition(&kagi,playerLeftX, playerRightX, keyLeftX, keyRightX, istranslate);
			KeyAcquisition2(&kagi2,playerLeftX, playerRightX, keyLeftX2, keyRightX2, istranslate);

			DoorC(&kagi, &kagi2, playerLeftX, playerRightX, DoorLeftX, DoorRightX, keys, preKeys, istranslate, DoorChange);

			BGTranslate(&box, playerLeftX, playerRightX, BoxLeftX, BoxRightX, keys, preKeys, istranslate, count);
			BGTranslate2(&box, playerLeftX, playerRightX, BoxLeftX, BoxRightX, keys, preKeys, istranslate, count);

			BGTranslate3(&box2, playerLeftX, playerRightX, BoxLeftX2, BoxRightX2, keys, preKeys, istranslate);

			ReturnCount(count, istranslate);

			ScreenPlayerPosition = ToScreen(player.position);
			ScreenBoxPosition = ToScreen(box.position);

			ScreenDoor = ToScreen(door.position);

			if (istranslate[0] == 0 && DoorChange == 1) {
				if (player.position.x >= 803) {
					Scene = GAMECLEAR;
				}
			}

			break;

		case GAMECLEAR:

			//画像のシェイク

			RandX = rand() % 15 - 7.0f;
			RandY = rand() % 15 - 7.0f;

			for (int i = 0; i < max; i++) {
				if (particle[i].isMove == false) {
					particle[i].isMove = true;
					particle[i].position.x = (positionX - Radius) + RandX;
					particle[i].position.y = (positionY - Radius) + RandY;
					break;
				}
			}

			for (int i = 0; i < max; i++) {
				if (particle[i].isMove == true) {
					particle[i].position.x += particle[i].speed * cosf(i * float(M_PI) / 10.0f);
					particle[i].position.y += particle[i].speed * sinf(i * float(M_PI) / 10.0f);

					particle[i].color -= 0x00000001;

					if (particle[i].color <= 0xFFFFFF00) {
						particle[i].color -= 0xFFFFFF80;
						particle[i].isMove = false;
					}
				}
			}

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

			Novice::DrawSprite(0, (int)posX, LetterHandle, 1, 1, 0.0f, WHITE);

			if (SpriteChange == true) {
				Novice::DrawSprite(0, 0, GameExplain, 1, 1, 0.0f, WHITE);
			}

			Novice::DrawBox((int)EaseInX, (int)EaseInY, (int)width, (int)height + (int)PosY, 0.0f, BLACK, kFillModeSolid);

			break;

		case GAMEEXPLAIN:

			if (SpriteChange2 == false) {
				Novice::DrawSprite(0, 0, GameExplain, 1, 1, 0.0f, WHITE);
			}

			if (SpriteChange2 == true) {
				Novice::DrawSprite(0, 0, GameHandle, 1, 1, 0.0f, WHITE);

				Novice::DrawSprite((int)door.position.x, (int)ScreenDoor.y + 495, DoorHandle[0], 1, 1, 0.0f, WHITE);
			}

			Novice::DrawBox(0, 0, (int)Width2 + (int)posX2, 720, 0.0f, BLACK, kFillModeSolid);

			break;

		case GAME:

			Translate(istranslate);

			if (istranslate[0] == 0 && DoorChange == 0) {
				Novice::DrawSprite((int)door.position.x, (int)ScreenDoor.y, DoorHandle[0], 1, 1, 0.0f, WHITE);
			}

			if (istranslate[0] == 0 && DoorChange == 1) {
				Novice::DrawSprite((int)door.position.x, (int)ScreenDoor.y, DoorHandle[1], 1, 1, 0.0f, WHITE);
			}

			if (istranslate[0] == 1 || istranslate[0] == 2 || istranslate[0] == 4 || istranslate[0] == 7) {
				Novice::DrawSprite((int)box.position.x - (int)box.radius, (int)ScreenBoxPosition.y + 25, WorpHandle, 1, 1, 0.0f, (int)box.color);
			}

			bg->Draw(istranslate);

			if (istranslate[0] == 33) {
				Novice::DrawSprite((int)box2.position.x - (int)box2.radius, (int)ScreenBoxPosition.y + 25, WorpHandle, 1, 1, 0.0f, (int)box2.color);
			}

			if (istranslate[0] == 3) {
				Novice::DrawSprite((int)kagi.position.x, (int)kagi.position.y, keyHandle, 1, 1, 0.0f, kagi.color);
			}

			if (istranslate[0] == 8) {
				Novice::DrawSprite((int)kagi2.position.x, (int)kagi2.position.y, keyHandle, 1, 1, 0.0f, kagi2.color);
			}

			if (kagi.Acquisition == true) {
				Novice::DrawSprite((int)kagi.position.x, (int)kagi.position.y, keyHandle, 1, 1, 0.0f, kagi.color);
			}

			if (kagi2.Acquisition == true) {
				Novice::DrawSprite((int)kagi2.position.x, (int)kagi2.position.y, keyHandle, 1, 1, 0.0f, kagi2.color);
			}

			if (Direction == 1) {
				Novice::DrawSprite(((int)player.position.x - (int)player.radius) + (int)player.rand.x,
					(int)ScreenPlayerPosition.y + (int)player.rand.y, PlayerHandle[0], 1, 1, 0.0f, WHITE);
			}

			if (Direction == 2) {
				Novice::DrawSprite(((int)player.position.x + (int)player.rand.x) - (int)player.radius, (int)ScreenPlayerPosition.y + (int)player.rand.y,
					PlayerHandle[1], 1, 1, 0.0f, WHITE);
			}

			break;

		case GAMECLEAR:

			Novice::DrawSprite(0, 0, ClearHandle, 1, 1, 0.0f, WHITE);

			Novice::DrawSprite((positionX - (int)Radius) + (int)RandX, (positionY - (int)Radius) + (int)RandY, TextureHandle, 1, 1, 0.0f, WHITE);

			for (int i = 0; i < max; i++) {
				if (particle[i].isMove == true) {
					Novice::DrawSprite((int)particle[i].position.x, (int)particle[i].position.y, TextureHandle, 1, 1, 0.0f, particle[i].color);
				}
			}

			Novice::DrawSprite(0, 0, ClearLetter, 1, 1, 0.0f, WHITE);

			break;
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
