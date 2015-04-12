#include "FileManager.h"


FileManager::FileManager()
{
	identifierFound = false;
}


FileManager::~FileManager()
{
}

void FileManager::LoadContent(const char *filename, std::vector<std::vector<std::string>> &category, std::vector<std::vector<std::string>> &contents)
{
	//라인 임시라인
	std::string line, tempLine;
	//파일을 열고
	std::ifstream openfile(filename);
	//파일이 열렸다면
	if(openfile.is_open())
	{
		//파일이 끝날때까지 while
		while(!openfile.eof())
		{
			/*한줄씩 읽어서 스트링스트림에 넣고
			스트링스트림에서 다시 delimiter까지 읽어서 tempLine에 저장*/
			std::stringstream str;
			std::getline(openfile, line);

			//카테고리이면 "Load=" 을 지워준다
			if(line.find("Load=") != std::string::npos)
			{
				type = LoadType::CATEGORY;
				line = line.erase(0, line.find("=") + 1);
				tempCategory.clear();
			}
			//콘텐츠일 경우
			else
			{
				type = LoadType::CONTENT;
				tempContents.clear();
			}

			str << line;
			while(std::getline(str, tempLine, ']'))
			{
				/*'['이거 찾아서 지워주기*/
				tempLine.erase(std::remove(tempLine.begin(), tempLine.end(), '['), tempLine.end());
				//끝에 빈칸이나 탭 개행등이 있음 지워주지
				std::string erase = " \t\n\r";
				tempLine.erase(tempLine.find_last_not_of(erase) + 1);

				/*LoadType에 따라서 temp에 넣어준다
				그냥 벡터에 안 넣고 temp에 넣어서 이중 벡터에 넣는 이유는
				Category를 하나 이상 가지고 있을수 있기때문에 string을 가지는 벡터를 벡터에 저장한다*/
				if(type == LoadType::CATEGORY)
					tempCategory.push_back(tempLine);
				else if(type == LoadType::CONTENT)
					tempContents.push_back(tempLine);

				std::cout << tempLine << std::endl;
			}
			if(type == LoadType::CONTENT && tempContents.size() > 0)
			{
				category.push_back(tempCategory);
				contents.push_back(tempContents);
			}
		}
	}
	else
	{
	}
}

void FileManager::LoadContent(const char *filename, std::vector<std::vector<std::string>> &category, std::vector<std::vector<std::string>> &contents, std::string identifier)
{
	//라인 임시라인
	std::string line, tempLine;
	//파일을 열고
	std::ifstream openfile(filename);
	//파일이 열렸다면
	if(openfile.is_open())
	{
		//파일이 끝날때까지 while
		while(!openfile.eof())
		{
			/*한줄씩 읽어서 스트링스트림에 넣고
			스트링스트림에서 다시 delimiter까지 읽어서 tempLine에 저장*/
			std::stringstream str;
			std::getline(openfile, line);

			/*EndIdentifier가 먼저 와야하는 이유는 EndIdentifier내에도 Identifier가 있어서 항상 먼저 실행이 된다
			그래서 EndIdentifier를 먼저 검사해야함*/
			if(line.find("EndIdentifier=") != std::string::npos && line.find(identifier) != std::string::npos)
			{
				identifierFound = false;
				break;
			}
			//"Identifier=" '는'기로까지 포함 하는 이유는 디렉토리명에 필요한 단어가 있을수도 있으니까 '='까지 해줬다
			else if(line.find("Identifier=") != std::string::npos && line.find(identifier) != std::string::npos)
			{
				identifierFound = true;
				continue;
			}

			if(identifierFound)
			{
				//카테고리이면 "Load=" 을 지워준다
				if(line.find("Load=") != std::string::npos)
				{
					type = LoadType::CATEGORY;
					line = line.erase(0, line.find("=") + 1);
					tempCategory.clear();
				}
				//콘텐츠일 경우
				else
				{
					type = LoadType::CONTENT;
					tempContents.clear();
				}

				str << line;
				while(std::getline(str, tempLine, ']'))
				{
					/*'['이거 찾아서 지워주기*/
					tempLine.erase(std::remove(tempLine.begin(), tempLine.end(), '['), tempLine.end());
					//끝에 빈칸이나 탭 개행등이 있음 지워주지
					std::string erase = " \t\n\r";
					tempLine.erase(tempLine.find_last_not_of(erase) + 1);

					/*LoadType에 따라서 temp에 넣어준다
					그냥 벡터에 안 넣고 temp에 넣어서 이중 벡터에 넣는 이유는
					Category를 하나 이상 가지고 있을수 있기때문에 string을 가지는 벡터를 벡터에 저장한다*/
					if(type == LoadType::CATEGORY)
						tempCategory.push_back(tempLine);
					else if(type == LoadType::CONTENT)
						tempContents.push_back(tempLine);

					std::cout << tempLine << std::endl;
				}
				if(type == LoadType::CONTENT && tempContents.size() > 0)
				{
					category.push_back(tempCategory);
					contents.push_back(tempContents);
				}
			}
		}
	}
	else
	{
	}
}
