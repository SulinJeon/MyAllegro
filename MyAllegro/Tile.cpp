#include "Tile.h"


Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::SetContent(ALLEGRO_BITMAP *image, State state, float position[])
{
	this->tileImage = image;
	this->state = state;
	this->position[0] = position[0];
	this->position[1] = position[1];
	tileAnimation.LoadContent(image, "", position);
}

void Tile::UnloadContent()
{
	al_destroy_bitmap(tileImage);
}

void Tile::Update(ALLEGRO_EVENT ev, Entity &e)
{
	//타일에 collision박스를 씌워 준다
	FloatRect tileRect(position[0], position[1], 32, 32);

	//충돌 시험
	if(e.rect->IsIntersect(tileRect) && state == State::SOLID)
	{
		if(e.rect->Bottom >= tileRect.Top && e.prevRect->Bottom <= tileRect.Top)
		{
			e.position[1] = tileRect.Top - 32;
		}
		else if(e.rect->Top <= tileRect.Bottom && e.prevRect->Top >= tileRect.Bottom)
		{
			e.position[1] = tileRect.Bottom;
		}
		else if(e.rect->Right >= tileRect.Left && e.prevRect->Right <= tileRect.Left)
		{
			e.position[0] = tileRect.Left - 32;
		}
		else if(e.rect->Left <= tileRect.Right && e.prevRect->Left >= tileRect.Right)
		{
			e.position[0] = tileRect.Right;
		}
	}
}

void Tile::Draw(ALLEGRO_DISPLAY *display)
{
	tileAnimation.Draw(display);
}
