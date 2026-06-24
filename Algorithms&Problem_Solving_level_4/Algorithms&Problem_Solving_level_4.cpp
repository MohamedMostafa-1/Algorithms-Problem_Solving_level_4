#include <iostream>
#include <string>

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

int main()
{
    int Number = ReadNumber();
    cout << endl << NumberToText(Number) << endl;
    system("pause>0");
    return 0;
}

