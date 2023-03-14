
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, int n)
{
	std::vector<std::string> substrings;

	for (size_t i = 0; i < str.size(); i += n) 
	{
		substrings.push_back(str.substr(i, n));
	}
	return substrings;
}

std::string findSubstr(std::string const& str, int n) {
	if (str.length() < n) {
		return str;
	}
	return str.substr(0, n);
}

bool IsKPeriodic(const std::string& str, int n)
{
	std::string pat = findSubstr(str, n);
	std::vector<std::string> tokens = split(str, n);
	for (auto& token : tokens)
	{
		if (token == pat)
		{
			std::cout << token << " = " << pat << std::endl;
			continue;
		}
		else
		{
			std::cout << token << " != " << pat << " ,значит " << str << " не кратен " << n << std::endl;
			return false;
		}
	}
	std::cout << str << " кратен " << n << std::endl;
	return true;
}



int main()
{
	setlocale(LC_ALL, "");
	const std::string txt = "ABAABA";
	int a;
	a= txt.size();
	std::cout << "Введите кратность 0<К<="<<a<<std::endl;
	int K;
	std::cin >> K;
	while ((K<=0) || (K>a))
	{
		std::cin >> K;
	}
	IsKPeriodic(txt,K);
	return 0;
}