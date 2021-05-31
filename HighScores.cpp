#include "HighScores.h"
#include <iostream>
#include <map>

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

multimap<int, temp> HighScores::GetScore(int pos)
{
	multimap<int, string> getscore;
	multimap <int, temp> scoreReturn;
	if (scores.size() == 0 || scores.size() < pos) return scoreReturn;

	multimap <int, string>::iterator it_get;
	it_get = scores.begin();
	advance(it_get, pos-1);	
	getscore.insert(make_pair(it_get->first, it_get->second));
	scoreReturn.insert(make_pair(pos, getscore));
	return scoreReturn;
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

void HighScores::GetScore(int* pos, multimap <int, string, greater<int>>& scoreReturn, int sizePos)
{
	multimap <int, string>::iterator it_delete;
	for (size_t i = 0; i < sizePos; i++)
	{
		it_delete = scores.begin();
		advance(it_delete, pos[i]-1);
		scoreReturn.insert(make_pair(it_delete->first, it_delete->second));
	}
}

multimap<int, pair<int, string>> HighScores::GetScore(string name)
{
	multimap<int, pair<int, string>> returnScores;
	multimap<int, string>::iterator it_scores;
	int count = 1;
	for (it_scores = scores.begin(); it_scores != scores.end(); it_scores++)
	{
		if (it_scores->second == name) {
			returnScores.insert(make_pair(count, make_pair(it_scores->first, it_scores->second)));
		}
		count++;
	}
	return returnScores;
}

void HighScores::GetScore(string name, multimap<int, multimap<int, string, greater<int>>>& returnScores)
{
	multimap<int, string>::iterator it_scores;
	int count = 1;
	for (it_scores = scores.begin(); it_scores != scores.end(); it_scores++)
	{
		if (it_scores->second == name) {
			multimap<int, string, greater<int>> temp;
			temp.insert(make_pair(it_scores->first, it_scores->second));
			returnScores.insert(make_pair(count, temp));
			temp.clear();
		}
		count++;
	}
}

void HighScores::PrintScores()
{	
	int i = 1;
	cout << "!-!-!-!-!-!-!-!-!- HIGHSCORES !-!-!-!-!-!-!-!-!-!-!-!" << endl;
	for (auto it = scores.begin(); it != scores.end(); it++)
	{		
		cout << "|-| Top " << i << ": " << it->second << " |-| Score: " << it->first << endl;
		i++;
	}
}

void HighScores::PrintScores(multimap<int, string> score) {
	int i = 1;
	cout << "!-!-!-!-!-!-!-!-!- HIGHSCORES !-!-!-!-!-!-!-!-!-!-!-!" << endl;
	for (auto it = score.begin(); it != score.end(); it++)
	{
		cout << "|-| Top " << i << ": " << it->second << " |-| Score: " << it->first << endl;
		i++;
	}
}

void HighScores::PrintScores(multimap<int, temp> score) {
	cout << "!-!-!-!-!-!-!-!-!- HIGHSCORES !-!-!-!-!-!-!-!-!-!-!-!" << endl;
	for (auto it = score.begin(); it != score.end(); it++)
	{
		cout << "|-| Top " << it->first << ": ";
		multimap<int, string>& internal_map = it->second;
		for (auto it2 = internal_map.begin(); it2 != internal_map.end(); it2++) {
			cout << it2->second << " |-| Score: " << it2->first <<endl;
		}			
	}
}

void HighScores::PrintScores(multimap<int, string, greater<int>> score) {
	int i = 1;
	cout << "!-!-!-!-!-!-!-!-!- HIGHSCORES !-!-!-!-!-!-!-!-!-!-!-!" << endl;
	for (auto it = score.begin(); it != score.end(); it++)
	{
		cout << "|-| Top " << i << ": " << it->second << " |-| Score: " << it->first << endl;
		i++;
	}
}

void HighScores::PrintScores(multimap<int, pair<int, string>> score) {
	cout << "!-!-!-!-!-!-!-!-!- HIGHSCORES !-!-!-!-!-!-!-!-!-!-!-!" << endl;
	for (auto it = score.begin(); it != score.end(); it++)
	{
		cout << "|-| Top " << it->first << ": ";
		pair<int, string>& internal_map = it->second;
		cout << internal_map.second << " |-| Score: " << internal_map.first << endl;		
	}
}
void HighScores::PrintScores(multimap<int, multimap<int, string, greater<int>>> score) {
	cout << "!-!-!-!-!-!-!-!-!- HIGHSCORES !-!-!-!-!-!-!-!-!-!-!-!" << endl;
	for (auto it = score.begin(); it != score.end(); it++)
	{
		cout << "|-| Top " << it->first << ": ";
		multimap<int, string, greater<int>>& internal_map = it->second;
		for (auto it2 = internal_map.begin(); it2 != internal_map.end(); it2++) {
			cout << it2->second << " |-| Score: " << it2->first << endl;
		}
	}
}