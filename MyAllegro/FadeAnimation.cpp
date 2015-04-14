#include "FadeAnimation.h"


FadeAnimation::FadeAnimation()
{
	fadeSpeed = 5.0f;
	increase = false;
}


FadeAnimation::~FadeAnimation()
{
}

void FadeAnimation::Update(Animation &a)
{
	/*isActive이면 알파값을 올릴지 말지를 보고
	fadeSpeed에 따라 알파값을 올리고 내린다
	알파가 255보다 높으면 increase는 false
	반대면 true, 다 끝나면 알파는 255
	(화면이 검정이라서 알파가 255일때 페이드 에니메이션이 끝난거임
	원래는 반대로 부분만 알파값을 낮춰서 0으로 만드는게 페이드에니메이션)*/
	if(a.IsActive())
	{
		if(!increase)
		{
			a.Alpha() -= fadeSpeed;
		}
		else
		{
			a.Alpha() += fadeSpeed;
		}
		if(a.Alpha() <= 0)
		{
			a.Alpha() = 0;
			increase = true;
		}
		else if(a.Alpha() >= 255)
		{
			a.Alpha() = 255;
			increase = false;
		}
	}
	else
		a.Alpha() = 255;
}

void FadeAnimation::SetIncrease(bool value)
{
	increase = value;
}


