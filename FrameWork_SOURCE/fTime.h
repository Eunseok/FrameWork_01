#pragma once
#include "Commoninclude.h"
namespace f
{
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Redner(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};
}
