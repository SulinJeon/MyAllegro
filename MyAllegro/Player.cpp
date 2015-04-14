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
		/*그래비티가 활성화 되면 그래비티를 더해준다*/
		velocity[1] += gravity;
	}
	else
		velocity[1] = 0;

	//포지션을 업데이트
	position[0] += velocity[0];
	position[1] += velocity[1];

	//카메라가 캐릭터를 따라오게 한다
	CameraUpdate(cameraPosition, position, 32, 32);
	al_identity_transform(&camera);
	//참고로 플러스가 왼쪽그리고 위로 움직인다
	al_translate_transform(&camera, -cameraPosition.first, 0);
	al_use_transform(&camera);

	//방향에 따라서 프레임을 업데이트하고 포지션도 다시 업데이트 한다
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

void Player::CameraUpdate(std::pair<float, float> &cameraPosition, float position[], int width, int height)
{
	//플레이어 위치가 화면 중앙보다 오른쪽이거나 위로가면 값이 플러스가 되면서 화면이 움직인다
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