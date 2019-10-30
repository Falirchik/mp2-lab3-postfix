#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

class TPostfix {
	string infix;
	string postfix;
public:
	TPostfix() {
		infix = "a+b";
	}
	TPostfix(string str){
		infix = str;
	}
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string ToPostfix();
	double Calculate();				//Ввод переменных, вычисление по постфиксной форме
	bool CheckOper(char elem) {		//проверить оператор?
		char operators[6] = { '(',')','+','-','*','/' };
		for (int i = 0; i < 6; i++)
			if (elem==operators[i])
				return true;
		return false;

	}
	int Priority(char oper) {		//получить приоритет операции
		char operators[4] = { '+','-','*','/' };
		char priority[4] = { 1, 1, 2, 2 };
		for (int i = 0; i < 4; i++)
			if (oper == operators[i])
				return priority[i];
		return -2;
	}
};


#endif