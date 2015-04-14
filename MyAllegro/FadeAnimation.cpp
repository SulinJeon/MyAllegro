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
	/*isActive�̸� ���İ��� �ø��� ������ ����
	fadeSpeed�� ���� ���İ��� �ø��� ������
	���İ� 255���� ������ increase�� false
	�ݴ�� true, �� ������ ���Ĵ� 255
	(ȭ���� �����̶� ���İ� 255�϶� ���̵� ���ϸ��̼��� ��������
	������ �ݴ�� �κи� ���İ��� ���缭 0���� ����°� ���̵忡�ϸ��̼�)*/
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


