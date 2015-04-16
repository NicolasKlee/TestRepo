#pragma once
#include <glm/ext.hpp>
#include <GeKo_Graphics/Observer/Observer.h>
#include <GeKo_Graphics/Scenegraph/Node.h>

/**Handles all the gravity-effects of the game.*/
class GravityObserver : public Observer<Node, Collision_Event>
{
public:
	GravityObserver(Level* level){ m_level = level; }

	~GravityObserver(){}

	void onNotify(Node& node, Collision_Event event)
	 {
		 switch (event)
		 {
		 case Collision_Event::PLANE_COLLISION:

			 if (m_level->hasTerrain())
			 {
				 Terrain* tmp = m_level->getTerrain();

				 if (node.getType() == ClassType::OBJECT)
				 {
					 break;
				 }
				 else if (node.getType() == ClassType::PLAYER){
					 float height = tmp->getHeight(glm::vec2(node.getPlayer()->getPosition().x, node.getPlayer()->getPosition().z));
					 if (node.getPlayer()->getPosition().y <= height + 0.5f){
						 node.setGravity(false);
						 node.getPlayer()->setPosition(glm::vec3(node.getPlayer()->getPosition().x, height + 0.5f, node.getPlayer()->getPosition().z));
						 if (node.hasCamera())
							 node.getCamera()->setCenter(glm::vec4(node.getPlayer()->getPosition(), 1.0));
					 }
					 else if (true)
					 {
						 node.setGravity(true);
					 }
				 }

				 else if (node.getType() == ClassType::AI)
				 {
					 float height = tmp->getHeight(glm::vec2(node.getAI()->getPosition().x, node.getAI()->getPosition().z));
					 if (node.getAI()->getPosition().y < height + 0.5f){
						 node.setGravity(false);
						 node.getAI()->setPosition(glm::vec3(node.getAI()->getPosition().x, height + 0.5f, node.getAI()->getPosition().z));
					 }
					 else if (true)
					 {
						 node.setGravity(true);
					 }
				 }
			 }
			 else
			 {
				 if (node.getType() == ClassType::OBJECT)
				 {
					 break;
				 }
				 else if (node.getType() == ClassType::PLAYER){
					 float height = 0.5;
					 if (node.getPlayer()->getPosition().y <= height ){
						 node.setGravity(false);
						 node.getPlayer()->setPosition(glm::vec3(node.getPlayer()->getPosition().x, height, node.getPlayer()->getPosition().z));
						 if (node.hasCamera())
							 node.getCamera()->setCenter(glm::vec4(node.getPlayer()->getPosition(), 1.0));
					 }
					 else if (true)
					 {
						 node.setGravity(true);
					 }
				 }

				 else if (node.getType() == ClassType::AI)
				 {
					 float height = 0.5;
					 if (node.getAI()->getPosition().y < height){
						 node.setGravity(false);
						 node.getAI()->setPosition(glm::vec3(node.getAI()->getPosition().x, height, node.getAI()->getPosition().z));
					 }
					 else if (true)
					 {
						 node.setGravity(true);
					 }
				 }
			 }
			 break;

		 }
	 }

	void  onNotify(AI& node, Collision_Event event) 
	 {

	 }

protected:
	Level* m_level;
};