
//using Doubly Circular Linked List.
/*
#include<iostream>
#include <cstdlib>
using namespace std;

class Theater {
private:

public:
    Theater *header;
    Theater *prev;
    Theater *nn;
    Theater *next;
    Theater *cn;
    char status;
    string name;

    void insert();
    void display();
    void bookSeat(int x);
    void cancelBooking(int y);


};

void Theater::insert() {
    header = NULL;

    for (int j = 0; j < 7; j++) {
        nn = new Theater;
        nn->status = 'A';
        nn->next = NULL;
        nn->prev = NULL;
        if (header == NULL) {
            header = nn;
            nn->next = header;
            nn->prev = header;
        } else {
            cn = header;
            while (cn->next != header) {
                cn = cn->next;
            }
            cn->next = nn;
            nn->prev = cn;
            nn->next = header;
            header->prev = nn;
        }
    }
}

void Theater::display() {
    cn = header;
    do {
        cout << cn->status << "\t";
        cn = cn->next;
    } while (cn != header);
    cout << "\n";
} 

void Theater::bookSeat(int x) {
    cn = header;
    for (int p = 1; p < x; p++) {
        cn = cn->next;
    }
    if (cn->status == 'B') {
        cout << "Sorry this seat is already booked";
    } else {
        cn->status = 'B';
    }
}

void Theater::cancelBooking(int y) {
    cn = header;
    for (int p = 1; p < y; p++) {
        cn = cn->next;
    }

    if (cn->status == 'A') {
        cout << "Already this seat is not booked";
    } else {
        cn->status = 'A';
    }
}

int main() {
    Theater t[10];
    int q;
    int y;
    int row, seat;

    do {
        y = 1;
        cout << "\nEnter(1).For To Watch Available Seats";
        cout << "\nEnter(2).For To Book Seats";
        cout << "\nEnter(3).For To Cancel Booking";
        cout << "\nEnter(4).For To Exit";
        cin>>q;
        switch (q) {
            case 1:
                for (int i = 0; i < 10; i++) {
                    t[i].insert();
                }
                for (int i = 0; i < 10; i++) {
                    t[i].display();
                }
                break;

            case 2:
                cout << "Enter which seat you want to book(Row no & seat no)";
                cin >> row>>seat;
                if (row > 10 || row < 0 || seat > 7 || seat < 0) {
                    cout << "Invalid Choice";
                }
                t[row - 1].bookSeat(seat);
                //display after booking
                for (int i = 0; i < 10; i++) {
                    t[i].display();
                }
                break;
                
            case 3:
                cout << "Enter which seat you want to cancel(Row no & seat no)";
                cin >> row>>seat;
                if (row > 10 || row < 0 || seat > 7 || seat < 0) {
                    cout << "Invalid Choice";
                }
                t[row - 1].cancelBooking(seat);
                for (int i = 0; i < 10; i++) {
                    t[i].display();
                }
                break;

            case 4:y = 0;
                break;

        }
    } while (y);

}

*/

//another way to program;
#include <iostream>
using namespace std;

//doubly circular ll

class Theater
{
	private:
		char status;
		Theater *cn;
		Theater *nn;
		Theater *next;
		Theater *prev;
		Theater *header;
		
	public:
		Theater();
		void insert();
		void book(int x);
		void cancelBooking(int y);
		void display();
};

Theater::Theater()
{
	header=NULL;
	next=NULL;
	prev=NULL;
}

void Theater::insert()
{
	for(int p=1;p<=7;p++)
	{
		nn=new Theater;
		nn->status='A';
	
	
		if(header==NULL)
		{
			header=nn;
			nn->next=header;
			nn->prev=header;
			header->prev=nn;
		}
		else
		{
			cn=header;
			while(cn->next!=header)
			{
				cn=cn->next;
			}
			cn->next=nn;
			nn->prev=cn;
			nn->next=header;
			header->prev=nn;
		}
	
	}
	
	
	
}

void Theater::book(int x)
{
	Theater *sn;
	sn=header;
	for(int a=1;a<x;a++)
	{
		sn=sn->next;
	}
	if(sn->status=='B')
	{
		cout<<"\nSoory Sir/Maam this Seat is Already Booked\n";
	}
	else
	{
		sn->status='B';
	}
}

void Theater::cancelBooking(int y)
{
	Theater *sn;
	sn=header;
	for(int a=1;a<y;a++)
	{
		sn=sn->next;
	}
	if(sn->status='A')
	{
		cout<<"\nThis Seat is Available u can't cancel it\n\n";
	}
	else
	{	
		sn->status='A';
	}



}
void Theater::display()
{
	cn=header;
	//cout<<cn->status<<"\t";
		do
		{
			cout<<cn->status<<"\t";
			cn=cn->next;
		}while(cn!=header);
		cout<<"\n";

}

int main()
{
	Theater t[10];
	int row,seat;
	int g;//for switch case
	int k;//for do while loop
	
	do
	{
		k=1;
		cout<<"\nEnter(1).To See the Available Seats";
		cout<<"\nEnter(2).To Book the Seats";
		cout<<"\nEnter(3).To Cancel the Booked the Seats";
		cout<<"\nEnter(4).To Exit";
		cin>>g;
		
		switch(g)
		{
			case 1:
				//showing availabili
  cout<<"\n****************************P .V .R***************************"<<endl;
				for(int u=0;u<10;u++)
				{
					t[u].insert();
				}
				for(int y=0;y<10;y++)
				{
					t[y].display();
				}
				
			break;
			
			case 2:
				//for booking
				cout<<"\nEnter the row and seat number you to book"<<endl;
				int y;
				do
				{
					y=0;
					cout<<"\nRow  :\t";
					cin>>row;
					if(row<1||row>10)
					{
						cout<<"\n!!!!Invalid Row Input!!!!\n";
						cout<<"\nEnter Again :\t";
						y=1;
					}
				}while(y);
				
				do
				{
					y=0;
					cout<<"\nSeat :\t";
					cin>>seat;
					if(seat<1||seat>7)
					{
						cout<<"\n!!!!Invalid Seat Input!!!!\n";
						cout<<"\nEnter Again :\t";
						y=1;
					}
				}while(y);
				
				
				
	
				t[row-1].book(seat);
				for(int y=0;y<10;y++)
				{
					t[y].display();
				}
			break;
			
			case 3:
				//for cancel booking
				cout<<"\nEnter the row and seat number you want to cancel book"<<endl;
				//int y;
				do
				{
					y=0;
					cout<<"\nRow  :\t";
					cin>>row;
					if(row<1||row>10)
					{
						cout<<"\n!!!!Invalid Row Input!!!!\n";
						cout<<"\nEnter Again :\t";
						y=1;
					}
				}while(y);
				
				do
				{
					y=0;
					cout<<"\nSeat :\t";
					cin>>seat;
					if(seat<1||seat>7)
					{
						cout<<"\n!!!!Invalid Seat Input!!!!\n";
						cout<<"\nEnter Again :\t";
						y=1;
					}
				}while(y);
	
				t[row-1].cancelBooking(seat);
				for(int y=0;y<10;y++)
				{
					t[y].display();
				}
			break;
	
			case 4:
				k=0;
			break;
					
			
		}
	}while(k);	
	
		
return 0;
	
}

