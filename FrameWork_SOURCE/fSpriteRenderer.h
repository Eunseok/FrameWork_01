#pragma once
#include "fEntity.h"
#include "fComponent.h"
#include "fTexture.h"

namespace f
{
	using namespace math;
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(Vector2 size) { mSize = size; }
	private:
		graphics::Texture* mTexture;
		Vector2 mSize;
	};
}

