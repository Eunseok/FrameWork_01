#pragma once
#include "../FrameWork_SOURCE/fResources.h"
#include "../FrameWork_SOURCE/fTexture.h"

namespace f
{
	void LoadResources()
	{
		Resources::Load<f::graphics::Texture>(L"BG", L"C:\\Users\\asp67\\source\\repos\\FrameWork_01\\Resources\\CloudOcean.png");
	}
}