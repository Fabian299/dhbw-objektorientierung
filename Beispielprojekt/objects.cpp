//Methoden Klasse objects
	void objects::set_color(Gosu::Color Farbe) {
		this->Farbe = Farbe;
	}
	void objects::set_color(int rot, int gruen, int blau) {
		this->Farbe.set_red(rot);
		this->Farbe.set_green(gruen);
		this->Farbe.set_blue(blau);
	}
	void objects::set_Radius(double Radius) {
		this->Radius = Radius;
		}
	void objects::set_PosX(double PosX) {
		this->Position.PosX = PosX;
	}
	void objects::set_PosY(double PosY) {
		this->Position.PosY = PosY;
	}
	Gosu::Color objects::get_Farbe() {
		return this->Farbe;
	}
	double objects::get_PosX() {
		return this->Position.PosX;
	}
	double objects::get_PosY() {
		return this->Position.PosY;
	}
	double objects::get_Radius() {
		return this->Radius;
	}

//Konstruktoren Klasse objects
	objects::objects(double Position_X, double Position_Y, double Radius = 0) {
		this->Radius = Radius;
		this->Position.PosX = Position_X;
		this->Position.PosY = Position_Y;
	}
	objects::objects(double Position_X, double Position_Y, double Radius, Gosu::Color Farbe) {
		this->Radius = Radius;
		this->Position.PosX = Position_X;
		this->Position.PosY = Position_Y;
		this->Farbe = Farbe;
	}
	objects::objects(double Position_X, double Position_Y, double Radius, int Farbe_rot, int Farbe_gruen, int Farbe_blau) {
		this->Radius = Radius;
		this->Position.PosX = Position_X;
		this->Position.PosY = Position_Y;
		this->set_color(Farbe_rot, Farbe_gruen, Farbe_blau);
	}

//Methoden Klasse player
	character player::get_name() {
		return this->name;
	}
	double player::get_speed() {
		if (this->boost) {
			return 2 * this->speed;
		}
		else {
			return speed;
		}
	}
	std::string player::get_picpath() {
		switch (name) {
		case Mario:
			return "Mario.png";
			break;

		case Luigi:
			return "Luigi.png";
			break;

		default:
			printf("\nERROR: ungültiger Zustand\n");
		}
	}
	
	void player::do_fall() {
		this->fall = TRUE;
	}
	void player::do_jump() {
		this->jump = TRUE;
	}
	void player::flight(double h_underground = 400) {
		if (this->jump && this->j_counter == 0 && !(fall)) {
			this->j_counter++;
			this->j_start = this->Position.PosY;
			this->Position.PosY = this->j_start - (-this->j_high * ((this->j_counter - 30) * (this->j_counter - 30)) + 100);
		}
		else if (!(this->fall) && this->jump && this->j_counter < 30) {
			this->j_counter++;
			this->Position.PosY = this->j_start - (-this->j_high * ((this->j_counter - 30) * (this->j_counter - 30)) + 100);
		}
		else if (!(this->fall) && this->jump && this->j_counter == 30) {
			this->jump = FALSE;
			this->fall = TRUE;
			this->j_counter = 0;
		}

		if (fall && j_counter == 0 && h_underground > this->Position.PosY) {
			this->jump = FALSE;
			this->j_counter++;
			this->j_start = this->Position.PosY;
			this->Position.PosY = this->j_start + (this->j_high * (this->j_counter * this->j_counter));
		}
		else if (fall && h_underground > this->Position.PosY) {
			this->jump = FALSE;
			this->j_counter++;
			if ((this->j_start + (this->j_high * (this->j_counter * this->j_counter))) < 400) {
				this->Position.PosY = this->j_start + (this->j_high * (this->j_counter * this->j_counter));
			}
			else {
				this->Position.PosY = h_underground;
			}
		}
		else if (fall) {
			this->jump = FALSE;
			this->fall = FALSE;
			this->j_counter = 0;
		}
		//debug
		/*if (fall | jump) {
			std::cout << this->j_counter << " | " << this->Position.PosY << std::endl;
		}*/
	}
	void player::set_boost() {
		this->boost = TRUE;
	}
	void player::set_name(character name) {
		this->name = name;
	}
	void player::set_speed(double speed) {
		this->speed = speed;
	}
	void player::reset_boost() {
		this->boost = FALSE;
	}

//Konstruktor player
	player::player(character name = Mario, double Position_X = 0, double Position_Y = 0, double Radius = 0, double speed = 80)
		: objects(Position_X, Position_Y, Radius) {
		set_name(name);
		set_speed(speed);
	}