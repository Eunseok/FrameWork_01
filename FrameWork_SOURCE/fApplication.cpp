#include "fApplication.h"
#include "fInput.h"

namespace f
{
    Application::Application()
        : mHwnd(nullptr), mHdc(nullptr)
    {
    }

    Application::~Application() {
    }

    void Application::Initialize(HWND hwnd)
    {
        mHwnd = hwnd;
        mHdc = GetDC(hwnd);
        Input::Initailize();
    }

    void Application::Run()
    {
        Update();
        LateUpdate();
        Render();
    }

    void Application::Update()
    {d
        Input::Update();

        mPlayer.Update();
    }

    void Application::LateUpdate()
    {
        mPlayer.LateUpdate();
    }

    void Application::Render()
    {
        mPlayer.Render(mHdc);
    }
}
