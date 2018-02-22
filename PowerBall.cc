//Patrick Connolly
/*This program takes the most recent 24 draws of the PowerBall
 * and calculates the numbers drawn the most. It then shows
 * a histogram showing the numbers from most often drawn to least
 * and gives a "prediction." This is not intended to acctually
 * determine anything and is a fun tool. I am not liable for anything
 * that becomes of this good or bad. This program is open source.
 * I am NOT liable for anything that becomes of the original work
 * or any derived versions. This is simply a statistics for fun program.
 * The guess recieved is not intended to be accurate and should not be
 * used to predict the actual outcome. I cannot stress this enough. Do
 * NOT use these numbers for the lottery. They will not win you anything.*/

#include <iostream>
#include <string>
using namespace std;

void addNums(int* white, int* red);
int parseNum(string it);
int parseNumHelper(char it);
void calculate(int* white, int* red);

int main()
{
	int numberOfGames = 24;
	int white [70];
	for(int i=0; i<70; i++){white[i]=0;}
	int powerBall [27];
	for(int i=0; i<27; i++){powerBall[i]=0;}
	
	for(int i=0; i<numberOfGames; i++)
	{addNums(white, powerBall);}
	
	calculate(white, powerBall);
	return 0;
}

void addNums(int* white, int* red)
{
	int temp;
	string tempo;
	for(int i=0; i<5; i++)
	{
		cin >> tempo;
		temp = parseNum(tempo);
		//cout << temp << "\n" << white[temp] << "\n";
		if(temp>0){white[temp]++;}
		else{cout<<"ERROR ADD NUMS WHITE\n";}
		//cout << white[temp] << "\n----------------------\n";
	}
	cin >> tempo;
	temp = parseNum(tempo);
	if(temp>0){red[temp]++;}
	else{cout<<"ERROR ADD NUMS POWERBALL\n";}
}

int parseNum(string it)
{
	int fin = 0;
	for(int i=0; i<(int)it.size(); i++)
	{
		fin = fin * 10 + parseNumHelper(it[i]);
	}
	return fin;
}

int parseNumHelper(char it)
{
	if(it=='0'){return 0;}
	else if(it=='1'){return 1;}
	else if(it=='2'){return 2;}
	else if(it=='3'){return 3;}
	else if(it=='4'){return 4;}
	else if(it=='5'){return 5;}
	else if(it=='6'){return 6;}
	else if(it=='7'){return 7;}
	else if(it=='8'){return 8;}
	else if(it=='9'){return 9;}
	else{return -1;}
}
	
void calculate(int* white, int* red)
{
	int whiteVals [70];
	for(int i=0; i<70; i++){whiteVals[i]=i;}
	int redVals [27];
	for(int i=0; i<27; i++){redVals[i]=i;}
	
	int temp;
	
	for(int i=0; i<70; i++)
	{
		for(int j=0; j<70-i-1; j++)
		{
			if(white[j]<white[j+1])
			{
				temp = whiteVals[j];
				whiteVals[j]=whiteVals[j+1];
				whiteVals[j+1]=temp;
				
				temp = white[j];
				white[j]=white[j+1];
				white[j+1]=temp;
			}
		}
	}
	
	for(int i=0; i<27; i++)
	{
		for(int j=0; j<27-i-1; j++)
		{
			if(red[j]<red[j+1])
			{
				temp = redVals[j];
				redVals[j]=redVals[j+1];
				redVals[j+1]=temp;
				
				temp = red[j];
				red[j]=red[j+1];
				red[j+1]=temp;
			}
		}
	}
	
	for(int i=0; i<70; i++)
	{
		cout << whiteVals[i];
		if(whiteVals[i]<10){cout << "  : ";}
		else{cout << " : ";}
		for(int j=0; j<white[i]; j++){cout << "*";}
		cout << "\n";
	}
	cout << "------------------------------------\n";
	for(int i=0; i<27; i++)
	{
		cout << redVals[i];
		if(redVals[i]<10){cout << "  : ";}
		else{cout << " : ";}
		for(int j=0; j<red[i]; j++){cout << "*";}
		cout << "\n";
	}
	cout << "\nI PREDICT ";
	for(int i=0; i<5; i++)
	{
		cout << whiteVals[i] << " ";
	}
	cout << "WITH A POWER BALL OF " << redVals[0] << ".\n";
}
