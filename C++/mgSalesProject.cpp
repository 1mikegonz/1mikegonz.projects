#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


const int EMPCOUNT = 5;
const int MONTHCOUNT = 3;
const string employees[EMPCOUNT] = { "A123", "B456", "C789", "D222", "E333" };
const string month[MONTHCOUNT] = { "January", "February", "March" };
void sales(const string employees[], double salesTable[][MONTHCOUNT]);
double bonusRate();
void calcTotal(double bonus, double salesTable[][MONTHCOUNT], const string employees[EMPCOUNT]);


int main()
{
	double bonus;
	double salesTable[][]; //you just need to initialize the array. It doesn't need to be set until you call the function

	sales(employees, salesTable);

	bonus = bonusRate(); //read the direction again for this one
	
	cout << left << "Employee ID" << setw(12) << "Total" << setw(20) << "Bonus Amount" << setw(0) << endl;
	//Why wouldn't you just put this statement in the function?
	calcTotal(bonus, salesTable, employees);

	cout << "\n\nPress [enter] to exit..."; //this wasn't part of the output he provided. Is there a reason you added this? I'm not being mean, just thinking out loud
	cin.ignore();
	cin.get();

	return 0;
}

void sales(const string employees[EMPCOUNT], double salesTable[EMPCOUNT][MONTHCOUNT])
{
	for (int i = 0; i < EMPCOUNT; i++) 
	{
		cout << "Enter the sales for the employee with id: " << employees[i] << endl;
		//there is an enter key that the directions is asking for. How would you do this?
		for (int j = 0; j < MONTHCOUNT; j++)
		{			
			cout << month[j] << ": $";
			cin >> salesTable[i][j];
		}
	}
}

double bonusRate()
{
	double rate;
	do
	{
		cout << "Enter the current bonus rate: ";
		cin >> rate;
	} while (rate < 6); //where is this number coming from? 
	return rate;
}

void calcTotal(double bonus, double salesTable[EMPCOUNT][MONTHCOUNT], const string employees[EMPCOUNT])
{
	double total;
	double totalBonus;
	for (int j = 0; j < MONTHCOUNT; j++) //which one goes in the outer loop and which one goes in the inner loop
	{
		total = 0; 
		for (int i = 0; i < EMPCOUNT; i++)
		{
			//make sure you always set it to zero. this will cause issues in the future!
			total = total + (salesTable[i][j]); // total += salesTable[j]
			//you will receive an error 95% of the time since you didn't declare a value on this variable to begin with 
			totalBonus = total * (bonus / 100); //this wouldn't be done like this. Think about how I told you it needed to be done. Don't be afriad to use more variables.
		}
		cout << employees[i] << setw(17) << total << setw(18) << totalBonus << endl;// if it the cout is in this inner for loop, how many times will it be printing out
		//there is no formatting (decimal points) on these outputs
	}
}