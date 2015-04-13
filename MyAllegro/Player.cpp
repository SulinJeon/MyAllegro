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
	//moveSpeed = 5.0f;
	direction = Direction::DOWN;
	//엔티티마다 따로 그래비티 설정할수도 있으니까
	gravity = 1.0f;
	jumpSpeed = 15.0f;
	activateGravity = true;
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


	if(input.IsKeyDown(ALLEGRO_KEY_UP) && !activateGravity)
	{
		//Up키를 누르거나 그래비티가 비활성화 되있을때만 뛸수 있다
		//뛰고 나면 그래비티를 활성화 시킨다
		direction = Direction::UP;
		velocity[1] = -jumpSpeed;
		activateGravity = true;
	}
	else if(input.IsKeyDown(ALLEGRO_KEY_LEFT))
	{
		direction = Direction::LEFT;
		velocity[0] = -moveSpeed;
	}
	else if(input.IsKeyDown(ALLEGRO_KEY_RIGHT))
	{
		direction = Direction::RIGHT;
		velocity[0] = +moveSpeed;
	}
	else
	{
		velocity[0] = 0;
		animation.IsActive() = false;
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
}

void Player::Draw(ALLEGRO_DISPLAY *display)
{
	Entity::Draw(display);
}