
//#include "stdafx.h"
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <assert.h>
#include <Windows.h>
#include <string>

using namespace std;

class User {
private:
    // Silas
    int score;
    string player_name;
public:
    User() {
        score = 0;
        player_name = "Hansi";
    };
    ~User() {};

    void set_score(const int s);
    int get_score();
    void set_name(const std::string n);
    string get_name();
};


class Settings {
private:
    int gamespeed;
    int victim_color;
    bool character; // 0 - Mario, 1- Luigi
    //int TopTenRanking[10];
    //string TopTenPlayer[10];
public:
    Settings() {	// Konstruktor
        gamespeed = 10;
        victim_color = 2;
        character = 0;
        //TopTenRanking= { 0,0,0,0,0,0,0,0,0,0 };
        //TopTenPlayer={"Silas", "Fabse", "Silas", "Fabse", "Silas", "Fabse","Silas", "Fabse", "Silas", "Fabse"};
    };
    ~Settings() {};

    int get_gamespeed();
    void set_gamespeed(const int gs);
    int get_victim_color();
    void set_victim_color(const int vc);
    void set_charakter(bool charakter);
    bool get_charakter();

    //void set_rankinglist(const int Userscore, const char Username);
    //int get_rankinglist();
    //void print_rankinglist();


};

