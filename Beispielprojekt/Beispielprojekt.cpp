
#include"stdafx.h"
#include "Vektor2d.h"
#include "objects.h"
#include "Aufbau.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

character Character = Mario;
player Figur(Mario, 100, 400, 32, 130);
game_mode mode = menu;

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

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		switch (mode) {
			case menu:
				ablauf_mainmenue();
				break;
			case start:
				// Biler einfügen 3-2-1
				break;
			case running:
				Gosu::Graphics::draw_rect(0, 400, 800, 200, Gosu::Color::Color(20, 200, 20), 0);
				bild.draw_rot(
					Figur.get_PosX(), (Figur.get_PosY() - Figur.get_Radius()), 1, 0, //Position
					0.5, 0.5,
					0.1, 0.1 //Skalierung
				);
				break;
			case gameover:
				// Gameover
				// value speichern
				// anzeigen des Rankings?
				break;
			default:
				std::cout << "ERROR: ungueltiger Zustand 'Game_mode'" << std::endl;
				break;
		}
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
	ablauf_start();
//	mode = running;
//	GameWindow window;
//	window.show();
}
