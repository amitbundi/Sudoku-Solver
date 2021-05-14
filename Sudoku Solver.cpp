#include <iostream> 
# include <iomanip>
# include <cmath>
# include <cstring>
# include <windows.h>

using namespace std;
int sudokucheck(int num1, int num2);

//int sudokunumber[9][9] = {{0,0,2,0,0,0,1,0,0},{0,5,6,4,0,9,7,0,0},{1,0,0,0,2,0,0,0,8},{0,8,9,7,0,1,4,6,0},{0,0,0,0,0,0,0,0,0},{0,3,4,8,0,5,9,7,0},{9,0,0,0,7,0,0,0,6},
{0,0,1,2,0,8,3,0,0},{0,0,8,0,0,0,5,0,0}};

//int sudokuoriginal[9][9]= {{0,0,2,0,0,0,1,0,0},{0,5,6,4,0,9,7,0,0},{1,0,0,0,2,0,0,0,8},{0,8,9,7,0,1,4,6,0},{0,0,0,0,0,0,0,0,0},{0,3,4,8,0,5,9,7,0},{9,0,0,0,7,0,0,0,6},
{0,0,1,2,0,8,3,0,0},{0,0,8,0,0,0,5,0,0}};


 
int rowspl1, rowspl2, colspl1, colspl2;

int rowchk[81], colchk[81];

int ctrchk1=0;

int iterations =0;


int quickcheckrow()
{	
	// across all row checks
	for (int counter=0;counter<9;counter++)
	
	{
		for (int counter1=0;counter1<8;counter1++)
		{
			int counter2=counter1+1;
			do
			{
				if(sudokunumber[counter][counter1]!=0 && sudokunumber[counter][counter1]==sudokunumber[counter][counter2] )
				{
					
					return counter+1;
				}
				counter2++;
			} while (counter2<9);
		}
	}
		
	return 0;	
}

int quickcheckcol()
{	
	// across all col checks
	for (int counter=0;counter<8;counter++)
	
	{
		for (int counter1=0;counter1<9;counter1++)
		{
			int counter2=counter1+1;
			do
			{
				if(sudokunumber[counter1][counter]!=0 && sudokunumber[counter1][counter]==sudokunumber[counter2][counter] )
				{
					
					return counter+1;
				}
				counter2++;
			} while (counter2<9);
		}
	}
		
	return 0;	
}



void setcolor(int value)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

void sudokuentry()
{

cout<<"Please enter number within 0-9 only (empty cells to be put in as 0) :"<<endl<<endl;

	for(int counter = 0;counter<9;counter++)
	{
		for (int counter1=0; counter1<9;counter1++)
		{
			cout<<"Enter the number at ("<<counter+1<<","<<counter1+1<<") :";
			cin>>sudokunumber[counter][counter1];
			if (cin.fail())
			{
				cout<<endl<<"Not an integer"<<endl;
				counter1--;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				
				
			} else
		if (sudokunumber[counter][counter1]<0 || sudokunumber[counter][counter1]>9)
		{
			cout<<endl<<"Incorrect Entry - Please enter number within 0-9 only"<<endl;
			counter1--;
		}
		
		
		
		}
		
		
		
	}
	
	for (int k=0; k<9;k++)
	{
		for (int j=0;j<9;j++)
		{
			sudokuoriginal[k][j]=sudokunumber[k][j];
			
		}
	}
	return;
}

void sudokudisplay()
{

cout<<endl<<endl<<setw(5)<<"No. of iterations :"<<iterations<<endl<<endl;

cout<<setw(4)<<"_"<<setw(35)<<setfill('_')<<"_"<<endl;


cout<<setw(3)<<setfill(' ')<<"|";

int setline1;
for (setline1=4;setline1<38; setline1=setline1+4)
{
	
	cout<<setw(4)<<"|";
}


	cout<<endl<<setw(3)<<setfill(' ')<<"|"<<setw(2);
	
	for(int counter = 0;counter<9;counter++)
	{
		
		
		for (int counter1=0; counter1<9;counter1++)
		{
			if (sudokuoriginal[counter][counter1]==0)
			{
			
			setcolor(14);
			cout<<(sudokunumber[counter][counter1]);
			setcolor(7);
			cout<<setw(2)<<"|"<<setw(2);
        	} else
        	{
        	cout<<(sudokunumber[counter][counter1])<<setw(2)<<"|"<<setw(2);
			}
		}
		
		cout<<endl<<setw(4)<<"|_"<<setw(35)<<setfill('_')<<"_|";
// putting in the vertical lines
		
		if(counter!=8)
{

		cout<<endl;
		cout<<setw(3)<<setfill(' ')<<"|";


for (setline1=4;setline1<38; setline1=setline1+4)
{
	
	cout<<setw(4)<<"|";
}
	
	
		
		cout<<endl<<setw(3)<<setfill(' ')<<"|"<<setw(2);
}


	}
	
cout<<endl<<endl<<"The original numbers are in white"<<endl;
setcolor(14);
cout<<"The calculated numbers are in yellow";
setcolor(7);
return;
}


int sudokusolver()

{

int lnumber;
	
	for(int counter = 0;counter<9;counter++)
	{
		for (int counter1=0; counter1<9;counter1++)
		{
			if (sudokunumber[counter][counter1]==0)
			{
				
				sudokunumber[counter][counter1]=1;
				int revert = sudokucheck(counter, counter1);
				while (revert!=2)
				{
					iterations++;
					sudokunumber[counter][counter1]++;
					revert = sudokucheck(counter, counter1);
	        	if (sudokunumber[counter][counter1]>9)
				{
					
					//cout<<endl<<endl<<counter<<"   "<<counter1<<"   "<<sudokunumber[rowchk[lnumber]][colchk[lnumber]]<<endl<<endl;
					//sudokudisplay();
					//system("pause");
					
					if (sudokunumber[rowchk[0]][colchk[0]]>9)
					{
						
						return 10;
						
					}
					
					sudokunumber[counter][counter1]=0;
					counter=rowchk[lnumber];
					counter1=colchk[lnumber];
					ctrchk1=lnumber;
					revert=6;
					if (lnumber!=0)
					{
						lnumber--;
					}
								
					
				}
					
					
				}
			rowchk[ctrchk1]=counter;
			colchk[ctrchk1]=counter1;
			lnumber=ctrchk1;
			ctrchk1++;
								
			}
			
		}
			
	
	}

return 0;	
}


int sudokucheck(int num1, int num2)
{

//row check

for (int counter=0;counter<9;counter++)
{
	if(num2!=counter)
	{
		if (sudokunumber[num1][num2]==sudokunumber[num1][counter])
		{
			return 3;
			
		}
	}
}
	
//column check

for (int counter=0;counter<9;counter++)
{
	if(num1!=counter)
	{
		if (sudokunumber[num1][num2]==sudokunumber[counter][num2])
		{
			return 4;
			
		}
	}
}

//matrix check

if (num1<3)
{
	rowspl1=0;
	rowspl2=2;
	} 
	else if (num1<6)
	{
	rowspl1=3;
	rowspl2=5;
	
	}else 
	{
		rowspl1=6;
		rowspl2=8;
	}

if (num2<3)
{
	colspl1=0;
	colspl2=2;
	} 
	else if (num2<6)
	{
	colspl1=3;
	colspl2=5;
	
	}else 
	{
		colspl1=6;
		colspl2=8;
	}


for (int counter=rowspl1; counter<=rowspl2; counter++)
{
	for (int counter1=colspl1;counter1<=colspl2;counter1++)
	{
		if(num1!=counter && num2!=counter1)
		{
			if (sudokunumber[num1][num2]==sudokunumber[counter][counter1])
		{
			return 5;
			
		}
		}
	}
}

return 2;
	
}


int main()
{
	

sudokuentry();

int sudokusen = quickcheckrow();

if (sudokusen!=0)
{
	cout<<endl<<endl<<setw(5)<<"Repetition of a number on row no: "<<sudokusen;
	return 0;
} 

sudokusen = quickcheckcol();

if (sudokusen!=0)
{
	cout<<endl<<endl<<setw(5)<<"Repetition of a number on col no: "<<sudokusen;
	return 0;
} 

int solv = sudokusolver();

if (solv==10)
{
cout<<endl<<endl<<setw(5)<<"No. of iterations :"<<iterations<<endl<<endl;
						cout<<setw(5)<<"Cannot be solved";

	
} else

{


sudokudisplay();

}

cout<<endl<<endl;

system ("pause");

return 0;

}
