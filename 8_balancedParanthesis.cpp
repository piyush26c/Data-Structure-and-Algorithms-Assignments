
//Programm : To Check Expression Whether it is Containing Balanced Paranthesis or not //
#include<iostream>
#include<cstdlib>
#include<cstring>
#define SIZE 40
using namespace std;

class Check_Paranthesis
{
private:
  char stack[SIZE];
  char exp[SIZE];
  static int top;

public:
  void getParanthesis();
  int isStackEmpty();
  int isStackFull();
  int check();
  int match(char x, char y);
  void push(char);
  char pop();

};
int Check_Paranthesis::top = -1;

void Check_Paranthesis::getParanthesis()
{
  cout << "\nEnter the Expression";
  cin>>exp;

}

int Check_Paranthesis::isStackEmpty()
{
  if (top == -1)
    {
      return 1;
    } else
    {
      return 0;
    }


}

int Check_Paranthesis::isStackFull()
{
  int n = strlen(exp);
  if (top == n - 1)
    {
      return 1;
    } else
    {
      return 0;
    }

}

char Check_Paranthesis::pop()
{
  return stack[top];
}

void Check_Paranthesis::push(char ch)
{
  top = top + 1;
  stack[top] = ch;
}

int Check_Paranthesis::check()
{
  int n = strlen(exp);
  char ch1;
  int flag;
  for (int p = 0; p < n; p++)
    {
      flag = 0;
      if (exp[p] == '(' || exp[p] == '[' || exp[p] == '{')
        {
          if (!isStackFull())
            push(exp[p]);
        }
      if (exp[p] == ')' || exp[p] == ']' || exp[p] == '}')
        {
          if (!isStackEmpty())
            ch1 = pop();
          int y = match(exp[p], ch1);
          return y;

        }
    }

}

int Check_Paranthesis::match(char y, char x)
{
  if (x == '(' && y == ')')
    {
      return 1;

    } else if (x == '[' && y == ']')
    {
      return 1;
    } else if (x == '{' && y == '}')
    {
      return 1;
    } else return 0;

}

int main()
{
  Check_Paranthesis c1;

  c1.getParanthesis();
  int y = c1.check();
  if (y == 1)
    cout << "\nBalanced" << endl;
  else
    cout << "\nNot Balanced" << endl;
  return 0;
}

