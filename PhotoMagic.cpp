/*
 * Nuno Mestre
 * 09/24/2021
 * PhotoMagic.cpp encrypting image/main file
*/

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"

void transform(sf::Image& input_image, FibLFSR* fib);

int main(int argc, char* argv[]){
	//Declarations	
	sf::Image input_image;
	sf::Image output_image;
	sf::Sprite input_sprite;
	sf::Sprite output_sprite;
	sf::Texture input_texture;
	sf::Texture output_texture;
	string s(argv[3]);
	FibLFSR sixteen_bit_int(s);
	//load images from input file
	string inputFile(argv[2]);
	if (!input_image.loadFromFile(inputFile))
		return -1;
	if (!output_image.loadFromFile(inputFile))
                return -1;
	//set texture of first sprite to the original image
	input_texture.loadFromImage(input_image);
	input_sprite.setTexture(input_texture);
	//windows are made the size of the input image
	sf::Vector2u world = input_image.getSize();
	sf::RenderWindow window(sf::VideoMode(world.x, world.y), "PHOTO MAGIC");
        sf::RenderWindow window2(sf::VideoMode(world.x, world.y), "PHOTO MAGIC 2");
	//second image transforms to an ecrypted version
	transform(output_image, &sixteen_bit_int);
	//sets the new_sprites texture to the encrypted version
	output_texture.loadFromImage(output_image);
	output_sprite.setTexture(output_texture);

	string outputFile(argv[2]);

	while(window.isOpen() && window2.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}
		while(window2.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window2.close();
		}
		
		window.clear();
		window.draw(input_sprite);
		window.display();
		
		window2.clear();
		window2.draw(output_sprite);
		window2.display();
	}
	if(!output_image.saveToFile(outputFile))
		return -1;

	return 0;
}

void transform(sf::Image& input, FibLFSR* fib){
	sf::Color p;
	sf::Vector2u size = input.getSize();
	for(unsigned int x = 0; x < size.x; x++){
		for(unsigned int y = 0; y < size.y; y++){
			p = input.getPixel(x, y);
			FibLFSR rand(*fib);
			p.r = p.r ^ rand.generate(8);
			p.g = p.g ^ rand.generate(8);
			p.b = p.b ^ rand.generate(8);
			input.setPixel(x, y, p);
		}
	}
}
