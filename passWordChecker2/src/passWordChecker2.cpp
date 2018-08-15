//============================================================================
// Name        : passWordChecker.cpp
// Author      : Mina Tadros
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string passWordChecker();


int main() {

	string passWord = passWordChecker();

	cout << "your password is: " << passWord;

	return 0;
}

string passWordChecker(){

	string password;

	cout << "Combine different types of characters" << endl;
	cout << "Use a mix of alphanumeric characters (letters and numbers) and symbols:" << endl;
	cout << "	*	Uppercase (capital) letters. Examples: A, E, R" << endl;
	cout << "	*	Lowercase (small) letters. Examples: a, e, r" << endl;
	cout << "	*	Numbers. Examples: 2, 6, 7" << endl;
	cout << "	*	Symbols and special characters. Examples: ! @ & *" << endl;

	cout << "Please Input Password: ";
	getline(cin, password);

	if(password.length() >= 6){

		bool upperCase = false;
		bool lowerCase = false;
		bool number = false;
		bool specialCharacter = false;
		bool space = false;

			for (int i = 0; i < password.length(); i++)
			{
			if(isdigit(password[i])){
			number = true;  	// makes sure there is a number
			}else if(isupper(password[i])){
			upperCase = true; 	// makes sure there is an uppercase Character
			}else if(islower(password[i])){
			lowerCase = true;	// makes sure there is a lowercase
			}else if(isblank(password[i])){
			space = true;
			}else{
			specialCharacter = true;
			}
			}
			if(upperCase == true && lowerCase == true && number == true && space == false && specialCharacter == true){
			return password;
			}else if(upperCase == false && lowerCase == true && number == true && space == false && specialCharacter == true){
				cout << "*** Password must contain at least one uppercase character ***" << endl;
				return passWordChecker();
			}else if(upperCase == true && lowerCase == false && number == true && space == false && specialCharacter == true){
				cout << "*** Password must contain at least one lowercase character ***" << endl;
				return passWordChecker();
			}else if(upperCase == true && lowerCase == true && number == false && space == false && specialCharacter == true){
				cout << "*** Password must contain at least one numaric character ***" << endl;
				return passWordChecker();
			}else if(upperCase == true && lowerCase == true && number == true && space == true && specialCharacter == true){
				cout << "*** Password must not contain any spaces ***" << endl;
				return passWordChecker();
			}else if(upperCase == true && lowerCase == true && number == true && space == false && specialCharacter == false){
				cout << "*** Password must contain at least one special character ***" << endl;
				return passWordChecker();
			}else{
				cout << "*** Password does not meet more than one criteria ***" << endl;
				return passWordChecker();
			}
	}
	else{
		cout << "***Invlaid entry password less than 6 characters***" << endl;
		return passWordChecker();
	}
}
