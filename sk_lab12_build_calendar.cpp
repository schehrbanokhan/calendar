
#include <iostream>
#include <ctime>
using namespace std;

int day_of_week(int year); // displays the day of the week the year started with
int num_spaces(int day); // number of spaces to add between days
void display_spaces(int number_of_spaces); // uses num spaces to add the appropriate number of spaces
void display_num_padded(int num); // displays the number padded or not based on input
char leap_year(int year); // checks if input year is leap or not

int main()
{
    string month_name;
    int num_days_in_month=0; 
    int year;
    int spaces_;
    int left_spaces;
    char is_leap_year;
    int starting_day;
    int current_day_of_week;

    int yearly[12][2] = {{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
    string month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    
    cout<<"What year would you like to see the calendar for? "<<endl;
    cin>>year;
    
    // day of the week the year starts with
    current_day_of_week = day_of_week(year);
    
    // what day does the year start with
    starting_day = day_of_week(year);

    // check if leap_year
    is_leap_year = leap_year(year);
    
    for (int m = 0; m<12; m+=1)
    {
        month_name = month[m];// name of month from 1D month array
        cout<<endl;
        cout<<"--------------------"<<month_name<<"---------------------"<<endl;
        cout<<endl;
        cout<<" Sun    Mon    Tue    Wed    Thu    Fri    Sat "<<endl;

        if (m==0)
        {
            spaces_ = num_spaces(starting_day); // counts the number of spaces to put before jan 1st 
        }
        else
        {
            spaces_=num_spaces(current_day_of_week);
        }

        display_spaces(spaces_);// displays spaces_ number of spaces

        if (m == 1 and is_leap_year =='Y')
        {
            num_days_in_month = 29;
        }
        else
        {
            num_days_in_month = yearly[m][1];
        }
        
        for (int dat = 1; dat<=num_days_in_month; dat+=1)
        {
            
            display_num_padded(dat);
            display_spaces(5);
            
            if (current_day_of_week == 6)
            {
                cout<<endl;
                display_spaces(2);
            }
            current_day_of_week = (current_day_of_week+1)%7;
        }
    cout<<endl;
    
    }
    return 0;
}

// Functions

// shows what day of the week the year starts with 
int day_of_week(int year)
{
    tm time_in = { 0, 0, 0, // seconds, minutes, hours
      1,0, year - 1900 }; // day = 1, month = Jan, year(since 1900)

    time_t time_temp = mktime(&time_in);
    
    const tm * time_out = localtime(&time_temp);

     //Sunday = 0, Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6
     return time_out->tm_wday;
}

// based on the day of the week calculate the number of spaces before a day can be displayed
int num_spaces(int day)
{   
    if (day==0)
    {
        return 2 ;
    }
    else if (day>=1)
    {
        return 2 + (7 * day);
    }
    return 0;
}

// number of spaces before date can be entered
void display_spaces(int number_of_spaces)
{
    for (int i = 0; i<number_of_spaces; i+=1)
    {
        cout<<" ";
    }
}

void display_num_padded(int num)
{
    if(num<10)
    {
        cout<<" "<<num;
    }
    else
    {
        cout<<num;
    }
}

char leap_year(int year)
{
    if (year % 400 ==0)
    {
        return 'Y';
    }

    if (year % 100 == 0)
    {
        return 'N';
    }

    if (year % 4 == 0)
    {
        return 'Y';
    }
    return 0;
}



