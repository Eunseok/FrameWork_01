#include "fTime.h"

namespace f
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initailize()
	{
		//CPU 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		//프로그램이 시작했을 때 진동수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differentFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		DeltaTimeValue = differentFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Redner(HDC hdc)
	{
		static float time = 0.0f;
		float fps = 1.0f / DeltaTimeValue;

		time += DeltaTimeValue;
		wchar_t strTime[50] = L"";
		swprintf_s(strTime, 50, L"Time : %f", time);
		int timeLen = wcsnlen_s(strTime, 50);

		wchar_t strFps[50] = L"";
		swprintf_s(strFps, 50, L"Fps : %d", (int)fps);
		int fpsLen = wcsnlen_s(strFps, 50);

		

		TextOut(hdc, 0, 0, strTime, timeLen);
		TextOut(hdc, 0, 20, strFps, fpsLen);
	}
}
