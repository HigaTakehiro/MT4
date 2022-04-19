#include "GameScene.h"

GameScene::GameScene() {

}

GameScene::~GameScene() {
	safe_delete(sprite);
	safe_delete(sphereModel);
	safe_delete(sphere);
	safe_delete(ground);
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio) {
	assert(dxCommon);
	assert(input);
	assert(audio);

	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;

	//�J����������
	camera = new Camera;
	camera->SetEye(XMFLOAT3(0, 200, -800));

	//Sprite & DebugText�̏�����
	Sprite::StaticInitialize(dxCommon->GetDev(), WinApp::window_width, WinApp::window_height);

	Sprite::LoadTexture(debugTextNumber, L"Resources/debugfont.png");
	debugText.Initialize(debugTextNumber);

	Sprite::LoadTexture(1, L"Resources/house.png");
	sprite = Sprite::Create(1, { 0, 0 });

	//Object3d�̏�����
	Object3d::StaticInitialize(dxCommon->GetDev(), WinApp::window_width, WinApp::window_height);

	sphereModel = Model::CreateModel("Sphere");
	groundModel = Model::CreateModel("Ground");
	skyModel = Model::CreateModel("Sky");
	ground = Object3d::Create(groundModel);
	ground->SetScale({ 50, 0, 50 });
	sky = Object3d::Create(skyModel);
	sky->SetScale({ 500, 500, 500 });
	sphere = Object3d::Create(sphereModel);
	sphereScale = { 15, 15, 15 };
	spherePos = initPos;
	sphereRot = { 0, 180, 0 };
	sphere->SetScale(sphereScale);
	sphere->SetPosition(spherePos);
	sphere->SetRotation(sphereRot);

	//MapChip�̏�����
	/*mapchip = new MapChip;
	mapchip->MapChipInitialize();*/

}

void GameScene::Update() {
	// DirectX���t���[�������@��������
	camera->SetTarget(spherePos);

	//�f�o�b�O�e�L�X�g
	if (input->PushKey(DIK_SPACE)) {
		spherePos = initPos;
		time = 0.0f;
	}

	if (spherePos.y >= 15) {
		time += 0.1f; 
		spherePos.y -= fallSpeed * time * time / 2.0f;
	}
	else {
		spherePos.y = 14.0f;
		time = 0.0f;
	}

	input->Update();
	sphere->SetPosition(spherePos);
	sphere->Update();
	ground->Update();
	sky->Update();
}

void GameScene::Draw() {
	dxCommon->PreDraw(color);

	//�X�v���C�g�`�揈��(�w�i)

	//3D�I�u�W�F�N�g�`�揈��
	Object3d::PreDraw(dxCommon->GetCmdList());
	sphere->Draw();
	ground->Draw();
	sky->Draw();
	Object3d::PostDraw();

	//�X�v���C�g�`�揈��(UI��)
	Sprite::PreDraw(dxCommon->GetCmdList());
	//sprite->Draw();
	debugText.DrawAll(dxCommon->GetCmdList());
	Sprite::PostDraw();

	// �S�D�`��R�}���h�����܂�
	dxCommon->PostDraw();
}

void GameScene::Finalize() {
	safe_delete(camera);
}