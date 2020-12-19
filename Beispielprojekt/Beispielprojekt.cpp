#include "stdafx.h"
#include "Vektor2d.h"
#include "objects.h"
#include "Aufbau.h"
// #include "Ufbau_new.h"
#include <iostream>
using namespace std;
// Simulationsgeschwindigkeit
const double DT = 100.0;



// Funktionsdeklaration
void spielstart();
void UserinterfaceHM();
// void rankingliste();
void settingfkt(Settings mySetting);
Settings mySetting;
User myUser;

// Globale Variablen
// std::string myscore[10][2]; 



// character Character = Mario;
 player Figur(Mario, 100, 400, 32, 130);
 objects Hinderniss(0, 300, 50);
 uint16_t layer = 400;
// uint16_t score = 0;

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
                //score++;
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
        if (((Figur.get_PosX() + Figur.get_Radius()) > (600 - Hinderniss.get_PosX() - Hinderniss.get_Radius())) && ((Figur.get_PosX() - Figur.get_Radius()) < (600 + Hinderniss.get_PosX() + Hinderniss.get_Radius()))) 
        {
            layer = Hinderniss.get_PosY();
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
     string eingabe;
     cout << "Hello How you name?" << endl;
     cin >> eingabe;
     myUser.set_name(eingabe);
     cout << "Your name is " << myUser.get_name() << endl;

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
//         case '3': cout << "3" << endl; // Rankingliste 
//             rankingliste();
//             break;
         case '4':
             return 0;
             break;
         case 'k':
             std::cout << "Easteregg gefunden. Du bist eine coole Socke!" << endl;
         default:
             cout << "Error" << endl;
             break;

         }
     }
     return 0;
 }


// Funktionendeklaration
 void spielstart() {
     cout << "Game start, please wait." << endl;

     bool luigi = mySetting.get_charakter();
     if (luigi) {
         Figur.set_name(Luigi);
     }
     else {
         Figur.set_name(Mario);
     }

     int red = mySetting.get_victim_color_red();
     int green = mySetting.get_victim_color_green();
     int blue = mySetting.get_victim_color_blue();
     objects Hinderniss(0, 300, 50, red, green, blue);

     uint16_t layer = 400;
     uint16_t score = 0;

     GameWindow window;
     window.show();

     // Nach dem Spiel
 //    myUser.set_score(hier_score_vom_Fabian);
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
             int red, green, blue;
             std::cout << "\t\t_Choose your color" << endl;
             std::cout << "\t1. red" << endl;
             std::cin >> red;
             std::cout << "\t2. green" << endl;
             std::cin >> green;
             std::cout << "\t3. blue" << endl;
             std::cin >> blue;

             mySetting.set_victim_color_red(red);
             mySetting.set_victim_color_green(green);
             mySetting.set_victim_color_blue(blue);
             
             break;
         case 2: cout << "2" << endl;
             std::cout << "Choose your gamespeed" << endl;
             int gamespeed;
             cin >> gamespeed;
             mySetting.set_gamespeed(gamespeed);
             cout << "The gamespeed is " << mySetting.get_gamespeed() << endl;
             break;
         case 3: cout << "3" << endl;
             std::cout << "Mario = 0, Luigi = 1" << endl;
             bool Luigi;
             cin >> Luigi;
             mySetting.set_charakter(Luigi);
             cout << mySetting.get_charakter() << endl;
             break;
         case 4: cout << "Return to Mainmenue" << endl; // Exitback
             setOpt = false;
             break;
         }
     }
 };
 // void rankingliste() {
 // std:cout << "Hier soll die Rankingliste ausgegeben werden" << endl;
 // };

 void UserinterfaceHM() {
     cout << endl;

     cout << "\t \t _MENU " << endl;
     cout << "\t 1. PLAY" << endl;
     cout << "\t 2. SETTINGS" << endl;
//     cout << "\t 3. RANKING LIST" << endl;
     cout << "\t 4. EXIT" << endl;
     cout << endl;
     cout << "Select an item number and confirm with the enter key" << endl;
 }

