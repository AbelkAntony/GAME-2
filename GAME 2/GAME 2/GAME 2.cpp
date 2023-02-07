#include <iostream>
#include <stdlib.h>
using namespace std;
//character class ---------------------------------------------------------------------
class Character
{
private:
	//variable 
	string name;
	int currentHealth;
	int maxHealth;
	int damagePoints;
	int defence;
	int healing;
public:
	//constructor
	Character(string _name, int _health, int _damagePoints, int _defence, int _healing)
	{
		name = _name;
		currentHealth = _health;
		maxHealth = _health;
		damagePoints = _damagePoints;
		defence = _defence;
		healing = _healing;
	}

	//Getter function
	string GetName() { return name; }
	int GetHealth() { return currentHealth; }
	int GetDamagePoints() { return damagePoints; }
	int GetDefence() { return defence; }
	int GetHealing() { return healing; }

	//Setter functons


	// functions
	void DisplayStatus()
	{
		cout << "\n\nNAME			: " << name;
		cout << "\nHEALTH			: " << currentHealth;
		cout << "\nDAMAGE POINT	: " << damagePoints;
		cout << "\nDEFENCE			: " << defence;
		cout << "\nHEALING			: " << healing;

	}
	void TakeDamage(Character* opponent)
	{
		int damage = (opponent->GetDamagePoints() - defence);
		currentHealth = currentHealth - damage;
		cout << endl << endl << opponent->GetName() << " CAUSE DAMAGE " << damage;
	}
	void GetHealed()
	{
		if (maxHealth == currentHealth)
		{
			cout << endl << endl << name << " TRY TO HEAL BUT HEALTH IS ALREADY FULL";
		}
		else if ((currentHealth + healing) > maxHealth)
		{
			cout << endl << name << " GOT HEALED " << maxHealth - currentHealth << " NOW HEALTH IS FULL";
			currentHealth = maxHealth;
		}
		else
		{
			cout << endl << name << " GOT HEALED " << healing;
			currentHealth += healing;
		}
	}
};

//player class ----------------------------------------------------------------------------------------------------
class Player : public Character
{
private:
	//variables 
	int rangedDamage;
	int meleeDamage;

public:
	//constructor
	Player(string _name) :Character(_name, 100, 50, 30, 40)
	{

	}

};

//enemy class--------------------------------------------------------------------------------------------------------
class Enemy : public Character
{
private:

public:
	//constructor
	Enemy(string _name, int _health, int _damagePoints, int _defence, int _healing) : Character(_name, _health, _damagePoints, _defence, _healing)
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
	//int level=1;
	Player* player;
	Enemy* enemy;
	string name;
	int time = 0;
	//function
//game title display function
	void DisplayGameTitle()
	{
		cout << "\n\n\n\t\t\t\t\tBATTLE WITH MONSTER";
		//getchar();

	}
	//Game story display function
	void DisplayGameStory()
	{
		cout << "\n\n\n\n ";
		//getchar();
		//system("clear");
	}
	//player character creation
	void PlayerCreation()
	{
		cout << "\nENTER YOUR NAME : ";
		cin >> name;
		player = new Player(name);
	}
	//Enemy character creation
	void EnemyCreation()
	{
		enemy = new Enemy("MONSTER MAC", 50, 40, 20, 20);
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
		//if player choice is attack 
		//enemy take damage(player get damage value)
		//else if player choice heal
		//check the player health and heal
		cout << endl << endl << player->GetName() << "'s TURN";
		cout << "\n\n1. ATTACK\n2. HEAL";
		cout << "\nENETR YOUR CHOISE : ";
		cin >> option;
		switch (option)
		{
		case 1:
			enemy->TakeDamage(player);
			break;
		case 2:
			player->GetHealed();
			break;
		}
	}
	void EnemyTurn()
	{
		cout << endl << endl << enemy->GetName() << "'s TURN";
		option = 1 + (rand() % (2 - 1 + 1));
		switch (option)
		{
		case 1:
			player->TakeDamage(enemy);
			break;
		case 2:
			enemy->GetHealed();
			break;
		default:
			cout << "error";
		}
	}
	//Game result
	void GameResult()
	{
		if (player->GetHealth() <= 0)
		{
			cout << "\nYOU LOSE THE BATTLE";
		}
		else if (enemy->GetHealth() <= 0)
		{
			cout << "\nYOU WIN THE BATTLE";
		}
		else
		{
			cout << "error";
		}
	}

public:
	BattleWithMonster()
	{
		//calling display game title function
		DisplayGameTitle();
		//display the story of the game
		DisplayGameStory();
		//calling function for creating player
		PlayerCreation();
	}
	void Play()
	{

		//set default level =1
		//for i = 1 i<=level i++

		//create enemy character
		EnemyCreation();
		//game loop
		battleRound = 1;
		while (player->GetHealth() > 0 && enemy->GetHealth() > 0)
		{
			cout << "\nROUND :" << battleRound << "-------------------------------------";
			//display player and enemy all status
			DisplayAllStatus();
			//player turn
			PlayerTurn();
			//check(health of enemy is >0)
			if (enemy->GetHealth() <= 0)
				break;
			DisplayAllStatus();
			//enemy turn
			EnemyTurn();

			//Turn(enemy , player);
				//enemy randomly choose attack or heal
				//if enemy choice is attack
					//player take damage(enemy get damge value)
				//else if enemy choice is heal
					//check the enemy health and heal
				//level++;
			battleRound++;
		}
		GameResult();
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