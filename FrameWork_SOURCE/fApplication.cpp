#include "fApplication.h"
#include "fInput.h"
#include "fTime.h"

namespace f
{
    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        , mWidth(0)
        , mHeight(0)
        , mBackHdc(nullptr)
        , mBackBitmap(nullptr)
    {
    }

    Application::~Application() {
    }

    void Application::Initialize(HWND hwnd, UINT width, UINT height)
    {
        mHwnd = hwnd;
        mHdc = GetDC(hwnd);

        RECT rect = {0, 0, width, height};
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

        mWidth = rect.right - rect.left;
        mHeight = rect.bottom - rect.top;

        SetWindowPos(mHwnd, nullptr, 0, 0
            , mWidth
            , height, 0);
        ShowWindow(mHwnd, true);

        //������ �ػ󵵿� �´� �����(��ȭ��)����
        mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

        //����۸� ����ų DC����
        mBackHdc = CreateCompatibleDC(mHdc);

        HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
        DeleteObject(oldBitmap);


        Time::Initailize();
        Input::Initailize();
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
        mPlayer.Update();
    }

    void Application::LateUpdate()

    {
        mPlayer.LateUpdate();
    }

    void Application::Render()
    {
        Rectangle(mBackHdc, 0, 0, 1600, 900);

        Time::Redner(mBackHdc);
        mPlayer.Render(mBackHdc);

        // BackBuffer�� �ִ°� ���� Buffer�� ����(�׷��ش�)
        BitBlt(mHdc, 0, 0, mWidth, mHeight
            , mBackHdc, 0, 0, SRCCOPY);
    }
}
