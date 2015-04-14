#include "Tile.h"


Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::SetContent(int id, ALLEGRO_BITMAP *image, Motion motion, State state, float position[])
{
	this->tileImage = image;
	this->state = state;
	this->motion = motion;
	this->position[0] = position[0];
	this->position[1] = position[1];
	this->id = id;
	containsEntity = false;
	direction = 1;
	range = 60;
	rangeCounter = 0;
	moveSpeed = 0.4f;
	prevPosition[0] = position[0];
	prevPosition[1] = position[1];
	tileAnimation.LoadContent(image, "", position);
}

void Tile::UnloadContent()
{
	al_destroy_bitmap(tileImage);
}

void Tile::Update(ALLEGRO_EVENT ev, Entity &e)
{
	if(motion == Motion::HORIZONTAL)
	{
		velocity[0] += moveSpeed * direction;
		velocity[1] = 0;
	}
	else if(motion == Motion::VERTICAL)
	{
		velocity[0] = 0;
		velocity[1] = moveSpeed * direction;
	}

	rangeCounter += velocity[0] + velocity[1];

	if(labs(rangeCounter) >= range)
	{
		rangeCounter = 0;
		direction *= -1;
	}

	position[0] += velocity[0];
	position[1] += velocity[1];

	tileAnimation.Position(position[0], position[1]);

	//Ÿ�Ͽ� collision�ڽ��� ���� �ش�
	FloatRect tileRect(position[0], position[1], 32, 32);
	FloatRect prevRect(e.prevPosition[0], e.prevPosition[1], 32, 32);

	//�浹 ����
	if(e.rect->IsIntersect(tileRect) && state == State::SOLID)
	{
		if(e.rect->Bottom >= tileRect.Top && prevRect.Bottom <= tileRect.Top)
		{
			/*Ÿ�� ���� �������� containsEntity�� Ű�� �׷���Ƽ�� ���鼭 ������ �Ҽ� �ְ� ���ش�*/
			e.position[1] = tileRect.Top - 32;
			e.activateGravity = false;
			e.isJumping = false;
			containsEntity = true;
			e.tileID = id;
		}
		else if(e.rect->Top <= tileRect.Bottom && prevRect.Top >= tileRect.Bottom)
		{
			e.position[1] = tileRect.Bottom;
		}
		else if(e.rect->Right >= tileRect.Left && prevRect.Right <= tileRect.Left)
		{
			e.position[0] = tileRect.Left - 32;
		}
		else if(e.rect->Left <= tileRect.Right && prevRect.Left >= tileRect.Right)
		{
			e.position[0] = tileRect.Right;
		}
		/*2015.04.13 �� ���� �߰� �����ν� �ٷιٷ� ���ϸ��̼ǿ� ������ �ִ°� ���´�
		���� Ÿ�� ������ �ȵ�*/
		//e.animation.Position(e.position[0], e.position[1]);
	}

	if(containsEntity && e.tileID == id)
	{
		/*containsEntity�� Ʈ���ε� entity�� ����� �ٽ� �׷���Ƽ Ȱ��ȭ containsEntity �� false*/
		if(e.position[0] + 32 < tileRect.Left || e.position[0] > tileRect.Right)
		{
			containsEntity = false;
			e.activateGravity = true;
		}
		else if(!e.animation.IsActive())
		{
			e.position[0] += velocity[0];
			e.position[1] += velocity[1];

			e.animation.Position(e.position[0], e.position[1]);
		}
		if(e.isJumping == false)
		{
			e.position[1] = position[1] - 32;
		}
	}
	/*else
	{
		if(motion == Motion::HORIZONTAL)
		{
			velocity[0] += moveSpeed * direction;
			velocity[1] = 0;
		}
		else if(motion == Motion::VERTICAL)
		{
			velocity[0] = 0;
			velocity[1] = moveSpeed * direction;
		}

		rangeCounter += velocity[0] + velocity[1];

		if(labs(rangeCounter) >= range)
		{
			range = 0;
			direction *= -1;
		}

		position[0] += velocity[0];
		position[1] += velocity[1];

		tileAnimation.Position(position[0], position[1]);

		//Ÿ�Ͽ� collision�ڽ��� ���� �ش�
		rect = new FloatRect(position[0], position[1], 32, 32);
		prevRect = new FloatRect(prevPosition[0], prevPosition[1], 32, 32);

		//�浹 ����
		if(e.rect->IsIntersect(*rect) && state == State::SOLID)
		{
			if(e.rect->Bottom >= rect->Top && e.prevRect->Bottom <= rect->Top)
			{
				/*Ÿ�� ���� �������� containsEntity�� Ű�� �׷���Ƽ�� ���鼭 ������ �Ҽ� �ְ� ���ش�
				e.position[1] = rect->Top - 32;
				e.activateGravity = false;
				containsEntity = true;
				e.tileID = id;
			}
			else if(e.rect->Top <= rect->Bottom && e.prevRect->Top >= rect->Bottom)
			{
				e.position[1] = rect->Bottom;
			}
			else if(e.rect->Right >= rect->Left && e.prevRect->Right <= rect->Left)
			{
				e.position[0] = rect->Left - 32;
			}
			else if(e.rect->Left <= rect->Right && e.prevRect->Left >= rect->Right)
			{
				e.position[0] = rect->Right;
			}
			/*2015.04.13 �� ���� �߰� �����ν� �ٷιٷ� ���ϸ��̼ǿ� ������ �ִ°� ���´�
			���� Ÿ�� ������ �ȵ�
			e.animation.Position(e.position[0], e.position[1]);
		}

		if(containsEntity && e.tileID == id)
		{
			/*containsEntity�� Ʈ���ε� entity�� ����� �ٽ� �׷���Ƽ Ȱ��ȭ containsEntity �� false
			if(e.position[0] + 32 < rect->Left || e.position[0] > rect->Right)
			{
				containsEntity = false;
				e.activateGravity = true;
			}
		}
	}*/
}

void Tile::Draw(ALLEGRO_DISPLAY *display)
{
	tileAnimation.Draw(display);
}
