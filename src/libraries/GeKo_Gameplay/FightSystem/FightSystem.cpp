#include "FightSystem.h"

FightSystem::FightSystem()
{
}

FightSystem::~FightSystem()
{
}

void FightSystem::objectVSobject(Object* o1, Object* o2){
	o2->setHealth(o2->getHealth() - o1->getStrength());
	o1->setHealth(o1->getHealth() - o2->getStrength());
	std::cout << "Fight: Health O1: " << o1->getHealth() << " Health O2: " << o2->getHealth() << std::endl;
	if (o1->getHealth() <= 0)
	{
		notify(*this, Quest_Event::GOAL_FINISHED);
	}
}