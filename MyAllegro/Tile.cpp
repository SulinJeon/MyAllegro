#include "Tile.h"


Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::SetContent(int id, ALLEGRO_BITMAP *image, State state, float position[])
{
	this->tileImage = image;
	this->state = state;
	this->position[0] = position[0];
	this->position[1] = position[1];
	this->id = id;
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
			/*타일 위에 있을때는 containsEntity를 키고 그래비티는 끄면서 점프를 할수 있게 해준다*/
			e.position[1] = tileRect.Top - 32;
			e.activateGravity = false;
			containsEntity = true;
			e.tileID = id;
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
		/*2015.04.13 이 줄을 추가 함으로써 바로바로 에니메이션에 포지션 주는걸 막는다
		따라서 타일 안으로 안들어감*/
		e.animation.Position(e.position[0], e.position[1]);
	}

	if(containsEntity && e.tileID == id)
	{
		/*containsEntity가 트루인데 entity가 벗어나면 다시 그래비티 활성화 containsEntity 는 false*/
		if(e.position[0] + 32 < tileRect.Left || e.position[0] > tileRect.Right)
		{
			containsEntity = false;
			e.activateGravity = true;
		}
	}
}

void Tile::Draw(ALLEGRO_DISPLAY *display)
{
	tileAnimation.Draw(display);
}
