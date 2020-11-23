
#include"stdafx.h"
#include "Vektor2d.h"
#include "objects.h"
#include "Aufbau.h"
#include <iostream>
using namespace std;
// Simulationsgeschwindigkeit
const double DT = 100.0;

// vector<playerscore> ranking_list = { };
// string player_name;

/* Sarah Testet Sachen */

int main(){
	Settings mySetting();
	mySetting.set_victim_color(3)
	cout << mySetting.get_victim_color()<<endl;
	mySetting.set_gamespeed(10000);
	cout << mySetting.get_gamespeed()<<endl;

}

// void get_gamespeed();
		
// void set_gamespeed(const int gs);
// void get_victim_color();
		
// void set_victim_color(const int vc);
// void set_rankinglist(const int Userscore, const char Username);
// int get_rankinglist();
// void print_rankinglist();

// void set_score(const int s);
// void get_score();
// void set_name(const std::string n);
// void get_name();




// // Silas
// std::string a1 = "With the '1' you can start the game. With the '2' you go to the settings. With the '0' you exit the programm. ";



// character Character = Mario;
// player Figur(Mario, 100, 400, 32, 130);
// uint16_t score = 0;

// class GameWindow : public Gosu::Window
// {
// public:
// 	Gosu::Image bild;
// 	GameWindow()
// 		: Window(800, 600)
// 	{
// 		set_caption("Fabian and Silas wonderfull Game");
// 	}

// 	// wird bis zu 60x pro Sekunde aufgerufen.
// 	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
// 	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
// 	void draw() override
// 	{
// 		Gosu::Graphics::draw_rect(0, 400, 800, 200, Gosu:: Color::Color(20, 200, 20), 0);
// 		Figur.draw();
// 		//Gosu::Font(string_menü);
// 		/*switch (mode) {

// 			case
// 			default
// 		}*/
// 	}

// 	// Wird 60x pro Sekunde aufgerufen
// 	void update() override
// 	{
// 		if (Gosu::Input::down(Gosu::ButtonName::KB_LEFT_CONTROL)) {
// 			Figur.set_boost();
// 		}
// 		else {
// 			Figur.reset_boost();
// 		}
// 		if (Gosu::Input::down(Gosu::ButtonName::KB_RIGHT)) {
// 			//std::cout << "->" << std::endl;
// 			Figur.set_PosX(Figur.get_PosX() + Figur.get_speed() / 60);
// 			score++;
// 		}
// 		if (Gosu::Input::down(Gosu::ButtonName::KB_LEFT)) {
// 			//std::cout << "<-" << std::endl;
// 			Figur.set_PosX(Figur.get_PosX() - Figur.get_speed() / 60);
// 		}
// 		if (Gosu::Input::down(Gosu::ButtonName::KB_UP)) {
// 			//std::cout << "^" << std::endl;
// 			Figur.do_jump();
// 		}
// 		Figur.flight(400);
// 	}
// };

// // C++ Hauptprogramm
// int main()
// {
// //	ablauf_start();
// //	mode = running;
// //	GameWindow window;
// //	window.show();
// }
