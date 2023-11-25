#include <iostream>
#include<string>
#include<algorithm>
#include <map>
using namespace std;
//tree. (string, bool)
map<string, bool> tree;
int N, M;
string str;
int result = 0;

class Trie
{
	Trie* next[26];
	bool isEnd;
	//memory allocation.
	Trie()
	{
		fill(next, next + 26, nullptr);
		isEnd = false;
	}
	//memory free
	~Trie()
	{
		for (size_t i = 0; i < 26; i++)
		{
			if (next[i])
			{
				delete next[i];
			}
		}
	}
	void insertTree(string word, int size, int index)
	{
		if (size < index)
		{
			isEnd = true;
			return;
		}
		int num = word.at(index);
	}
};
void insertTree(string word, int size, int index);
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		//input string.
		cin >> str;
		//TREE
		tree.insert(pair<string, bool>(str, true));
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		//if isend true => leaf node.
		if (tree[str] == true)
			result++;
	}
	cout << result;

}

