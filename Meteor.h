#pragma once
#include "settings.h"

class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
	static std::string mFileNames[];
	void spawn() {
		speedy = rand() % 6 + 2;
		//speedx от -2 до 5
		speedx = rand() % 5 - 2;
		//позиция случайная по х в границах окна 
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float x = rand() % (int)(width - bounds.width);
		//по у выше верхнего края экрана 
		float y = -(rand() % (int)(width - bounds.width) + bounds.height);
		sprite.setPosition(x, y);
	}
public:
	Meteor() {
		int index = rand() % meteor_type_qty;
		texture.loadFromFile(im_folder + mFileNames[index]);
		sprite.setTexture(texture);
	}
	void update() {
		sprite.move(speedx, speedy);
		sf::FloatRect bounds =sprite.getGlobalBounds();
		if (bounds.left < -bounds.width || bounds.left > width || bounds.top > height)
		{
			spawn();
		}
	}
	sf::Sprite getSprite() { return sprite; }
};
 std::string  Meteor::mFileNames[] = { "meteorGrey_big1.png", "meteorGrey_big2.png" , "meteorGrey_med1.png","meteorGrey_med2.png","meteorGrey_small1.png","meteorGrey_small2.png","meteorGrey_tiny1.png","meteorGrey_tiny2.png" };
