/*
 * Project_One.cpp
 *
 *  Created on: Jan 19, 2021
 *      Author: Britteny Itter
 */

#include<iostream>
using namespace std;

//enum timeOfDay so that AM and PM can be called more easily.
enum timeOfDay {AM , PM} timeofday;

//create public class for base variables.
class Time {
    public:
    int hours;
    int minutes;
    int seconds;
};

//create public class to inherit from Time class for 12-hour clock.
class _12Clock : public Time {
    public:
    _12Clock(int h , int m , int s) {
        hours = h;
        minutes = m;
        seconds = s;
        timeofday = AM;
}
//create functions with if statements to add one hour, one minute, and one second to 12-hour clock.
void addOneHour() {
    if(hours == 11) {
        hours = 0;
        timeofday = timeofday == AM ? PM : AM;
    }
    else {
        hours += 1;
    }
}

void addOneMinute() {
    if(minutes == 59) {
        minutes = 0;
        addOneHour();
    }
    else {
        minutes += 1;
    }
}

void addOneSecond() {
    if(seconds == 59) {
        seconds = 0;
        addOneMinute();
    }
    else {
        seconds += 1;
    }
}
};

//create public class to inherit from Time class for 24-hour clock.
class _24Clock : public Time {
    public:
    _24Clock(int h , int m , int s) {
        hours = h;
        minutes = m;
        seconds = s;
}

//create functions with if statements to add one hour, one minute, and one second to 24-hour clock.
void addOneHour() {
    if(hours == 23) {
        hours = 0;
    }
    else {
        hours += 1;
    }
}

void addOneMinute() {
    if(minutes == 59) {
        minutes = 0;
        addOneHour();
    }
    else {
        minutes += 1;
    }
}

void addOneSecond() {
    if(seconds == 59) {
        seconds = 0;
        addOneMinute();
}
    else {
        seconds += 1;
    }
}
};

//create PrintDisplayClock() function to set layout for clock output.
void PrintDisplayClock(const _12Clock& _12time ,const _24Clock& _24time) {
    cout << "*************************** ***************************" << endl;
    cout << "*     12-Hour Clock       * *      24-Hour Clock      *" << endl;
    cout << "*     ";
        if(_12time.hours < 10) {
            cout << "0" << _12time.hours << ":";
    }
        else {
            cout << _12time.hours << ":";
    }

        if(_12time.minutes < 10 ) {
            cout << "0" << _12time.minutes << ":";
    }
        else {
            cout << _12time.minutes << ":";
    }

        if(_12time.seconds < 10) {
            cout << "0" << _12time.seconds;
    }
        else {
            cout << _12time.seconds;
    }

        if(timeofday == AM ) {
            cout << " A M";
    }
        else {
            cout << " P M";
   }

    cout << "        * *         ";

        if(_24time.hours < 10) {
            cout << "0" << _24time.hours << ":";
    }
        else {
            cout << _24time.hours << ":";
    }

        if(_24time.minutes < 10 ) {
            cout << "0" << _24time.minutes << ":";
    }
        else {
            cout << _24time.minutes << ":";
    }

        if(_24time.seconds < 10) {
            cout << "0" << _24time.seconds;
    }
        else {
            cout << _24time.seconds;
    }

    cout << "        *" << endl;
    cout << "*************************** ***************************" << endl;
}

//create PrintMenu() function to set layout for selection menu output
void PrintMenu() {
    cout << "***************************" << endl;
    cout << "* 1 - Add One Hour        *" << endl;
    cout << "* 2 - Add One Minute      *" << endl;
    cout << "* 3 - Add One Second      *" << endl;
    cout << "* 4 - Exit Program        *" << endl;
    cout << "***************************" << endl;
}

//create main() method
int main() {
    //set default clock times
    _12Clock _12Time(11, 59, 59 );
    _24Clock _24Time(23, 59, 59);
    //output default clock times
    PrintDisplayClock(_12Time , _24Time);

    //create while loop so that program does not terminate until they input the number 4.
    while(true) {
        //output option menu.
        PrintMenu();
        //set variable for input.
        int choice;
        cin >> choice;

        //create switch statement so that appropraite output is set for each choice selection.
        switch (choice) {
            case 1:
                _12Time.addOneHour();
                _24Time.addOneHour();
                PrintDisplayClock(_12Time , _24Time);

                break;

            case 2:
                _12Time.addOneMinute();
                _24Time.addOneMinute();
                PrintDisplayClock(_12Time , _24Time);

                break;

            case 3:
                _12Time.addOneSecond();
                _24Time.addOneSecond();
                PrintDisplayClock(_12Time , _24Time);

                    break;

            case 4:
                cout << "Goodbye.";
                exit(1);

                break;

            default:
                cout << "Invalid choice. Please try again." << endl;

                break;
        }
    }
}
