#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int main(){
	char black = 35;
	
	int size_x,size_y;
	
	cin >> size_x;
	cin >> size_y;
	
	size_x += 2;
	size_y += 2;
	
	int board[size_x][size_y];
	
	for(int a = 0; a< size_x;a++){
		for(int b = 0;b<size_y;b++){
			board[a][b] = 0;
		}
	}
	
	
	int posx,posy;
	int xx;
	/*for(int a = 1; a< size_x-1;a++){
		for(int b = 1;b<size_y-1;b++){
			cin >> xx;
			if(xx == '-')
			continue;
			else board[a][b] = 1;
		}
	}*/
	while(1){
		
	/*for(int a = 1; a< size_x-1;a++){
		for(int b = 1;b<size_y-1;b++){
			cout<< board[a][b]<<' ';
		}cout<<endl;
	}*/
	cin >> posx >> posy;
	if(posx == 0&&posy == 0)
		break;
	if(posx > size_x-1 || posy > size_y-1)
		continue;
	
	board[posx][posy] = 1;
	cout<<"------\n";
		
	}
	
	
	cout<<"------\n";
	
	int nearlife;
	
	while(1){
		
		///fflush(stdin);
		//getch();
		
		
		
		int milisec = 10; // length of time to sleep, in miliseconds
		struct timespec req = {0};
		req.tv_sec = 0;
		req.tv_nsec = milisec * 1000000L;
		nanosleep(&req, (struct timespec *)NULL);
		
		
		for(int a = 1; a< size_x-1;a++){
			for(int b = 1;b<size_y-1;b++){
				nearlife = 0;
				for(int inner_x = a-1;inner_x <= a+1;inner_x ++){
					for(int inner_y = b-1;inner_y<= b+1;inner_y++){
						if(inner_x == a && inner_y == b)
							continue;
						else if(board[inner_x][inner_y] == 1 || board[inner_x][inner_y] == 3)
								nearlife++;
						
					}
				}
				//cout<< nearlife<<'\n';
				//3 means to die in the next frame
				//5 means to be born in the next frame
				if(board[a][b] == 1){
					if( nearlife <2)
						board[a][b] = 3;
					
					else if( nearlife >3)
						board[a][b] = 3;
				}
				else if(board[a][b] == 0){
					if(nearlife == 3)
						board[a][b] = 5;
				}
					
				
				
			}
		}
		
		
			for(int a = 1; a< size_x-1;a++){
				for(int b = 1;b<size_y-1;b++){
					if(board[a][b] == 5)
						board[a][b] = 1;
					if(board[a][b] == 3)
						board[a][b] = 0;
				}
			}
			system("CLS");
			for(int a = 1; a< size_x-1;a++){
				for(int b = 1;b<size_y-1;b++){
					//cout<< board[a][b] << ' ';
					if(board[a][b] == 1)
						cout<<"# ";
					else cout<<"  ";
				}cout<<"\n";
			}
			
		
		
	}
	
	
	
	
	
	
}
