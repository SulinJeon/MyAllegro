#pragma once
#include "Animation.h"
class SpriteSheetAnimation :
	public Animation
{
	private:
	//������ ī���ͷ� ���� ����ġī���ͱ��� ���� �������� �ٲ۴�
	int frameCounter, switchFrame;

	public:
	SpriteSheetAnimation();
	~SpriteSheetAnimation();

	void Update(Animation& a);
};

