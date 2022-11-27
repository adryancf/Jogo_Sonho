#pragma once
#include "Menu.h"
class MenuPrincipal : public Menu
{

protected:

	virtual void set_values();
	virtual void loop_events();

public:
	MenuPrincipal();
	~MenuPrincipal();

	virtual void run_menu();
};

