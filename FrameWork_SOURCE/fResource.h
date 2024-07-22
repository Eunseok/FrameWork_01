#pragma once
#include "fEntity.h"


namespace f
{
	class Resource : public Entity
	{
	public:
		Resource(enums::eReourceType mTypes);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path;  }

	private:
		enums::eReourceType mTypes;
		std::wstring mPath;
	};

	/*class Texture : public Resource;
	class AudioClip : public Resource;*/
}

