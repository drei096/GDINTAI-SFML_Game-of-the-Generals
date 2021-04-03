#include <SFML/Graphics.hpp>
#include <unordered_map>
using namespace std;
using namespace sf;

class TextureManager
{
public:
    static TextureManager* getInstance();

    void loadAll();
    sf::Texture* getTexture(std::string);
private:
    // set constructor to private
    TextureManager() {};
    // set copy contructor to private
    TextureManager(TextureManager const&) {};
    // assignment operator is private
    TextureManager& operator=(TextureManager const&) {};
    static TextureManager* sharedInstance;

    void loadTexture(string, string);
    std::unordered_map<string, Texture*> textureMap;
};