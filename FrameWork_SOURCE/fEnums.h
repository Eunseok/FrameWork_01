#pragma once

namespace f::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		//Tree
		//Character
		Player,
		Max = 16,
	};

	enum class eReourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}