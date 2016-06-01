/*
Creator: 
	zzDeagle545zz
		Deagle Corp Productions
Contributors:
	FattyKakeHero
		Private: Concept Artist
	cutiepacheco
		Java Platform Analyst
Project:
	Creature Battle Game
Development Tools:
	VisualStudio-IDE
	CMake-Compiling
	SFML-Utility Libraries/Graphics
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
#include "Creature.h"
#include "Ability.h"

//Global Constants

//Function Prototypes
void Menu();void Optns();void gStart(sf::RenderWindow&);
void setLocal(sf::FloatRect*, sf::RectangleShape&);
void hitBox(sf::FloatRect*, sf::RectangleShape);
void setLocal(sf::FloatRect*, sf::Text&);
void hitBox(sf::FloatRect*, sf::Text);

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
	sf::ContextSettings settings;
	settings.antialiasingLevel=8;
//Menu
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
//Logo
	sf::RectangleShape Logo(sf::Vector2f(150, 150));
//Background
	sf::RectangleShape Bk(sf::Vector2f(1280, 720));
//Teaxtures
	sf::Texture *mBttns = new sf::Texture;			//Button Texture
	sf::Texture *bkTexture = new sf::Texture;		//BackGround Image
	sf::Texture *iLogo = new sf::Texture;			//BackGround Image
//Fonts
	sf::Font mbFont;								//Button Font
	sf::Font tFont;									//Title Font
//Music
	sf::Music bkMsc;								//Music
//Text
	sf::Text Title("Creature Battle", tFont, 100);
	sf::Text tStart("Start Game", mbFont, 30);
	sf::Text tOptns("Options", mbFont, 30);
	sf::Text thtPly("How To Play", mbFont, 30);
	sf::Text tSub11("Sub11", mbFont, 30);
	sf::Text tSub12("Sub12", mbFont, 30);
	sf::Text tSub21("Sub21", mbFont, 30);
	sf::Text tSub22("Exit", mbFont, 30);
	sf::Text Deagle("Deagle Corp Productions", mbFont, 20);
	//sf::Thread thread(&lSpin, Logo, window);
//Load Data From File
	try {
	//Load Textures
		if (!mBttns->loadFromFile("Resources/Textures/mButtons.png")) 
			throw "Fail to Load";
		if (!bkTexture->loadFromFile("Resources/Images/mBackground.png")) 
			throw "Fail to Load";
	//Load Images
		if (!iLogo->loadFromFile("Resources/Images/Logo.png"))
			throw "Fail to Load";
	//Load Fonts
		if (!mbFont.loadFromFile("Resources/Fonts/Xolonium-R.otf")) 
			throw "Fail to Load";
		if (!tFont.loadFromFile("Resources/Fonts/BBrick-R.otf")) 
			throw "Fail to Load";
	//Load Music
		if (!bkMsc.openFromFile("Resources/Sounds/MenuMusic.ogg")) 
			throw "Fail to Load";
		}
	catch (char* msg) {

	}
	bkMsc.setLoop(true);
	bkMsc.play();

//Config Text
	tStart.setColor(sf::Color::Black);
	Title.setColor(sf::Color(0,0,0,240));
	tOptns.setColor(sf::Color::Black);
	thtPly.setColor(sf::Color::Black);
	tSub11.setColor(sf::Color::Black);
	tSub12.setColor(sf::Color::Black);
	tSub21.setColor(sf::Color::Black);
	tSub22.setColor(sf::Color::Black);
//Configure Buttons
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
//Set Positions
	//Position Buttons
	sf::FloatRect* sRct= new sf::FloatRect;					//Start
	setLocal(sRct,Start);
	Start.setPosition(640, 300);
	hitBox(sRct, Start);
	sf::FloatRect* oRct = new sf::FloatRect;				//Opitions
	setLocal(oRct, Optns);
	Optns.setPosition(640, 380);
	hitBox(oRct, Optns);
	sf::FloatRect* hRct = new sf::FloatRect;				//HowtoPlay
	setLocal(hRct, htPly);
	htPly.setPosition(640, 460);
	hitBox(hRct, htPly);
	sf::FloatRect* aRct = new sf::FloatRect;				//Button 1
	setLocal(aRct, sub11);
	sub11.setPosition(500, 540);
	hitBox(aRct, sub11);
	sf::FloatRect * bRct = new sf::FloatRect;				//Button 2
	setLocal(bRct, sub12);
	sub12.setPosition(780, 540);
	hitBox(bRct, sub12);
	sf::FloatRect * cRct = new sf::FloatRect;				//Button 3
	setLocal(cRct, sub21);
	sub21.setPosition(500, 620);
	hitBox(cRct, sub21);
	sf::FloatRect * dRct = new sf::FloatRect;				//Button 4
	setLocal(dRct, sub22);
	sub22.setPosition(780, 620);
	hitBox(dRct, sub22);
//Position Text
	sf::FloatRect* tRct = new sf::FloatRect;				//Title
	setLocal(tRct, Title);
	Title.setPosition(640, 120);
	sf::RectangleShape test(sf::Vector2f(tRct->width, tRct->height));
	setLocal(tRct, test);
	test.setPosition(640, 120);
	test.setFillColor(sf::Color(255, 255, 255, 33));
	sf::FloatRect* tsRct = new sf::FloatRect;				//Start
	setLocal(tsRct, tStart);
	tStart.setPosition(640, 300);
	sf::FloatRect* toRct = new sf::FloatRect;				//Options
	setLocal(toRct, tOptns);
	tOptns.setPosition(640, 460);
	sf::FloatRect* thRct = new sf::FloatRect;				//HowToPlay
	setLocal(thRct, thtPly);
	thtPly.setPosition(640, 380);
	sf::FloatRect* atRct = new sf::FloatRect;				//Button1
	setLocal(atRct, tSub11);
	tSub11.setPosition(500, 540);
	sf::FloatRect* btRct = new sf::FloatRect;				//Button2
	setLocal(btRct, tSub12);
	tSub12.setPosition(780, 540);
	sf::FloatRect* ctRct = new sf::FloatRect;				//Button3
	setLocal(ctRct, tSub21);
	tSub21.setPosition(500, 620);
	sf::FloatRect* dtRct = new sf::FloatRect;				//Button4
	setLocal(dtRct, tSub22);
	tSub22.setPosition(780, 620);
	sf::FloatRect* DERct = new sf::FloatRect;				//Deagle Corp
	setLocal(DERct, Deagle);
	Deagle.setPosition(1100, 690);
//Position Images
	sf::FloatRect* lRct = new sf::FloatRect;				//Logo
	setLocal(lRct, Logo);
	Logo.setPosition(100, 620);
	

//Set Textures for Menu Position Buttons
	Bk.setTexture(bkTexture);
	Start.setTexture(mBttns);
	Optns.setTexture(mBttns);
	htPly.setTexture(mBttns);
	sub11.setTexture(mBttns);
	sub12.setTexture(mBttns);
	sub21.setTexture(mBttns);
	sub22.setTexture(mBttns);
	Logo.setTexture(iLogo);
	Logo.setFillColor(sf::Color(255, 255, 255, 150));
//Game Loop

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
		//Events
			//Closed
			if (event.type == sf::Event::Closed)
				window.close();
			//Resized
			if (event.type == sf::Event::Resized);
				//Do something
			//Exit
			if (dRct->contains(
			static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) &&
			(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
				window.close();
			//Start Game
			if (sRct->contains(
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) &&
				(sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
				window.clear();gStart(window);
			}

	//Menu Buttons Hover
		//Start
			if (sRct->contains(
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				Start.setOutlineColor(sf::Color::Color(80, 80, 80, 255));}
			else Start.setOutlineColor(sf::Color::Black);
		//Options
			if (oRct->contains(
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				Optns.setOutlineColor(sf::Color::Color(80, 80, 80, 255));}
			else Optns.setOutlineColor(sf::Color::Black);
		//How to Play
			if (hRct->contains(
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				htPly.setOutlineColor(sf::Color::Color(80, 80, 80, 255));}
			else htPly.setOutlineColor(sf::Color::Black);
		//Button 1
			if (aRct->contains(
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				sub11.setOutlineColor(sf::Color::Color(80, 80, 80, 255));}
			else sub11.setOutlineColor(sf::Color::Black);
		//Button 2
			if (bRct->contains(
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				sub12.setOutlineColor(sf::Color::Color(80, 80, 80, 255));}
			else sub12.setOutlineColor(sf::Color::Black);
		//Button 3
			if (cRct->contains(
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				sub21.setOutlineColor(sf::Color::Color(80, 80, 80, 255));}
			else sub21.setOutlineColor(sf::Color::Black);
		//Button 4
			if (dRct->contains(
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				sub22.setOutlineColor(sf::Color::Color(80, 80, 80, 255));}
			else sub22.setOutlineColor(sf::Color::Black);
	}
	//Display Window
		window.clear();
		//Draw Shapes
		window.draw(Bk);window.draw(test);
		window.draw(Start);
		window.draw(Optns);
		window.draw(htPly);
		window.draw(tStart);
		window.draw(sub11);
		window.draw(sub12);
		window.draw(sub21);
		window.draw(sub22);
		window.draw(Title);
		window.draw(tOptns);
		window.draw(thtPly);
		window.draw(tSub11);
		window.draw(tSub12);
		window.draw(tSub21);
		window.draw(tSub22);
		window.draw(Deagle);
		window.draw(Logo);
		
		window.display();
	}
//Delete Textures
	delete mBttns;delete bkTexture;delete iLogo;
//Delete Rects
	delete sRct;delete oRct;delete hRct;delete aRct;
	delete bRct;delete cRct;delete dRct;delete tRct;delete tsRct;
	delete toRct;delete thRct;delete lRct;delete DERct;
}
//******************************************************************************
//******************************************************************************
//                            Game Start
//Function-Starts the game
//Inputs
//      --->None
//Outputs
//      <---None
////////////////////////////////////////////////////////////////////////////////
void gStart(sf::RenderWindow& window) {
//Declare Variables

//BackGround
	sf::RectangleShape Bk(sf::Vector2f(1280, 720));
//Creature Description
	sf::RectangleShape cBttn11(sf::Vector2f(550, 125));
	sf::RectangleShape cBttn12(sf::Vector2f(550, 125));
	sf::RectangleShape cBttn21(sf::Vector2f(550, 125));
	sf::RectangleShape cBttn22(sf::Vector2f(550, 125));
	sf::RectangleShape cBttn31(sf::Vector2f(550, 125));
	sf::RectangleShape cBttn32(sf::Vector2f(550, 125));
//Fonts
	sf::Font tFont;
	sf::Font cFont;
//Text
	sf::Text Title("Choose Your Creature!", tFont, 80);
	sf::Text c11("Gigatary", cFont, 60);
	sf::Text c12("Teradon", cFont, 60);
	sf::Text c21("Gekasaurs", cFont, 60);
	sf::Text c22("Another", cFont, 60);
	sf::Text c31("Another", cFont, 60);
	sf::Text c32("Another", cFont, 60);
//Textures
	sf::Texture* bkTexture=new sf::Texture;
	sf::Texture* cStats = new sf::Texture;
//Load Textures
	if (!bkTexture->loadFromFile("Resources/Textures/SelectBackground.png"))
		throw "Fail to Load";
	if (!cStats->loadFromFile("Resources/Images/CreatureButton.png"))
		throw "Fail to Load";
//Load Font
	if (!tFont.loadFromFile("Resources/Fonts/BBrick-r.otf"))
		throw "Fail to Load";
	if (!cFont.loadFromFile("Resources/Fonts/Xolonium-R.otf"))
		throw "Fail to Load";
//Set Textures
	cStats->setSmooth(true);
	bkTexture->setSmooth(true);
	Bk.setTexture(bkTexture);
	cBttn11.setTexture(cStats);
	cBttn12.setTexture(cStats);
	cBttn21.setTexture(cStats);
	cBttn22.setTexture(cStats);
	cBttn31.setTexture(cStats);
	cBttn32.setTexture(cStats);
//Configure Text
	Title.setColor(sf::Color(200, 200, 200, 250));
	c11.setColor(sf::Color(200, 200, 200, 255));
	c12.setColor(sf::Color(200, 200, 200, 255));
	c21.setColor(sf::Color(200, 200, 200, 255));
	c22.setColor(sf::Color(200, 200, 200, 255));
	c31.setColor(sf::Color(200, 200, 200, 255));
	c32.setColor(sf::Color(200, 200, 200, 255));
//Position Buttons
	sf::FloatRect* c11Rct = new sf::FloatRect;				//Creature Button 1
	setLocal(c11Rct, cBttn11);
	cBttn11.setPosition(340, 175);
	sf::FloatRect* c12Rct = new sf::FloatRect;				//Creature Button 2
	setLocal(c12Rct, cBttn12);
	cBttn12.setPosition(940, 175);
	sf::FloatRect* c21Rct = new sf::FloatRect;				//Creature Button 3
	setLocal(c21Rct, cBttn21);
	cBttn21.setPosition(340, 325);
	sf::FloatRect* c22Rct = new sf::FloatRect;				//Creature Button 4
	setLocal(c22Rct, cBttn22);
	cBttn22.setPosition(940, 325);
	sf::FloatRect* c31Rct = new sf::FloatRect;				//Creature Button 5
	setLocal(c31Rct, cBttn31);
	cBttn31.setPosition(340, 475);
	sf::FloatRect* c32Rct = new sf::FloatRect;				//Creature Button 6
	setLocal(c32Rct, cBttn32);
	cBttn32.setPosition(940, 475);
//Postion Text
	sf::FloatRect* tRct = new sf::FloatRect;				//Title
	setLocal(tRct, Title);
	Title.setPosition(640, 50);
	sf::FloatRect* t11Rct = new sf::FloatRect;				//Creature 1
	setLocal(t11Rct, c11);
	c11.setPosition(340, 175);
	sf::FloatRect* t12Rct = new sf::FloatRect;				//Creature 2
	setLocal(t12Rct, c12);
	c12.setPosition(940, 175);
	sf::FloatRect* t21Rct = new sf::FloatRect;				//Creature 3
	setLocal(t21Rct, c21);
	c21.setPosition(340, 325);
	sf::FloatRect* t22Rct = new sf::FloatRect;				//Creature 4
	setLocal(t22Rct, c22);
	c22.setPosition(940, 325);
	sf::FloatRect* t31Rct = new sf::FloatRect;				//Creature 5
	setLocal(t31Rct, c31);
	c31.setPosition(340, 475);
	sf::FloatRect* t32Rct = new sf::FloatRect;				//Creature 6
	setLocal(t32Rct, c32);
	c32.setPosition(940, 475);
//Game Loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			//Events
				//Closed
			if (event.type == sf::Event::Closed)
				window.close();
			//Resized
			if (event.type == sf::Event::Resized);
			//Go Back
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return;
		//Menu Buttons Hover
			//Start
			if (c11Rct->contains(
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))
				c11.setColor(sf::Color(0, 0, 0, 255));
			else c11.setColor(sf::Color(200, 200, 200, 255));
		}
	//Display Window
		window.clear();

		window.draw(Bk);
		window.draw(cBttn11);
		window.draw(cBttn12);
		window.draw(cBttn21);
		window.draw(cBttn22);
		window.draw(cBttn31);
		window.draw(cBttn32);
		window.draw(c11);
		window.draw(c12);
		window.draw(c21);
		window.draw(c22);
		window.draw(c31);
		window.draw(c32);
		window.draw(Title);

		window.display();
	}


//Deallocate Memory
	//Textures
	delete bkTexture;delete cStats;
//Rects
	delete tRct, delete c11Rct;delete c12Rct;delete c21Rct;delete c22Rct;
	delete c31Rct;delete c32Rct;delete t11Rct;delete t12Rct;delete t21Rct;
	delete t22Rct;delete t31Rct;delete t32Rct;
}
//******************************************************************************
//******************************************************************************
//                                 Options
//Function-Displays the Option part of the GUI
//Inputs
//      --->None
//Outputs
//      <---None
////////////////////////////////////////////////////////////////////////////////
void Optns() {
//Declare Variables



}
//******************************************************************************
//******************************************************************************
//                                 Local (Recatnagle Shape)
//Function-Displays the Menu part of the GUI
//Inputs
//      --->None
//Outputs
//      <---None
////////////////////////////////////////////////////////////////////////////////
void setLocal(sf::FloatRect* A,sf::RectangleShape& B) {
//Set Local Rect
	*A = B.getLocalBounds();
	B.setOrigin(A->left + A->width / 2.0f,
		A->top + A->height / 2.0f);
}
//******************************************************************************
//******************************************************************************
//                           hitBox (Recatnagle Shape)
//Function-Displays the Menu part of the GUI
//Inputs
//      --->None
//Outputs
//      <---None
////////////////////////////////////////////////////////////////////////////////
void hitBox(sf::FloatRect* A, sf::RectangleShape B) {
//Set Hit Box
	A->left = B.getPosition().x - A->width/2;
	A->top = B.getPosition().y - A->height/2;
	A->width = B.getLocalBounds().width;
	A->height = B.getLocalBounds().height;
}
//******************************************************************************
//******************************************************************************
//                                 Local (Text)
//Function-Displays the Menu part of the GUI
//Inputs
//      --->None
//Outputs
//      <---None
////////////////////////////////////////////////////////////////////////////////
void setLocal(sf::FloatRect* A, sf::Text& B) {
	//Set Local Rect
	*A = B.getLocalBounds();
	B.setOrigin(A->left + A->width / 2.0f,
		A->top + A->height / 2.0f);

}
//******************************************************************************
//******************************************************************************
//                           hitBox (Text)
//Function-Displays the Menu part of the GUI
//Inputs
//      --->None
//Outputs
//      <---None
////////////////////////////////////////////////////////////////////////////////
void hitBox(sf::FloatRect* A, sf::Text B) {
//Set Hit Box
	A->left = B.getPosition().x - A->width / 2;
	A->top = B.getPosition().y - A->height / 2;
	A->width = B.getLocalBounds().width;
	A->height = B.getLocalBounds().height;
}
