#pragma once
#include "Primitive.h"
#include <DirectXMath.h>

class Collision
{
private: //�G�C���A�X
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public: //�����o�֐�
	static bool testSphereSphere(const Sphere& sphere1, const Sphere& sphere2);

	static bool testSphereBox(const Sphere& sphere, const Box& box);
};

