#include <iostream>
#include "HighScores.h";

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

	system("pause");
	return 0;
}