#include <stddef.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include "Media/Pieces/GameObject.h"

using namespace std;
using namespace sf;

typedef unordered_map<string, GameObject*> HashTable;
typedef vector<GameObject*> List;

class GameObjectManager : sf::NonCopyable
{

public:
    static GameObjectManager* getInstance();
    GameObject* findObjectByName(string name);
    List getAllObjects();
    int activeObjects();
    void processInput(Event event, RenderWindow* window);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow* window);
    void addObject(GameObject* window);
    void deleteObject(GameObject* gameObject);
    void deleteObjectByName(string name);

private:
    // set constructor to private
    GameObjectManager() {};
    static GameObjectManager* sharedInstance;

    HashTable gameObjectMap;
    List gameObjectList;
};



