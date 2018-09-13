#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "vector"


int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cerr << "参数错误" << std::endl;
		return 1;
	}

	std::ifstream f1(argv[1]);
	if(!f1)
	{
		std::cerr << "打开" << argv[1] << "失败" << std::endl;
		return 2;
	}

	std::string name;
	vector<std::string> names;

	while(1)
	{
		if(!(f1 >> name)) break;
		names.push_back(name);
	}

	srand(time(NULL));
	int i = rand() % names.length();

	for(int j = 20; j > 0 ; --j)
	{
		system("clear");
		std::cout << names[i] << std::endl;
		i = rand() % names.length();
		usleep(5000 * j);
	}

	return 0;
}

