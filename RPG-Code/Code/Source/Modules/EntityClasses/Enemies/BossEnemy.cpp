#include "EntityManager.h"

#include "Entity.h"
#include "DynamicEntity.h"
#include "Enemy.h"
#include "BossEnemy.h"
#include "PauseMenu.h"


BossEnemy::BossEnemy(BossType bossType) : Enemy(EnemyType::BOSS)
{
	this->bossType = bossType;

	switch (bossType) {
	case BossType::TRUCK:

		

		break;

	case BossType::VALION:

		//IDLE
		battleAnim.PushBack({ 0 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		battleAnim.PushBack({ 1 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		battleAnim.PushBack({ 2 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		battleAnim.PushBack({ 3 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		battleAnim.PushBack({ 4 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		battleAnim.PushBack({ 5 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		battleAnim.loop = true;
		battleAnim.speed = 0.01f;

		//ATTACK 1
		attackAnim.PushBack({ 0 * BATTLE_SIZE , 1 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 1 * BATTLE_SIZE , 1 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 2 * BATTLE_SIZE , 1 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 3 * BATTLE_SIZE , 1 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 4 * BATTLE_SIZE , 1 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 5 * BATTLE_SIZE , 1 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 6 * BATTLE_SIZE , 1 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 7 * BATTLE_SIZE , 1 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		attackAnim.PushBack({ 0 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 1 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 2 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 3 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 4 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim.PushBack({ 5 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		attackAnim.loop = false;
		attackAnim.speed = 0.008f;

		//ATTACK 2
		attackAnim2.PushBack({ 0 * BATTLE_SIZE , 2 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 1 * BATTLE_SIZE , 2 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 2 * BATTLE_SIZE , 2 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 3 * BATTLE_SIZE , 2 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 4 * BATTLE_SIZE , 2 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 5 * BATTLE_SIZE , 2 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 6 * BATTLE_SIZE , 2 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 7 * BATTLE_SIZE , 2 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		attackAnim2.PushBack({ 0 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 1 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 2 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 3 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 4 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		attackAnim2.PushBack({ 5 * BATTLE_SIZE , 0 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		attackAnim2.loop = false;
		attackAnim2.speed = 0.01f;

		protectAnim.PushBack({ 0 * BATTLE_SIZE , 2 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		//HIT ANIM
		hitAnim.PushBack({ 0 * BATTLE_SIZE , 100 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		hitAnim.PushBack({ 1 * BATTLE_SIZE , 100 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		hitAnim.PushBack({ 2 * BATTLE_SIZE , 100 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		hitAnim.PushBack({ 3 * BATTLE_SIZE , 100 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		hitAnim.loop = false;
		hitAnim.speed = 0.006f;

		//DEATH
		dieAnim.PushBack({ 0 * BATTLE_SIZE , 4 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		dieAnim.PushBack({ 1 * BATTLE_SIZE , 4 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		dieAnim.PushBack({ 2 * BATTLE_SIZE , 4 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		dieAnim.PushBack({ 3 * BATTLE_SIZE , 4 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		dieAnim.PushBack({ 4 * BATTLE_SIZE , 4 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		dieAnim.PushBack({ 5 * BATTLE_SIZE , 4 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		dieAnim.PushBack({ 6 * BATTLE_SIZE , 4 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		dieAnim.loop = false;
		dieAnim.speed = 0.006f;

		//JUMP
		jumpAnim.PushBack({ 0 * BATTLE_SIZE , 5 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		jumpAnim.PushBack({ 1 * BATTLE_SIZE , 5 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		jumpAnim.loop = true;
		jumpAnim.speed = 0.006f;

		//FALL
		fallAnim.PushBack({ 0 * BATTLE_SIZE , 6 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		fallAnim.PushBack({ 1 * BATTLE_SIZE , 6 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		fallAnim.loop = true;
		fallAnim.speed = 0.006f;

		//RUN
		walkAnim.PushBack({ 0 * BATTLE_SIZE , 7 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		walkAnim.PushBack({ 1 * BATTLE_SIZE , 7 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		walkAnim.PushBack({ 2 * BATTLE_SIZE , 7 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		walkAnim.PushBack({ 3 * BATTLE_SIZE , 7 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		walkAnim.PushBack({ 4 * BATTLE_SIZE , 7 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		walkAnim.PushBack({ 5 * BATTLE_SIZE , 7 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		walkAnim.PushBack({ 6 * BATTLE_SIZE , 7 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });
		walkAnim.PushBack({ 7 * BATTLE_SIZE , 7 * BATTLE_SIZE , BATTLE_SIZE , BATTLE_SIZE });

		walkAnim.speed = 0.006f;

		baseCollider = nullptr;

		currentAnimation = &idleAnimL;

		name = "Valion";
		battleName = " Valion";
		configName = "evilValion";

		zoom = 2;

		break;
	

	case BossType::RYLA:

		
		break;

	case BossType::DHION:


		break;

	default:
		break;
	}

	isAlive = true;
}

BossEnemy::~BossEnemy()
{}

bool BossEnemy::Awake(pugi::xml_node& config)
{
	return true;
}

// Called before the first frame
bool BossEnemy::Start()
{
	LOG("Start Normal Enemies variables");

	switch (bossType) {
	case BossType::TRUCK:

		spriteTex = app->tex->Load("Assets/sprites/characters/wizard/wizardBattleSprite.png");

		stats = new Stats(1, 5, 10, 2, 2, 27);

		break;
	case BossType::VALION:

		spriteTex = app->tex->Load("Assets/sprites/characters/wizard/wizardBattleSprite.png");

		stats = new Stats(1, 5, 10, 2, 2, 27);

		break;
	case BossType::RYLA:

		spriteTex = app->tex->Load("Assets/sprites/characters/wizard/wizardBattleSprite.png");

		stats = new Stats(1, 5, 10, 2, 2, 27);

		break;
	case BossType::DHION:

		spriteTex = app->tex->Load("Assets/sprites/characters/wizard/wizardBattleSprite.png");

		stats = new Stats(1, 5, 10, 2, 2, 27);
		break;
	default:
		break;
	}

	return true;
}

bool BossEnemy::PreUpdate()
{
	return true;
}

// Call modules on each loop iteration
bool BossEnemy::Update(float dt)
{
	if (!app->pauseM->pauseGame) {
		if (currentAnimation != nullptr) {
			currentAnimation->Update(dt);
		}
	}
	return true;
}

// Call modules after each loop iteration
bool BossEnemy::PostUpdate()
{
	return true;
}

// Called before quitting
bool BossEnemy::CleanUp()
{
	if (baseCollider != nullptr) {
		app->collisions->RemoveCollider(baseCollider);
	}


	baseCollider = nullptr;
	delete baseCollider;

	app->tex->UnLoad(spriteTex);


	currentAnimation = nullptr;
	delete currentAnimation;


	return true;
}