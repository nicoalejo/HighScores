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
	//Empty Constructor 
	HighScores();
	//Constructor recieving a multimap with scores
	HighScores(multimap<int, string> addscores);
	//Adds new score
	void AddScore(string name, int score);
	////Add multiple scores
	void AddScore(multimap<int, string> addscores);
	////Delete all elements
	//void RemoveScore();
	////Delete element in x position
	//void RemoveScore(int pos);
	////Delete all elements associated to that name
	//void RemoveScore(string name);
	////Get score in x position
	//multimap<string, int> GetScore(int pos);
	////Get scores in various positions
	//multimap<string, int> GetScore(int pos[]);
	////Recieves multimap reference and insert data there
	//void GetScore(int pos[], multimap<string, int>& scoreReturn);
	////Get all the scores from the same name
	//multimap<string, int> GetScore(string name);
	////Get all the scores from the same name using a referenced multimap
	//void GetScore(string name, multimap<string, int>& getscores);
	//Print top 10 Scores
	void PrintScores();

};

