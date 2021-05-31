#pragma once
#include <iostream>
#include <map>

/* AddScore()
   RemoveScore()
   GetScore()
   PrintScore()
*/
using namespace std;

class HighScores
{
private:
	multimap<int, string, greater<int>> scores;
	
public:
	typedef multimap <int, string> temp;
	//Empty Constructor 
	HighScores();
	//Constructor recieving a multimap with scores
	HighScores(multimap<int, string> addscores);
	//Adds new score
	void AddScore(string name, int score);
	////Add multiple scores
	void AddScore(multimap<int, string> addscores);
	////Delete all elements
	void RemoveScore();
	////Delete element in x position
	void RemoveScore(int pos);
	////Delete all elements associated to that name
	void RemoveScore(string name);
	////Get score in x position
	multimap<int, temp> GetScore(int pos);
	////Get scores in various positions
	multimap<int, temp> GetScore(int *pos, int count);
	//Recieves multimap reference and insert data there
	void GetScore(int* pos, multimap<int,  string, greater<int>>& scoreReturn, int sizePos);
	////Get all the scores from the same name
	multimap<int, pair<int, string>> GetScore(string name);
	//Get all the scores from the same name using a referenced multimap
	void GetScore(string name, multimap<int, multimap<int, string, greater<int>>>& getscores);
	//Print top 10 Scores
	void PrintScores();
	//Different Print Forms
	void PrintScores(multimap<int, string> score);
	void PrintScores(multimap<int, temp> score);
	void PrintScores(multimap<int, string, greater<int>> score);
	void PrintScores(multimap<int, pair<int, string>> score);
	void PrintScores(multimap<int, multimap<int, string, greater<int>>> score);

};

