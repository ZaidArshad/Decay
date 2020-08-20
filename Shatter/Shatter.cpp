#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include "Platform.h"

using namespace sf;

void Update(RectangleShape &rectangle);
void Draw(RenderWindow& window, RectangleShape &rectangle, Platform &platform);

int main()
{
	sf::RenderWindow window(VideoMode(1024, 576), "Shatter");
	window.setFramerateLimit(60);

	RectangleShape rectangle(Vector2f(50, 50));
	rectangle.setFillColor(Color::Green);
	rectangle.setOrigin(rectangle.getSize().x / 2.f, rectangle.getSize().y / 2.f);
	rectangle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
	rectangle.setFillColor(Color::Red);

	Platform platform(100, 25, 400, 300);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

		}

		Update(rectangle);
		Draw(window, rectangle, platform);

	}
	return 0;
};



void Update(RectangleShape &rectangle) {
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		rectangle.move(10, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		rectangle.move(-10, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		rectangle.move(0, 10);
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		rectangle.move(0, -10);
	}
}

void Draw(RenderWindow &window, RectangleShape &rectangle, Platform &platform) {
	window.clear(Color::Black);
	window.draw(platform.getShape());
	window.draw(rectangle);
	window.display();
}
