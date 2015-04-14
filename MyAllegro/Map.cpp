#include "Map.h"

Map::Map()
{
}


Map::~Map()
{
}

void Map::LoadContent(std::string stageNumber)
{
	layer = new Layer();
	layer->LoadContent(stageNumber);
	//지금은 1스테이지뿐
	/*Layer layerInstace;
	layers.push_back(layerInstace);
	layers[0].LoadContent("Layer1");*/
}

void Map::UnloadContent()
{
	layer->UnloadContent();
	delete layer;
	//layers[0].UnloadContent();
}

void Map::Update(ALLEGRO_EVENT ev, Entity &e)
{
	layer->Update(ev, e);
	//layers[0].Update(ev, e);
}

void Map::Draw(ALLEGRO_DISPLAY *display)
{
	layer->Draw(display);
	//layers[0].Draw(display);
}
