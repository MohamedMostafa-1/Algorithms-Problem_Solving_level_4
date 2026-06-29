#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

//#1
int ReadNumber() {
    int Num = 0;
    cout << "\nEnter Number: ";
    cin >> Num;
    return Num;
}
string NumberToText(int Number) {
    if (Number == 0) {
        return "";
    }
    else if(Number >=1  && Number <=19)
    {
        string arrString[] = { "" , "one" , "two","Three","Four","Five","Six","Seven",
                    "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
                    "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
        return arrString[Number];
    }
    else if(Number >=20 && Number <= 99)
    {
        string arrString[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        return arrString[Number / 10] + " " + NumberToText(Number % 10);
    }
    else if(Number >= 100 && Number <= 199)
    {
        return "One Hundred " + NumberToText(Number % 100);
    }
    else if(Number >= 200 && Number <=999)
    {
        return NumberToText(Number / 100) + " Hundreds " + NumberToText(Number%100);
    }
    else if(Number >=1000 && Number <= 1999)
    {
        return "one Thousand " + NumberToText(Number%1000);
    }
    else if(Number >=2000 && Number <= 999999)
    {
       return  NumberToText(Number/1000) + " Thousands " + NumberToText(Number%1000);
    }
    else if(Number >= 1000000 && Number <= 1999999)
    {
        return "one Million " + NumberToText(Number%1000000);
    }
    else if(Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number%1000000);
    }
    else if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number %1000000000);
    }
    else
    {
        return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }
  
}

//#2
short ReadYear() {
    short Year = 0;
    cout << "\nPlease Enter a Year To Chock? : ";
    cin >> Year;
    return Year;
}

bool IsLeapYear(short Year) {
    if (Year % 400 == 0)
        return true;
    else if (Year % 4 == 0 && Year % 100 != 0)
        return true;
    else
        return false;
}

//#3
bool isLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

//#4
int NumberOfDayInYear(short Year) {
    return isLeapYear(Year) ? 366 : 365;
}
int NumberOfHourInYear(short Year) {
    return NumberOfDayInYear(Year)*24;
}
int NumberOfMinutesInYear(short Year) {
    return NumberOfHourInYear(Year)*60;
}
int NumberOfSecondsInYear(short Year) {
    return NumberOfMinutesInYear(Year)*60;
}

//#5
short ReadMonth() {
    short Month=0;
    cout << "\nPlease Enter a Month To Chock? : ";
    cin >> Month;
    return Month;

}
short NumberOfDaysInMonth(short Month, short Year) {
    if (Month < 1 || Month >12)
        return 0;

    if (Month == 2) {
        return isLeapYear(Year) ? 29 : 28;
    }

    short arrDays[] = { 0 ,31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return arrDays[Month];
}
short NumberOfDaysInMonth_better(short Month, short Year) {
    if (Month < 1 || Month >12)
        return 0;

    //if (Month == 2) {
    //    return isLeapYear(Year) ? 29 : 28;
    //}


    short arrDays[] = { 0 ,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : arrDays[Month];
}
int NumberOfHoursInMonth(short Month,short Year) {
    return NumberOfDaysInMonth(Month,Year) * 60;
}
int NumberOfMinutesInMonth(short Month,short Year) {
    return NumberOfHoursInMonth(Month,Year) * 60;
}
int NumberOfSecondsInMonth(short Month,short Year) {
    return NumberOfMinutesInMonth(Month,Year) * 60;
}


//#7
short ReadDay() {
    short Day = 0;
    cout << "\nEnter a Day: ";
    cin >> Day;
    return Day;
}

short DayOfWeekOrder(short Day,short Month, short Year) {
    short a, y, m, d;
     a = (14 - Month) / 12;
     y = Year - a;
     m = Month + 12 * a - 2;
     d = (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
    return d;
}
string DayShortName(short DayOfWeekOrder) {
    string arrDayName[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayName[DayOfWeekOrder];
}
void PrintDayOrder(short Day, short Month, short Year) {
    short DayOrder = DayOfWeekOrder(Day, Month, Year);

    cout << endl;
    cout << "Date      :" << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order :" <<  DayOrder << endl;
    cout << "Day Name  :" << DayShortName(DayOrder) << endl;
}

//#8
string MonthShortName(short Month) {
    string arrMonths[13] = {"","Jan", "Feb", "Mar","Apr", "May", "Jun","Jul", "Aug", "Sep","Oct", "Nov", "Dec"};
    return arrMonths[Month];
}
void PrintMonthCalendar(short Month, short Year) {
    int NumberOfDays;
    // Index of the day from 0 to 6
    int current = DayOfWeekOrder(1, Month, Year);
    NumberOfDays = NumberOfDaysInMonth(Month, Year);
    // Print the current month name
    printf("\n _______________%s_______________\n\n",
        MonthShortName(Month).c_str());
    // Print the columns
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    // Print appropriate spaces
    int i;
    for (i = 0; i < current; i++)
        printf("     ");
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n _________________________________\n");
    //cout << "\n_____________________________________________________________________\n";
}

//#9
void PrintYearCalender(short Year) {
    printf("\n______________________________\n\n");
    printf("         Calender - %d           ", Year);
    printf("\n______________________________\n");

    for (short month = 1; month <= 12; month++)
    {
        PrintMonthCalendar(month , Year);
    }
}

//#10
int NumberOfDaysFormTheBeginingOfTheYear(short Day, short Month, short Year){
    int TotalDays = 0;
    for (short  month = 1; month <= Month-1; month++)
    {
        TotalDays += NumberOfDaysInMonth(month, Year);
    }
    TotalDays += Day;
    return TotalDays;
}

//#11
struct stDate
{
    short Day;
    short Month;
    int Year;
};
void PrintDate(short Day, short Month, short Year) {
    cout << "Date      :" << Day << "/" << Month << "/" << Year << endl;
}
void ConvertTotalDaysToDate(int TotalDays  , short Year ) {
    short NumberOfMonth = 0;
    short NumebrOfDayInLastMonth =0;
  
    while (TotalDays != 0) {
        if (TotalDays <= 31){
            NumebrOfDayInLastMonth = TotalDays;
            ++NumberOfMonth;
            break;
        }

        ++NumberOfMonth;
        TotalDays -= NumberOfDaysInMonth(NumberOfMonth, Year);
    }

     PrintDate(NumebrOfDayInLastMonth, NumberOfMonth, Year);
}
stDate GetDateFromDayOrderInYear(short TotalDays, int Year) {
    stDate Date;
    short RemainingDays = TotalDays;
    short MonthDays = 0;

    Date.Month = 1;
    Date.Year = Year;

    while (true) {
        MonthDays = NumberOfDaysInMonth(Date.Month, Year);
        if (RemainingDays > MonthDays) {
            RemainingDays -=MonthDays;
            Date.Month++;
            if (Date.Month > 12) {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

//#12
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
int ReadDaysToAdd() {
    int Days=0;
    cout << "\nHow Many Days To Add? ";
    cin >> Days;
    return Days;
}
stDate DateAddDays(int DaysAdding , stDate reDate) {
    stDate Date;
    int TotalDaysBeforeAdding = NumberOfDaysFormTheBeginingOfTheYear(reDate.Day, reDate.Month, reDate.Year);
    int TotalDaysAfterAdding = TotalDaysBeforeAdding + DaysAdding;
    Date = GetDateFromDayOrderInYear(TotalDaysAfterAdding , reDate.Year);
    return Date;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    //#1
    //int Number = ReadNumber();
    //cout << endl << NumberToText(Number) << endl;
    cout << "\n===========================================================================\n";

    //#2&3
    if (IsLeapYear(Year)) 
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    else
        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";

    cout << "\n===========================================================================\n";
    //#4
    cout << "\nNumber of Days in Year [" << Year << "] is "  << NumberOfDayInYear(Year);
    cout << "\nNumber of Hours in Year [" << Year << "] is " << NumberOfHourInYear(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(Year);


    cout << "\n===========================================================================\n";
    //#5
    cout << "\nNumber of Days in Month [" << Month << "] is "
        << NumberOfDaysInMonth_better(Month, Year);
    cout << "\nNumber of Hours in Month [" << Month << "] is "
        << NumberOfHoursInMonth(Month, Year);
    cout << "\nNumber of Minutes in Month [" << Month << "] is "
        << NumberOfMinutesInMonth(Month, Year);
    cout << "\nNumber of Seconds in Month [" << Month << "] is "
        << NumberOfSecondsInMonth(Month, Year);


    cout << "\n===========================================================================\n";
    //#7
    //PrintDayOrder(Day, Month, Year);

    cout << "\n===========================================================================\n";
    //#8
    //PrintMonthCalendar(Month, Year);

    cout << "\n===========================================================================\n";
    //#9
    //PrintYearCalender(Year);
     

    cout << "\n===========================================================================\n";
    //#10
    cout << "\n Number Of Days From The Begining Of The Year : " << NumberOfDaysFormTheBeginingOfTheYear(Day , Month,Year);


    cout << "\n===========================================================================\n";
    //#11
    short TotalDays = NumberOfDaysFormTheBeginingOfTheYear(Day, Month, Year);
    // way one
    ConvertTotalDaysToDate(TotalDays ,Year);
    // way two
    stDate Date = GetDateFromDayOrderInYear(TotalDays, Year);

    cout << "Date for [" << TotalDays << "] is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


    cout << "\n===========================================================================\n";
    //#12
    stDate ReadDate = ReadFullDate();
    int DaysAdding = ReadDaysToAdd();
    stDate Date1 = DateAddDays(DaysAdding, ReadDate);
    cout << "\nDate After [" << DaysAdding << "] is: ";
    cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    system("pause>0");
    return 0;
}

