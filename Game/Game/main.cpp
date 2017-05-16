#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GameSFML");
	sf::CircleShape circle(100.f);
	circle.setFillColor(sf::Color::Red);
	sf::RectangleShape rectangle(sf::Vector2f(100,100));
	rectangle.setFillColor(sf::Color::Green);

	sf::Texture texture;
	texture.loadFromFile("C:/Users/822/Desktop/GameSFML/Textura.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	//sprite.scale(sf::Vector2f(0.5f, 2.f));

	float x, y;
	x = y = 0;

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		    rectangle.move(0.05, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			rectangle.move(-0.05, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			rectangle.move(0, 0.05);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			rectangle.move(0, -0.05);
	
		circle.setPosition(x, y);
		if(x < window.getSize().x - circle.getGlobalBounds().width)
		    x += 0.01; 
		if (y < window.getSize().y - circle.getGlobalBounds().height)
		    y += 0.01;

		window.clear(sf::Color::White);
		window.draw(circle);
		window.draw(rectangle);
		window.draw(sprite);
		window.display();
	}

	return 0;
}