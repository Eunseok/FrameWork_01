#pragma once
#include "fEntity.h"
#include "Commoninclude.h"
#include "fGameObject.h"

namespace f
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer(); 

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);
	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObject;
	};
}

