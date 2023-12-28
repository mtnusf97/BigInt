/**
 * @file demo.cpp
 * @author Matin Yousefabadi (mtnusf97@gmail.com)
 * @brief Demo of the bigint header
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream> 
#include <stdexcept>
#include "bigint.hpp"

int main()  
{
    // BigInt = ("-0")
    BigInt bigint0("-0");
    cout << "bigint0 is: " << bigint0 << "\n";

    // default constructor
    BigInt bigint1;
    cout << "default constructor -> bigint1 = " << bigint1 << "\n";

    // constructing a BigInt with 64-bit integer
    BigInt bigint2 = 136124642;
    cout << "creating bigint from integer -> bigint2 = " << bigint2 << "\n";

    // constructing a BigInt with string
    BigInt bigint3("00005125123561263163415613412415636514124213561261");
    cout << "creating bigint from string -> bigint3 = " << bigint3 << "\n";

    // construct a BigInt with string with zeros in the beginning
    BigInt bigint4("000012515415636514124213561261");
    cout << "creating bigint from string with zeros in the beginning-> bigint4 = " << bigint4 << "\n";

    // trying to construct a BigInt with string that can't be seen as a number
    try
    {
        BigInt bigint5("00215@asga412sdar40012515415636514124213561261");
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

    // construct BigInt from another BigInt
    BigInt bigint5(bigint3);
    cout << "used bigint3 to create bigint5 -> bigint5 = " << bigint5 << "\n";
    
    // assign one BigInt object to another BigInt object
    bigint2 = bigint1;
    cout << "is bigint2 == bigint1? " << (bigint2 == bigint1) << "\n";

    // assign a string object to a BigInt object
    string str1 = "125125214151";
    bigint2 = str1;
    cout << "after assigning '125125214151' as a string in bigint2, bigint2 = " << bigint2 << "\n";
    
    // assign an integer to a BigInt object
    int16_t number = 1251;
    bigint2 = number;
    cout << "after assigning 1252 as a string in bigint2, bigint2 = " << bigint2 << "\n";

    // +before a BigInt shouldn't do anything
    cout << "+bigint2: " << +bigint2 << " bigint2: " << bigint2 << "\n";

    // -before a BigInt should return it's negative
    cout << "-bigint2: " << -bigint2 << " bigint2: " << bigint2 << "\n";

    // BigInt object += BigInt object
    cout << "operator+= \n========= \n";
    // scenario1: this.sign == other.sign == '+'
    BigInt bigint6("152341516164516");
    BigInt bigint7("1423421361060001009");
    cout << "scenario1: this.sign == other.sign == '+' \n";
    cout << "bigint6 = " << bigint6 << ", bigint7 = " << bigint7 << " -> doing bigint6 += bigint7 :: ";
    bigint6 += bigint7;
    cout << "bigint6 = " << bigint6 << "\n";

    // scenario2: this.sign == other.sign == '-'
    BigInt bigint8("-152341516164516");
    BigInt bigint9("-1423421361060001009");
    cout << "scenario2: this.sign == other.sign == '-' \n";
    cout << "bigint8 = " << bigint8 << ", bigint9 = " << bigint9 << " -> doing bigint8 += bigint9 :: ";
    bigint8 += bigint9;
    cout << "bigint8 = " << bigint8 << "\n";

    // scenario3: this.sign == '-' && other.sign == '+'
    BigInt bigint10("-152341516164516");
    BigInt bigint11("1423421361060001009");
    cout << "scenario3: this.sign == '-' && other.sign == '+' \n";
    cout << "bigint10 = " << bigint10 << ", bigint11 = " << bigint11 << " -> doing bigint10 += bigint11 :: ";
    bigint10 += bigint11;
    cout << "bigint10 = " << bigint10 << "\n";

    // BigInt object += string object
    BigInt bigint10_("-152341516164516");
    string string11 = "1423421361060001009";
    bigint10_ += string11;
    cout << "bigint10 += string11 -> " << bigint10_ << "\n";

    // BigInt object += 64-bit integer object
    BigInt bigint10__("-152341516164516");
    int64_t int11 = 1423421361060001009;
    bigint10__ += int11;
    cout << "bigint10 += string11 -> " << bigint10__ << "\n";

    // BigInt object -= BigInt object
    cout << "operator-= \n========= \n";
    // scenario1: this.sign == other.sign == '+'
    BigInt bigint12("152341516164516");
    BigInt bigint13("1423421361060001009");
    cout << "scenario1: this.sign == other.sign == '+' \n";
    cout << "bigint12 = " << bigint12 << ", bigint13 = " << bigint13 << " -> doing bigint12 -= bigint13 :: ";
    bigint12 -= bigint13;
    cout << "bigint12 = " << bigint12 << "\n";

    // scenario2: this.sign == other.sign == '-'
    BigInt bigint14("-152341516164516");
    BigInt bigint15("-1423421361060001009");
    cout << "scenario2: this.sign == other.sign == '-' \n";
    cout << "bigint14 = " << bigint14 << ", bigint15 = " << bigint15 << " -> doing bigint14 -= bigint15 :: ";
    bigint14 -= bigint15;
    cout << "bigint14 = " << bigint14 << "\n";

    // scenario3: this.sign == '-' && other.sign == '+'
    BigInt bigint16("-152341516164516");
    BigInt bigint17("1423421361060001009");
    cout << "scenario3: this.sign == '-' && other.sign == '+' \n";
    cout << "bigint16 = " << bigint16 << ", bigint17 = " << bigint17 << " -> doing bigint16 -= bigint17 :: ";
    bigint16 -= bigint17;
    cout << "bigint16 = " << bigint16 << "\n";

    // BigInt object -= string object
    BigInt bigint16_("-152341516164516");
    string string17 = "1423421361060001009";
    bigint16_ -= string11;
    cout << "bigint16 -= string17 -> " << bigint16_ << "\n";

    // BigInt object -= 64-bit integer object
    BigInt bigint16__("-152341516164516");
    int64_t int17 = 1423421361060001009;
    bigint16__ -= int17;
    cout << "bigint16 -= int17 -> " << bigint16__ << "\n";

    // BigInt object = BigInt object + BigInt object
    BigInt bigint18("152341516164516");
    BigInt bigint19("1423421361060001009");
    BigInt bigint20 = bigint18 + bigint19;
    cout << "bigint20 = bigint18 + bigint19 = " << bigint20 << "\n";

    // BigInt object = BigInt object + string object
    string string19 = "1423421361060001009";
    bigint20 = bigint18 + string19;
    cout << "bigint20 = bigint18 + string19 = " << bigint20 << "\n";

    // BigInt object = string object + BigInt object
    bigint20 = string19 + bigint18;
    cout << "bigint20 = string19 + bigint18 = " << bigint20 << "\n";

    // BigInt object = BigInt object + 64-bit integer object
    int64_t int19 = 1423421361060001009;
    bigint20 = bigint18 + int19;
    cout << "bigint20 = bigint18 + int19 = " << bigint20 << "\n";

    // BigInt object = 64-bit integer object + BigInt object
    bigint20 = int19 + bigint18;
    cout << "bigint20 = int19 + bigint18 = " << bigint20 << "\n";

    // BigInt object = BigInt object - BigInt object
    BigInt bigint21("152341516164516");
    BigInt bigint22("1423421361060001009");
    BigInt bigint23 = bigint21 - bigint22;
    cout << "bigint23 = bigint21 - bigint22 = " << bigint23 << "\n";

    // BigInt object = BigInt object - string object
    string string22 = "1423421361060001009";
    bigint23 = bigint21 - string22;
    cout << "bigint23 = bigint21 - string22 = " << bigint23 << "\n";

    // BigInt object = string object - BigInt object
    bigint23 = string22 - bigint21;
    cout << "bigint23 = string22 - bigint21 = " << bigint23 << "\n";

    // BigInt object = BigInt object - 64-bit integer object
    int64_t int22 = 1423421361060001009;
    bigint23 = bigint21 - int22;
    cout << "bigint23 = bigint21 - int22 = " << bigint23 << "\n";

    // BigInt object = 64-bit integer object - BigInt object
    bigint23 = int22 - bigint21;
    cout << "bigint23 = int22 - bigint21 = " << bigint23 << "\n";

    // BigInt object *= BigInt object
    BigInt bigint24("152341516164516");
    BigInt bigint25("1423421361060001009");
    cout << "bigint25 = " << bigint25 << ", bigint24 = " << bigint24 << " -> doing bigint25 *= bigint24 :: ";
    bigint25 *= bigint24;
    cout << "bigint25 = " << bigint25 << "\n";

    // BigInt object *= string object
    BigInt bigint24_("152341516164516");
    string string25 = "1423421361060001009";
    bigint24_ *= string25;
    cout << "bigint24 *= string25 -> " << bigint24_ << "\n";

    // BigInt object *= 64-bit integer object
    BigInt bigint24__("152341516164516");
    int64_t int25 = 1423421361060001009;
    bigint24__ *= int25;
    cout << "bigint24 *= int25 -> " << bigint24__ << "\n";

    // BigInt object = BigInt object * BigInt object
    BigInt bigint26("152341516164516");
    BigInt bigint27("1423421361060001009");
    BigInt bigint28 = bigint26 * bigint27;
    cout << "bigint28 = bigint26 * bigint27 = " << bigint28 << "\n";

    // BigInt object = BigInt object * string object
    string string27 = "1423421361060001009";
    bigint28 = bigint26 * string27;
    cout << "bigint28 = bigint26 * string22 = " << bigint28 << "\n";

    // BigInt object = string object * BigInt object
    bigint28 = string27 * bigint26;
    cout << "bigint28 = string27 * bigint26 = " << bigint28 << "\n";

    // BigInt object = BigInt object * 64-bit integer object
    int64_t int27 = 1423421361060001009;
    bigint28 = bigint26 * int27;
    cout << "bigint28 = bigint26 * int27 = " << bigint28 << "\n";

    // BigInt object = 64-bit integer object * BigInt object
    bigint28 = int27 * bigint26;
    cout << "bigint28 = int27 * bigint26 = " << bigint28 << "\n";

    // BigInt object == BigInt object
    BigInt bigint29("152341516164516");
    BigInt bigint30("152341516164516");
    BigInt bigint31("-152341516164516");
    BigInt bigint32(1423421361001009);
    cout << "bigint29 == bigint30 ? " << (bigint29 == bigint30 ? "Yes" : "No") << "\n";
    cout << "bigint29 == bigint31 ? " << (bigint29 == bigint31 ? "Yes" : "No") << "\n";
    cout << "bigint29 == bigint32 ? " << (bigint29 == bigint32 ? "Yes" : "No") << "\n";

    // BigInt object == string object
    string string30 = "152341516164516";
    cout << "bigint29 == string30 ? " << (bigint29 == string30 ? "Yes" : "No") << "\n";

    // string object == BigInt object
    cout << "string30 == bigint29 ? " << (string30 == bigint29 ? "Yes" : "No") << "\n";

    // BigInt object == 64-bit integer object
    int64_t int30 = 152341516164516;
    cout << "bigint29 == int30 ? " << (bigint29 == int30 ? "Yes" : "No") << "\n";

    // BigInt object == 64-bit integer object
    cout << "int30 == bigint29 ? " << (int30 == bigint29 ? "Yes" : "No") << "\n";

    // BigInt object != BigInt object
    cout << "bigint29 != bigint30 ? " << (bigint29 != bigint30 ? "Yes" : "No") << "\n";
    cout << "bigint29 != bigint31 ? " << (bigint29 != bigint31 ? "Yes" : "No") << "\n";
    cout << "bigint29 != bigint32 ? " << (bigint29 != bigint32 ? "Yes" : "No") << "\n";

    // BigInt object != string object
    cout << "bigint29 != string30 ? " << (bigint29 != string30 ? "Yes" : "No") << "\n";

    // string object != BigInt object
    cout << "string30 != bigint29 ? " << (string30 != bigint29 ? "Yes" : "No") << "\n";

    // BigInt object != 64-bit integer object
    cout << "bigint29 != int30 ? " << (bigint29 != int30 ? "Yes" : "No") << "\n";

    // BigInt object != 64-bit integer object
    cout << "int30 != bigint29 ? " << (int30 != bigint29 ? "Yes" : "No") << "\n";

    // BigInt object > BigInt object
    cout << "bigint29 > bigint30 ? " << (bigint29 > bigint30 ? "Yes" : "No") << "\n";
    cout << "bigint29 > bigint31 ? " << (bigint29 > bigint31 ? "Yes" : "No") << "\n";
    cout << "bigint29 > bigint32 ? " << (bigint29 > bigint32 ? "Yes" : "No") << "\n";

    // BigInt object > string object
    cout << "bigint29 > string30 ? " << (bigint29 > string30 ? "Yes" : "No") << "\n";

    // string object > BigInt object
    cout << "string30 > bigint29 ? " << (string30 > bigint29 ? "Yes" : "No") << "\n";

    // BigInt object > 64-bit integer object
    cout << "bigint29 > int30 ? " << (bigint29 > int30 ? "Yes" : "No") << "\n";

    // BigInt object > 64-bit integer object
    cout << "int30 > bigint29 ? " << (int30 > bigint29 ? "Yes" : "No") << "\n";

    // BigInt object < BigInt object
    cout << "bigint29 < bigint30 ? " << (bigint29 < bigint30 ? "Yes" : "No") << "\n";
    cout << "bigint29 < bigint31 ? " << (bigint29 < bigint31 ? "Yes" : "No") << "\n";
    cout << "bigint29 < bigint32 ? " << (bigint29 < bigint32 ? "Yes" : "No") << "\n";

    // BigInt object < string object
    cout << "bigint29 < string30 ? " << (bigint29 < string30 ? "Yes" : "No") << "\n";

    // string object < BigInt object
    cout << "string30 < bigint29 ? " << (string30 < bigint29 ? "Yes" : "No") << "\n";

    // BigInt object < 64-bit integer object
    cout << "bigint29 < int30 ? " << (bigint29 < int30 ? "Yes" : "No") << "\n";

    // BigInt object < 64-bit integer object
    cout << "int30 < bigint29 ? " << (int30 < bigint29 ? "Yes" : "No") << "\n";

    // BigInt object >= BigInt object
    cout << "bigint29 >= bigint30 ? " << (bigint29 >= bigint30 ? "Yes" : "No") << "\n";
    cout << "bigint29 >= bigint31 ? " << (bigint29 >= bigint31 ? "Yes" : "No") << "\n";
    cout << "bigint29 >= bigint32 ? " << (bigint29 >= bigint32 ? "Yes" : "No") << "\n";

    // BigInt object >= string object
    cout << "bigint29 >= string30 ? " << (bigint29 >= string30 ? "Yes" : "No") << "\n";

    // string object >= BigInt object
    cout << "string30 >= bigint29 ? " << (string30 >= bigint29 ? "Yes" : "No") << "\n";

    // BigInt object >= 64-bit integer object
    cout << "bigint29 >= int30 ? " << (bigint29 >= int30 ? "Yes" : "No") << "\n";

    // BigInt object >= 64-bit integer object
    cout << "int30 >= bigint29 ? " << (int30 >= bigint29 ? "Yes" : "No") << "\n";

    // BigInt object <= BigInt object
    cout << "bigint29 <= bigint30 ? " << (bigint29 <= bigint30 ? "Yes" : "No") << "\n";
    cout << "bigint29 <= bigint31 ? " << (bigint29 <= bigint31 ? "Yes" : "No") << "\n";
    cout << "bigint29 <= bigint32 ? " << (bigint29 <= bigint32 ? "Yes" : "No") << "\n";

    // BigInt object <= string object
    cout << "bigint29 <= string30 ? " << (bigint29 <= string30 ? "Yes" : "No") << "\n";

    // string object <= BigInt object
    cout << "string30 <= bigint29 ? " << (string30 <= bigint29 ? "Yes" : "No") << "\n";

    // BigInt object <= 64-bit integer object
    cout << "bigint29 <= int30 ? " << (bigint29 <= int30 ? "Yes" : "No") << "\n";

    // BigInt object <= 64-bit integer object
    cout << "int30 <= bigint29 ? " << (int30 <= bigint29 ? "Yes" : "No") << "\n";
}
