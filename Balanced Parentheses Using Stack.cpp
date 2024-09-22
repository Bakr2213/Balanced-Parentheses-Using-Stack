#include<string>
#include<stack>
#include <iostream>
using namespace std;
bool arePair(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	if (open == '[' && close == ']')
		return true;
	if (open == '{' && close == '}')
		return true;
	return false;
}
bool areBalanced(string exp)
{
    stack<char>s;
	for (size_t i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			s.push(exp[i]);
		else if ((exp[i] == ')' || exp[i] == ']' || exp[i] == '}'))
		{
			if (s.empty() || !arePair(s.top(), exp[i]))
				return false;
			else
				s.pop();
		}
	}
	return s.empty()?true:false;
}
int main()
{
	string expression;
	cout << "enter an expression \n";
	cin >> expression;
	if (areBalanced(expression))
		cout << "Balanced \n";
	else
		cout << "Not Balanced\n";
}
