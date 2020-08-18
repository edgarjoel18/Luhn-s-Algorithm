/****************************************************************
*
* File: Credit Card Validation
* By: Edgar Catalan
* Date: June 29,2020
*
* Description: This program checks an input of credit card numbers from a vector. isValidCC checks
* returns true if the credit card number is valid. Otherwise, false.
*
****************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>


//It was orginally bool isvalidcc(const string&);
bool isvalidcc(const std::string &input){
    /* First double every second right to left. If doubling of a digit results in a two digit number, add
     the two digits to get a single digit number */
    
    int temp = 0;
    int total = 0; // total inlcuding sum and odds
    int sumOfEvens = 0;
    int sumOfOdds = 0;

    /*The for loop begins at the end of the string values */
    for(int even = (input.size()-2), odd = (input.size()-1); even>=0 || odd>=0; even = even - 2, odd = odd - 2){

        if(even >= 0){
            // Multiply from the right end of the int by 2
            temp = 2 * std::stoi(input.substr(even,1));

            if(temp > 9){// if the even value is double digit
                temp = (temp/10) + (temp % 10);
            }
            sumOfEvens = sumOfEvens + temp;
        }
        // add the numbers in the odd places
        sumOfOdds = sumOfOdds + std::stoi(input.substr(odd,1));
    }
    /* Finally check to see if the total is divisible by 10. If it is return true, otherwise false */
    total = sumOfEvens + sumOfOdds;
    return (total % 10 == 0)? true : false; // if the total is divisible by 10 it has a remainder 0 hence, it is divisible by 10
}

int main()
{
    //
    // PLEASE DO NOT CHANGE function main
    //
    std::vector<std::string> cardnumbers = {
         "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
        "4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
        "5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
        "4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
        "5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
         "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
        "4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
        "5556551555555557", "6011316011016011"
    };
//    int arr[] ={1,2,3,45};
//    int length = sizeof(arr)/sizeof(arr[0]);
//    std::cout<< length;

    int i;
    std::vector<std::string>::iterator itr;

    for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
        std::cout << std::setw(2)  << i << " "
             << std::setw(17) << *itr
             << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << std::endl;
    }

    return 0;
}


