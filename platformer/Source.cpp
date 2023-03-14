#include<iostream>
using namespace std;
#include "SFML/Graphics.hpp"
int yes = 100;
int main() {
	cout << "platformer game!" << endl;
	//set up
	sf::RenderWindow screen(sf::VideoMode(800, 800), "PLAAAAaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaAAAAAAAAAAAAAAAAAAAAAAAAAATFORMER");
	sf::Event event; //holds keyboard input and whatnotz
	sf::Clock clock; //clock setup
	const float FPS = 60.0f; //fps baybe
	screen.setFramerateLimit(FPS);
	// player set up
	sf::RectangleShape player(sf::Vector2f(30, 30)); //player size 30x30
	player.setFillColor(sf::Color(244, 133, 0));
	float xpos = 25;
	float ypos = 25;
	player.setPosition(xpos, ypos);
	// player velocity
	float vx = .0;
	float vy = .0;
	bool isOnGround = false;
	bool keys[] = { false, false, false, false }; // keeps track of keyboard presses
	// GAME LOOP ---------------------------
	while (screen.isOpen()) {
		// input section -----------------------
		while (screen.pollEvent(event)) {

			//checks if user clicks the x button in the corner
			if (event.type == sf::Event::EventType::Closed)
				screen.close();
			//keyboard input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) keys[2] = true;
			else keys[2] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) keys[0] = true;
			else keys[0] = false;
		}

		// physics section ---------------------
			//JUMPING

		if (ypos + 30 > 800) { //check if were on the bottom of the screen
			isOnGround = true;
			ypos = 800 - 30; // reset position so feet are on the ground
		}
		else
			isOnGround = false;
			// apply gravity if not on ground
		if (isOnGround == false) {
			vy += 1;
			if (vy > 5)//set terminal/maximum velocity
				vy = 5;
		}
			// move the player
		if (keys[2] == true)
			if (isOnGround == true) {
				vy = -15;
				isOnGround = false;
			}
			// right movement
		if (keys[0] == true)
			vx = 8;
		else
			vx = 0;
		xpos += vx;
		ypos += vy;
		player.setPosition(xpos, ypos);

		// render section ----------------------
		screen.clear();
		screen.draw(player);
		screen.display();

	}
	// END OF GAME LOOP -------------------
}
	