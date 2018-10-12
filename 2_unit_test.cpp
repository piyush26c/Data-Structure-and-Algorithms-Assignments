#include <cstdlib>
#include<iostream>
using namespace std;

static int arr[31];

class u_test {
private:
    string name;
    int marks, roll_no;
    static int count, avg, sum, max, min, absent, present;
public:
    u_test();
    ~u_test();
    void get();
    void put();
    void details();


};

int u_test::count;
int u_test::avg;
int u_test::sum;
int u_test::max = 0;
int u_test::min = 30;
int u_test::absent;
int u_test::present;

u_test::u_test() //CONSTRUCTOR
{
    roll_no = 0;
    marks = -1;
}

u_test::~u_test() //DESTRUCTOR
{

}

void u_test::get() {

    cout << "\nEnter name\t";
    cin>>name;
    cout << "\nEnter roll_no number\t";
    cin>>roll_no;
    cout << "\nEnter Marks\t";
    cin>>marks;
    if (marks < 0)
        absent++;
    else {
        if (marks > max)
            max = marks;
        if (marks < min)
            min = marks;
        sum += marks;
		//arr array of 31 size which denotes marks and on specific location it denotes count of students having that much //marks.
        arr[marks]++;
        present++;
    }
}

void u_test::put() {
    cout << "roll_no number :\t " << roll_no << "\t\t";
    cout << "Name :\t" << name << "\t\t";
    cout << "Marks :\t" << marks << endl;
}

void u_test::details() {
    int i, m = 0, p;
    cout << "\nNo. of student present is         \t" << present;
    avg = sum / present;
    cout << "\nAverage of the present students is\t" << avg;
    for (i = 0; i < 31; i++) {
        if (arr[i] > m) {
            m = arr[i];
            p = i;
        }

    }
    cout << "\nmax marks is                      \t" << max;
    cout << "\nmin marks is                      \t" << min;
    cout << "\n" << p << " Marks are obtained by " << m << "students";
}

int main() //MAIN
{
    int i, c, f;
    char j;
    u_test z[3];
    do {
        cout << "\nENter your choice\n";
        cout << "1. Enter Details \n2. See all the details\n3. Class Analysis\n4. Exit\n";
        cin>>c;

        switch (c) {
                f = 1;
            case 1: //getting input
                for (i = 0; i < 3; i++) {
                    z[i].get();
                }
                break;
            case 2: //displaying output
                for (i = 0; i < 3; i++) {
                    z[i].put();
                }
                break;
            case 3: z[0].details();
                break;
            case 4: f = 0;
                break;

            default:cout << "Incorrect choice";
                break;

        }

    } while (f);
}

