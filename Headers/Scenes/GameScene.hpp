#include <Scenes/Scene.hpp>

class GameScene : public Scene
{
	public:
		GameScene();
		~GameScene();

	public:
		void Load(GameManager* gameManager) override final;
};