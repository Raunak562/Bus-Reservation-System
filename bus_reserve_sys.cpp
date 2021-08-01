#include <iostream>
#include <string.h>
#include <iomanip>
#include <conio.h>
using namespace std;

class Time
{
    private:
        int hh;
        int mm;
        int ss;
    
    public:
        Time(int hh = 0, int mm = 0, int ss = 0)
        {
            this->hh = hh;
            this->mm = mm;
            this->ss = ss;
        }
        
        void getTime(int hh = 0, int mm = 0, int ss = 0)
        {
            this->hh = hh;
            this->mm = mm;
            this->ss = ss;
        }
        
        void diplayTime()
        {

            cout<<setw(2)<<setfill('0')<<hh<<":";
            cout<<setw(2)<<setfill('0')<<mm<<":";
            cout<<setw(2)<<setfill('0')<<ss;
        }
};

class Bus
{
    private:
        int BusNo;
        string DriverName;
        Time DepartureTime;
        Time ArrivalTime;
        string StartingPoint;
        string DestinationPoint;
        int NoOfSeats;
        string BusType;
        
    public:
        void getBusDetails(int BusNo, string DriverName, Time DepartureTime, Time ArrivalTime, string StartingPoint, 
        string DestinationPoint, int NoOfSeats, string BusType)
        {
            this->BusNo = BusNo;
            this->DriverName = DriverName;
            this->DepartureTime = DepartureTime;
            this->ArrivalTime = ArrivalTime;
            this->StartingPoint = StartingPoint;
            this->DestinationPoint = DestinationPoint;
            this->NoOfSeats = NoOfSeats;
            this->BusType = BusType;
        }
        void showBusDetails()
        {
            cout<<"\nBus No: "<<BusNo;
            cout<<"\tDriver Name: "<<DriverName;
            cout<<"\tDeparture Time: ";
            DepartureTime.diplayTime();
            cout<<"\tArrival Time: ";
            ArrivalTime.diplayTime();
            cout<<"\tStarting Point: "<<StartingPoint;
            cout<<"\tDestination Point: "<<DestinationPoint;
            cout<<"\tNo Of Seats: "<<NoOfSeats;
            cout<<"\tBus Type: "<<BusType;            
        }
        
        int getBusNo()
        {
            return BusNo;
        }
        
        string getDriverName()
        {
            return DriverName;
        }
        
        Time getDepartureTime()
        {
            return DepartureTime;
        }
        
        Time getArrivalTime()
        {
            return ArrivalTime;
        }
        
        string getStartingPoint()
        {
            return StartingPoint;
        }
        
        string getDestinationPoint()
        {
            return DestinationPoint;
        }
        
        int getNoOfSeats()
        {
            return NoOfSeats;
        }
        
        string getBusType()
        {
            return BusType;
        }
        void putNoOfSeats(int n)
        {
            NoOfSeats += n;
        }
        
};

class Bus_Reservation_System
{
    private:
        Bus b[10];
        int p = -1;
        
    public:
        void addBus()
        {
            if(p == 9)
            {
                cout<<"We already own 10 Buses. That's our current limit.";
                getchar();
                getchar();
                return;
            }
            else
            {
                p++;
                
                int NoOfSeats, BusNo, hh, mm, ss;
                string DriverName, StartingPoint, DestinationPoint, BusType;
                Time DepartureTime, ArrivalTime;
                
                cout<<"\nEnter the following Details: ";
                cout<<"\nBus No: ";
                cin>>BusNo;
                cout<<"Driver Name: ";
                cin.ignore();
                getline(cin, DriverName);
                cout<<"Departure Time(space separated hour, minutes and seconds): ";
                cin>>hh>>mm>>ss;
                DepartureTime.getTime(hh, mm, ss);
                cout<<"Arrival Time(space separated hour, minutes and seconds): ";
                cin>>hh>>mm>>ss;
                ArrivalTime.getTime(hh, mm, ss);
                cout<<"Starting Point: ";
                cin.ignore();
                getline(cin, StartingPoint);
                cout<<"Destination Point: ";
                getline(cin, DestinationPoint);
                cout<<"No Of Seats: ";
                cin>>NoOfSeats;
                cout<<"Bus Type: ";
                cin.ignore();
                getline(cin, BusType);
                
                b[p].getBusDetails(BusNo, DriverName, DepartureTime, ArrivalTime, 
                StartingPoint, DestinationPoint, NoOfSeats, BusType);
                
                cout<<"\nCongratulations! New Bus added!";
                getchar();
            }
            
            
        }
        void removeBus()
        {
            bool flag;
            if(p == -1)
            {
                cout<<"\nWe actually own zero Buses. Cannot remove buses any further.";
                getchar();
                getchar();                
                return;
            }
            else
            {
                int Busno, i = 0;
                char choice;
                
                cout<<"\nEnter the Busno of the Bus that is to be removed: ";
                cin>>Busno;
                
                for(i = 0; i <= p; i++)
                    if(b[i].getBusNo() == Busno)
                    {
                        b[i].showBusDetails();
                        cout<<"\n\nIs is the Bus you want to remove?(Y/N): ";
                        cin>>choice;
                        flag = true;
                    }
                    
                if(choice == 'Y' || choice == 'y')
                {
                    cout<<"\nThis Bus has now been removed!";
                    getchar();
                    getchar();
                    p--;
                }
                else
                {
                    cout<<"\nOperation Abort!";
                    getchar();
                    getchar();
                }
                
                if(!flag)
                {
                    cout<<"BusNo not found!";
                    getchar();
                    getchar();
                }
            }
        }
        
        void showAllBuses()
        {
            if(p == -1)
            {
                cout<<"\nWe actually own zero Buses.";
                getchar();
                getchar();                
                return;
            }
            else
            {
                cout<<"\nBuses Available:\n";
                int i = 0;
                for( ; i <= p; i++)
                {
                    b[i].showBusDetails();
                    cout<<endl;
                }
                getchar();
                getchar();
            }
        }
        
        void bookSeat()
        {
            int Busno, i = 0;
            char choice;
            cout<<"\nEnter Busno: ";
            cin>>Busno;
            
            for(i = 0; i <= p; i++)
                if(b[i].getBusNo() == Busno)
                {
                    b[i].showBusDetails();
                    cout<<"\n\nConfirm Ticket?(Y/N)";
                    cin>>choice;
                    break;
                }
            
            if(choice == 'Y' || choice == 'y')
            {
                cout<<"\nCongratulations! Your seat has been booked!";
                getchar();
                getchar();
                b[i].putNoOfSeats(-1);
            }
            else
            {
                cout<<"\nBooking unsuccessful. Please try again!";
                getchar();
                getchar();
            }
        }
        void cancelSeat()
        {
            int Busno, i = 0;
            char choice;
            cout<<"Enter Busno: ";
            cin>>Busno;
            
            for(i = 0; i <= p; i++)
                if(b[i].getBusNo() == Busno)
                {
                    b[i].showBusDetails();
                    cout<<"\n\nCancel Ticket?(Y/N)";
                    cin>>choice;
                    break;
                }
            
            if(choice == 'Y' || choice == 'y')
            {
                cout<<"\nYour booking has been cancelled!";
                getchar();
                getchar();
                b[i].putNoOfSeats(1);
            } 
            else
            {
                cout<<"\nCancellation unsuccessful. Please try again!";
                getchar();
                getchar();
            }
        }
        
};


int main()
{
    char choice;
    int i = 0;
    // string username, original_username;
    // char password[24], original_pass, c;
    Bus_Reservation_System brs;
    
    while(1)
    {
        system("clear");
        cout<<"Welcome to ClickBus.com\n\n1.Admin Mode\n2.Public Mode\n3.Exit\n\nPlease enter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case '1':
                i = 0;
                while(i >= 0)
                {
                    /*
                    system("clear");
                
                    cout<<"ADMIN MODE\nUser Name: ";
                    cin>>username;
                    getchar();
                    cout<<"Password: ";
                    i = 0;
                    while(1)
                    {
                        c = getchar();
                        
                        if(c == '\n')
                        {
                            password[i] = '\0';
                            break;
                        }
                        
                        if(c =='\b' && i > 0)
                            i--;
                        
                        password[i++] = c;
                        cout<<"*";
                    }
                    
                    if(original_username != username && strcmp(original_pass, password) != 0)
                    {
                        cout<<"\nIncorrect Username/Password!";
                        break;
                    }
                    */
                    
                    system("clear");
                
                    cout<<"Welcome to Administrator Mode\n\n1.Show all Bus Details\n2.Add a new Bus";
                    cout<<"\n3.Remove an existing Bus\nPress any key to go back to Main Menu.\n";
                    cout<<"\nPlease enter your choice: ";
                    cin>>choice;
                    
                    switch(choice)
                    {
                        case '1':
                            brs.showAllBuses();
                            break;
                            
                        case '2':
                            brs.addBus();
                            break;
                            
                        case '3':
                            brs.removeBus();
                            break;
                            
                        default:
                            i = -1;
                    }
                }
                break;
                
            case '2':
                i = 0;
                while(i >= 0)
                {
                    system("clear");            
                    cout<<"Welcome to ClickBus\n\n1.Show all Bus Details\n2.Book a seat";
                    cout<<"\n3.Cancel your seat.\nPress any key to go back to Main Menu.\n";
                    cout<<"\nPlease enter your choice: ";
                    cin>>choice;
                
                    switch(choice)
                    {
                        case '1':
                            brs.showAllBuses();
                            break;
                            
                        case '2':
                            brs.bookSeat();
                            break;
                            
                        case '3':
                            brs.cancelSeat();
                            break;
                            
                        default:
                            i = -1;
                    }
                }
                break;
                
            case '3':
            
                exit(0);
                break;
                
            default:
            
                cout<<"Incorrect Option. Try Again!\n";
                getchar();
                getchar();
        }
    }
    return 0;
}
