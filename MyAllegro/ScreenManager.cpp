#include "ScreenManager.h"

ScreenManager &ScreenManager::GetInstance()
{
	/*정적 클래스 하나 생성하고 그 클래스를 리턴*/
	static ScreenManager instance;
	return instance;
}

ScreenManager::ScreenManager()
{
}


ScreenManager::~ScreenManager()
{
}

void ScreenManager::AddScreen(std::string screen)
{
	transition.Alpha() = 0;
	fade.SetIncrease(true);
	startTransition = true;
	newScreen = screenName[screen];
	transition.IsActive() = true;

}

void ScreenManager::Initialize()
{
	//currentScreen = new SplashScreen;
	screenName["SplashScreen"] = new SplashScreen;
	screenName["TitleScreen"] = new TitleScreen;
	screenName["GamePlayScreen"] = new GamePlayScreen;
	currentScreen = screenName["GamePlayScreen"];
}

void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
	transitionImage = al_load_bitmap("Black.png");
	position[0] = position[1] = 0;
	transition.LoadContent(transitionImage, "", position);
	startTransition = false;
}

void ScreenManager::UnloadContent()
{
	al_destroy_bitmap(transitionImage);
	currentScreen->UnloadContent();
	//delete currentScreen;
	//currentScreen = NULL;
	transition.UnloadContent();

	std::map<std::string, GameScreen*>::iterator tempIt;

	for(auto temp : screenName)
	{
		delete temp.second;
	}
	screenName.clear();
}

void ScreenManager::Update(ALLEGRO_EVENT ev)
{
	if(!startTransition)
		currentScreen->Update(ev);
	else
		Transition(ev);
}

void ScreenManager::Draw(ALLEGRO_DISPLAY *display)
{
	currentScreen->Draw(display);
	if(startTransition)
		transition.Draw(display);
}

void ScreenManager::Transition(ALLEGRO_EVENT ev)
{
	fade.Update(transition);
	if(transition.Alpha() == 255)
	{
		currentScreen->UnloadContent();
		//delete currentScreen;
		//currentScreen = NULL;
		currentScreen = newScreen;
		currentScreen->LoadContent();
		al_rest(1.0);
	}
	else if(transition.Alpha() == 0)
	{
		startTransition = false;
		transition.IsActive() = false;
	}
}
