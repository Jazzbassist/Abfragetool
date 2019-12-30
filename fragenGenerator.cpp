#include <fstream>
#include <string>
#include <iostream>
#include "random.cpp"
#define MAX1 1 //Anzahl Fragen in Fragen1.txt
#define MAX2 1 //Anzahl Fragen in Fragen2.txt
using namespace std;

int waitforinput(void)
{
	char c;
	cout << "	Press Enter to continue, q to abort...";
	cin.get(c);
	if(c=='q'){return 1;}
	return 0;
}
int main(int argc, char** argv)
{
	int semester = 1;
	if(argc <= 1)  {
	//kein übergabeparameter (was tun?)
	}
	if(argc == 2) {
	//übergabeparameter vorhanden, auslesen!

		string help1 = "-h";
		string help2 = "--help";
		if( (help1.compare(argv[1]) == 0) || (help2.compare(argv[1]) == 0) ) {

		    cout << "Das ist die Hilfe zum Fragengenerator:" << endl << endl << 
		    "OPTIONS:" << endl << 
		    "1\n" << "\t" << "Fragen aus 1\n" << endl << 
		    "2\n" << "\t" << "Fragen aus 2\n" << 
		    "\n-h / --help\n" << "\t" << "Zeigt diese Hilfe an" << endl << endl;
		    return 0;
		}
		else if( stoi(argv[1]) == 1 || stoi(argv[1]) == 2) {

		    semester = stoi(argv[1]);
		}
		else {
		    cout << "Der Parameter '" << stoi(argv[1]) << "' bezeichnet kein gültiges Semester." << endl << "Für Compilerbau 1 bitte die 1 übergeben und für Compilerbau 2 die 2 übergeben." << endl;
		    return 1;
		}
	}
    
    
	srand(static_cast<int>(time(NULL)));
	if(semester==1){
		string frage[MAX1];
		string nummer[MAX1];
		string antwort[MAX1];
		ifstream fragen("Fragen.txt");
     		if(!fragen.is_open()) {
			return 1;
		}
		ifstream antworten("Antworten.txt");
		if(!antworten.is_open()) {
			return 1;
		}
		int start, end;
		start=0; end=MAX1;
		for(int i=start; i<end; i++)
		{
			getline(fragen, nummer[i], '.');
			getline(fragen, frage[i], '?');
			getline(antworten, nummer[i], '.');
			getline(antworten, antwort[i], '!');
		} 
		fragen.close();
		antworten.close();
		
		//Einlesen aller Fragen und Antworten
		/*for(int i=0; i<104; i++)
		{
			cout << i+1 <<". " << frage[i] << "?" << endl <<"Antwort: "<< antwort[i] << endl;
		}*/
		while(!waitforinput())
		{
		cout<<"Zufällige Frage:"<<endl; // Ausgabe aller Fragen und Antworten
		int z= Random::rnd_nobias(start,end-1); //Zufallszahl
		cout<< z+1 <<". " << frage[z]<<"?"<<endl; //Ausgabe der zufälligen Frage
		if(waitforinput()){return 0;}
			cout<<endl<<antwort[z]<<endl;
			cout<<endl<<endl;
		}
		return 0;
	}else if(semester == 2){
		string frage[MAX2];
		string nummer[MAX2];
		string antwort[MAX2];
		string antwort2[MAX2];
		ifstream fragen("Fragen2.txt");
		if(!fragen.is_open()) {
			return 1;
		}
		ifstream antworten("Antworten2.txt");
		if(!antworten.is_open()) {
			return 1;
		}
		ifstream antworten2("Antworten2 alternativ.txt");
		if(!antworten2.is_open()) {
			return 1;
		}
		int start, end;
		start=MAX1; end=MAX1+MAX2;
		for(int i=start; i<end; i++)
		{
			getline(fragen, nummer[i-MAX1], '.');
			getline(fragen, frage[i-MAX1], '?');
			getline(antworten, nummer[i-MAX1], '.');
			getline(antworten, antwort[i-MAX1], '!');
			getline(antworten2, nummer[i-MAX1], '.');
			getline(antworten2, antwort2[i-MAX1], '!');
		} 
		fragen.close();
		antworten.close();
		antworten2.close();

		//Einlesen aller Fragen und Antworten
		/*for(int i=start; i<end; i++)
		{
			cout << i+1 <<". " << frage[i-104] << "?" << endl 
			<<"Antwort: "<< antwort[i-104] << endl << antwort2[i-104] << endl;
		}*/
		while(!waitforinput())
		{
			cout<< "------------" << endl << "Zufällige Frage:"<<endl; // Ausgabe aller Fragen und Antworten
			int z= Random::rnd_nobias(start,end-1); //Zufallszahl
			cout<< z+1 <<". " << frage[z-1]<<"?"<<endl; //Ausgabe der zufälligen Frage
			if(waitforinput()){return 0;}
			cout<<endl<<antwort[z-1]<<endl;
			cout<<endl;
			if(waitforinput()){return 0;}
			cout<<endl<<antwort2[z-1]<<endl;
			cout<<endl<<endl;
		}
		


		return 0;
	}
}
