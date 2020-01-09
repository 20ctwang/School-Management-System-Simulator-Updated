// Chuting Wang functions project.cpp : Defines the entry point for the console application.
//
/*---------------------Chuting Wang Functions Project---------------------------*/
/*  This program uses funtions. Users would enter password corresponding to     */
/*  their identity to log in. Everything starts from guidance that all students */
/*  and teachers should create an account in guidance giving them a unique      */
/*  ID, which is teacher/student password to log in teacher/student system.     */
/*																			    */
/*  Guidance:                                                                   */
/*  Teacher management can have: teacher added, edited, deleted and viewed.     */
/*  One teacher can select one major course only and become supply              */
/*  teacher for maximum 6 kinds of courses that are different from major        */
/*  Courses.                                                                    */
/*                                                                              */
/*  Student management can have:                                                */
/*  student added, edited, deleted and viewed. One student can select maximum   */
/*  6 different kinds of courses and are required to pay for them. Students     */
/*  can determine to either pay in guidance or pay when have their own account  */
/*  logged in.                                                                  */
/*                                                                              */
/*  Teacher: entering the corresponding teacher ID to log in teacher account,   */
/*  teacher can enter their personal info and view in both guidance and their   */
/*  own account, then teacher can add assignment for their major course only    */
/*  and if there are two teachers adding assignments to the same courses, then  */
/*  student choosing this course would have two assignments to work on.         */
/*                                                                              */
/*  Student: entering the corresponding student ID to log in student account    */
/*  student can enter their personal info and view in both guidance and their   */
/*  own account, then student can view the assignment of the courses they select*/
/*  in guidance before,and then if the student does not pay the courses in      */
/*  guidance before, they can also pay the course here.                         */
/*                                                                              */
/*                                                                              */
/*                   PROGRAM ID:Chuting Wang Functions Project                  */ 
/*                   PROGRAMMER:Chuting Wang                                    */
/*                   DATE:May 28th, 2018                                        */ 
/*                                                   						    */
/*------------------------------------------------------------------------------*/
/*----------------------------PREPORCESSING DIRECTIVES-------------------------*/
#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

/*-------------------------------MAINLINE CONTROL------------------------------*/
int main (void)
{
/*------------------------------------TITLE------------------------------------*/

	system("TITLE Chuting Wang functions project");

/*------------------------DECLARE FUNCTIONS PROTOTYPES-------------------------*/
    /*start and end*/
    void  printIntro                         (void);                   //print greeting to screen   
	int   logIn                              (int);                    //log in
	void  printEnding                        (void);                   //print ending to screen
	int   backToPreviousMenu                 (int);                    //return to previous page
	void  loading                            (void);                   //animation of loading 
	                                                                      
	/*Guidance*/                                                           
	int   guidanceMenu                       (void);                   											                	  //guidance main menu
	int   guidanceTeacherManagementMenu      (void);                   												                 //teacher management menu
	int   guidanceStudentManagementMenu      (void);                   							                                     //student management menu
	int   loadTeacherBasicInfo               (char[30][100],int[30][6],int,int[30],int[30]);                                         //enter teacher name and course selection
	void  printTeacherBasicInfo              (char[30][100],int[30][6],int,int[30],int[30][10],int[30][11],char[30][100]);           //view teacher all infomation
	void  deleteTeacher                      (char[30][100],int[30],int[30]);                                                        //delete teacher 
	void  editTeacher                        (char[30][100],int[30],int[30],int[30][6]);                                             //edit teacher
	int   loadStudentBasicInfo               (char[120][100],int[120][7],int[120],int,int[120],char[120][5]);                        //enter student name and select course  
	void  editStudent                        (char[120][100],int[120],int[120][7],char[120][5],int[120]);                            //edit student   
	void  deleteStudent                      (char[120][100],int[120]);                                                              //delete student 
	void  printStudentBasicInfo              (char[120][100],int[120],int[120][7],char[120][5],int[120][10],int[120][11],int[120][11],char[120][100]);	     //view student all infomation 
	  
	/*Teacher*/
	int   teacherLogIn                       (char[30][100],int[30],int);                           	                             //teacher log in
	int   teacherMenu                        (void);                                                								//teacher main menu
	void  loadTeacherDetailedInfo            (char[30][100],int[30][11],char[30][100],int[30][10],int); 							//enter/edit teacher infomation 
	void  printTeacherDetailedInfo           (char[30][100],int[30][11],char[30][100],int[30][10],int); 							//view teacher infomation
	void  teacherAddAssignment               (char[30][100],int,int[30],int[30][6],char[30][200],char[30][10]);    					//teacher add assignment
	
	/*Student*/
	int   studentLogIn                       (char[120][100],int[120],int);                          							 	//student log in
	int   studentMenu                        (void);    																		   //student main menu
	void  loadStudentDetailedInfo            (char[120][100],int[120][11],char[120][100],int[120][10],int,int[120][11]);          //enter/edit student infomation
	void  printStudentDetailedInfo           (char[120][100],int[120][11],char[120][100],int[120][10],int,int[120][11]);          //view student infomation
	void  studentViewAssignment              (char[120][100],int,int[120][7],int[30],char[30][200],char [30][10]);               //student view assignment
	void  studentPayCourse                   (char[120][100],int[120][7],int,char[120][5],int[120]);                             //student pay the course
/*-----------------------------DECLARE LOCAL VARIABLES-------------------------*/
	/*log in*/
	int   position=0;                            //determine user's identity
	
	/*Guidance*/
	int   guidanceTeacherManagementMenuChoice=0;//teacher management choice
	int   guidanceStudentManagementMenuChoice=0;//student management choice
	int   guidanceMenuChoice=0;                 //guidance main menu choice
	char  teacherName[30][100];                 //teacher name
	char  studentName[120][100];                //student name
	int   teacherCourse[30][6] = {0};           //teacher supply courses
	int   teacherMajorCourse[30] = {0};         //teacher major courses
	int   studentCourse[120][7] = {0};          //student courses
	int   teacherId[30];                        //teacher ID
	int   teacherID=0;                          //total number of teachers
	int   studentId[120];                       //student ID 
	int   studentID=0;                          //total number of students
	int   studentPay[120]={0};                  //money student required to pay
	char  pay[120][5];                          //determine student pay the course or not
	                                              
	/*Teacher*/                                   
	int   teacherMenuChoice=0;                   //teacher main menu choice
	int   teacherLogInNumber=0;                 //teacher ID teacher input to log in
	int   teacherContact[30][11]={0};               //teacher contact number
	char  teacherEmailAddress[30][100];         //teacher email address
	int   teacherBirthday[30][10]={0};              //teacher date of birth
	char  assignment[30][200];                  //teacher course assignment
	char  assignmentSituation[30][10];          //determine teacher entered assignment or not
	                                              
	/*Student*/                                   
	int   studentMenuChoice=0;                   //student main menu choice
	int   studentLogInNumber=0;                  //student ID student input to log in
	int   studentContact[120][11]={0};            //student contact number
	int   studentEmergencyContact[120][11]={0};   //student emergency contact number
	char  studentEmailAddress[120][100];        //student email address
	int   studentBirthday[120][10]={0};           //student date of birth
	                                              
	/*loop*/		                                    
	int   flag=0; 	                            //determine return or exit 
	int   row;                                  //for loop
                                                 
/*set screen size*/                              
	HWND foregroundWindow = GetForegroundWindow();   
/*set color*/
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);  
	WORD wOldColorAttrs;                                                                                               
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                                                               
	GetConsoleScreenBufferInfo(h1, &csbiInfo);                                                                                       
	wOldColorAttrs = csbiInfo.wAttributes;
                                                 
	for(row=0;row<30;row++)       //set initial value to teacher variables                  
	{                                               
		strcpy(teacherName[row],"N/A");                
		teacherId[row]=row;    
		strcpy(assignmentSituation[row],"N/A");
		strcpy(assignment[row],"N/A");    
		strcpy(teacherEmailAddress[row],"N/A");
	}                                               
	for(row=0;row<120;row++)         //set initial value to student variables               
	{     
		strcpy(studentName[row],"N/A");                                             
		studentId[row]=row;    
		strcpy(studentEmailAddress[row],"N/A");                          
	}                                                 
/*-----------------------------FUNCTION CALLS------------------------------*/                                 
    system ("color F0"); //background and foreground colour
	printIntro();        //introduction
	ShowWindow(foregroundWindow, SW_MAXIMIZE); //full screen  
	system("color 0D");//background and foreground colour
	loading(); //animation of loading                                  
	do                                                
	{   
		system("color D");    //foreground colour                                          
		position=logIn(position);  //log in		                     
		if(position == 1)                                
		{                                                
			do                                              
			{                                                 
				guidanceMenuChoice = guidanceMenu();   //guidance main menu          
				switch(guidanceMenuChoice)                       
				{                                                
					case 1:   //teacher management                                      
					do                                              
					{                                               
						guidanceTeacherManagementMenuChoice=guidanceTeacherManagementMenu();  //guidance teacher management menu
						switch(guidanceTeacherManagementMenuChoice)    
						{                                              
							case 1://add teacher                 
							teacherID = loadTeacherBasicInfo(teacherName,teacherCourse,teacherID,teacherMajorCourse,teacherId);
							flag=backToPreviousMenu(flag);
							break;
							
							case 2: //edit teacher info
							editTeacher(teacherName,teacherMajorCourse,teacherId,teacherCourse);
							flag=backToPreviousMenu(flag);
							break;
							
							case 3: //delete teacher
							deleteTeacher(teacherName,teacherMajorCourse,teacherId);
							flag=backToPreviousMenu(flag);
							break;
							
							case 4://view teacher info
							printTeacherBasicInfo(teacherName,teacherCourse,teacherID,teacherMajorCourse,teacherBirthday,teacherContact,teacherEmailAddress);
							flag=backToPreviousMenu(flag);
							break;
							
							case 5://return to guidance menu
							flag=3;
							break;
							
							case 6: //exit
							flag=7;
							break;
							
							default:
							flag=2;
							break;
						}
					}while(flag<3);
					break; 
					case 2://student management 
					do
					{
						guidanceStudentManagementMenuChoice=guidanceStudentManagementMenu();  //guidance student management menu
						switch(guidanceStudentManagementMenuChoice)
						{
							case 1: //add student
							studentID=loadStudentBasicInfo(studentName,studentCourse,studentId,studentID,studentPay,pay);
							flag=backToPreviousMenu(flag);
							break;
							
							case 2: //edit student
							editStudent(studentName,studentId,studentCourse,pay,studentPay);
							flag=backToPreviousMenu(flag);
							break;
							
							case 3: //delete student
							deleteStudent(studentName,studentId);
							flag=backToPreviousMenu(flag);
							break;
							
							case 4: //view student
							printStudentBasicInfo(studentName,studentId,studentCourse,pay,studentBirthday,studentContact,studentEmergencyContact,studentEmailAddress);
							flag=backToPreviousMenu(flag);
							break;
							
							case 5://return to guidance menu							
							flag=3;
							break;
							
							case 6: //exit
							flag=7;
							break;
							
							default:
							flag=2;
							break;						
						}
					}while(flag<3);
					break;
					
					case 3://return to log in page
					flag=6;
					break;
					
					case 4://exit 
					flag=7;
					break;
					
					default:
					flag=3;
					break;
				}
			}while(flag<4);
		}
		else if(position == 2) //teacher 
		{
			teacherLogInNumber=teacherLogIn(teacherName,teacherId,teacherID);//teacher log in 
			if(teacherLogInNumber==0)
			flag=3;
			else
			{
				do
				{
					teacherMenuChoice = teacherMenu(); //teacher menu
					switch(teacherMenuChoice)
					{
						case 1:
						loadTeacherDetailedInfo(teacherName,teacherContact,teacherEmailAddress,teacherBirthday,teacherLogInNumber);  //teacher enter personal info
						flag=backToPreviousMenu(flag);
						break;
						
						case 2:
						printTeacherDetailedInfo(teacherName,teacherContact,teacherEmailAddress,teacherBirthday,teacherLogInNumber);  //view teacher personal info
						flag=backToPreviousMenu(flag);
						break;
						
						case 3:
						teacherAddAssignment(teacherName,teacherLogInNumber,teacherMajorCourse,teacherCourse,assignment,assignmentSituation); //teacher add assignment to major course
						flag=backToPreviousMenu(flag);
						break;
						
						case 4:
						flag=3;
						break;
						
						case 5:
						flag=7;
						break;
						
						default:
						flag=2;
						break;
					}
				}while(flag<3);
			}
			
		}
		else if(position == 3)//student
		{
			studentLogInNumber=studentLogIn(studentName,studentId,studentID);  //student log in
			if(studentLogInNumber==0)
			flag=3;
			else
			{
				do
				{
					studentMenuChoice = studentMenu();  //student menu
					switch(studentMenuChoice)
					{
						case 1:
						loadStudentDetailedInfo(studentName,studentContact,studentEmailAddress,studentBirthday,studentLogInNumber,studentEmergencyContact);//student enter personal info
						flag=backToPreviousMenu(flag);
						break;
						
						case 2:
						printStudentDetailedInfo(studentName,studentContact,studentEmailAddress,studentBirthday,studentLogInNumber,studentEmergencyContact);  //student view personal info
						flag=backToPreviousMenu(flag);
						break;
						
						case 3:
						studentViewAssignment(studentName,studentLogInNumber,studentCourse,teacherMajorCourse,assignment,assignmentSituation); //student view assignment 
						flag=backToPreviousMenu(flag);
						break;
						
						case 4:
						studentPayCourse(studentName,studentCourse,studentLogInNumber,pay,studentPay);//student pay courses
						flag=backToPreviousMenu(flag);
						break;
						
						case 5:
						flag=3;
						break;
						
						case 6:
						flag=7;
						break;
						
						default:
						flag=2;
						break;
					}
				}while(flag<3);
			}
		}
		else
		printEnding(); //print ending to screen
	}while(flag<7);

	while(flag==7)
	{
		printEnding();//print ending to screen
		flag++;
	}
	getch(); //hold the screen
	return 0;
} //end main
/*------------------------------FUNCTION DEFINITION-----------------------------------------*/
/*----Start and end------*/
/*program intro*/
void printIntro (void)
{
	printf("\n\n\t\t\t================================================================");
	printf("\n\t\t\t|                                                              |");											
	printf("\n\t\t\t|                THE MATH SCHOOL MANAGEMENT SYSTEM             |");		
	printf("\n\t\t\t|                       By: CHUTING WANG                       |");		
	printf("\n\t\t\t|                                                              |");		
	printf("\n\t\t\t================================================================\n\n"); 
	printf("\n\t\t                        Welcome to THE MATH SCHOOL MANAGEMENT!\n\n");
	printf("\n\t\t           All teachers and students should create an account in guidance first!");
	printf("\n\t\t  All users can manage their personal infomation and course selection in this system!!\n\n");
	printf("\n\t\t                           Press <ENTER> and START!");
	getch();   //hold the screen
	system("cls");  //clear screen
	return;
}
/*users log in*/
int logIn (int position)
{
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE); 
	//declare local variables
	int flag;
	int intLetter=0, keyNum=0;	                    //password letter as integer
	char letter;			                        //input letter key (password)
	char password[20],maskPassword[20];	            //mask password
	int mainMenu;                                  //determine user's identity   
	char userName[30];                             //username
	
	printf("Password:");
	printf("\nGuidance: guidance");
	printf("\nTeacher: teacher");
	printf("\nStudent: student");
	printf("\n\n\n\n");
	SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\tMMMMMMMM               MMMMMMMM               AAA         TTTTTTTTTTTTTTTTTTTTTTTHHHHHHHHH     HHHHHHHHH");	
	printf("\n\t\t\tM:::::::M             M:::::::M              A:::A        T:::::::::::::::::::::TH:::::::H     H:::::::H");
	printf("\n\t\t\tM::::::::M           M::::::::M             A:::::A       T:::::::::::::::::::::TH:::::::H     H:::::::H");
	printf("\n\t\t\tM:::::::::M         M:::::::::M            A:::::::A      T:::::TT:::::::TT:::::THH::::::H     H::::::HH");
	printf("\n\t\t\tM::::::::::M       M::::::::::M           A:::::::::A     TTTTTT  T:::::T  TTTTTT  H:::::H     H:::::H  ");
	printf("\n\t\t\tM:::::::::::M     M:::::::::::M          A:::::A:::::A            T:::::T          H:::::H     H:::::H  ");
	printf("\n\t\t\tM:::::::M::::M   M::::M:::::::M         A:::::A A:::::A           T:::::T          H::::::HHHHH::::::H  ");
	printf("\n\t\t\tM::::::M M::::M M::::M M::::::M        A:::::A   A:::::A          T:::::T          H:::::::::::::::::H  ");
	printf("\n\t\t\tM::::::M  M::::M::::M  M::::::M       A:::::A     A:::::A         T:::::T          H:::::::::::::::::H  ");
	printf("\n\t\t\tM::::::M   M:::::::M   M::::::M      A:::::AAAAAAAAA:::::A        T:::::T          H::::::HHHHH::::::H  ");
	printf("\n\t\t\tM::::::M    M:::::M    M::::::M     A:::::::::::::::::::::A       T:::::T          H:::::H     H:::::H  ");
	printf("\n\t\t\tM::::::M     MMMMM     M::::::M    A:::::AAAAAAAAAAAAA:::::A      T:::::T          H:::::H     H:::::H  ");
	printf("\n\t\t\tM::::::M               M::::::M   A:::::A             A:::::A   TT:::::::TT      HH::::::H     H::::::HH");
	printf("\n\t\t\tM::::::M               M::::::M  A:::::A               A:::::A  T:::::::::T      H:::::::H     H:::::::H");
	printf("\n\t\t\tM::::::M               M::::::M A:::::A                 A:::::A T:::::::::T      H:::::::H     H:::::::H");
	printf("\n\t\t\tMMMMMMMM               MMMMMMMMAAAAAAA                   AAAAAAATTTTTTTTTTT      HHHHHHHHH     HHHHHHHHH");
                                                
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\n\n\n\n\t\t\t\t\t\t\tUSERNAME:");  //input username               
	scanf("%s",&userName);
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\tPASSWORD:");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	do
	{
		keyNum=0;
		maskPassword[0]=0;			//set to not length
		do
		{	
			SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour			
			system("cls");			//clear screen for password typing
			printf("Password:");
			printf("\nGuidance: guidance");
			printf("\nTeacher: teacher");
			printf("\nStudent: student");
			printf("\n\n\n\n");
			SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour
			printf("\n\t\t\tMMMMMMMM               MMMMMMMM               AAA         TTTTTTTTTTTTTTTTTTTTTTTHHHHHHHHH     HHHHHHHHH");	
			printf("\n\t\t\tM:::::::M             M:::::::M              A:::A        T:::::::::::::::::::::TH:::::::H     H:::::::H");
			printf("\n\t\t\tM::::::::M           M::::::::M             A:::::A       T:::::::::::::::::::::TH:::::::H     H:::::::H");
			printf("\n\t\t\tM:::::::::M         M:::::::::M            A:::::::A      T:::::TT:::::::TT:::::THH::::::H     H::::::HH");
			printf("\n\t\t\tM::::::::::M       M::::::::::M           A:::::::::A     TTTTTT  T:::::T  TTTTTT  H:::::H     H:::::H  ");
			printf("\n\t\t\tM:::::::::::M     M:::::::::::M          A:::::A:::::A            T:::::T          H:::::H     H:::::H  ");
			printf("\n\t\t\tM:::::::M::::M   M::::M:::::::M         A:::::A A:::::A           T:::::T          H::::::HHHHH::::::H  ");
			printf("\n\t\t\tM::::::M M::::M M::::M M::::::M        A:::::A   A:::::A          T:::::T          H:::::::::::::::::H  ");
			printf("\n\t\t\tM::::::M  M::::M::::M  M::::::M       A:::::A     A:::::A         T:::::T          H:::::::::::::::::H  ");
			printf("\n\t\t\tM::::::M   M:::::::M   M::::::M      A:::::AAAAAAAAA:::::A        T:::::T          H::::::HHHHH::::::H  ");
			printf("\n\t\t\tM::::::M    M:::::M    M::::::M     A:::::::::::::::::::::A       T:::::T          H:::::H     H:::::H  ");
			printf("\n\t\t\tM::::::M     MMMMM     M::::::M    A:::::AAAAAAAAAAAAA:::::A      T:::::T          H:::::H     H:::::H  ");
			printf("\n\t\t\tM::::::M               M::::::M   A:::::A             A:::::A   TT:::::::TT      HH::::::H     H::::::HH");
			printf("\n\t\t\tM::::::M               M::::::M  A:::::A               A:::::A  T:::::::::T      H:::::::H     H:::::::H");
			printf("\n\t\t\tM::::::M               M::::::M A:::::A                 A:::::A T:::::::::T      H:::::::H     H:::::::H");
			printf("\n\t\t\tMMMMMMMM               MMMMMMMMAAAAAAA                   AAAAAAATTTTTTTTTTT      HHHHHHHHH     HHHHHHHHH");
			SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
			printf("\n\n\n\n\n\t\t\t\t\t\t\tUSERNAME:%s",userName); 
			printf("\n\n\t\t\t\t\t\t\tPASSWORD:"); //input password
			printf("%s",maskPassword);							
			fflush(stdin);
			letter=getch();		//get individual letters
			intLetter=letter;	//convert to integer for key handling
			if(keyNum<20)
			{
				if((intLetter!=13)&&(intLetter!=8))
				{//if not enter or backspace
					password[keyNum]=letter;		//add to password
					maskPassword[keyNum]='*';		//create mask of password
					maskPassword[keyNum+1]=0;		//create end of string null for mask
					keyNum++;						//go to next input letter
				}
			}
			if(intLetter==8)
			{								//if backspace
				if(keyNum>0) keyNum--;		//erase a letter from password
				maskPassword[keyNum]=0;		//end mask of password
			}

		}while(intLetter!=13);		//wait until enter
		password[keyNum]=0;			//create end of password string	

		do
		{
			SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour	
			printf("\n\n\t\t\t\t\tEnter the number corresponding to your choice.");
			SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
			printf("\n\n\t\t\t\t\t 1] Guidance  2] Teacher  3] Student  4] Exit");
			printf("\n\t\t\t\t\t                   choice:");  //prompt user select
			scanf("%d",&mainMenu);
			fflush(stdin);
			switch(mainMenu)
			{
				case 1:
				/*test password*/
				if(strcmp(password,"guidance")==0)  //string compare testing if password is 'guidance'
				{
					flag = 2;
					position=1;
				}
				else
				{
					printf("\n\n\t\t\tYou have entered an invalid password!");
					printf("\n\n\t\t\tPress <ENTER> to try again!");				
					getch();
					flag = 1;
				}
				break;
				case 2:
				/*test password*/
				if(strcmp(password,"teacher")==0)  //string compare testing if password is 'teacher'
				{
					flag = 2;
					position=2;
				}		
				else
				{
					printf("\n\n\t\t\tYou have entered an invalid password!");
					printf("\n\n\t\t\tPress <ENTER> to try again!");
					flag = 1;
					getch();
				}
				break;
				case 3:
				/*test password*/
				if(strcmp(password,"student")==0)  //string compare testing if password is 'student'
				{
					flag = 2;
					position=3;
				}		
				else
				{
					printf("\n\n\t\t\tYou have entered an invalid password!");
					printf("\n\n\t\t\tPress <ENTER> to try again!");
					flag = 1;
					getch();
				}
				break;
				
				case 4:
				flag = 2;
				position=4;
				break;
				
				default:
				system("cls");
				printf("\nYou have entered an invalid number!!");
				printf("\nPress <ENTER> to try again!");
				flag=0; 
				getch();
				system("cls");
				break;
			}
		}while (flag<1);
	}while(flag < 2);   //if flag < 2, retry password, others go next
	printf("\n\t\t\t\t\t   Press <ENTER> to Continue!!!!");
	getch();       // hold screen
	system("cls"); //clear screen
	return(position);
}
/*user exit*/
void printEnding (void)
{
	system("cls");
	printf("\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t\t     .-""""""-.       ");
	printf("\n\t\t\t\t\t\t   .'          '.     ");
	printf("\n\t\t\t\t\t\t  ,   O      O   ,    ");
	printf("\n\t\t\t\t\t\t :           `    :   ");
	printf("\n\t\t\t\t\t\t |                |   ");
	printf("\n\t\t\t\t\t\t :    .------.    :   ");
	printf("\n\t\t\t\t\t\t  ,  '        '  ,    ");
	printf("\n\t\t\t\t\t\t   '.          .'     ");
	printf("\n\t\t\t\t\t\t     '-......-'      ");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t888888b. Y88b   d88P 8888888888 ");
	printf("\n\t\t\t\t\t888   88b Y88b d88P  888        ");
	printf("\n\t\t\t\t\t888  .88P  Y88o88P   888        ");
	printf("\n\t\t\t\t\t8888888K.   Y888P    8888888    ");
	printf("\n\t\t\t\t\t888   Y88b   888     888        ");
	printf("\n\t\t\t\t\t888    888   888     888        ");
	printf("\n\t\t\t\t\t888   d88P   888     888        ");
	printf("\n\t\t\t\t\t8888888P     888     8888888888 ");

	return;
}
/*return to previous page*/
int backToPreviousMenu(int flag)
{
	char choice;  //determine exit or not
	do
	{
		printf("\n\n\t\t\t\tExit Program? Y/N:");
		scanf(" %c",&choice);
		fflush(stdin);
		if ((choice=='N')||(choice=='n'))
		{
			flag=2;
			system("cls");
		}
		else if ((choice=='Y')||(choice=='y'))
		flag = 7;
		else
		{
			system("cls");
			printf("\n\n\t\t\t\tSORRY!! You have entered an invalid letter!!");
			printf("\n\n\t\t\t\tPress <ENTER> to try again!!");
			flag=1;
			getch();
			system("cls");
		}
	}while(flag<2);
	return (flag);
}
/*animation of loading*/
void loading (void)
{
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE); 
	system("cls"); //clear screen
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t  ______       ");
	printf("\n\t\t\t\t\t /|_||_|`.__  ");
	printf("\n\t\t\t\t\t(   _    _ _| ");
	printf("\n\t\t\t\t\t=`-(_)--(_)-' "); 
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t=========================================================");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\tWe are almost there.");
	Sleep(150);     // stay on screen for 150 milliseconds
	system("cls");  //clear screen

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground color
	printf("\n\t\t\t\t\t                     ______       ");
	printf("\n\t\t\t\t\t                    /|_||_|`.__  ");
	printf("\n\t\t\t\t\t                   (   _    _ _| ");
	printf("\n\t\t\t\t\t                 ===`-(_)--(_)-' "); 
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t=========================================================");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\tWe are almost there..");
	Sleep(150);
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\n\t\t\t\t\t                     ______       ");
	printf("\n\t\t\t\t\t                    /|_||_|`.__  ");
	printf("\n\t\t\t\t\t                   (   _    _ _| ");
	printf("\n\t\t\t\t\t                 ===`-(_)--(_)-' "); 
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t=========================================================");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\tWe are almost there...");
	Sleep(150);
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\n\t\t\t\t\t                     ______       ");
	printf("\n\t\t\t\t\t                    /|_||_|`.__  ");
	printf("\n\t\t\t\t\t                   (   _    _ _| ");
	printf("\n\t\t\t\t\t                 ===`-(_)--(_)-' "); 
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t=========================================================");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\tWe are almost there.");
	Sleep(150);
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\n\t\t\t\t\t                                             ______       ");
	printf("\n\t\t\t\t\t                                            /|_||_|`.__  ");
	printf("\n\t\t\t\t\t                                           (   _    _ _| ");
	printf("\n\t\t\t\t\t                                           =`-(_)--(_)-' "); 
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t=========================================================");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\tWe are almost there...");
	Sleep(150);
	system("cls");
	return;
}

/*-------Guidance---------*/
/*guidance menu*/
int guidanceMenu (void)
{
	 
	int guidanceMenuChoice=0;  //guidance main menu choice 
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour
	printf("\n\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t      __...--~~~~~-._   _.-~~~~~--...__       ");
	printf("\n\t\t\t\t\t    ,,               `,'               ,,     ");
	printf("\n\t\t\t\t\t   ,,    chuting      ,                 ,,    ");
	printf("\n\t\t\t\t\t  ,,__...--~~~~~~-._  ,  _.-~~~~~~--...__,,   ");
	printf("\n\t\t\t\t\t ,,__.....----~~~~._, , ,_.~~~~----.....__,,  ");
	printf("\n\t\t\t\t\t====================,,,,,==================== ");
	printf("\n\t\t\t\t\t                    `---`                     ");
	printf("\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t        ||*********GUIDANCE*********||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||* 1] Teacher Management  *||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||* 2] Student Management  *||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||* 3] Log in Page         *||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||* 4] Exit                *||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||**************************||");
	printf("\n");
	printf("\n\t\t\t\t\t                   choice:");
	
	scanf("%d",&guidanceMenuChoice);
	system("cls");
	return(guidanceMenuChoice);
}

/*guidance teacher management menu*/
int guidanceTeacherManagementMenu (void)
{
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);  
	int guidanceTeacherManagementMenuChoice=0;  //guidance teacher management choice
	SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour
	printf("\n\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t      __...--~~~~~-._   _.-~~~~~--...__       ");
	printf("\n\t\t\t\t\t    ,,               `,'               ,,     ");
	printf("\n\t\t\t\t\t   ,,    chuting      ,                 ,,    ");
	printf("\n\t\t\t\t\t  ,,__...--~~~~~~-._  ,  _.-~~~~~~--...__,,   ");
	printf("\n\t\t\t\t\t ,,__.....----~~~~._, , ,_.~~~~----.....__,,  ");
	printf("\n\t\t\t\t\t====================,,,,,==================== ");
	printf("\n\t\t\t\t\t                    `---`                     ");
	printf("\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t          ||*******TEACHER*******|| ");
	printf("\n\t\t\t\t\t          ||*                   *||");
	printf("\n\t\t\t\t\t          ||* 1] Add Teacher    *||");
	printf("\n\t\t\t\t\t          ||*                   *||");
	printf("\n\t\t\t\t\t          ||* 2] Edit Teacher   *||");
	printf("\n\t\t\t\t\t          ||*                   *||");
	printf("\n\t\t\t\t\t          ||* 3] Delete Teacher *||");
	printf("\n\t\t\t\t\t          ||*                   *||");
	printf("\n\t\t\t\t\t          ||* 4] View Teacher   *||");
	printf("\n\t\t\t\t\t          ||*                   *||");
	printf("\n\t\t\t\t\t          ||* 5] Guidance Menu  *||");
	printf("\n\t\t\t\t\t          ||*                   *||");
	printf("\n\t\t\t\t\t          ||* 6] Exit           *||");
	printf("\n\t\t\t\t\t          ||*                   *||");
	printf("\n\t\t\t\t\t          ||*********************||");
	printf("\n");
	printf("\n\t\t\t\t\t                  choice:");
	scanf("%d",&guidanceTeacherManagementMenuChoice);
	fflush(stdin);
	system("cls");
	return (guidanceTeacherManagementMenuChoice);
}
/*add teacher*/
int loadTeacherBasicInfo(char teacherName[30][100],int teacherCourse[30][6],int teacherID,int teacherMajorCourse[30],int teacherId[30])
{
	int row;  //for loop
	int col;  //for loop
	int flag; //do-while
	char choice; //determine continue or return
	int supplyCourseNum; //order of supply course
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);  	
	do
	{	
		system("cls");  //clear screen
		SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
		printf("\n\t\t\t\t||**********COURSES SELECTION**********||");
		printf("\n\t\t\t\t||*                                   *||");
		printf("\n\t\t\t\t||*  1] Foundations of Mathematics    *|| ");
		printf("\n\t\t\t\t||*                                   *||");
		printf("\n\t\t\t\t||*  2] Principles of Mathematics     *||");
		printf("\n\t\t\t\t||*                                   *||");
		printf("\n\t\t\t\t||*  3] Functions                     *||");
		printf("\n\t\t\t\t||*                                   *||");
		printf("\n\t\t\t\t||*  4] Advanced Functions            *||");
		printf("\n\t\t\t\t||*                                   *||");
		printf("\n\t\t\t\t||*  5] Data Management               *||");
		printf("\n\t\t\t\t||*                                   *||");
		printf("\n\t\t\t\t||*  6] Calculus                      *||");
		printf("\n\t\t\t\t||*                                   *||");
		printf("\n\t\t\t\t||*************************************||");
		SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour

		teacherID++;		
		printf("\n");
		printf("\n\t\t\t\t**********BASIC INFOMATION**********");
		printf("\n\n\t\t\t\tTeacher ID: %d",teacherId[teacherID]);
		printf("\n\n\t\t\t\tName:");
		scanf("%[^\n]",teacherName[teacherID]);
		fflush(stdin);	
		
		printf("\n\t\t\t\t**********COURSE SELECTION**********");
		printf("\n\n\t\t\t\tMajor Course:");
		scanf("%d",&teacherMajorCourse[teacherID]);
		fflush(stdin);
		
		do
		{
			printf("\n\t\t\t\tAdd supply course? Y/N: ");
			scanf("%c",&choice);
			fflush(stdin);
			
			if((choice=='y')||(choice=='Y'))
			{
				for(col=0;col<6;col++)
				{
					supplyCourseNum = col+1;
					printf("\n\t\t\t\tSupply Course %d:",supplyCourseNum);
					scanf("%d",&teacherCourse[teacherID][col]);
					fflush(stdin);
						
					do
					{
						printf("\t\t\t\tAdd another supply course? Y/N: ");
						scanf("%c",&choice);
						fflush(stdin);
						if((choice == 'y')||(choice == 'Y'))
						{
							flag = 2;
						}
						else if((choice == 'n')||(choice == 'N'))
						{
							flag = 2;
							col=6;
						}
						else 
						{
							flag = 1;
						}
					}while(flag<2);	
				}
			}
			else if((choice == 'n')||(choice == 'N'))
			flag=2;
			else
			flag=1;
		}while(flag<2);

		do
		{
			printf("\n\t\t\t\tAdd another teacher? Y/N: ");
			scanf("%c",&choice);
			fflush(stdin);
			if((choice == 'y')||(choice == 'Y'))
			{
				flag = 2;
				system("cls"); //clear screen
			}
			else if((choice == 'n')||(choice == 'N'))
			{
				flag = 3;
			}
			else 
			{
				flag = 1;
			}
		}while(flag<2);	
		
	}while(flag<3);
	return (teacherID);
}
/*view teacher*/
void printTeacherBasicInfo (char teacherName[30][100],int teacherCourse[30][6],int teacherID, int teacherMajorCourse[30],int teacherBirthday[30][10],int teacherContact[30][11],char teacherEmailAddress[30][100])
{

	int row=0;  //for loop
	int col=0;  //for loop
	int enterNum=0;  //user enter number
	int flag=0;  //do while
	char choice; //determine continue or return
	do
	{
		printf("Notice: '--' meaning nothing has been entered.");
		printf("\nOnly courses teacher supply can be repeated but must be different from major course.");
		printf("\n");
		printf("\n\t\t\t\t||********************COURSES********************||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*       Course Name               Course Code *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Foundations of Mathematics         001     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Principles of Mathematics          002     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Functions                          003     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Advanced Functions                 004     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Data Management                    005     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Calculus                           006     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||***********************************************||");
	
		printf("\n\n\t   Teacher \t     Teacher  \t     Major\tSupply  \tSupply  \tSupply  \tsupply   \tSupply  \tSupply");
		printf("\n\t     ID    \t       Name   \t    Course\tCourse 1\tCourse 2\tCourse 3\tCourse 4\tCourse 5\tCourse 6");
		for(row=1;row<teacherID+1;row++)
		{
			if(strcmp(teacherName[row],"N/A")!=0)
			{
				printf("\n");
				printf("\n\t       %d",row);
				printf("\t   %10s",teacherName[row]);
				if((teacherMajorCourse[row]<1)||(teacherMajorCourse[row]>6))
				printf("\t       ---");
				else
				printf("\t       00%d",teacherMajorCourse[row]);
				for (col=0;col<6;col++)
				{	
					if((teacherCourse[row][col]!=teacherMajorCourse[row])&&(teacherCourse[row][col]>0)&&(teacherCourse[row][col]<7))								
					printf("\t\t 00%d",teacherCourse[row][col]);					
					else
					printf("\t\t--");
				}
			}
			else
			{
				printf("");
			}
		}
		do
		{
			printf("\n\n\t\t\t\tView more Infomation? Y/N: ");
			scanf("%c",&choice);
			fflush(stdin);
			if((choice=='Y')||(choice=='y'))
			{
				do
				{
					printf("\n\n\t\t\tTeacher ID: ");
					scanf("%d",&enterNum);
					fflush(stdin);
					if((strcmp(teacherName[enterNum],"N/A")==0)||(enterNum<1)||(enterNum>120))
					{
						printf("\n\n\t\t\t\tInvalid ID!");
						printf("\n\n\t\t\t\tPress <ENTER> to retry!");
						getch();
						system("cls");
						flag=0;
					}
					else
					{
						system("cls");
						printf("\n\n\t\t\t\tID: %d",enterNum);
						printf("\n\n\t\t\t\tName: %s",teacherName[enterNum]);
						printf("\n\n\t\t\t\tDate of Birth: ");
						for(row=0;row<2;row++)
						{
							printf("%d",teacherBirthday[enterNum][row]);
						}
						printf("/");
						for(row=2;row<4;row++)
						{
							printf("%d",teacherBirthday[enterNum][row]);
						}
						printf("/");
						for(row=4;row<8;row++)
						{
							printf("%d",teacherBirthday[enterNum][row]);
						}
						printf("\n\n\t\t\t\tPhone Number:");
						for(row=0;row<3;row++)
						{
							printf("%d",teacherContact[enterNum][row]);
						}
						printf("-");
						for(row=3;row<6;row++)
						{
							printf("%d",teacherContact[enterNum][row]);
						}
						printf("-");
						for(row=6;row<10;row++)
						{
							printf("%d",teacherContact[enterNum][row]);
						}
						
						printf("\n\n\t\t\t\tEmail Address: %s",teacherEmailAddress[enterNum]);
						printf("\n\n\t\t\t\tPress <ENTER> to continue!");
						getch();
						system("cls");
						flag=2;						
					}
				}while(flag<1);
			}
			else if((choice=='N')||(choice=='n'))
			flag=3;
			else
			flag=1;
		}while(flag<2);		
	}while(flag<3);
	return;
}
/*edit teacher*/
void editTeacher (char teacherName[30][100],int teacherMajorCourse[30],int teacherId[30],int teacherCourse[30][6])
{
	int editNumber;         //user enter teacherID 
	int row;                //for loop
	int col;                //for loop
	char choice;            //choice of 'yes' or 'no'
	int flag;               //do while
	int supplyCourseNum;    //supply course order
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);  
	do
	{
		printf("\n");
		printf("\n\t\t\t\t||********************COURSES********************||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*       Course Name               Course Code *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Foundations of Mathematics         001     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Principles of Mathematics          002     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Functions                          003     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Advanced Functions                 004     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Data Management                    005     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Calculus                           006     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||***********************************************||");

		printf("\n\n\t\t\t\t   Teacher ID \t  Teacher Name \tMajor Course");
		for(row=1;row<30;row++)
		{			
			if(strcmp(teacherName[row],"N/A")!=0)
			{
				printf("\n");
				printf("\n\t\t\t\t   %d",teacherId[row]);
				printf("\t   %10s",teacherName[row]);
				if((teacherMajorCourse[row]<1)||(teacherMajorCourse[row]>6))
				printf("\t       ---");
				else
				printf("\t                    00%d",teacherMajorCourse[row]);
			}
			else
			{
				printf("");
			}
		}
		for(row=1;row<2;row++)
		{	
			printf("\n\t\t\t\t---------------------------------------------------");
			printf("\n\t\t\t\tEdit Teacher? Y/N: ");
			scanf("%c",&choice);
			fflush(stdin);
			
			if((choice=='Y')||(choice=='y'))
			{				
				printf("\n\t\t\t\tTeacher ID:");
				scanf("%d",&editNumber);
				fflush(stdin);
				
				if((editNumber>0)&&(editNumber<30))
				{
					system("cls");
					SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
					printf("\n\t\t\t\t||**********COURSES SELECTION**********||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  1] Foundations of Mathematics    *|| ");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  2] Principles of Mathematics     *||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  3] Functions                     *||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  4] Advanced Functions            *||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  5] Data Management               *||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  6] Calculus                      *||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*************************************||");
					SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
					
					printf("\n");
					printf("\n\t\t\t\t**********BASIC INFOMATION**********");
					printf("\n\n\t\t\t\tTeacher ID: %d",teacherId[editNumber]);
					printf("\n\n\t\t\t\tName:");
					scanf("%[^\n]",teacherName[editNumber]);
					fflush(stdin);	
					
					printf("\n\t\t\t\t**********COURSE SELECTION**********");
					printf("\n\n\t\t\t\tMajor Course:");
					scanf("%d",&teacherMajorCourse[editNumber]);
					fflush(stdin);

					do
					{
						printf("\n\t\t\t\tAdd supply course? Y/N: ");
						scanf("%c",&choice);
						fflush(stdin);
						
						if((choice=='y')||(choice=='Y'))
						{
							for(col=0;col<6;col++)
							{
								supplyCourseNum = col+1;
								printf("\n\t\t\t\tSupply Course %d:",supplyCourseNum);
								scanf("%d",&teacherCourse[editNumber][col]);
								fflush(stdin);
									
								do
								{
									printf("\t\t\t\tAdd another supply course? Y/N: ");
									scanf("%c",&choice);
									fflush(stdin);
									if((choice == 'y')||(choice == 'Y'))
									{
										flag = 2;
									}
									else if((choice == 'n')||(choice == 'N'))
									{
										flag = 2;
										col=6;
									}
									else 
									{
										flag = 1;
									}
								}while(flag<2);	
							}
						}
						else if((choice == 'n')||(choice == 'N'))
						flag=2;
						else
						flag=1;
					}while(flag<2);
					flag=1;
					system("cls");
				}			
				else
				{
					flag=1;
					printf("\n\t\t\t\t Number Invalid!!!");
					printf("\n\t\t\t\t Press <ENTER> to try again!");
					getch();
					system("cls");
				}
			}
			else if((choice=='N')||(choice=='n'))
			flag=2;
			else
			{
				printf("\n\n\t\t\t\t Letter invalid!!!");
				printf("\n\t\t\t\t Press <ENTER> to try again!!!");
				flag=1;
				getch();
				system("cls");
			}
		}

	}while(flag<2);
	return;
}
/*delete teacher*/
void deleteTeacher (char teacherName[30][100],int teacherMajorCourse[30],int teacherId[30])
{
	int deleteNumber;  //id user enter to delete teacher
	int row;           //for loop
	int col;           //for loop
	char choice;	   //determine return or continue
	int flag;         //do while
	do
	{
		printf("\n");
		printf("\n\t\t\t\t||********************COURSES********************||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*       Course Name               Course Code *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Foundations of Mathematics         001     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Principles of Mathematics          002     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Functions                          003     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Advanced Functions                 004     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Data Management                    005     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Calculus                           006     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||***********************************************||");

		printf("\n\n\t\t\t\t   Teacher ID \t  Teacher Name  \t  Major Course");
		for(row=1;row<30;row++)
		{			
			if(strcmp(teacherName[row],"N/A")!=0)
			{
				printf("\n\t\t\t\t\t  %d",teacherId[row]);
				printf("\t   %10s",teacherName[row]);
				if((teacherMajorCourse[row]<1)||(teacherMajorCourse[row]>6))
				printf("\t       ---");
				else
				printf("\t       00%d",teacherMajorCourse[row]);			
			}
			else
			{
				printf("");
			}
		}
		for(row=1;row<2;row++)
		{	
			printf("\n\t\t\t\t------------------------------------------------");
			printf("\n\t\t\t\tDelete Teacher? Y/N: ");
			scanf("%c",&choice);
			fflush(stdin);
			
			if((choice=='Y')||(choice=='y'))
			{				
				printf("\n\t\t\t\tTeacher ID: ");
				scanf("%d",&deleteNumber);
				fflush(stdin);
				
				if((deleteNumber>0)&&(deleteNumber<30))
				{
					strcpy(teacherName[deleteNumber],"N/A");
					flag=1;
					system("cls");
				}			
				else
				{
					flag=1;
					printf("\n\t\t\t\t Number Invalid!!!");
					printf("\n\t\t\t\t Press <ENTER> to try again!");
					getch();
					system("cls");
				}
			}
			else if((choice=='N')||(choice=='n'))
			flag=2;
			else
			{
				printf("\n\n\t\t\t\t Letter invalid!!!");
				printf("\n\t\t\t\t Press <ENTER> to try again!!!");
				flag=1;
				getch();
				system("cls");
			}
		}
	}while(flag<2);
	return;
}
/*guidance student management menu*/
int guidanceStudentManagementMenu (void)
{
	int guidanceStudentManagementMenuChoice=0; //guidance student management menu 
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour
	printf("\n\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t      __...--~~~~~-._   _.-~~~~~--...__       ");
	printf("\n\t\t\t\t\t    ,,               `,'               ,,     ");
	printf("\n\t\t\t\t\t   ,,    chuting      ,                 ,,    ");
	printf("\n\t\t\t\t\t  ,,__...--~~~~~~-._  ,  _.-~~~~~~--...__,,   ");
	printf("\n\t\t\t\t\t ,,__.....----~~~~._, , ,_.~~~~----.....__,,  ");
	printf("\n\t\t\t\t\t====================,,,,,==================== ");
	printf("\n\t\t\t\t\t                    `---`                     ");
	printf("\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t           ||*******STUDENT*******|| ");
	printf("\n\t\t\t\t\t           ||*                   *||");
	printf("\n\t\t\t\t\t           ||* 1] Add Student    *||");
	printf("\n\t\t\t\t\t           ||*                   *||");
	printf("\n\t\t\t\t\t           ||* 2] Edit Student   *||");
	printf("\n\t\t\t\t\t           ||*                   *||");
	printf("\n\t\t\t\t\t           ||* 3] Delete Student *||");
	printf("\n\t\t\t\t\t           ||*                   *||");
	printf("\n\t\t\t\t\t           ||* 4] View Student   *||");
	printf("\n\t\t\t\t\t           ||*                   *||");
	printf("\n\t\t\t\t\t           ||* 5] Guidance Menu  *||");
	printf("\n\t\t\t\t\t           ||*                   *||");
	printf("\n\t\t\t\t\t           ||* 6] Exit           *||");
	printf("\n\t\t\t\t\t           ||*                   *||");
	printf("\n\t\t\t\t\t           ||*********************||");
	printf("\n");
	printf("\n\t\t\t\t\t                   choice:");
	scanf("%d",&guidanceStudentManagementMenuChoice);
	fflush(stdin);
	system("cls");
	return (guidanceStudentManagementMenuChoice);
}
/*add student*/
int loadStudentBasicInfo(char studentName[120][100],int studentCourse[120][7],int studentId[30],int studentID,int studentPay[120],char pay[120][5]) 
{
	int row;          //for loop
	int col=0;        //for loop
	int flag;         //do while
	char choice;      //determine continue or return
	int courseNum=0;  //Course number
	int creditCard;   //credit card user input
	int count;        //for loop
	int flag1=0;      //determine if user pay the course
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);  
	do
	{	
		system("cls");
		SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
		printf("\n\t\t\t\t||*******************COURSES SELECTION*******************||");
		printf("\n\t\t\t\t||*                                                     *||");
		printf("\n\t\t\t\t||*              Courses              Prices($/semester)*||");
		printf("\n\t\t\t\t||*                                                     *||");
		printf("\n\t\t\t\t||*  1] Foundations of Mathematics           1200       *||");
		printf("\n\t\t\t\t||*                                                     *||");
		printf("\n\t\t\t\t||*  2] Principles of Mathematics            1200       *||");
		printf("\n\t\t\t\t||*                                                     *||");
		printf("\n\t\t\t\t||*  3] Functions                            1200       *||");
		printf("\n\t\t\t\t||*                                                     *||");
		printf("\n\t\t\t\t||*  4] Advanced Functions                   1200       *||");
		printf("\n\t\t\t\t||*                                                     *||");
		printf("\n\t\t\t\t||*  5] Data Management                      1200       *||");
		printf("\n\t\t\t\t||*                                                     *||");
		printf("\n\t\t\t\t||*  6] Calculus                             1200       *||");
		printf("\n\t\t\t\t||*                                                     *||");
		printf("\n\t\t\t\t||*******************************************************||");
		SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour

		studentID++;		
		printf("\n");
		printf("\n\t\t\t\t**********BASIC INFOMATION**********");
		printf("\n\n\t\t\t\tStudent ID: %d",studentId[studentID]);
		printf("\n\n\t\t\t\tName:");
		scanf("%[^\n]",studentName[studentID]);
		fflush(stdin);	
		
		printf("\n\t\t\t\t**********COURSE SELECTION**********");	
		do
		{
			printf("\n\t\t\t\tAdd course? Y/N: ");
			scanf("%c",&choice);
			fflush(stdin);
			
			if((choice=='y')||(choice=='Y'))
			{
				do
				{					
					courseNum = col+1;
					col++;
					printf("\n\t\t\t\tCourse %d:",courseNum);
					scanf("%d",&studentCourse[studentID][col]);
					fflush(stdin);			
					do
					{
						if(courseNum<7)
						{
							printf("\t\t\t\tAdd another course? Y/N: ");
							scanf("%c",&choice);
							fflush(stdin);
							if((choice == 'y')||(choice == 'Y'))
							flag = 1;
							else if((choice == 'n')||(choice == 'N'))
							{
								flag = 1;
								flag1 = 1;
							}
							else 						
							flag = 0;
						}
					}while(flag<1);	
					for(count=1;count<col+1;count++)
					{
						if(studentCourse[studentID][col]==studentCourse[studentID][col-count])
						col--;
						if(flag1==1)
						{
							flag=2;
							courseNum = col;
							if(courseNum==0)
							flag1=1;
							else
							flag1=2;
						}
					}
				}while(flag<2);	
		
			}
			else if((choice == 'n')||(choice == 'N'))
			flag=2;
			else
			flag=1;
			
			while(flag1==2)
			{
				studentPay[studentID]=1200*courseNum;
				printf("\t\t\t\tTotal Price: $%d",studentPay[studentID]);
				do
				{			
					printf("\n\t\t\t\tPay now? Y/N");
					scanf("%c",&choice);
					fflush(stdin);
					if((choice=='y')||(choice=='Y'))
					{
						system("cls");	
						printf("\n\n\t\t\t\tTotal Price: $%d",studentPay[studentID]);			
						printf("\n\n\t\t\t\tCredit Card:");
						scanf("%d",&creditCard);
						fflush(stdin);
						printf("\t\t\t\tPress <ENTER> to pay!!");
						getch();
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||===                              ||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing.");
						Sleep(50);
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||   ===                           ||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing..");
						Sleep(50);
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||      ===                        ||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing..");
						Sleep(50);
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||         ===                     ||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing...");
						Sleep(50);
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||            ===                  ||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing...");
						Sleep(50);
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||               ===               ||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing.");
						Sleep(50);
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||                  ===            ||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing.");
						Sleep(50);
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||                     ===         ||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing..");
						Sleep(50);
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||                        ===      ||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing..");
						Sleep(50);
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||                           ===   ||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing...");
						Sleep(50);
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t||                              ===||");
						printf("\n\t\t\t\t||=================================||");
						printf("\n\t\t\t\t            Processing...");
						Sleep(50);
						system("cls");
						printf("\n\n\t\t\t\tTotal Price: $%d",studentPay[studentID]);
						printf("\n\n\t\t\t\t       Paid: $%d",studentPay[studentID]);
						printf("\n\n\t\t\t\tAll Price has been paied!!");
						printf("\n\t\t\t\tPress <ENTER> to continue!!!");
						getch();
						strcpy(pay[studentID],"yes");
						flag=2;
					}
					else if((choice == 'n')||(choice == 'N'))
					{
						strcpy(pay[studentID],"no");
						flag=2;
					}
					else
					flag=0;
				}while(flag<1);
				flag1=0;
			}
		}while(flag<2);//end of do-while
		do
		{
			printf("\n\t\t\t\tAdd another student? Y/N: ");
			scanf("%c",&choice);
			fflush(stdin);
			if((choice == 'y')||(choice == 'Y'))
			{
				flag = 2;
				col=0;
				system("cls"); //clear screen
			}
			else if((choice == 'n')||(choice == 'N'))
			{
				flag = 3;
			}
			else 
			{
				flag = 1;
			}
		}while(flag<2);	
		
	}while(flag<3);
	return(studentID);
}
/*edit student*/
void editStudent(char studentName[120][100], int studentId[120],int studentCourse[120][7],char pay[120][5],int studentPay[120])
{
	int editNumber;         //user enter studentID 
	int row;                //for loop
	int col=0;                //for loop
	char choice;            //choice of 'yes' or 'no'
	int flag;               //do while
	int courseNum;          //course order
	int flag1=0;            //determine if user pay the course
	int count=1;            //for loop
	int creditCard=0;       //credit card user input
	int count1=0;           //for loop
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);  
	do
	{
		col=0;
		printf("\n");
		printf("\n\t\t\t\t||********************COURSES********************||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*       Course Name               Course Code *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Foundations of Mathematics         001     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Principles of Mathematics          002     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Functions                          003     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Advanced Functions                 004     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Data Management                    005     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Calculus                           006     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||***********************************************||");

		printf("\n\n\t\t\t\t   Student ID \t  Student Name ");
		for(row=1;row<120;row++)
		{			
			if(strcmp(studentName[row],"N/A")!=0)
			{
				printf("\n");
				printf("\n\t\t\t\t   %d",studentId[row]);
				printf("\t   %10s",studentName[row]);
			}
			else
			{
				printf("");
			}
		}
		for(row=1;row<2;row++)
		{	
			printf("\n\t\t\t\t---------------------------------------------------");
			printf("\n\t\t\t\tEdit Student? Y/N: ");
			scanf("%c",&choice);
			fflush(stdin);
			
			if((choice=='Y')||(choice=='y'))
			{				
				printf("\n\t\t\t\tStudent ID:");
				scanf("%d",&editNumber);
				fflush(stdin);
				
				if((editNumber>0)&&(editNumber<120))
				{
					system("cls");
					SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
					printf("\n\t\t\t\t||**********COURSES SELECTION**********||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  1] Foundations of Mathematics    *|| ");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  2] Principles of Mathematics     *||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  3] Functions                     *||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  4] Advanced Functions            *||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  5] Data Management               *||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*  6] Calculus                      *||");
					printf("\n\t\t\t\t||*                                   *||");
					printf("\n\t\t\t\t||*************************************||");
					SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
					
					printf("\n");
					printf("\n\t\t\t\t**********BASIC INFOMATION**********");
					printf("\n\n\t\t\t\tStudent ID: %d",studentId[editNumber]);
					printf("\n\n\t\t\t\tName:");
					scanf("%[^\n]",studentName[editNumber]);
					fflush(stdin);	
					printf("\n\t\t\t\t**********COURSE SELECTION**********");

					do
					{
						printf("\n\t\t\t\tAdd course? Y/N: ");
						scanf("%c",&choice);
						fflush(stdin);
						
						if((choice=='y')||(choice=='Y'))
						{
							
							do
							{					
								courseNum = col+1;
								col++;
								printf("\n\t\t\t\tCourse %d:",courseNum);
								scanf("%d",&studentCourse[editNumber][col]);
								fflush(stdin);			
								do
								{
									if(courseNum<7)
									{
										printf("\t\t\t\tAdd another course? Y/N: ");
										scanf("%c",&choice);
										fflush(stdin);
										if((choice == 'y')||(choice == 'Y'))
										flag = 1;
										else if((choice == 'n')||(choice == 'N'))
										{
											flag = 1;
											flag1 = 1;
										}
										else 						
										flag = 0;
									}
								}while(flag<1);	
								for(count=1;count<col+1;count++)
								{
									if(studentCourse[editNumber][col]==studentCourse[editNumber][col-count])
									col--;
									if(flag1==1)
									{
										flag=2;
										courseNum = col;
										if(courseNum==0)
										flag1=1;
										else
										flag1=2;
									}
								}
							}while(flag<2);	
					
						}
						else if((choice == 'n')||(choice == 'N'))
						flag=2;
						else
						flag=1;
						
						while(flag1==2)
						{
							studentPay[editNumber]=1200*courseNum;
							printf("\t\t\t\tTotal Price: $%d",studentPay[editNumber]);
							do
							{			
								printf("\n\t\t\t\tPay now? Y/N");
								scanf("%c",&choice);
								fflush(stdin);
								if((choice=='y')||(choice=='Y'))
								{
									system("cls");	
									printf("\n\n\t\t\t\tTotal Price: $%d",studentPay[editNumber]);			
									printf("\n\n\t\t\t\tCredit Card:");
									scanf("%d",&creditCard);
									fflush(stdin);
									printf("\t\t\t\tPress <ENTER> to pay!!");
									getch();
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||===                              ||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing.");
									Sleep(50);
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||   ===                           ||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing..");
									Sleep(50);
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||      ===                        ||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing..");
									Sleep(50);
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||         ===                     ||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing...");
									Sleep(50);
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||            ===                  ||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing...");
									Sleep(50);
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||               ===               ||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing.");
									Sleep(50);
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||                  ===            ||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing.");
									Sleep(50);
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||                     ===         ||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing..");
									Sleep(50);
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||                        ===      ||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing..");
									Sleep(50);
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||                           ===   ||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing...");
									Sleep(50);
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t||                              ===||");
									printf("\n\t\t\t\t||=================================||");
									printf("\n\t\t\t\t            Processing...");
									Sleep(50);
									system("cls");
									printf("\n\n\t\t\t\tTotal Price: $%d",studentPay[editNumber]);
									printf("\n\n\t\t\t\t       Paid: $%d",studentPay[editNumber]);
									printf("\n\n\t\t\t\tAll Price has been paied!!");
									printf("\n\t\t\t\tPress <ENTER> to continue!!!");
									getch();
									strcpy(pay[editNumber],"yes");
									flag=2;
								}
								else if((choice == 'n')||(choice == 'N'))
								{
									strcpy(pay[editNumber],"no");
									flag=2;
								}
								else
								flag=0;
							}while(flag<1);
							flag1=0;
						}
					}while(flag<2);//end of do-while
					flag=1;
					system("cls");
				}			
				else
				{
					flag=1;
					printf("\n\t\t\t\t Number Invalid!!!");
					printf("\n\t\t\t\t Press <ENTER> to try again!");
					getch();
					system("cls");
				}
			}
			else if((choice=='N')||(choice=='n'))
			flag=2;
			else
			{
				printf("\n\n\t\t\t\t Letter invalid!!!");
				printf("\n\t\t\t\t Press <ENTER> to try again!!!");
				flag=1;
				getch();
				system("cls");
			}
		}

	}while(flag<2);
	return;
}
/*delete student*/
void deleteStudent (char studentName[120][100],int studentId[120])
{
	int deleteNumber;    //id user enter to delete the corresponding student
	int row;             //for loop
	int col;             //for loop
	char choice;	     //determine if user continue or return
	int flag;            //do while
	do
	{
		printf("\n\n\n\n\n\n");
		printf("\n\n\t\t\t\t   Student ID \t  Student Name");
		for(row=1;row<120;row++)
		{			
			if(strcmp(studentName[row],"N/A")!=0)
			{
				printf("\n\t\t\t\t\t   %d",studentId[row]);
				printf("\t   %10s",studentName[row]);			
			}
			else
			{
				printf("");
			}
		}
		for(row=1;row<2;row++)
		{	
			printf("\n\t\t\t\t------------------------------------------------");
			printf("\n\t\t\t\tDelete Student? Y/N: ");
			scanf("%c",&choice);
			fflush(stdin);
			
			if((choice=='Y')||(choice=='y'))
			{				
				printf("\n\t\t\t\tStudent ID: ");
				scanf("%d",&deleteNumber);
				fflush(stdin);
				
				if((deleteNumber>0)&&(deleteNumber<30))
				{
					strcpy(studentName[deleteNumber],"N/A");
					flag=1;
					system("cls");
				}			
				else
				{
					flag=1;
					printf("\n\t\t\t\t Number Invalid!!!");
					printf("\n\t\t\t\t Press <ENTER> to try again!");
					getch();
					system("cls");
				}
			}
			else if((choice=='N')||(choice=='n'))
			flag=2;
			else
			{
				printf("\n\n\t\t\t\t Letter invalid!!!");
				printf("\n\t\t\t\t Press <ENTER> to try again!!!");
				flag=1;
				getch();
				system("cls");
			}
		}
	}while(flag<2);
	return;
}
/*view student*/
void printStudentBasicInfo (char studentName[120][100],int studentId[120],int studentCourse[120][7],char pay[120][5],int studentBirthday[120][10],int studentContact[120][11],int studentEmergencyContact[120][11],char studentEmailAddress[120][100])
{
	int row=0;        //for loop
	int col=1;        //for loop
	int count=0;      //for loop
	char choice;      //determine continue or return
	int flag=0;       //do while
	int enterNum=0;   //entered id to view more info
	do
	{
		printf("Notice: '--' meaning nothing has been entered.");
		printf("\nCourse cannot be repreated.");
		printf("\n");
		printf("\n\t\t\t\t||********************COURSES********************||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*       Course Name               Course Code *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Foundations of Mathematics         001     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Principles of Mathematics          002     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Functions                          003     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Advanced Functions                 004     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Data Management                    005     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Calculus                           006     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||***********************************************||");
	
		printf("\n\n\t   Student \t     Student  \t     ");
		printf("\n\t     ID    \t       Name   \t       Pay \tCourse 1\tCourse 2\tCourse 3\tCourse 4\tCourse 5\tCourse 6");
		for(row=1;row<120;row++)
		{
			if(strcmp(studentName[row],"N/A")!=0)
			{
				printf("\n");
				printf("\n\t       %d",row);
				printf("\t   %10s",studentName[row]);
				if((strcmp(pay[row],"yes")==0)||(strcmp(pay[row],"no")==0))
				printf("\t         %s",pay[row]);
				else
				printf("\t         ---");
				
				for (col=1;col<7;col++)
				{
					if((studentCourse[row][col]>0)&&(studentCourse[row][col]<7))
					{
						if(col==1)
						printf("\t\t 00%d",studentCourse[row][1]);
						for(count=2;count<col+1;count++)
						{
							if((studentCourse[row][col]==studentCourse[row][col-count])&&(col!=0))
							printf("\t\t --");
							else
							{	
								if(studentCourse[row][col]!=studentCourse[row][col-1])
								{
									printf("\t\t 00%d",studentCourse[row][col]);									
								}
								else
								printf("\t\t --");
								count=col+1;
							}
						}
						
					}
					else
					printf("\t\t--");
				}
			}
			else
			{
				printf("");
			}
		}
		do
		{
			printf("\n\n\t\t\t\tView more Infomation? Y/N: ");
			scanf("%c",&choice);
			fflush(stdin);
			if((choice=='Y')||(choice=='y'))
			{
				do
				{
					printf("\n\n\t\t\tStudent ID: ");
					scanf("%d",&enterNum);
					fflush(stdin);
					if((strcmp(studentName[enterNum],"N/A")==0)||(enterNum<1)||(enterNum>120))
					{
						printf("\n\n\t\t\t\tInvalid ID!");
						printf("\n\n\t\t\t\tPress <ENTER> to retry!");
						getch();
						system("cls");
						flag=0;
					}
					else
					{
						system("cls");
						printf("\n\n\t\t\t\tID: %d",enterNum);
						printf("\n\n\t\t\t\tName: %s",studentName[enterNum]);
						printf("\n\n\t\t\t\tDate of Birth: ");
						for(row=0;row<2;row++)
						{
							printf("%d",studentBirthday[enterNum][row]);
						}
						printf("/");
						for(row=2;row<4;row++)
						{
							printf("%d",studentBirthday[enterNum][row]);
						}
						printf("/");
						for(row=4;row<8;row++)
						{
							printf("%d",studentBirthday[enterNum][row]);
						}
						printf("\n\n\t\t\t\tPhone Number:");
						for(row=0;row<3;row++)
						{
							printf("%d",studentContact[enterNum][row]);
						}
						printf("-");
						for(row=3;row<6;row++)
						{
							printf("%d",studentContact[enterNum][row]);
						}
						printf("-");
						for(row=6;row<10;row++)
						{
							printf("%d",studentContact[enterNum][row]);
						}
						printf("\n\n\t\t\t\tEmergency Contact: ");
						for(row=0;row<3;row++)
						{
							printf("%d",studentEmergencyContact[enterNum][row]);
						}
						printf("-");
						for(row=3;row<6;row++)
						{
							printf("%d",studentEmergencyContact[enterNum][row]);
						}
						printf("-");
						for(row=6;row<10;row++)
						{
							printf("%d",studentEmergencyContact[enterNum][row]);
						}
						printf("\n\n\t\t\t\tEmail Address: %s",studentEmailAddress[enterNum]);
						printf("\n\n\t\t\t\tPress <ENTER> to continue!");
						getch();
						system("cls");
						flag=2;						
					}
				}while(flag<1);
			}
			else if((choice=='N')||(choice=='n'))
			flag=3;
			else
			flag=1;
		}while(flag<2);					
	}while(flag<3);
	return;
}

/*-----Teacher---------*/
/*teacher log in page*/
int teacherLogIn(char teacherName[30][100], int teacherId[30],int teacherID)
{
	int teacherLogInNumber=0; //teacher log in entered number
	teacherLogInNumber=0;     
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour	
	printf("password: [teacher ID]");
	printf("\nExample: PASSWORD: 1");
	printf("\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\tMMMMMMMM               MMMMMMMM               AAA         TTTTTTTTTTTTTTTTTTTTTTTHHHHHHHHH     HHHHHHHHH");	
	printf("\n\t\t\tM:::::::M             M:::::::M              A:::A        T:::::::::::::::::::::TH:::::::H     H:::::::H");
	printf("\n\t\t\tM::::::::M           M::::::::M             A:::::A       T:::::::::::::::::::::TH:::::::H     H:::::::H");
	printf("\n\t\t\tM:::::::::M         M:::::::::M            A:::::::A      T:::::TT:::::::TT:::::THH::::::H     H::::::HH");
	printf("\n\t\t\tM::::::::::M       M::::::::::M           A:::::::::A     TTTTTT  T:::::T  TTTTTT  H:::::H     H:::::H  ");
	printf("\n\t\t\tM:::::::::::M     M:::::::::::M          A:::::A:::::A            T:::::T          H:::::H     H:::::H  ");
	printf("\n\t\t\tM:::::::M::::M   M::::M:::::::M         A:::::A A:::::A           T:::::T          H::::::HHHHH::::::H  ");
	printf("\n\t\t\tM::::::M M::::M M::::M M::::::M        A:::::A   A:::::A          T:::::T          H:::::::::::::::::H  ");
	printf("\n\t\t\tM::::::M  M::::M::::M  M::::::M       A:::::A     A:::::A         T:::::T          H:::::::::::::::::H  ");
	printf("\n\t\t\tM::::::M   M:::::::M   M::::::M      A:::::AAAAAAAAA:::::A        T:::::T          H::::::HHHHH::::::H  ");
	printf("\n\t\t\tM::::::M    M:::::M    M::::::M     A:::::::::::::::::::::A       T:::::T          H:::::H     H:::::H  ");
	printf("\n\t\t\tM::::::M     MMMMM     M::::::M    A:::::AAAAAAAAAAAAA:::::A      T:::::T          H:::::H     H:::::H  ");
	printf("\n\t\t\tM::::::M               M::::::M   A:::::A             A:::::A   TT:::::::TT      HH::::::H     H::::::HH");
	printf("\n\t\t\tM::::::M               M::::::M  A:::::A               A:::::A  T:::::::::T      H:::::::H     H:::::::H");
	printf("\n\t\t\tM::::::M               M::::::M A:::::A                 A:::::A T:::::::::T      H:::::::H     H:::::::H");
	printf("\n\t\t\tMMMMMMMM               MMMMMMMMAAAAAAA                   AAAAAAATTTTTTTTTTT      HHHHHHHHH     HHHHHHHHH");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\n\t\t\t\tWelcome, Teacher!!");
	printf("\n\n\t\t\t\tPASSWORD:");
	scanf("%d",&teacherLogInNumber);
	fflush(stdin);
	
	if((teacherLogInNumber<teacherID+1)&&(teacherLogInNumber>0)&&(strcmp(teacherName[teacherLogInNumber],"N/A")!=0))
	{
		printf("\n\t\t\t\tHello!! %s",teacherName[teacherLogInNumber]);
		printf("\n\n\t\t\t\tPress <ENTER> to continue!!!");
		getch();
		system("cls");
	}
	else
	{
		printf("\n\t\t\t\tInvalid teacher ID!");
		printf("\n\t\t\t\tPlease make sure you have created a teacher account in 'GUIDANCE'!!");
		printf("\n\t\t\t\tPress <ENTER> to continue!!");
		getch();
		system("cls");
		teacherLogInNumber=0;
	}
	return(teacherLogInNumber);
}
/*teacher menu*/
int teacherMenu(void)
{
	int teacherMenuChoice=0;  //teacher menu choice
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour
	printf("\n\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t      __...--~~~~~-._   _.-~~~~~--...__       ");
	printf("\n\t\t\t\t\t    ,,               `,'               ,,     ");
	printf("\n\t\t\t\t\t   ,,    chuting      ,                 ,,    ");
	printf("\n\t\t\t\t\t  ,,__...--~~~~~~-._  ,  _.-~~~~~~--...__,,   ");
	printf("\n\t\t\t\t\t ,,__.....----~~~~._, , ,_.~~~~----.....__,,  ");
	printf("\n\t\t\t\t\t====================,,,,,==================== ");
	printf("\n\t\t\t\t\t                    `---`                     ");
	printf("\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t       ||**********TEACHER*********||");
	printf("\n\t\t\t\t\t       ||*                        *||");
	printf("\n\t\t\t\t\t       ||* 1] Enter/Edit Info     *||");
	printf("\n\t\t\t\t\t       ||*                        *||");
	printf("\n\t\t\t\t\t       ||* 2] View Info           *||");
	printf("\n\t\t\t\t\t       ||*                        *||");
	printf("\n\t\t\t\t\t       ||* 3] Add Assignment      *||");
	printf("\n\t\t\t\t\t       ||*                        *||");
	printf("\n\t\t\t\t\t       ||* 4] Log In Page         *||");
	printf("\n\t\t\t\t\t       ||*                        *||");
	printf("\n\t\t\t\t\t       ||* 5] Exit                *||");
	printf("\n\t\t\t\t\t       ||*                        *||");
	printf("\n\t\t\t\t\t       ||**************************||");
	printf("\n");
	printf("\n\t\t\t\t\t                  choice:");
	
	scanf("%d",&teacherMenuChoice);
	system("cls");
	return(teacherMenuChoice);
}

/*teacher enter infomation*/
void loadTeacherDetailedInfo (char teacherName[30][100],int teacherContact[30][11],char teacherEmailAddress[30][100],int teacherBirthday[30][10],int teacherLogInNumber)
{
	int row=0; //for loop
	int teacherUnrealContact[30][11]={0};  //teacher contact before calculation
	int teacherUnrealBirthday[30][10]={0};  //teacher date of birth before calculation
	printf("\n\n");
	printf("\n\n\t\t\t\tHello, %s!",teacherName[teacherLogInNumber]);
	printf("\n\n\t\t\t\tFollowing please enter your personal infomation");
	printf("\n\n\t\t\t\t-------------------------------------------------------------");
	printf("\n\n\t\t\t\tTeacher ID: %d",teacherLogInNumber);
	printf("\n\n\t\t\t\tName: %s",teacherName[teacherLogInNumber]);
	printf("\n\n\t\t\t\tDate of Birth(mm/dd/yyyy): ");
	for(row=0;row<2;row++)
	{
		teacherUnrealBirthday[teacherLogInNumber][row] = _getch();
		fflush(stdin);
		teacherBirthday[teacherLogInNumber][row] = teacherUnrealBirthday[teacherLogInNumber][row]-48;
		printf("%d",teacherBirthday[teacherLogInNumber][row]);
	}
	printf("/");
	for(row=2;row<4;row++)
	{
		teacherUnrealBirthday[teacherLogInNumber][row] = _getch();
		fflush(stdin);
		teacherBirthday[teacherLogInNumber][row] = teacherUnrealBirthday[teacherLogInNumber][row]-48;
		printf("%d",teacherBirthday[teacherLogInNumber][row]);
	}
	printf("/");
	for(row=4;row<8;row++)
	{
		teacherUnrealBirthday[teacherLogInNumber][row] = _getch();
		fflush(stdin);
		teacherBirthday[teacherLogInNumber][row] = teacherUnrealBirthday[teacherLogInNumber][row]-48;
		printf("%d",teacherBirthday[teacherLogInNumber][row]);
	}
	printf("\n\n\t\t\t\tPhone Number: ");        
	for(row=0;row<3;row++)
	{
		teacherUnrealContact[teacherLogInNumber][row] = _getch();
		fflush(stdin);
		teacherContact[teacherLogInNumber][row] = teacherUnrealContact[teacherLogInNumber][row]-48;
		printf("%d",teacherContact[teacherLogInNumber][row]);	
	}
	printf("-");
	for(row=3;row<6;row++)
	{
		teacherUnrealContact[teacherLogInNumber][row] = _getch();
		fflush(stdin);
		teacherContact[teacherLogInNumber][row] = teacherUnrealContact[teacherLogInNumber][row]-48;
		printf("%d",teacherContact[teacherLogInNumber][row]);
	}
	printf("-");
	for(row=6;row<10;row++)
	{
		teacherUnrealContact[teacherLogInNumber][row] = _getch();
		fflush(stdin);
		teacherContact[teacherLogInNumber][row] = teacherUnrealContact[teacherLogInNumber][row]-48;
		printf("%d",teacherContact[teacherLogInNumber][row]);
	}
	printf("\n\n\t\t\t\tEmail Address:");
	scanf("%s",&teacherEmailAddress[teacherLogInNumber]);
	fflush(stdin);
	
	return;
}
/*teacher view infomation*/
void printTeacherDetailedInfo (char teacherName[30][100],int teacherContact[30][11],char teacherEmailAddress[30][100],int teacherBirthday[30][10],int teacherLogInNumber)
{
	int row=0; //for loop
	printf("\n\n\t\t\t\t**************Teacher**************");
	printf("\n\n\t\t\t\tID: %d",teacherLogInNumber);
	printf("\n\n\t\t\t\tName: %s",teacherName[teacherLogInNumber]);
	printf("\n\n\t\t\t\tDate of Birth: ");
	for(row=0;row<2;row++)
	{
		printf("%d",teacherBirthday[teacherLogInNumber][row]);
	}
	printf("/");
	for(row=2;row<4;row++)
	{
		printf("%d",teacherBirthday[teacherLogInNumber][row]);
	}
	printf("/");
	for(row=4;row<8;row++)
	{
		printf("%d",teacherBirthday[teacherLogInNumber][row]);
	}
	printf("\n\n\t\t\t\tPhone Number:");
	for(row=0;row<3;row++)
	{
		printf("%d",teacherContact[teacherLogInNumber][row]);
	}
	printf("-");
	for(row=3;row<6;row++)
	{
		printf("%d",teacherContact[teacherLogInNumber][row]);
	}
	printf("-");
	for(row=6;row<10;row++)
	{
		printf("%d",teacherContact[teacherLogInNumber][row]);
	}
	printf("\n\n\t\t\t\tEmail Address: %s",teacherEmailAddress[teacherLogInNumber]);
	return;
}
/*teacher view course and add assignment*/
void teacherAddAssignment (char teacherName[30][100],int teacherLogInNumber,int teacherMajorCourse[30],int teacherCourse[30][6],char assignment[30][200],char assignmentSituation[30][10])
{
	int row=0;  //for loop
	char choice;  //determine continue or return
	int flag=0;  //for loop
	printf("\n");
	printf("\n\t\t\t\t||********************COURSES********************||");
	printf("\n\t\t\t\t||*                                             *||");
	printf("\n\t\t\t\t||*       Course Name               Course Code *||");
	printf("\n\t\t\t\t||*                                             *||");
	printf("\n\t\t\t\t||*  Foundations of Mathematics         001     *||");
	printf("\n\t\t\t\t||*                                             *||");
	printf("\n\t\t\t\t||*  Principles of Mathematics          002     *||");
	printf("\n\t\t\t\t||*                                             *||");
	printf("\n\t\t\t\t||*  Functions                          003     *||");
	printf("\n\t\t\t\t||*                                             *||");
	printf("\n\t\t\t\t||*  Advanced Functions                 004     *||");
	printf("\n\t\t\t\t||*                                             *||");
	printf("\n\t\t\t\t||*  Data Management                    005     *||");
	printf("\n\t\t\t\t||*                                             *||");
	printf("\n\t\t\t\t||*  Calculus                           006     *||");
	printf("\n\t\t\t\t||*                                             *||");
	printf("\n\t\t\t\t||***********************************************||");
	printf("\n\n\t\t\t\t********************Teacher********************");
	printf("\n\n\t\t\t\t ID  \t\t\t\tName");
	printf("\n\n\t\t\t\t %d  \t\t\t\t%s",teacherLogInNumber,teacherName[teacherLogInNumber]);
	printf("\n");
	printf("\n\t\t\t\t Supply \t Supply \t Supply \t Supply \t Supply \t Supply");
	printf("\n\t\t\t\tCourse 1\tCourse 2\tCourse 3\tCourse 4\tCourse 5\tCourse 6");
	printf("\n\t\t\t\t");
	for(row=0;row<6;row++)
	{
		if((teacherCourse[teacherLogInNumber][row]>0)&&(teacherCourse[teacherLogInNumber][row]<7)&&(teacherCourse[teacherLogInNumber][row]!=teacherMajorCourse[teacherLogInNumber]))
		printf("  00%d\t\t",teacherCourse[teacherLogInNumber][row]);
		else
		printf("  --\t\t");
	}
	printf("\n\n\t\t\t\t Major Course: 00%d",teacherMajorCourse[teacherLogInNumber]);

	do
	{
		printf("\n\n\t\t\t\t Add Assignment for 00%d? Y/N:",teacherMajorCourse[teacherLogInNumber]);
		scanf(" %c",&choice);
		fflush(stdin);

		if((choice=='Y')||(choice=='y'))
		{
			system("cls");
			printf("\n\t\t\t\tAssignment - 00%d",teacherMajorCourse[teacherLogInNumber]);
			printf("\n\t\t\t\tFollowing please enter the content of your assignment:");
			printf("\n\n\t\t\t\t");
			scanf("%[^\n]",assignment[teacherLogInNumber]);
			fflush(stdin);
			strcpy(assignmentSituation[teacherLogInNumber],"Updated"); 
			printf("\n\n\t\t\t\tPress <ENTER> to continue!!!");
			getch();
			flag=2;
		}
		else if((choice=='N')||(choice=='n'))
		flag=2;
		else
		flag=1;
	}while(flag<2);
	return;
}
/*------Student------*/
/*student log in page*/
int studentLogIn(char studentName[120][100],int studentId[120],int studentID)
{
	int studentLogInNumber=0; //student log in entered number
	studentLogInNumber=0;
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour	
	printf("password: [student ID]");
	printf("\nExample: PASSWORD: 1");
	printf("\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\tMMMMMMMM               MMMMMMMM               AAA         TTTTTTTTTTTTTTTTTTTTTTTHHHHHHHHH     HHHHHHHHH");	
	printf("\n\t\t\tM:::::::M             M:::::::M              A:::A        T:::::::::::::::::::::TH:::::::H     H:::::::H");
	printf("\n\t\t\tM::::::::M           M::::::::M             A:::::A       T:::::::::::::::::::::TH:::::::H     H:::::::H");
	printf("\n\t\t\tM:::::::::M         M:::::::::M            A:::::::A      T:::::TT:::::::TT:::::THH::::::H     H::::::HH");
	printf("\n\t\t\tM::::::::::M       M::::::::::M           A:::::::::A     TTTTTT  T:::::T  TTTTTT  H:::::H     H:::::H  ");
	printf("\n\t\t\tM:::::::::::M     M:::::::::::M          A:::::A:::::A            T:::::T          H:::::H     H:::::H  ");
	printf("\n\t\t\tM:::::::M::::M   M::::M:::::::M         A:::::A A:::::A           T:::::T          H::::::HHHHH::::::H  ");
	printf("\n\t\t\tM::::::M M::::M M::::M M::::::M        A:::::A   A:::::A          T:::::T          H:::::::::::::::::H  ");
	printf("\n\t\t\tM::::::M  M::::M::::M  M::::::M       A:::::A     A:::::A         T:::::T          H:::::::::::::::::H  ");
	printf("\n\t\t\tM::::::M   M:::::::M   M::::::M      A:::::AAAAAAAAA:::::A        T:::::T          H::::::HHHHH::::::H  ");
	printf("\n\t\t\tM::::::M    M:::::M    M::::::M     A:::::::::::::::::::::A       T:::::T          H:::::H     H:::::H  ");
	printf("\n\t\t\tM::::::M     MMMMM     M::::::M    A:::::AAAAAAAAAAAAA:::::A      T:::::T          H:::::H     H:::::H  ");
	printf("\n\t\t\tM::::::M               M::::::M   A:::::A             A:::::A   TT:::::::TT      HH::::::H     H::::::HH");
	printf("\n\t\t\tM::::::M               M::::::M  A:::::A               A:::::A  T:::::::::T      H:::::::H     H:::::::H");
	printf("\n\t\t\tM::::::M               M::::::M A:::::A                 A:::::A T:::::::::T      H:::::::H     H:::::::H");
	printf("\n\t\t\tMMMMMMMM               MMMMMMMMAAAAAAA                   AAAAAAATTTTTTTTTTT      HHHHHHHHH     HHHHHHHHH");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\n\t\t\t\tWelcome, Student!!");
	printf("\n\n\t\t\t\tPASSWORD:");
	scanf("%d",&studentLogInNumber);
	fflush(stdin);
	
	if((studentLogInNumber<studentID+1)&&(studentLogInNumber>0)&&(strcmp(studentName[studentLogInNumber],"N/A")!=0))
	{
		printf("\n\t\t\t\tHello!! %s",studentName[studentLogInNumber]);
		printf("\n\n\t\t\t\tPress <ENTER> to continue!!!");
		getch();
		system("cls");
	}
	else
	{
		printf("\n\t\t\t\tInvalid student ID!!");
		printf("\n\t\t\t\tPlease make sure you have created a student account in 'GUIDANCE'!!");
		printf("\n\t\t\t\tPress <ENTER> to continue!!");
		getch();
		system("cls");
		studentLogInNumber=0;
	}
	return(studentLogInNumber);
}
/*student menu*/
int studentMenu(void)
{
	int studentMenuChoice=0;  //student menu choice 
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour
	printf("\n\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t      __...--~~~~~-._   _.-~~~~~--...__       ");
	printf("\n\t\t\t\t\t    ,,               `,'               ,,     ");
	printf("\n\t\t\t\t\t   ,,    chuting      ,                 ,,    ");
	printf("\n\t\t\t\t\t  ,,__...--~~~~~~-._  ,  _.-~~~~~~--...__,,   ");
	printf("\n\t\t\t\t\t ,,__.....----~~~~._, , ,_.~~~~----.....__,,  ");
	printf("\n\t\t\t\t\t====================,,,,,==================== ");
	printf("\n\t\t\t\t\t                    `---`                     ");
	printf("\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t        ||**********STUDENT*********||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||* 1] Enter/Edit Info     *||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||* 2] View Info           *||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||* 3] View Assignment     *||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||* 4] Pay Your Course     *||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||* 5] Log In Page         *||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||* 6] Exit                *||");
	printf("\n\t\t\t\t\t        ||*                        *||");
	printf("\n\t\t\t\t\t        ||**************************||");
	printf("\n");
	printf("\n\t\t\t\t\t                   choice:");
	
	scanf("%d",&studentMenuChoice);
	system("cls");
	return(studentMenuChoice);
}
/*student enter infomation*/
void loadStudentDetailedInfo (char studentName[120][100],int studentContact[120][11],char studentEmailAddress[120][100],int studentBirthday[120][10],int studentLogInNumber,int studentEmergencyContact[120][11])
{
	int row=0;   //for loop
	int studentUnrealContact[120][11]={0};  //student contact before calculation 
	int studentUnrealBirthday[120][10]={0}; //student date of birth before calculation 
	int studentUnrealEmergencyContact[120][11]={0}; //student emergency contact before calculation
	printf("\n\n");
	printf("\n\n\t\t\t\tHello, %s!",studentName[studentLogInNumber]);
	printf("\n\n\t\t\t\tFollowing please enter your personal infomation");
	printf("\n\n\t\t\t\t-------------------------------------------------------------");
	printf("\n\n\t\t\t\tStudent ID: %d",studentLogInNumber);
	printf("\n\n\t\t\t\tName: %s",studentName[studentLogInNumber]);
	printf("\n\n\t\t\t\tDate of Birth(mm/dd/yyyy): ");
	for(row=0;row<2;row++)
	{
		studentUnrealBirthday[studentLogInNumber][row] = _getch();
		fflush(stdin);
		studentBirthday[studentLogInNumber][row] = studentUnrealBirthday[studentLogInNumber][row]-48;
		printf("%d",studentBirthday[studentLogInNumber][row]);
	}
	printf("/");
	for(row=2;row<4;row++)
	{
		studentUnrealBirthday[studentLogInNumber][row] = _getch();
		fflush(stdin);
		studentBirthday[studentLogInNumber][row] = studentUnrealBirthday[studentLogInNumber][row]-48;
		printf("%d",studentBirthday[studentLogInNumber][row]);
	}
	printf("/");
	for(row=4;row<8;row++)
	{
		studentUnrealBirthday[studentLogInNumber][row] = _getch();
		fflush(stdin);
		studentBirthday[studentLogInNumber][row] = studentUnrealBirthday[studentLogInNumber][row]-48;
		printf("%d",studentBirthday[studentLogInNumber][row]);
	}
	printf("\n\n\t\t\t\tPhone Number: ");        
	for(row=0;row<3;row++)
	{
		studentUnrealContact[studentLogInNumber][row] = _getch();
		fflush(stdin);
		studentContact[studentLogInNumber][row] = studentUnrealContact[studentLogInNumber][row]-48;
		printf("%d",studentContact[studentLogInNumber][row]);	
	}
	printf("-");
	for(row=3;row<6;row++)
	{
		studentUnrealContact[studentLogInNumber][row] = _getch();
		fflush(stdin);
		studentContact[studentLogInNumber][row] = studentUnrealContact[studentLogInNumber][row]-48;
		printf("%d",studentContact[studentLogInNumber][row]);	
	}
	printf("-");
	for(row=6;row<10;row++)
	{
		studentUnrealContact[studentLogInNumber][row] = _getch();
		fflush(stdin);
		studentContact[studentLogInNumber][row] = studentUnrealContact[studentLogInNumber][row]-48;
		printf("%d",studentContact[studentLogInNumber][row]);	
	}
	printf("\n\n\t\t\t\tEmergency Contact Number:");
	for(row=0;row<3;row++)
	{
		studentUnrealEmergencyContact[studentLogInNumber][row] = _getch();
		fflush(stdin);
		studentEmergencyContact[studentLogInNumber][row] = studentUnrealEmergencyContact[studentLogInNumber][row]-48;
		printf("%d",studentEmergencyContact[studentLogInNumber][row]);	
	}
	printf("-");
	for(row=3;row<6;row++)
	{
		studentUnrealEmergencyContact[studentLogInNumber][row] = _getch();
		fflush(stdin);
		studentEmergencyContact[studentLogInNumber][row] = studentUnrealEmergencyContact[studentLogInNumber][row]-48;
		printf("%d",studentEmergencyContact[studentLogInNumber][row]);	
	}
	printf("-");
	for(row=6;row<10;row++)
	{
		studentUnrealEmergencyContact[studentLogInNumber][row] = _getch();
		fflush(stdin);
		studentEmergencyContact[studentLogInNumber][row] = studentUnrealEmergencyContact[studentLogInNumber][row]-48;
		printf("%d",studentEmergencyContact[studentLogInNumber][row]);	
	}
	printf("\n\n\t\t\t\tEmail Address:");
	scanf("%s",&studentEmailAddress[studentLogInNumber]);
	fflush(stdin);
	return;
}
/*student view infomation*/
void printStudentDetailedInfo (char studentName[120][100],int studentContact[120][11],char studentEmailAddress[120][100],int studentBirthday[120][10],int studentLogInNumber,int studentEmergencyContact[120][11])
{
	int row=0;     //for loop
	int flag=0;
	flag=0;
	printf("\n\n\t\t\t\t**************Student**************");
	printf("\n\n\t\t\t\tID: %d",studentLogInNumber);
	printf("\n\n\t\t\t\tName: %s",studentName[studentLogInNumber]);
	printf("\n\n\t\t\t\tDate of Birth: ");
	for(row=0;row<2;row++)
	{
		printf("%d",studentBirthday[studentLogInNumber][row]);
	}
	printf("/");
	for(row=2;row<4;row++)
	{
		printf("%d",studentBirthday[studentLogInNumber][row]);
	}
	printf("/");
	for(row=4;row<8;row++)
	{
		printf("%d",studentBirthday[studentLogInNumber][row]);
	}
	printf("\n\n\t\t\t\tPhone Number:");
	for(row=0;row<3;row++)
	{
		printf("%d",studentContact[studentLogInNumber][row]);
	}
	printf("-");
	for(row=3;row<6;row++)
	{
		printf("%d",studentContact[studentLogInNumber][row]);
	}
	printf("-");
	for(row=6;row<10;row++)
	{
		printf("%d",studentContact[studentLogInNumber][row]);
	}
	printf("\n\n\t\t\t\tEmergency Contact: ");
	for(row=0;row<3;row++)
	{
		printf("%d",studentEmergencyContact[studentLogInNumber][row]);
	}
	printf("-");
	for(row=3;row<6;row++)
	{
		printf("%d",studentEmergencyContact[studentLogInNumber][row]);
	}
	printf("-");
	for(row=6;row<10;row++)
	{
		printf("%d",studentEmergencyContact[studentLogInNumber][row]);
	}
	printf("\n\n\t\t\t\tEmail Address: %s",studentEmailAddress[studentLogInNumber]);
	printf("\n\n\t\t\t\tPress <ENTER> to continue!!!");
	getch();
	return;
}
/*student view all course's assignment*/
void studentViewAssignment (char studentName[120][100],int studentLogInNumber, int studentCourse[120][7], int teacherMajorCourse[30], char assignment[30][200],char assignmentSituation[30][10])
{
	int row=0;      //for loop
	int courseNum=0; //course number
	int col=0;      //for loop
	int count=0;     //for loop
	int flag=0;      //do while
	char choice;     //determine continue or return
	int enterNumber=0; //id user entered
	do
	{
		printf("1. Courses that are repeated would show the same assignment.");
		printf("\n2. blank - no teacher are taking this course.");
		printf("\n3. 'N/A' - there are teachers taking this course, but no assignment has been handed out yet.");
		printf("\n4. 'updated' - new assignment is handed out!");
		printf("\n");
		printf("\n\t\t\t\t||********************COURSES********************||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*       Course Name               Course Code *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Foundations of Mathematics         001     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Principles of Mathematics          002     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Functions                          003     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Advanced Functions                 004     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Data Management                    005     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||*  Calculus                           006     *||");
		printf("\n\t\t\t\t||*                                             *||");
		printf("\n\t\t\t\t||***********************************************||");
		printf("\n\n");
		printf("\n\n\t\t\t\t********************Student*********************");
		printf("\n\n\t\t\t\t   ID                              Name");
		printf("\n\n\t\t\t\t   %d                               %s",studentLogInNumber,studentName[studentLogInNumber]);
		printf("\n\n\t\t\t\tNumber\t\tCourses\t\tAssignment");
		
		for(row=0;row<6;row++)
		{
			
			if((studentCourse[studentLogInNumber][row]>0)&&(studentCourse[studentLogInNumber][row]<7))
			{				
				printf("\n\n\t\t\t\t%d",row);		
				printf("\t\t00%d\t",studentCourse[studentLogInNumber][row]);
				for(col=0;col<30;col++)
				{
					if(teacherMajorCourse[col]!=0)				
					{
						if((teacherMajorCourse[col]==studentCourse[studentLogInNumber][row]))
						{
							printf("\t%s",assignmentSituation[col]);
						}
						else
						printf("");
					}
				}	
			}
			else
			printf("");
			
		}
		do
		{
			printf("\n\n\t\t\t\tView Assignment? Y/N: ");
			scanf(" %c",&choice);
			fflush(stdin);
			if((choice=='Y')||(choice=='y'))
			{

				printf("\n\t\t\t\tNumber: ");
				scanf(" %d",&enterNumber);
				fflush(stdin);				
				system("cls");
				printf("\n\n\t\t\t\t00%d",enterNumber);
				printf("\n\n\t\t\t\tAssignment:");
				for(row=0;row<30;row++)
				{					
					if(teacherMajorCourse[row]==enterNumber)
					printf("\n\n\t\t\t\t %s",assignment[row]);
					else 
					printf("");					
				}
				printf("\n\n\t\t\t\tPress <ENTER> to continue!!");
				getch();
				system("cls");			
				flag=1;			
			}
			else if((choice=='N')||(choice=='n'))
			flag=2;
			else
			flag=0;
		}while(flag<1);
	}while(flag<2);
	return;
}
/*student pay the course*/
void studentPayCourse (char studentName[120][100],int studentCourse[120][7],int studentLogInNumber,char pay[120][5],int studentPay[120])
{
	int row=0;       //for loop
	int courseNum=0; //course number
	char choice;     //determine continue or return
	int creditCard=0; //credit card number
	int col=0;       //for loop
	int flag=0;      //do while
	system("cls");
	printf("\n\t\t\t\t||***************************COURSES MENU****************************||");
	printf("\n\t\t\t\t||*                                                                 *||");
	printf("\n\t\t\t\t||*              Courses          Course Code    Prices($/semester) *||");
	printf("\n\t\t\t\t||*                                                                 *||");
	printf("\n\t\t\t\t||*   Foundations of Mathematics      001             1200          *||");
	printf("\n\t\t\t\t||*                                                                 *||");
	printf("\n\t\t\t\t||*   Principles of Mathematics       002             1200          *||");
	printf("\n\t\t\t\t||*                                                                 *||");
	printf("\n\t\t\t\t||*   Functions                       003             1200          *||");
	printf("\n\t\t\t\t||*                                                                 *||");
	printf("\n\t\t\t\t||*   Advanced Functions              004             1200          *||");
	printf("\n\t\t\t\t||*                                                                 *||");
	printf("\n\t\t\t\t||*   Data Management                 005             1200          *||");
	printf("\n\t\t\t\t||*                                                                 *||");
	printf("\n\t\t\t\t||*   Calculus                        006             1200          *||");
	printf("\n\t\t\t\t||*                                                                 *||");
	printf("\n\t\t\t\t||*******************************************************************||");
	printf("\n\n\t\t\t\tName\t\tID");
	printf("\n\n\t\t\t\t%s\t\t%d",studentName[studentLogInNumber],studentLogInNumber);
	printf("\n\n\t\t\t\t");
	for(row=0;row<6;row++)
	{
		courseNum=row+1;
		printf("Course %d\t",courseNum);
	}
	printf("\n\n\t\t\t\t");
	for(row=1;row<7;row++)
	{
		if(row==1)
		printf(" 00%d\t\t",studentCourse[studentLogInNumber][1]);
		if((studentCourse[studentLogInNumber][row]>0)&&(studentCourse[studentLogInNumber][row]<7))
		{
			for(col=2;col<row+1;col++)
			{
				if((row!=0)&&(studentCourse[studentLogInNumber][row]==studentCourse[studentLogInNumber][row-col]))
				printf("-- \t\t");
				else
				{	
					if(studentCourse[studentLogInNumber][row]!=studentCourse[studentLogInNumber][row-1])
					printf(" 00%d\t\t",studentCourse[studentLogInNumber][row]);
					else
					printf("-- \t\t");
					col=row+1;
				}
			}
		}
		else
		printf("--\t\t");
	}
	printf("\n\n\t\t\t\tTotal Price: $%d",studentPay[studentLogInNumber]);
	printf("\n\n\t\t\t\tPay: %s",pay[studentLogInNumber]);
	if(strcmp(pay[studentLogInNumber],"yes")==0)
	{
		printf("\n\n\t\t\t\tPaid: $%d",studentPay[studentLogInNumber]);
		printf("\n\n\t\t\t\tAll price has been paid!!");
		printf("\n\n\t\t\t\tPress <ENTER> to continue!!");
		getch();
	}
	else
	{
		do
		{
			printf("\n\n\t\t\t\tPay now? Y/N: ");
			scanf(" %c",&choice);
			fflush(stdin);
			if((choice=='y')||(choice=='Y'))
			{
				system("cls");	
				printf("\n\n\t\t\t\tTotal Price: $%d",studentPay[studentLogInNumber]);			
				printf("\n\n\t\t\t\tCredit Card:");
				scanf("%d",&creditCard);
				fflush(stdin);
				printf("\t\t\t\tPress <ENTER> to pay!!");
				getch();
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||===                              ||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing.");
				Sleep(50);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||   ===                           ||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing..");
				Sleep(50);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||      ===                        ||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing..");
				Sleep(50);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||         ===                     ||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing...");
				Sleep(50);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||            ===                  ||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing...");
				Sleep(50);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||               ===               ||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing.");
				Sleep(50);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||                  ===            ||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing.");
				Sleep(50);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||                     ===         ||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing..");
				Sleep(50);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||                        ===      ||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing..");
				Sleep(50);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||                           ===   ||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing...");
				Sleep(50);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t||                              ===||");
				printf("\n\t\t\t\t||=================================||");
				printf("\n\t\t\t\t            Processing...");
				Sleep(50);
				system("cls");
				printf("\n\n\t\t\t\tTotal Price: $%d",studentPay[studentLogInNumber]);
				printf("\n\n\t\t\t\t       Paid: $%d",studentPay[studentLogInNumber]);
				printf("\n\n\t\t\t\tAll Price has been paied!!");
				strcpy(pay[studentLogInNumber],"yes");
				flag=2;
			}
			else if((choice == 'n')||(choice == 'N'))
			{
				strcpy(pay[studentLogInNumber],"no");
				flag=2;
			}
			else
			flag=0;
		}while(flag<2);
	}

	return;
}
