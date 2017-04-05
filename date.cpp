/* Sagar Kumar
 * SADS Homework 5
 * Question 5.2 Verification: Class invariants
 */
#include <iostream>
#include <cstdlib>
using namespace std;

bool has_31_days(int n){
    if(n==1 || n==3 || n==5 || n==7 || n==8 || n==10 || n==12)
        return true;
    else return false;
}

bool has_30_days(int n){
    if(n==4 || n==6 || n==9 || n==11)
        return true;
    else return false;
}

bool has_28_days(int n){
    if(n==2)
        return true;
    else return false;
}

class Date{
private:
    int year;
    int month;
    int day;
public:
    Date(){};
    Date(int year_in, int month_in, int day_in){
        this->year = year_in;
        this->month = month_in;
        this->day = day_in;
    }

    Date yesterday(){
        /* checking input */
        if(this->year<0 || (this->month<=0 || this->month>=13) || (this->day<=0 || this->day>31)){
            cout << "Invalid Date! exiting..." << endl;
            exit(-1);
        /* checking input */
        }else if((this->month==4 || this->month==6 || this->month==9 || this->month==11) && this->day==31){
            cout << "Day 31 does not exist for this month! Invalid date! exiting..." << endl;
            exit(-1);
        /* calculating date */
        /* Three cases arise: mid-month, new years, last day of month*/
        }else if(this->month==2 && this->day>28){
            cout << "Too many days for Feb! Invalid date! exiting..." << endl;
            exit(-1);
        }else{
            Date to_return;
            if(this->day!=1){                                           /* middle of month */
                to_return.day = (this->day)-1;
                to_return.month = this->month;
                to_return.year = this->year;
            }else if(this->day==1 && this->month==1 && this->year!=0){  /* New years */
                to_return.day = 31;
                to_return.month = 12;
                to_return.year = (this->year)-1;
            }else if(this->day==1 && this->month!=1){                   /* first day of month */
                if(has_31_days(this->month))
                    to_return.day = 30;
                else if(!has_31_days(this->month))
                    to_return.day = 31;
                else if(this->month == 3)
                    to_return.day = 28;
                to_return.month = (this->month)-1;
                to_return.year = this->year;
            }
            return to_return;
        }
    }

    /* cases: Last day of year, last day of month, middle of month*/
    Date tomorrow(){
        Date to_return;
        if(this->year<0 || (this->month<=0 || this->month>=13) || (this->day<=0 || this->day>31)){
            cout << "Invalid Date! exiting..." << endl;
            exit(-1);
        }else if((this->month==4 || this->month==6 || this->month==9 || this->month==11) && this->day==31){
            cout << "Day 31 does not exist for this month! Invalid date! exiting..." << endl;
            exit(-1);
        }else if(this->month==2 && this->day>28){
            cout << "Too many days for Feb! Invalid date! exiting..." << endl;
            exit(-1);
        }else{
            // end of month
            if(((this->day==31&&has_31_days(this->month))||(this->day==30&&has_30_days(this->month))||(this->day==28 && has_28_days(this->month))) && this->month!=12){   // last day of month
                to_return.day = 1;
                to_return.month = (this->month)+1;
                to_return.year = this->year;
            // end of year
            }else if(this->month==12 && this->day==31){
                to_return.day = 1;
                to_return.month = 1;
                to_return.year = (this->year)+1;
            // middle of month
            }else{
                to_return.day = (this->day)+1;
                to_return.month = this->month;
                to_return.year = this->year;
            }
            return to_return;
        }
    }

    void print(){
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }
};

int main(){

    Date my_birthday(1996,9,2);
    cout << "My birthday is on..." << endl;
    my_birthday.print();

    Date day_before_I_was_born = my_birthday.yesterday();
    cout << endl << "So the day before was..." << endl;
    day_before_I_was_born.print();

    return 0;
}
