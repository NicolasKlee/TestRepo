////===================================================================//
////==================Your Includes===================================//
////==================================================================//
//#include <GL/glew.h>
//
//#include <GeKo_Graphics/InputInclude.h>
//#include <GeKo_Graphics/GeometryInclude.h>
//#include <GeKo_Graphics/Camera/StrategyCamera.h>
//#include <GeKo_Graphics/Camera/Pilotview.h>
//#include <GeKo_Graphics/ShaderInclude.h>
//
//#include <GeKo_Graphics/AIInclude.h>
////#include <GeKo_Gameplay/AI_DecisionTree/DecisionTree.h>
//#include <GeKo_Gameplay/Object/Geko.h>
//#include <GeKo_Gameplay/Object/AI.h>
//
//#include <GeKo_Graphics/Geometry/AntMesh.h>
//#include <GeKo_Graphics/Geometry/TreeMesh.h>
//#include <GeKo_Graphics/Geometry/GekoMesh.h>
//#include <GeKo_Graphics/Geometry/Plane.h>
//
//
//#include <GeKo_Physics/CollisionTest.h>
//
//#include <GeKo_Graphics/Observer/ObjectObserver.h>
//#include <GeKo_Graphics/Observer/CollisionObserver.h>
//#include <GeKo_Graphics/Observer/GravityObserver.h>
//#include <GeKo_Graphics/Observer/SoundObserver.h>
//#include <GeKo_Graphics/Observer/QuestObserver.h>
//
//#include <GeKo_Graphics/Geometry/ForestData.h>
//
////===================================================================//
////==================Things you need globally==========================//
////==================================================================//
//InputHandler iH;
//StrategyCamera cam("StrategyCam");
//Geko geko("Geko", glm::vec3(10.0, 3.0, -5.0));
//
////===================================================================//
////==================Callbacks for the Input==========================//
////==================================================================//
//
////void generateTrees()
//
//void playKey_callback(GLFWwindow* window)
//{
//	//Recognizing if the player wants to move its character
//	if (glfwGetKey(window, GLFW_KEY_UP))
//	{
//		geko.moveForward();
//	}
//	if (glfwGetKey(window, GLFW_KEY_DOWN))
//	{
//		geko.moveBackward();
//	}
//	if (glfwGetKey(window, GLFW_KEY_RIGHT))
//	{
//		geko.moveRight();
//	}
//	if (glfwGetKey(window, GLFW_KEY_LEFT))
//	{
//		geko.moveLeft();
//	}
//
//}
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
//	std::map<int, std::function<void()>> activeMap = iH.getActiveInputMap()->getMap();
//
//	iH.getActiveInputMap()->setGLFWwindow(window);
//
//	for (std::map<int, std::function<void()>>::iterator it = activeMap.begin(); it != activeMap.end(); it++){
//		if (it->first == key)
//			activeMap.at(key)();
//		if (it == activeMap.end())
//			std::cout << "Key is not mapped to an action" << std::endl;
//	}
//}
//
//void mouse_callback(GLFWwindow* window)
//{
//	int i = 0;
//	if (glfwGetMouseButton(window, i) == GLFW_PRESS)
//	{
//		std::map<int, std::function<void()>> activeMap = iH.getActiveInputMap()->getMap();
//
//		iH.getActiveInputMap()->setGLFWwindow(window);
//
//		for (std::map<int, std::function<void()>>::iterator it = activeMap.begin(); it != activeMap.end(); it++){
//			if (it->first == i)
//				activeMap.at(i)();
//			if (it == activeMap.end())
//				std::cout << "Key is not mapped to an action" << std::endl;
//		}
//	}
//	else{
//		cam.updateCursor(window);
//	}
//}
//
//void mouseScroll_callback(GLFWwindow* window, double offsetX, double offSetY)
//{
//
//	std::map<int, std::function<void()>> activeMap = iH.getActiveInputMap()->getMap();
//
//	iH.getActiveInputMap()->setGLFWwindow(window);
//
//	if (offSetY < 0)
//	{
//		for (std::map<int, std::function<void()>>::iterator it = activeMap.begin(); it != activeMap.end(); it++){
//			if (it->first == 001)
//				activeMap.at(001)();
//			if (it == activeMap.end())
//				std::cout << "Key is not mapped to an action" << std::endl;
//		}
//	}
//	else{
//		for (std::map<int, std::function<void()>>::iterator it = activeMap.begin(); it != activeMap.end(); it++){
//			if (it->first == 002)
//				activeMap.at(002)();
//			if (it == activeMap.end())
//				std::cout << "Key is not mapped to an action" << std::endl;
//		}
//	}
//}
//
////===================================================================//
////==================Main Method=====================================//
////==================================================================//
//int main()
//{
//
//	//===================================================================//
//	//==================Things you need to start with====================//
//	//==================================================================//
//	glfwInit();
//
//	Window testWindow(500, 50, 800, 600, "testWindow");
//	glfwMakeContextCurrent(testWindow.getWindow());
//
//	cam.setCenter(glm::vec4(0.0, 10.0, 20.0, 1.0));
//	cam.setName("StrategyCam");
//	cam.setKeySpeed(2.0);
//	cam.setNearFar(0.0001, 100);
//
//	glfwSetKeyCallback(testWindow.getWindow(), key_callback);
//	glfwSetScrollCallback(testWindow.getWindow(), mouseScroll_callback);
//
//	glewInit();
//
//	OpenGL3Context context;
//	Renderer renderer(context);
//
//	//===================================================================//
//	//==================Shaders for your program========================//
//	//==================================================================//
//	VertexShader vs(loadShaderSource(SHADERS_PATH + std::string("/TextureShader3D/TextureShader3D.vert")));
//	FragmentShader fs(loadShaderSource(SHADERS_PATH + std::string("/TextureShader3D/TextureShader3D.frag")));
//	ShaderProgram shader(vs, fs);
//
//
//	//===================================================================//
//	//==================A Graph for the AI-Unit=========================//
//	//==================================================================//
//
//	glm::vec3 posFood(10.0, 0.0, -5.0);
//	glm::vec3 posSpawn(10.0, 0.0, 60.0);
//	Graph<AStarNode, AStarAlgorithm> testGraph;
////	testGraph.setExampleGraph2(posSpawn, posFood, geko.getPosition());
//
//	//===================================================================//
//	//==================A Decision-Tree for the AI-Unit==================//
//	//==================================================================//
//
//	DecisionTree defaultTree;
//	defaultTree.setAntTreeAggressiv();
//
//
//	//===================================================================//
//	//==================Object declarations - Geometry, Texture, Node=== //
//	//==========================Object: AI==============================//
//
//	Teapot teaAnt;
//
//	Texture texPlayer((char*)RESOURCES_PATH "/Snake.jpg");
//	SoundFileHandler sfh = SoundFileHandler(1000);
//
//	//AStarNode defaultASNode("Default");
//	//AI ant_Flick(&defaultTree, &defaultASNode, &aiNode);
//	AI ant_Flick;
//	ant_Flick.setAntAfraid();
//	/*ant_Flick.setGraph(&testGraph);
//	ant_Flick.setPosition(posSpawn);
//	ant_Flick.setPosHome(testGraph.searchNode("Spawn"));*/
//	//ant_Flick.addFoodNodes(testGraph.searchNode("Food"));
//
//	AntMesh ant;
//
//	Node aiNode("Flick");
//	aiNode.addGeometry(&ant);
//	aiNode.addTexture(&texPlayer);
////	aiNode.addScale(0.3, 0.3, 0.3);
//	//aiNode.addTranslation(ant_Flick.getPosition().x, ant_Flick.getPosition().y, ant_Flick.getPosition().z);
//	aiNode.setObject(&ant_Flick);
//	aiNode.setSoundHandler(&sfh);
//	aiNode.setSourceName("Ameise1", RESOURCES_PATH "/Sound/Footsteps.wav");
//	glm::vec3 testpos = {3.0, 0.0, 3.0};
//	sfh.generateSource("Ameise",testpos, RESOURCES_PATH "/Sound/rascheln.wav");
//	sfh.playSource("Ameise");
//
//
//
//
//
//	//===================================================================//
//	//==================Object declarations - Geometry, Texture, Node=== //
//	//==========================Object: Player===========================//
//	Teapot teaPlayer;
//	Texture texCV((char*)RESOURCES_PATH "/cv_logo.bmp");
//
//	GekoMesh gekoMesh;
//	geko.setExp(0.0);
//	geko.setLevelThreshold(100.0);
//	geko.setLevel(0);
//
//	Node playerNode("Player");
//
//	playerNode.addGeometry(&gekoMesh);
//	playerNode.setObject(&geko);
//	playerNode.addTexture(&texCV);
////	playerNode.addScale(0.5, 0.5, 0.5);
////	playerNode.addTranslation(20.0, 0.0, 20.0);
//
//	geko.setSoundHandler(&sfh);
//	//geko.setSourceName(MOVESOUND, "SpielerFootsteps", RESOURCES_PATH "/Sound/rascheln.wav");
//	//geko.setSourceName(BACKGROUNDMUSIC, "Hintergrund", RESOURCES_PATH "/Sound/jingle2.wav");
//	geko.setSourceName(FIGHTSOUND, "Kampfsound", RESOURCES_PATH "/Sound/Cookies kurz.wav");
//	//geko.setSourceName(EATSOUND, "Essen", RESOURCES_PATH "/Sound/Munching.wav");
//	geko.setSourceName(QUESTSOUND, "Quest", RESOURCES_PATH "/Sound/jingle.wav");
//	geko.setSourceName(ITEMSOUND, "Item", RESOURCES_PATH "/Sound/itempickup.wav");
//	sfh.disableLooping("Essen");
//	sfh.disableLooping("Kampfsound");
//	sfh.disableLooping("Quest");
//	sfh.disableLooping("Item");
//	sfh.generateSource("Feuer",posFood, RESOURCES_PATH "/Sound/Feuer kurz.wav");
//
//
//
//	playerNode.setCamera(&cam);
//
//	// ==============================================================
//	// == Items =====================================================
//	// ==============================================================
//	/*Item cookie(1);
//	cookie.setName("Cookie");
//	cookie.setTypeId(ItemType::COOKIE);
//	Item cookie2(2);
//	cookie.setName("Cookie");
//	cookie.setTypeId(ItemType::COOKIE);
//	Item branch(3);
//	branch.setName("Branch");
//	branch.setTypeId(ItemType::BRANCH);
//*/
//
//	//===================================================================//
//	//==================Setting up the Level and Scene==================//
//	//==================================================================//
//
//	Level testLevel("testLevel");
//	Scene testScene("testScene");
//	testLevel.addScene(&testScene);
//	testLevel.changeScene("testScene");
//
//	//==================Add Camera to Scene============================//
//	testScene.getScenegraph()->addCamera(&cam);
//	testScene.getScenegraph()->setActiveCamera("StrategyCam");
//
//	//==================Set Input-Maps and activate one================//
//	iH.setAllInputMaps(*(testScene.getScenegraph()->getActiveCamera()));
//	iH.changeActiveInputMap("Strategy");
//
//	//==================Add Objects to the Scene=======================//
//	//==================Update the Bounding-Sphere 1st time============//
//	testScene.getScenegraph()->getRootNode()->addChildrenNode(&aiNode);
//	testScene.getScenegraph()->getRootNode()->addChildrenNode(&playerNode);
//
//	
//
//
//
//
//
//	//===================================================================//
//	//==================Object declarations - Geometry, Texture, Node=== //
//	//==========================Object: Tree===========================//
//
//	TreeMesh tree;
//
//	//glm::vec3 trees[11] = { glm::vec3(16.0, 0.0, 66.0), glm::vec3(23.0, 0.0, 64.0), glm::vec3(21.5, 0.0, 68.5), glm::vec3(15.0, 0.0, 71.5), glm::vec3(27.5, 0.0, 78.5), glm::vec3(28.0, 0.0, 67.0), glm::vec3(24.0, 0.0, 71.0), glm::vec3(29.0, 0.0, 74.0), glm::vec3(15.0, 0.0, 75.0), glm::vec3(8.0, 0.0, 76.0), glm::vec3(3.0, 0.0, 77.0) };
//	
//	
//	//std::vector<glm::vec3> trees;
//	/*trees.push_back(glm::vec3(16.0, 0.0, 76.0));
//	trees.push_back(glm::vec3(23.0, 0.0, 74.0));
//	trees.push_back(glm::vec3(21.5, 0.0, 78.5));
//	trees.push_back(glm::vec3(15.0, 0.0, 81.5));
//	trees.push_back(glm::vec3(27.5, 0.0, 88.5));
//	trees.push_back(glm::vec3(28.0, 0.0, 67.0));
//	trees.push_back(glm::vec3(24.0, 0.0, 71.0));
//	trees.push_back(glm::vec3(29.0, 0.0, 74.0));
//	trees.push_back(glm::vec3(15.0, 0.0, 75.0));
//	trees.push_back(glm::vec3(8.0, 0.0, 76.0));
//	trees.push_back(glm::vec3(3.0, 0.0, 77.0));*/
//
//	std::stringstream name;
//	for(int i = 0;i<TreeData::forest1.size();i++)
//	{
//		name << "Forest1Tree" << i;
//		std::string stringname = name.str() ;
//		StaticObject *treeStatic = new StaticObject();
//		treeStatic->setTree(50 / TreeData::forest1.size());
//		Node *treeNode = new Node(stringname);
//		treeNode->addGeometry(&tree);
//		treeNode->setObject(treeStatic);
//		treeNode->addTranslation(TreeData::forest1[i]);
//		treeNode->getBoundingSphere()->radius = 2.5;
//		testScene.getScenegraph()->getRootNode()->addChildrenNode(treeNode);
//		name.str("");
//	}
//	for (int i = 0; i<TreeData::forest2.size(); i++)
//	{
//		name << "Forest2Tree" << i;
//		std::string stringname = name.str();
//		StaticObject *treeStatic = new StaticObject();
//		treeStatic->setTree(50 / TreeData::forest2.size());
//		Node *treeNode = new Node(stringname);
//		treeNode->addGeometry(&tree);
//		treeNode->setObject(treeStatic);
//		treeNode->addTranslation(TreeData::forest2[i]);
//		treeNode->getBoundingSphere()->radius = 2.5;
//		testScene.getScenegraph()->getRootNode()->addChildrenNode(treeNode);
//		name.str("");
//	}
//	/*for (int i = 0; i<TreeData::forest2.size(); i++)
//	{
//		name << "Forest2Tree" << i;
//		std::string stringname = name.str();
//		StaticObject *treeStatic = new StaticObject();
//		treeStatic->setTree();
//		Node *treeNode = new Node(stringname);
//		treeNode->addGeometry(&tree);
//		treeNode->setObject(treeStatic);
//		treeNode->addTranslation(TreeData::forest2[i]);
//		treeNode->getBoundingSphere()->radius = 3.0;
//		testScene.getScenegraph()->getRootNode()->addChildrenNode(treeNode);
//		name.str("");
//	}*/
//
//
//
//
//	//treeStatic.getInventory()->addItem(&cookie, 25);
//	//treeStatic.getInventory()->addItem(&branch, 10);
//
//	//===================================================================//
//	//==================Object declarations - Geometry, Texture, Node=== //
//	//==========================Object: Plane===========================//
//
//	Plane terrain;
//	Texture terrainTex((char*)RESOURCES_PATH "/Grass.jpg");
//
//	Node terrainNode("Plane");
//	terrainNode.addGeometry(&terrain);
//	terrainNode.addTexture(&terrainTex);
//	terrainNode.addTranslation(0.0, -0.75, 0.0);
//	terrainNode.addRotation(90.0f, glm::vec3(1.0, 0.0, 0.0));
//	terrainNode.addScale(100.0, 100.0, 100.0);
//	testScene.getScenegraph()->getRootNode()->addChildrenNode(&terrainNode);
//	
//
//	
//
//
//
//	// ==============================================================
//	// == Questsystem ====================================================
//	// ==============================================================
//	//QuestHandler questhandler;
//
//	//testLevel.getQuestHandler()->getGraph()->setExampleGraph();
//	Quest questCollect(1);
//	questCollect.setActive(true);
//	Goal_Collect goalCollect(1);
//	Goal_Collect goalCollect3(3);
//	questCollect.addGoal(&goalCollect);
//	questCollect.addGoal(&goalCollect3);
//
//	Reward expReward(1);
//	expReward.setExp(100);
//	questCollect.addReward(&expReward);
//
//	Quest questCollect2(2);
//	questCollect2.setActive(true);
//	Goal_Collect goalCollect2(2);
//	questCollect2.addGoal(&goalCollect2);
//	questCollect2.addReward(&expReward);
//
//	goalCollect.setGoalCount(50);
//	goalCollect2.setGoalCount(50);
//	goalCollect3.setGoalCount(50);
//
//	goalCollect.setItemType(ItemType::BRANCH);
//	goalCollect2.setItemType(ItemType::BRANCH);
//	goalCollect3.setItemType(ItemType::COOKIE);
//
//	testLevel.getQuestHandler()->addQuest(&questCollect);
//	testLevel.getQuestHandler()->addQuest(&questCollect2);
//
//	//===================================================================//
//	//==================Setting up the Collision=========================//
//	//==================================================================//
//	CollisionTest collision;
//	collision.collectNodes(testScene.getScenegraph()->getRootNode());
//
//	//===================================================================//
//	//==================Setting up the Observers========================//
//	//==================================================================//
//	ObjectObserver aiObserver(&testLevel);
//	SoundObserver soundAIObserver(&testLevel);
//	ant_Flick.addObserver(&aiObserver);
//	ant_Flick.addObserver(&soundAIObserver);
//
//	ObjectObserver playerObserver(&testLevel);
//	SoundObserver soundPlayerObserver(&testLevel);
//	geko.addObserver(&playerObserver);
//	geko.addObserver(&soundPlayerObserver);
//
//	CollisionObserver colObserver(&testLevel);
//	collision.addObserver(&colObserver);
//	collision.addObserver(&soundPlayerObserver);
//
//	GravityObserver gravityObserver;
//	collision.addObserver(&gravityObserver);
//
//	QuestObserver questObserver(&testLevel);
//	questCollect.addObserver(&questObserver);
//	questCollect2.addObserver(&questObserver);
//	questCollect.addObserver(&soundPlayerObserver);
//	questCollect2.addObserver(&soundPlayerObserver);
//	
//	goalCollect.addObserver(&questObserver);
//	goalCollect2.addObserver(&questObserver);
//	goalCollect3.addObserver(&questObserver);
//
//	testLevel.getFightSystem()->addObserver(&questObserver);
//
//
//
//	//===================================================================//
//	//==================Setting up the Gravity===========================//
//	//==================================================================//
//	Gravity gravity;
//	playerNode.addGravity(&gravity);
//	aiNode.addGravity(&gravity);
//
//	//===================================================================//
//	//==================The Render-Loop==================================//
//	//==================================================================//
//	float lastTime = glfwGetTime();
//
//	Node* tmp = testLevel.getActiveScene()->getScenegraph()->searchNode("Plane");
//	tmp->getNodeName();
//
//	sfh.playSource("Feuer");
//	sfh.playSource("Hintergrund");
//	sfh.setGain("Hintergrund", 0.5f);
//	while (!glfwWindowShouldClose(testWindow.getWindow()))
//	{
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		
//		float currentTime = glfwGetTime();
//		float deltaTime = currentTime - lastTime;
//		lastTime = currentTime;
//		
//		mouse_callback(testWindow.getWindow());
//
//		
//		//===================================================================//
//		//==================Update your Objects per Frame here =============//
//		//==================================================================//
//		collision.update();
//
//		//ant_Flick.updateState();
//		ant_Flick.update();
//
//
//		//===================================================================//
//		//==================Input and update for the Player==================//
//		//==================================================================//
//
//		playKey_callback(testWindow.getWindow());
//		geko.update(deltaTime);
//
//		//===================================================================//
//		//==================Render your Objects==============================//
//		//==================================================================//
//		glEnable(GL_DEPTH_TEST);
//
//		shader.bind();
//		shader.sendMat4("viewMatrix", cam.getViewMatrix());
//		shader.sendMat4("projectionMatrix", cam.getProjectionMatrix());
//
//		testScene.render(shader);
//		shader.unbind();
//
//
//		glfwSwapBuffers(testWindow.getWindow());
//		glfwPollEvents();
//
//	}
//
//	glfwDestroyWindow(testWindow.getWindow());
//	glfwTerminate();
//
//	
//	return 0;
//
//}
//

int main()
{
	return 0;
}