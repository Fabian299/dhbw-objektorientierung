
#include"stdafx.h"
#include "Vektor2d.h"
#include "objects.h"
#include "Aufbau.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

// vector<playerscore> ranking_list = { };
// string player_name;

// Silas
std::string a1 = "With the '1' you can start the game. With the '2' you go to the settings. With the '0' you exit the programm. ";



character Character = Mario;
player Figur(Mario, 100, 400, 32, 130);
uint16_t score = 0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild;
	GameWindow()
		: Window(800, 600)
	{
		set_caption("Fabian and Silas wonderfull Game");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		Gosu::Graphics::draw_rect(0, 400, 800, 200, Gosu:: Color::Color(20, 200, 20), 0);
		Figur.draw();
		//Gosu::Font(string_menü);
		/*switch (mode) {

			case
			default
		}*/
	}

	// Wird 60x pro Sekunde aufgerufen
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
			score++;
		}
		if (Gosu::Input::down(Gosu::ButtonName::KB_LEFT)) {
			//std::cout << "<-" << std::endl;
			Figur.set_PosX(Figur.get_PosX() - Figur.get_speed() / 60);
		}
		if (Gosu::Input::down(Gosu::ButtonName::KB_UP)) {
			//std::cout << "^" << std::endl;
			Figur.do_jump();
		}
		Figur.flight(400);
	}
};

// C++ Hauptprogramm
int main()
{
//	ablauf_start();
//	mode = running;
//	GameWindow window;
//	window.show();
}
