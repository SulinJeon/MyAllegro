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
	//��ƼƼ���� ���� �׷���Ƽ �����Ҽ��� �����ϱ�
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
	//input.Update�� Ű������Ʈ�� �׻� ������Ʈ ��Ű��
	//IsActive�� ������ �ϰ� �ִٰ� �ƹ�Ű�� �ȴ����������� false�� �Ѵ�
	input.Update();
	animation.IsActive() = true;


	if(input.IsKeyDown(ALLEGRO_KEY_UP) && !activateGravity)
	{
		//UpŰ�� �����ų� �׷���Ƽ�� ��Ȱ��ȭ ���������� �ۼ� �ִ�
		//�ٰ� ���� �׷���Ƽ�� Ȱ��ȭ ��Ų��
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
		/*�׷���Ƽ�� Ȱ��ȭ �Ǹ� �׷���Ƽ�� �����ش�*/
		velocity[1] += gravity;
	}
	else
		velocity[1] = 0;

	position[0] += velocity[0];
	position[1] += velocity[1];

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