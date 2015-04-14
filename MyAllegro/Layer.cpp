#include "Layer.h"


Layer::Layer()
{
}


Layer::~Layer()
{
}

std::pair<int, int> Layer::SetTiles(std::string tileString)
{
	//스트링에서 float으로 다 바꿔줍니다
	std::pair<int, int> tile;
	tile.first = atoi(tileString.substr(0, tileString.find(',')).c_str());
	tile.second = atoi(tileString.substr(tileString.find(',') + 1).c_str());
	return tile;
}


void Layer::LoadContent(std::string layerID)
{
	fileManager.LoadContent("Load/Map1.txt", category, contents, layerID);
	
	int indexY = 0;
	int id = 0;

	for(int i = 0; i < category.size(); i++)
	{
		for(int j = 0; j < category[i].size(); j++)
		{
			if(category[i][j] == "SolidTiles")
			{
				solidTiles.push_back(SetTiles(contents[i][j]));
			}
			else if(category[i][j] == "TileSheet")
			{
				tileSheet = al_load_bitmap(contents[i][j].c_str());
			}
			else if(category[i][j] == "Motion")
			{
				std::pair<int, int> temp;
				std::string motionType;

				std::string tempStr = contents[i][j].substr(0, 3);
				motionType = contents[i][j].substr(4);
				temp = SetTiles(tempStr);

				motion[temp] = motionType;
			}
			else if(category[i][j] == "StartLayer")
			{
				for(int k = 0; k < contents[i].size(); k++)
				{
					if(contents[i][k] != "---")
					{
						ALLEGRO_BITMAP *tileImage;
						//일단은 passive
						Tile::State tempState = Tile::State::PASSIVE;
						//타일 다 변경하고
						std::pair<int, int> tempTile = SetTiles(contents[i][k]);

						if(std::find(solidTiles.begin(), solidTiles.end(), tempTile) != solidTiles.end())
						{
							tempState = Tile::State::SOLID;
						}
						//각 타일에 맞는 이미지 불러주고
						tileImage = al_create_sub_bitmap(tileSheet, tempTile.first * 32, tempTile.second * 32, 32, 32);
						//indexY를 이용해서 쉽게 0부터 시작
						float position[2] = { k * 32, indexY * 32 };

						Tile::Motion m;

						if(motion.find(tempTile) != motion.end())
						{
							if(motion[tempTile] == "Horizontal")
								m = Tile::Motion::HORIZONTAL;
							else
								m = Tile::Motion::VERTICAL;
						}
						else
							m = Tile::Motion::STATIC;

						Tile tileInstance;
						tiles.push_back(tileInstance);
						tiles[tiles.size() - 1].SetContent(id, tileImage, m, tempState, position);
						id++;
					}
				}
				indexY++;
			}
		}
	}
}

void Layer::UnloadContent()
{
	for(int i = 0; i < tiles.size(); i++)
		tiles[i].UnloadContent();
	tiles.clear();
	al_destroy_bitmap(tileSheet);
}

void Layer::Update(ALLEGRO_EVENT ev, Entity &e)
{
	for(int i = 0; i < tiles.size(); i++)
		tiles[i].Update(ev, e);
}

void Layer::Draw(ALLEGRO_DISPLAY *display)
{
	for(int i = 0; i < tiles.size(); i++)
		tiles[i].Draw(display);
}