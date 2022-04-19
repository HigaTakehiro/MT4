#pragma once
#include <DirectXMath.h>

struct Sphere
{
	DirectX::XMFLOAT3 position;
	float radius;
};

struct Box {
	DirectX::XMFLOAT3 minPosition;
	DirectX::XMFLOAT3 maxPosition;
};

struct Capsule {
	DirectX::XMFLOAT3 startPosition;
	DirectX::XMFLOAT3 endPosition;
	float radius;
};