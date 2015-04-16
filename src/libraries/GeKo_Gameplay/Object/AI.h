#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <iostream>
#include <string>

#include "GeKo_Gameplay/AI_Pathfinding/Graph.h"
#include "GeKo_Gameplay/AI_Pathfinding/AStarNode.h"
#include "GeKo_Gameplay/AI_Pathfinding/AStarAlgorithm.h"

#include "GeKo_Graphics/Scenegraph/BoundingSphere.h"

#include "GeKo_Gameplay/AI_Decisiontree/DecisionTree.h"
#include "GeKo_Gameplay/AI_Decisiontree/TreeOutput.h"

#include "Object.h"
#include "States.h"

enum SoundtypeAI{
	MOVESOUND_AI, EATSOUND_AI, DEATHSOUND_AI
};

class AI : public Object, public Subject<AI, Object_Event>
{
public: 

	AI();
	~AI();

	AStarNode* getPosHome();
	void setPosHome(AStarNode* pos);

	Graph<AStarNode, AStarAlgorithm>* getGraph();
	void setGraph(Graph<AStarNode, AStarAlgorithm>* graph);

	DecisionTree* getDecisionTree();
	void setDecisionTree(DecisionTree* tree);

	void addFoodNodes();

	//Per Frame
	void update();

	//Move Object on Terrain
	void move();

	void viewArea(bool state);

	/// A method to check if p1 and p2 are very near each other
	bool checkPosition(glm::vec3 p1, glm::vec3 p2);

	AStarNode* nearestFoodNode();

	float getViewRadius();

	void decide();
	void decide2();

	void updatePath();
	void updatePathPlayer();
	void updatePathPatrol();

	AStarNode* nextNodeOnPatrol();

	void setAntAfraid();
	void setAntAggressiv();

	///Returns the m_sourceName string
	/**If a Sound-File-Handler was attached, the m_sourceName contains the name of the source which should be played!*/
	std::string getSourceName(SoundtypeAI type);
	///Sets a specific source-file to the node
	/**This method uses the sfh to generate a new sound-source which can be played with the sfh later ingame!*/
	void setSourceName(SoundtypeAI type, std::string sourceName, const char* filepath);
	
	void updateSourcesInMap();

	bool hasDied();
	
protected:
	float m_epsilon;

	AStarNode* m_lastTarget;
	AStarNode* m_lastTargetOnGraph;
	AStarNode* m_target;
	std::vector<AStarNode*> m_path;
	std::vector<AStarNode*> m_pathPatrol;
	AStarNode* m_nextTarget;

	DecisionTree* m_decisionTree;

	Graph<AStarNode, AStarAlgorithm>* m_graph;

	BoundingSphere* m_view;
	float m_viewRadius;

	TreeOutput m_targetType;

	AStarNode* m_homeNode;
	std::vector<AStarNode*> m_foodNodes;

	std::map<SoundtypeAI, std::string> m_soundMap;
	bool m_hasDied;

};