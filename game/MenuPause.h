#pragma once
#include "Menu.h"

class MenuPause : public Menu
{
protected:

	virtual void set_values();
	virtual void loop_events();
public:
	MenuPause();
	~MenuPause();

	virtual void run_menu();

};


