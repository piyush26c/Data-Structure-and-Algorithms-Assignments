//using singly linked list
#include <cstdlib>
#include<iostream>
#include<string.h>
using namespace std;

class pinnacle {
private:
    string name;
    long int prn;
    static int count;
    pinnacle* nn;
    pinnacle* cn;
    pinnacle* next;
    pinnacle*header1;
    pinnacle*header2;
public:
    pinnacle* header;
    pinnacle();
    ~pinnacle();
    void addStudents();
    void deleteStudents();
    void display(pinnacle *cn);
    void addStudentsAtPost();
    void revers(pinnacle*cn);
    void returnc();
    void addList1();
    void addList2();
    void concatenateO_1();
    void concatenate1_2();


};
int pinnacle::count;

pinnacle::pinnacle() {
    name = "NoName";
    prn = -1;
    header = NULL;
    header1 = NULL;
    header2 = NULL;

}

pinnacle::~pinnacle() {

}

void pinnacle::addStudents() {
    char ch;
    cout << "\nFirst Entry For President";
    cout << "\nSecond Entries For Students";
    cout << "\nLast Entry Will Be Of Secretory";


    //for president
    nn = new pinnacle;
    nn->next = NULL;
    cout << "\nEnter The StudentName.  :\t";
    cin >> nn->name;
    cout << "\nEnter The StudentPRN.   :\t";
    cin >> nn->prn;
    nn->next = header;
    header = nn;
    count = count + 1;
    //entry for other students
    do {
        nn = new pinnacle;
        nn->next = NULL;
        cout << "\nEnter The StudentName.  :\t";
        cin >> nn->name;
        cout << "\nEnter The StudentPRN.   :\t";
        cin >> nn->prn;
        if (header == NULL) {
            header = nn;
        }
        cn = header;

        while (cn->next != NULL) {
            cn = cn->next;
        }
        cn->next = nn;
        count = count + 1;
        cout << "\nWant to Continue Y/N";
        cin>>ch;
    } while (ch == 'Y' || ch == 'y');
}

void pinnacle::display(pinnacle *cn) {
    //cn = header;
    cout << "****************************************************************************************" << endl;
    cout << "\tPINNACLE CLUB" << endl;
    cout << "****************************************************************************************" << endl;
    cout << "PRN\tNAME\tPOSITION" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    cout << cn->prn << "\t";
    cout << cn->name << "\t";
    cout << "(PRESIDENT)";
    cout << "\n";
    cn = cn->next;
    while (cn->next != NULL) {
        cout << cn->prn << "  " << "\t";
        cout << cn->name << " " << "\t";
        cout << "(MEMBER)";
        cn = cn->next;
        cout << "\n";
    }
    cout << cn->prn << "\t";
    cout << cn->name << "\t";
    cout << "(SECRETARY)";
    cout << "\n";
}

void pinnacle::deleteStudents() {
    long int z;
    int r;
    int q = 0;
    cout << "\nEnter(1).For To Delete President";
    cout << "\nEnter(2).For To Delete Students";
    cout << "\nEnter(3).For To Delete Secretory";
    cin>>r;
    if (r <= 3 && r >= 1) {
        count = count - 1;
    }
    if (r == 1) {
        cn = header;
        header = cn->next;
    }
    else if (r == 2) {
        long int p;
        cout << "\nEnter The PRN Of Student :\t";
        cin>>p;
        cn = header;
        while ((cn->next)->prn != p) {
            cn = cn->next;
        }
        cn->next = (cn->next)->next;
    } else if (r == 3) {
        cn = header;
        if (header == NULL) {
            header = nn;
        }
        while (cn->next != NULL) {
            if ((cn->next)->next == NULL) {
                cn->next = NULL;
                break;
            }
            cn = cn->next;
        }
    }

}

void pinnacle::returnc() {
    cout << "\nTotal Members Of Club\t" << count;

}

void pinnacle::addStudentsAtPost() {
    int k;
    nn = new pinnacle;
    cout << "\nEnter the Position";
    cin>>k;
    cn = header;

    if (k == 1) {
        nn->next = header;
        header = nn;
        cout << "\nEnter The StudentName.  :\t";
        cin >> nn->name;
        cout << "\nEnter The StudentPRN.   :\t";
        cin >> nn->prn;
        count = count + 1;
    } else {

        for (int i = 1; i < k - 1; i++) {
            cn = cn->next;
        }
        cout << "\nEnter The StudentName.  :\t";
        cin >> nn->name;
        cout << "\nEnter The StudentPRN.  :\t";
        cin >> nn->prn;
        nn->next = cn->next;
        cn->next = nn;
        count = count + 1;
    }
}

void pinnacle::revers(pinnacle *qn) {
    if (qn->next != NULL) {
        revers(qn->next);
    }
    cout << "\nStudentName.  :\t" << qn->name;
    cout << "\nStudentPRN.   :\t" << qn->prn;
    cout << "\n";
}

void pinnacle::addList1() {
    char ch;
    do {
        cout << "\n\tList For Division-1" << endl;
        nn = new pinnacle;
        nn->next = NULL;
        cout << "\nEnter The StudentName.  :\t";
        cin >> nn->name;
        cout << "\nEnter The StudentPRN.  :\t";
        cin >> nn->prn;
        if (header1 == NULL) {
            header1 = nn;
        } else {
            cn = header1;
            while (cn->next != NULL) {
                cn = cn->next;
            }
            cn->next = nn;
        }
        cout << "\nWhether You Have To Continue Y/N";
        cin>>ch;
        count = count + 1;
    } while (ch == 'Y' || ch == 'y');
}

void pinnacle::concatenateO_1() {
    pinnacle *i;
    pinnacle *p;
    if (header == NULL) {
        i = header1;
    }

    if (header1 == NULL) {
        i = header;
    }

    p = header;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = header1;
    i = header;

    while (i) {
        cout << "\nStudentName.  :\t" << i->name;
        cout << "\nStudentPRN.   :\t" << i->prn;
        i = i->next;
    }
}

void pinnacle::concatenate1_2() {
    pinnacle *i;
    pinnacle *p;
    if (header1 == NULL) {
        i = header2;
    }
    if (header2 == NULL) {
        i = header1;
    }
    p = header1;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = header2;
    i = header1;

    while (i) {

        cout << "\nStudentName.  :\t" << i->name;
        cout << "\nStudentPRN.   :\t" << i->prn;
        i = i->next;

    }

}

int main(int argc, char const* argv[]) {
    pinnacle p1, p2, p3;
    int i, q;
    do {
        cout << "\nEnter(1).To Add Students";
        cout << "\nEnter(2). To Display Students";
        cout << "\nEnter(3). To Compute Total Members Of Club";
        cout << "\nEnter(4). To Delete The Student Record";
        cout << "\nEnter(5). To Display Students In Reverse Order";
        cout << "\nEnter(6). To Add Students At Position";
        cout << "\nEnter(7). To Add Students Of Division-1";
        cout << "\nEnter(9).To Display Combined List Of Division Original && 1";
        cout << "\nEnter(11). To Exit\t";
        cin>>i;

        q = 1;
        switch (i) {

            case 1:p1.addStudents();
                break;
            case 2:p1.display(p1.header);
                break;
            case 3:p1.returnc();
                break;
            case 4:p1.deleteStudents();
                break;
            case 5:p2.revers(p1.header);
                break;
            case 6:p1.addStudentsAtPost();
                break;
            case 7:p1.addList1();
                break;
            case 9:p1.concatenateO_1();
                break;
            case 11:q = 0;
                break;
        }

    } while (q);

    return 0;
}
