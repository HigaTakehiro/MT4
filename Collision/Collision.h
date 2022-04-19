#pragma once
#include "Primitive.h"
#include <DirectXMath.h>

class Collision
{
private: //エイリアス
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public: //メンバ関数
	static bool testSphereSphere(const Sphere& sphere1, const Sphere& sphere2);

	static bool testSphereBox(const Sphere& sphere, const Box& box);
};

