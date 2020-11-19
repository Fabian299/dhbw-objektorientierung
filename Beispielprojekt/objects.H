#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>


#pragma once
//#include <string>

typedef enum { Mario, Luigi } character;

class position {
public:
	double PosX;
	double PosY;

//Konstruktoren:
	position(double Position_X = 0, double Position_Y = 0) {
		this->PosX = Position_X;
		this->PosY = Position_Y;
	};
};

class objects {
protected:
	double	Radius;
	position Position;
	Gosu::Color Farbe;
public:
	void draw();
	void set_Radius(double Radius);
	double get_Radius();
	double get_PosX();
	double get_PosY();
	void set_color(int rot, int gruen, int blau);
	void set_color(Gosu::Color Farbe);
	Gosu::Color get_Farbe();

//Konstruktoren:
	objects(double Position_X, double Position_Y, double Radius = 0);
	objects(double Position_X, double Position_Y, double Radius, Gosu::Color Farbe);
	objects(double Position_X, double Position_Y, double Radius, int Farbe_rot, int Farbe_gruen, int Farbe_blau);
};

class player : public objects {
protected:
	Gosu::Image Pic_Mario;
	Gosu::Image Pic_Luigi;
	bool boost = FALSE;
	bool fall = FALSE;
	bool jump = FALSE;
	character name;
	double j_counter = 0; //Sprung-Zeit-Zähler
	const double j_high = 1.0/9;
	double j_start = 0;
	double speed;
	std::string picpath;
public:
	void draw();
	void set_boost();
	void reset_boost();
	void set_name(character name);
	void do_jump();
	void do_fall();
	void flight(double h_underground = 400);
	void set_PosX(double PosX);
	void set_PosY(double PosY);
	void set_speed(double spee);
	double get_speed();
	character get_name();
	//std::string get_picpath();


//Konstruktoren
	player(character name = Mario, double Position_X = 0, double Position_Y = 0, double Radius = 0, double speed = 80);
	
};