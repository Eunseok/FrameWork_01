#pragma once
#include "Commoninclude.h"
#include "fComponent.h"

namespace f {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			mComponents.push_back(comp);

			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}




		/*float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }*/
	private:
		////게임오브젝트의 좌표
		//float mX;
		//float mY;
		std::vector<Component*> mComponents;
	};
}

