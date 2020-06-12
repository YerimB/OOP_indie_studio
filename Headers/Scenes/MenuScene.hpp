#include <Scenes/Scene.hpp>

class MenuScene : public Scene
{
	public:
		MenuScene();
		~MenuScene();

	protected:
		void LoadSystems(GameManager*) override final;
		void LoadAssets(GameManager*) override final;
		void LoadElements(GameManager*) override final;

	public:
		void Load(GameManager* gameManager) override final;
		void Update(GameManager* gameManager) override final;
		void Unload(void) override final;

};