#include <iostream>
using namespace std;

void fiveTestScores();
int avgScore(int, int, int, int, int);
int dropLowestScore(int, int, int, int, int);

int main(){
	fiveTestScores();
}

void fiveTestScores(){
	int sum = 0;
	int test1, test2, test3, test4, test5;
	char dropLowestTestGrade;
	cout << "Please enter five test scores, each seperated by a space." << endl;
	cin >> test1 >> test2 >> test3 >> test4 >> test5;
	sum = avgScore(test1, test2, test3, test4, test5);
	cout << "Your average test score is: " << sum << endl;
	cout << "Would you like to drop your lowest test grade?\nPlease enter a 'y' for yes or a 'n' for no.: ";
	cin >> dropLowestTestGrade;
	if (dropLowestTestGrade == 'y'){
		dropLowestTestGrade = 1;
	}
	else {
		dropLowestTestGrade = 0;
	}

	switch (dropLowestTestGrade){

	case 1: // you can use a case statement with 'y' and 'Y' with 'n' and 'N'
            //case 'y':
            //case 'Y':
            //this is known as falling through cases.
        sum = (test1 + test2 + test3 + test4 + test5) - dropLowestScore(test1, test2, test3, test4, test5);
		sum = sum / 4;
		cout << "Your new average test score is " << sum;
		break;

	case 0:
		cout << "Your average test score will remain unchanged. " << avgScore(test1, test2, test3, test4, test5) << endl;
		break;

	default: // this should have been a do/while loop to catch the errors.
		cout << "Please enter a correct response.\nPlease enter a 'y' for yes or a 'n' for no.:  ";
		cin >> dropLowestTestGrade;
		break;
	}
}

int avgScore(int test1,int test2,int test3,int test4,int test5){
	int sum = 0;
	sum = (test1 + test2 + test3 + test4 + test5) / 5;
	return sum;
}

int dropLowestScore(int test1, int test2, int test3, int test4, int test5){
	int minScore = 0; // instead of 0, you could have set it to test1
	if (test1 < test2){
		if (test2 < test1){
			minScore = test2;
		}
		else{
			minScore = test1;
		}
	}
	else if (minScore > test3){
		minScore = test3;
	}
	else if (minScore > test4){
		minScore = test4;
	}
	else{
		minScore = test5;
	}
	return minScore;
}