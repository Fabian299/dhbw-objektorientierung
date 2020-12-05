
#include "stdafx.h"
#include "Aufbau.h"



using namespace std;

// Globale Variable
typedef enum { mainmenue, game, changeplayer, ranking, setting } enum_ort;

// Definitionen der Klassenmethode
void User::set_score(const int s) {
    this->score = s;
};
int User::get_score() {
    return this->score;
};
void User::set_name(const std::string n) {
    this->player_name = n;
};
string User::get_name() {
    return this->player_name;
};


// ---------------------Settings ---------------------------------


int Settings::get_gamespeed() {
    return this->gamespeed;
}
void Settings::set_gamespeed(const int gs) {
    this->gamespeed = gs;
}
int Settings::get_victim_color() {
    return this->victim_color;
}
void Settings::set_victim_color(const int vc) {
    this->victim_color = vc;
}

bool Settings::get_charakter() {
    if (this->character)
        return true;
    else
        return false;
}

void Settings::set_charakter(bool charakter) {
    this->character = charakter;
}
/*
void Settings::set_rankinglist(const int Userscore) {
    int TopTen[] = this->TopTenRanking;
    if (Userscore > this->TopTenRanking[9][1]){	// Name , Score
        // einfügen
        for(int i = 8; i>=0; i--){
            if(Userscore<this->TopTenRanking[i]) {
                this->TopTen[i+1]=Userscore;
                i=0;
                break;  // reicht 1 break um aus der Vorschleife zu kommen?
            }
        }
        // break;
    }
    else
    {
        cout <<"You are stupid as fuck" << endl;	// Ausgabe noch freundlich machen
    }
    //this->TopTenRanking = TopTen,
};

int[10] Settings::get_rankinglist(){
    return this->TopTenRanking;
}

int Settings::print_rankinglist(){
    int TopTenScores[10];
    TopTenScores = get_rankinglist();
    for (int i = 0; i < 10; i++) {
        cout << "\tScore: " << TopTenScores[i] << endl;
    }
}*/