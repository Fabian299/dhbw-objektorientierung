#include <iostream>
#include <thread>
#include <string>
#include <vector>


using namespace std;

// Globale Variablen
enum { mainmenue, game, changeplayer, ranking, setting };
int enum_ort;
string player_name;
int color_victims;
int gamespeed;

struct playerscore {
	int score;
	string name;
};
// �berladen des Streamingoperators
istream& operator>>(istream& stream, rankinglist& rl) {
	stream >> rl.score;
	char op;
	stream >> op;
	assert(op == '\t');
	stream >> rl.name;
	// char op2;				// Evtl wenn man in txt auch Iterator haben m�chte, als "Ranking" in der txt-Datei
	// assert(op2 == "\t");
	return stream;
}

// Funktionsdeklaration
void ablauf_start();
void ablauf_mainmenue();
void ablauf_game();
string ablauf_changename();
void ablauf_ranking();
void ablauf_setting();
void ablauf_exit();

void fkt_navigation(int ort);
bool fkt_check_name(string new_name);
void fkt_reset_rankinglist();
void fkt_after_the_game(int value, string name, vector<playerscore>& a);
void fkt_print_ranking(vector<playerscore>& a);
void fkt_rankingsort(vector<playerscore>& a);
void fkt_init_from_file(vector<playerscore>& a);
void fkt_update_the_file(vector<playerscore>& a);
void fkt_change_character();


int main() {
	ablauf_start();
	vector<playerscore> ranking_list = { };
	// rankingsort(rankinglist);
	// print_ranking(ranking_list);
}

// Funktionsdefinition
ablauf_start() {
	cout << "Das Spiel wird ge�ffnet." << endl;
	cout << "Bitte warten" << endl;
	_sleep(2);
	cout << "..." << endl;
	_sleep(2);
	cout << "..." << endl;
	_sleep(2);
	cout << "Bitte geben Sie ihren Namen ein" << endl;
	cin >> player_name;
	// ---------------------
	ablauf_mainmenue();
}

ablauf_mainmenue() {
	enum_ort = mainmenue; // 1
	fkt_navigation(enum_ort);
	cout << "With the '1' you can start the game.\nWith the '2' you can change your name." << endl;
	cout << "With the '3' you can see the best player.\n With the '4' you can change the settings" << endl;
	cout << "With the '0' you exit the programm. \n\n" << endl;
	_sleep(1);
	cout << "\n What do you want?" << endl;
	char eingabe = cin.get();
	if (eingabe == "1") ablauf_game();
	if (eingabe == "2") player_name = ablauf_changename();
	if (eingabe == "3") ablauf_ranking();
	if (eingabe == "4") ablauf_setting();
	if (eingabe == "0") ablauf_exit();
	else ablauf_mainmenue();
}

ablauf_game() {
	enum_ort = game; // 2
	fkt_navigation(enum_ort);

	// START GAME		--> Befehl f�r beenden

	// Irgendwie wenn ende, dann 1 f�r restart , 0 f�r mainmenue
}

ablauf_changename() {
	enum_ort = changeplayer; // 3
	fkt_navigation(enum_ort);

	string changed_name;
	cin << changed_name;
	if (fkt_check_name(changed_name) ablauf_changename();		// Fehler bei 1 --> Neustart der Seite

		cout << "Change successfull" << endl;
		_sleep(1);
		return changed_name;
		// ablauf_mainmenue();	//											-------------??????---------------
}

ablauf_ranking() {
	enum_ort = ranking; // 4
		fkt_navigation(enum_ort);

		// Zeige den / die beste Spieler an
		system("pause");
	ablauf_mainmenue();
}

ablauf_setting() {
	enum_ort = setting; // 5
	fkt_navigation(enum_ort);
	cout << "Press '1' to reset the rankinglist. Press '2' to change the character.\nPress '0' for exit the settings" << endl;

	char eingabe = cin.get();
	if (eingabe == "1") fkt_reset_rankinglist();
	if (eingabe == "2") fkt_change_character();
	if (eingabe == "0") ablauf_mainmenue();
	else ablauf_setting();

	cout << "\n\n\n!!HIER GEHT NOCH NICHTS" << endl;
}

ablauf_exit() {
	cout << "You exit the game. Thank you for using it. We hope we will see you another time.\n" << endl;
	cout << "Best regard from Fabian and Silas!" << endl;
	_sleep(1);
	void exit(					// Programm schlie�en
		int const status
	);
}

fkt_navigation(int ort) {
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

fkt_check_name(string new_name) {
	for (int i = 0; i < strlen(new_name); i++)
	{
		if (new_name[i] == "\t") return true;
		else ++i;
	}
	return false;
}

fkt_reset_rankinglist() {
	ofstream f("Rankinglist.txt", ios::trunc);		//ios::trunc leert die Datei
	cout << "Rankinglist is reseted" << endl;
}

fkt_after_the_game(int value, string name, vector<playerscore>& a) {
	if (value > a.at(9).score) cout << "You are not in the Top 10" << endl;
	else {
		rankingsort(a);
		if (value == a.at(0).score) cout << "Congratulation. You are the HIGHSCORE !!" << endl;
		else cout << "Congratulation! You are in the Top 10" << endl;
		playerscore new_entry = { value, name };				// des evtl schon au�erhalb, anderer Name der Fkt..
		a.push_back(new_entry);		// danach Sortaufruf
	}

	while (a.size >= 100) a.pop_back;	// Nur besten 100, schlechter wird gel�scht
}

fkt_print_ranking(const vector <playerscore>& a)
{
	for (int elem = 1; elem < 11; elem++)
	{
		if (elem < a.size) cout << elem << ". Platz\t" << rankinglist.at(elem).name << "\t Score: " << rankinglist.at(elem).score << endl;
	}
}

fkt_rankingsort(vector <playerscore>& a)
{
	bool sorted = false;
	//n-1 Sortierdurchl�ufe von n-1 bis 1
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
				int temp = a.at(i);
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
}

// Vector erg�nzen bzw kompletter (geordneter) Vector �berschreiben.

void fkt_update_the_file(vector<playerscore>& a) {
	ofstream f("Rankinglist.txt", ios::trunc);		// Datei leermachen
	if (!f) cout << "Error. Can't open the file." << endl;
	else {											// Vector schreiben
		for (vector<playerscore> vec : a)
		{
			/* ostream& operator<<(ostream & stream, const rankingliste &rl) {
				return stream << k.real << "+" << k.imag << "i";
			} */
			f << vec->score << "\t" << vec->name << endl;
		}
	}
}

fkt_change_character() {
	system.("cls");
	cout << "You want change your character?" << endl;
	cout << "Press '1' for Mario, Press '2' for Luigi.\nPress '0' to return to the settings." << endl;
	char eingabe = cin.get();
	if (eingabe == "1") character = Mario;
	if (eingabe == "2") character = Luigi;
	if (eingabe == "0") ablauf_setting();
	else fkt_change_character();
}