#pragma once
#include "settings.h"
#include "player.h"
#include "Meteor.h"
#include "textobj.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	std::vector<Meteor*> meteorSprites;
	TextObj lives;
	sf::RectangleShape rectangle;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void update() {
		player.update(player);
		for (auto m : meteorSprites) {
			m->update();
		}
		lives.update(std::to_string(player.getLives()));
		sf::RectangleShape rectangle(sf::Vector2f(width, 40));
		rectangle.setFillColor(sf::Color::Green);
		rectangle.setPosition(sf::Vector2f{ 0,0 });
	}
	void checkCollisions() {}
	void draw() {
		window.clear();
		window.draw(rectangle);
		window.draw(player.getSprite());
		for (auto m : meteorSprites) {
			window.draw(m->getSprite());
		}
		window.draw(lives.getText());
		window.display();
	}

public:
	Game() : window(sf::VideoMode(width, height), WINDOW_TITLE),
	lives(std::to_string(player.getLives()), sf::Vector2f{ width / 2,0.f }) 
    {
		window.setFramerateLimit(FPS);
		meteorSprites.reserve(meteor_qty);
		for (int i = 0; i < meteor_qty; i++) {
			Meteor* m = new Meteor();
			meteorSprites.push_back(new Meteor());
		}
	}

	void play() {
		while (window.isOpen())
		{
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}
};