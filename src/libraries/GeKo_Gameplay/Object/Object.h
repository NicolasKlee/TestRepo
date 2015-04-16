#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <iostream>
#include <string>

#include "GeKo_Graphics/Observer/Subject.h"
#include "GeKo_Gameplay/Item/Inventory.h"
#include "GeKo_Sound/SoundFileHandler.h"

#include "ObjectType.h"
#include "ClassType.h"
#include "States.h"

class Object
{
public: 
	Object();
	~Object();

	void setPosition(glm::vec3 pos);

	glm::vec3 getPosition();

	float getStrength();

	void setHealth(float newHealth);
	float getHealth();

	void setNodeName(std::string nodeName);
	std::string getNodeName();

	Inventory* getInventory();

	void setObjectType(ObjectType type);
	ObjectType getObjectType();

	void setClassType(ClassType type);
	ClassType getClassType();

	glm::vec3 getViewDirection();

	bool getStates(States state);
	void setStates(States state, bool b);

	virtual void update();
	void updateStates();

	///Moves Object on Terrain
	virtual void move();

	virtual void eat();

	void collectItem(ItemType typeId, int count);

	virtual void heal();

	float getExp();
	void addExp(float exp);
	void setExp(float exp);

	int getLvl();
	void levelUp();
	void setLevel(int level);

	float getLevelThreshold();
	void setLevelThreshold(float threshold);

	///Returns the m_sfh
	/**This Handler manages all the sounds of an object like the movement of a Player etc.*/
	SoundFileHandler* getSoundHandler();
	void setSoundHandler(SoundFileHandler* soundHandler);

protected:
	int m_id;
	ObjectType m_type;
	std::string m_name;
	std::string m_myNodeName;
	ClassType m_class;

	glm::vec3 m_position;

	glm::vec3 m_viewDirection;

	std::vector<std::pair<States, bool>> m_states;
	float m_hunger;
	float m_hungerMax;
	float m_health;
	float m_healthMax;
	float m_speed;
	float m_strength;
	float m_exp;
	int m_level;
	float m_levelThreshold;

	Inventory* m_inventory;
	SoundFileHandler* m_sfh;

	bool m_hasSound;
};