#pragma once
#include <DirectXMath.h>

class Physics
{
private: //�G�C���A�X
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

private: //�萔
	const float gravity = 9.8f;

public: //�����o�֐�
	/// <summary>
	/// �d�͏���
	/// </summary>
	/// <param name="pos">�d�͂��|����Ώ�</param>
	void Gravity(XMFLOAT3* pos);

private: //�����o�ϐ�
	float time = 0.0f;
	XMFLOAT3 fallPos = { 0.0f, 0.0f, 0.0f };
};

