#include <Novice.h>
#define _USE_MATH_DEFINES
#include<math.h>

const char kWindowTitle[] = "学籍番号";

struct Vector3 {
	float x, y, z;
};

Vector3 v1a{ 1.0f,3.0f,-5.0f };
Vector3 v2a{ 4.0f,-1.0f,2.0f };
float scalar1 = { 4.0f };


Vector3 Add(const Vector3& v1, const Vector3& v2)
{
	Vector3 Answer;
	Answer.x = v1.x + v2.x;
	Answer.y = v1.y + v2.y;
	Answer.z = v1.z + v2.z;

	return Answer;
}

Vector3 Subtract(const Vector3& v1, const Vector3& v2)
{
	Vector3 Answer;
	Answer.x = v1.x - v2.x;
	Answer.y = v1.y - v2.y;
	Answer.z = v1.z - v2.z;
	return Answer;
}

Vector3 Multiply(float scalar, const Vector3& v)
{
	Vector3 Answer;
	Answer.x = scalar * v.x;
	Answer.y = scalar * v.y;
	Answer.z = scalar * v.z;
	return Answer;
}

float Dot(const Vector3& v1, const Vector3& v2)
{
	float Answer;
	Answer = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return Answer;
}

float Length(const Vector3& v)
{
	float length;
	length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	return length;
}

float resultLength = Length(v1a);

Vector3 Normalize(const Vector3& v)
{
	Vector3 normalize;
	normalize.x = 1 / resultLength;
	normalize.x *= v.x;
	normalize.y = 1 / resultLength;
	normalize.y *= v.y;
	normalize.z = 1 / resultLength;
	normalize.z *= v.z;
	return normalize;
}

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2);

//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v);

//内積
float Dot(const Vector3& v1, const Vector3& v2);

//長さ（ノルム）
float Length(const Vector3& v);

//正規化
Vector3 Normalize(const Vector3& v);

Vector3 resultAdd = Add(v1a, v2a);
Vector3 resultSubtract = Subtract(v1a, v2a);
Vector3 resultMultiply = Multiply(scalar1, v1a);
float resultDot = Dot(v1a, v2a);

Vector3 resultNormalize = Normalize(v2a);

static const int kRowHeight = 20;
static const int kColumWidth = 60;

static void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumWidth * 3, y, "%s", label);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

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

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

	

		VectorScreenPrintf(0, 0, resultAdd, " : Add");
		VectorScreenPrintf(0, kRowHeight, resultSubtract, " : Subtract");
		VectorScreenPrintf(0, kRowHeight * 2, resultMultiply, " : Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f : Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f : Length", resultLength);
		VectorScreenPrintf(0, kRowHeight * 5, resultNormalize, " : Normalize");

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

