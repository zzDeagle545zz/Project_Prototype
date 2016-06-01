/*
* File:   Creature.h
* Author: zzDeagle545zz
*
* Created on April 29, 2016, 3:43 PM
*/

//Guard Block
#ifndef CREATURE_H
#define CREATURE_H

//System Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//User Libraries
#include "Element.h"

////////////////////////////////////////////////////////////////////////////////
class Creature {
public:
	enum { GIGATARY, TERADON };
//Creature Info
	sf::String name;        //Creature Name
	sf::String type;        //Creature Type
	sf::String element;     //Creature Element Name
//Creature Stats
	int HP, cHP;          //Health
	int Strgth, cStrgth;  //Physical Damage
	int Magic, cMagic;    //Elemental Damage
	int Armor, cArmor;    //Defense Against Physical Damage
	int Resist, cResist;  //Defense Against Magic Damage
	int aPen;			  //Armor Penatration
	int mPen;			  //Magic Penatration
	int Speed, cSpeed;    //Quickness to react and or attack
	int Enrgy, cEnrgy;    //Amount of Energy to Attack/Abilities
	Element Elment;       //Element Type
public:
	Creature();						//Constructor
	virtual ~Creature();			//Destructor
	//virtual void attck();			//Attack
	virtual void tkAdmg(int,int);	//Take Attack Damage
	virtual void tkMdmg(int,int);	//Take Magic Damage
	void heal();					//Heal
	void mArmor();					//Manipulate Armor
	void mResist();					//Manipulate Resist
	void mStrgth();					//Manipulate Stregth
	void mMagic();					//Manipulate Magic
	void mSpeed();					//Manipulate Speed
};

#endif // CREATURE_H 