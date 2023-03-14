#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class TextObj {
private:
	sf::Font font;
	sf::Text text;
public:
	TextObj(std::string str, sf::Vector2f pos) {
		font.loadFromFile(res_folder + font_file_name);
		text.setString(str);
		text.setFont(font);
		text.setCharacterSize(char_size);
		text.setPosition(pos);
	}

	void update(std::string str) {
		text.setString(str);
	}

	sf::Text getText() { return text; }
};