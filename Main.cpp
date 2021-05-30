#include <iostream>
#include "HighScores.h";
typedef multimap <int, string> temp;
void PrintScores(const multimap<int, string> scores);
void PrintScores(const multimap<int, temp> scores);

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
	////Get score in x position
	puntajes.AddScore(addscores);
	puntajes.AddScore(addscores);
    puntajes.PrintScores();
	PrintScores(puntajes.GetScore(4));
	
	////Get scores in various positions	
	int positions[] = { 2, 4, 6 };
	PrintScores(puntajes.GetScore(positions, *(&positions + 1) - positions));
	////Recieves multimap reference and insert data there
	//void GetScore(int pos[], multimap<string, int>& scoreReturn);
	////Get all the scores from the same name
	//multimap<string, int> GetScore(string name);
	////Get all the scores from the same name using a referenced multimap
	//void GetScore(string name, multimap<string, int>& getscores);

	system("pause");
	return 0;
}

void PrintScores(multimap<int, string> scores) {
	int i = 1;
	cout << "!-!-!-!-!-!-!-!-!- HIGHSCORES !-!-!-!-!-!-!-!-!-!-!-!" << endl;
	for (auto it = scores.begin(); it != scores.end(); it++)
	{
		cout << "|-| Top " << i << ": " << it->first << " |-| Score: " << it->second << endl;
		i++;
	}
}

void PrintScores(multimap<int, temp> score) {
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
