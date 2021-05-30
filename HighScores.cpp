#include "HighScores.h"
#include <iostream>
#include <map>

//user <algoritm> y <map>

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

//void HighScores::RemoveScore()
//{
//	scores.clear();
//}
//
//void HighScores::RemoveScore(int pos)
//{
//	multimap <string, int>::iterator it_delete;
//	advance(it_delete, pos);
//	scores.erase(it_delete);
//}
//
//void HighScores::RemoveScore(string name)
//{
//	scores.erase(name);
//}

//multimap<string, int> HighScores::GetScore(int pos)
//{
//	multimap <string, int>::iterator it_delete;
//	it_delete = scores.begin();
//	advance(it_delete, pos);	
//	return { make_pair(it_delete->first, it_delete->second) };
//}
//
//multimap<string, int> HighScores::GetScore(int pos[])
//{
//	multimap <string, int>::iterator it_delete;
//	multimap <string, int> scoreReturn;
//	int sizePos = *(&pos + 1) - pos;
//	for (size_t i = 0; i < sizePos; i++)
//	{
//		it_delete = scores.begin();
//		advance(it_delete, pos[i]);
//		scoreReturn.insert(make_pair(it_delete->first, it_delete->second));
//	}		
//	return scoreReturn;
//}
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
