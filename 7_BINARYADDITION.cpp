
//this program is using doubly linked list.
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

class Binary {
private:
    int bit;
public:
    Binary *nn;
    Binary *cn;
    Binary *header;
    Binary *next;
    Binary *prev;

    void acceptBinary();
    void displayBinary();
    void onesCompliment();
    void towsCompliment();
    void addBinary(Binary b1, Binary b8);

    Binary() {
        header = NULL;
    }

    //Copy constructor

    Binary(Binary &x) {

        Binary *sn;
        sn = x.header;
        nn = new Binary;
        nn->next = NULL;
        nn->prev = NULL;
        nn->bit = sn->bit;
        header = nn;

        sn = sn->next;
        while (sn != NULL) {
            nn = new Binary;
            nn->next = NULL;
            nn->prev = NULL;
            cn = header;
            while (cn->next != NULL) {
                cn = cn->next;
            }
            nn->bit = sn->bit;
            cn->next = nn;
            nn->prev = cn;
            sn = sn->next;
        }
        nn->next = NULL;
    }
};

void Binary::towsCompliment() {
    cn = header;
    while (cn->next != NULL) {
        cn = cn->next;
    }
    while (cn->prev != NULL) {
        if (cn->bit == 0) {
            cn->bit = 1;
            break;
        }
        cn = cn->prev;
    }
}

void Binary::addBinary(Binary b1, Binary b8) {

    int carry = 0, sum = 0;
    Binary *nn;

    Binary *ln1 = b1.header;
    Binary *ln2 = b8.header;
    while (ln1->next != NULL) {
        ln1 = ln1->next;
    }
    while (ln2->next != NULL) {
        ln2 = ln2->next;
    }

    while (ln1 != NULL && ln2 != NULL) {
        sum = (ln1->bit + ln2->bit + carry) % 2;
        carry = (ln1->bit + ln2->bit + carry) / 2;
        ln1 = ln1->prev;
        ln2 = ln2->prev;

        nn = new Binary;
        nn->bit = sum;


        if (header == NULL)
            header = nn;

        else {
            header->prev = nn;
            nn->next = header;
            nn->prev = NULL;
            header = nn;
        }
    }

    while (ln1 != NULL && ln2 == NULL) {
        sum = (ln1->bit + carry) % 2;
        carry = (ln1->bit + carry) / 2;
        nn = new Binary;
        nn->bit = sum;
        if (header == NULL)
            header = nn;
        else {
            header->prev = nn;
            nn->next = header;
            nn->prev = NULL;
            header = nn;
        }
        ln1 = ln1->prev;
    }
    
    while (ln2 != NULL && ln1 == NULL) {
        sum = (ln2->bit + carry) % 2;
        carry = (ln2->bit + carry) / 2;
        nn = new Binary;
        nn->bit = sum;

        if (header == NULL)
            header = nn;
        else {
            header->prev = nn;
            nn->next = header;
            nn->prev = NULL;
            header = nn;
        }
        ln2 = ln2->prev;
    }


    if (carry == 1) {
        nn = new Binary;
        nn->bit = carry;

        if (header == NULL)
            header = nn;

        else {
            header->prev = nn;
            nn->next = header;
            nn->prev = NULL;
            header = nn;
        }
    }
}

void Binary::acceptBinary() {
    int b;
    cout << "\nEnter Number Of Bits Of Binary Number";
    cin>>b;

    for (int i = 0; i < b; i++) {
        nn = new Binary;
        cout << "\nEnter Bit\t";
        cin >> nn->bit;
        nn->next = NULL;
        nn->prev = NULL;
        if (header == NULL) {
            header = nn;
        } else {
            cn = header;
            while (cn->next != NULL) {
                cn = cn->next;
            }
            cn->next = nn;
            nn->prev = cn;
        }
    }
}

void Binary::displayBinary() {
    cn = header;
    do {
        cout << cn->bit << " ";
        cn = cn->next;
    } while (cn != NULL);


}

void Binary::onesCompliment() {

    cn = header;
    while (cn != NULL) {
        if (cn->bit == 0) {
            cn->bit = 1;
        } else {
            cn->bit = 0;
        }
        cn = cn->next;
    }
}

int main() {
    Binary b1, b8, b6;
    //first binary number
    b1.acceptBinary();
    cout << "\n" << "\nOriginal first binary No               :\t";
    b1.displayBinary();
    //2nd binary number
    b8.acceptBinary();
    cout << "\n" << "\nOriginal Second Binary NO              :\t";
    b8.displayBinary();
    //1'scompilment of first binary number
    Binary b2 = b1;
    b2.onesCompliment();
    cout << "\n" << "\none'scompliment of first binary number::\t";
    b2.displayBinary();
    //2'scompliment of first binary number
    Binary b3 = b2;
    b3.towsCompliment();
    cout << "\n" << "\n2 compliment of first binary number   :\t";
    b3.displayBinary();
    //Original Number -1
    cout << "\n" << "\nOriginal first binary number          :\t";
    b1.displayBinary();
    //one's complimemnt of second binary number
    Binary b4 = b8;
    b4.onesCompliment();
    cout << "\n" << "\none's compliment of second binary number:\t";
    b4.displayBinary();
    //2'scompliment of second binary number
    Binary b5 = b4;
    b5.towsCompliment();
    cout << "\n" << "\n2 compliment of second binary number  \t";
    b5.displayBinary();
    //Original Number 2
    cout << "\n" << "\nOriginal second binary number          \t";
    b8.displayBinary();
    //Addition
    cout << "\n" << "\nAddition of two binary number          \t";
    b6.addBinary(b1, b8);
    b6.displayBinary();

    return EXIT_SUCCESS;
}

