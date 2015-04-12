#pragma once
class FloatRect
{
	public:
	FloatRect(float x, float y, float width, float height);

	FloatRect();
	~FloatRect();

	const float Right, Left, Top, Bottom;

	bool IsIntersect(FloatRect f);
};

