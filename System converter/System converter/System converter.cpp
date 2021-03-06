// System converter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

long long From10To2(int a) { //перевод из 10й в 2ю
	int c, e;
	long long d;// так как Д может быть довольно большим
	c = 2;
	e = 1;
	vector <int> num1;
	while ((c != 0) && (c != 1)) {
		c = a / 2;
		d = a % 2;
		num1.push_back(d);
		a = c;
		e = e + 1;
	}
	num1.push_back(c);//получаем массив в виде двоичного числа наоборот
	d = 0;
	for (int i = 0; i < e; i++) {//переводим массив в число
		d = d * 10;
		d = num1[e - i -1] + d;
	}
	return(d);
}
int From2To10(long long a) {
	int c, e, d;
	e = 0;
	d = 0;
	while (a / 10 != 0) {
		c = a % 10;
		a = (a - c) / 10;
		d = d +  c * pow(2, e);
		e = e + 1;
	}
	d = d + (a % 10) * pow(2, e);
	return (d);
}
long long From8To2(int a) {
	long long d;
	int c, e, f;
	e = 0;
	vector <int> num;
	while (a != 0) {
		c = a % 10;
		for (int i = 0; i < 3; i++) {
			d = c % 2;
			c = c / 2;
			num.push_back(d);
		}
		c = a % 10;
		a = (a - c) / 10;
		e = e + 3;
	}
	d = 0;
	for (int i = 0; i < e; i++) {
		d = d * 10;
		d = num[e - i - 1] + d;
	}
	return(d);
}
int From2To8(long long a) {
	int c, e, d, f;
	e = 0;
	f = 0;
	while (a != 0) {
		c = a % 1000;
		d = 0;
		for (int i = 0; i < 3; i++) {
			d = d + (c % 10) * pow(2, i);
			c = (c - c % 10) / 10;
		}
		f = f + d * pow(10, e);
		e = e + 1;
		a = (a - a % 1000) / 1000;
	}
	return (f);
}
long long From16To2(string a) {
	char c;
    unsigned long long d;
	int e, f, g;
	e = 0;
	vector <int> num2;
	for (int i = 0; i < size(a); i++) {
		c = a[size(a) - i - 1];
		if ((int(c) >= 65) && (int(c) <= 70)) {
			g = int(c) - 55;
			for (int i = 0; i < 4; i++) {
				f = g % 2;
				g = g / 2;
				num2.push_back(f);
			}
		}else if ((int(c) >= 48) && (int(c) <= 57)) {
			g = int(c) - 48;
			for (int i = 0; i < 4; i++) {
				f = g % 2;
				g = g / 2;
				num2.push_back(f);
			}
		}else {
			cout << "bad number input error" << endl;
			return 0;
		}
		e = e + 4;
	}
	d = 0;
	for (int i = 0; i < e; i++) {
		d = d * 10;
		d = num2[e - i - 1] + d;
	}
	return(d);
}
string From2To16(long long a) {
	string s = "";
	string s1 = "";
	char k;
	int c, e, d, f;
	e = 0;
	f = 0;
	while (a != 0) {
		c = a % 10000;
		d = 0;
		for (int i = 0; i < 4; i++) {
			d = d + (c % 10) * pow(2, i);
			c = (c - c % 10) / 10;
		}
		if ((d >= 0) && (d <= 9)) {
			k = char(d + 48);
		}
		else {
			k = char(d + 55);
		}
		s = s + k;
		a = (a - a % 10000) / 10000;
	}
	for (int i = 0; i < size(s); i++) {
		s1 = s1 + s[size(s) - i - 1];
	}
	return (s1);
}

int main()
{
	//int value = numeric_limits<int>::max();
	//long long result = From10To2(value);
	//cout << result;
	//return 0;
	double a;
	long long k;
	string command;
	
	cout << " <1> means converting from 10 system to 2 system" << endl;
	cout << " <2> means converting from 2 system to 10 system" << endl;
	cout << " <3> means converting from 8 system to 2 system" << endl;
	cout << " <4> means converting from 2 system to 8 system" << endl;
	cout << " <5> means converting from 10 system to 8 system" << endl;
	cout << " <6> means converting from 8 system to 10 system" << endl;
	cout << " <7> means converting from 2 system to 16 system" << endl;
	cout << " <8> means converting from 16 system to 2 system" << endl;
	cout << " <9> means closing the program" << endl;
	
	do {
		cout << "Choose your destiny:   ";
		cin >> command;

		if (command == "8") {
			string m;
			cout << "and then input your number with less than 5 chars   ";
			cin >> m;
			if (size(m) > 4) {
				cout << "Please inter a string with less than 5 chars" << endl;
				continue;
			}
			cout << "The result is " << From16To2(m) << endl;
			continue;
		}
		if (command == "9") {
			break;
		}
		cout << "and then input your number less than 10^6 in 10 system  ";
		cin >> a;//делаем все через функции для большей наглядности
		
		if (a - trunc(a) > 0) {
			cout << "error please input integer number" << endl;
			continue;
		}
		else if (a < 0) {
			cout << "error please input positive number" << endl;
			continue;
		}
		if (command == "1" || command == "3" || command == "5"|| command == "6"){
			if (a > pow(10, 6)) {
				cout << "please input a number less than 10^6" << endl;
				continue;
			}
		}else if (command == "2" || command == "4" || command == "7") {
			k = From2To10(a);
			if (k > pow(10, 6)) {
				cout << "please input a number less than 10^6 in 10 system" << endl;
				continue;
			}
		}
		
		if (command == "1") {
			k = From10To2(a);

		}
		else if (command == "2") {
			k = From2To10(a);

		}
		else if (command == "3") {
			k = From8To2(a);
		}
		else if (command == "4") {
			k = From2To8(a);
		}
		else if (command == "5") {
			a = From10To2(a);
			k = From2To8(a);
		}
		else if (command == "6") {
			a = From8To2(a);
			k = From2To10(a);
		}
		else if (command == "7") {
			cout << "The result is " << From2To16(a) << endl;
			continue;
		}
		else {
			cout << "bad command input error";
		}
		cout << "The result is " << k << endl;
	} while (1);
	cout << "Goodbye!" << endl;
	return 0;

}

