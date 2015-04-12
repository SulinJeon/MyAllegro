#pragma once
#include "Animation.h"
class SpriteSheetAnimation :
	public Animation
{
	private:
	//프레임 카운터로 세고 스윗치카운터까지 가면 프레임을 바꾼다
	int frameCounter, switchFrame;

	public:
	SpriteSheetAnimation();
	~SpriteSheetAnimation();

	void Update(Animation& a);
};

