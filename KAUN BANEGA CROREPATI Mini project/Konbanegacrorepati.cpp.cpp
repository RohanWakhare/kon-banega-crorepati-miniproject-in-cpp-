
/*************************************************************
*		    COMPUTER SCIENCE PROJECT         			  *
*		KAUN BANEGA CROREPATI SIMULATION             		  *
**************************************************************/
/*************************************************************
*   HEADER FILE INCLUSIONS                                   				  *
**************************************************************/
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <dos.h>
#include <string.h>
#include <graphics.h>
#include <ctype.h>
#include <stdlib.h>
#include <fstream.h>
/*************************************************************
*   FUNCTION PROTOTYPES                                      				  *
**************************************************************/
void main();  /*main() requires a prototype itself because it is called in functions declared before itself.*/
void quit();
void displayhead(int);
void mainmenu();
void createquiz();
void addq();
void adminmenu();
void start();
void displayopt();
void showhelp();
void play();
void drawbox(int,int,int,int,int,int);
void showallq(int);

/*************************************************************
*    Global Variables                                        					  *
**************************************************************/
char Q[13][350];
char Options[13][4][20];
int A[13];
int q;
int t=100;

/*************************************************************
*    Class declaration                                       					  *
**************************************************************/
class kbc
{	int ans;
public:
char Ques[350],Opt[4][20];
kbc()
{	 ans=1;	
}
int getans()
{return ans;}
void readq()
{	 cout<<"\n\n    Enter question: \n\t\t";gets(Ques);
		 cout<<"\n\n    Enter Option1: ";gets(Opt[0]);
		 cout<<"\n\n    Enter Option2: ";gets(Opt[1]);
		 cout<<"\n\n    Enter Option3: ";gets(Opt[2]);
		 cout<<"\n\n    Enter Option4: ";gets(Opt[3]);
		 cout<<"Enter correct option number: ";cin>>ans;
		 cout<<"\n\n    New question added!";
		 delay(1000);
		 displayhead(2);
}
       	void showbrief();
};
void kbc::showbrief()
{	if(strlen(Ques)<80)
     cout<<Ques;
else
{	for(int i=0;i<74;i++)
      { cout<<Ques[i];
       }
     cout<<"...";
   }
}

/*************************************************************
*     Function to select random questions		     			  *
**************************************************************/
void createquiz()
{	 kbc KBCQ[13];
  fstream file;
  for(int i=0;i<13;i++)
  {	char fname[15]={'L','e','v','e','l',' ',i+49,'.','k','b','c','\0'};
if(i>=9)
{	fname[5]='1';
if(i==9)
				fname[6]='0';
else if(i==10)
				fname[6]='1';
else if(i==11)
				fname[6]='2';
else if(i==12)
				fname[6]='3';
}
    int no_of_records=0;
    ifstream levelfile(fname,ios::in|ios::binary);
	    if(levelfile)
   {	levelfile.seekg(0,ios::end);
long filesize=levelfile.tellg();
no_of_records=filesize/sizeof(kbc);
    }
    else
    {	cout<<"\nERROR>> FILE NOT FOUND: "<<fname;
getch();
mainmenu();
    }
    randomize();
    int qno=random(no_of_records+1);
    if(qno==0)
qno=1;
    file.open(fname,ios::in|ios::binary);
    file.seekg((qno-1)*sizeof(kbc),ios::beg);
    file.read((char*)&KBCQ[i],sizeof(kbc));
     strcpy(Q[i],KBCQ[i].Ques);
     strcpy(Options[i][0],KBCQ[i].Opt[0]);
     strcpy(Options[i][1],KBCQ[i].Opt[1]);
     strcpy(Options[i][2],KBCQ[i].Opt[2]);
     strcpy(Options[i][3],KBCQ[i].Opt[3]);
     A[i]=KBCQ[i].getans();
    file.close();
    getch();
  	}
}

/*************************************************************
*    Function to add a question to an existing database      			  *
**************************************************************/
void addq()
{	 reenter:
 displayhead(2);
  kbc KBCQ[13];
  int level=0;
cout<<"\n\n\n\n Enter the level you want to add questions to \n(The levels are numbered 1 to 13)...";
  	cin>>level;
char fname[15]={'l','e','v','e','l',' ',level+48,'.','k','b','c','\0'};
if(level>8)	
{	fname[5]='1';
if(level==10)
			fname[6]='0';
else if(level==11)
			fname[6]='1';
else if(level==12)
			fname[6]='2';
else if(level==13)
			fname[6]='3';
}
  	  cout<<"\n\nHow many questions do you want to enter?\n";
  int n=0;cin>>n;
  _setcursortype(_NORMALCURSOR);
  fstream file(fname,ios::out|ios::binary|ios::app);
  displayhead(2);
  for(int i=0;i<n;i++)
    {  	  cout<<"\nQ no."<<i+1<<": \n";KBCQ[i].readq();
  file.write((char*)&KBCQ[i],sizeof(KBCQ[i]));
    }
  file.close();
  _setcursortype(_NOCURSOR);
}







/*************************************************************
*    Function to display the KBC header                      				   *
**************************************************************/
void displayhead(int opt=1)
{	textcolor(LIGHTGREEN);textbackground(BLACK);clrscr();
   gotoxy(1,1);
   textcolor(WHITE);textbackground(BLUE);
   if(opt==1)
   {	 cprintf("ESC: EXIT");
 for (int ctr=0;ctr<19;ctr++)
cprintf(" ");
		cprintf("  Kaun Banega Crorepati                   F1: Help");
for (ctr=0;ctr<2;ctr++)
cprintf(" ");
   }
 else
   {	 for (int ctr=0;ctr<28;ctr++)
			cprintf(" ");
 cprintf("  Kaun Banega Crorepati                           ");	
 for (ctr=0;ctr<2;ctr++)
			cprintf(" ");
   }
   gotoxy(1,2);
}










/*************************************************************
*    Function to display the loading splash screen	     			  *
**************************************************************/
void start()
{	  displayhead(2);
  char l=176,d=178;
  cout<<"\n\n\n\n\n\n\n\t\t\t\t  LOADING\n\n\t\t\t\t\t ";
  for (int j=0;j<4;j++)
   {	  for(int i=0;i<7;i++)
  {	if(i==0){cout<<"\b\b\b\b\b\b\b"<<d<<l<<l<<l<<l<<l<<l;delay(80);}
			if(i==1){cout<<"\b\b\b\b\b\b\b"<<l<<d<<l<<l<<l<<l<<l;delay(80);}
			if(i==2){cout<<"\b\b\b\b\b\b\b"<<l<<l<<d<<l<<l<<l<<l;delay(80);}
			if(i==3){cout<<"\b\b\b\b\b\b\b"<<l<<l<<l<<d<<l<<l<<l;delay(80);}
			if(i==4){cout<<"\b\b\b\b\b\b\b"<<l<<l<<l<<l<<d<<l<<l;delay(80);}
			if(i==5){cout<<"\b\b\b\b\b\b\b"<<l<<l<<l<<l<<l<<d<<l;delay(80);}
			if(i==6){cout<<"\b\b\b\b\b\b\b"<<l<<l<<l<<l<<l<<l<<d;delay(80);}
  }
   }
  displayhead(2);
  cout<<"\n\n\n\n\n\t\t\t";textcolor(BLINK+LIGHTGREEN);textbackground(BLACK);
  cprintf("Press any key to continue...");
  getch();
  displayhead(2);
}

/*************************************************************
*    Function to show a list of questions in a file          			  *
**************************************************************/
void showallq(int levelnumber=1)
{	   kbc kbcobj;
   int recordsread=0;
   if(levelnumber==0)levelnumber++;
   char fname[15]={'l','e','v','e','l',' ',levelnumber+48,'.','k','b','c','\0'};

   if(levelnumber>=9)
  {	fname[5]='1';
if(levelnumber==10)
			fname[6]='0';
else if(levelnumber==11)
			fname[6]='1';
else if(levelnumber==12)
			fname[6]='2';
else if(levelnumber==13)
			fname[6]='3';
 }
   ifstream file(fname,ios::in|ios::binary);
    long filesize=0;
    int nofrecords=0;
    if(file)
    {	file.seekg(0,ios::end);
		filesize=file.tellg();
		nofrecords=filesize/sizeof(kbc);
		file.seekg(0,ios::beg);
    }
    else
    {	cout<<"ERROR>> FILE NOT FOUND: "<<fname;
		getch();
		mainmenu();
    }
    displayhead(2);
    while(file && recordsread<nofrecords)
   {	      cout<<"\n";      file.read((char*)&kbcobj,sizeof(kbc));
      recordsread++;
      cout<<recordsread<<") ";
      kbcobj.showbrief();
  }
   file.close();
}
/*************************************************************
*    Function to control selection of options in gameplay    			  *
**************************************************************/
void displayopt(int selected=0)
{  if(selected==0)
    cout<<"\n\n\n\t\t1) "<<Options[q][0]<<"\n\n\t\t2) "<<Options[q][1]<<"\n\n\t\t3) "<<Options[q][2]<<"\n\n\t\t4) "<<Options[q][3];
  else if(selected==1)
  {cout<<"\n\n\n\t    >>  1) ";textbackground(BLUE);cprintf(Options[q][0]);cout<<"\n\n\t\t2) "<<Options[q][1]<<"\n\n\t\t3) "<<Options[q][2]<<"\n\n\t\t4) "<<Options[q][3];}
  else if (selected==2)
  {cout<<"\n\n\n\t\t1) "<<Options[q][0]<<"\n\n\t    >>  2) ";textbackground(BLUE);cprintf(Options[q][1]);cout<<"\n\n\t\t3) "<<Options[q][2]<<"\n\n\t\t4) "<<Options[q][3];}
  else if (selected==3)
  {cout<<"\n\n\n\t\t1) "<<Options[q][0]<<"\n\n\t\t2) "<<Options[q][1];cout<<"\n\n\t    >>  3) ";textbackground(BLUE);cprintf(Options[q][2]);cout<<"\n\n\t\t4) "<<Options[q][3];}
  else if (selected==4)
  {cout<<"\n\n\n\t\t1) "<<Options[q][0]<<"\n\n\t\t2) "<<Options[q][1]<<"\n\n\t\t3) "<<Options[q][2]<<"\n\n\t    >>  4) ";textbackground(BLUE);cprintf(Options[q][3]);}
}

/*************************************************************
*    Function to display the help section                    				  *
**************************************************************/
void showhelp()
{ displayhead(2);
  cout<<"\n\n\n\t\t\t            HELP";
  cout<<"\n\n\t\t\t     Selection : Arrow keys";
  cout<<"\n\t\t\t     Submit : Enter key";
  cout<<"\n\t\t\t     Exit : Escape key";
  cout<<"\n\n\n\n\t\t\t          Gameplay";
  cout<<"\n\n\t\t\t  There are 13 questions in a game";
  cout<<"\n\t\t\t  which are selected randomly from";
  cout<<"\n\t\t\t  our database. Arrow keys are used";
  cout<<"\n\t\t\t  to highlight the options and enter";
  cout<<"\n\t\t\t  key to lock the answer. You can";
  cout<<"\n\t\t\t  can quit anytime by pressing ESC.";
  cout<<"\n\n\n\n\nPress ESC to go back...";
  drawbox(22,3,64,22,WHITE,LIGHTGRAY);
  drawbox(22,11,64,22,LIGHTGRAY,WHITE);
  char ch;
lbl1:
  ch=getch();
  if(ch==27)
  { clrscr();
    mainmenu();
  }
  else
    goto lbl1;
}

/*************************************************************
*    Function to control the game in play mode               			  *
**************************************************************/
void play()
{   long amt[13]={5000, 10000, 20000, 40000, 80000, 160000, 320000, 640000, 1250000, 2500000, 5000000, 10000000, 50000000 };
   char ans='0';int sel=0;
   createquiz();
//=======THE QUESTIONS ARE ASKED IN THIS SECTION=========
   for(q=1;q<13;q++)     //This loop is iterated 13 times with a different question each time.
  {
   for(t=45*4;t>=0;t--)  //Timer loop
    {
     displayhead(2);
     cout<<"\n\nQuestion "<<q+1<<"\n\t\t  "<<"In Hand: Rs."<<(amt[q]==5000?0:amt[q-1])<<"\t\t\tPrize: Rs."<<amt[q]<<"\n\n";
     cout<<Q[q];
     displayopt(sel);
     cout<<"\n\n\t\t\t You have "<<t/4<<" seconds to answer.";
	 if(kbhit())
	  { ans=getch();
	    if(ans==13)
		ans=sel+48;
	    if(ans==27)
		quit();
	    if(ans==59)
		showhelp();
	    if (ans==80||ans==72)
	     { if(ans==80)
		   sel++;    //down arrow
	       if(ans==72)
		   sel--;    //up arrow
	       if(sel<1)
		   sel=4;
	       if(sel>4)
		   sel=1;
	     }
	   t++; //This increment is for compensating the loss of time in analysing a keypress.
	     if(isdigit(ans) && (ans=='1'||ans=='2'||ans=='3'||ans=='4'))
	     {  cout<<"\nYou selected Option "<<ans<<"\n";delay(500);
		ans-=48;   //to enable processing answer as a numeric value, digit 0 is char 48
		  if(ans==A[q])
		    {cout<<"\n\n\t\t\t  YES!!! Correct Answer! You won Rs."<<amt[q];cout<<"\n\n\t\t\t  ";textcolor(LIGHTGREEN+BLINK);textbackground(BLACK);cprintf("Press any key to continue...");getch();goto dis;}
		  else if(ans!=A[q])
		    {ans='0';cout<<"\n\n\t\t\t  Sorry Wrong Answer.\n";
		      delay(500);cout<<"\n\t\t\t  Try again(y/n)? ";char ch;
reenter1:
		      ch=getch();
		      if(ch=='y'||ch=='Y'||ch==13)
		       play();
		      else if(ch=='n'||ch=='N'||ch==27)
		       {displayhead(1);mainmenu();}
		      else
			goto reenter1;
		    }

	     }

	  }
       else
	 {
	   if((t/4)<10)
	     {for(int j=0;j<20;j++)cout<<"\b";
	     textcolor(RED);textbackground(BLACK);
	     }
	   else
	     {for(int j=0;j<21;j++)cout<<"\b";
	     textcolor(GREEN);textbackground(BLACK);
	     }
	   cprintf("%i",t/4);textbackground(BLACK);textcolor(LIGHTGREEN);
   cprintf(" seconds to answer.");
	   delay(250);
	   if(t%5==0){sound(3000);delay(5);nosound();}
	 }

     }//end of timer loop

      cout<<"\n\n\t\t\t Game Over.";
      delay(500);cout<<"\n\t\t\t  Try again(y/n)? ";char ch;
reenter:
      ch=getch();
      if(ch=='y'||ch=='Y'||ch==13)
	play();
      else if (ch=='n'||ch=='N'||ch==27)
       mainmenu();
      else
       goto reenter;

dis:    }//end of the main for loop
    displayhead(2);    char l=179,c1=218,c2=191,c3=192,c4=217,d=196;
    cout<<"\n\n\n\n\n\t\t\t  Congratulations you've won the game!!!\n\n\t Your Cheque: \n\n";
    cout<<"\n\t\t "<<c1;for(int i=0;i<48;i++)cout<<d;cout<<c2;
    cout<<"\n\t\t "<<l<<"                                                "<<l;
    cout<<"\n\t\t "<<l<<"  Pay __The Winner_____________________________ "<<l;
    cout<<"\n\t\t "<<l<<"  a sum of Rs. ___5 Crore______________________ "<<l;
    cout<<"\n\t\t "<<l<<"                                                "<<l;
    cout<<"\n\t\t "<<l<<"                                                "<<l;
    cout<<"\n\t\t "<<l<<"    AXIS BANK                  AMITABH BACHHAN  "<<l;
    cout<<"\n\t\t "<<l<<"    Mumbai                                      "<<l;
    cout<<"\n\t\t "<<l<<"                                                "<<l;
    cout<<"\n\t\t "<<c3;for(i=0;i<48;i++)cout<<d;cout<<c4;
    getch();
}
/*************************************************************
*    Function to display credits before the program exits    *
**************************************************************/
void quit()
{  displayhead(2);
      cout<<"\n\n\n\n\n\n\n\n\t\t\t      Thank You for playing!";
      cout<<"\n\n\t\t\t\tCode by\n\t\t\t     Deepanshu Nagar\n";
      cout<<"\t\t\tEmail: dipanshunagar@hotmail.com\n";
      cout<<"\t\t\t  	   Roll number ------\n\n\t\t                Submitted to\n\t\t\t     Ms.Raina Gupta";
      cout<<"\n\t\t\t     Arunodaya Public School\n\n\n\n\n\nPress any key to exit...";
  drawbox(2,8,79,22,WHITE,LIGHTGRAY);
  getch();  clrscr();
  exit(0);
}
/*************************************************************
*    Function that controls the working of the admin menu        		  *
**************************************************************/
void adminmenu()
{ displayhead(2);
  cout<<"\n\n\n\n\n\t\t\t ENTER PASSWORD\n\n\n\t\t\t ";
  char ch,pass[20];
  drawbox(20,5,50,18,WHITE,LIGHTGRAY);
  drawbox(26,11,44,13,WHITE,LIGHTGRAY);
  int i=0;
  gotoxy(30,12);
  do
  { ch=getch();
    gotoxy(30+i,12);
   if(ch!=13)
    { pass[i]=ch;cout<<"*";
     i++;
     drawbox(20,5,50,18,WHITE,LIGHTGRAY);
     drawbox(26,11,44,13,WHITE,LIGHTGRAY);
     gotoxy(30+i,12);
    }
   }while(ch!=13);
  pass[i]='\0';
  if(strcmp(pass,"kbcadmin")==0)
    {displayhead(2);
     cout<<"\n\n\n\t\t\t AUTHORISED";
     delay(1000);
  displayhead(2);
  int sel=1;
  do
  {  cout<<"\n\n\n\n\t\t\t         ADMIN MENU";
     if(sel==1)
       cout<<"\n\n\n\t\t\t  >>  Add a Question\n\n\t\t\t      See all questions\n\n\t\t\t      Back to Main-Menu";
     else if(sel==2)
       cout<<"\n\n\n\t\t\t      Add a Question\n\n\t\t\t  >>  See all questions\n\n\t\t\t      Back to Main-Menu";
     else if(sel==3)
       cout<<"\n\n\n\t\t\t      Add a Question\n\n\t\t\t      See all questions\n\n\t\t\t  >>  Back to Main-Menu";
     drawbox(24,4,55,15,WHITE,LIGHTGRAY);
     ch=getch();
    if (ch==80) //down arrow
      sel++;
    else if (ch==72) //up arrow
      sel--;
    if (sel>3)   //selection out of bounds
      sel=1;
    else if (sel<1)   //selection out of bounds
      sel=3;

    displayhead(2);
  }while(ch!=13);

    if(sel==1)
      addq();
    else if(sel==2)
      {   gotoxy(1,20);
	  cout<<"\tWhich file do you want to open?\nPlease enter a file number 1 to 13: ";
	  int n;cin>>n;	  showallq(n);
      }
    else if(sel==3)
      mainmenu();
  }
  else
    {  cout<<"\n\n\n\t\t\t WRONG PASSWORD";
       getch();    }
}
/*************************************************************
*    Function to draw a border on the screen                 			  *
**************************************************************/
void drawbox(int x1,int y1,int x2,int y2,int color1=WHITE,int color2=WHITE)
{  for(int i=x1;i<=x2;i++)
   { if(i%2==0)textcolor(color1);
     else
     textcolor(color2);
     gotoxy(i,y1);
     cprintf("%c",219);
     gotoxy(i,y2);
     cprintf("%c",219);
   }
   for(i=y1;i<=y2;i++)
   { if(i%2==0)textcolor(color1);
     else
     textcolor(color2);
     gotoxy(x1,i);
     cprintf("%c",219);
     gotoxy(x2,i);
     cprintf("%c",219);
    }
}

/*************************************************************
*    Function that controls the main menu                    *
**************************************************************/
void mainmenu()
{   displayhead(1);
    int selected=1;
    char options[3][20]={"      PLAY      ","  Admin. Login  ","      Exit      "},ch;
    textbackground(BLACK);textcolor(WHITE);
    cout<<"\n\n\n\n\n\n\t\t\t        ";cprintf("    MAIN MENU   ");
    cout<<"\n\n\n\t\t\t        ";textbackground(BLUE);cprintf(options[0]);cout<<"\n\n\t\t\t        "<<options[1]<<"\n\n\t\t\t        "<<options[2];
    drawbox(30,6,51,17,WHITE,LIGHTGRAY);

    do
    { ch=getch();
    if (ch==80) //down arrow
      selected++;
    if (ch==72) //up arrow
      selected--;
    if (ch==27) //escape key
       quit();
    if (ch==59) //F1 Key
       showhelp();
    if (selected>3)   //selection out of bounds
      selected=1;
    if (selected<1)   //selection out of bounds
      selected=3;
    displayhead(1);
    textbackground(BLACK);textcolor(WHITE);
    cout<<"\n\n\n\n\n\n\t\t\t        ";cprintf("    MAIN MENU   ");
    if(selected==1)
      {cout<<"\n\n\n\t\t\t        ";textbackground(BLUE);cprintf(options[0]);cout<<"\n\n\t\t\t        "<<options[1]<<"\n\n\t\t\t        "<<options[2];}
    else if(selected==2)
      {cout<<"\n\n\n\t\t\t        "<<options[0]<<"\n\n\t\t\t        ";textbackground(BLUE);cprintf(options[1]);cout<<"\n\n\t\t\t        "<<options[2];}
    else if(selected==3)
      {cout<<"\n\n\n\t\t\t        "<<options[0];cout<<"\n\n\t\t\t        "<<options[1]<<"\n\n\t\t\t        ";textbackground(BLUE);cprintf(options[2]);}
    drawbox(30,6,51,17,WHITE,LIGHTGRAY);
    }while(ch!=13);
    if(selected==1)
       play();
    else if(selected==2)
       adminmenu();
    else if(selected==3)
       quit();
}


/*************************************************************
*    Function to start and run the program                   			  *
**************************************************************/
void main()
{   clrscr();
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    errorcode = graphresult();
    if (errorcode != grOk)  /* an error occurred */
     { printf("Graphics error: %s\n", grapherrormsg(errorcode));
       printf("Press any key to halt:");
       getch();
       exit(1); /* terminate with an error code */
     }
    //Draw the KBC logo
    setcolor(BLUE);
    for(int n=100;n<107;n++)
    circle(getmaxx()/2,getmaxy()/2,n);
    setcolor(LIGHTBLUE);
    arc((getmaxx()/2)-100,(getmaxy()/2)+0, 300, 60, 100);
    arc((getmaxx()/2)+100,(getmaxy()/2)+0, 120, 240, 100);
    arc((getmaxx()/2)+0,(getmaxy()/2)+100, 30, 150, 100);
    arc((getmaxx()/2)+0,(getmaxy()/2)-100, 210, 330, 100);
    arc((getmaxx()/2)+70,(getmaxy()/2)+70, 76, 194, 100);
    arc((getmaxx()/2)+70,(getmaxy()/2)-70, 165, 285, 100);
    arc((getmaxx()/2)-70,(getmaxy()/2)+70, 345, 104, 100);
    arc((getmaxx()/2)-70,(getmaxy()/2)-70, 255, 16, 100);
    setcolor(WHITE);
    settextstyle(0,HORIZ_DIR,2);
    outtextxy((getmaxx()/2)-160,(getmaxy()/2)-10,"Kaun Banega Crorepati");
    delay(1000);
    getch();
    getch();
    closegraph();
    delay(500);
    _setcursortype(_NOCURSOR);
    start();   //Displays the Loading splash screen
    getch();
main_menu:
    randomize();
    mainmenu();
    getch();
    displayhead(1);
goto main_menu;  //Program does not end until the user wishes to exit.
}
