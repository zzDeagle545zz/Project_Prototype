/*
* File:   Ability.h
* Author: zzDeagle545zz
*
* Created on April 29, 2016, 3:46 PM
*/

#ifndef ABILITY_H
#define ABILITY_H

//System Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//User Libraries
#include "Creature.h"

class Ability {
	friend class Creature;
protected:
//Ability info
	sf::String Name;
	sf::String Elmnt;
//Ability Stats
	int eCst;			//Energy Cost
	int speed;			//Speed
	int aDmg;			//Attack Damage
	int mDmg;			//Magic Damage
public:
	
	Ability();
	virtual void stEffct(Creature,Creature)=0;


};
//******************************************************************************
//******************************************************************************
//                                 Shock Nova
//  
////////////////////////////////////////////////////////////////////////////////
class ShockNova :protected Ability {
protected:

public:
	ShockNova();
	virtual void stEffct(Creature*,Creature*);
};



#endif	// ABILITY_H
