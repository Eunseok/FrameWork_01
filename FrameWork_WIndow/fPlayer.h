#pragma once
#include "../FrameWork_SOURCE/fGameObject.h"

namespace f
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}

