#pragma once
#include <DirectXMath.h>

class Camera
{
private: //�G�C���A�X
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;


public: //�T�u�N���X
	// �萔�o�b�t�@�p�f�[�^�\����
	struct ConstBufferDataB0
	{
		XMMATRIX mat;	// �R�c�ϊ��s��
	};

public: //�ÓI�����o�֐�
	/// <summary>
	/// �J����������
	/// </summary>
	/// <param name="window_width">��ʉ���</param>
	/// <param name="window_height">��ʏc��</param>
	static void InitializeCamera(int window_width, int window_height);

	/// <summary>
	/// �r���[�s����X�V
	/// </summary>
	static void UpdateViewMatrix();

	/// <summary>
	/// ���_���W�̎擾
	/// </summary>
	/// <returns>���W</returns>
	static const XMFLOAT3& GetEye() { return eye; }

	/// <summary>
	/// ���_���W�̐ݒ�
	/// </summary>
	/// <param name="position">���W</param>
	static void SetEye(XMFLOAT3 eye);

	/// <summary>
	/// �����_���W�̎擾
	/// </summary>
	/// <returns>���W</returns>
	static const XMFLOAT3& GetTarget() { return target; }

	/// <summary>
	/// �����_���W�̐ݒ�
	/// </summary>
	/// <param name="position">���W</param>
	static void SetTarget(XMFLOAT3 target);

	/// <summary>
	/// �x�N�g���ɂ��ړ�
	/// </summary>
	/// <param name="move">�ړ���</param>
	static void CameraMoveVector(XMFLOAT3 move);
	static void CameraMoveEyeVector(XMFLOAT3 move);

public: //�����o�֐�
	XMMATRIX MartixMix(XMMATRIX matWorld) { return matWorld * matView * matProjection; }

private: //�ÓI�����o�ϐ�
	// �r���[�s��
	static XMMATRIX matView;
	// �ˉe�s��
	static XMMATRIX matProjection;
	// ���_���W
	static XMFLOAT3 eye;
	// �����_���W
	static XMFLOAT3 target;
	// ������x�N�g��
	static XMFLOAT3 up;
};

