/*
====================================================================
 *  Mid Term 2 (Cineplex)
 *  cineplex.cpp
 *  01:42:34 AM
 *  Created on: Nov 24, 2014
 *  This source code is copyright protected under GNU PUBLIC LICENSE
====================================================================
 */
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#define TOTALcinema 2
#define TOTALviwer 100
#define Premium 3
#define Regular 7

using namespace std;

class movie
{
private:
    string movieName;
    int movieId;
    int runtime;
    int rating;
public:
    movie() : movieName("UNKNOWN"), movieId(0), runtime(0), rating(0) {}

    void setmovieName( string Name )
    {
        movieName=Name;
    }
    string getmovieName()
    {
        return movieName;
    }
    void setmovieId( int id)
    {
        movieId=id;
    }
    int getmovieId()
    {
        return movieId;
    }
    void setruntime( int time )
    {
        runtime=time;
    }
    int getruntime()
    {
        return runtime;
    }
    void setrating(int rate)
    {
        rating = rate;
    }
    int getrating ()
    {
        return rating ;
    }
    void inputMovieinformation();
    void showMovieinformation();
    ~movie() {}
};

void movie :: inputMovieinformation()
{

    cout << "Enter the Movie name : ";
    fflush(stdin);
    getline(cin, movieName);
    cout << "Enter Movie Id : ";
    fflush(stdin);
    cin >> movieId;
    cout << "Enter Movie Runtime : ";
    fflush(stdin);
    cin >> runtime;
    cout << "Enter Movie Rating : ";
    fflush(stdin);
    cin >> rating;
}

void movie :: showMovieinformation()
{
    cout << setw(14) << setfill(' ') << "Movie Id:" << setw(20) << movieId << endl
         << setw(14) << setfill(' ') << "Movie Name:" << setw(20) << movieName << endl
         << setw(14) << setfill(' ') << "Movie Runtime:" << setw(20) << runtime << endl
         << setw(14) << setfill(' ') << "Movie Rating:" << setw(20) << rating << endl;
}

class viwer
{
private:
    int theaterId;
    int seatNumber;
    string cinemaName;
    string ticketType;
    float ticketprice;

public:
    void settheaterId(int theater)
    {
        theaterId=theater;
    }
    int gettheaterId()
    {
        return theaterId;
    }
    void setSeatNumber(int number)
    {
        seatNumber=number;
    }
    int getSeatNumber ()
    {
        return seatNumber;
    }
    void setCinemaName (string name )
    {
        cinemaName = name;
    }
    string getCinemaId()
    {
        return cinemaName;
    }
    void setticketType(string type)
    {
        ticketType =type;
    }
    string getTicketType()
    {
        return ticketType;
    }
    void setTicketPrice( float price )
    {
        ticketprice = price;
    }
    float getTicketPrice()
    {
        return ticketprice;
    }
    void inputViewerinformation()
    {
        cout << "Enter Cinema Name: " ;
        getline(cin, cinemaName);
        cout << "Enter Theater Id : ";
        cin >> theaterId;
        cout << "Ticket Type (premium/regular) : " ;
        getline(cin, ticketType);
    }
    void showViwerinformation()
    {
        cout << "Theater Number : " << theaterId << endl
             << "Seat Number    : " << seatNumber <<'(' << ticketType << ')' << endl
             << "Ticket Price   : " << ticketprice << endl;
    }
};

class theater
{
private :
    //movie cinema[TOTALcinema];
    //viwer customer[TOTALviwer];
    int theaterId;
    string movieName[TOTALcinema];
    int movieId[TOTALcinema];
    int movieRating[TOTALcinema];
    int movieRuntime[TOTALcinema];
    float premiumPrice;
    float regularPrice;
    float ticketPrice;
    int premiumSeat[TOTALcinema];
    int regularSeat[TOTALcinema];
public:
    void settheater(movie Movie[])
    {
        static int Tid=1;
        theaterId=Tid;
        for(int i=0; i<TOTALcinema; i++)
        {
            movieName[i]=Movie[i].getmovieName();
            movieId[i]=100000+(Tid*10000)+Movie[i].getmovieId();
            movieRating[i]=Movie[i].getrating();
            movieRuntime[i]=Movie[i].getruntime();
            regularSeat[i]=Regular;
            premiumSeat[i]=Premium;
        }
        premiumPrice=0.00;
        regularPrice=0.00;
        ticketPrice=0.00;
        Tid++;
    }
    int getpremiumseat(int i)
    {
        return premiumSeat[i];
    }
    int getregularseat(int i)
    {
        return regularSeat[i];
    }
    void setTheaterId( int id )
    {
        theaterId=id;
    }
    int getTheaterId ()
    {
        return theaterId;
    }
    void theaterPricing()
    {
        cout << "Enter Premium seat Price of The Theater : " ;
        cin >> premiumPrice;
        cout << "Enter Regular seat Price of The Theater : " ;
        cin >> regularPrice;
    }
    viwer sellTicket(viwer customer)
    {
        int id,k;
        static int RseatNo=1;
        cout << "             Movie List          " << endl ;
        for(int i=0; i<TOTALcinema; i++)
        {
            cout <<"    " << movieId[i] << ". " << movieName[i] << endl;
        }
        cout << "Please Choose a Movie : ";
        fflush(stdin);
        cin >> id;
        for(int i=0; i<TOTALcinema; i++)
        {
            if(id==movieId[i])
            {
                k=i;
                break;
            }
        }
        customer.setCinemaName(movieName[k]);

        cout << "What kind of seat you want ? (premium/regular): ";
        string call;
        fflush(stdin);
        cin >> call;
        if(call=="premium")
        {
            static int PseatNo=1;
            if( PseatNo <= Premium)
            {

                customer.setSeatNumber(PseatNo);
                ticketPrice=premiumPrice+100*movieRating[k];
                customer.setTicketPrice(ticketPrice);
                customer.setticketType("Premium");
                --premiumSeat[k];
                customer.showViwerinformation();
                ++PseatNo;
            }
            else
            {
                cout << "There is no Premium seat in theater " << customer.gettheaterId() << endl;
            }

        }
        else if(call=="regular")
        {
            if(RseatNo <= Regular)
            {

                customer.setSeatNumber(RseatNo);
                ticketPrice=regularPrice+100*movieRating[k];
                customer.setTicketPrice(ticketPrice);
                customer.setticketType("Regular");
                --regularSeat[k];
                customer.showViwerinformation();
                ++RseatNo;
            }
            else
            {
                cout << "There is no Regular seat in theater " << customer.gettheaterId() << endl;
            }

        }
        else
        {
            if(RseatNo <= Regular)
            {

                customer.setSeatNumber(RseatNo);
                ticketPrice=regularPrice+100*movieRating[k];
                customer.setTicketPrice(ticketPrice);
                customer.setticketType("Regular");
                --regularSeat[k];
                customer.showViwerinformation();
                ++RseatNo;
            }
            else
            {
                cout << "There is no Regular seat in theater " << customer.gettheaterId() << endl;
            }

        }
        return customer;
    }
};

int main()
{
    viwer people[TOTALviwer];
    movie cinema[TOTALcinema];
    theater hall[2];

    for(;;)
    {
        cout << "                     Soitan Cineplex                         "<< endl << endl;
        cout << "1.Input Today's movie Information " << endl
             <<"2.set seat type price " << endl
             <<"3.Seat available" << endl
             <<"4.Sell a Ticket" << endl
             <<"5.Exit"<< endl
             <<"6.Help for using this system"<< endl ;
        cout << "Enter What you want : ";
        int choose;
        cin >> choose;
        switch(choose)
        {
        case 1:
        {
            for(int i=0; i<TOTALcinema; i++)
            {
                cinema[i].inputMovieinformation();
            }
            for(int i=0; i<2; i++)
            {
                hall[i].settheater(cinema);
            }
            break;
        }
        case 4:
        {
            static int i;
            int k;
            cout << "Theater Number (1-6): " ;
            cin >> k;
            people[i].settheaterId(k);
            k-=1;
            people[i]=hall[k].sellTicket(people[i]);
            i++;
            break;
        }
        case 5:
        {
            return EXIT_SUCCESS;
        }
        case 2:
        {
            for(int i=0; i<2; i++)
            {
                hall[i].theaterPricing();

            }
            break;
        }
        case 3:
        {
            cout << "Enter the theater Id : " ;
            int l;
            cin >> l;
            cout << "What type of seat (premium/regular) : ";
            string a;
            cin >> a;
            cout << "which Movie (1/2): ";
            int h;
            cin >> h;
            l-=1;
            h-=1;
            if(a=="premium")
            {
                cout << "Seat available - " <<hall[l].getpremiumseat(h);
            }
            else if(a=="regular")
            {
                cout << "Seat available:" <<hall[l].getregularseat(h);
            }
            else
                break;
            break;

        }
        case 6:
        {
            cout << "This system is still on Alpha stage. Although the program run quit well"<<endl
                 << "but it does have some problem. This program not well written. " << endl
                 << "First select 1 then 2 then anything. use this by what is saying to do or what is saying to input" << endl
                 << " I again saying this is still Alpha stage it has lots of problem." << endl;
        }

        }
    }

    return 0;

}

