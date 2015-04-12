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
	//input.Update�� Ű������Ʈ�� �׻� ������Ʈ ��Ű��
	//IsActive�� ������ �ϰ� �ִٰ� �ƹ�Ű�� �ȴ����������� false�� �Ѵ�
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

	//�� ������Ʈ���� ���ο� �ڽ��� �����ش�
	delete rect;
	delete prevRect;
	rect = new FloatRect(position[0], position[1], 32, 32);
	prevRect = new FloatRect(prevPosition[0], prevPosition[1], 32, 32);
}

void Player::Draw(ALLEGRO_DISPLAY *display)
{
	Entity::Draw(display);
}