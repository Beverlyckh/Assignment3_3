/*
 * BigNumbers.cpp
 *
 *  Created on: Oct 30, 2017
 *  Author: Beverly ACKAH
 *
 */

#include "LinkedStack.h"
#include <iostream>
#include <string>
using namespace std;

string sum(string,string);

int main(){
	LinkedStack<int> s1; // first stack will hold the digits of the first number,
	LinkedStack<int> s2; // second stack will hold the digits of the second number,
	LinkedStack<int> s3; // third stack will store the digits of the sum.
	//Algorithm
	//1. Reverse both string if n1<n2
	//2. Add digits from 0th index to end of smaller string
	//take last digit of sum + keep track of carry
	//reverse the result

	string number1, number2;

	cout<<"Enter a very large number:"<<endl;
	cin>>number1;

	cout<<"Enter a very large number:"<<endl;
	cin>>number2;

	cout << "The result is: " << sum(number1,number2);

	return 0;
};

string sum(string number1, string number2){

	if(number1.length() < number2.length()){
		swap(number1, number2);
	}

	string str = "";

	int n1 = number1.length();
	int n2 = number2.length();

	int carry = 0;

	for(int i = (n1-1); i>=0; i--){
		int sum = ((number1[i] - '0') + (number2[i+(n2-n1)] - '0') + carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}
	for (int i=n2-n1-1; i>=0; i--){
	        int sum = ((number2[i]-'0')+carry);
	        str.push_back(sum%10 + '0');
	        carry = sum/10;
	    }

	    if (carry)
	        str.push_back(carry+'0');

	    reverse(str.begin(), str.end());

	    return str;

	    //cout << "The result is: " << str ;
}
