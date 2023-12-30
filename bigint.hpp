/**
 * @file bigint.hpp
 * @author Matin Yousefabadi (mtnusf97@gmail.com)
 * @brief A header file to create a BigInt object in c++ with no size limitation.
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


/**********************************************************************
*************************** BIGINT CLASS ******************************
**********************************************************************/

class BigInt 
{
    public:
        // default constructor        
        BigInt();
        // constructing from another 64-bit integer
        BigInt(const int64_t&);
        // constructing from a string
        BigInt(const string&);

        // assignment of an int to BigInt
        BigInt& operator=(const int64_t&);
        // assignment of a string to BigInt
        BigInt& operator=(const string&);

        // overloaded +bigint
        BigInt operator+() const;
        // -bigint
        BigInt operator-() const;

        BigInt& operator+=(const BigInt&);
        // overloaded BigInt += 64-bit integer
        BigInt& operator+=(const int64_t&);
        // overloaded BigInt += string
        BigInt& operator+=(const string&);

        // overloaded BigInt -= BigInt
        BigInt& operator-=(const BigInt&);
        // overloaded BigInt -= 64-bit integer
        BigInt& operator-=(const int64_t&);
        // overloaded BigInt -= string
        BigInt& operator-=(const string&);

        // overloaded BigInt *= BigInt
        BigInt& operator*=(const BigInt&);
        // overloaded BigInt *= 64-bit integer
        BigInt& operator*=(const int64_t&);
        // overloaded BigInt *= string
        BigInt& operator*=(const string&);

        // get sign and value
        char get_sign() const;
        string get_abs_value() const;
            
        // << stream
        friend ostream& operator<<(ostream&, const BigInt&);

    private:
        string abs_value;
        char sign;
};

// overloaded BigInt + BigInt
BigInt operator+(BigInt lhs, const BigInt& rhs);

// overloaded BigInt + string
BigInt operator+(const BigInt& lhs, const string& rhs);

// overloaded string + BigInt
BigInt operator+(const string& lhs, const BigInt& rhs);

// overloaded BigInt + 64-bit integer
BigInt operator+(const BigInt& lhs, const int64_t& rhs);

// overloaded 64-bit integer + BigInt
BigInt operator+(const int64_t& lhs, BigInt rhs);

// overloaded BigInt - BigInt
BigInt operator-(BigInt lhs, const BigInt& rhs);

// overloaded BigInt - string
BigInt operator-(const BigInt& lhs, const string& rhs);

// overloaded string - BigInt
BigInt operator-(const string& lhs, const BigInt& rhs);

// overloaded BigInt - 64-bit integer
BigInt operator-(const BigInt& lhs, const int64_t& rhs);

// overloaded 64-bit integer - BigInt
BigInt operator-(const int64_t& lhs, BigInt rhs);

// overloaded BigInt * BigInt
BigInt operator*(BigInt lhs, const BigInt& rhs);

// overloaded BigInt * string
BigInt operator*(const BigInt& lhs, const string& rhs);

// overloaded string * BigInt
BigInt operator*(const string& lhs, const BigInt& rhs);

// overloaded BigInt * 64-bit integer
BigInt operator*(const BigInt& lhs, const int64_t& rhs);

// overloaded 64-bit integer * BigInt
BigInt operator*(const int64_t& lhs, BigInt rhs);

// overloaded BigInt == BigInt
bool operator==(const BigInt& lhs, const BigInt& rhs);

// overloaded BigInt == string
bool operator==(const BigInt& lhs, const string& rhs);

// overloaded string == BigInt
bool operator==(const string& lhs, const BigInt& rhs);

// overloaded 64-bit integer == BigInt
bool operator==(const int64_t& lhs, const BigInt& rhs);

// overloaded BigInt == 64-bit integer
bool operator==(const BigInt& lhs, const int64_t& rhs);

// overloaded BigInt != BigInt
bool operator!=(const BigInt& lhs, const BigInt& rhs);

// overloaded BigInt != string
bool operator!=(const BigInt& lhs, const string& rhs);

// overloaded string != BigInt
bool operator!=(const string& lhs, const BigInt& rhs);

// overloaded 64-bit integer != BigInt
bool operator!=(const int64_t& lhs, const BigInt& rhs);

// overloaded BigInt != 64-bit integer
bool operator!=(const BigInt& lhs, const int64_t& rhs);

// overloaded BigInt > BigInt
bool operator>(const BigInt& lhs, const BigInt& rhs);

// overloaded BigInt > string
bool operator>(const BigInt& lhs, const string& rhs);

// overloaded string > BigInt
bool operator>(const string& lhs, const BigInt& rhs);

// overloaded 64-bit integer > BigInt
bool operator>(const int64_t& lhs, const BigInt& rhs);

// overloaded BigInt > 64-bit integer
bool operator>(const BigInt& lhs, const int64_t& rhs);

// overloaded BigInt < BigInt
bool operator<(const BigInt& lhs, const BigInt& rhs);

// overloaded BigInt < string
bool operator<(const BigInt& lhs, const string& rhs);

// overloaded string < BigInt
bool operator<(const string& lhs, const BigInt& rhs);

// overloaded 64-bit integer < BigInt
bool operator<(const int64_t& lhs, const BigInt& rhs);

// overloaded BigInt < 64-bit integer
bool operator<(const BigInt& lhs, const int64_t& rhs);

// overloaded BigInt >= BigInt
bool operator>=(const BigInt& lhs, const BigInt& rhs);

// overloaded BigInt >= string
bool operator>=(const BigInt& lhs, const string& rhs);

// overloaded string >= BigInt
bool operator>=(const string& lhs, const BigInt& rhs);

// overloaded 64-bit integer >= BigInt
bool operator>=(const int64_t& lhs, const BigInt& rhs);

// overloaded BigInt >= 64-bit integer
bool operator>=(const BigInt& lhs, const int64_t& rhs);

// overloaded BigInt <= BigInt
bool operator<=(const BigInt& lhs, const BigInt& rhs);

// overloaded BigInt <= string
bool operator<=(const BigInt& lhs, const string& rhs);

// overloaded string <= BigInt
bool operator<=(const string& lhs, const BigInt& rhs);

// overloaded 64-bit integer <= BigInt
bool operator<=(const int64_t& lhs, const BigInt& rhs);

// overloaded BigInt <= 64-bit integer
bool operator<=(const BigInt& lhs, const int64_t& rhs);

/**********************************************************************
*********************** AUXILIARY FUNCTIONS ***************************
**********************************************************************/

/**
 * @brief is_number checks if a string can be interpreted as an integer
 * 
 * @param str the input string
 * @return true if the string can be seen as an integer
 * @return false else. e.g. "23451515gsgas51235124asfq" can't be seen as an integer
 */
bool is_number(const string& str) 
{
    int64_t ascii_0 = int('0');
    int64_t ascii_9 = int('9');
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i] < ascii_0 or str[i] > ascii_9)
            return false;
    }
    return true;
}

/**
 * @brief remove_left_zeros removes zeros before a number starts from it's string representation
 * 
 * @param str the input string
 */
string remove_left_zeros(string& str) 
{
    char zero = str[0];
    size_t idx = 0;
    while (zero == '0') 
    {
        idx++;
        zero = str[idx];
    }
    str = str.substr(idx);
    if(str.size() == 0)
        str = "0";
        
    return str;
}

/**
 * @brief sum two large numbers represented as strings, without signs
 * 
 * @param str1 
 * @param str2 
 * @return string:: sum result
 */
string positive_sum(const string& str1, const string& str2)
{
    // create a vector and push back the first input as in int in reverse (for easier addition)
    vector<int64_t> str1_v;
    for (size_t i = str1.size(); i >= 1; i--)
        str1_v.push_back(str1[i - 1] - '0');

    // create a vector and push back the second input as in int in reverse (for easier addition)
    vector<int64_t> str2_v;
    for (size_t i = str2.size(); i >= 1; i--)
        str2_v.push_back(str2[i - 1] - '0');

    // add 0 padding to the smaller one
    while (str1_v.size() < str2_v.size()) 
        str1_v.push_back(0);
    while (str2_v.size() < str1_v.size()) 
        str2_v.push_back(0);

    string sum;
    int64_t carry = 0;
    // addition loop
    for (uint64_t i = 0; i < str1_v.size(); i++) 
    {
        int64_t sum_i = str1_v[i] + str2_v[i] + carry;
        sum += to_string(sum_i % 10);
        carry = sum_i / 10;
    }
    if(carry != 0)
        sum += to_string(carry);

    // sum is reversed, so reversing it back
    reverse(sum.begin(), sum.end());
    return sum;
}

/**
 * @brief subtract two large numbers represented as strings. 
 * For correct results str1 should represent a larger number than what str2 represents
 * 
 * @param str1 
 * @param str2 
 * @return string:: subtract result
 */
string positive_subtract(const string& str1, const string& str2)
{
    // create a vector and push back the first input as in int in reverse (for easier subtraction)
    vector<int64_t> str1_v;
    for (size_t i = str1.size(); i >= 1; i--)
        str1_v.push_back(str1[i - 1] - '0');
    
    // create a vector and push back the second input as in int in reverse (for easier subtraction)
    vector<int64_t> str2_v;
    for (size_t i = str2.size(); i >= 1; i--)
        str2_v.push_back(str2[i - 1] - '0');

    // add 0 padding to the smaller one
    while (str1_v.size() < str2_v.size()) 
        str1_v.push_back(0);
    while (str2_v.size() < str1_v.size()) 
        str2_v.push_back(0);

    vector<int64_t> result;
    string sub;
    // subtraction loop
    for (size_t i = 0; i < str1_v.size(); i++)
    {
        int64_t up_num = str1_v[i];
        int64_t down_num = str2_v[i];
        
        if (up_num < down_num)
        {
            up_num += 10;
            str1_v[i + 1] -= 1;
        }
        result.push_back(up_num - down_num);
        sub += to_string(up_num - down_num);
    }

    // sub is reversed, so reversing it back
    reverse(sub.begin(), sub.end());
    return remove_left_zeros(sub);
}

/**
 * @brief sum two large numbers represented as strings, without signs
 * 
 * @param str1 
 * @param str2 
 * @return string:: product result
 */
string positive_multiply(const string& str1, const string& str2)
{
    // create a vector and push back the first input as in int 
    // in reverse (for easier multiplication)
    vector<int64_t> str1_v;
    for (size_t i = str1.size(); i >= 1; i--)
        str1_v.push_back(str1[i - 1] - '0');

    // create a vector and push back the second input as in int in 
    // reverse (for easier multiplication)
    vector<int64_t> str2_v;
    for (size_t i = str2.size(); i >= 1; i--)
        str2_v.push_back(str2[i - 1] - '0');

    // product is the final vector result (m-digit * n-digit has at most (m + n) digits)
    vector<int64_t> product(str1_v.size() + str2_v.size(), 0);
    
    // multiplication loop
    for (size_t i = 0; i < str1_v.size(); i++)
    {
        for (size_t j = 0; j < str2_v.size(); ++j)
        {
            product[i + j] += str1_v[i] * str2_v[j];
            if (product[i + j] >= 10) {
                product[i + j + 1] += product[i + j] / 10;
                product[i + j] %= 10;
            }
        }
    }
    
    // create string version of product
    string product_str;
    for (size_t i = product.size(); i >= 1; i--)
    {
        product_str += to_string(product[i - 1]);
    }

    // remove zeros in the beginning
    return remove_left_zeros(product_str);
}

/**
 * @brief checks if the first abs_value is greater than the second
 * 
 * @param str1 
 * @param str2 
 * @return true abs_val1 > abs_val2
 * @return false abs_val2 >= abs_val1
 */
bool is_first_abs_value_greater(const string& abs_val1, const string& abs_val2)
{
    if(abs_val1.length() == abs_val2.length())
        return abs_val1 > abs_val2;
    else
        return abs_val1.length() > abs_val2.length() ? true : false;
}

/**********************************************************************
************************** MEMBER FUNCTIONS ***************************
**********************************************************************/

/**
 * @brief get sign of a BigInt object
 * 
 * @return char 
 */
char BigInt::get_sign() const
{
    return sign;
}

/**
 * @brief get absolute value of a BigInt object
 * 
 * @return char 
 */
string BigInt::get_abs_value() const
{
    return abs_value;
}

/**********************************************************************
*************************** CONSTRUCTORS ******************************
**********************************************************************/

/**
 * @brief Default Constructor of a new BigInt:: BigInt object
 * 
 */
BigInt::BigInt() 
{
    abs_value = "0";
    sign = '+';
}

/**
 * @brief Construct a new BigInt from 64-bit integer:: BigInt object
 * 
 * @param str is a 64-bit integer
 */
BigInt::BigInt(const int64_t& number) 
{
    abs_value = to_string(abs(number));
    if (number < 0)
        sign = '-';
    else
        sign = '+';
}

/**
 * @brief Construct a new BigInt from string:: BigInt object
 * 
 * @param str is a string
 */
BigInt::BigInt(const string& str) 
{

    if(str[0] == '+' or str[0] == '-')
    {
        if(is_number(str.substr(1)))
        {
            abs_value = str.substr(1);
            abs_value = remove_left_zeros(abs_value);
            sign = abs_value == "0" ? '+' : '-' ;
        }
        else
        {
            throw invalid_argument(str + " is not a valid integer!");
        }
    }
    else
    {
        if(is_number(str))
        {
            abs_value = str;
            abs_value = remove_left_zeros(abs_value);
            sign = '+';
        }
        else
        {
            throw invalid_argument(str + " is not a valid integer!");
        }
    }

}

/**********************************************************************
*************************** ASSIGNMENT = ******************************
**********************************************************************/

/**
 * @brief assigning a previously defined 64-bit integer to a BigInt object
 * 
 * @param number 
 * @return BigInt& 
 */
BigInt& BigInt::operator=(const int64_t& number) 
{

    abs_value = to_string(abs(number));
    if (number < 0)
        sign = '-';
    else
        sign = '+';

    return *this;
}

/**
 * @brief assigning a previously defined string to a BigInt object
 * 
 * @param str 
 * @return BigInt& 
 */
BigInt& BigInt::operator=(const string& str) 
{
    if(str[0] == '+' or str[0] == '-')
    {
        if(is_number(str.substr(1)))
        {
            abs_value = str.substr(1);
            abs_value = remove_left_zeros(abs_value);
            sign = abs_value == "0" ? '+' : '-' ;
        }
        else
        {
            throw invalid_argument(str + " is not a valid integer!");
        }
    }
    else
    {
        if(is_number(str))
        {
            abs_value = str;
            abs_value = remove_left_zeros(abs_value);
            sign = '+';
        }
        else
        {
            throw invalid_argument(str + " is not a valid integer!");
        }
    }
    return *this;
}

/**********************************************************************
*********************** NEGATION (UNARY - +) **************************
**********************************************************************/

/**
 * @brief returns negative of the BigInt object.
 * 
 * @return BigInt 
 */
BigInt BigInt::operator-() const 
{
    BigInt res;
    if(abs_value == "0")
        return res;
    else
    {
        res.abs_value = abs_value;
        res.sign = (sign == '-') ? '+' : '-';
        return res;
    }
}

/**
 * @brief doesn't do anything to the input BigInt. implemented solely 
 * for completeness.
 * 
 * @return BigInt 
 */
BigInt BigInt::operator+() const 
{
    return *this;
}

/**********************************************************************
************************* ADDITION (+= +) *****************************
**********************************************************************/

/**
 * @brief implementing operator += between two BigInt objects
 * it uses the auxiliary functions positive_sum and positive_subtract 
 * 
 * @param other 
 * @return BigInt& sum of inputs
 */
BigInt& BigInt::operator+=(const BigInt& other)
{
    if(sign == other.sign)
    {
        abs_value = positive_sum(abs_value, other.abs_value);
        return *this;
    }
    else
    {
        if(is_first_abs_value_greater(abs_value, other.abs_value))
        {
            abs_value = positive_subtract(abs_value, other.abs_value);
            return *this;
        }
        else
        {
            abs_value = positive_subtract(other.abs_value, abs_value);
            sign = sign == '+'? '-': '+';
            return *this;
        }
    }
}

/**
 * @brief implementing operator += between BigInt objects and string objects
 * 
 * @param other 
 * @return BigInt& sum of inputs
 */
BigInt& BigInt::operator+=(const string& other)
{
    *this += BigInt(other);
    return *this;
}

/**
 * @brief implementing operator += between BigInt objects and 
 * 64-bit integer objects
 * 
 * @param other 
 * @return BigInt& sum of inputs
 */
BigInt& BigInt::operator+=(const int64_t& other)
{
    *this += BigInt(other);
    return *this;
}

/**
 * @brief adding two BigInt objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator+(BigInt lhs, const BigInt& rhs)
{
    return lhs += rhs;
}

/**
 * @brief adding BigInt object to string objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator+(const BigInt& lhs, const string& rhs)
{
    return lhs + BigInt(rhs);
}

/**
 * @brief adding string object to BigInt objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator+(const string& lhs, const BigInt& rhs)
{
    return BigInt(lhs) + rhs;
}

/**
 * @brief adding BigInt object to 64-bit integer objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator+(const BigInt& lhs, const int64_t& rhs)
{
    return lhs + BigInt(rhs);
}

/**
 * @brief adding 64-bit integer objects to BigInt object
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator+(const int64_t& lhs, BigInt rhs)
{
    return BigInt(lhs) + rhs;
}

/**********************************************************************
************************ SUBTRACTION (- -=) ***************************
**********************************************************************/

/**
 * @brief implementing operator -= between two BigInt objects
 * it uses the auxiliary functions positive_sum and positive_subtract 
 * 
 * @param other 
 * @return BigInt& 
 */
BigInt& BigInt::operator-=(const BigInt& other)
{
    if(sign != other.sign)
    {
        abs_value = positive_sum(abs_value, other.abs_value);
        return *this;
    }
    else
    {
        if(is_first_abs_value_greater(abs_value, other.abs_value))
        {
            abs_value = positive_subtract(abs_value, other.abs_value);
            return *this;
        }
        else
        {
            abs_value = positive_subtract(other.abs_value, abs_value);
            sign = sign == '+'? '-': '+';
            return *this;
        }
    }
}

/**
 * @brief implementing operator -= between BigInt objects and string objects
 * 
 * @param other 
 * @return BigInt& sum of inputs
 */
BigInt& BigInt::operator-=(const string& other)
{
    *this -= BigInt(other);
    return *this;
}

/**
 * @brief implementing operator -= between BigInt objects and 
 * 64-bit integer objects
 * 
 * @param other 
 * @return BigInt& sum of inputs
 */
BigInt& BigInt::operator-=(const int64_t& other)
{
    *this -= BigInt(other);
    return *this;
}

/**
 * @brief subtracting two BigInt objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator-(BigInt lhs, const BigInt& rhs)
{
    return lhs -= rhs;
}

/**
 * @brief subtracting BigInt object to string objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator-(const BigInt& lhs, const string& rhs)
{
    return lhs - BigInt(rhs);
}

/**
 * @brief subtracting string object to BigInt objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator-(const string& lhs, const BigInt& rhs)
{
    return BigInt(lhs) - rhs;
}

/**
 * @brief subtracting BigInt object to 64-bit integer objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator-(const BigInt& lhs, const int64_t& rhs)
{
    return lhs - BigInt(rhs);
}

/**
 * @brief subtracting 64-bit integer objects to BigInt object
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator-(const int64_t& lhs, BigInt rhs)
{
    return BigInt(lhs) - rhs;
}

/**
 * @brief multiplying two BigInt objects
 * 
 * @param lhs 
 * @param rhs 
 * @return BigInt 
 */

/**********************************************************************
********************** MULTIPLICATION (* *=) **************************
**********************************************************************/

/**
 * @brief implementing operator *= between two BigInt objects
 * it uses the auxiliary function positive_multiply 
 * 
 * @param other 
 * @return BigInt& 
 */
BigInt& BigInt::operator*=(const BigInt& other) 
{   
    sign = sign == other.sign ? '+' : '-';
    abs_value = positive_multiply(abs_value, other.abs_value);
    return *this;
}

/**
 * @brief implementing operator *= between BigInt objects and string objects
 * 
 * @param other 
 * @return BigInt& sum of inputs
 */
BigInt& BigInt::operator*=(const string& other)
{
    *this *= BigInt(other);
    return *this;
}

/**
 * @brief implementing operator *= between BigInt objects and 
 * 64-bit integer objects
 * 
 * @param other 
 * @return BigInt& sum of inputs
 */
BigInt& BigInt::operator*=(const int64_t& other)
{
    *this *= BigInt(other);
    return *this;
}

BigInt operator*(BigInt lhs, const BigInt& rhs)
{
    return lhs *= rhs;
}

/**
 * @brief multiplying BigInt object to string objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator*(const BigInt& lhs, const string& rhs)
{
    return lhs * BigInt(rhs);
}

/**
 * @brief multiplying string object to BigInt objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator*(const string& lhs, const BigInt& rhs)
{
    return BigInt(lhs) * rhs;
}

/**
 * @brief multiplying BigInt object to 64-bit integer objects
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator*(const BigInt& lhs, const int64_t& rhs)
{
    return lhs * BigInt(rhs);
}

/**
 * @brief multiplying 64-bit integer objects to BigInt object
 * 
 * @param lhs left operand
 * @param rhs right operand
 * @return BigInt 
 */
BigInt operator*(const int64_t& lhs, BigInt rhs)
{
    return BigInt(lhs) * rhs;
}

/**********************************************************************
**************** COMPARISON (==, !=, <, >, <=, >=) ********************
**********************************************************************/

/**
 * @brief BigInt == BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator==(const BigInt& lhs, const BigInt& rhs)
{
    return (lhs.get_sign() == rhs.get_sign() and 
            lhs.get_abs_value() == rhs.get_abs_value());
}

/**
 * @brief BigInt == string
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator==(const BigInt& lhs, const string& rhs)
{
    BigInt temp_big_int(rhs);
    return ((lhs.get_sign() == temp_big_int.get_sign()) 
            and (lhs.get_abs_value() == temp_big_int.get_abs_value()));
}

/**
 * @brief string == BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator==(const string& lhs, const BigInt& rhs)
{
    BigInt temp_big_int(lhs);
    return ((temp_big_int.get_sign() == rhs.get_sign()) 
            and (temp_big_int.get_abs_value() == rhs.get_abs_value()));
}

/**
 * @brief BigInt == 64-bit integer
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator==(const BigInt& lhs, const int64_t& rhs)
{
    BigInt temp_big_int(rhs);
    return ((lhs.get_sign() == temp_big_int.get_sign()) 
            and (lhs.get_abs_value() == temp_big_int.get_abs_value()));
}

/**
 * @brief 64-bit integer == BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator==(const int64_t& lhs, const BigInt& rhs)
{
    BigInt temp_big_int(lhs);
    return ((temp_big_int.get_sign() == rhs.get_sign()) 
            and (temp_big_int.get_abs_value() == rhs.get_abs_value()));
}

/**
 * @brief BigInt != BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator!=(const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs == rhs);
}

/**
 * @brief BigInt != string
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator!=(const BigInt& lhs, const string& rhs)
{
    return !(lhs == rhs);
}

/**
 * @brief string != BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator!=(const string& lhs, const BigInt& rhs)
{
    return !(lhs == rhs);
}

/**
 * @brief BigInt != 64-bit integer
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator!=(const BigInt& lhs, const int64_t& rhs)
{
    return !(lhs == rhs);
}

/**
 * @brief 64-bit integer != BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator!=(const int64_t& lhs, const BigInt& rhs)
{
    return !(lhs == rhs);
}

/**
 * @brief BigInt > BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator>(const BigInt& lhs, const BigInt& rhs)
{
    if(lhs == rhs)
        return false;
    bool is_lhs_abs_value_greater = is_first_abs_value_greater(lhs.get_abs_value(), 
                                                               rhs.get_abs_value());
    if (lhs.get_sign() == rhs.get_sign())
        return lhs.get_sign() == '+' ? is_lhs_abs_value_greater : !is_lhs_abs_value_greater;
    else
        return lhs.get_sign() == '+' ? true : false;
}

/**
 * @brief BigInt > string
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator>(const BigInt& lhs, const string& rhs)
{
    return lhs > BigInt(rhs);
}

/**
 * @brief string > BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator>(const string& lhs, const BigInt& rhs)
{
    return BigInt(lhs) > rhs;
}

/**
 * @brief BigInt > 64-bit integer
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator>(const BigInt& lhs, const int64_t& rhs)
{
    return lhs > BigInt(rhs);
}

/**
 * @brief 64-bit integer > BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator>(const int64_t& lhs, const BigInt& rhs)
{
    return BigInt(lhs) > rhs;
}

/**
 * @brief BigInt < BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator<(const BigInt& lhs, const BigInt& rhs)
{
    return rhs > lhs;
}

/**
 * @brief BigInt < string
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator<(const BigInt& lhs, const string& rhs)
{
    return lhs < BigInt(rhs);
}

/**
 * @brief string < BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator<(const string& lhs, const BigInt& rhs)
{
    return BigInt(lhs) < rhs;
}

/**
 * @brief BigInt < 64-bit integer
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator<(const BigInt& lhs, const int64_t& rhs)
{
    return lhs < BigInt(rhs);
}

/**
 * @brief 64-bit integer < BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator<(const int64_t& lhs, const BigInt& rhs)
{
    return BigInt(lhs) < rhs;
}

/**
 * @brief BigInt >= BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator>=(const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs < rhs);
}

/**
 * @brief BigInt >= string
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator>=(const BigInt& lhs, const string& rhs)
{
    return !(lhs < rhs);
}

/**
 * @brief string >= BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator>=(const string& lhs, const BigInt& rhs)
{
    return !(lhs < rhs);
}

/**
 * @brief BigInt >= 64-bit integer
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator>=(const BigInt& lhs, const int64_t& rhs)
{
    return !(lhs < rhs);
}

/**
 * @brief 64-bit integer >= BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator>=(const int64_t& lhs, const BigInt& rhs)
{
    return !(lhs < rhs);
}

/**
 * @brief BigInt <= BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator<=(const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs > rhs);
}

/**
 * @brief BigInt <= string
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator<=(const BigInt& lhs, const string& rhs)
{
    return !(lhs > rhs);
}

/**
 * @brief string <= BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator<=(const string& lhs, const BigInt& rhs)
{
    return !(lhs > rhs);
}

/**
 * @brief BigInt <= 64-bit integer
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator<=(const BigInt& lhs, const int64_t& rhs)
{
    return !(lhs > rhs);
}

/**
 * @brief 64-bit integer <= BigInt
 * 
 * @param str 
 * @return true if yes
 * @return false if no
 */
bool operator<=(const int64_t& lhs, const BigInt& rhs)
{
    return !(lhs > rhs);
}

/**********************************************************************
************************** INSERTION (<<) *****************************
**********************************************************************/

/**
 * @brief output stream
 * 
 * @param out reference to ostream
 * @param str reference to BigInt
 * @return ostream& 
 */
ostream& operator<<(ostream& out, const BigInt& str)
{
    out << (str.sign == '-' ? '-' + str.abs_value : str.abs_value);
    return out;
}
