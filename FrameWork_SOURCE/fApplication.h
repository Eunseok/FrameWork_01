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

		const HDC GetHdc() { return mHdc; }
		
	private:
		void getGetClientRect();
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void CreateSizedBitmap(HWND hwnd, int width, int height);
	private:
		HWND mHwnd;
		HDC mHdc;

		HDC hMemDC;
		HBITMAP hBitmap;

		UINT mWidth;
		UINT mHeight;		
	};
}
 