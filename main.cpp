#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using std::vector;

int main ( int bla, char *h[] ) {

//calc points
string width;
string height;
int lines = 0;
int ww=330;
int hh=425;
int i=0;
/*
std::vector <string> cal;

ifstream filecal("cal.svg");

  	std::string linecal;
   	std::getline(filecal, linecal);

   	if(linecal.find("rgb(255,0,0)")<1000){
			linecal.replace(0,linecal.find("cx=\"")+4,"");
			linecal.replace(linecal.find("\" cy=\""),6,",");
			linecal=linecal.substr(0,linecal.find("\""));

	  		cal.push_back(linecal);
	   		lines++;
			
		}cout <<"bla";

				
	cout <<"bla";
	hh=atoi(cal[0].substr(cal[0].find(",")+1, cal[0].length()-cal[0].find(",") ).c_str())+hh;
	ww=atoi(cal[0].substr(0,cal[0].find(",")).c_str())+ww;
	
hh=hh/lines;
ww=ww/lines;

filecal.close();
*/

ifstream file(h[2]);
std::vector <string> cont;
while ( file.good() )
{
   std::string line;
   std::getline(file, line);
/*   if(line.find("width")<10000){
	int start=line.find("width=\"")+7;
	int end=line.find("\" height=\"")-start;
	width=line.substr(start,end);
        //cout<<width<<endl;
	ww = atoi(width.c_str())/2;

   }
   if(line.find("height")<10000){
	int start=line.find("height=\"")+8;
	int end= line.find("\">")-start;
        height=line.substr(start,end);
	//cout<<height<<endl;
	hh = atoi(height.c_str())/2;
   }*/


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
i=0;
float pointsx[lines];
float pointsy[lines];
int x[lines];
int y[lines];
//Variablen welche proportionalität zwischen pixel auf bild und entfernung auf ebene herstellt
int cx=1;
int cy=3;
while(i<lines){

pointsx[i]=atoi(cont[i].substr(0,cont[i].find(",")).c_str())-ww;
pointsy[i]=atoi(cont[i].substr(cont[i].find(",")+1, cont[i].length()-cont[i].find(",") ).c_str())-hh;

x[i]=cx*pointsx[i];
y[i]=cy*pointsy[i];
//cout<<"v "<<x[i]<<".0 "<<y[i]<<".0 "<< h[1] <<".0 1.0\n";
i++;
}

cout<<"# "<<lines<<" Punkte gefunden!\n";
//cout<<"TODO: \nCalculate x,y,z position\nwrite to cvs file\n\n\n\n"<<endl;

cout<<"# scan"<<endl;
i=0;
while(i<lines){
cout<<"v "<<x[i]<<".0 "<<y[i]<<".0 "<< h[1] <<".0 1.0\n";
i++;
}


cout << "#end plane nr "<<h[1]<<endl;
  return 0;
}


