#pragma once
#ifndef string
#include <string>
#endif // !string


typedef enum { Mario, Luigi } character;

class position {
public:
	double PosX;
	double PosY;

//Konstruktoren:
	position(double Position_X, double Position_Y) {
		this->PosX = Position_X;
		this->PosY = Position_Y;
	};
	position() {};
};

class Objekte {
protected:
	double	Radius;
	position Position;
	Gosu::Color Farbe;
public:
	void set_Radius(double Radius) {
		this->Radius = Radius;
	};
	double get_Radius() {
		return this->Radius;
	};
	void set_color(int rot, int gruen, int blau) {
		this->Farbe.set_red(rot);
		this->Farbe.set_green(gruen);
		this->Farbe.set_blue(blau);
	};
	void set_color(Gosu::Color Farbe) {
		this->Farbe = Farbe;
	};
	Gosu::Color get_Farbe() {
		return this->Farbe;
	};


//Konstruktoren:
	Objekte(double Position_X, double Position_Y, double Radius = 0) {
		this->Radius = Radius;
		this->Position.PosX = Position_X;
		this->Position.PosY = Position_Y;
	}
	Objekte(double Position_X, double Position_Y, double Radius, Gosu::Color Farbe) {
		this->Radius = Radius;
		this->Position.PosX = Position_X;
		this->Position.PosY = Position_Y;
		this->Farbe = Farbe;
	}
	Objekte(double Position_X, double Position_Y, double Radius, int Farbe_rot, int Farbe_gruen, int Farbe_blau) {
		this->Radius = Radius;
		this->Position.PosX = Position_X;
		this->Position.PosY = Position_Y;
		this->set_color(Farbe_rot, Farbe_gruen, Farbe_blau);
	}
};

class Spieler : protected Objekte {
protected:
	character name;
public:
	void set_name(character name) {
		this->name = name
	};
	character get_name() {
		return this->name;
	};
	

//Konstruktoren
	Spieler(character name = Mario, double Position_X = 0, double Position_Y = 0, double Radius = 0)
		: Objekte(Position_X, Position_Y, Radius) {
		set_name(name);
	};
};