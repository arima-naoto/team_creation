#include <Novice.h>
#include "Mytypedef.h"
#include "Player.h"
#include "PlayerMove.h"
#include "ToScreen.h"
#include "BackGroundDraw.h"

const char kWindowTitle[] = "チーム制作";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player player = { 
		{640.0f,0.0f},
		{0.0f,-0.8f},
		{0.0f,-0.8f},
		5.0f,32.0f,
		WHITE,false,
		false
	};

	int istranslate[40];
	istranslate[0] = 0;

	/*int LeftPosX;
	int RightPosX;
	int TopPosY;
	int BottomPosY;*/

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

		PlayerMove(&player, keys);

		PlayerJump(&player, keys,preKeys);

		PlayerTranslate(&player, istranslate);

		Vector2 ScreenPlayerPosition = ToScreen(player.position);

		///
		/// ↑更新処理ここまで
		///
		 
		///
		/// ↓描画処理ここから
		///

		Translate(istranslate);

		Novice::DrawEllipse((int)player.position.x, (int)ScreenPlayerPosition.y, (int)player.radius, (int)player.radius, 0.0f, player.color, kFillModeSolid);

		Novice::ScreenPrintf(0, 0, "istranslate[0] = %d", istranslate[0]);

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
