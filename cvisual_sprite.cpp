#include <stdlib.h>
#include "cvisual_sprite.h"

CVisual_Sprite::CVisual_Sprite()
{
	texture = NULL;
}

CVisual_Sprite::~CVisual_Sprite()
{
	texture = NULL;
}

void CVisual_Sprite::Render(const SRenderData* rnd_data)
{
	float x = 0.f;
	float y = 0.f;
	
	if (rnd_data)
	{
		x=rnd_data->x;
		y=rnd_data->y;
	}
	
	static bool calc_anchor = false;
	
	// anchor calculation
	
	float w = (float)texture->GetWidth();
	float h = (float)texture->GetHeight();
	
	if (calc_anchor)
	{
		x = x - (w * 0.5f);
		y = y - (h * 0.5f);
		w = w - (w * 0.5f);
		h = h - (h * 0.5f);
	}
	
	renderer->SetAlphaBlend(true);
	renderer->DrawTexture(texture, x, y, w, h);
	renderer->SetAlphaBlend(false);
}

void CVisual_Sprite::Load(const char* filename)
{
	texture = texcontainer->LoadTexture(filename);
}

