// #include "Aufbau.h"
#include "stdafx.h"
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <assert.h>
#include <Windows.h>
#include <string>

class User {
	// Silas
	int score;
	std::string player_name;
public:
	void set_score(const int& s) {
		this->score = s;
	}

	void set_name(const std::string& n) {
		this->player_name = n;
	}

	std::string get_playername() {
		return this->player_name;
	}

	int get_score() {
		return this->score;
	}
};

class Settings : public User {
	int gamespeed;
	int victim_color;
public:
	void set_gamespeed(const int& gs) {
		this->gamespeed = gs;
	}
	void set_victim_color(const int& vc) {
		this->victim_color = vc;
	}

	int get_gamespeed() {
		return this->gamespeed;
	}
	int get_victim_color() {
		return this->victim_color;
	}
	// aus Elternklasse
	void set_changedname(const std::string &changedname) {
		this->set_name(changedname);	// Hallo Fabian
	}

	std::string get_changendname() {
		return this->get_playername();
	}
};







/*

using namespace std;

// Globale Variablen
//int color_victims;
//int gamespeed;

struct playerscore {
	int score;
	string name;
};

// Überladen des Streamingoperators
// istream& operator>>(istream& stream, playerscore& rl);

// Funktionsdeklaration
string ablauf_start();
void ablauf_mainmenue();
void ablauf_game();
string ablauf_changename();
void ablauf_ranking(vector<playerscore> ranking_list);
void ablauf_setting();
void ablauf_exit();

void fkt_navigation(int ort);
// bool fkt_check_name(string new_name);
void fkt_reset_rankinglist();
void fkt_after_the_game(int value, string name, vector<playerscore>& a);
void fkt_print_ranking(vector<playerscore>& a);
void fkt_rankingsort(vector<playerscore>& a);
// void fkt_init_from_file(vector<playerscore>& a);
// void fkt_update_the_file(vector<playerscore>& a);
void fkt_change_character();
void fkt_get_playername();
*/