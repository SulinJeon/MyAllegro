#pragma once
#include "Animation.h"


class FadeAnimation : public Animation
{
	private:
	//�ִϸ��̼� �ӵ�
	float fadeSpeed;
	//���İ� �ø��� ����
	bool increase;
	public:
	FadeAnimation();
	~FadeAnimation();


	void Update(Animation &a);	
	void SetIncrease(bool value);
};

