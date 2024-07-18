#include "fApplication.h"
#include "fInput.h"
#include "fTime.h"
#include "fSceneManager.h"

namespace f
{
    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        , mWidth(0)
        , mHeight(0)
        , hMemDC(nullptr)
        , hBitmap(nullptr)
    {
    }

    Application::~Application() {
    }

    void Application::Initialize(HWND hwnd)
    {
        mHwnd = hwnd;
        mHdc = GetDC(hwnd);

        getGetClientRect();
        CreateSizedBitmap(hwnd, mWidth, mHeight);

        Time::Initailize();
        Input::Initailize();

        SceneManager::Initialize();
    }

    void Application::Run() 
    {
        Update();
        LateUpdate();
        Render();  
    }

    void Application::Update()
    {
        Time::Update();
        Input::Update();

        SceneManager::Update();
    }

    void Application::LateUpdate()
    {
    }

    void Application::Render()
    {
        //메모리 DC를 초기화(흰색으로 채움)
        clearRenderTarget();

        Time::Redner(hMemDC);

        SceneManager::Render(hMemDC);

        copyRenderTarget(hMemDC, mHdc);
    }
    void Application::copyRenderTarget(HDC source, HDC dest)
    {
        BitBlt(dest, 0, 0, mWidth, mHeight
            , source, 0, 0, SRCCOPY);
    }
   

    void Application::clearRenderTarget()
    {

        RECT rect = { 0, 0, mWidth, mHeight };
        FillRect(hMemDC, &rect, (HBRUSH)(COLOR_WINDOW + 1));
    }

    void Application::getGetClientRect()
    {
        RECT windowRect;
        GetClientRect(mHwnd, &windowRect);
        mWidth = windowRect.right - windowRect.left;
        mHeight = windowRect.bottom - windowRect.top;
    }

    void Application::CreateSizedBitmap(HWND hwnd, int width, int height)
    {
        if (hBitmap)
            DeleteObject(hBitmap);
        else
            DeleteDC(hMemDC);

        //새 비트맵과 메모리 DC를 생성
        HDC hdc = GetDC(hwnd);
        hMemDC = CreateCompatibleDC(hdc);
        hBitmap = CreateCompatibleBitmap(hdc, width, height);
        SelectObject(hMemDC, hBitmap);
        ReleaseDC(hwnd, hdc);

        //메모리 DC를 초기화(흰색으로 채움)
        RECT rect = { 0, 0, width, height };
        FillRect(hMemDC, &rect, (HBRUSH)(COLOR_WINDOW + 1));
    }



}


