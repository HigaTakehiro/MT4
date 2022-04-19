#pragma once
#include <DirectXMath.h>

class Physics
{
private: //エイリアス
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

private: //定数
	const float gravity = 9.8f;

public: //メンバ関数
	/// <summary>
	/// 重力処理
	/// </summary>
	/// <param name="pos">重力を掛ける対象</param>
	void Gravity(XMFLOAT3* pos);

private: //メンバ変数
	float time = 0.0f;
	XMFLOAT3 fallPos = { 0.0f, 0.0f, 0.0f };
};

