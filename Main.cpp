#include <iostream>
#include "HighScores.h";

int main() {

	HighScores puntajes = HighScores({ {10, "Noob1"},{15, "Noob2"},{20, "Noob3"} });
	//Adding one score
	puntajes.AddScore("Nico", 100);
	//Adding multiple scores
	multimap<int, string> addscores = { {200, "Nicol"},{25, "Nicola"},{150, "Nico"} };
	puntajes.AddScore(addscores);
	//Print Top 10 HighScores
	puntajes.PrintScores();


	system("pause");
	return 0;
}