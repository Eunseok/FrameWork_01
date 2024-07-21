#include "fScene.h"


namespace f
{
	Scene::Scene()
		:mLayers{}
	{
		createLayers();
	}
	Scene::~Scene()
	{
	}

	void Scene::createLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (!layer)
				continue;
			layer->Initialize();
		}
	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (!layer)
				continue;
			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (!layer)
				continue;
			layer->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			if (!layer)
				continue;
			layer->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObj,const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

	void Scene::OnEnter()
	{

	}
	void Scene::OnExit()
	{

	}
}