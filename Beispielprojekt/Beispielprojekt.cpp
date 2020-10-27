#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"
#include "Klassen.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

character Character = Mario;
player Figur(Mario, 100, 400, 32);
game_mode mode = menu;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild;
	GameWindow()
		: Window(800, 600),
		bild(Figur.get_picpath())
	{
		set_caption("Gosu Tutorial mit Git");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		switch (mode) {
		case menu:
			//Einstellungen, Score, Spielstart
			break;
		case start:
			//Startvorgang
			break;
		case running:
			Gosu::Graphics::draw_rect(
				0, 400, 800, 200, Gosu::Color::GREEN, 0
			);
			bild.draw_rot(
				Figur.get_PosX(), (Figur.get_PosY() - Figur.get_Radius()), 1, 0, //Position
				0.5, 0.5,
				0.1, 0.1 //Skalierung
			);
			break;
		case end:
			break;
		default:
			std::cout << "ERROR: ungueltiger Zustand 'Game_mode'" << std::endl;
			break;
		}
	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
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
	mode = running;
	GameWindow window;
	window.show();
}
