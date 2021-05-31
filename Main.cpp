#include <iostream>
#include <map>
#include "HighScores.h"

typedef multimap <int, string> temp;

int main() {
	//Creating class with constructor
	HighScores puntajes = HighScores({ {10, "Noob1"},{15, "Noob2"},{20, "Noob3"} });
	puntajes.PrintScores();
	//Deleting all scores
	puntajes.RemoveScore();
	puntajes.PrintScores();
	//Adding one score
	puntajes.AddScore("Nico", 100);
	//Adding multiple scores
	multimap<int, string> addscores = { {200, "Nicol"},{25, "Nicola"},{150, "Nico"} };
	puntajes.AddScore(addscores);	
	puntajes.PrintScores();		
	//Delete element in x position
	puntajes.RemoveScore(1);
	puntajes.PrintScores();
	//Delete all elements associated to that name
	puntajes.RemoveScore("Nico");
	puntajes.PrintScores();
	//Get score in x position
	puntajes.AddScore(addscores);
	puntajes.AddScore(addscores);
    puntajes.PrintScores();
	puntajes.PrintScores(puntajes.GetScore(4));
	//Get scores in various positions	
	int positions[] = { 2, 4, 6 };
	puntajes.PrintScores(puntajes.GetScore(positions, *(&positions + 1) - positions));
	//Recieves multimap reference and insert data there with multiple positions
	multimap<int, string, greater<int>> scoreReturn;
	int anotherpositions[] = { 1, 2, 5 };
	puntajes.GetScore(anotherpositions, scoreReturn, *(&anotherpositions + 1) - anotherpositions);
	puntajes.PrintScores(scoreReturn);
	////Get all the scores from the same name
	puntajes.PrintScores(puntajes.GetScore("Nicola"));
	////Get all the scores from the same name using a referenced multimap
	multimap<int, multimap<int, string, greater<int>>> getscores;
	puntajes.GetScore("Nico", getscores);
	puntajes.PrintScores(getscores);

	system("pause");
	return 0;
}



