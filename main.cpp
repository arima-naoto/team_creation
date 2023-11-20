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

const char kWindowTitle[] = "チーム制作";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int WorpHandle = Novice::LoadTexture("./Resources/images/Worp.png");

	Player player = { 
		{640.0f,0.0f},
		{0.0f,-0.8f},
		{0.0f,-0.8f},
		{0.0f,0.0f},
		7.0f,32.0f,
		0.0f,
		WHITE,false,
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

		PlayerMove(&player, keys, playerLeftX, playerRightX);
		PlayerJump(&player, keys,preKeys);
		PlayerShake(&player, istranslate);

		PlayerTranslate(&player, istranslate);
		PlayerTranslate2(&player, istranslate);
		PlayerTranslate3(&player, istranslate);

		BGTranslate(&box, playerLeftX, playerRightX, BoxLeftX, BoxRightX,keys,preKeys,istranslate,count);
		BGTranslate2(&box, playerLeftX, playerRightX, BoxLeftX, BoxRightX,keys,preKeys,istranslate,count);

		Vector2 ScreenPlayerPosition = ToScreen(player.position);

		Vector2 ScreenBoxPosition = ToScreen(box.position);

		///
		/// ↑更新処理ここまで
		///
		 
		///
		/// ↓描画処理ここから
		///

		Translate(istranslate);

		if (istranslate[0] == 1 || istranslate[0] == 2 || istranslate[0] == 4 || istranslate[0] == 7) {
			Novice::DrawSprite((int)box.position.x - (int)box.radius, (int)ScreenBoxPosition.y - 65, WorpHandle, 1, 1, 0.0f, (int)box.color);
		}

		bg->Draw(count);

		Novice::DrawEllipse((int)player.position.x + (int)player.rand.x, (int)ScreenPlayerPosition.y + (int)player.rand.y, 
			(int)player.radius, (int)player.radius, 0.0f, player.color, kFillModeSolid);


		Novice::ScreenPrintf(0, 0, "isTranslate[0] = %d", istranslate[0]);
		Novice::ScreenPrintf(0, 20, "count = %d", count);

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
