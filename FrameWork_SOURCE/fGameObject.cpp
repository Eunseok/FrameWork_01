#include "fGameObject.h"
#include "fInput.h"
#include "fTime.h"

namespace f
{
    GameObject::GameObject()
        : mComponents{}
    {
    }

    GameObject::~GameObject()
    {
        for (Component* comp : mComponents)
        {
            delete comp;
            comp = nullptr;
        }
    }
    void GameObject::Initialize()
    {
        for (Component* comp : mComponents)
            comp->Initialize();
    }

    void GameObject::Update()
    {
        for (Component* comp : mComponents)
            comp->Update();
        //const int speed = 200.0f ;
        //if (Input::GetKey(eKeyCode::A))
        //{
        //    mX -= speed * Time::DeltaTime();
        //}
        //if (Input::GetKey(eKeyCode::D))
        //{
        //    mX += speed * Time::DeltaTime();
        //}
        //if (Input::GetKey(eKeyCode::W))
        //{
        //    mY -= speed * Time::DeltaTime();
        //}
        //if (Input::GetKey(eKeyCode::S))
        //{
        //    mY += speed * Time::DeltaTime();
        //}
    }

    void GameObject::LateUpdate()
    {
        for (Component* comp : mComponents)
            comp->LateUpdate();
    }

    void GameObject::Render(HDC hdc)
    {
        for (Component* comp : mComponents)
            comp->Render(hdc);
    }
}
