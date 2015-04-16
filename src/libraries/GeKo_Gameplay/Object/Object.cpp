#include "GeKo_Gameplay/Object/Object.h"

Object::Object()
{
		m_id = 0;
		m_type = ObjectType::DEFAULTOBJECT;
		m_name = "defaultObject";
		m_myNodeName = "NULL";
	
		m_hunger = 10;
		m_hungerMax = 10;
		m_health = 10;
		m_healthMax = 10;
		m_strength = 0.5;
		m_exp = 0.0;
		m_level = 0;
		m_levelThreshold = 100;
	
		m_speed = 0.01;
	
		m_position = glm::vec3(0.0);
	
		m_inventory = new Inventory();
		
		m_class = ClassType::OBJECT;

		std::pair<States, bool> s(States::DEFAULTSTATE, false);
		m_states.push_back(s);
		m_hasSound = false;
}

Object::~Object(){}

void Object::setPosition(glm::vec3 pos){
	m_position = pos;
}

glm::vec3 Object::getPosition()
{
	return m_position;
}

float Object::getStrength(){
	return m_strength;
}

void Object::setHealth(float newHealth){
	m_health = newHealth;
}

float Object::getHealth(){
	return m_health;
}

void Object::setNodeName(std::string nodeName)
{
	m_myNodeName = nodeName;
}

std::string Object::getNodeName()
{
	return m_myNodeName;
}

Inventory* Object::getInventory()
{
	return m_inventory;
}

void Object::setObjectType(ObjectType type)
{
	m_type = type;
}

ObjectType Object::getObjectType()
{
	return m_type;
}

glm::vec3 Object::getViewDirection()
{
	return m_viewDirection;
}

bool Object::getStates(States state){
	for (int i = 0; i < m_states.size(); i++){
		if (m_states.at(i).first == state) {
			return m_states.at(i).second;
		}
	}
	return NULL;
}

void Object::setStates(States state, bool b){
	for (int i = 0; i < m_states.size(); i++){
		if (m_states.at(i).first == state){
			m_states.at(i).second = b;
		}
	}
}

void Object::update(){
}

void Object::updateStates(){
	if (m_hunger > 0){
		m_hunger -= 0.01;
		if (m_hunger <= m_hungerMax / 2){
			std::cout << "Object" << m_name << ": Is hungry! Hunger: " << m_hunger << std::endl;
			setStates(States::HUNGER, true);
		}
		else {
			if (m_health < m_healthMax)
				m_health++;
		}
	}
	else {
		m_health--;
		std::cout << "Object looses health because it is too hungry!" << std::endl;
	}
	if (m_health == 0){
		std::cout << "Player: Died because he was too hungry" << std::endl;
		setStates(States::HEALTH, false);
	}
}

void Object::move(){}

void Object::eat(){
	m_hunger = m_hungerMax;
	std::cout << "Object" << m_name << ": Has eaten." << std::endl;
	setStates(States::HUNGER, false);
}

void Object::collectItem(ItemType typeId, int count){
	for (int i = 0; i < count; i++){
		m_inventory->addItem(typeId);
	}
}

void Object::setClassType(ClassType type)
{
	m_class = type;
}

ClassType Object::getClassType()
{
	return m_class;
}

void Object::heal()
{
}

float Object::getExp()
{
	return m_exp;
}

void Object::addExp(float exp)
{
	m_exp += exp;
	while (m_exp >= m_levelThreshold)
	{
		levelUp();
	}
}

void Object::setExp(float exp)
{
	m_exp = exp;
	while (m_exp >= m_levelThreshold)
	{
		levelUp();
	}
}

int Object::getLvl()
{
	return m_level;
}

void Object::levelUp()
{
	if (m_exp >= m_levelThreshold)
	{
		m_level++;
		m_exp = m_exp - m_levelThreshold;
		m_levelThreshold *= m_level;
	}
}

void Object::setLevel(int level)
{
	m_level = level;
}

float Object::getLevelThreshold()
{
	return m_levelThreshold;
}

void Object::setLevelThreshold(float threshold)
{
	m_levelThreshold = threshold;
}

SoundFileHandler* Object::getSoundHandler()
{
	if (m_hasSound)
	{
		return m_sfh;
	}
	else
	{
		std::cout << "ERROR: The Node has no SoundFileHandler attached!" << std::endl;
		return 0;
	}
}

void Object::setSoundHandler(SoundFileHandler* soundHandler)
{
	m_hasSound = true;
	m_sfh = soundHandler;
}