#pragma once
#include "Menu.h"
using namespace Menus;

class MenuJogadores : public Menu
{
protected:
	
	virtual void set_values();
	virtual void loop_events();

public:
	MenuJogadores();
	~MenuJogadores();
	
	virtual void run_menu();
};

