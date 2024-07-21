#include "fPlayScene.h"
#include "fGameObject.h"
#include "fPlayer.h"
#include "fTransform.h"
#include "fSpriteRenderer.h"
#include "fInput.h"
#include "fTitleScene.h"
#include "fSceneManager.h"

namespace f
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		bg = new Player();

		Transform* tr
			= bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\asp67\\source\\repos\\FrameWork_01\\Resources\\CloudOcean.png");

		AddGameObject(bg, eLayerType::BackGround);
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N))
			SceneManager::LoadScene(L"TitleScene");
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{

	}
	void PlayScene::OnExit()
	{
		Transform* tr
			= bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
	}
}
