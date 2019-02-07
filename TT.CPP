//-----------------------------------------------------------------------
//
// -------------------------------------------
// | TYPING TUTORIAL AND LOGIN SYSTEM MODEL |
// -------------------------------------------
//
// MADE BY : E.Rohith
//           S.Sankaran
//	     S.Sitharthan
//	     Sajeet Prasad Sah
//
// CLASS   : 12th STD.
//
// SCHOOL  : Kola Perumal Chetty Vaishnav Senior Secondary School
//
//-----------------------------------------------------------------------


  #include<iostream.h>
  #include<conio.h>
  #include<stdio.h>
  #include<string.h>
  #include<stdlib.h>
  #include<ctype.h>
  #include<fstream.h>
  #include<process.h>
  #include<time.h>
  #include<dos.h>

  #define TESTMODE '1'
  #define TRAINMODE '2'
  #define QUIT '3'
  #define ESC '\xlb'
  #define Y 'y'
  #define N 'n'

  enum Boolean
  {
     FALSE,
     TRUE
  };

  class LOGIN

  {

	   private:

		   char login_name[25];
		   char passwd[20];

	   public:

		   void set_login();
		   void set_passwd();
		   void set_login_name();
		   void set_login_name(char str[25]);
		   void temp();
		   int access_login(char str[]);
		   int get_pass(char Password[]);
		   int check_pass();

  };


//------------------------------------------------------------------------
// FUNCTION PROTOTYPES
//----------------------------------------------------------


  void MainProcess (LOGIN &log) ;

  void TestMode () ;

  void TestInitial (int * , int * ,int *, fstream &, char *) ;

  void TestProcess (int * , int * , int * , int * , char * , int *) ;

  void UserInput (int * , int * , int * , int * , char *) ;

  void EndTestMode () ;

  void OutputLetter (int * , int * , char , int *) ;

  void CheckCursorPosition (int * , int * , int * , char * , int *) ;

  void NewPage (int * , int * , char * , int *) ;

  void NewLine (int * , int *) ;

  void CheckIfTyped(int * , int * ) ;

  void Report (int * , int *) ;

  void print_char(char *,int *);

  void TrainMode () ;

  void TrainInitial () ;

  void TrainProcess (int * , int *) ;

  void SelectLetter (char , int * , int *) ;

  void PrintLetter () ;

  void TrainUserInput (char , int * , int *) ;

  void EndTrainMode () ;

  void TrainOutputLetter (int , int * , int *) ;

  void SelectWord (int * , int *) ;

  void PrintWord (char *) ;

  void TrainUserInputWord (char * , int * , int *) ;

  void EndTrainWordMode () ;

  void TrainOutputWord (int * , int *) ;

  void TrainCheckIfTyped (int * , int *) ;

  void TrainReport (int * , int *) ;

  void QuitConfirm () ;

  void EndBody () ;

  void write_to_file(LOGIN );

  int usercheck(LOGIN &login,char str[]);

  void box(int ,int ,int ,int );

  void login_screen();

  void new_user_screen();

  void welcome_screen();

  void instruct();

  void aboutus();


//-----------------------------------------------------------
// GLOBAL VARIABLES
//--------------------------------------------------


enum	Boolean    ExitProgram, ExitTestProcess, ExitTrainProcess,
		   ExitTrainUserInput, TrainSelect, ChoiceLetter,
		   ExitTrainUserInputWord, EndofWord ;

int cntr=0;
char RequiredLetter ;
float TimeUsed ;
char Letters[] ={
		 'a','s','d','f','g','h','j','k','l','q','w','e','r','t','y','u','i','o','p','z','x','c','v','b','n','m',
		 '0','1','2','3','4','5','6','7','8','9',
		 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		 '+','-','*','/',',','.','"','?','='
		};

clock_t TimeStart , TimeStop ;

//-----------------------------------------------------------
// LOGIN CLASS FUNCTIONS
//-----------------------------------------------------------

//*******************
// prints login name
//*******************

  void LOGIN::temp()
  {

	cout<<login_name;

  }

//*****************
//Sets Login Name
//*****************

  void LOGIN::set_login_name(char str[25])
  {

	 strcpy(login_name,str);

  }


//********************************************
//checks if login_name and str[] are equal
// returns 1 if equal
// 0 if not same

int LOGIN::access_login(char str[25])
{
      if(strcmp(str,login_name))
	      return 0;
      else
	      return 1;
}

//********************************************
//sets password


  void LOGIN::set_passwd()
  {
	char password[20]={'\O'};

	get_pass(password);

	strcpy(passwd,password);
  }


//********************************************
//checks password
//returns 0 if incorrect
// 1 if correct
// -1 if too many characters were entered


  int LOGIN::check_pass()
  {
	char Password[20]={'\0'};
	int pass=0;
	int p , i;

	p=get_pass(Password);
	pass=strcmp( passwd, Password ); /* compare strings */

	if( pass != 0 )
	{
		//Login Unsuccessful
		i = 0 ;
	}

	else if( pass == 0 )
	{
		//successfull login
		i = 1 ;
	}

	if(p == 19) /* indicates too many characters were entered*/
	{
		i = -1 ;
	}
	return i;
  }

//********************************************
//obtains password and prints '*' on the screen
//returns password length


  int LOGIN::get_pass(char Password[])
  {
	char input = '\0';
	int pass;
	int p = 0;
	for(p = 0;p < 19;p++)
	{
		input = getch(); /* get character entered */

		if( input != '\r' && input != '\b' )
		{
			if( isprint( input ) != 0 )

			Password[p] = input; /* store input in Password */

			if( iscntrl( input ) == 0 )
			{
				textcolor(12);
				cprintf("*");
				textcolor(7); /* print '*' instead of input */
			}
		}

		else if( input == '\r' ) /* if input = 'return' then */
		{
		break;	         /* break out of for() statment */
		}
		else if( input == '\b' )/* if input = 'backspace' then */
		{
			if( p > 0 )
			{  //make sure that the 'password' prompt is not deleted */

				cout<<'\b' << " " << '\b' ; /* erase the last '*' */
				--p;
				Password[p]='\01';
				/*overwrite last character with '\0'*/
			}

			--p;
		}


		/* END OF UPDATED CODE */
	}

	return p;

  }

//********************************************
//writes data to file

  void write_to_file(LOGIN login)
  {
	fstream file;
	file.open("type.dat",ios::in|ios::out|ios::binary|ios::app);
	file.write((char*) &login,sizeof(login));
	file.close();
  }


//********************************************
// checks if the username exists
// returns 1 if username exists
// 0 if username does not exist


  int usercheck(LOGIN &login,char str[])
  {
	fstream file;
	file.open("type.dat",ios::in|ios::binary);
	file.seekg(0);
	while(1)
	{
	  //read from file
		file.read((char*) &login,sizeof(login));
		if(!file)
		break;
		else
		if(login.access_login(str)==1)
		{
			return 1;
		}
	}
	file.close();
	return 0;
  }


//********************************************
//draws box for the given coordinates


  void box(int x1,int y1,int x2,int y2)
  {
	gotoxy(x1,y1);
	cprintf("Ú");
	gotoxy(x2,y1);
	cprintf("¿");
	gotoxy(x1,y2);
	cprintf("À");
	gotoxy(x2,y2);
	cprintf("Ù");

	for(int i=x1+1;i<x2;++i)
	{
		gotoxy(i,y1);
		cprintf("Ä");
		gotoxy(i,y2);
		cprintf("Ä");
	}

	for(i=y1+1;i<y2;++i)
	{
		gotoxy(x1,i);
		cprintf("³");
		gotoxy(x2,i);
		cprintf("³");
	}
  }



//-------------------------------------------------
// TUTOR SCREEN FUNCTIONS
//-------------------------------------------------


  void t_main(LOGIN & log)
  {

	randomize () ; //to make the random number generated more randomly

	ExitProgram = FALSE ;

	do
	{

		MainProcess (log) ;

	} while (ExitProgram == FALSE) ;

  }


//********************************************
//handles tutor menu options


  void MainProcess (LOGIN &log)
  {
	int Count ;
	char MenuChoice;
	textbackground(BLACK);
	clrscr () ;

	textcolor(BLUE);
	box(1,1,79,50); //screen border
	textcolor(YELLOW);
	box(23,17,55,27); //frame
	gotoxy(65,3);
	log.temp();
	gotoxy (30 , 19) ;
	textcolor(LIGHTGREEN);
	cprintf("1. Test Mode"); //Display the menu
	gotoxy (30 , 21) ;
	cprintf("2. Training Mode");
	gotoxy (30 , 23) ;
	cprintf("3. Log Out");
	gotoxy (30 , 25) ;
	textcolor(LIGHTRED);
	cprintf("Enter your choice :");
	gotoxy (49 , 25) ;
	MenuChoice = getch () ; //Accept a key value from the user

	switch (MenuChoice)
	{
		case '1' : //if the user press 1
			 TestMode () ;
			 break ;
		case '2' : //if the user press 2
			 TrainMode () ;
			 break ;
		case '3' : //if the user press 3
			 QuitConfirm () ;	     //Call QuitConfirm ()
	}

  }

//--------------------------------------------------
// TEST FUNCTIONS
//--------------------------------------------------


  void TestMode ()
  {
	int x=0,y=0, InputCount=0, CorrectInputCount=0, Page=0;
	char str[50000] ;
	fstream file;

	clrscr();
	TestInitial(&x,&y,&Page,file,str);


	do    //Once the user pressed ESC, it will exit

	{

		TestProcess(&x,&y,&InputCount, &CorrectInputCount,str,&Page);

	}while(ExitTestProcess==FALSE) ;

	//if the user have not typed any letter, no report will be printed

	CheckIfTyped (&InputCount , &CorrectInputCount) ;

	file.close() ; //close the file

  }

//************************************************
//initialises variables in test and selects random passage

  void TestInitial(int *x, int *y, int *Page, fstream &file, char *str)
  {

	int Count,random_file;
	randomize();
	random_file=random(10)+1;  	//generate a random number
					//in the range from 1 to 10

	switch(random_file) //select a random file
	{
		case 1 :
			 file.open("passage1.txt" ,ios::in) ;
			 break ;
		case 2 :
			 file.open("passage2.txt" ,ios::in) ;
			 break ;
		case 3 :
			 file.open("passage3.txt" ,ios::in) ;
			 break ;
		case 4 :
			 file.open("passage4.txt" ,ios::in) ;
			 break ;
		case 5 :
			 file.open("passage5.txt" ,ios::in) ;
			 break ;
		case 6 :
			 file.open("passage6.txt" ,ios::in) ;
			 break ;
		case 7 :
			 file.open("passage7.txt" ,ios::in) ;
			 break ;
		case 8 :
			 file.open("passage8.txt" ,ios::in) ;
			 break ;
		case 9 :
			 file.open("passage9.txt" ,ios::in) ;
			 break ;
		case 10 :
			 file.open("passage0.txt" ,ios::in) ;
			 break ;
	}

	if(file==NULL) //if cannot open the file
	{
		cout<<"\nCannot open the file!!";
		ExitTestProcess = TRUE ;
	}

	else //if can open the file
	{
		//The letters of the external file are checked if they are
		//newlines or tabs. If they are , they will be changed into
		//spaces to avoid any error.

		file.seekg(0);

		for ( Count = 0 ; !file.eof() ; Count++ )
		{
			file.get(str[Count]);
			if((str[Count]=='\t')||(str[Count]=='\n'))
			{
				str[Count]=' ' ;
			}
		}

		print_char( str, Page);

	}

	textcolor(LIGHTGREEN);

	ExitTestProcess = FALSE ;

	*x = 5 ; //tell the computer that the starting cursor position
	*y = 5 ; //is (1 , 2)
	gotoxy (5 , 40) ;
	textcolor(WHITE);
	cprintf("Press any key to start!");

	getch () ; //wait for the user to press any key

	delline () ; //delete all the content of the current line

	gotoxy (5 , 40) ;

	cprintf("Press ~ to quit.");

	TimeUsed = 0 ;
	TimeStart = clock () ; //record the current time into TimeStart

	gotoxy (5 , 5) ;
  }


//************************************************
//handles test code

  void TestProcess (int *x, int *y, int *InputCount, int *CorrectInputCount,char *str, int *Page)
  {
	UserInput(x,y,InputCount, CorrectInputCount,str);
	CheckCursorPosition(x,y,CorrectInputCount,str,Page);
  }

//************************************************
//inputs passage

  void UserInput (int *x , int *y , int *InputCount , int *CorrectInputCount ,char *str )
  {
	char InputLetter ;
	static float TimeStop ;
	textcolor(YELLOW);
	gotoxy (27 , 24) ;
	cprintf("Time used     : ");
	gotoxy (27 , 25) ;
	cprintf("Accuracy      : ");
	gotoxy (27 , 26) ;
	cprintf("Speed         : ");
	gotoxy (27 , 27) ;
	cprintf("Wrong letters : ");
	gotoxy (27 , 28) ;
	cprintf("Typed letters : ");
	gotoxy (*x , *y) ;

	while ( !kbhit() )
	{
		if ( *InputCount > 0 )
		{
			double Speed ;

			//Calculate the accuracy
			float Accuracy = (float) *CorrectInputCount * 100 / *InputCount ;

			//Calculate the number of letters typed wrongly
			int WrongInput = *InputCount - *CorrectInputCount ;

			//Calculate wpm
			TimeStop = clock () ;
			TimeUsed = TimeUsed + (TimeStop - TimeStart) / CLK_TCK ;
			Speed = *CorrectInputCount / 5 / (TimeUsed / 60) ;
			TimeStart = clock () ;

			gotoxy (45 , 24) ;
			cout<<TimeUsed<<" seconds" ;
			gotoxy (45 , 25) ;
			cout<<Accuracy<<" %" ;
			gotoxy (45 , 26) ;
			cout<<Speed<<" wpm" ;
			gotoxy (45 , 27) ;
			cout<<WrongInput<<" letters" ;
			gotoxy (45 , 28) ;
			cout<<*InputCount<<" letters";
			gotoxy (*x , *y) ;
			delay (100) ;
		}

	}

	InputLetter = getch ();

	if(InputLetter=='`') //if the user press ESC
	{
		TimeStop = clock () ;
		EndTestMode () ;
	}
	else
	{
		//if the user typed correcly
		if(InputLetter==str[*CorrectInputCount])
			OutputLetter(x, InputCount, InputLetter, CorrectInputCount);

		else //if the user typed wrongly
			(*InputCount)++;
	}
  }


//************************************************
//ends test mode


  void EndTestMode()
  {
	ExitTestProcess=TRUE;
  }


//************************************************
//Prints the letter typed

  void OutputLetter (int *x , int *InputCount , char InputLetter , int *CorrectInputCount)

  {

	(*CorrectInputCount)++;   //the user typed 1 more correct
	(*InputCount)++;    //the user typed 1 more letter
	putchar(InputLetter);   //output the key the user pressed
	(*x)++;


	//the cursor should be shifted
	//to right by 1 position

  }


//************************************************
//handles cursor position in the box

  void CheckCursorPosition(int *x, int *y, int *CorrectInputCount, char *str, int *Page)

  {
	if ( str[*CorrectInputCount] == EOF )
	{
		getch();
		TimeStop=clock();
		EndTestMode ();
	}
	else //if the cursor reach the end of any line ,
	{

		if (wherex()==75 && wherey()>=19)
		{
			clrscr () ;
			NewPage (x , y , str , Page) ;
		}
		else
		{
			if(*x==75)
			{
			NewLine(x,y);
			}
		}
	}

  }


//************************************************
//handles page changeover and printing in the new page

  void NewPage (int *x , int *y , char *str , int *Page)
  {
	(*Page) ++ ;
	print_char(str,Page);
	textcolor(WHITE);
	gotoxy (30 , 30) ;
	printf ("Press ESC to quit.") ;
	*x = 5 ;
	*y = 5 ;
	gotoxy (*x , *y) ;
  }


//************************************************
//takes cursor to next line's starting position


  void NewLine(int *x,int *y)
  {
	*x=5;
	*y+=3; //tell computer to shift the cursor down two rows
	gotoxy (*x , *y);
  }


//************************************************
//checks if user typed
//prints report only if user entered at least one character

  void CheckIfTyped (int *InputCount , int *CorrectInputCount)

  {
	//if the user have not typed anything, it does not show report

	if (*InputCount != 0)
		Report (InputCount , CorrectInputCount) ;
  }


//************************************************
//prints report


  void Report (int *InputCount , int *CorrectInputCount)
  {

		//Calculate the accuracy

	float Accuracy = (float) *CorrectInputCount * 100 / *InputCount ;

		//Calculate the number of letters typed wrongly

	int WrongInputcount = *InputCount - (*CorrectInputCount) ;

		//Calculate wpm

	double Speed = (*CorrectInputCount / 5) / (TimeUsed / 60) ;

	clrscr () ;
	box(1,1,79,50);
	textcolor(LIGHTGREEN);
	gotoxy (20 , 8) ;
	cprintf ( "Time Used       : %10.2f seconds" , TimeUsed ) ;
	gotoxy (20 , 10) ;
	cprintf ( "Character Typed : %10d letters" , *InputCount ) ;
	gotoxy (20 , 12) ;
	cprintf ( "Wrong Input     : %10d letters" , WrongInputcount ) ;
	gotoxy (20 , 14) ;
	cprintf ( "Accuracy        : %10.2f %%" , Accuracy) ;
	gotoxy (20 , 16) ;
	cprintf ( "Speed           : %10.2f wpm (words per minute)" , Speed);
	gotoxy (26 , 25) ;
	textcolor(LIGHTBLUE);
	cprintf ( "Press ~ key to exit") ;

		//wait until the user press ESC

	while(tolower(getch())!='`');

  }


//************************************************
//Prints characters on the screen


  void print_char(char *str,int *Page)
  {
	clrscr () ;
	textcolor(BLUE);
	box(1,1,79,50);
	textcolor(LIGHTBLUE);
	box(4,3,75,21);
	gotoxy(5,4);

	textcolor(LIGHTGREEN);
	int Row,Column;

	for (Row = 0 ; Row < 6 ; Row++)
	{
		gotoxy(5,wherey());
		for ( Column = 1 ; Column <= 70 ; Column++ )
		{
			if (str[(Row*70+Column-1)+(*Page*70*6)]==EOF)
			{
			return;
			}
			cprintf ("%c",str[(Row*70+Column-1)+(*Page*70*6)]);
		}
		cout<<"\n\n\n";
	}
  }


//-----------------------------------------------------
// TRAIN MODE FUNCTIONS
//-----------------------------------------------------


  void TrainMode ()
  {

	int CorrectInputCount = 0 , InputCount = 0 ;
	TimeUsed = 0 ;

	TrainInitial () ;

	//Once the user pressed ESC , it will end TrainProcess

	while (ExitTrainProcess == FALSE)
	{
		TrainProcess ( &CorrectInputCount , &InputCount) ;
	}

	//Check if the user typed in train mode

	TrainCheckIfTyped ( &CorrectInputCount , &InputCount ) ;

  }


//************************************************
//initialises variables in train mode
//handles menu options


  void TrainInitial ()
  {

	char ch ;
	clrscr () ;
	textcolor(BLUE);
	box(1,1,79,50);
	textcolor(YELLOW);
	box(22,17,59,29);
	ExitTrainUserInputWord = FALSE ;
	ExitTrainProcess = FALSE ;
	gotoxy (25 , 20) ;
	textcolor(LIGHTGREEN);
	cprintf("1. Single letter training.");
	gotoxy (25 , 23) ;
	cprintf("2. Words training.");
	gotoxy (25 , 26) ;
	textcolor(LIGHTRED);
	cprintf("Please press either 1 , 2 or ~: ");
	ch=getch();
	if(ch=='`')
			ExitTrainProcess = TRUE ;
	else
	{
		if (ch == '1')
			ChoiceLetter=TRUE;
		if (ch == '2')
			ChoiceLetter=FALSE;
	}
  }


//************************************************
//processes according to user's choice


  void TrainProcess(int *CorrectInputCount , int *InputCount)
  {

	char InputLetter ;

	if (ChoiceLetter == TRUE)
		SelectLetter (InputLetter , CorrectInputCount , InputCount) ;
	else
		SelectWord (CorrectInputCount , InputCount) ;
  }


//************************************************
//select random letter


  void SelectLetter (char InputLetter , int *CorrectInputCount , int *InputCount)

  {

	ExitTrainUserInput = FALSE ;
	PrintLetter () ;

	do //Once the user press ESC key , it will exit Train mode
	{
		TrainUserInput ( InputLetter , CorrectInputCount , InputCount);

	} while(ExitTrainUserInput==FALSE);

  }


//************************************************
//prints the selected letter


  void PrintLetter ()
  {

	clrscr () ;
	textbackground(BLACK);
	textcolor(BLUE);
	box(1,1,79,50);
	time_t t;
	randomize();
	srand((unsigned) time(&t));
	RequiredLetter=Letters[random(71)];
	gotoxy (30 , 25) ;
	textcolor(YELLOW);
	cprintf("Press ~ to quit.");
	gotoxy (35 , 17) ;
	textcolor(LIGHTGREEN);
	cprintf("%c",RequiredLetter);
	TimeStart = clock () ; //record the current time as start time
  }


//************************************************
// gets user input


  void TrainUserInput (char InputLetter , int *CorrectInputCount , int*InputCount)

  {
	textbackground(BLACK);
	textcolor(WHITE);
	gotoxy(35,18);
	InputLetter = getch () ; //wait for the user to input choice'

	if (InputLetter == '`') //Pressed ~ key
	{
		ExitTrainUserInput = TRUE ;
		ExitTrainProcess = TRUE ;
	}
	else
	{
		if (InputLetter == RequiredLetter) //Typed correctly
		{
			TrainOutputLetter (InputLetter , CorrectInputCount, InputCount) ;
		}
		else //Typed wrongly
		{
			(*InputCount) ++ ;
		}
	}
  }


//************************************************
// outputs entered letter only if it is correct


  void TrainOutputLetter (int InputLetter , int *CorrectInputCount , int *InputCount)
  {

	TimeStop = clock () ; //Record the current time as stop time
	(*CorrectInputCount) ++ ;
	(*InputCount)++ ;
	cout<<InputLetter;
	ExitTrainUserInput = TRUE ;

	//Accumulate the time used of the user to type many letters

	TimeUsed = TimeUsed + (TimeStop - TimeStart) / CLK_TCK ;
  }

//************************************************
// selects random word from words .txt


  void SelectWord (int *CorrectInputCount , int *InputCount)
  {

	char Word[20] ;
	ExitTrainUserInputWord = FALSE ;

	for (int i=0;i<20;i++)
	{
		Word[i]=0;
	}

	textbackground(BLACK);
	textcolor(WHITE);
	PrintWord (Word) ;

	do
	{

		TrainUserInputWord (Word , CorrectInputCount , InputCount) ;

	} while ( (ExitTrainUserInputWord == FALSE) && (EndofWord ==FALSE) ) ;

  }


//************************************************
// prints the selected word


  void PrintWord (char *Word)
  {
	fstream file;
	randomize();
	char ch;
	long int Random = random (173) , Count = 0 ;

	file.open("Words.txt",ios::in|ios::binary);
	clrscr () ;
	box(1,1,79,50);

	if (file == NULL)
	{

		printf ("Cannot open the file 'words.txt'!!" "\nPlease copy it into the directory.") ;
		ExitTrainUserInputWord = TRUE ;
		ExitTrainProcess = TRUE ;
	}
	else
	{
		textbackground(BLACK);
		textcolor(WHITE);
		box(25,9,55,15);
		file.seekg((Random),ios::beg);

		do
		{
			file.seekg(1,ios::cur);
			file.get(ch);
		} while((ch!=' ')&&(ch!='\n'));
		do
		{
			file.get(Word[Count]);
		} while(Word[Count]!=' '&&(Word[Count++]!='\n'));

		gotoxy(35,12);

		for (Count = 0 ; Count < 20 ; Count++)
		{
			textcolor(YELLOW);
			cprintf("%c",Word[Count]);
			textcolor(WHITE);
		}
		if(cntr==0)
		{
			gotoxy (1 , 25)	;
			printf	("Press ENTER key to start!") ;
			getch () ; //wait for the user to press any key
			delline () ; //delete all the content of the current line
		}
		gotoxy (35 , 13) ;
		EndofWord = FALSE ;
		file.close();
		cntr++;
	}
  }


//***************************************************
//Inputs word from user
//***************************************************

  void TrainUserInputWord (char *Word , int *CorrectInputCount, int *InputCount)

  {

	char InputLetter ;
	static Count = 0 ;
	int x = wherex () , y = wherey () ;
	gotoxy (27, 19) ;
	cout<<"Time used       : " ;
	gotoxy (27, 20) ;
	cout<<"Accuracy        : ";
	gotoxy (27, 21) ;
	cout<<"Speed           : ";
	gotoxy (27, 22) ;
	cout<<"Wrong letters   : ";
	gotoxy (27, 23) ;
	cout<<"Typed letters   : ";
	gotoxy (x , y) ;

	if(InputLetter=='`')
	{
		// EndTrainWordMode() ;
		//Count = 0	;
		TrainReport(CorrectInputCount	, InputCount);
	}
	while ( !kbhit() )
	{
		if ( *InputCount > 0 )
		{
			double Speed ;
			float Accuracy = (float) *CorrectInputCount * 100 /(*InputCount) ;
			int WrongInput = *InputCount - *CorrectInputCount ;
			TimeStop = clock () ;
			TimeUsed = TimeUsed + (TimeStop - TimeStart) / CLK_TCK ;
			Speed = (*CorrectInputCount / 5) / (TimeUsed / 60) ;
			TimeStart = clock () ;

			gotoxy (45 , 19) ;
			cout<<" "<<TimeUsed<<" seconds";
			gotoxy (45 , 20) ;
			printf ("%10.2f %%" , Accuracy) ;
			gotoxy (45 , 21) ;
			printf ("%10.2f wpm" , Speed) ;
			gotoxy (45 , 22) ;
			printf ("%10d letters" , WrongInput) ;
			gotoxy (45 , 23) ;
			printf ("%10d letters" , *InputCount) ;
			gotoxy (x , y) ;
			delay (100) ;
		}
	}

	InputLetter = getch ();

	if (InputLetter == '`')
	{
		EndTrainWordMode() ;
		Count = 0 ;
	}
	else
	{
		if (Word[Count + 1] == 0)
		{
			EndofWord = TRUE ;
			Count = 0 ;
		}
		else
		{
			if (InputLetter == Word[Count] )
			{
				TrainOutputWord (CorrectInputCount , InputCount);
				cout<<InputLetter;
				Count++ ;
			}
			else
			{
				(*InputCount) ++ ;
			}
		}
	}
  }


//************************************************
//ends word training mode


  void EndTrainWordMode ()
  {

	ExitTrainUserInputWord = TRUE ;
	ExitTrainProcess = TRUE ;
  }


//************************************************

  void TrainOutputWord (int *CorrectInputCount , int *InputCount)
  {
	(*CorrectInputCount) ++ ;
	(*InputCount) ++ ;
  }

//************************************************

  void TrainCheckIfTyped (int *CorrectInputCount , int *InputCount)
  {
	if (*InputCount) //if the user has typed some letters
	{
		TrainReport (CorrectInputCount , InputCount) ;
	}
  }


//************************************************


  void TrainReport (int *CorrectInputCount , int *InputCount)
  {

	double Accuracy = (*CorrectInputCount) * 100 / (*InputCount) ;
	double Speed = (*CorrectInputCount / 5) / (TimeUsed / 60) ;
	int WrongInput = (*InputCount) - (*CorrectInputCount);
	clrscr () ;

	//Display the report

	gotoxy ( 20 , 8 ) ;
	printf ( "Time used       : %10.2f seconds per letter." , (float) TimeUsed / *CorrectInputCount) ;
	gotoxy ( 20 , 10 ) ;
	printf ( "Character Typed : %7d letters" , *InputCount) ;
	gotoxy ( 20 , 12 ) ;
	printf ( "WrongInput      : %7d letters" , WrongInput) ;
	gotoxy ( 20 , 14 ) ;
	printf ( "Accuracy        : %10.2f %%" , Accuracy) ;
	gotoxy ( 20 , 16 ) ;
	printf ( "Speed           : %10.2f wpm (words per minute)" ,Speed) ;
	gotoxy ( 20 , 25 ) ;
	cout<<"Press any key to exit";      //wait for the user to press
	getch();
  }


//------------------------------------------
// EXIT FUNCTIONS
//------------------------------------------


  void QuitConfirm ()

  {

	char QuitChoice ;
	clrscr () ;
	gotoxy (20 , 15) ;
	cout<<"Do you really want to LOG OUT? (y/n) ";
	//wait for the user to press y or n
	if ( (QuitChoice = getch ())== 'T' )
	{
		while ( (tolower(QuitChoice) != Y )&& ( tolower(QuitChoice) !=N))
		{
			clrscr () ;
			gotoxy (20 , 20) ;
			cout<<"Please press 'y' or 'n' only!";
			gotoxy (20 , 15) ;
			cout<<"Do you really want to LOG OUT? (y/n) : ";
			QuitChoice = getch () ;
		}
	}
	cout<<QuitChoice;
	if (tolower(QuitChoice) == Y) //if the user pressed y ,
	{
		//then exit the program
		EndBody () ;
	}
  }


//ends tutor mode

  void EndBody()
  {

	ExitProgram = TRUE ;

  }


//------------------------------------------------------
// LOGIN PAGE
//------------------------------------------------------


  void login_screen()
  {

	textbackground(BLACK);
	clrscr();
	textcolor(RED);
	box(1,1,79,49);
	textcolor(LIGHTBLUE);
	box(24,12,60,16);
	box(24,17,60,25);
	LOGIN login;
	char str[25];
	gotoxy(35,14);
	textcolor(LIGHTGREEN);
	cprintf("-----LOGIN-----");
	gotoxy(27,20);
	textcolor(YELLOW);
	cprintf("User_ID  :");
	gotoxy(27,23);
	cprintf("Password :");
	gotoxy(37,20);
	gets(str);

	if(usercheck(login,str)) //FUNCTION.CPP*
	{
		gotoxy(37,23);
		if(login.check_pass()==1)
		{
			//correct password
			t_main(login);
		}
		else
		{
			cout<<"User_ld and Password do not match!!\7";
			return;
		}
	}
	else
	{
		gotoxy(30,30);
		cout<<"User_Id does not exists\7";
		getch();
	}
  }

//-------------------------------------------
//NEW USER PAGE
//-------------------------------------------

  void new_user_screen()
  {

	clrscr();
	LOGIN login;
	char str[25];
	textcolor(LIGHTRED);
	box(1,1,79,50);
	textcolor(LIGHTBLUE);
	box(25,13,52,17);
	box(25,23,52,29);
	gotoxy(30,15);
	textcolor(LIGHTGREEN);
	cprintf("-----NEW USER-----");
	textcolor(WHITE+BLINK);
	gotoxy(27,20);
	cprintf("Enter user details below ");
	gotoxy(27,25);
	textcolor(YELLOW);
	cprintf("USER_ID  : ");
	gets(str);

	if(!(usercheck(login,str)))
	{
		login.set_login_name(str);
		gotoxy(27,27);
		cprintf("PASSWORD : ");
		login.set_passwd();
		write_to_file(login);
	}
	else
	{
		gotoxy(30,35);
		cout<<"User_Id already exists\7";
		getch();
	}
  }


//-----------------------------------
// WELCOME SCREEN
//-----------------------------------


  void welcome_screen()
  {

	clrscr();
	textbackground(BLUE);
	for(int i=25;i<55;i++)
	{
		for(int j=20;j<30;++j)
		{
			gotoxy(i,j);
			cprintf(" ");
		}
	}

	gotoxy(33,25);
	textcolor(WHITE+BLINK);
	cprintf("TYPING TUTOR\r\n");
	textbackground(BLACK);
	textcolor(LIGHTBLUE);
	box(1,1,79,50);
	textcolor(LIGHTRED);
	box(24,19,54,30);
	textcolor(LIGHTGREEN);
	box(29,32,49,42);
	gotoxy(30,33);
	textcolor(WHITE);
	cprintf("Made By :");
	gotoxy(30,35);
	textcolor(LIGHTRED);
	cprintf("E.Rohith");
	gotoxy(30,37);
	cprintf("S.Sankaran");
	gotoxy(30,39);
	cprintf("S.Sitharthan");
	gotoxy(30,41);
	cprintf("Sajeet Prasad Sah");
	textcolor(WHITE);
	gotoxy(1,1);
	getch();
  }


//------------------------------------------
//INSTRUCTIONS PAGE
//------------------------------------------


  void instruct()
  {

	clrscr();
	gotoxy(27,5);
	textcolor(LIGHTBLUE);
	cprintf("  -----INSTRUCTIONS-----");
	gotoxy(10,11);
	textcolor(YELLOW);
	cprintf(" *  `Touch typing' is a technique of typing quickly and");
	gotoxy(10,14);
	cprintf("    accurately without looking at the keyboard ");
	gotoxy(10,18);
	textcolor(LIGHTGREEN);
	cprintf(" *  Position your fingers on the middle row fo your keyboard -");
	gotoxy(10,21);
	cprintf("    left hand ( A S D F ) , right hand ( J K L ; )");
	gotoxy(10,25);
	textcolor(YELLOW);
	cprintf(" *  Starting with your left hand, placeyour little finger on");
	gotoxy(10,28);
	cprintf("    key A, ring finger on S, middle finger on F, let your thumb");
	gotoxy(10,31);
	cprintf("    rest on Space bar.");
	gotoxy(10,35);
	textcolor(LIGHTGREEN);
	cprintf(" *  With your right hand place your index finger on J, middle");
	gotoxy(10,38);
	cprintf("    finger on K, ring finger on L and your little finger on the");
	gotoxy(10,41);
	cprintf("    next key");
	gotoxy(10,45);
	textcolor(YELLOW);
	cprintf(" *  Press Enter with little finger of your right hand");
	textcolor(BLUE);
	box(1,1,79,50);
	textcolor(LIGHTRED);
	box(8,3,74,7);
	textcolor(LIGHTRED);
	box(8,8,74,47);
	getch();
  }


//-------------------------------------------
//ABOUT THE PROGRAMMER
//-------------------------------------------


  void aboutus()
  {

	clrscr();
	textcolor(YELLOW);
	box(1,1,79,50);
	textcolor(BLUE);
	box(7,18,74,28);
	box(7,12,74,16);
	gotoxy(27,14);
	textcolor(YELLOW);
	cprintf("-----ABOUT PROGRAMMERS-----");
	gotoxy(9,20);
	textcolor(LIGHTRED);
	cprintf("Names  :");
	textcolor(LIGHTGREEN+BLINK);
	cprintf(" E.Rohith , S.Sankaran , S.Sitharthan & Sajeet Prasad Sah") ;
	textcolor(LIGHTRED);
	gotoxy(9,23) ;
	cprintf("Class  : 12th");
	gotoxy(9,26) ;
	cprintf("School : Kola Perumal Chetty Vaishnav Senior Secondary School");
	getch();
  }

//----------------------------------------------------------------
//  MAIN FUNCTION  I:
//----------------------------------------------------------------


  void main()
  {

	char choice;
	welcome_screen();
	do
	{

		textbackground(BLACK);
		clrscr();
		textcolor(BLUE);
		box(1,1,79,50);
		box(31,13,48,17);
		box(31,19,48,31);
		gotoxy(33,15);
		textcolor(LIGHTGREEN);
		cprintf("-----MENU-----");
		textcolor(LIGHTRED);
		gotoxy(33,21);
		cprintf("1. Login");
		gotoxy(33,23);
		cprintf("2. New user");
		gotoxy(33,25);
		cprintf("3. Instructions");
		gotoxy(33,27);
		cprintf("4. About us");
		gotoxy(33,29);
		cprintf("5. Quit");
		gotoxy(30,34);
		textcolor(WHITE+BLINK);
		cprintf("Enter your choice :");
		textcolor(WHITE);
		choice=getch();

		switch(choice)
		{

			case '1': login_screen(); //second.cpp
				  break;
			case '2': new_user_screen(); //new_user.cpp
				  break;
			case '3': instruct();
				  break;
			case '4': aboutus();
				  break;
			case '5': welcome_screen();
				  exit(EXIT_SUCCESS);
				  break;
		}
	}while(choice!='5');
  }

