#include <iostream>
#include <stdlib.h>
using namespace std;
//character class ---------------------------------------------------------------------
class Character
{
private:
	//variable 
	string name ;
	int currentHealth ;
	int maxHealth;
	int damagePoint ;
	int defence ;
	int healing;
public:
	//constructor
	Character(string _name ,int _health ,int _damagePoint ,int _defence ,int _healing)
	{
			name			=	 _name;
			currentHealth	=	 _health;
			maxHealth		=	 _health;
			damagePoint		=	 _damagePoint;
			defence			=	 _defence;
			healing			=	 _healing;
	}

	//Getter function
	string GetName()			{	return name;			}
	int GetHealth()				{	return currentHealth;	}
	int GetDamagePoint()		{	return damagePoint;	}
	int GetDefence()			{	return defence;			}
	int GetHealing()			{	return healing;			}
	int GetMaxHealth()			{	return maxHealth;		}

	//Setter functons
	void SetHealth(int _health)					{	currentHealth = _health;		}
	void SetMaxHealth(int _health)				{	maxHealth = _health;			}
	void SetDamagePoint(int newDamagePoint)		{	damagePoint = newDamagePoint;	}
	void SetDefence(int newDefence)				{	defence = newDefence;			}

	// functions
	void DisplayStatus()
	{
		cout<<"\n\nNAME			: "<<name;
		cout<<"\nHEALTH			: "<<currentHealth;
		cout<<"\nDAMAGE POINT	: "<<damagePoint;
		cout<<"\nDEFENCE			: "<<defence;
		cout<<"\nHEALING			: "<<healing;
		
	}
	void TakeDamage(Character *opponent)
	{
		int damage =(opponent->GetDamagePoint()- defence);
		currentHealth = currentHealth - damage;
		cout<<endl<<endl<<opponent->GetName()<<" CAUSE DAMAGE "<<damage;
	}
	void GetHealed()
	{
		if(maxHealth == currentHealth)
		{
			cout<<endl<<endl<<name<<" TRY TO HEAL BUT HEALTH IS ALREADY FULL";
		}
		else if((currentHealth+healing)>maxHealth)
		{
			cout<<endl<<name<<" GOT HEALED "<<maxHealth-currentHealth<<" NOW HEALTH IS FULL";
			currentHealth = maxHealth;
		}
		else
		{
			cout<<endl<<name<<" GOT HEALED "<<healing;
			currentHealth += healing;
		}
	}
};

//player class ----------------------------------------------------------------------------------------------------
class Player : public Character
{
private: 
	//variables 
public:
	//constructor
	Player(string _name ):Character( _name ,100,50 ,30,40)
	{
		
	}
	void HealthReset()								{	SetHealth(GetMaxHealth());			}
	void UpdateDamagePoint(int newDamagePoint)		{	SetDamagePoint(newDamagePoint);		}
	void UpdateDefence(int newDefence)				{	SetDefence(newDefence);				}

};

//enemy class--------------------------------------------------------------------------------------------------------
class Enemy : public Character
{
private:

public:
	//constructor
	Enemy(string _name,int _health,int _damagePoints,int _defence,int _healing) : Character(_name, _health, _damagePoints, _defence,  _healing)
	{
		 
	}
};






//game class--------------------------------------------------------------------------
class BattleWithMonster
{
private:
	//variables
	int option;
	int battleRound;
	int stage=1;
	Player *player;
	Enemy *enemy;
	string name;
	int time=0;
	//function
//game title display function
	void DisplayGameTitle()
	{
		cout<<"\n\n\n\t\t\t\t\tBATTLE WITH MONSTER";
			//getchar();
		
	}
//Game story display function
	void DisplayGameStory()
	{
		cout<<"\n\n\n\nMr/Ms "<<player->GetName()<<",\n your village is conquired by a Monster and you need to fight with them and defeat the monsters\n ";
		//getchar();
		//system("clear");
	}
	//player character creation
	void PlayerCreation()
	{
		cout<<"\nENTER YOUR NAME : ";
		cin>>name;
		player = new Player(name);
	}
	//Enemy character creation
	void EnemyCreation(int stage)
	{
		switch(stage)
		{
			case 1:
			enemy = new Enemy("MONSTER LEVEL 1 ",50,40,20,20);
			break;
			case 2:
			enemy = new Enemy("MONSTER LEVEL 2 ",75,45,25,25);
			break;
			case 3:
			enemy = new Enemy("MONSTER LEVEL 3 ",100,50,30,30);
			break;
			case 4:
			enemy = new Enemy("MONSTER LEVEL 4 ",125,55,35,35);
			break;
			case 5:
			enemy = new Enemy("MONSTER LEVEL 5 ",130,60,40,40);
			break;
			case 6:
			enemy = new Enemy("MURLOCS BOSS",150,65,45,45);
			break;
		}
	}
	//map
	void Map(int stage)
	{
		if(stage!=1 && stage!=6)
		{
		cout<<"\nhi chef\nYou are far away from your final destination. You just completed your stage "<<stage-1<<" of 6 .\nIn this stage you have to defeat "<<stage<<" enemies of level "<<stage<<"\n All the best "	;
		}
		if(stage == 6)
		{
			cout<<"\nHi chef\n You are going to fight with BOSS MURLOCS ,So make sure that you have Sword, Shield, Armour and Bow . Without these equpment you can't defeat Boss\n All the best ";
		}
	}
	//Player reward
	void PlayerReward(int stage)
	{
		cout<<endl<<player->GetName()<<" GOT ";
		switch(stage)
		{
			case 1:
				cout<<"MAP ";
				break;
			case 2:
			{
				cout<<"SWORD YOUR DAMAGE POINT INCREASE BY 20% ";
				int newDamagePoint = player->GetDamagePoint() + (player->GetDamagePoint()* .2);	
				player->UpdateDamagePoint(newDamagePoint);	
				break;
			}	
			case 3:
			{
				cout<<"SHEILD YOUR DEFENCE INCREASE BY 20% ";
				int newDefence = player->GetDefence() + (player->GetDefence()* .2);
				player->UpdateDefence(newDefence);
				break;
			}
			case 4:
			{
				cout<<"ARMOR YOUR DEFENCE INCREASE BY 30%";
				int newDefence = player->GetDefence() + (player->GetDefence()* .3);
				player->UpdateDefence(newDefence);
				break;
			}
			case 5:
			{
				cout<<"BOW YOUR DAMAGE POINT INCREASE BY 30%";
				int newDamagePoint = player->GetDamagePoint() + (player->GetDamagePoint()* .2);	
				player->UpdateDamagePoint(newDamagePoint);	
				break;
			}
		}
	}
	//Display player and enemy status
	void DisplayAllStatus()
	{
		player->DisplayStatus();
		enemy->DisplayStatus();
		//getchar();
		//system("clear");
	}
	void PlayerTurn()
	{	
		//ask user input
		cout<<endl<<endl<<player->GetName()<<"'s TURN";
		cout<<"\n\n1. ATTACK\n2. HEAL";
		cout<<"\nENETR YOUR CHOISE : ";
		cin>>option;
		switch(option)
		{
		//if player choice is attack 
			case 1:
		//enemy take damage(player get damage value)
			enemy->TakeDamage(player);
			break;
		//else if player choice heal
			case 2:
		//check the player health and heal
			player->GetHealed();
			break;
		}
	}
	void EnemyTurn()
	{	
		cout<<endl<<endl<<enemy->GetName()<<"'s TURN";
		//enemy randomly choose attack or heal
		option = 1+(rand()%(2-1+1));
		switch(option)
		{
			//if enemy choice is attack
			case 1:
			player->TakeDamage(enemy);
			break;
			//else if enemy choice is heal
			case 2:
			enemy->GetHealed();
			break;
			
		}
	}
	//Game result
	void GameResult()
	{
		if(player->GetHealth()<=0)
		{
			cout<<"\nYOU LOSE THE BATTLE";
		}
		else if (enemy->GetHealth()<=0)
		{
			cout<<"\nYOU WIN THE BATTLE";
		}
	}
	//stage wise battle
	void Battle(int stage)
	{
		//create enemy character
		EnemyCreation(stage);
		//game loop
		battleRound = 1;
		while(player->GetHealth()>0 && enemy->GetHealth()>0)
			{
				cout<<"\nROUND :"<<battleRound<<"-------------------------------------";
				//display player and enemy all status
				DisplayAllStatus();
				//player turn
				PlayerTurn();		
				//check(health of enemy is >0)
				if(enemy->GetHealth()<=0)
					break;
				DisplayAllStatus();
				//enemy turn
				EnemyTurn();
				//Turn(enemy , player);
				battleRound++;
			}
		GameResult();
		if(player->GetHealth()<=0)
			return;
	}
	
public:
	BattleWithMonster()
	{
		//calling display game title function
		DisplayGameTitle();
		//calling function for creating player
		PlayerCreation();
		//display the story of the game
		DisplayGameStory();
	}
	void Play()
	{
	while(stage<=6)
		{
		
		cout<<"\nSTAGE : "<<stage<<"*******************************************************";
		Map(stage);
		cout<<"\nDO YOU WANT TO START GAME\n1. YES\n2. NO \nENTER YOUR CHOICE : ";
		cin>>option;
		if(option==2)
			break;
		if(stage==6)
		{
			cout<<"\nBATTLE STARTS";
				Battle(stage);
				delete enemy;
			
		}
		else
		{
			for (int i = 1 ;i<=stage ;i++)
				{
					cout<<"\nBATTLE STARTS";
					Battle(stage);
					delete enemy;
				}	
		}
		if(player->GetHealth()>0)
				{
					PlayerReward(stage);
					player->HealthReset();
				}	
		stage++;	
		}	
	delete player;	
	}	
};

int main() 
{
	srand(time(0));
	//class for game function and loop
	BattleWithMonster newGame;
	newGame.Play();
	return 0;
}