#ifndef __NPC_H__
#define __NPC_H__

#include "App.h"
#include "Point.h"
#include "Animation.h"
#include "Render.h"
#include "Entity.h"

#include "EntityManager.h"
#include "DynamicEntity.h"

#include <vector>

struct SDL_Texture;
struct SDL_Surface;
struct Collider;

enum class NPCType
{
	COCK,
	BARKEEPER,
	MERCHANT,
	TRAINER
};

class NPC : public DynamicEntity
{
public:

	NPC(NPCType type, int x, int y);
	~NPC();

	virtual bool Awake(pugi::xml_node& config);
	virtual bool Start();
	virtual bool PreUpdate();
	virtual bool Update(float dt);
	virtual bool PostUpdate();

	// Returns the enemy's collider
	//const Collider* GetCollider() const;
	//virtual void OnCollision(Collider* collider);

	virtual bool CleanUp();

public:

	int NPCid;
	bool isMerchant;

	bool hasMovement;

	NPCType NpcType;

	SDL_Texture* NPCSprite = nullptr;

	Animation* currentAnimationNPC = nullptr;
	Animation idleAnimNPC;
	Animation* currentAnimation = nullptr;
	Animation idleAnim;
	iPoint position;
};

#endif // !__NPC_H__