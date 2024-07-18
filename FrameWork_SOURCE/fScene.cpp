#include "fScene.h"


namespace f
{
	Scene::Scene()
		:mGameObject{}
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{

	}
	void Scene::Update()
	{
		for (GameObject* gameObj : mGameObject)
		{
			gameObj->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGameObject)
		{
			gameObj->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObject)
		{
			gameObj->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObject.push_back(gameObject);
	}
}