#pragma once
#include "Commoninclude.h"
#include "fGameObject.h"

namespace f
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mPlayer;
	};
}
 