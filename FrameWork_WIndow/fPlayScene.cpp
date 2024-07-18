#include "fPlayScene.h"
#include "fGameObject.h"


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
		for (size_t i = 0; i < 100; i++)
		{
			GameObject* objc = new GameObject();
			objc->SetPosition(rand() % 1600, rand() % 900);
			Scene::AddGameObject(objc);
		}
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc) 
	{
		Scene::Render(hdc);
	}
}
