#ifndef __PAUSEMENU_H__
#define __PAUSEMENU_H__

#include "Module.h"
#include "GuiButton.h"
struct SDL_Texture;

class PauseMenu : public Module
{
public:
	PauseMenu(App* application, bool start_enabled = true);

	// Destructor
	virtual ~PauseMenu();

	// Called before render is available
	bool Awake(pugi::xml_node& config);

	// Called before the first frame
	bool Start();

	// Define multiple Gui Event methods
	bool OnGuiMouseClickEvent(GuiControl* control);

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

public:

	/*Player* player = nullptr;*/

	int confirmFx;

	bool pauseGame;

	bool resumen;

	SDL_Texture* Pausetex;


	// Buttons

	GuiButton* party;
	GuiButton* invent;
	GuiButton* town;
	GuiButton* resume;
	GuiButton* config;
	GuiButton* save;
	GuiButton* load;
	GuiButton* exit;
	
};

#endif