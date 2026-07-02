//time
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>


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
    cout << "Please Enter a Year: ";
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
    cout << "Please Enter a Month: ";
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
    cout << "\nPlease Enter a Day: ";
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

//#13
bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
    Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
    Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}

//#14
bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

//#15
bool IsLastMonthInYear(short Month){
    return (Month == 12);
}
bool IsLastDayInMonth(stDate Date){
    short NumbetOfDays = NumberOfDaysInMonth(Date.Month, Date.Year);
    return (Date.Day == NumbetOfDays);
}


//#16
stDate IncreaseDateByOneDay_Me(stDate Date) {
    int NumberOfDay = NumberOfDaysFormTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year)+1;
    return GetDateFromDayOrderInYear(NumberOfDay ,Date.Year);
}
stDate IncreaseDateByOneDay(stDate Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month)) {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month = 1;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

//#17
//#19
void SwapDates(stDate Date1, stDate Date2) {
    stDate TempDate
        ;
    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;

    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;

    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;
}
int GetDifferenceInDays(stDate Date1, stDate Date2, bool
    IncludeEndDay = false)
{
    int Days = 0;
    short SawpFlagValue = 1;
    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        //Swap Dates
        SwapDates(Date1, Date2);
        SawpFlagValue = -1;
    }
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}

//#18
stDate GetSystemDate() {
    stDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;   

    return Date;
}


//#20 to #32
stDate DecreaseDateByXDays( short DaysAdding, stDate Date ) {
    for (short i = 1; i <= DaysAdding; i++)
    {
       Date =  IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) {
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}
stDate IncreaseDateByXWeeks(short WeeksAdding,stDate Date ) {
    for (short i = 1; i <= WeeksAdding; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date) {
    if (Date.Month == 12) {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month , Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

        return Date;
}
stDate IncreaseDateByXMonths(short MonthsAdding,stDate Date ) {
    for (short i = 1; i <= MonthsAdding; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;


}

stDate IncreaseDateByOneYear(stDate Date) {

    Date.Year++;
    return Date;
}
stDate IncreaseDateByXYears(short YearsAdding,stDate Date) {
    for (short i = 1; i <= YearsAdding; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
stDate IncreaseDateByXYearsFaster(short YearsAdding, stDate Date ) {
    Date.Year + YearsAdding;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {

    Date.Year+10;
    return Date;
}
stDate IncreaseDateByXDecades(short DecadesAdding , stDate Date ) {
    for (short i = 1; i <= DecadesAdding; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}
stDate IncreaseDateByXDecadesFaster(short DecadesAdding ,stDate Date) {
    Date.Year + (10 * DecadesAdding);
    return Date;
}


stDate IncreaseDateByOneCentury(stDate Date) {

    Date.Year+100;
    return Date;
}
stDate IncreaseDateByOneMillennium(stDate Date) {

    Date.Year+1000;
    return Date;
}

//===========================================================================================================

//#33 to #46
stDate DecreaseDateByOneDay(stDate Date) {
    if (Date.Day == 1) {
        if (Date.Month == 1) {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Month , Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}
stDate IncreaseDateByXDays( short DaysAdding, stDate Date ) {
    for (short i = 1; i <= DaysAdding; i++)
    {
       Date =  IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) {
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}
stDate IncreaseDateByXWeeks(short WeeksAdding,stDate Date ) {
    for (short i = 1; i <= WeeksAdding; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date) {
    if (Date.Month == 12) {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month , Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

        return Date;
}
stDate IncreaseDateByXMonths(short MonthsAdding,stDate Date ) {
    for (short i = 1; i <= MonthsAdding; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;


}

stDate IncreaseDateByOneYear(stDate Date) {

    Date.Year++;
    return Date;
}
stDate IncreaseDateByXYears(short YearsAdding,stDate Date) {
    for (short i = 1; i <= YearsAdding; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
stDate IncreaseDateByXYearsFaster(short YearsAdding, stDate Date ) {
    Date.Year + YearsAdding;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {

    Date.Year+10;
    return Date;
}
stDate IncreaseDateByXDecades(short DecadesAdding , stDate Date ) {
    for (short i = 1; i <= DecadesAdding; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}
stDate IncreaseDateByXDecadesFaster(short DecadesAdding ,stDate Date) {
    Date.Year + (10 * DecadesAdding);
    return Date;
}


stDate IncreaseDateByOneCentury(stDate Date) {

    Date.Year+100;
    return Date;
}
stDate IncreaseDateByOneMillennium(stDate Date) {

    Date.Year+1000;
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
    //stDate ReadDate = ReadFullDate();
    //int DaysAdding = ReadDaysToAdd();
    //stDate Date1 = DateAddDays(DaysAdding, ReadDate);
    //cout << "\nDate After [" << DaysAdding << "] is: ";
    //cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    cout << "\n===========================================================================\n";
    //#13
    //system("cls");
    //stDate Date1 = ReadFullDate();
    //stDate Date2 = ReadFullDate();
    //if(IsDate1BeforeDate2(Date1, Date2))
    //    cout << "\nYes, Date1 is Less than Date2.";
    //else
    //    cout << "\nNo, Date1 is NOT Less than Date2.";

    cout << "\n===========================================================================\n";
    //#14
    //if(IsDate1EqualDate2(Date1, Date2))
    //    cout << "\nYes, Date1 is Equal To Date2.";
    //else
    //    cout << "\nNo, Date1 is NOT Equal To Date2.";

    cout << "\n===========================================================================\n";
    //#15
    //stDate DateRead = ReadFullDate();
    //if (IsLastDayInMonth(DateRead))
    //    cout << "\nYes, Day is Last Day in Month.";
    //else
    //    cout << "\nNo, Day is Not Last Day in Month.";

    //if (IsLastMonthInYear(DateRead.Month))
    //    cout << "\nYes, Month is Last Month in Year.";
    //else
    //    cout << "\nNo, Month is Not Last Month in Year.";


    cout << "\n===========================================================================\n";
    //#16
    //stDate Date3 = ReadFullDate();
    ////Date3 = IncreaseDateByOneDay(Date3);
    //Date3 = IncreaseDateByOneDay_Dr_Solution(Date3);
    //cout << "\nDate After Adding One is: ";
    //cout << Date3.Day << "/" << Date3.Month << "/" << Date3.Year;


    cout << "\n===========================================================================\n";
    //#17
    //stDate Date1 = ReadFullDate();
    //stDate Date2 = ReadFullDate();

    //cout << "\nDiffrence is: "
    //    << GetDifferenceInDays(Date1, Date2) << " Day(s).";
    //cout << "\nDiffrence (Including End Day) is: "
    //    << GetDifferenceInDays(Date1, Date2, true) << " Day(s).";

    cout << "\n===========================================================================\n";
    //#18
    //cout << "\nEnter Your Date Of Barth: ";
    //stDate BarthDate = ReadFullDate();
    //stDate SystemDate = GetSystemDate();
    //cout << "\nYour Age is : "
    //    << GetDifferenceInDays(BarthDate, SystemDate, true) << " Day(s).";


    cout << "\n===========================================================================\n";
    //#19
    //stDate Date1 = ReadFullDate();
    //stDate Date2 = ReadFullDate();
    //cout << "\nDiffrence is: "
    //    << GetDifferenceInDays(Date1, Date2) << " Day(s).";
    //cout << "\nDiffrence (Including End Day) is: "
    //    << GetDifferenceInDays(Date1, Date2, true) << " Day(s).";

    cout << "\n===========================================================================\n";
    //#20 to #32
    stDate Date1 = ReadFullDate();
    cout << "\nDate After: \n";
    Date1 = IncreaseDateByOneDay(Date1);
    cout << "\n01-Adding one day is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByXDays(10, Date1);
    cout << "\n02-Adding 10 days is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByOneWeek(Date1);
    cout << "\n03-Adding one week is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByXWeeks(10, Date1);
    cout << "\n04-Adding 10 weeks is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByOneMonth(Date1);
    cout << "\n05-Adding one month is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByXMonths(5, Date1);
    cout << "\n06-Adding 5 months is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByOneYear(Date1);
    cout << "\n07-Adding one year is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByXYears(10, Date1);
    cout << "\n08-Adding 10 Years is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByXYearsFaster(10, Date1);
    cout << "\n09-Adding 10 Years (faster) is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByOneDecade(Date1);
    cout << "\n10-Adding one Decade is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByXDecades(10, Date1);
    cout << "\n11-Adding 10 Decades is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByXDecadesFaster(10, Date1);
    cout << "\n12-Adding 10 Decade (faster) is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByOneCentury(Date1);
    cout << "\n13-Adding One Century is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    Date1 = IncreaseDateByOneMillennium(Date1);
    cout << "\n14-Adding One Millennium is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    system("pause>0");
    return 0;
}

