#pragma once
#include "Animation.h"


class FadeAnimation : public Animation
{
	private:
	//애니매이션 속도
	float fadeSpeed;
	//알파값 올릴까 말까
	bool increase;
	public:
	FadeAnimation();
	~FadeAnimation();


	void Update(Animation &a);	
	void SetIncrease(bool value);
};

