//************************** Report Card Generation *************************//
//*************************** MADE BY : Tushar ******************//
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


class student
{
public:
	char name[20];
	int admno;
	char f_name[20];
	char add[20];
	char st_code[5];
	int m1,m2,m3,m4,m5;
	int total,pa;
	char grd;
	int dd;
	int mm;
	int yy;
};
student stud;
void box();
void b_box();
void add(void);
void report(void);
void search(void);
void report1(void);
void report2(void);
void report3(void);
void report4(void);
void del(void);
void start(void);

char ans;
int ch;

void main()
{   delay(500);
  start();
}

	void start(void)
	{ do
	      {
		 clrscr();
		 box();
		 gotoxy(33,2);
		 cout<<"MAIN MENU";
		 gotoxy(20,7);
		 cout<<"1. FOR ADD RECORD";
		 gotoxy(20,9);
		 cout<<"2. FOR SEARCH RECORD";
		 gotoxy(20,11);
		 cout<<"3. FOR REPORT";
		 gotoxy(20,13);
		 cout<<"4. FOR DELETION";
		 gotoxy(20,15);
		 cout<<"5. FOR EXIT";
		 gotoxy(26,19);
		 cout<<"ENTER YOUR CHOICE ..... #";
		 cin>>ch;
		 switch(ch)
		 {   	case 1: add();break;
			case 2: search();break;
			case 3: report();break;
			case 4: del();break;
		       default: exit(0);break;
		 }
	      }
	  while(ch!=5);
	}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//**************** THIS FUNCTION ADDS NEW RECORD IN THE FILE ************
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void add(void)
{fstream sfile;
 sfile.open("s.dat",ios::app);
 char ans;
 ans='y';
		do
		{ clrscr();
		  b_box();
		  stud.grd='o';
		  gotoxy(5,3);
		  cout<<"NAME : ";
		  gets(stud.name);
		  gotoxy(30,3);
		  cout<<"ADMISSION NO. : ";
		  cin>>stud.admno;
		  gotoxy(5,5);
		  cout<<"FATHER'S NAME : ";
		  gets(stud.f_name);
		  gotoxy(5,7);
		  cout<<"STREAM CODE(nmed/comm/medi) : ";
	   again: gotoxy(35,7);
		  cin>>stud.st_code;
		  if((strcmp(stud.st_code,"nmed")==0)||
		  (strcmp(stud.st_code,"comm")==0)||
		  (strcmp(stud.st_code,"medi")==0));
		  else{ gotoxy(35,7);
			 cout<<"No such stream exists, Please Re-enter";
			 delay(1200);
			 gotoxy(35,7);
			 clreol();
			 goto again;
		       }
		  gotoxy(5,9);
		  cout<<"ADDRESS : ";
		  gets(stud.add);
		  gotoxy(5,11);
		  cout<<"DATE OF BIRTH : ";
		  gotoxy(22,11);
		  cin>>stud.dd;
		  gotoxy(24,11);
		  cout<<"/";
		  cin>>stud.mm;
		  gotoxy(27,11);
		  cout<<"/";
		  cin>>stud.yy;
		  int flag=1;
		  while(flag==1)
      {	if((stud.yy<=0)||(stud.mm<=0)||(stud.dd<=0))
	{ gotoxy(22,11);
	  clreol();
	  gotoxy(22,11);
	  cout<<"Invalid Date, re-enter";
	  gotoxy(22,11);
	  delay(500);
	  clreol();
	  gotoxy(22,11);
	  cin>>stud.dd;
	  gotoxy(24,11);
	  cout<<"/";
	  cin>>stud.mm;
	  gotoxy(27,11);
	  cout<<"/";
	  cin>>stud.yy;
	  flag=1;
	}
	else
	{ switch(stud.mm)
	  { case 1 :
	    case 3 :
	    case 5 :
	    case 7 :
	    case 8 :
	    case 10:
	    case 12: if((stud.dd<1)||(stud.dd>31))
		      { gotoxy(22,11);
			clreol();
			gotoxy(22,11);
			cout<<"Invalid Date, re-enter";
			delay(500);
			gotoxy(22,11);
			clreol();
			gotoxy(22,11);
			cin>>stud.dd;
			gotoxy(25,11);
			cout<<"/";
			cin>>stud.mm;
			gotoxy(27,11);
			cout<<"/";
			cin>>stud.yy;
			flag=1;
		      }
		     else flag=0;break;

	    case 4 :
	    case 6 :
	    case 9 :
	    case 11: if((stud.dd<1)||(stud.dd>30))
			{ gotoxy(22,11);
			  clreol();
			  gotoxy(22,11);
			  cout<<"Invalid Date, re-enter";
			  gotoxy(22,11);
			  delay(500);
			  clreol();
			  gotoxy(22,11);
			  cin>>stud.dd;
			  gotoxy(24,11);
			  cout<<"/";
			  cin>>stud.mm;
			  gotoxy(27,11);
			  cout<<"/";
			  cin>>stud.yy;
			  flag=1;
			}
		       else flag=0;
		       break;

	    case 2: { if((stud.yy%4==0)&&
			 (stud.yy%100!=0)||
			 (stud.yy%400==0))
			{ if((stud.dd<1)||(stud.dd>29))
			    { gotoxy(22,11);
			      clreol();
			      cout<<"Invalid Date, re-enter";
			      gotoxy(22,11);
			      delay(500);
			      clreol();
			      gotoxy(22,11);
			      cin>>stud.dd;
			      gotoxy(24,11);
			      cout<<"/";
			      cin>>stud.mm;
			      gotoxy(27,11);
			      cout<<"/";
			      cin>>stud.yy;
			      flag=1;
			    }
			  else flag=0;
			       break;
			} }

	    default : { gotoxy(22,11);
			clreol();
			cout<<"Invalid Date, re-enter";
			gotoxy(22,11);
			delay(500);
			clreol();
			gotoxy(22,11);
			cin>>stud.dd;
			gotoxy(24,11);
			cout<<"/";
			cin>>stud.mm;
			gotoxy(27,11);
			cout<<"/";
			cin>>stud.yy;
			flag=1;
		      }
		  }
	     }    //*********** end of switch ************
	 }     //*********** end of while ************

       if(strcmp(stud.st_code,"nmed")==0)
	 { gotoxy(5,13);
	   cout<<"ENGLISH    ";
	   gotoxy(5,15);
	   cout<<"MATHS      ";
	   gotoxy(5,17);
	   cout<<"COMPUTERS  ";
	   gotoxy(5,19);
	   cout<<"CHEMISTRY  ";
	   gotoxy(5,21);
	   cout<<"PHYSICS    ";
	 }
       if(strcmp(stud.st_code,"medi")==0)
	 { gotoxy(5,13);
	   cout<<"ENGLISH    ";
	   gotoxy(5,15);
	   cout<<"MATHS      ";
	   gotoxy(5,17);
	   cout<<"BIOLOGY    ";
	   gotoxy(5,19);
	   cout<<"CHEMISTRY  ";
	   gotoxy(5,21);
	   cout<<"PHYSICS    ";
	 }
       if(strcmp(stud.st_code,"comm")==0)
	 { gotoxy(5,13);
	   cout<<"ENGLISH    ";
	   gotoxy(5,15);
	   cout<<"MATHS      ";
	   gotoxy(5,17);
	   cout<<"ACCOUNTS   ";
	   gotoxy(5,19);
	   cout<<"COMMERCE   ";
	   gotoxy(5,21);
	   cout<<"ECONOMICS  ";
	}
      gotoxy(17,13);
      cin>>stud.m1;
      while((stud.m1<0)||(stud.m1>100))
	{ gotoxy(17,13);
	  cout<<"Wrong Marks Entered, Re-enter ";
	  delay(500);
	  gotoxy(17,13);
	  clreol();
	  cin>>stud.m1;
	}
      gotoxy(17,15);
      cin>>stud.m2;
      while((stud.m2<0)||(stud.m2>100))
	{ gotoxy(17,15);
	  cout<<"Wrong Marks Entered, Re-enter";
	  delay(500);
	  gotoxy(17,15);
	  clreol();
	  cin>>stud.m2;
	}
      gotoxy(17,17);
      cin>>stud.m3;
      while((stud.m3<0)||(stud.m3>100))
	{ gotoxy(17,17);
	  cout<<"Wrong Marks Enterd, Re-enter";
	  delay(500);
	  gotoxy(17,17);
	  clreol();
	  cin>>stud.m3;
	}
      gotoxy(17,19);
      cin>>stud.m4;
      while((stud.m4<0)||(stud.m4>100))
	{ gotoxy(17,19);
	  cout<<"Wrong Marks Enterd, Re-enter";
	  delay(500);
	  gotoxy(17,19);
	  clreol();
	  cin>>stud.m4;
	}
      gotoxy(17,21);
      cin>>stud.m5;
      while((stud.m5<0)||(stud.m5>100))
	{ gotoxy(17,21);
	  cout<<"Wrong Marks Entered, Re-enter";
	  delay(500);
	  gotoxy(17,21);
	  clreol();
	  cin>>stud.m5;
	}
      stud.total=stud.m1+stud.m2+stud.m3+stud.m4+stud.m5;
      stud.pa=stud.total/5;
      if(stud.pa>=90) stud.grd='A';
	 else if((stud.pa<90)&&(stud.pa>=70)) stud.grd='B';
	 else if((stud.pa<70)&&(stud.pa>=50)) stud.grd='C';
	 else if((stud.pa<50)&&(stud.pa>=40)) stud.grd='D';
	 else stud.grd='E';
      sfile.write((char*)&stud,sizeof(student));
      gotoxy(5,23);
      cout<<"Do You Want To Continue... ?(y/n)";
      ans=getche();
    }
     while(ans=='y');
     sfile.close();
  }
//***************************************************************************
//******************** This Function Displays The Box ***********************
//***************************************************************************

void box(void)
{

	int counter;
	char c=3;
	for(counter=16;counter<=66;counter++)
	{ gotoxy(counter,21);
	  cout<<c;
	  sound(100+(15*counter));
	  delay(10);
	} nosound();
	for(counter=16;counter<=66;counter++)
	{  gotoxy(counter,4);
	   cout<<c;
	   sound(100+(15*counter));
	   delay(10);
	}  nosound();
	for(counter=4;counter<=21;counter++)
	{  gotoxy(16,counter);
	   cout<<c;
	   sound(100+(150*counter));
	   delay(15);
	} nosound();
	for(counter=4;counter<=21;counter++)
	{  gotoxy(66,counter);
	   cout<<c;
	   sound(100+(250*counter));
	   delay(15);
	} nosound();
      }

//***************************************************************************
//******************** This Function Displays The Big Box *******************
//***************************************************************************

void b_box(void)
{
	int counter;
	for(counter=2;counter<=76;counter++)
	{ gotoxy(counter,24);
	  cout<<"×"<<"×";

	  sound(100+(10*counter));
	  delay(10);
	} nosound();
	for(counter=2;counter<=76;counter++)
	{ gotoxy(counter,1);
	  cout<<"×"<<"×";
	  sound(100+(10*counter));
	  delay(10);
	} nosound();
}

//***************************************************************************
//******** This Function Searches The Record Of A Particular Student ********
//***************************************************************************

void search()
{
	int a_no;
	int flag=0;
	ifstream rfile;
	rfile.open("s.dat");
	clrscr();
	box();
	gotoxy(20,6);
	cout<<"ENTER ADMISSION No. TO BE SEARCHED : ";
	cin>>a_no;
	clrscr();
	box();
	while(rfile)
	{ rfile.read((char*)&stud,sizeof(student));
	  if(a_no==stud.admno)
	     { gotoxy(20,6);
	       cout<<"NAME          :   "<<stud.name;
	       gotoxy(20,8);
	       cout<<"FATHER'S NAME :   "<<stud.f_name;
	       gotoxy(20,10);
	       cout<<"STREAM        :	";
	       gotoxy(38,10);
	       cout<<stud.st_code;
	       gotoxy(20,12);
	       cout<<"D.O.B         :	";
	       gotoxy(38,12);
	       cout<<stud.dd<<"/";
	       gotoxy(40,12);
	       cout<<stud.mm<<"/";
	       gotoxy(42,12);
	       cout<<stud.yy;
	       gotoxy(20,14);
	       cout<<"ADDRESS       :	"<<stud.add;
	       flag=1;
	       gotoxy(10,24);
	       cout<<"Press Any Key To Continue.....";
	     }
	 }
	 if(flag==0)
	 { gotoxy(20,16);
	   cout<<"RECORD NOT FOUND!!!";
	   gotoxy(20,18);
	   cout<<"PRESS ANY KEY TO CONTINUE...";
	 }
	 getch();
	 rfile.close();

    }

//***************************************************************************
//*** This Function Forms Report Of A Particular Student/Group of Student ***
//***************************************************************************

void report()
{
	int ch1,temp;
	ch1=0;

     while(ch1!=5)
     {
	clrscr();
	box();
	gotoxy(20,6);
	cout<<"1. FOR INDIVIDUAL REPORT";
	gotoxy(20,8);
	cout<<"2. FOR STREAM WISE REPORT";
	gotoxy(20,10);
	cout<<"3. FOR REPORT OF ALL STUDENTS";
	gotoxy(20,12);
	cout<<"4. FOR SPECIAL REPORTS";
	gotoxy(20,14);
	cout<<"5. FOR EXIT";
	gotoxy(20,16);
	cout<<"ENTER CHOICE....";
	cin>>ch1;
	switch(ch1)
	{
	       case 1: report1();
		       break;
	       case 2: report2();
		       break;
	       case 3: report3();
		       break;
	       case 4: report4();
		       break;
	       default: flushall();
		       start();
		  }
	  }
  }
//***************************************************************************
//********** THIS FUNCTION DISPLAYS THE RECORD OF SINGLE STUDENT*************
//***************************************************************************



   void report1()
   { int  a_no;
     int col,row,i;
     ifstream rfile;
     rfile.open("s.dat");
     int ans1;
     clrscr();
     box();
     gotoxy (20,6);
     cout<<"ENTER ADMISSION No. OF THE STUDENT : ";
     cin>>a_no;
     while(rfile)
     {
	rfile.read((char*)&stud,sizeof(student));
	if(a_no==stud.admno)
	{  clrscr();
	   b_box();
	   gotoxy(30,3);
           cout<<"GURU HARKRISHAN PUBLIC SCHOOL";
	   gotoxy(33,4);
	   cout<<"EXAMINATION 2003-2004";
	   gotoxy(18,6);
	   cout<<"ADMISSION NUMBER:"<<stud.admno;
	   gotoxy(18,8);
	   cout<<"NAME:"<<stud.name;
	   gotoxy(18,9);
	   cout<<"STREAM:";
	   if(strcmp(stud.st_code,"nmed")==0)
	   {  gotoxy(28,9);
	      cout<<"COMPUTER";
	   }
	   if(strcmp(stud.st_code,"comm")==0)
	   {  gotoxy(28,9);
	      cout<<"COMMERCE";
	   }
	   if(strcmp(stud.st_code,"medi")==0)
	   {  gotoxy(28,9);
	      cout<<"MEDICAL";
	   }
	   gotoxy(48,9);
	   cout<<"DOB:"<<stud.dd<<"/"<<stud.mm<<"/"<<stud.yy;
	   gotoxy(18,10);
	   cout<<"..............................................";
	   gotoxy(18,11);
	   cout<<"SUBJECT";
	   gotoxy(36,11);
	   cout<<"MAX MARKS";
	   gotoxy(49,11);
	   cout<<"MARKS OBTAINED";
	   gotoxy(18,12);
	   cout<<"..............................................";
	   if(strcmp(stud.st_code,"nmed")==0)
	   {  gotoxy(18,13);
	      cout<<"ENGLISH";
	      gotoxy(18,14);
	      cout<<"MATHEMATICS";
	      gotoxy(18,15);
	      cout<<"COMPUTERS";
	      gotoxy(18,16);
	      cout<<"CHEMISTRY";
	      gotoxy(18,17);
	      cout<<"PHYSICS";
	   }
	   if(strcmp(stud.st_code,"comm")==0)
	   {  gotoxy(18,13);
	      cout<<"ENGLISH";
	      gotoxy(18,14);
	      cout<<"MATHEMATICS";
	      gotoxy(18,15);
	      cout<<"ACCOUNTS";
	      gotoxy(18,16);
	      cout<<"COMMERCE";
	      gotoxy(18,17);
	      cout<<"ECONOMICS";
	   }
	   if(strcmp(stud.st_code,"medi")==0)
	   {  gotoxy(18,13);
	      cout<<"ENGLISH";
	      gotoxy(18,14);
	      cout<<"MATHEMATICS";
	      gotoxy(18,15);
	      cout<<"BIOLOGY";
	      gotoxy(18,16);
	      cout<<"CHEMISTRY";
	      gotoxy(18,17);
	      cout<<"PHYSICS";
	   }
	   gotoxy(52,13);
	   cout<<stud.m1;
	   gotoxy(52,14);
	   cout<<stud.m2;
	   gotoxy(52,15);
	   cout<<stud.m3;
	   gotoxy(52,16);
	   cout<<stud.m4;
	   gotoxy(52,17);
	   cout<<stud.m5;
	   col=40;
	   row=13;
	   for(i=0;i<5;i++)
	   {  gotoxy(col,row);
	      cout<<"100";
	      row++;
	   }
	   gotoxy(19,18);
	   cout<<".............................................";
	   gotoxy(18,19);
	   cout<<"TOTAL:";
	   gotoxy(40,19);
	   cout<<"500";
	   gotoxy(52,19);
	   cout<<stud.total;
	   gotoxy(17,20);
	   cout<<"PERCENTAGE:"<<stud.pa<<"%";
	   gotoxy(37,20);
	   cout<<"GRADE:"<<stud.grd;
     }

 }
 rfile.close();
 getch();
}

//***************************************************************************
//************** This Function Displays The Result Streamwise ***************
//***************************************************************************

void report2()
{
	int row;
	char code[5];
	ifstream rfile;
	flushall();
	rfile.open("s.dat");
	clrscr();
	box();
	gotoxy(20,6);
	cout<<"Enter Stream ...(nmed/medi/comm) ";
	again: gotoxy(56,6);
	       cin>>code;
	       if((strcmp(code,"nmed")==0)||
	       (strcmp(code,"comm")==0)||
	       (strcmp(code,"medi")==0));
	       else{ gotoxy(20,2);
		     cout<<"No such stream exists, Please Re-enter.....";
		     delay(2000);
		     gotoxy(20,2);
		     clreol();
		     gotoxy(56,6);
		     clreol();
		     gotoxy(66,6);
		     char c=3;
		     cout<<c;
		     goto again;
		   }

	row=8;
	clrscr();
	box();
	gotoxy(20,6);
	cout<<"STREAM     NAME      TOTAL   DIV  ADMNO  ";
	gotoxy(20,7);
	cout<<"..........................................";
	while (rfile)
	{  rfile.read((char*)&stud,sizeof(student));
	   if(strcmp(code,stud.st_code)==0)
	   {  if(!rfile)
		break;
	      gotoxy(20,row);
	      cout<<stud.st_code;
	      gotoxy(30,row);
	      cout<<stud.name;
	      gotoxy(45,row);
	      cout<<stud.total;
	      gotoxy(52,row);
	      cout<<stud.grd;
	      gotoxy(58,row);
	      cout<<stud.admno;
	      row++;
	   }
	 }
	 gotoxy(18,20);
	 cout<<"PRESS ANY KEY TO CONTINUE....";
	 getch();
	 rfile.close();
	 flushall();
  }

//***************************************************************************
//*************** This Function Diplays Report Of All Students **************
//***************************************************************************

void report3()
{
	int row;
	char code[5];
	ifstream rfile;
	flushall();
	rfile.open("s.dat");
	clrscr();
	row=8;
	clrscr();
	box();
	gotoxy(20,6);
	cout<<"STREAM     NAME      TOTAL   DIV  ADMNO  ";
	gotoxy(20,7);
	cout<<"..........................................";
	while (rfile)
	{  rfile.read((char*)&stud,sizeof(student));

	   {  if(!rfile)
		break;
	      gotoxy(20,row);
	      cout<<stud.st_code;
	      gotoxy(30,row);
	      cout<<stud.name;
	      gotoxy(45,row);
	      cout<<stud.total;
	      gotoxy(52,row);
	      cout<<stud.grd;
	      gotoxy(58,row);
	      cout<<stud.admno;
	      row++;
	   }
	 }
	 gotoxy(18,20);
	 cout<<"PRESS ANY KEY TO CONTINUE....";
	 getch();
	 rfile.close();
	 flushall();
  }

//***************************************************************************
//************ This Function Displays Special Reports ***********************
//***************************************************************************

void report4()
{   int fe;
   while(fe!=3)
   {clrscr();
    box();
    gotoxy(20,6);
    cout<<"1. Report Of Distinction Holders";
    gotoxy(20,8);
    cout<<"2. Report Of Failures";
    gotoxy(20,10);
    cout<<"3. Exit";
    gotoxy(22,16);
    cout<<"Enter choice... ";
    cin>>fe;
    switch(fe)
    {case 1:{ int row;
	     ifstream rfile;
	     flushall();
	     rfile.open("s.dat");
	     clrscr();
	     row=8;
	     clrscr();
	     box();
	     gotoxy(20,6);
	     cout<<"STREAM     NAME      TOTAL   DIV  ADMNO  ";
	     gotoxy(20,7);
	     cout<<"..........................................";
	     while (rfile)
	     {  rfile.read((char*)&stud,sizeof(student));
		if('A'==stud.grd)
		{  if(!rfile)
		   break;
		   gotoxy(20,row);
		   cout<<stud.st_code;
		   gotoxy(30,row);
		   cout<<stud.name;
		   gotoxy(45,row);
		   cout<<stud.total;
		   gotoxy(52,row);
		   cout<<stud.grd;
		   gotoxy(58,row);
		   cout<<stud.admno;
		   row++;
	      }
	     }
		  gotoxy(18,20);
		  cout<<"PRESS ANY KEY TO CONTINUE....";
		  getch();
		  rfile.close();
		  flushall();
	     }    break;

    case 2: {int row;
	     ifstream rfile;
	     flushall();
	     rfile.open("s.dat");
	     clrscr();
	     row=8;
	     clrscr();
	     box();
	     gotoxy(20,6);
	     cout<<"STREAM     NAME      TOTAL   DIV  ADMNO  ";
	     gotoxy(20,7);
	     cout<<"..........................................";
	     while (rfile)
	     {  rfile.read((char*)&stud,sizeof(student));
		if('E'==stud.grd)
		{  if(!rfile)
		   break;
		   gotoxy(20,row);
		   cout<<stud.st_code;
		   gotoxy(30,row);
		   cout<<stud.name;
		   gotoxy(45,row);
		   cout<<stud.total;
		   gotoxy(52,row);
		   cout<<stud.grd;
		   gotoxy(58,row);
		   cout<<stud.admno;
		   row++;
	      }
	     }
		  gotoxy(18,20);
		  cout<<"PRESS ANY KEY TO CONTINUE....";
		  getch();
		  rfile.close();
		  flushall();
	     }
	   }
 }
 }

//***************************************************************************
//******** This Function Will Delete Records Of A Particular ****************
//***************************************************************************

    void del()
      {	int a_no;
	clrscr();
	b_box();
	gotoxy(5,3);
	cout<<"Enter Admno. Of The Student Whose Record Is To Be Deleted ";
	cin>>a_no;
	ifstream abc;
	ofstream def;

	abc.open("s.dat");
	def.open("s1.dat");
	abc.read((char*)&stud,sizeof(student));
	while(abc)
		{  if (a_no!=stud.admno)
		     {  def.write((char*)&stud,sizeof(student));
		     }
		   if(abc.eof()!=0) break;
		   abc.read((char*)&stud,sizeof(student));
 }
	abc.close();
	def.close();
	ofstream xyz;
	ifstream stu;
	xyz.open("s.dat");
	stu.open("s1.dat");
	xyz.seekp(0);
	stu.seekg(0);
	stu.read((char*)&stud,sizeof(student));
	while(stu)
	       {
		 xyz.write((char*)&stud,sizeof(student));
		 if(stu.eof()!=0) break;
		 stu.read((char*)&stud,sizeof(student));

	       }
      stu.close();
      xyz.close();

    }
