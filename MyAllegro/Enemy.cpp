#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::LoadContent(std::vector<std::string> category, std::vector<std::string> contents)
{
	Entity::LoadContent(category, contents);
	gravity = 1;
	animation.IsActive() = true;
	counter = 0;
	activateGravity = true;
}

void Enemy::UnloadContent()
{
	Entity::UnloadContent();
}

void Enemy::Update(ALLEGRO_EVENT ev)
{
	prevPosition[0] = position[0];
	prevPosition[1] = position[1];

	if(direction == Direction::RIGHT)
	{
		velocity[0] = moveSpeed;
	}
	else if(direction == Direction::LEFT)
	{
		velocity[0] = -moveSpeed;
	}

	if(activateGravity)
	{
		/*그래비티가 활성화 되면 그래비티를 더해준다*/
		velocity[1] += gravity;
	}
	else
		velocity[1] = 0;

	position[0] += velocity[0];
	position[1] += velocity[1];

	animation.CurrentFrame().second = direction;
	animation.Position(position[0], position[1]);
	ssAnimation.Update(animation);

	//매 업데이트마다 새로운 박스를 씌워준다
	delete rect;
	delete prevRect;
	rect = new FloatRect(position[0], position[1], 32, 32);
	prevRect = new FloatRect(prevPosition[0], prevPosition[1], 32, 32);

	counter += moveSpeed;

	if(counter >= range)
	{
		counter = 0;
		if(direction == Direction::RIGHT)
		{
			direction = Direction::LEFT;
		}
		else if(direction == Direction::LEFT)
		{
			direction = Direction::RIGHT;
		}
	}

}

void Enemy::Draw(ALLEGRO_DISPLAY *display)
{
	animation.Draw(display);
}
