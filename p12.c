#include <stdio.h>

/*  This routine returns an integer, corresponding to the input string, that codifies a binary number;
    consider that the string internal characters are just '0' and '1', with a maximum length of 32. Also,
    consider that the conversion should be finished reaching a null or any invalid character.
 */
int asciiBinaryToInt(char *s) {
    char *ptr = s;
    int counter = 0;
    double power = 0;
    int result = 0;
    
    //print string
    while(*ptr != '\0' && (*ptr == '0' || *ptr == '1') && counter < 32) {
        // move the ptr pointer to the next memory location
        ptr++;
        counter++;
    }
    ptr--;
    while(counter > 0) {
        result += (*ptr - '0') * ((int) pow((double) 2,power));
        //printf("%d\n", result);
        //printf("%c", *ptr);
        counter--;
        ptr--;
        power++;
    }
    //printf("%d\n", result);
    return result;
}


int checkHexChar(char c) {
    if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != 'A' && c != 'B' && c != 'C' && c != 'D' && c != 'E' && c != 'F' && c != 'a' && c != 'b' && c != 'c' && c != 'd' && c != 'e' && c != 'f') {
        return 0;
    }
    return 1;
}

int getHexValue(char c) {
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        return (c - '0');
    } else if (c == 'A' || c == 'a') {
        return 10;
    } else if (c == 'B' || c == 'b') {
        return 11;
    } else if (c == 'C' || c == 'c') {
        return 12;
    } else if (c == 'D' || c == 'd') {
        return 13;
    } else if (c == 'E' || c == 'e') {
        return 14;
    } else if (c == 'F' || c == 'f') {
        return 15;
    }
    return -1;
}

/*  This routine returns an integer, corresponding to an equivalent decimal number converted from a
    hexadecimal, represented in sequence of characters in the input string; consider that the only alowed
    characters are from '0' to '9', from 'A' to 'F' and from 'a' to 'f', with a maximum string length of 8
    characters .. any invalid character will finish the conversion process, so the acumulated result will be
    returned.
 */
int asciiHEXToInt(char *s) {
    char *ptr = s;
    int counter = 0;
    double power = 0;
    int result = 0;
    
    //print string
    while(*ptr != '\0' && checkHexChar(*ptr) && counter < 8) {
        // move the ptr pointer to the next memory location
        ptr++;
        counter++;
    }
    ptr--;
    
    while(counter > 0) {
        result += (getHexValue(*ptr)) * ((int) pow((double) 16,power));
        counter--;
        ptr--;
        power++;
    }
    return result;
}

/*  This routine returns a double precision float number, corresponding to a sequence of digit
    characters in the input string, with the optional single appearance of the sign ('+' or '-') and
    decimal point ('.') to commit with a valid representation for a real number, with integers and decimals;
    any invalid character will finish the conversion process, so the acumulated result will be returned.
 */
double asciiToDouble(char *s) {
    char *ptr = s;
    int counter = 0;
    double power = 0;
    double result = 0;
    
    //print string
    while(*ptr != '\0' && *ptr != '.' && ((*ptr - '0' >= 0 && *ptr - '0' <= 9) || *ptr == '-' || *ptr == '+')) {
        // move the ptr pointer to the next memory location
        ptr++;
        counter++;
    }
    if (*ptr == '.') {
        ptr++;
        counter++;
        while (*ptr != '\0' && (*ptr - '0' >= 0 && *ptr - '0' <= 9)) {
            ptr++;
            counter++;
            power--;
        }
    }
    ptr--;
    
    while(counter > 1) {
        if (*ptr != '.') {
            //printf("%d\n", counter);
            double digit = (double)(*ptr - '0');
            double positionValue = (pow((double) 10,power));
            result += digit * positionValue;
            //printf("%lf\n",power);
            //printf("%lf\n",positionValue);
            //printf("%lf\n", digit);
            //printf("%lf\n\n", result);
            counter--;
            ptr--;
            power++;
        } else {
            //printf("%d\n", counter);
            ptr--;
            counter--;
        }
    }
    if (*ptr == '-') {
        result = -result;
    } else if (*ptr != '+') {
        double digit = (double)(*ptr - '0');
        double positionValue = (pow((double) 10,power));
        result += digit * positionValue;
    }
    //printf("%d\n", result);
    return result;
}

int myHexToInt(char *s) {
    char *ptr = s;
    int counter = 0;
    double power = 0;
    int result = 0;
    
    //print string
    while(*ptr != '\0' && counter < 8) {
        if (!checkHexChar(*ptr)) {
            return - 1;
        }
        // move the ptr pointer to the next memory location
        ptr++;
        counter++;
    }
    ptr--;
    
    while(counter > 0) {
        result += (getHexValue(*ptr)) * ((int) pow((double) 16,power));
        counter--;
        ptr--;
        power++;
    }
    return result;
}