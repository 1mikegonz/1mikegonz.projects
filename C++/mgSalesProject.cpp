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
	double salesTable[][];

	sales(employees, salesTable);

	bonus = bonusRate(); 
	
	cout << left << "Employee ID" << setw(12) << "Total" << setw(20) << "Bonus Amount" << setw(0) << endl;
	calcTotal(bonus, salesTable, employees);

	cout << "\n\nPress [enter] to exit..."; 
	cin.ignore();
	cin.get();

	return 0;
}

void sales(const string employees[EMPCOUNT], double salesTable[EMPCOUNT][MONTHCOUNT])
{
	for (int i = 0; i < EMPCOUNT; i++) 
	{
		cout << "Enter the sales for the employee with id: " << employees[i] << endl;
		
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
	} while (rate < 6); 
	return rate;
}

void calcTotal(double bonus, double salesTable[EMPCOUNT][MONTHCOUNT], const string employees[EMPCOUNT])
{
	double total;
	double totalBonus;
	for (int j = 0; j < MONTHCOUNT; j++) 
	{
		total = 0; 
		for (int i = 0; i < EMPCOUNT; i++)
		{
			
			total = total + (salesTable[i][j]); // total += salesTable[j]
			 
			totalBonus = total * (bonus / 100); 
		}
		cout << employees[i] << setw(17) << total << setw(18) << totalBonus << endl;
		
	}
}