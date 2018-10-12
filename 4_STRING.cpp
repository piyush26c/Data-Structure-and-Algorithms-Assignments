#include<iostream>
#include<string.h>
using namespace std;

class stringp {
private:
    char s1[50], s2[50];
    int l1, l2;
public:
    void getString();
    void lengthOfString();
    void copyString1_2();
    void copyString2_1();
    void compareString();
    void concatenateString1_2();
    void concatenateString2_1();
    void alphanumeric();
    void frequencyCount();
    
};

void stringp::getString() {
    cout << "\nEnter the String 1:\t";
    cin>>s1;
    cout << "\nEnter the String 2:\t";
    cin>>s2;

}

void stringp::lengthOfString() {

    for (l1 = 0; s1[l1] != '\0'; l1++);
    cout << "\nLength Of String 1 :\t" << l1;

    for (l2 = 0; s2[l2] != '\0'; l2++);
    cout << "\nLength Of String 2 :\t" << l2;
}

void stringp::copyString2_1() {
    int i;
    for (i = 0; s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    cout << "\nString1\t";
    for (i = 0; s1[i] != '\0'; i++) {
        cout << s1[i];
    }
    cout << "\n";
}

void stringp::frequencyCount() {
    char s5[50];
    char ch, c;
    int i, j;
    int ct;

    int t;
    for (t = 0; s1[t] != '\0'; t++) {
        s5[t] = s1[t];
    }
    s5[t] = '\0';
    //Sorting Characters in ascending manner.....
    int min;
    int temp;
    for (i = 0; i < l1; i++) {
        min = i;
        for (j = i + 1; j < l1; j++) {
            if (s5[min] > s5[j]) {
                min = j;
            }
        }

        temp = s5[i];
        s5[i] = s5[min];
        s5[min] = temp;
    }

    //counter     
    for (i = 0; s5[i] != '\0'; i = i + ct) {
        ct = 1;
        for (j = (i + 1); s5[j] != '\0'; j++) {
            if (s5[i] == s5[j]) {
                ct = ct + 1;
            }

        }
        cout << "\nCount:\t" << s5[i] << "\t" << ct;

    }

}

void stringp::copyString1_2() {
    int i;
    for (i = 0; s1[i] != '\0'; i++) {
        s2[i] = s1[i];
    }
    s2[i] = '\0';
    cout << "\nString2\t";
    for (i = 0; s2[i] != '\0'; i++) {
        cout << s2[i];
    }
    cout << "\n";
}

void stringp::compareString() {
    int j, flag;
    for (j = 0; s1[j] != '\0' && s2[j] != '\0'; j++) {
        flag = 1;
        if (s1[j] != s2[j]) {
            flag = 0;
        }
    }
    if (flag == 0) {
        cout << "\nEntered Strings Are Equal";
    } else {
        cout << "\nEntered Strings Are Not Equal\n";
    }
}

void stringp::concatenateString1_2() {
    int k, i, j;
    i = 0;
    while (s1[i] != '\0') {
        i++;
    }
    j = 0;
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i = i + 1;
        j = j + 1;
    }
    s1[i] = '\0';
    for (k = 0; s1[k] != '\0'; k++) {
        cout << s1[k];
    }


    cout << "\n";

}

void stringp::concatenateString2_1() {
    int k, i, j;
    i = 0;
    while (s2[i] != '\0') {
        i++;
    }
    j = 0;
    while (s1[j] != '\0') {
        s2[i] = s1[j];
        i = i + 1;
        j = j + 1;
    }
    s2[i] = '\0';
    for (k = 0; s2[k] != '\0'; k++) {
        cout << s2[k];
    }


    cout << "\n";


}

void stringp::alphanumeric() {
    char s5[30];
    int i = 0;
    int l3;
    cout << "\nEnter the String :\t";
    cin>>s5;


    // for(l3=0;s5[l3]!='\0';l3++);

    for (int p = 0; s5[p] != '\0'; p++) {
        if ((s5[p] > 65 && s5[p] < 90) || (s5[p] > 97 && s5[p] < 122)) {

            cout << s5[p];

        }


    }


}

int main() {
    stringp p, q, r, s, t, N;
    int a, b;
    do {
        a = 1;
        cout << "\nEnter (1).For To Enter String1 And String2";
        cout << "\nEnter (2).For ToCalculate Length Of String1 And String2";
        cout << "\nEnter (3).For ToCopy String2 Into String1";
        cout << "\nEnter (4).For ToCopy String1 Into String2";
        cout << "\nEnter (5).For ToCompare String1 And String2";
        cout << "\nEnter (6).For ToConCatenate String2 After String1";
        cout << "\nEnter (7).For ToConCatenate String1 After String2";
        cout << "\nEnter (8).For ToCheck Alphanumeric";
        cout << "\nEnter (9).For ToCheck Alphanumeric";
        cout << "\nEnter (10).For To Exit\t";
        cin>>b;

        switch (b) {
            case 1:p.getString();
                break;
            case 2:p.lengthOfString();
                q = p;
                r = p;
                s = p;
                break;
            case 3: p.copyString2_1();
                break;
            case 4:
                q.copyString1_2();
                break;
            case 5: p.compareString();
                break;
            case 6:
                r.concatenateString1_2();
                break;
            case 7:
                s.concatenateString2_1();
                break;

            case 8:
                t.alphanumeric();
                break;
            case 9:
                N.frequencyCount();
                break;

            case 10:a = 0;
                break;
        }

    } while (a);




    return 0;
}

