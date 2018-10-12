#include <cstdlib>
#include<iostream>
using namespace std;

//tp = touple matrix;
//add = added matrix;
//ft = fast matrix;
class matrix {
    int r, c, i, j, k, n, d, e;
    int arr[30][30], tp[30][30], add[30][30], mt[30][30], ft[30][30];

public:
    matrix();
    ~matrix();
    void get();
    void disp();
    void touple();
    void dispt();
    void addition(matrix m1, matrix m2);
    void transpose(matrix m);
    void fasttranspose(matrix mt);
};

int main() //MAIN FUNCTION//
{
    matrix m1, m2, m3;

    cout << "\nINPUT FIRST MATRIX M1" << endl;
    m1.get();
    cout << "\nSPARSE FIRST MATRIX M1" << endl;
    m1.disp();
    //CALCUTE TOUPLE MATRIX-1//
    m1.touple(); 
    cout << "\nTOUPLE MATRIX M1" << endl;
    m1.dispt();     
    cout << "\nINPUT SECOND MATRIX M2" << endl;
    m2.get();
    cout << "\nSIMPLE SECOND  MATRIX M2" << endl;
    m2.disp();
    //CALCUTE TOUPLE MATRIX-2//
    m2.touple();
    cout << "\nTOUPLE MATRIX M2" << endl;
    m2.dispt(); 
    //ADDITION MATRIX
    cout << "\nADDITION MATRIX M1 + M2" << endl;
    m3.addition(m1, m2);
    cout << "\nTRANSPOSE(BY SIMPLE) MATRIX M1" << endl;
    m3.transpose(m1);
    cout << "\nTRANSPOSE(BY SIMPLE) MATRIX M2" << endl;
    m3.transpose(m2);
    cout << "\nTRANSPOSE (FAST METHOD)MATRIX M1" << endl;
    m3.fasttranspose(m1);
    cout << "\nTRANSPOSE (FAST METHOD)MATRIX M2" << endl;
    m3.fasttranspose(m2);
    return 0;
}

matrix::matrix() {
    r = 0;
    c = 0;
}

matrix::~matrix() {

}

void matrix::get() {
    cout << "\nENTER NUMBER OF ROWS\t";
    cin>>r;

    cout << "\nENTER NUMBER OF COLOUMS\t";
    cin>>c;
    cout << "\nENTER ELEMENTS";
    cout << "\nORDER : arr[" << r << "][" << c << "]";
    for (i = 0; i < r; i++) {
        cout << "\nENTER VALUES FOR" << i << "ROW\n";
        for (j = 0; j < c; j++) {
            cin >> arr[i][j];

        }

    }

}

void matrix::disp() {
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cout << arr[i][j] << "\t";
        }

        cout << "\n";
    }

}

void matrix::touple() //CALCULATION OF TOUPLE MATRIX//
{

    n = 1;
    tp[0][0] = r;
    tp[0][1] = c;


    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (arr[i][j] != 0) {
                tp[n][0] = i;
                tp[n][1] = j;
                tp[n][2] = arr[i][j];
                n = n + 1;
            }
        }

    }
    tp[0][2] = n - 1; //NUMBER OF TERMS IN TOUPLE MATRIX//
}

void matrix::dispt() {
    cout << "\nTRIPLET MATRIX :\n";

    for (i = 0; i < (n); i++) {
        for (j = 0; j < 3; j++) {
            cout << tp[i][j] << "\t";
        }
        cout << "\n";
    }
}

void matrix::addition(matrix m1, matrix m2) //ADDITION //	
{
    //checking condition that column and row quantity should be equal
    if ((m1.tp[0][0] == m2.tp[0][0]) && (m1.tp[0][1] == m2.tp[0][1])) {
        i = 1;
        j = 1;
        k = 1;
        //adding column and row numbers to added matrix array
        add[0][0] = m1.tp[0][0];
        add[0][1] = m1.tp[0][1];
        //tracing each element of both matrix
        while ((i <= m1.tp[0][2]) && (j <= m2.tp[0][2])) {
            //checking if rows of both matrix are same
            if ((m1.tp[i][0]) == (m2.tp[j][0])) {
                //checking if row as well as column numbers are also same
                if ((m1.tp[i][1]) == (m2.tp[j][1])) {
                    add[k][0] = m1.tp[i][0];
                    add[k][1] = m1.tp[i][1];
                    add[k][2] = m1.tp[i][2] + m2.tp[j][2];
                    i = i + 1;
                    j = j + 1;
                    k = k + 1;
                }                  
                //if no then put that matrix which is having lesser row th number in addition matrix
                else if ((m1.tp[i][1])<(m2.tp[j][1])) {
                    add[k][0] = m1.tp[i][0];
                    add[k][1] = m1.tp[i][1];
                    add[k][2] = m1.tp[i][2];
                    i = i + 1;
                    k = k + 1;
                } else if (m1.tp[i][1] > m2.tp[j][1]) {
                    add[k][0] = m2.tp[i][0];
                    add[k][1] = m2.tp[i][1];
                    add[k][2] = m2.tp[i][2];
                    j = j + 1;
                    k = k + 1;
                }
            }                
            //when row index are not same then put first lesser number index matrix in addition matrix
            else if ((m1.tp[i][0])<(m2.tp[j][0])) {
                add[k][0] = m1.tp[i][0];
                add[k][1] = m1.tp[i][1];
                add[k][2] = m1.tp[i][2];
                i = i + 1;
                k = k + 1;
            } else if (m1.tp[i][0] > m2.tp[j][0]) {
                add[k][0] = m2.tp[j][0];
                add[k][1] = m2.tp[j][1];
                add[k][2] = m2.tp[j][2];
                j = j + 1;
                k = k + 1;
            }
        }

        //this occurs when number of elements in matrix-1 is greater than matrix-2
        while (i <= (m1.tp[0][2])) {
            add[k][0] = m1.tp[i][0];
            add[k][1] = m1.tp[i][1];
            add[k][2] = m1.tp[i][2];
            i = i + 1;
            k = k + 1;
        }
        //this occurs when number of elements in matrix-2 is greater than matrix-1
        while (j <= (m2.tp[0][2])) {
            add[k][0] = m2.tp[j][0];
            add[k][1] = m2.tp[j][1];
            add[k][2] = m2.tp[j][2];
            j = j + 1;
            k = k + 1;
        }

        add[0][2] = k; //NUMBER OF TERMS IN ADDITION MATRIX//


    } else {
        cout << "\nADDITION IS NOT POSSIBLE" << endl;
    }


    cout << "\nADDTION MATRIX : \n";

    for (i = 0; i < k; i++) {
        for (j = 0; j < 3; j++) {
            cout << add[i][j] << "\t";
        }
        cout << "\n";
    }

}

void matrix::transpose(matrix m) // SIMPLE TRANSPOSE CALCULATION//
{
    e = 0;
    //copying number of row th and column th elements in transpose ki touple matrix
    mt[0][0] = m.tp[0][1];
    mt[0][1] = m.tp[0][0];
    mt[0][2] = m.tp[0][2];

    if (e <= m.tp[0][2]) {
        for (i = 0; i < (m.tp[0][1]); i++) {
            for (d = 0; d <= (mt[0][2]); d++) {
                if (m.tp[d][1] == i) {
                    mt[e + 1][0] = m.tp[d][1];
                    mt[e + 1][1] = m.tp[d][0];
                    mt[e + 1][2] = m.tp[d][2];
                    e = e + 1;
                }

            }
            if (e > m.tp[0][2])
                break;

        }
    }

    cout << "\nTRANSPOSE MATRIX\n";
    for (i = 0; i <= e; i++) {
        for (j = 0; j < 3; j++) {
            cout << mt[i][j] << "\t";
        }
        cout << "\n";
    }

}

void matrix::fasttranspose(matrix mt) {
    ft[0][0] = mt.tp[0][1];
    ft[0][1] = mt.tp[0][0];
    ft[0][2] = mt.tp[0][2];

    int rterms[mt.tp[0][1]], rpos[mt.tp[0][1]];

    for (i = 0; i < mt.tp[0][1]; i++) //making rterms 0//
    {
        rterms[i] = 0;
    }

    for (i = 1; i <= mt.tp[0][2]; i++) //calculation of rterms array//
    {
        rterms[mt.tp[i][1]]++;
    }
    
    
    rpos[0] = 1; //AS ROW WILL HAVE POSITION 1//
    for (i = 1; i < mt.tp[0][1]; i++) //CALCULATION OF POSITION OF ROW//
    {
        rpos[i] = rpos[i - 1] + rterms[i - 1];
    }

    for (i = 1; i <= mt.tp[0][2]; i++) {

        j = rpos[mt.tp[i][1]];
        ft[j][0] = mt.tp[i][1];
        ft[j][1] = mt.tp[i][0];
        ft[j][2] = mt.tp[i][2];
        rpos[mt.tp[i][1]]++;
    }


    cout << "\n FAST TRANSPOSE MATRIX\n";
    for (i = 0; i <= mt.tp[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            cout << ft[i][j] << "\t";
        }
        cout << "\n";
    }

}
