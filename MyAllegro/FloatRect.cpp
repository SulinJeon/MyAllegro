#include "FloatRect.h"

FloatRect::FloatRect(float x, float y, float width, float height) :
Left(x), Right(x + width), Top(y), Bottom(y + height)
{

}

FloatRect::~FloatRect()
{
}

bool FloatRect::IsIntersect(FloatRect f)
{
	//그러하다
	if(Right < f.Left || Left > f.Right || Top > f.Bottom || Bottom < f.Top)
	{
		return false;
	}
	else
		return true;
}
