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
	//Ÿ�Ͽ� collision�ڽ��� ���� �ش�
	FloatRect tileRect(position[0], position[1], 32, 32);

	//�浹 ����
	if(e.rect->IsIntersect(tileRect) && state == State::SOLID)
	{
		if(e.rect->Bottom >= tileRect.Top && e.prevRect->Bottom <= tileRect.Top)
		{
			/*Ÿ�� ���� �������� containsEntity�� Ű�� �׷���Ƽ�� ���鼭 ������ �Ҽ� �ְ� ���ش�*/
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
		/*2015.04.13 �� ���� �߰� �����ν� �ٷιٷ� ���ϸ��̼ǿ� ������ �ִ°� ���´�
		���� Ÿ�� ������ �ȵ�*/
		e.animation.Position(e.position[0], e.position[1]);
	}

	if(containsEntity && e.tileID == id)
	{
		/*containsEntity�� Ʈ���ε� entity�� ����� �ٽ� �׷���Ƽ Ȱ��ȭ containsEntity �� false*/
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
