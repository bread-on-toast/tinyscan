#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using std::vector;

int main ( int bla, char *h[] ) {

int lines = 0;
ifstream file("laser.svg");

std::vector <string> cont;


while ( file.good() )
{
   std::string line;
   std::getline(file, line);
   if(line.find("rgb(255,0,0)")<1000){
	if(line.find("cx")<1000){
		line.replace(0,line.find("cx=\"")+4,"");
		line.replace(line.find("\" cy=\""),6,",");
		line=line.substr(0,line.find("\""));
		//cout<<line<<endl;
	  	cont.push_back(line);
	   	lines++;
		}
	}
}
file.close();
int i=0;
int pointsx[lines];
int pointsy[lines];
int x[lines];
int y[lines];
int cx=10000;//Variable welche proportionalität zwischen pixel auf bild und entfernung auf ebene herstellt
int cy=30000;
int cz=10;
while(i<lines){

pointsx[i]=atoi(cont[i].substr(0,cont[i].find(",")).c_str());
pointsy[i]=atoi(cont[i].substr(cont[i].find(",")+1, cont[i].length()-cont[i].find(",") ).c_str());
x[i]=cx/(pointsx[i]);
y[i]=cy/(pointsy[i]);

i++;
}

//cout<<lines<<"Punkte gefunden!\n";
//cout<<"TODO: \nCalculate x,y,z position\nwrite to cvs file\n\n\n\n"<<endl;

cout<<"# scan";
i=0;
while(i<lines){
cout<<"v "<<x[i]<<".0 "<<y[i]<<".0 "<< h[1] <<".0 1.0\n";
i++;
}
cout << "#end plane nr "<<h[1]<<endl;
  return 0;
}
