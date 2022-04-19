#pragma once
#include "Input.h"
#include "DirectXCommon.h"
#include "Object3d.h"
#include "Model.h"
#include "Sprite.h"
#include "DebugText.h"
#include "Audio.h"
#include "Camera.h"
#include "MapChip.h"
#include "SafeDelete.h"

using namespace DirectX;
using namespace Microsoft::WRL;

class GameScene
{
private: //�ÓI�����o�ϐ�
	//�f�o�b�N�e�L�X�g�p�e�N�X�`���ԍ�
	static const int debugTextNumber = 0;

public: //�����o�֐�
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GameScene();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~GameScene();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �I������
	/// </summary>
	void Finalize();

private: //�����o�ϐ�
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	WinApp* winApp = nullptr;
	DebugText debugText;
	Audio* audio = nullptr;
	Camera* camera = nullptr;
	MapChip* mapchip = nullptr;

	//�Q�[���I�u�W�F�N�g & �X�v���C�g
	Model* groundModel = nullptr;
	Model* skyModel = nullptr;
	Model* sphereModel = nullptr;
	Object3d* ground = nullptr;
	Object3d* sky = nullptr;
	Object3d* sphere = nullptr;
	Sprite* sprite = nullptr;

	//�}�b�v�`�b�v�p�ϐ�
	//int** map1_a = nullptr;
	//int** map1_b = nullptr;
	//std::vector<Object3d*> objects;
	//std::vector<Object3d*> objects2;

	//�Q�[���V�[���p�ϐ�
	XMFLOAT3 spherePos = { 0, 0, 0 };
	XMFLOAT3 sphereScale = { 0, 0, 0 };
	XMFLOAT3 sphereRot = { 0, 0, 0 };

	const XMFLOAT3 initPos = { 0, 1000, 0 };
	const float fallSpeed = 9.8f;
	float time = 0.0f;

	XMFLOAT4 color = { 0.1f,0.25f, 0.5f,0.0f };
};

