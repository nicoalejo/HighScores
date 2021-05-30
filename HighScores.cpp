#include "HighScores.h"
#include <iostream>
#include <map>

//user <algoritm> y <map>
typedef multimap <int, string> temp;

HighScores::HighScores()
{
}

HighScores::HighScores(multimap<int, string> addscores)
{
	for (auto it = addscores.begin(); it != addscores.end(); it++) {
		scores.insert(make_pair(it->first, it->second));
	}
}

void HighScores::AddScore(string name, int score)
{
	scores.insert(make_pair(score, name));
}

void HighScores::AddScore(multimap<int, string> addscores)
{
	for (auto it = addscores.begin(); it != addscores.end(); it++) {
		scores.insert(make_pair(it->first, it->second));
	}	
}

void HighScores::RemoveScore()
{
	scores.clear();
}

void HighScores::RemoveScore(int pos)
{
	if (scores.size() == 0 || scores.size() < pos) return;

	multimap <int, string>::iterator it_delete = scores.begin();;
	advance(it_delete, pos-1);
	scores.erase(it_delete);
}

void HighScores::RemoveScore(string name)
{
	multimap <int, string>::iterator it_delete;
	for (it_delete = scores.begin(); it_delete != scores.end();)
	{
		if (it_delete->second == name) {
			auto it_aux = it_delete;
			it_aux++;
			scores.erase(it_delete);	
			it_delete = it_aux;
		}
		else {
			it_delete++;
		}
	}
}

multimap<int, string> HighScores::GetScore(int pos)
{
	multimap<int, string> getscores;
	if (scores.size() == 0 || scores.size() < pos) return getscores;

	multimap <int, string>::iterator it_get;
	it_get = scores.begin();
	advance(it_get, pos-1);	
	getscores.insert(make_pair(it_get->first, it_get->second));
	return getscores;
}

multimap<int, temp> HighScores::GetScore(int *pos, int sizePos)
{
	multimap <int, string>::iterator it_get;
	multimap <int, temp> scoreReturn;
	for (size_t i = 0; i < sizePos; i++)
	{
		it_get = scores.begin();
		advance(it_get, pos[i]-1);
		multimap <int, string> test; 
		test.insert(make_pair(it_get->first, it_get->second));
		scoreReturn.insert(make_pair(pos[i], test));
		test.clear();
	}		
	return scoreReturn;
}
//
//void HighScores::GetScore(int pos[], multimap <string, int>& scoreReturn)
//{
//	multimap <string, int>::iterator it_delete;
//	int sizePos = *(&pos + 1) - pos;
//	for (size_t i = 0; i < sizePos; i++)
//	{
//		it_delete = scores.begin();
//		advance(it_delete, pos[i]);
//		scoreReturn.insert(make_pair(it_delete->first, it_delete->second));
//	}
//}

//multimap<string, int> HighScores::GetScore(string name)
//{
//	multimap<string, int> getscores;
//	typedef multimap<string, int>::iterator it_scores;
//	pair<it_scores, it_scores> result = scores.equal_range(name);
//	for (it_scores it = result.first; it != result.second; it++) {
//		getscores.insert(make_pair(it->first, it->second));
//	}
//	return getscores;
//}
//
//void HighScores::GetScore(string name, multimap<string, int>& getscores)
//{
//	typedef multimap<string, int>::iterator it_scores;
//	pair<it_scores, it_scores> result = scores.equal_range(name);
//	for (it_scores it = result.first; it != result.second; it++) {
//		getscores.insert(make_pair(it->first, it->second));
//	}
//}

void HighScores::PrintScores()
{	
	int i = 1;
	cout << "!-!-!-!-!-!-!-!-!- HIGHSCORES !-!-!-!-!-!-!-!-!-!-!-!" << endl;
	for (auto it = scores.begin(); it != scores.end(); it++)
	{		
		cout << "|-| Top " << i << ": " << it->first << " |-| Score: " << it->second << endl;
		i++;
	}
}
