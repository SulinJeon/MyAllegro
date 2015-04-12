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
	//IsActive�϶��� �������� �ö󰣴�
	if(a.IsActive())
	{
		frameCounter++;
		if(frameCounter >= switchFrame)
		{
			frameCounter = 0;
			a.CurrentFrame().first++;
			//�̹��� �������� width�� Ŀ���� �ٽ� ����
			if(a.CurrentFrame().first * a.GetFrameDimensions().first >= al_get_bitmap_width(a.Image()))
			{
				a.CurrentFrame().first = 0;
			}
		}
	}
	//�ƴҶ��� ī���͸� 0���� CurrentFrame�� �� �ִ� ���·�
	else
	{
		frameCounter = 0;
		a.CurrentFrame().first = 1;
	}
	//�̸� ĳ���� �������� �߶� ���´�
	a.SourceRect() = al_create_sub_bitmap(a.Image(), a.CurrentFrame().first * a.GetFrameDimensions().first, a.CurrentFrame().second * a.GetFrameDimensions().second,
		a.GetFrameDimensions().first, a.GetFrameDimensions().second);
}