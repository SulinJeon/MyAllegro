#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::LoadContent(std::vector<std::string> category, std::vector<std::string> contents)
{
	Entity::LoadContent(category, contents);
	moveSpeed = 5.0f;
	direction = Direction::DOWN;

	
}

void Player::UnloadContent()
{
	Entity::UnloadContent();
	animation.UnloadContent();
}

void Player::Update(ALLEGRO_EVENT ev)
{
	Entity::Update(ev);
	//input.Update로 키스테이트를 항상 업데이트 시키고
	//IsActive를 참으로 하고 있다가 아무키도 안눌러져있으면 false로 한다
	input.Update();
	animation.IsActive() = true;

	if(input.IsKeyDown(ALLEGRO_KEY_DOWN))
	{
		direction = Direction::DOWN;
		position[1] += moveSpeed;
	}
	else if(input.IsKeyDown(ALLEGRO_KEY_LEFT))
	{
		direction = Direction::LEFT;
		position[0] -= moveSpeed;
	}
	else if(input.IsKeyDown(ALLEGRO_KEY_RIGHT))
	{
		direction = Direction::RIGHT;
		position[0] += moveSpeed;
	}
	else if(input.IsKeyDown(ALLEGRO_KEY_UP))
	{
		direction = Direction::UP;
		position[1] -= moveSpeed;
	}
	else
		animation.IsActive() = false;

	animation.CurrentFrame().second = direction;
	animation.Position(position[0], position[1]);
	ssAnimation.Update(animation);

	//매 업데이트마다 새로운 박스를 씌워준다
	delete rect;
	delete prevRect;
	rect = new FloatRect(position[0], position[1], 32, 32);
	prevRect = new FloatRect(prevPosition[0], prevPosition[1], 32, 32);
}

void Player::Draw(ALLEGRO_DISPLAY *display)
{
	Entity::Draw(display);
}