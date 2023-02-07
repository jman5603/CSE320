#include <stdlib.h>
#include <string.h>
#include "binarymath.h"

char *copy_string(const char *str)
{   
    size_t required = strlen(str) + 1;
    char *result = (char *)malloc(required);
    strncpy(result, str, required);
    result[required-1] = '\0';
    return result;
}

/**
 *  * Increment a BINARY_SIZE binary number expressed as a 
 *   * character string.
 *    * @param number The number we are passed
 *     * @returns Incremented version of the number
 *      */
char *inc(const char *number)
{     
    char *number2 = copy_string(number);
    int i = BINARY_SIZE - 1;
    if (number2[i] == '0')
    {       
        number2[i] = '1';
    }
    else  
    {       
        while (number2[i] == '1')
        {         
            number2[i] = '0';
            i--;  
        }
        number2[i] = '1';
    }
    number2[BINARY_SIZE] = '\0';
    return number2;
}

/**
 *  * Negate a BINARY_SIZE binary number expressed as a character string
 *   * @param number The number we are passed
 *    * @returns Incremented version of the number
 *     */
char *negate(const char *number)
{    
    char *number2 = copy_string(number);
    int i = 0; 
    for (i; i < BINARY_SIZE; i++)
    {       
        if (number2[i] == '0')
        {          
            number2[i] = '1';
        }
        else    
        {          
            number2[i] = '0';
        }
    }
    char *number3 = inc(number2);
    number3[BINARY_SIZE] = '\0';
    free(number2);
    return number3;
}

/**
 *  * Add two BINARY_SIZE binary numbers expressed as
 *   * a character string. 
 *    * @param a First number to add
 *     * @param b Second number to add
 *      * @return a + b
 *       */
char *add(const char *a, const char *b)
{
    char *a2 = copy_string((char*)a);
    char *b2 = copy_string((char*)b);
    char *c = (char*)malloc(BINARY_SIZE + 1);

    int sum = 0;
    int carry = 0;
    int i = 0;

    for (i = BINARY_SIZE - 1; i >= 0; i--)
    {
        sum = (a2[i]-'0') + (b2[i]-'0') + carry;
        carry = sum / 2;
        c[i] = (sum % 2) + '0';
    }

    c[BINARY_SIZE] = '\0';
    free(a2);
    free(b2);
    return c;
}

/**
 *  * Subtract two BINARY_SIZE binary numbers expressed as
 *   * a character string.
 *    * @param a First number
 *     * @param b Second number 
 *      * @return a - b
 *       */
char *sub(const char *a, const char *b)
{
    char *a2 = copy_string((char*)a);
    char *b2 = copy_string((char*)b);
    char *c = (char*)malloc(BINARY_SIZE + 1);

    int borrow = 0;
    int diff = 0;
    int i = 0;

    for (i = BINARY_SIZE - 1; i >= 0; i--)
    {
        diff = (a2[i]-'0') - (b2[i]-'0') - borrow;
        if (diff < 0)
        {
            diff += 2;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
    c[i] = diff + '0';
    }

    c[BINARY_SIZE] = '\0';
    free(a2);
    free(b2);
    return c;
}