#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<limits>
using namespace std;
using std::vector;
#include "scan.h"


std::vector <string>  cont;//array cont[*]="x,y"
int lines=0;
	int cx=0;
	int cy=0;
	int ww=0;
	int hh=0;
bool end=false;
int i=0;

std::vector <int> x;
std::vector <int> y;

int pointsx;
int pointsy;


void scan::load_file(char* name){ //füllt cont
	std::string width;
	std::string height;
	ifstream file(name);
	lines=0;
	
	while(file.good() ){
			
			//pos++;
		   	std::string line;
		   	std::getline(file, line);
	   		if(line.find("rgb(255,0,0)")<1000){
				if(line.find("cx")<1000){
					line.replace(0,line.find("cx=\"")+4,"");
					line.replace(line.find("\" cy=\""),6,",");
					line=line.substr(0,line.find("\""));
				  	cont.push_back(line);
					lines++;
					}
				}
			}
	file.close();
}


void scan::read_file(){

	i=0;
	while(i<lines){

		pointsx=atoi(cont[i].substr(0,cont[i].find(",")).c_str())-ww;
		pointsy=atoi(cont[i].substr(cont[i].find(",")+1, cont[i].length()-cont[i].find(",") ).c_str())-hh;
		//cout <<pointsy<<endl;
		x.push_back(cx*pointsx);
		y.push_back(cy*pointsy);
		i++;
		}

	}



void scan::test(){
	i=0;
	while(i<lines)
		{
		cout<<y[i]<<endl;
		i++;
		}
	}

void scan::set_cal(int kx, int ky, int www, int hhh){
	hh=hhh;
	ww=www;
	cx=kx;
	cy=ky;
	}

void scan::write_values(char* z){
	cout<<"# "<<lines<<" Punkte gefunden!\n";
	cout<<"# scan begin:"<<endl;
	i=0;
	while(i<lines){
		cout<<"v "<<x[i]<<".0 "<<y[i]<<".0 "<< z <<".0 1.0\n";
		i++;
		}
	cout << "#end plane nr "<<z<<endl;
	}



