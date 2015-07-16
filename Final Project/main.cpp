// Final_Project.cpp : Defines the entry point for the console application.
//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void clearmap();
void findloc();
void potion();
void giveinfo();
void map();

string command;
char sure_exit;
char map_location[25];

class attributes
{
public:
	int health;
	int str;
	int def;
	int agl;
	int xpos;
	int ypos;
	string name;
    
	int attack()
	{
		int ra;
		int valueA;
		srand(time(NULL));
		ra=rand() %10+1;
		valueA=str+ra;
		return valueA;
	}
	int defense()
	{
		int rd;
		int valueD;
		srand(time(NULL));
		rd=rand() % 15 + 1;
		valueD=def+rd;
		return valueD;
	}
	bool agility()
	{
		int rM;
		bool result;
		srand(time(NULL));
		rM=rand() % 100 + 1;
		if(rM<agl)
		{
			result=true;
		}
		else
		{
			result=false;
		}
		return result;
	}
}plr1,lm1,lm2,lm3,lm4,lm5,lm6,boss;


int main()
{
	srand(time(NULL));
	bool foundkey=false;
	bool entered=false;
	int potions=0;
	//Seting up the game with initial selection
	string initial_choice;
	printf ("Welcome to Adam's adventure game.\nPlease enter your name:\n");
	cin >> plr1.name;
	cout <<"Welcome, "<<plr1.name;
	printf("!\n");
	do
	{
		printf("Would you like to initially specialize in strength, defense, or agility?\n");
		cin >> initial_choice;
	}while(initial_choice!="Strength"&&initial_choice!="strength"&&initial_choice!="Defense"&&initial_choice!="defense"&&initial_choice!="Agility"&&initial_choice!="agility"&&initial_choice!="s"&&initial_choice!="d"&&initial_choice!="a");
	//defining starting stats
	if(initial_choice=="Strength"||initial_choice=="strength"||initial_choice=="s")
	{
		plr1.str=40;
		plr1.def=12;
		plr1.agl=5;
		plr1.health=100;
		printf("You have specialized in strength.\n");
	}
	else if(initial_choice=="Defense"||initial_choice=="defense"||initial_choice=="d")
	{
		plr1.str=30;
		plr1.def=26;
		plr1.agl=5;
		plr1.health=100;
		printf("You have specialized in defense.\n");
	}
	else if(initial_choice=="Agility"||initial_choice=="agility"||initial_choice=="a")
	{
		plr1.str=30;
		plr1.def=12;
		plr1.agl=15;
		plr1.health=100;
		printf("You have specialized in agility.\n");
	}
	plr1.xpos=3;
	plr1.ypos=3;
	lm1.str=25;
	lm1.def=10;
	lm1.agl=5;
	lm1.health=80;
	lm2.str=30;
	lm2.def=15;
	lm2.agl=10;
	lm2.health=90;
	lm3.str=30;
	lm3.def=15;
	lm3.agl=10;
	lm3.health=90;
	lm4.str=30;
	lm4.def=15;
	lm4.agl=10;
	lm4.health=90;
	lm5.str=30;
	lm5.def=15;
	lm5.agl=10;
	lm5.health=90;
	lm6.str=35;
	lm6.def=20;
	lm6.agl=15;
	lm6.health=100;
	boss.str=50;
	boss.def=30;
	boss.agl=20;
	boss.health=100;
    
	printf ("Type help for a list of commands.\nYou should probably examine your area to take a look at your surroundings.\n");
    
    clearmap();
    findloc();
    
	//starting the forever loop
	while(1){
        
        //main command list
        string command;
        cin >> command;
        //Help command. Will list available commands
        if (command=="help"||command=="Help")
		{
            printf ("----------------Help----------------\nStats - show your player stats\nMap - show the map\nExit - leave the game\nChangename - Change your character's name\nNorth/South/East/West- move your character.\nExamine - get information about your current location\nAttack - attack an enemy within the tile, if possible.\nPotion - drink a potion, if possible\nHeal - heal your character, if possible.\n");
		}
        //display current player stats
        else if (command=="stats"||command=="Stats")
		{
            cout <<"Current Stats:"<<endl<<"Name: "<<plr1.name;
			printf("\nHealth: %d\nStrength: %d\nDefense: %d\nAgility: %d\nPotions: %d\n",plr1.health,plr1.str,plr1.def,plr1.agl,potions);
            
		}
        else if(command=="Exit"||command=="exit")
        {
            printf("Are you sure you want to exit? Y/N\n");
            cin >> sure_exit;
            if(sure_exit=='y'||sure_exit=='Y')
            {
                printf("Exitting game...\n");
                return(0);
            }
            else
            {
                printf("Returning to game...\n");
            }
            
        }
        else if(command=="Heal"||command=="heal")
        {
            if(plr1.xpos==2&&plr1.ypos==3)
            {
                printf("You heal at the city\n");
                plr1.health=100;
            }
            else
            {
                printf("You can't heal here!\n");
            }
        }
        else if(command=="Changename"||command=="changename")
        {
            printf("Please type the name you would like to have:\n");
            cin >>plr1.name;
            cout <<"Your new name is "<<plr1.name<<"."<<endl;
        }
        else if(command=="Potion"||command=="potion")
        {
            if(potions==0)
            {
                printf("You have no potions to use!\n");
            }
            if(potions>0)
            {
                potion();
                potions=potions-1;
            }
        }
        else if(command=="N"||command=="North"||command=="n"||command=="north")
        {
            if(entered==false)
            {
                plr1.ypos=plr1.ypos+1;
                if (plr1.ypos>5)
                {
                    plr1.ypos=5;
                    printf("You can't go there!\n");
                }else
                {
                    printf("You moved north.\n");
                    clearmap();
                    findloc();
                    map();
                    giveinfo();
                }
            }
            else{cout<<"You cannot leave!"<<endl;}
        }
        else if(command=="S"||command=="South"||command=="s"||command=="south")
        {
            if(entered==false)
            {
                plr1.ypos=plr1.ypos-1;
                if (plr1.ypos<1)
                {
                    plr1.ypos=1;
                    printf("You can't go there!\n");
                }else{
                    printf("You moved south.\n");
                    clearmap();
                    findloc();
                    map();
                    giveinfo();
                }
            }
            else{cout<<"You cannot leave!"<<endl;}
        }
        else if(command=="W"||command=="West"||command=="w"||command=="west")
        {
            if(entered==false)
            {
                plr1.xpos=plr1.xpos-1;
                if (plr1.xpos<1)
                {
                    plr1.xpos=1;
                    printf("You can't go there!\n");
                }else{
                    printf("You moved west.\n");
                    clearmap();
                    findloc();
                    map();
                    giveinfo();
                }
            }
            else{cout<<"You cannot leave!"<<endl;}
        }
        else if(command=="E"||command=="East"||command=="e"||command=="east")
        {
            if(entered==false)
            {
                plr1.xpos=plr1.xpos+1;
                if (plr1.xpos>5)
                {
                    plr1.xpos=5;
                    printf("You can't go there!\n");
                }else{
                    printf("You moved east.\n");
                    clearmap();
                    findloc();
                    map();
                    giveinfo();
                }
            }
            else{cout<<"You cannot leave!"<<endl;}
        }
        else if(command=="Examine"||command=="e"||command=="E"||command=="examine"||command=="ex"||command=="Ex")
        {
            giveinfo();
            if(plr1.xpos==5&&plr1.ypos==3)
            {
                foundkey=true;
            }
        }
        else if(command=="attack"||command=="Attack")
        {
            int playerdamage;
            int enemydamage;
            int playerdef;
            int enemydef;
            bool playerdodge;
            bool enemydodge;
            
            playerdamage=plr1.attack();
            playerdef=plr1.defense()/2;
            playerdodge=plr1.agility();
            
            //First fight in southern forest
            if(plr1.ypos==2&&plr1.xpos==3&&lm1.health>0)
            {
                cout <<"You are fighting a lizardman."<<endl;
                enemydamage=lm1.attack();
                enemydef=lm1.defense()/2;
                enemydodge=lm1.agility();
                if(enemydodge==true)
                {
                    printf("The enemy dodged your attack.\n");
                }
                else if (enemydodge==false)
                {
                    lm1.health=lm1.health-(playerdamage-enemydef);
                    printf("You dealt %i damage, but the enemy blocked %i and received %i.\n",playerdamage,enemydef,playerdamage-enemydef);
                }
                if(playerdodge==true)
                {
                    printf("You dodged the enemy's attack.\n");
                }
                else if(playerdodge==false)
                {
                    plr1.health=plr1.health-(enemydamage-playerdef);
                    printf("The enemy dealt %i damage, but you blocked %i and received %i\n",enemydamage,playerdef,(enemydamage-playerdef));
                }
                if(lm1.health<0) {printf("You have defeated the lizardman and gained a potion!\n");
                    potions=potions+1;}
            }
            //second enemy south of first
            else if(plr1.ypos==1&&plr1.xpos==3&&lm2.health>0)
            {
                cout <<"You are fighting a lizardman."<<endl;
                enemydamage=lm2.attack();
                enemydef=lm2.defense()/2;
                enemydodge=lm2.agility();
                if(enemydodge==true)
                {
                    printf("The enemy dodged your attack.\n");
                }
                else if (enemydodge==false)
                {
                    lm2.health=lm2.health-(playerdamage-enemydef);
                    printf("You dealt %i damage, but the enemy blocked %i and received %i.\n",playerdamage,enemydef,playerdamage-enemydef);
                }
                if(playerdodge==true)
                {
                    printf("You dodged the enemy's attack.\n");
                }
                else if(playerdodge==false)
                {
                    plr1.health=plr1.health-(enemydamage-playerdef);
                    printf("The enemy dealt %i damage, but you blocked %i and received %i\n",enemydamage,playerdef,(enemydamage-playerdef));
                }
                if(lm2.health<0) {printf("You have defeated the lizardman and gained a potion!\n");
                    potions=potions+1;}
            }
            //third fight west of second
            else if(plr1.ypos==1&&plr1.xpos==2&&lm3.health>0)
            {
                cout <<"You are fighting a lizardman."<<endl;
                enemydamage=lm3.attack();
                enemydef=lm3.defense()/2;
                enemydodge=lm3.agility();
                if(enemydodge==true)
                {
                    printf("The enemy dodged your attack.\n");
                }
                else if (enemydodge==false)
                {
                    lm3.health=lm3.health-(playerdamage-enemydef);
                    printf("You dealt %i damage, but the enemy blocked %i and received %i.\n",playerdamage,enemydef,playerdamage-enemydef);
                }
                if(playerdodge==true)
                {
                    printf("You dodged the enemy's attack.\n");
                }
                else if(playerdodge==false)
                {
                    plr1.health=plr1.health-(enemydamage-playerdef);
                    printf("The enemy dealt %i damage, but you blocked %i and received %i\n",enemydamage,playerdef,(enemydamage-playerdef));
                }
                if(lm3.health<0) {printf("You have defeated the lizardman and gained a potion!\n");
                    potions=potions+1;}
            }
            //fourth fight west of third
            else if(plr1.ypos==1&&plr1.xpos==1&&lm4.health>0)
            {
                cout <<"You are fighting a lizardman."<<endl;
                enemydamage=lm4.attack();
                enemydef=lm4.defense()/2;
                enemydodge=lm4.agility();
                if(enemydodge==true)
                {
                    printf("The enemy dodged your attack.\n");
                }
                else if (enemydodge==false)
                {
                    lm4.health=lm4.health-(playerdamage-enemydef);
                    printf("You dealt %i damage, but the enemy blocked %i and received %i.\n",playerdamage,enemydef,playerdamage-enemydef);
                }
                if(playerdodge==true)
                {
                    printf("You dodged the enemy's attack.\n");
                }
                else if(playerdodge==false)
                {
                    plr1.health=plr1.health-(enemydamage-playerdef);
                    printf("The enemy dealt %i damage, but you blocked %i and received %i\n",enemydamage,playerdef,(enemydamage-playerdef));
                }
                if(lm4.health<0) printf("You have defeated the lizardman and gained a potion!\n");
                potions=potions+1;
            }
            //fifth fight east of second
            else if(plr1.ypos==1&&plr1.xpos==4&&lm5.health>0)
            {
                cout <<"You are fighting a lizardman."<<endl;
                enemydamage=lm5.attack();
                enemydef=lm5.defense()/2;
                enemydodge=lm5.agility();
                if(enemydodge==true)
                {
                    printf("The enemy dodged your attack.\n");
                }
                else if (enemydodge==false)
                {
                    lm5.health=lm5.health-(playerdamage-enemydef);
                    printf("You dealt %i damage, but the enemy blocked %i and received %i.\n",playerdamage,enemydef,playerdamage-enemydef);
                }
                if(playerdodge==true)
                {
                    printf("You dodged the enemy's attack.\n");
                }
                else if(playerdodge==false)
                {
                    plr1.health=plr1.health-(enemydamage-playerdef);
                    printf("The enemy dealt %i damage, but you blocked %i and received %i\n",enemydamage,playerdef,(enemydamage-playerdef));
                }
                if(lm5.health<0) {printf("You have defeated the lizardman and gained a potion!\n");
                    potions=potions+1;}
            }
            //sixth fight east of fifth
            else if(plr1.ypos==1&&plr1.xpos==5&&lm6.health>0)
            {
                cout <<"You are fighting a lizardman."<<endl;
                enemydamage=lm6.attack();
                enemydef=lm6.defense()/2;
                enemydodge=lm6.agility();
                if(enemydodge==true)
                {
                    printf("The enemy dodged your attack.\n");
                }
                else if (enemydodge==false)
                {
                    lm6.health=lm6.health-(playerdamage-enemydef);
                    printf("You dealt %i damage, but the enemy blocked %i and received %i.\n",playerdamage,enemydef,playerdamage-enemydef);
                }
                if(playerdodge==true)
                {
                    printf("You dodged the enemy's attack.\n");
                }
                else if(playerdodge==false)
                {
                    plr1.health=plr1.health-(enemydamage-playerdef);
                    printf("The enemy dealt %i damage, but you blocked %i and received %i\n",enemydamage,playerdef,(enemydamage-playerdef));
                }
                if(lm6.health<0) {printf("You have defeated the lizardman and gained a potion!\n");
                    potions=potions+1;}
            }
            //Final boss fight in the castle
            else if(plr1.ypos==5&&plr1.xpos==2&&boss.health>0)
            {
                cout <<"You are fighting the Lizard King!\n"<<endl;
                enemydamage=boss.attack();
                enemydef=boss.defense()/2;
                enemydodge=boss.agility();
                if(enemydodge==true)
                {
                    printf("The enemy dodged your attack.\n");
                }
                else if (enemydodge==false)
                {
                    boss.health=boss.health-(playerdamage-enemydef);
                    printf("You dealt %i damage, but the enemy blocked %i and received %i.\n",playerdamage,enemydef,playerdamage-enemydef);
                }
                if(playerdodge==true)
                {
                    printf("You dodged the enemy's attack.\n");
                }
                else if(playerdodge==false)
                {
                    plr1.health=plr1.health-(enemydamage-playerdef);
                    printf("The enemy dealt %i damage, but you blocked %i and received %i\n",enemydamage,playerdef,(enemydamage-playerdef));
                }
                if(boss.health<0)
                {
                    cout << plr1.name;
                    printf(" has defeated the Lizard King!! Congratulations on beating my game!\nUnfortunately, the game will have to exit now...\n");
                    return(0);
                }
            }
            else
            {
                cout << "There is nothing to attack here."<<endl;
            }
            
        }
        //Map
        else if(command=="Map"||command=="map")
        {
            map();
        }
        //If no command was recognized
        else
        {
            printf ("That command was not recognized.\n");
        }
        if(plr1.xpos==2&&plr1.ypos==5&&entered==false)
        {
            if(foundkey==false)
            {
                cout<<"You need a key to enter the lizard king's castle."<<endl;
                plr1.xpos=2;
                plr1.ypos=4;
            }
            if(foundkey==true)
            {
                string sureboss;
                printf("You are about to enter the Lizard King's castle. Once you enter, you cannot leave. Are you sure you want to enter? Y/N\n");
                cin >> sureboss;
                if(sureboss=="y"||sureboss=="Y")
                {
                    entered=true;
                    printf("Good luck!\n");
                }
                else
                {
                    cout<<"Exitting castle area..."<<endl;
                    plr1.xpos=2;
                    plr1.ypos=4;
                }
                
            }
        }
        
        if(plr1.health<0)
		{
			cout<<"You died..."<<endl;
			return (0);
		}
	}
	//end of the forever loop
    
	return (0);
}


void clearmap()
{
	map_location[0]=' ';
	map_location[1]=' ';
	map_location[2]=' ';
	map_location[3]=' ';
	map_location[4]=' ';
	map_location[5]=' ';
	map_location[6]=' ';
	map_location[7]=' ';
	map_location[8]=' ';
	map_location[9]=' ';
	map_location[10]=' ';
	map_location[11]=' ';
	map_location[12]=' ';
	map_location[13]=' ';
	map_location[14]=' ';
	map_location[15]=' ';
	map_location[16]=' ';
	map_location[17]=' ';
	map_location[18]=' ';
	map_location[19]=' ';
	map_location[20]=' ';
	map_location[21]=' ';
	map_location[22]=' ';
	map_location[23]=' ';
	map_location[24]=' ';
	
}

void findloc()
{
	if(plr1.xpos==1&&plr1.ypos==5){map_location[0]='X';}
	if(plr1.xpos==2&&plr1.ypos==5){map_location[1]='X';}
	if(plr1.xpos==3&&plr1.ypos==5){map_location[2]='X';}
	if(plr1.xpos==4&&plr1.ypos==5){map_location[3]='X';}
	if(plr1.xpos==5&&plr1.ypos==5){map_location[4]='X';}
	if(plr1.xpos==1&&plr1.ypos==4){map_location[5]='X';}
	if(plr1.xpos==2&&plr1.ypos==4){map_location[6]='X';}
	if(plr1.xpos==3&&plr1.ypos==4){map_location[7]='X';}
	if(plr1.xpos==4&&plr1.ypos==4){map_location[8]='X';}
	if(plr1.xpos==5&&plr1.ypos==4){map_location[9]='X';}
	if(plr1.xpos==1&&plr1.ypos==3){map_location[10]='X';}
	if(plr1.xpos==2&&plr1.ypos==3){map_location[11]='X';}
	if(plr1.xpos==3&&plr1.ypos==3){map_location[12]='X';}
	if(plr1.xpos==4&&plr1.ypos==3){map_location[13]='X';}
	if(plr1.xpos==5&&plr1.ypos==3){map_location[14]='X';}
	if(plr1.xpos==1&&plr1.ypos==2){map_location[15]='X';}
	if(plr1.xpos==2&&plr1.ypos==2){map_location[16]='X';}
	if(plr1.xpos==3&&plr1.ypos==2){map_location[17]='X';}
	if(plr1.xpos==4&&plr1.ypos==2){map_location[18]='X';}
	if(plr1.xpos==5&&plr1.ypos==2){map_location[19]='X';}
	if(plr1.xpos==1&&plr1.ypos==1){map_location[20]='X';}
	if(plr1.xpos==2&&plr1.ypos==1){map_location[21]='X';}
	if(plr1.xpos==3&&plr1.ypos==1){map_location[22]='X';}
	if(plr1.xpos==4&&plr1.ypos==1){map_location[23]='X';}
	if(plr1.xpos==5&&plr1.ypos==1){map_location[24]='X';}
}

void potion()
{
	string choice;
	cout <<"You drink the potion. ";
	do{
        printf("Please choose one stat to increase: Strength, Defense, or Agility:\n");
        cin >> choice;
	}while(choice!="Strength"&&choice!="strength"&&choice!="Defense"&&choice!="defense"&&choice!="Agility"&&choice!="agility"&&choice!="s"&&choice!="d"&&choice!="a");
	//defining possibilities
	if(choice=="Strength"||choice=="strength"||choice=="s")
	{
		plr1.str=plr1.str+7;
		printf("You have chosen strength.\n");
	}
	else if(choice=="Defense"||choice=="defense"||choice=="d")
	{
		plr1.def=plr1.def+7;
		printf("You have chosen defense.\n");
	}
	else if(choice=="Agility"||choice=="agility"||choice=="a")
	{
		plr1.agl=plr1.agl+7;
		printf("You have chosen agility.\n");
	}
}
void giveinfo()
{
	if(plr1.xpos==1&&plr1.ypos==5){}
	else if(plr1.xpos==2&&plr1.ypos==5){cout<<"You are in the Lizard King's castle. You cannot exit."<<endl;}
	else if(plr1.xpos==3&&plr1.ypos==5){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==4&&plr1.ypos==5){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==5&&plr1.ypos==5){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==1&&plr1.ypos==4){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==2&&plr1.ypos==4){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==3&&plr1.ypos==4){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==4&&plr1.ypos==4){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==5&&plr1.ypos==4){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==1&&plr1.ypos==3){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==2&&plr1.ypos==3){cout<<"You are in the city. You can heal here. The townspeople tell of a castle with an evil Lizard King, whose Lizardman minions wander through the forests."<<endl;}
	else if(plr1.xpos==3&&plr1.ypos==3){cout <<"You are in a lush meadow. To the south is a forest and to the north are some mountains. To the west some houses can be seen, and to the east are some ruins."<<endl;}
	else if(plr1.xpos==4&&plr1.ypos==3){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==5&&plr1.ypos==3){cout<<"You are in some ruins. As you look around, you find a key, which you take."<<endl;}
	else if(plr1.xpos==1&&plr1.ypos==2){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==2&&plr1.ypos==2){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==3&&plr1.ypos==2){cout <<"You are in a forest. There are some lizardmen wandering around occaisionally."<<endl;}
	else if(plr1.xpos==4&&plr1.ypos==2){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==5&&plr1.ypos==2){cout << "You are in a plain grass field."<<endl;}
	else if(plr1.xpos==1&&plr1.ypos==1){cout <<"You are in a forest. There are some lizardmen wandering around occaisionally."<<endl;}
	else if(plr1.xpos==2&&plr1.ypos==1){cout <<"You are in a forest. There are some lizardmen wandering around occaisionally."<<endl;}
	else if(plr1.xpos==3&&plr1.ypos==1){cout <<"You are in a forest. There are some lizardmen wandering around occaisionally."<<endl;}
	else if(plr1.xpos==4&&plr1.ypos==1){cout <<"You are in a forest. There are some lizardmen wandering around occaisionally."<<endl;}
	else if(plr1.xpos==5&&plr1.ypos==1){cout <<"You are in a forest. There are some lizardmen wandering around occaisionally."<<endl;}
    
}

void map()
{
    
    cout << "+-----+-----+-----+-----+-----+"<<endl;
    cout << "|     |  C  |     |     |     |"<<endl;
    cout << "|  "<<map_location[0]<<"  |  "<<map_location[1]<<"  |  "<<map_location[2]<<"  |  "<<map_location[3]<<"  |  "<<map_location[4]<<"  |"<<endl;
    cout << "|     |     |     |     |     |"<<endl;
    cout << "+-----+-----+-----+-----+-----+"<<endl;
    cout << "|     |     |     |     |     |"<<endl;
    cout << "|  "<<map_location[5]<<"  |  "<<map_location[6]<<"  |  "<<map_location[7]<<"  |  "<<map_location[8]<<"  |  "<<map_location[9]<<"  |"<<endl;
    cout << "|     |     |     |     |     |"<<endl;
    cout << "+-----+-----+-----+-----+-----+"<<endl;
    cout << "|     |  H  |  M  |     |  R  |"<<endl;
    cout << "|  "<<map_location[10]<<"  |  "<<map_location[11]<<"  |  "<<map_location[12]<<"  |  "<<map_location[13]<<"  |  "<<map_location[14]<<"  |"<<endl;
    cout << "|     |     |     |     |     |"<<endl;
    cout << "+-----+-----+-----+-----+-----+"<<endl;
    cout << "|     |     |  F  |     |     |"<<endl;
    cout << "|  "<<map_location[15]<<"  |  "<<map_location[16]<<"  |  "<<map_location[17]<<"  |  "<<map_location[18]<<"  |  "<<map_location[19]<<"  |"<<endl;
    cout << "|     |     |     |     |     |"<<endl;
    cout << "+-----+-----+-----+-----+-----+"<<endl;
    cout << "|  F  |  F  |  F  |  F  |  F  |"<<endl;
    cout << "|  "<<map_location[20]<<"  |  "<<map_location[21]<<"  |  "<<map_location[22]<<"  |  "<<map_location[23]<<"  |  "<<map_location[24]<<"  |"<<endl;
    cout << "|     |     |     |     |     |"<<endl;
    cout << "+-----+-----+-----+-----+-----+"<<endl;
}

