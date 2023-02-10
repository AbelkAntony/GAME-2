#include <iostream>
//class character
//private 
	//variable -name  health , damage points , defence , healing
//public
	//constructor (name , helath , damage points , defence , healing)


//class player : public charcter
//private 
	//variables ranged damage , melee damage
		
int main() 
{
	//display game title
	//display the story of the game
	//create player character
	//set default level =1
	//for i = 1 i<=level i++
		//create enemy character
		//game loop
		//if (health of player and health of enemy is >0)
			//display player and enemy all status
			//player turn
				//ask user input
				//if player choice is attack 
					//enemy take damage(player get damage value)
				//else if player choice heal
					//check the player health and heal
			//check(health of enemy is >0)
			//enemy turn
				//enemy randomly choose attack or heal
				//if enemy choice is attack
					//player take damage(enemy get damge value)
				//else if enemy choice is heal
					//check the enemy health and heal
		//level++
	return 0;
}