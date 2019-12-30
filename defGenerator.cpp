#include <fstream>
#include <string>
#include <iostream>
#include "random.cpp"
#define MAX 55
using namespace std;

int waitforinput(void)
{
	char c;
	cout << "	Press Enter to continue, q to abort...";
	cin.get(c);
	if(c=='q'){return 1;}
	return 0;
}
string getDef(void)
{
	string ret;
	cin >> ret;
	if (!ret.compare(""))//Strings are equal
	{
		return "";
	}
	if (!ret.compare("q"))
	{
		return ret;
	}
	return "Hier könnte ein Suchergebnis stehen";
}

int main(void)
{
	srand(static_cast<int>(time(NULL)));
	string name[MAX];
	string nummer[MAX];
	string def[MAX];
	ifstream infile("Definitionen.txt");
	for(int i=0; i<MAX; i++)
	{
		getline(infile, nummer[i], '.');
		getline(infile, name[i], ':');
		getline(infile, def[i], '!');
	} //Einlesen aller Fragen und Antworten
/*	for (int i=0;i<MAX;i++)
	{
		cout<<"Definiere '"<<name[i]<<"'!"<<endl<<"Here goes: "<<def[i]<<endl<<endl<<endl;
	} 
*/ //Alle Ausgeben
	while(!(waitforinput()))
	{
	int z= Random::rnd_nobias(0,MAX-1);
	cout<<"Definieren sie: '"<< name[z]<<"'!"<<endl; //Ausgabe der zufälligen Frage
	if(waitforinput()){return 0;}
	cout<<endl<<def[z]<<endl;
	cout<<endl<<endl;
	}
	
/*	while(1)	//Mit Suche
	{
	cout<<"Geben sie bitte den Namen einer Definition ein oder drücken sie ENTER um über eine zufällige Definition abgefragt zu werden:"<<endl; // Ausgabe aller Fragen und Antworten
	if (!getDef().compare("q")){return 0;}
	else if(!getDef().compare("")){
	int z= Random::rnd_nobias(0,MAX-1); //Zufallszahl
	cout<<endl<<name[z]<<endl;
	if(waitforinput()){return 0;}
	cout<<def[z]<<endl<<endl;
	cout<<endl<<endl;
	}
	else{cout<<getDef()<<endl<<endl;}
	}
*/
	return 1;
}
