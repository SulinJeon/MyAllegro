#pragma once

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class FileManager
{
	private:
	enum LoadType { CATEGORY, CONTENT };
	int type;
	bool identifierFound;

	std::vector<std::string> tempCategory, tempContents;

	public:
	FileManager();
	~FileManager();

	void LoadContent(const char *filename, std::vector<std::vector<std::string>> &category, std::vector<std::vector<std::string>> &contents);
	void LoadContent(const char *filename, std::vector<std::vector<std::string>> &category, std::vector<std::vector<std::string>> &contents, std::string identifier);
};

