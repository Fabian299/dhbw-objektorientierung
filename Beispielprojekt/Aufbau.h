
#include "stdafx.h"
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <assert.h>
#include <Windows.h>
#include <string>
// #include "objects.H"
// #include "Klassen.h"

#pragma once

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
    int victim_color_red;
    int victim_color_green;
    int victim_color_blue;
    bool character; // 0 - Mario, 1- Luigi
    //int TopTenRanking[10];
    //string TopTenPlayer[10];
public:
    Settings() {	// Konstruktor
        gamespeed = 10;
        victim_color_red = 255;
        victim_color_green = 0;
        victim_color_blue = 0;
        character = 0;
    };
    ~Settings() {};

    int get_gamespeed();
    void set_gamespeed(const int gs);
    int get_victim_color_red();
    void set_victim_color_red(const int vcr);
    int get_victim_color_green();
    void set_victim_color_green(const int vcg);
    int get_victim_color_blue();
    void set_victim_color_blue(const int vcb);


    void set_charakter(bool charakter);
    bool get_charakter();




};

