#include <iostream>
#include<windows.h>
#include "MMSystem.h"
#include <string.h>
#include <conio.h>
using namespace std;

class song
{
	
		public:
		char str[50],i;
		int play();
		void pause();
		int playing();
				
};
int song::play()
{
			PlaySound(TEXT(str),NULL,SND_ASYNC);
			
			int s;
			s=playing();
			
			PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
			return s;
}
	
void song::pause()
{
	char c=1;

	while(c!=0)
	{
		c=getch();
		if(c=='s')
		return;
        Sleep(10);
		
	}
}
song s[100];
void initsongs()
{
	
	strcpy(s[0].str,"songA");
	strcpy(s[1].str,"songB");
	strcpy(s[2].str,"songC");
	strcpy(s[3].str,"songD");
	strcpy(s[4].str,"songE");
	strcpy(s[5].str,"songF");
	strcpy(s[6].str,"songG");
	strcpy(s[7].str,"songH");
	strcpy(s[8].str,"songI");
	
	
	char c=0;
	cout<<"\n\nPRESS FOLLOWING BUTTONS FOR PERFORMING SPECIFIED OPERATION\n\n";
	cout<<"<<<A - TO PLAY PREIVOUS SONG>>><<<S - TO START/STOP SONG>>><<<D - TO PLAY NEXT SONG>>>\n";

	while(c!='s'){
		c=getch();
	}
}




void display(int i)
{
	cout<<"\n\tCURRENTLY PLAYING ----->		SONG\t"<<i+1<<"\n\n";
}


int song::playing()
{
	cout<<"PRESS FOLLOWING BUTTONS FOR PERFORMING SPECIFIED OPERATION\n";
	cout<<"<<<A - TO PLAY PREIVOUS SONG>>>   <<<S - TO STOP SONG>>>   <<<D - TO PLAY NEXT SONG>>>            ";
	char c=1;
	
	while(c!=0)
	{
		c=getch();
		
		if(c=='s')
		{
			PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
			exit;
	 	}
		if(c=='a')
			return -1;
		if(c=='d')
			return 1;
	}
}


int main(int argc, char** argv) 
{
	initsongs();
	int max=8;
	int i=0;
	int p=1;
	while(p!=0)
		{
		system("CLS");
		display(i);
		p=s[i].play();
		i+=p;
		if(i<0)
		{
			i=max-1;
		}
		else
		{
			i=i%(max);
		}
		}
	return 0;
}
