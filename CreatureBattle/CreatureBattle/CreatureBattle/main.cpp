/*
Creator: 
	zzDeagle545zz
		Deagle Corp Productions
Contributors:
	FattyKakeHero
		Private: Concept Artist
Project:
	Creature Battle Game
Development Tools:
	VisualStudio-IDE
	CMake-Compiling
	SFML-Utility Libraries
	OpenGl- Graphics
*/

//Simple and Fast MultiMedia Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void Menu();

//******************************************************************************
//******************************************************************************
//                                   Main
//Function- Execution Begins Here
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv){
//Declare Variables
	Menu();
	return 0;
}
//******************************************************************************
//******************************************************************************
//                                 Menu
//Function-Displays the Menu part of the GUI
//Inputs
//      --->None
//Outputs
//      <---None
////////////////////////////////////////////////////////////////////////////////
void Menu(){
//Declare Variables

//Main Window to draw too
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Creature Battle");
//Images
	sf::Image icon;									//Window Icon
//Menu Buttons
	sf::RectangleShape Start(sf::Vector2f(500, 40));
	sf::RectangleShape Optns(sf::Vector2f(500, 40));
	sf::RectangleShape htPly(sf::Vector2f(500, 40));
//Menu Half-Buttons
	sf::RectangleShape sub11(sf::Vector2f(220, 40));
	sf::RectangleShape sub12(sf::Vector2f(220, 40));
	sf::RectangleShape sub21(sf::Vector2f(220, 40));
	sf::RectangleShape sub22(sf::Vector2f(220, 40));
//Background
	sf::RectangleShape Bk(sf::Vector2f(1280, 720));
//Teaxtures
	sf::Texture *mBttns = new sf::Texture;			//Button Texture
	sf::Texture *bkTexture = new sf::Texture;		//BackGround Image
//Fonts
	sf::Font mbFont;								//Button Font
	sf::Font tFont;									//Title Font
//Music
	sf::Music bkMsc;								//Music
//Text
	sf::Text Title("CreatureBattle", tFont, 100);
	sf::Text tStart("Start Game", mbFont, 30);
	sf::Text tOptns("Options", mbFont, 30);
	sf::Text tQuit("Quit", mbFont, 30);
//Load Data From File
	try {
		//Load Textures
		if (!mBttns->loadFromFile("Resources/Textures/mButtons.png")) {
			throw "Fail to Load";
		}
		if (!bkTexture->loadFromFile("Resources/Images/mBackground.png")) {
			throw "Fail to Load";
		}
		//Load Fonts
		if (!mbFont.loadFromFile("Resources/Fonts/Xolonium-R.otf")) {
			throw "Fail to Load";
		}
		if (!tFont.loadFromFile("Resources/Fonts/BBrick-R.otf")) {
			throw "Fail to Load";
		}
		//Load Music
		if (!bkMsc.openFromFile("Resources/Sounds/Test.ogg")) {
			throw "Fail to Load";
		}
	}
	catch (char* msg) {

	}

	bkMsc.play();
//Config Text
	tStart.setColor(sf::Color::Black);
	Title.setColor(sf::Color::Black);
	Start.setOutlineThickness(5);
	Start.setOutlineColor(sf::Color::Black);
	Optns.setOutlineThickness(5);
	Optns.setOutlineColor(sf::Color::Black);
	htPly.setOutlineThickness(5);
	htPly.setOutlineColor(sf::Color::Black);
	sub11.setOutlineThickness(5);
	sub11.setOutlineColor(sf::Color::Black);
	sub12.setOutlineThickness(5);
	sub12.setOutlineColor(sf::Color::Black);
	sub21.setOutlineThickness(5);
	sub21.setOutlineColor(sf::Color::Black);
	sub22.setOutlineThickness(5);
	sub22.setOutlineColor(sf::Color::Black);

	//Game Loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
		}

		window.clear();
		//Set Positions
		//center text
		sf::FloatRect textRect= tStart.getLocalBounds();
		tStart.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
		tStart.setPosition(640,320);
		sf::FloatRect tRect = Title.getLocalBounds();
		Title.setOrigin(tRect.left + tRect.width / 2.0f,
			tRect.top + tRect.height / 2.0f);
		Title.setPosition(640, 150);

		Start.setPosition(390, 300);
		Optns.setPosition(390, 380);
		htPly.setPosition(390, 460);
		//tStart.setPosition(640, 360);
		sub11.setPosition(390, 540);
		sub12.setPosition(670, 540);
		sub21.setPosition(390, 620);
		sub22.setPosition(670, 620);

		//Set Textures for Menu Buttons
		Bk.setTexture(bkTexture);
		Start.setTexture(mBttns);
		Optns.setTexture(mBttns);
		htPly.setTexture(mBttns);
		sub11.setTexture(mBttns);
		sub12.setTexture(mBttns);
		sub21.setTexture(mBttns);
		sub22.setTexture(mBttns);

		//Draw Shapes
		window.draw(Bk);
		window.draw(Start);
		window.draw(Optns);
		window.draw(htPly);
		window.draw(tStart);
		window.draw(sub11);
		window.draw(sub12);
		window.draw(sub21);
		window.draw(sub22);
		window.draw(Title);

		window.display();
	}
	delete mBttns;

}