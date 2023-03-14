#pragma once
#include "settings.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx = 0.f;
	int lives = 3;
public:
	Player() {
		texture.loadFromFile(im_folder + player_file_name);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		sprite.setPosition((width - bounds.width) / 2, height - bounds.height - 10.f);
	}
	void update(Player& player) {

		player.speedx = 0.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			player.speedx = -player_speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			player.speedx = player_speed;
		player.sprite.move(player.speedx, 0.f);
		//ReboundEdges
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float playerx = player.sprite.getPosition().x;
		float playery = player.sprite.getPosition().y;
		if (playerx <= 0)player.sprite.setPosition(0.f, playery);
		if (playerx >= width - bounds.width)
			player.sprite.setPosition(width -bounds.width, playery);
	}
	sf::Sprite getSprite() { return sprite; }	
	int getLives() { return lives; }
	void incLives() { lives++; }
	void decLives() { lives--; }
};
