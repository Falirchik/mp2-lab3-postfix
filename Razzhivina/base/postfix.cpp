#include "postfix.h"
#include "stack.h"

string TPostfix::ToPostfix()
{
	postfix = "";
	TStack<char> operStack(MaxStackSize);
	for (int i = 0; i < infix.length(); i++)
	{
		if (CheckOper(infix[i])){
			if ( infix[i] == '(' || infix[i] == ')') {				//наткнули на скобку
				if (infix[i] == '(')								//если открывающая
					operStack.Push(infix[i]);						//кладем в стек операций
				else{
					while (operStack.Get() != '(')					//иначе пока не открывающая
						postfix.push_back(operStack.Pop());			//кладем в postfix вытащенный из стека операций
					operStack.Pop();								
				}
			}
			else{													//если не скобки
				if (operStack.Empty())								//если пустой -> добавить
					operStack.Push(infix[i]);
				else{												//приоритет последнего в стеке больше приоритета в постфиксе
																	//и последний в стеке '(' или ')'
																	//и стек не пуст
					while ((Priority(operStack.Get()) >= Priority(infix[i])) && operStack.Get() != '(' && operStack.Get() != ')' && !operStack.Empty())
						postfix.push_back(operStack.Pop());			//в конец постфикса последний из стека операций
					operStack.Push(infix[i]);						
				}
			}
		}
		else
			postfix.push_back(infix[i]);
	}
	while (!operStack.Empty())										//пока стек не пуст
		postfix.push_back(operStack.Pop());							//вытаскиваем из стека в постфикс
	return postfix;
}

double TPostfix::Calculate()
{
	const int N = 100;
	TStack<double> values(N);
	string elem = "";
	bool flag = true;
	double value[N];
	double _elem = 0;
	const double n = 0;
	double res = 0;
	for (int i = 0; i < postfix.length(); i++)
	{
		if (CheckOper(postfix[i]))
		{
			res = values.Pop();
			if (values.Empty())
				values.Push(n);
			if (postfix[i] == '+')
				res += values.Pop();
			if (postfix[i] == '-')
				res = values.Pop() - res;
			if (postfix[i] == '*')
				res = res * values.Pop();
			if (postfix[i] == '/')
			{
				if (res == 0)
					throw "делеие на ноль";
				res = values.Pop() / res;
			}
			values.Push(res);
		}
		else //инициализация без повторения введенных параметров
		{
			for (int q = 0; q <elem.length(); q++)
			{
				if (postfix[i] == elem[q])
				{
					values.Push(value[q]);
					flag = false;
				}
			}
			if (flag)
			{
				cout << "Введите величину: " << postfix[i] << endl;
				cin >> _elem;
				elem.push_back(postfix[i]);
				value[elem.length() - 1] = _elem;
				values.Push(_elem);
			}
			flag = true;
		}
	}
	return values.Pop();
}