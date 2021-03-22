#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

class Button
{
private:
	RectangleShape button;
	Text textButton;

public:
	Button();
	void initFont(Font& font);
	void setBackColor(Color color);
	void setTextColor(Color color);
	void setPosition(Vector2f pos);
	void renderButton(RenderTarget* target, string text, float buttonX, float buttonY);
	bool isMouseHover(RenderWindow& window);
	Vector2f getSize();

private:
	void initShape();
};

