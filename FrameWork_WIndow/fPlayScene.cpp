#include "fPlayScene.h"
#include "fGameObject.h"
#include "fPlayer.h"
#include "fTransform.h"
#include "fSpriteRenderer.h"
#include "fInput.h"
#include "fTitleScene.h"
#include "fSceneManager.h"
#include "fObject.h"
#include "fTexture.h"
#include "fResources.h"

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
		//게임오브젝트 만들기 전에 리소스들 전무 LOAD해두면 좋다.
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BG");
		sr->SetTexture(bg);
		
		//sr->ImageLoad(L"C:\\Users\\asp67\\source\\repos\\FrameWork_01\\Resources\\CloudOcean.png");
		//graphics::Texture* tex = new graphics::Texture();
		//tex->Load(L"C:\\Users\\asp67\\source\\repos\\FrameWork_01\\Resources\\CloudOcean.png");
		 
		Scene::Initialize();
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
