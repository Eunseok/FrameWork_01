#include "fGameObject.h"
#include "fInput.h"
#include "fTime.h"

namespace f
{
    GameObject::GameObject()
        : mX(0.f), mY(0.f)
    {
    }

    GameObject::~GameObject()
    {
    }

    void GameObject::Update()
    {
        const int speed = 200.0f ;
        if (Input::GetKey(eKeyCode::A))
        {
            mX -= speed * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::D))
        {
            mX += speed * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::W))
        {
            mY -= speed * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::S))
        {
            mY += speed * Time::DeltaTime();
        }
    }

    void GameObject::LateUpdate()
    {

    }

    void GameObject::Render(HDC hdc)
    {
        HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

        Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

        SelectObject(hdc, oldBrush);
        DeleteObject(redBrush);

    }
}
