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
	isJumping = false;
}

void Player::UnloadContent()
{
	delete rect;
	delete prevRect;
	Entity::UnloadContent();
	//animation.UnloadContent();
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
		isJumping = true;

		std::cout << position[0] << std::endl;
		std::cout << position[1] << std::endl;
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

	//�������� ������Ʈ
	position[0] += velocity[0];
	position[1] += velocity[1];

	//ī�޶� ĳ���͸� ������� �Ѵ�
	CameraUpdate(cameraPosition, position, 32, 32);
	al_identity_transform(&camera);
	//����� �÷����� ���ʱ׸��� ���� �����δ�
	al_translate_transform(&camera, -cameraPosition.first, 0);
	al_use_transform(&camera);

	//���⿡ ���� �������� ������Ʈ�ϰ� �����ǵ� �ٽ� ������Ʈ �Ѵ�
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

void Player::CameraUpdate(std::pair<float, float> &cameraPosition, float position[], int width, int height)
{
	//�÷��̾� ��ġ�� ȭ�� �߾Ӻ��� �������̰ų� ���ΰ��� ���� �÷����� �Ǹ鼭 ȭ���� �����δ�
	cameraPosition.first = -(800 / 2) + (position[0] + width / 2);
	cameraPosition.second = -(600 / 2) + (position[1] + height / 2);

	if(cameraPosition.first < 0)
		cameraPosition.first = 0;
	if(cameraPosition.second < 0)
		cameraPosition.second = 0;
}

void Player::SetPos(float x, float y)
{
	this->position[0] = x;
	this->position[1] = y;
}