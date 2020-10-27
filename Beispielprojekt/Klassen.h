#pragma once
#ifndef string
#include <string>
#endif // !string

typedef enum {menu, start, running, end} game_mode;

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
	void set_Radius(double Radius) {
		this->Radius = Radius;
	};
	double get_Radius() {
		return this->Radius;
	};
	double get_PosX() {
		return this->Position.PosX;
	};
	double get_PosY() {
		return this->Position.PosY;
	}
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
	objects(double Position_X, double Position_Y, double Radius = 0) {
		this->Radius = Radius;
		this->Position.PosX = Position_X;
		this->Position.PosY = Position_Y;
	}
	objects(double Position_X, double Position_Y, double Radius, Gosu::Color Farbe) {
		this->Radius = Radius;
		this->Position.PosX = Position_X;
		this->Position.PosY = Position_Y;
		this->Farbe = Farbe;
	}
	objects(double Position_X, double Position_Y, double Radius, int Farbe_rot, int Farbe_gruen, int Farbe_blau) {
		this->Radius = Radius;
		this->Position.PosX = Position_X;
		this->Position.PosY = Position_Y;
		this->set_color(Farbe_rot, Farbe_gruen, Farbe_blau);
	}
};

class player : public objects {
protected:
	character name;
	const double j_high = 1.0/9;
	double j_start = 0;
	bool jump = FALSE;
	bool fall = FALSE;
	std::string picpath;
	double speed;
	double j_counter = 0; //Sprung-Zeit-Zähler
public:
	void set_name(character name) {
		this->name = name;
	};
	void do_jump() {
		this->jump = TRUE;
	};
	void do_fall() {
		this->fall = TRUE;
	};
	void flight(double h_underground = 400){
		if (this->jump && this->j_counter == 0) {
			this->j_counter++;
			this->j_start = this->Position.PosY;
			this->Position.PosY = this->j_start - (-this->j_high * ((this->j_counter - 30) * (this->j_counter - 30)) + 100);
		}
		else if (this->jump && this->j_counter < 30) {
			this->j_counter++;
			this->Position.PosY = this->j_start - (-this->j_high * ((this->j_counter - 30) * (this->j_counter - 30))+100);
		}
		else if (this->jump && this->j_counter == 30) {
			this->jump = FALSE;
			this->fall = TRUE;
			this->j_counter = 0;
		}

		if (fall && j_counter == 0 && h_underground > this->Position.PosY) {
			this->j_counter++;
			this->j_start = this->Position.PosY;
			this->Position.PosY = this->j_start + (this->j_high * (this->j_counter * this->j_counter));
		}
		else if (fall && h_underground > this->Position.PosY) {
			this->j_counter++;
			this->Position.PosY = this->j_start + (this->j_high * (this->j_counter * this->j_counter));
		}
		else if (fall) {
			this->fall = FALSE;
			this->j_counter = 0;
		}
		//debug
		if (fall | jump) {
			std::cout << this->j_counter << " | " << this->Position.PosY << std::endl;
		}
	}
	void set_PosX(double PosX) {
		this->Position.PosX = PosX;
	}
	void set_PosY(double PosY) {
		this->Position.PosY = PosY;
	}
	void set_speed(double speed) {
		this->speed = speed;
	}
	double get_speed() {
		return speed;
	};
	character get_name() {
		return this->name;
	};
	std::string get_picpath() {
		switch (name) {
		case Mario:
			return "Mario.png";
			break;

		case Luigi:
			return "Luigi.png";
			break;

		default:
			printf("\nERROR: ungültiger Zustand\n");
		};
	}
	
//Konstruktoren
	player(character name = Mario, double Position_X = 0, double Position_Y = 0, double Radius = 0, double speed = 80)
		: objects(Position_X, Position_Y, Radius) {
		set_name(name);
		set_speed(speed);
	};
};