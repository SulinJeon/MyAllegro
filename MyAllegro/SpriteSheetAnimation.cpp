#include "SpriteSheetAnimation.h"


SpriteSheetAnimation::SpriteSheetAnimation()
{
	frameCounter = 0;
	switchFrame = 10;
}


SpriteSheetAnimation::~SpriteSheetAnimation()
{
}

void SpriteSheetAnimation::Update(Animation& a)
{
	//IsActive일때만 프레임이 올라간다
	if(a.IsActive())
	{
		frameCounter++;
		if(frameCounter >= switchFrame)
		{
			frameCounter = 0;
			a.CurrentFrame().first++;
			//이미지 원본보다 width가 커지면 다시 리셋
			if(a.CurrentFrame().first * a.GetFrameDimensions().first >= al_get_bitmap_width(a.Image()))
			{
				a.CurrentFrame().first = 0;
			}
		}
	}
	//아닐때는 카운터를 0으로 CurrentFrame은 서 있는 상태로
	else
	{
		frameCounter = 0;
		a.CurrentFrame().first = 1;
	}
	//미리 캐릭터 프레임을 잘라 놓는다
	a.SourceRect() = al_create_sub_bitmap(a.Image(), a.CurrentFrame().first * a.GetFrameDimensions().first, a.CurrentFrame().second * a.GetFrameDimensions().second,
		a.GetFrameDimensions().first, a.GetFrameDimensions().second);
}