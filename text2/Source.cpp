#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(void)
{
	setlocale(LC_ALL, "Russian");
	char let;
	string slovo;
	int n, min;
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << " in.txt" << endl;
		return -4;
	}
	in.get(let);
	ofstream out("out.txt");
	if (!out.is_open())
	{
	cout << "out.txt" << endl;
	return -4;
	}
	out << "        ";
	min = 9;
	n = 0;
	while (!in.eof())
	{ 
		if (let == ' ')
		{
			if (min + n > 50)
			{
				min = n;
				out << endl<< slovo<<let;
				slovo.clear();
				in.get(let);
				n = 0;
			}
			else if (min+n<50)
			{
				min = min + n+1;
				out << slovo<<let;
				slovo.clear();
				in.get(let);
				n = 0;
			}
			else
			{
				min = 0;
				n = 0;
				out << slovo << endl;
				slovo.clear();
				in.get(let);
			}
		}
		else if (let == '$')
		{
			out << endl<< "        ";
			in.get(let);
			min = 8;
		}
		else if (let == '@')
		{
			while (let != '.')
			{
				in.get(let);
			}
			in.get(let);
		}
		else if (let == '#')
		{
			while (let != ' ')
			{
				in.get(let);
			}
			in.get(let);
		}
		else
		{
			
			slovo=slovo + let;
			in.get(let);
			n = n + 1;
		}
	}
	system("pause");
	return 0;
}

