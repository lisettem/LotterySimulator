/*
subject:Lisette_Matute_A7.cpp
purpose:The purpose of this program is to simulate a 
		lottery using arrays. 
author:lmatute 
date:5/4/16
*/
#include <iostream>
#include <iomanip>
using namespace std; 

const int SIZE=6; 

//function prototypes 
void generateWinningNum(int winning[]);
void getPlayerNum(int player[]);
int getMatches(int winning[], int player[]);
void printNumber(int winning[], int player[]);

int main()
{
	int winning[SIZE];
	int player[SIZE];
	
	getPlayerNum(player);
	printNumber(winning, player); 

	system ("pause");
	return 0;
}
void getPlayerNum(int player[])
{
	cout<<"Enter six numbers between 1 and 9:";

	for (int i =0; i<SIZE; i++)
	{
		cin>>player[i];
	
		while (player[i]<1 || player[i]>9)
		{
			cout<<"Enter a number between 1 and 9:";
			cin>>player[i];
		}
	}

}
void generateWinningNum(int winning[])
{
	const int MIN=1, MAX=9;

	srand(time(0));
	for (int i=0; i< SIZE; i++)
	{
		winning[i]=MIN + rand() % (MAX-MIN+1); 

		cout<<winning[i]; 
	}
}
int getMatches(int winning[], int player[])
{
	int match=0; 

	for (int i=0; i<SIZE; i++)
	{
		if (winning[i]==player[i])
		match++; 
	}

	return match; 
}
void printNumber(int winning[], int player[])
{
	int matches;

	cout<<"The player's numbers were:\n";
	for (int i=0; i<SIZE; i++)
	{
		cout<<player[i]; 
	}
	cout<<endl; 

	cout<< "The winning numbers are:\n";
	generateWinningNum(winning);
	cout<<endl; 
	
	matches = getMatches(winning, player);
	cout<<"You have "<<matches<<" matches"<<endl; 
}
