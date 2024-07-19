#pragma once
#include "fComponent.h"

namespace f
{
	struct Pos
	{
		int mX;
		int mY;
	};

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPos(int x, int y) { mPos.mX = x; mPos.mY = y; }
		int GetX() { return mPos.mX; }
		int GetY() { return mPos.mY; }
	private:
		Pos mPos;
	};
}

