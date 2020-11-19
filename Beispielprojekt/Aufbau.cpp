#include "Aufbau.h"
#include "stdafx.h"
#include "objects.H"


using namespace std;

// Globale Variable
//typedef enum { mainmenue, game, changeplayer, ranking, setting } enum_ort;

/*
int main() {
	ablauf_start();

	// After game 
	// /*
	int value = 3;
	fkt_after_the_game(value, player_name, ranking_list);
	// 

}	*/


// Globale Variablen

// Überladen des Streamingoperators 
/*
istream& operator>>(istream& stream, playerscore& rl) {
	stream >> rl.score;
	char op;
	stream >> op;
	assert(op == '\t');
	stream >> rl.name;
	// char op2;				// Evtl wenn man in txt auch Iterator haben möchte, als "Ranking" in der txt-Datei
	// assert(op2 == "\t");
	return stream;
} */



// Funktionsdefinition
string ablauf_start() {
	cout << "Das Spiel wird geöffnet." << endl;
	//	ifstream f("Rankinglist.txt");
	//	if (f) fkt_init_from_file(ranking_list);
	cout << "Bitte warten" << endl;
	// _sleep(2);
	cout << "..." << endl;
	// _sleep(2);
	cout << "..." << endl;
	// _sleep(2);
	cout << "Bitte geben Sie ihren Namen ein" << endl;
	string player_name;
	cin >> player_name;
	return player_name;
	// ---------------------
	ablauf_mainmenue();
}

void ablauf_mainmenue() {
	enum_ort Ort = mainmenue; // 1
	fkt_navigation(Ort);
	cout << "With the '1' you can start the game.\nWith the '2' you can change your name." << endl;
	cout << "With the '3' you can see the best player.\n With the '4' you can change the settings" << endl;
	cout << "With the '0' you exit the programm. \n\n" << endl;
	// _sleep(1);
	cout << "\n What do you want?" << endl;
	char eingabe = cin.get();
	if (eingabe == '1') ablauf_game();
	if (eingabe == '2') player_name = ablauf_changename();
	if (eingabe == '3') ablauf_ranking();
	if (eingabe == '4') ablauf_setting();
	if (eingabe == '0') ablauf_exit();
	else ablauf_mainmenue();
}

void ablauf_game() {
	enum_ort Ort = game; // 2
	fkt_navigation(Ort);
	//	mode = running
	//	GameWindow window;
	//	window.show();
}

string ablauf_changename() {
	enum_ort Ort = changeplayer; // 3
	fkt_navigation(Ort);

	string changed_name;
	cin >> changed_name;
	//	if (fkt_check_name(changed_name)) ablauf_changename();		// Fehler bei 1 --> Neustart der Seite

	cout << "Change successfull" << endl;
	//		_sleep(1);
	return changed_name;
	// ablauf_mainmenue();	//											-------------??????---------------
}

void ablauf_ranking(vector<playerscore> ranking_list) {
	enum_ort Ort = ranking; // 4
	fkt_navigation(Ort);

	fkt_print_ranking(ranking_list);
	system("pause");
	ablauf_mainmenue();
}

void ablauf_setting() {
	enum_ort Ort = setting; // 5
	fkt_navigation(Ort);
	cout << "Press '1' to reset the rankinglist. Press '2' to change the character.\nPress '0' for exit the settings" << endl;

	char eingabe = cin.get();
	if (eingabe == '1') fkt_reset_rankinglist();
	if (eingabe == '2') fkt_change_character();
	if (eingabe == '3') ablauf_mainmenue();
	else ablauf_setting();

	cout << "\n\n\n!!HIER GEHT NOCH NICHTS" << endl;
}

void ablauf_exit() {
	cout << "You exit the game. Thank you for using it. We hope we will see you another time.\n" << endl;
	cout << "Best regard from Fabian and Silas!" << endl;
	// _sleep(1);
//	void exit(					// Programm schließen
//		int const status
//	);
}

void fkt_navigation(int ort) {
	system("cls");
	switch (ort)
	{
	case 1:	cout << "Mainmenue" << endl;
		cout << "----------\n\n" << endl;

	case 2: cout << "Game - please change the window" << endl;
		cout << "----------\n\n" << endl;
	case 3: cout << "You are changing your name. What's your name?" << endl;
		cout << "----------\n\n" << endl;
	case 4: cout << "Ranking - Who's the best player?" << endl;
		cout << "----------\n\n" << endl;
	case 5: cout << "Settings" << endl;
		cout << "----------\n\n" << endl;
	default: cout << endl;
	}
}

/* bool fkt_check_name(string new_name) {
	for (int i = 0; i < strlen(new_name); i++)
	{
		if (new_name[i] == '\t') return true;
		else ++i;
	}
	return false;
} */

void fkt_reset_rankinglist() {
	//	ofstream f("Rankinglist.txt", ios::trunc);		//ios::trunc leert die Datei
	cout << "Rankinglist is reseted" << endl;
}

void fkt_after_the_game(int value, string name, vector<playerscore>& a) {
	if (value > a.at(9).score) cout << "You are not in the Top 10" << endl;
	else {
		fkt_rankingsort(a);
		if (value == a.at(0).score) cout << "Congratulation. You are the HIGHSCORE !!" << endl;
		else cout << "Congratulation! You are in the Top 10" << endl;
		playerscore new_entry = { value, name };				// des evtl schon außerhalb, anderer Name der Fkt..
		a.push_back(new_entry);
		fkt_rankingsort(a);
		// fkt_update_the_file();
	}

	while (a.size() >= 100) a.pop_back();	// Nur besten 100, schlechter wird gelöscht
}

void fkt_print_ranking(const vector <playerscore>& a)
{
	for (int elem = 1; elem < 11; elem++)
	{
		if (elem < a.size()) cout << elem << ". Platz\t" << a.at(elem).name << "\t Score: " << a.at(elem).score << endl;
	}
}

void fkt_rankingsort(vector <playerscore>& a)
{
	bool sorted = false;
	//n-1 Sortierdurchläufe von n-1 bis 1
	size_t j = a.size() - 1;
	while ((j > 0) && (sorted == false))
	{
		sorted = true; //Annahme, a sei schon sortiert
		//Ein Sortierdurchlauf von 0 bis j-1
		for (size_t i = 0; i < j; i++)
		{
			if (a.at(i + 1).score < a.at(i).score)
			{
				//Elemente i und i+1 vertauschen
				int temp = a.at(i).score;
				a.at(i).score = a.at(i + 1).score;
				a.at(i + 1).score = temp;
				//da Vertauschung notwendig, ist a evtl. noch nicht sortiert
				sorted = false;
			}
		}
		j = j - 1;
	}
}

// Ranglistenvector aus Textdatei initialisieren --> Am Anfang des Programms (-start)
/*
fkt_init_from_file(vector<playerscore>& a) {
	ifstream f("Rankinglist.txt");
	if (!f) cout << "Error. Can't open the file." << endl;
	else {   // Lesen ...
		a.clear();
		string line;
		while (getline(f, line))
		{
			playerscore tmp;
			line >> tmp;
			a.push_back(tmp);
		}
	}
}	*/

// Vector ergänzen bzw kompletter (geordneter) Vector überschreiben.

/*
void fkt_update_the_file(vector<playerscore>& a) {
//	ofstream f("Rankinglist.txt", ios::trunc);		// Datei leermachen											// Vector schreiben
		for (vector<playerscore> vec : a)
		{
//			f << vec.score << "\t" << vec.name << endl;
		}

} */

void fkt_change_character() {
	system("cls");
	cout << "You want change your character?" << endl;
	cout << "Press '1' for Mario, Press '2' for Luigi.\nPress '0' to return to the settings." << endl;
	char eingabe = cin.get();
	if (eingabe == '1') // character = Mario;
		if (eingabe == '2') // character = Luigi;
			if (eingabe == '0') ablauf_setting();
			else fkt_change_character();
}

void fkt_get_playername() {
	
}


