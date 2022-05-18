#include "GameScene.h"

GameScene::GameScene() {

}

GameScene::~GameScene() {
	safe_delete(sprite);
	safe_delete(sphereModel);
	safe_delete(sphere);
	safe_delete(sphere2);
	safe_delete(ground);
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio) {
	assert(dxCommon);
	assert(input);
	assert(audio);

	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;

	//カメラ初期化
	camera = new Camera;
	camera->SetEye(XMFLOAT3(0, 200, -800));

	//Sprite & DebugTextの初期化
	Sprite::StaticInitialize(dxCommon->GetDev(), WinApp::window_width, WinApp::window_height);

	Sprite::LoadTexture(debugTextNumber, L"Resources/debugfont.png");
	debugText.Initialize(debugTextNumber);

	Sprite::LoadTexture(1, L"Resources/house.png");
	sprite = Sprite::Create(1, { 0, 0 });

	//Object3dの初期化
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
	spherePos2 = initPos2;
	sphere2 = Object3d::Create(sphereModel);
	sphere2->SetScale(sphereScale);
	sphere2->SetPosition(spherePos2);
	sphere2->SetRotation(sphereRot);

	//sphereSpeed = 10.0f;

	//MapChipの初期化
	/*mapchip = new MapChip;
	mapchip->MapChipInitialize();*/

}

void GameScene::Update() {
	// DirectX毎フレーム処理　ここから
	camera->SetTarget(XMFLOAT3(0, 0, 0));

	if (input->PushKey(DIK_SPACE)) {
		spherePos = initPos;
		spherePos2 = initPos2;
		time = 0.0f;
	}

	time += 0.1f;

	input->Update();
	sphere->SetPosition(spherePos);
	sphere->Update();
	sphere2->SetPosition(spherePos2);
	sphere2->Update();
	ground->Update();
	sky->Update();
}

void GameScene::Draw() {
	dxCommon->PreDraw(color);

	//スプライト描画処理(背景)

	//3Dオブジェクト描画処理
	Object3d::PreDraw(dxCommon->GetCmdList());
	sphere->Draw();
	sphere2->Draw();
	ground->Draw();
	sky->Draw();
	Object3d::PostDraw();

	//スプライト描画処理(UI等)
	Sprite::PreDraw(dxCommon->GetCmdList());
	//sprite->Draw();
	debugText.DrawAll(dxCommon->GetCmdList());
	Sprite::PostDraw();

	// ４．描画コマンドここまで
	dxCommon->PostDraw();
}

void GameScene::Finalize() {
	safe_delete(camera);
}