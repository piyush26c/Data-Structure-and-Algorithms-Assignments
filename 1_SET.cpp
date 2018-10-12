#include <cstdlib>
#include<iostream>
using namespace std;

class set {
private:
   int r, roll[30], i, j, h, z;
public:
    set();
    ~set();
    void get();
    void disp();
    void union_s(set cric, set bad);
    void intersection(set cric, set bad);
    void diff(set cric, set bad);
    void ncnb(set univ, set uni);

};

set::set() {
    r = -1;
}

set::~set() {

}

void set::get() {
    cout << "\nENTER TOTAL STUDENTS";
    cin>>r;
    cout << "\nENETER THEIR ROLL NO.";
    for (i = 0; i < r; i++)
        cin >> roll[i];
}

void set::disp()
 {
    cout << "\nTOTAL STUDENTS";
    cout << "{";
    for (i = 0; i < r - 1; i++) {
        cout << roll[i] << ",";
    }
    cout << roll[i];
    cout << "}" << endl;
}

void set::union_s(set cric, set bad) {
    int flag;

	//first entering all students palying cricket.
    h = 0;
    for (i = 0; i < cric.r; i++) {
        roll[h] = cric.roll[i];
        h++;
    }

	//after then students only palying badmintoon are taken into consideration in below section
    for (i = 0; i < bad.r; i++) {
        flag = 0;
        for (j = 0; j < cric.r; j++) {
            if (bad.roll[i] == cric.roll[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            roll[h] = bad.roll[i];
            h++;
        }
    }
	
	//dispaly
    cout << ".\t{";
    for (i = 0; i < h - 1; i++) {
        cout << roll[i] << ",";
    }
    cout << roll[i];
    cout << "}" << endl;
   //important as it updates the count of total students in union object.
    r = h;


}

void set::intersection(set cric, set bad) {
    int g = 0;
    for (i = 0; i < cric.r; i++) {
        for (j = 0; j < bad.r; j++) {
            if (cric.roll[i] == bad.roll[j]) {
                roll[g] = bad.roll[j];
                g++;
            }
        }

    }
	//dipaly
    cout << ".\t{";
    for (i = 0; i < g - 1; i++) {
        cout << roll[i] << ",";
    }
    cout << roll[i];
    cout << "}" << endl;

}

//as this method can be used in two ways as by first passing respective objects i.e : first cricket and second badmintoon  & 
//second way to use this methaod is to secd first badmintoon object and then cricket object.
//as pattern is like this  :- case 1 : badmintoon - cricket & case 2 : cricket - badmintoon; 
void set::diff(set cric, set bad) {
    int c;
    int flag;
    r = cric.r;
    c = bad.r;
    int m = 0;

	 
    for (i = 0; i < r; i++) {
        flag = 0;
        for (j = 0; j < c; j++) {
            if (cric.roll[i] == bad.roll[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            roll[m] = cric.roll[i];
            m++;
        }
    }
	//display

    cout << ".\t{";
    for (i = 0; i < m - 1; i++) {
        cout << roll[i] << ",";
    }
    cout << roll[i];
    cout << "}" << endl;

}

//passing first universal object and then union object , Logic :- universal - Union
void set::ncnb(set univ, set uni) {
    int flag = 0;
    z = 0;
    for (i = 0; i < univ.r; i++) {
        flag = 0;
        for (j = 0; j < uni.r; j++) {
            if (univ.roll[i] == uni.roll[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            roll[z] = univ.roll[i];
            z++;
        }
    }

    cout << ".\t{";
    for (i = 0; i < z - 1; i++) {
        cout << roll[i] << ",";
    }
    cout << roll[i];
    cout << "}" << endl;

}

int main() {
    int u;
    int g;
    char ch;
    do {
        set cricket, badminton, uni, intersectioon, difference, NCNB, total;
        cout << "Enter total number of students playing games:\n";
        total.get();
        cout << "Enter students playing cricket:\n";
        cricket.get();
        cout << "Enter students playing badminton:\n";
        badminton.get();
        cout << "Total students playing games are:\n";
        total.disp();
        cout << "Students playing cricket are:\n";
        cricket.disp();
        cout << "Students playing badminton are:\n";
        badminton.disp();


        cout << "Enter from the the following choice:\n\t1.Union\n\t2.Intersection\n\t3.Only Cricket\n\t4.Only Badminton\n\t5.No games." << endl;

        for (int u = 0; u < 5; u++) {
            cin>>g;
            switch (g) {
                case 1:cout << "Students playing cricket or badminton or both are:\n";
                    uni.union_s(cricket, badminton);
                    break;
                case 2:cout << "Students playing cricket and badminton are:\n";
                    intersectioon.intersection(cricket, badminton);
                    break;
                case 3:cout << "Students playing only cricket are:\n";
                    difference.diff(cricket, badminton);
                    break;
                case 4:cout << "Students playing only badminton are:\n";
                    difference.diff(badminton, cricket);
                    break;
                case 5:cout << "Students playing no games are:\n";
                    NCNB.ncnb(total, uni);
                    break;
            }
        }
        cout << "\nWHETHER YOU WANT TO CONTINUE";
        cin>>ch;

    } while (ch == 'Y' || ch == 'y');
}
