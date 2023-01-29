#pragma once
#include "Menu.h"
using namespace Menus;

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


