#ifndef __QUEST_MANAGER_H__
#define __QUEST_MANAGER_H__

#include "Module.h"
#include "List.h"
#include "DialogSystem.h"
#include <vector>

enum class QuestType
{
	KILL,
	RECOLECT,
	INTERACT
};

enum class QuestState 
{
	DISABLED,
	AVAILABLE,
	ACTIVE,
	COMPLETED,
	FINISHED	
};

class Quest 
{
public:
	QuestType questType;
	QuestState State;
	const char* questName; //Name of the quest
	const char* questDescription; //A text to descrive the quest
	int QuestId; //Number of the quest
	int NPCId; //Npc that give you the quest
	int QuestGold; //Gold reward
	int QuestExp; //Exp reward
	bool QuestChain; //if it's in a chain
	bool QuestLastChain;
	int QuestChainId; //chain id
	int QuestInChainId; //in chain number

	int objectiveNum;
	int objectiveProgress;

	int NPCinteractId;

	const char* availableDialog[DIALOG_LENGHT];
	const char* activeDialog[DIALOG_LENGHT];
	const char* completedDialog[DIALOG_LENGHT];

public:
	Quest()
	{
		questType = QuestType::INTERACT;
		State = QuestState::AVAILABLE;
		questName = "Default Name";
		questDescription = "Do something";
		QuestId = 1;
		NPCId = 8;
		QuestGold = 0;
		QuestExp = 100;
		QuestChain = false;
		QuestLastChain = false;
		QuestChainId = 0;
		QuestInChainId = 0;

		objectiveNum = 0;
		objectiveProgress = 0;

		NPCinteractId = 1;

		availableDialog[DIALOG_LENGHT] = { "active quest" };
		activeDialog[DIALOG_LENGHT] = { "quest in process" };
		completedDialog[DIALOG_LENGHT] = { "take reward" };
	}

	Quest(QuestType qtype, QuestState qState, int ID, int NPCid, const char* name, const char* description, int Gold, int XP, int objective_NPCid, int ChainId, int inChainId, bool LastInChain)
	{
		questType = qtype;
		State = qState;
		questName = name;
		questDescription = description;
		QuestId = ID;
		NPCId = NPCid;
		QuestGold = Gold;
		QuestExp = XP;
		QuestChainId = ChainId;
		QuestInChainId = inChainId;
		if (QuestChainId != 0) {
			QuestChain = true;
		}
		QuestLastChain = LastInChain;

		availableDialog[DIALOG_LENGHT] = "active quest";
		activeDialog[DIALOG_LENGHT] = "quest in process";
		completedDialog[DIALOG_LENGHT] = "take reward";

		switch (qtype) {
		case QuestType::INTERACT:
			objectiveNum = 0;
			objectiveProgress = 0;

			NPCinteractId = objective_NPCid;
			break;
		default:
			objectiveNum = objective_NPCid;
			objectiveProgress = 0;

			NPCinteractId = 0;
			break;
		}
	}

	void QuestDialogs(const char* available[DIALOG_LENGHT], const char* active[DIALOG_LENGHT], const char*  completed[DIALOG_LENGHT])
	{
		availableDialog[DIALOG_LENGHT] = available[DIALOG_LENGHT];
		activeDialog[DIALOG_LENGHT] = active[DIALOG_LENGHT];
		completedDialog[DIALOG_LENGHT] = completed[DIALOG_LENGHT];
	}

};


class QuestManager : public Module
{
public:

	QuestManager(App* application, bool start_enabled = true);
	~QuestManager();

	bool Awake(pugi::xml_node& config);
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();

	void CheckQuest(int NPCid);
	void CheckState(int ID);
	void GiveReward(int ID);
	void CheckChain(int ID);

	//// Load / Save
	//bool LoadState(pugi::xml_node&);
	//bool SaveState(pugi::xml_node&) const;
	

public:

	List<Quest*> questList;

};


#endif // !__QUEST_MANAGER_H__