

#include <iostream>
#include <cstdlib>
#define SIZE 5
using namespace std;

class PizzaQueue
{

  struct Queue
  {
    int queue[SIZE];
    int front;
    int rare;
  } q;

public:

  PizzaQueue()
  {
    q.front = -1;
    q.rare = -1;
  }

  void display();
  void accept(int item);
  int queEmpty();
  int queFull();
  void ready();
};

int PizzaQueue::queEmpty()
{
  if (q.front == -1)
    return 1;
  else
    return 0;

}

int PizzaQueue::queFull()
{
  if (q.front == (q.rare + 1) % SIZE)
    return 1;
  else
    return 0;
}

void PizzaQueue::display()
{
  int i;
  i = q.front;

  while (i != q.rare)
    {
      cout << q.queue[i] << "\t";
      i = (i + 1) % SIZE;
    }
  cout << q.queue[i];
}

void PizzaQueue::accept(int item)
{
  if (q.front == -1)
    {
      q.rare = q.front = 0;
      q.queue[q.rare] = item;
    } else
    {
      if (q.rare != (SIZE - 1))
        {
          q.rare = (q.rare + 1) % SIZE;
          q.queue[q.rare] = item;
        } else
        cout << "\nSoory.....No More Orders Are To Be Taken!!!";

    }

}

void PizzaQueue::ready()
{
  if (q.front != q.rare)
    {
      q.front = (q.front + 1) % SIZE;
      cout << q.queue[q.front - 1];

    } else
    cout << "\nNo Orders Are Ready Except last order" << q.queue[q.front];

}

int main()
{
  PizzaQueue p1;
  int s, d, o;
  //p1.q.front;
  do
    {
      d = 1;
      cout << "\nEnter(1).ToAccept";
      cout << "\nEnter(2).Ready";
      cout << "\nEnter(3).Display";
      cin>>s;

      switch (s)
        {
          case 1:
            cout << "\nEnter the order value::\t";
            cin>>o;
            p1.accept(o);
            break;
          case 2:
            p1.ready();
            break;

          case 3:
            p1.display();
            break;

          case 4: d = 0;
            break;
        }

    } while (d);

};







