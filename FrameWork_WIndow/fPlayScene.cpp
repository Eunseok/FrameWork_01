#include "fPlayScene.h"
#include "fGameObject.h"
#include "fPlayer.h"
#include "fTransform.h"
#include "fSpriteRenderer.h"
#include "fInput.h"
#include "fTitleScene.h"
#include "fSceneManager.h"
#include "fObject.h"

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

		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround, Vector2(10, 10));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\asp67\\source\\repos\\FrameWork_01\\Resources\\CloudOcean.png");
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
	}
}
