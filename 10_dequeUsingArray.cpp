/* 
 * File:   dequeuUsingArray.cpp
 * Author: Piyush
 *
 * Created on September 30, 2018, 3:08 PM
 */

#include <iostream>
#include <cstdlib>
#define SIZE 5
using namespace std;

class DequeUsingArray {
  private:
    int deque[SIZE];

    int item;
  public:
    int front;
    int rear;

    DequeUsingArray() {
        front = -1;
        rear = -1;

    }
    void insertionAtFront(int item);
    void insertionAtEnd(int item);
    void deletionAtFront();
    void deletionAtEnd();
    void displayDeque();


};

void DequeUsingArray::deletionAtEnd() {
    {
        cout << "Deleted Element from End : " << deque[rear];
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = rear - 1;
        }

    }


}

void DequeUsingArray::deletionAtFront() {
    {
        cout << "Deleted Element from Front : " << deque[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = front + 1;
        }

    }


}

void DequeUsingArray::insertionAtEnd(int item) {
    {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = rear + 1;
        }

        deque[rear] = item;
    }

}

void DequeUsingArray::insertionAtFront(int item) {

    {
        if (front == -1) {
            front = 0;


        } else {
            int i = rear;
            while (i >= front) {
                deque[i + 1] = deque[i];
                i--;
            }

        }
        deque[front] = item;
        rear++;

    }

}

void DequeUsingArray::displayDeque() {
    if (front == -1) {
        cout << "\nDeque is Empty";
    } else {
        cout << "\nDeque : ";
        for (int i = front; i <= rear; i++) {
            cout << deque[i] << " ";
        }
    }

}

int main(int argc, char** argv) {

    DequeUsingArray d1;
    int c, val;
    char ch;

    do {
        cout << "\nDeQueue Operations";
        cout << "\n1 : PUSH FROM FRONT";
        cout << "\n2 : PUSH FROM BACK";
        cout << "\n3 : POP  FROM FRONT";
        cout << "\n4 : POP  FROM BACK";
        cout << "\n5 : DISPLAY QUEUE";
        cout << "\nEnter Your Choice :\t";
        cin>>c;
        switch (c) {

            case 1:
                cout << "\nEnter Value :\t";
                cin>>val;
                if (d1.rear > SIZE - 1) {
                    cout << "\nDeque is Full";
                }
                else {
                    d1.insertionAtFront(val);
                }

                break;

            case 2:
                cout << "\nEnter Value :\t";
                cin>>val;
                if (d1.rear > SIZE - 1) {
                    cout << "\nDeque is Full";
                }
                else {
                    d1.insertionAtEnd(val);
                }

                break;
            case 3:
                if (d1.front == -1) {
                    cout << "\nDeque is Empty";
                }
                else {
                    d1.deletionAtFront();
                }

                break;
            case 4:
                if (d1.front == -1) {
                    cout << "\nDeque is Empty";
                }
                else {
                    d1.deletionAtEnd();
                }

                break;
            case 5:
                d1.displayDeque();
                break;
            default:
                cout << "\nInvalid Input";
                break;

        }
        cout << "\nDo You Want To Continue Y/N : ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');



    return 0;
}

