#include "stdafx.h"
#include "Vektor2d.h"
#include "objects.h"
#include "Aufbau.h"
#include <iostream>
using namespace std;
// Simulationsgeschwindigkeit
const double DT = 100.0;

// vector<playerscore> ranking_list = { };
// string player_name;

// Funktionsdeklaration
void spielstart();
void UserinterfaceHM();
void rankingliste();
void settingfkt(Settings mySetting);
Settings mySetting;

// Globale Variablen
std::string myscore[10][2]; 



 character Character = Mario;
 player Figur(Mario, 100, 400, 32, 130);
 objects Hinderniss(0, 300, 50);
 uint16_t layer = 400;
 uint16_t score = 0;

 class GameWindow : public Gosu::Window
 {
 public:
 	Gosu::Image bild;
 	GameWindow()
 		: Window(800, 600),
        bild(Figur.get_picpath())
 	{
 		set_caption("Fabian and Silas wonderfull Game");
 	}

// 	// wird bis zu 60x pro Sekunde aufgerufen.
// 	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
// 	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
 	void draw() override
 	{
 		Gosu::Graphics::draw_rect(0, 400, 800, 200, Gosu:: Color::Color(20, 200, 20), 0);
        Gosu::Graphics::draw_rect((600-Hinderniss.get_PosX()), Hinderniss.get_PosY(), Hinderniss.get_Radius(), 200, Gosu::Color::Color(20, 200, 20), 0);
        bild.draw_rot(Figur.get_PosX(), Figur.get_PosY(), 1, 0, //Position, Layer, angle
            0.5, 1,      //center
            0.1, 0.1     //scale
        );
 		//Gosu::Font(string_menü);
 		/*switch (mode) {

 			case
 			default
 		}*/
 	}

// 	// Wird 60x pro Sekunde aufgerufen
 	void update() override
 	{
 		if (Gosu::Input::down(Gosu::ButtonName::KB_LEFT_CONTROL)) {
 			Figur.set_boost();
 		}
 		else {
 			Figur.reset_boost();
 		}
 		if (Gosu::Input::down(Gosu::ButtonName::KB_RIGHT)) {
 			//std::cout << "->" << std::endl;
 			Figur.set_PosX(Figur.get_PosX() + Figur.get_speed() / 60);
            if (Figur.get_PosX() == 401) {
                score++;
                Hinderniss.set_PosX(Hinderniss.get_PosX() + 1);
                Figur.set_PosX(400);
            };
 		}
 		if (Gosu::Input::down(Gosu::ButtonName::KB_LEFT)) {
 			//std::cout << "<-" << std::endl;
 			Figur.set_PosX(Figur.get_PosX() - Figur.get_speed() / 60);
 		}
 		if (Gosu::Input::down(Gosu::ButtonName::KB_UP)) {
 			//std::cout << "^" << std::endl;
 			Figur.do_jump();
 		}
        if (Hinderniss.get_PosX() > 800) {
            Hinderniss.set_PosX(0);
        }
        if (((Figur.get_PosX() + Figur.get_Radius()) > (600 - Hinderniss.get_PosX() - Hinderniss.get_Radius()) && ((Figur.get_PosX() - Figur.get_Radius()) < (600 + Hinderniss.get_PosX() + Hinderniss.get_Radius())) {
            layer = Hinderniss.get_PosY;
        }
        else {
            layer = 400;
        }
 		Figur.flight(layer);
 	}
 };

// // 

 
 int main() {
     std::cout << "Hello, World!" << std::endl;
     Settings mySetting;
     User myUser;
     string eingabe;
     cout << "Hello How you name?" << endl;
     cin >> eingabe;
     myUser.set_name(eingabe);
     cout << "Dein Name ist: " << myUser.get_name() << endl;

     //Hauptmenü
     // Userinterface: Hauptmenü
     while (true) {
         UserinterfaceHM();
         char eingaben;
         cin >> eingaben;
         switch (eingaben) {
         case '1': cout << "1" << endl; //Spielstarten
             spielstart();
             break;
         case '2': cout << "2" << endl; // Settings
             settingfkt(mySetting);
             break;
         case '3': cout << "3" << endl; // Rankingliste ->  SILAS
             rankingliste();
             break;
         case '4':
             return 0;
             break;
         case 'k':
             std::cout << "Easteregg gefunden. Du bist eine coole Socke!" << endl;
         default:
             cout << "Fehler" << endl;
             break;

         }
         cout << mySetting.get_gamespeed() << endl;
         /*
         mySetting.set_victim_color(3);
         std::cout << mySetting.get_victim_color()<<endl;
         mySetting.set_gamespeed(10000);
         cout << mySetting.get_gamespeed()<<endl;
          */
          //return 0;
     }
     return 0;
 }




 //void get_gamespeed();

// void set_gamespeed(const int gs);
 //void get_victim_color();

 //void set_victim_color(const int vc);
 //void set_rankinglist(const int Userscore, const char Username);
 //int get_rankinglist();
 //void print_rankinglist();

 //void set_score(const int s);
 //void get_score();
 //void set_name(const std::string n);
 //void get_name();

// Funktionendeklaration
 void spielstart() {
     cout << "Spiel startet. Bitte warten" << endl;
     GameWindow window;
     window.show();
 }

 void settingfkt(Settings mySetting) {
     bool setOpt = true;
     while (setOpt) {
         int eingabe;
         cout << endl;

         cout << "\t \t _SETTINGS " << endl;
         cout << "\t 1. COLOR OF YOUR VICTIM" << endl;
         cout << "\t 2. GAMESPEED" << endl;
         cout << "\t 3. CHARACTER" << endl;
         cout << "\t 4. RETURN TO MAIN MENU" << endl;
         cout << endl;
         cout << "Select an item number and confirm with the enter key" << endl;

         cin >> eingabe;
         switch (eingabe) {
         case 1: cout << "1" << endl;
             std::cout << "Hier kann man die Farbe auswählen" << endl;
             int farbe;
             cin >> farbe;
             mySetting.set_victim_color(farbe);
             std::cout << mySetting.get_victim_color() << endl;
             break;
         case 2: cout << "2" << endl;
             std::cout << "Hier kann man die Gamespeed auswählen" << endl;
             int gamespeed;
             cin >> gamespeed;
             mySetting.set_gamespeed(gamespeed);
             cout << mySetting.get_gamespeed() << endl;
             break;
         case 3: cout << "3" << endl;
             std::cout << "Luigi = 0, Mario = 1" << endl;
             bool Luigi;
             cin >> Luigi;
             mySetting.set_charakter(Luigi);
             cout << mySetting.get_charakter() << endl;
             break;
         case 4: cout << "3" << endl; // Exitback
             setOpt = false;
             break;
         }
     }
 };
 void rankingliste() {
 std:cout << "Hier soll die Rankingliste ausgegeben werden" << endl;
 };

 void UserinterfaceHM() {
     cout << endl;

     cout << "\t \t _MENU " << endl;
     cout << "\t 1. PLAY" << endl;
     cout << "\t 2. SETTINGS" << endl;
     cout << "\t 3. RANKING LIST" << endl;
     cout << "\t 4. EXIT" << endl;
     cout << endl;
     cout << "Select an item number and confirm with the enter key" << endl;
     //cout << "With '1' you can start the game.\nWith  '2' Settings." << endl;
     //cout << "With '3' you can see the best player. " << endl;
     //cout << "With '0' you exit the programm. \n" << endl;
 }



 // // Silas
 // std::string a1 = "With the '1' you can start the game. With the '2' you go to the settings. With the '0' you exit the programm. ";

