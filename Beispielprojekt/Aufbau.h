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
// Überladen des Streamingoperators
istream& operator>>(istream& stream, rankinglist& rl);

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
