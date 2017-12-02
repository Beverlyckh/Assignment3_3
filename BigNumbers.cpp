/*
 * BigNumbers.cpp
 *
 *Use a stack to add two large numbers
 *Use
 *  Created on: Nov 21, 2017
 *  Author: Beverly ACKAH
 *
 */

#include "LinkedStack.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	LinkedStack<int> s1; // first stack will hold the digits of the first number,
	LinkedStack<int> s2; // second stack will hold the digits of the second number,
	LinkedStack<int> s3; // third stack will store the digits of the sum.

	string number1, number2;

	cout<<"Enter a very large number:"<<endl;
	cin>>number1;

	cout<<"Enter a very large number:"<<endl;
	cin>>number2;

	// swap number
	if(number1.length() < number2.length()){
		swap(number1, number2);
	}

	// convert and push!
	for (int i= 0; i< number1.length() ; i++){
		char ch = number1[i];
		int value = ch -'0';
		s1.push(value);
	}

	// convert and push!
	for (int i= 0; i< number2.length() ; i++){
		char ch = number2[i];
		int value = ch - '0';
		s2.push(value);
	}

	int carry = 0;
	int sum;

	while(!s1.isEmpty() && !s2.isEmpty()){ //s1 remains the larger stack put back
		int num1 = s1.pop();
		int num2 = s2.pop();
		sum = num1 + num2+ carry;

		//there is a carry
		if(sum > 9){
			int remainder = sum%10;
			s3.push(remainder);
			carry = sum/10;
		}
		else {
			carry =0;
			s3.push(sum);
		}
	}
	if(!s1.isEmpty()){
		while(!s1.isEmpty()){
			int num1 = s1.pop();
			sum = num1 + carry;
			if(sum > 9){
				int remainder = sum%10;
				s3.push(remainder);
				carry = sum/10;
			}
			else {
				carry =0;
				s3.push(sum);
			}
		}
	}
	if(!s2.isEmpty()){
		while(!s2.isEmpty()){
			int num2 = s2.pop();
			sum = num2 + carry;
			if(sum > 9){
				int remainder = sum%10;
				s3.push(remainder);
				carry = sum/10;
			}
			else {
				carry =0;
				s3.push(sum);
			}
		}
	}

	string str = "";

	while(!s3.isEmpty()){
		str += s3.pop() + '0';
	}
	cout << "Sum is:" << str;

	return 0;
};
