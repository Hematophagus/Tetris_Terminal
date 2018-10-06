#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "tetris.h"

using namespace std;

int main(){
	
	srand(time(NULL));
	
	char **shape = newPiece();
	char c;
	
	print(shape);
	
	do{
	
		c = getch();
	
		if(c == 'd')
			rotatePiece(shape);
		else if(c == 'n')
			pickShape(shape);
		
		print(shape);
	
	}while(c != 'q');
	
	return 0;
}
