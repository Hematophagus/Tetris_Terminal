#include <cstdlib>
#include <ctime>
#include <iostream>
#include "tetris.h"

using namespace std;

void line(char **shape){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(j == n/2)
				shape[i][j] = '*';
			else
				shape[i][j] = ' ';
	
}

void box(char **shape){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i > 0 && i < n-1 && j > 0 && j < n-1)
				shape[i][j] = '*';
			else
				shape[i][j] = ' ';
				
}

void podium(char **shape){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i > 1 && (j == 2 || (j > 0 && i == n-1)))
				shape[i][j] = '*';
			else
				shape[i][j] = ' ';
}

void stairLeft(char **shape){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if((i == n-2 && j > 1) || (j > 0 && j < n - 1 && i == n-1))
				shape[i][j] = '*';
			else
				shape[i][j] = ' ';
}

void stairRight(char **shape){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if((i == n - 2 && j < 2) || (j > 0 && j < n - 1 && i == n-1))
				shape[i][j] = '*';
			else
				shape[i][j] = ' ';
}

void L(char **shape){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if((i > 0 && j == 1) || (j == n - 2 && i == n-1))
				shape[i][j] = '*';
			else
				shape[i][j] = ' ';
}

void J(char **shape){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if((i > 0 && j == 2) || (j == 1 && i == n-1))
				shape[i][j] = '*';
			else
				shape[i][j] = ' ';
}

char **newPiece(){
	char **shape = new char *[n];
	for(int i = 0; i < n; i ++)
		shape[i] = new char [n];	
	
	pickShape(shape);
	
	return shape;
}

void pickShape(char **shape){
	
	switch(rand()%7){
		case 0:
			line(shape);
			break;
		case 1:
			box(shape);
			break;
		case 2:
			podium(shape);
			break;
		case 3:
			stairLeft(shape);
			break;
		case 4:
			stairRight(shape);
			break;
		case 5:
			L(shape);
			break;
		case 6:
			J(shape);
			break;
	}	
	
}

void rotatePiece(char **shape){
	for (int i = 0; i < n/ 2; i++){ 
        for (int j = i; j < n-i-1; j++){ 
            int temp = shape[i][j]; 
  	 	    shape[i][j] = shape[j][n-1-i]; 
	       	shape[j][n-1-i] = shape[n-1-i][n-1-j]; 
	        shape[n-1-i][n-1-j] = shape[n-1-j][i]; 
            shape[n-1-j][i] = temp; 
        } 
    }
}

void print(char** shape){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << shape[i][j];
		cout << "\n";
	}		
}

void destroy(char ***shape){
	char **aux = *shape;
	for(int i = 0; i < n; i++)
		delete []aux[i];
	delete []aux;
	
	
}
