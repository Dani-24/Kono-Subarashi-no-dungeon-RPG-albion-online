#include "PauseMenu.h"
#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Title.h"
#include "FadeToBlack.h"
#include "ModuleQFonts.h"
#include "Stages.h"
#include "Scene.h"
#include "GuiManager.h"
#include "Camera.h"
#include "Player.h"
#include "Defs.h"
#include "Log.h"
#include "GuiButton.h"
#include "Configuration.h"
#include "Battle.h"
#include "Inventory.h"

PauseMenu::PauseMenu(App* application, bool start_enabled) : Module(application, start_enabled)
{
	name.Create("pauseMenu");
	
}

// Destructor
PauseMenu::~PauseMenu()
{}

// Called before render is available
bool PauseMenu::Awake(pugi::xml_node& config)
{
	LOG("Loading Title");
	bool ret = true;

	

	return ret;
}

// Called before the first frame
bool PauseMenu::Start()
{
	
	
	// GUI
	party = (GuiButton*)app->guiManager->CreateGuiControl(this, GuiControlType::BUTTON, 21, "Party", { (app->win->GetWidth() / 2) - 580, (app->win->GetWidth() / 50) + 250 });
	invent = (GuiButton*)app->guiManager->CreateGuiControl(this, GuiControlType::BUTTON, 22, "Inventory", { (app->win->GetWidth() / 2) - 470, (app->win->GetWidth() / 50) + 250 });
	town = (GuiButton*)app->guiManager->CreateGuiControl(this, GuiControlType::BUTTON, 23, "Town", { (app->win->GetWidth() / 2) - 360, (app->win->GetWidth() / 50) + 250 });
	resume = (GuiButton*)app->guiManager->CreateGuiControl(this, GuiControlType::BUTTON, 24, "Resume", { (app->win->GetWidth() / 2) - 250, (app->win->GetWidth() / 50) + 250 });
	config = (GuiButton*)app->guiManager->CreateGuiControl(this, GuiControlType::BUTTON, 25, "Config", { (app->win->GetWidth() / 2) - 140, (app->win->GetWidth() / 50) + 250 });
	save = (GuiButton*)app->guiManager->CreateGuiControl(this, GuiControlType::BUTTON, 26, "Save", { (app->win->GetWidth() / 2) - 140, (app->win->GetWidth() / 50) + 250 });
	load = (GuiButton*)app->guiManager->CreateGuiControl(this, GuiControlType::BUTTON, 27, "Load", { (app->win->GetWidth() / 2) - 140, (app->win->GetWidth() / 50) + 250 });
	exit = (GuiButton*)app->guiManager->CreateGuiControl(this, GuiControlType::BUTTON, 28, "Exit", { (app->win->GetWidth() / 2) - 140, (app->win->GetWidth() / 50) + 250 });
	
	party->state = GuiControlState::DISABLED;
	invent->state = GuiControlState::DISABLED;
	town->state = GuiControlState::DISABLED;
	resume->state = GuiControlState::DISABLED;
	config->state = GuiControlState::DISABLED;
	save->state = GuiControlState::DISABLED;
	load->state = GuiControlState::DISABLED;
	exit->state = GuiControlState::DISABLED;
	// Load Assets

	// Audio 

	confirmFx = app->audio->LoadFx("Assets/audio/sfx/fx_select_confirm.wav");

	Pausetex = app->tex->Load("Assets/gui/pause_menu2.png");
	// Set camera to 0,0

	//app->camera->SetPos({ 0,0 });

	
	resumen = false;
	pauseGame = false;
	exitg = false;
	_wait,wait = false; 

	return true;
}


bool PauseMenu::OnGuiMouseClickEvent(GuiControl* control)
{
	if (!app->conf->isEnabled()) {
		switch (control->type)
		{
		case GuiControlType::BUTTON:
		{
			//Checks the GUI element ID

			if (control->id == 21)
			{
				LOG("partu");
			}
			if (control->id == 22)
			{
				LOG("invent");

				app->inventory->Enable();
			}
			if (control->id == 23)
			{
				LOG("town");
				resumen = true;
				app->fade->DoFadeToBlack(StageIndex::TOWN);
			}
			if (control->id == 24)
			{
				LOG("resume");
				resumen = true;

			}
			if (control->id == 25)
			{
				LOG("config");
				if (!app->conf->isEnabled())app->conf->Enable();
			}
			if (control->id == 26)
			{
				LOG("save");
				app->audio->PlayFx(app->scene->saveFx);
				app->SaveGameRequest();
			}
			if (control->id == 27)
			{
				LOG("loadd");
				resumen = true;
				app->audio->PlayFx(app->scene->loadFx);
				app->LoadGameRequest();
			}
			if (control->id == 28)
			{
				LOG("exit");
				exitg = true;
				resumen = true;
			}

		}
		//Other cases here

		default: break;
		}
	}
	return true;
}


// Called each loop iteration
bool PauseMenu::PreUpdate()
{
	bool ret = true;
	//ret = exitg;
	int xt, yt, xc, yc;

	//variables for textures
	xt = -app->camera->GetPos().x / 2 + app->win->GetWidth() / 2;
	yt = -app->camera->GetPos().y / 2 + app->win->GetHeight() / 2;

	//variables for text
	xc = -app->camera->GetPos().x / app->win->GetScale() + app->win->GetWidth() / 2;
	yc = -app->camera->GetPos().y / app->win->GetScale() + app->win->GetHeight() / 2;

	if (pauseGame)
	{
		app->camera->SetPos({ 0,0 });
		party->SetPos({ xc - 100,yc - 265 });
		invent->SetPos({ xc - 100,yc - 240 });
		town->SetPos({ xc - 100,yc - 215 });
		resume->SetPos({ xc - 100, yc - 190 });
		config->SetPos({ xc - 100,yc - 165 });
		save->SetPos({ xc - 100,yc - 140 });
		load->SetPos({ xc - 100,yc - 115 });
		exit->SetPos({ xc - 100,yc - 90 });

		KeyboardControl();

	}

	
	/*if (app->input->GetKey(SDL_SCANCODE_B) == KEY_DOWN) {
		if (app->pauseM->pauseGame == false && app->scene->playing == true)app->pauseM->pauseGame = true, app->scene->playing = true, app->conf->Enable() ;
		else app->pauseM->pauseGame = false, app->conf->Disable();
	}*/

	//if (start == true) {
	//	if (pause == false) {
	//		pause = true;
	//		app->audio->PlayFx(confirmFx);
	//	}
	//	app->stages->ChangeStage(StageIndex::TOWN);

	//	app->fade->DoFadeToBlack(this, (Module*)app->scene);
	//}

	//if (options == true) {
	//	options = false;
	//	app->audio->PlayFx(confirmFx);

	//	app->fade->DoFadeToBlack(this, (Module*)app->conf);
	//}

	//if (app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN || exit == true) {
	//	ret = false;
	//}
	return ret;
}

// Called each loop iteration
bool PauseMenu::Update(float dt)
{

	int xt, yt, xc, yc;
	GamePad& pad = app->input->pads[0];

	//variables for textures
	xt = -app->camera->GetPos().x / 2 + app->win->GetWidth() / 2;
	yt = -app->camera->GetPos().y / 2 + app->win->GetHeight() / 2;

	//variables for text
	xc = -app->camera->GetPos().x / app->win->GetScale() + app->win->GetWidth() / 2;
	yc = -app->camera->GetPos().y / app->win->GetScale() + app->win->GetHeight() / 2;
	if (!pad.start) _wait = true;
	if ((app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN || resumen == true || pad.start && _wait == true)&&app->scene->playing&&!app->battle->isEnabled() ) {

		
		if (pauseGame){
			if (app->conf->isEnabled())app->conf->Disable();
			pauseGame = false;
			resumen = false;
			app->scene->player->canMove = true; app->scene->player->toggleGui = true;
			app->camera->SetTarget(app->scene->player);
			app->camera->SetLimits(640, 350, 4490, 4200);
			CleanUp();
		}
		else
		{
			if (app->inventory->isEnabled() == false) {
				pauseGame = true, app->scene->player->canMove = false; app->scene->player->toggleGui = false;
				party->state = GuiControlState::NORMAL;
				invent->state = GuiControlState::NORMAL;
				town->state = GuiControlState::NORMAL;
				resume->state = GuiControlState::NORMAL;
				config->state = GuiControlState::NORMAL;
				save->state = GuiControlState::NORMAL;
				load->state = GuiControlState::NORMAL;
				exit->state = GuiControlState::NORMAL;
				party->state = GuiControlState::NORMAL;
				app->audio->ChangeVolume(app->audio->vol / 3);
			}
		}
		_wait = false;
	}

	
		return true;
}

// Called each loop iteration
bool PauseMenu::PostUpdate()
{
	bool ret = true;
	SDL_Color c = { 0,0,0 };
	SDL_Color w = { 255,255,255 };
	int xt, yt, xc, yc;

	//variables for textures
	xt = -app->camera->GetPos().x / 2 + app->win->GetWidth() / 2;
	yt = -app->camera->GetPos().y / 2 + app->win->GetHeight() / 2;

	//variables for text
	xc = -app->camera->GetPos().x / app->win->GetScale() + app->win->GetWidth() / 2;
	yc = -app->camera->GetPos().y / app->win->GetScale() + app->win->GetHeight() / 2;


	if (pauseGame && app->scene->playing) {
		app->render->DrawRectangle({ xt + -1000 ,yt - 1000, 1000,1000  },0,0,0,120);

		app->render->DrawTexture(Pausetex, xc - 120, yc - 280);
	}

	return ret;
}

// Called before quitting
bool PauseMenu::CleanUp()
{
	LOG("Freeing Title scene");

	/*app->font->CleanFonts();*/

	party->state = GuiControlState::DISABLED;
	invent->state = GuiControlState::DISABLED;
	town->state = GuiControlState::DISABLED;
	resume->state = GuiControlState::DISABLED;
	config->state = GuiControlState::DISABLED;
	save->state = GuiControlState::DISABLED;
	load->state = GuiControlState::DISABLED;
	exit->state = GuiControlState::DISABLED;
	
	//app->tex->UnLoad(titleBg);
	//app->tex->UnLoad(startb);
	//app->tex->UnLoad(continueb);
	//app->tex->UnLoad(optionsb);
	//app->tex->UnLoad(creditsb);
	//app->tex->UnLoad(exitb);

	app->audio->ChangeVolume(app->audio->vol * 3);

	return true;
}

//called on preupdate
void PauseMenu::KeyboardControl()
{

	GamePad& pad = app->input->pads[0];

	if (party->state == GuiControlState::NORMAL && invent->state == GuiControlState::NORMAL &&
		town->state == GuiControlState::NORMAL && resume->state == GuiControlState::NORMAL &&
		config->state == GuiControlState::NORMAL && save->state == GuiControlState::NORMAL &&
		load->state == GuiControlState::NORMAL && exit->state == GuiControlState::NORMAL)
	{
		if (app->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN || app->input->GetKey(SDL_SCANCODE_DOWN) ||
			app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN ||
			pad.right || pad.left || pad.up || pad.down)
		{
			party->state = GuiControlState::FOCUSED;
			app->guiManager->keyb = true;
		}
	}

	if (party->state == GuiControlState::FOCUSED) {

		if (app->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN || pad.a)
		{
			party->state = GuiControlState::PRESSED;
			party->NotifyObserver();
		}
		if (!pad.right && !pad.left) wait = true;
		
		if (app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || pad.right && wait == true) {
			invent->state = GuiControlState::FOCUSED;
			party->state = GuiControlState::NORMAL;
			wait = false;
		}

		
	}
	else if (invent->state == GuiControlState::FOCUSED) {

		if (app->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN || pad.a)
		{
			invent->state = GuiControlState::PRESSED;
			invent->NotifyObserver();
		}
		if (!pad.right && !pad.left) wait = true;
		if (app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || pad.right && wait == true) {
			town->state = GuiControlState::FOCUSED;
			invent->state = GuiControlState::NORMAL;
			wait = false;
		}

		if (app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || pad.left && wait == true) {
			party->state = GuiControlState::FOCUSED;
			invent->state = GuiControlState::NORMAL;
			wait = false;
		}

		
	}
	else if (town->state == GuiControlState::FOCUSED) {

		if (app->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN || pad.a)
		{
			town->state = GuiControlState::PRESSED;
			town->NotifyObserver();
		}
		if (!pad.right && !pad.left) wait = true;
		if (app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || pad.right && wait == true) {
			resume->state = GuiControlState::FOCUSED;
			town->state = GuiControlState::NORMAL;
			wait = false;
		}

		if (app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || pad.left && wait == true) {
			invent->state = GuiControlState::FOCUSED;
			town->state = GuiControlState::NORMAL;
			wait = false;
		}


	}
	else if (resume->state == GuiControlState::FOCUSED) {

		if (app->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN || pad.a)
		{
			resume->state = GuiControlState::PRESSED;
			resume->NotifyObserver();
		}
		if (!pad.right && !pad.left) wait = true;
		if (app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || pad.right && wait == true) {
			config->state = GuiControlState::FOCUSED;
			resume->state = GuiControlState::NORMAL;
			wait = false;
		}

		if (app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || pad.left && wait == true) {
			town->state = GuiControlState::FOCUSED;
			resume->state = GuiControlState::NORMAL;
			wait = false;
		}


	}
	else if (config->state == GuiControlState::FOCUSED) {

		if (app->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN || pad.a)
		{
			config->state = GuiControlState::PRESSED;
			config->NotifyObserver();
		}
		if (!pad.right && !pad.left) wait = true;
		if (app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || pad.right && wait == true) {
			save->state = GuiControlState::FOCUSED;
			config->state = GuiControlState::NORMAL;
			wait = false;
		}

		if (app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || pad.left && wait == true) {
			resume->state = GuiControlState::FOCUSED;
			config->state = GuiControlState::NORMAL;
			wait = false;
		}


	}
	else if (load->state == GuiControlState::FOCUSED) {

		if (app->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN || pad.a)
		{
			load->state = GuiControlState::PRESSED;
			load->NotifyObserver();
		}
		if (!pad.right && !pad.left) wait = true;
		if (app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || pad.right && wait == true) {
			exit->state = GuiControlState::FOCUSED;
			load->state = GuiControlState::NORMAL;
			wait = false;
		}

		if (app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || pad.left && wait == true) {
			save->state = GuiControlState::FOCUSED;
			load->state = GuiControlState::NORMAL;
			wait = false;
		}


	}
	else if (save->state == GuiControlState::FOCUSED) {

		if (app->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN || pad.a)
		{
			save->state = GuiControlState::PRESSED;
			save->NotifyObserver();
		}
		if (!pad.right && !pad.left) wait = true;
		if (app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || pad.right && wait == true) {
			load->state = GuiControlState::FOCUSED;
			save->state = GuiControlState::NORMAL;
			wait = false;
		}

		if (app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || pad.left && wait == true) {
			config->state = GuiControlState::FOCUSED;
			save->state = GuiControlState::NORMAL;
			wait = false;
		}


	}
	else if (exit->state == GuiControlState::FOCUSED) {

		if (app->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN || pad.a)
		{
			exit->state = GuiControlState::PRESSED;
			exit->NotifyObserver();
		}
		if (!pad.right && !pad.left) wait = true;

		if (app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || pad.left && wait == true) {
			load->state = GuiControlState::FOCUSED;
			exit->state = GuiControlState::NORMAL;
			wait = false;
		}


	}

}