#include <Scenes/Scene.hpp>

class MenuScene : public Scene
{
	public:
		MenuScene();
		~MenuScene();

	public:
		void Load(GameManager* gameManager) override final;

};