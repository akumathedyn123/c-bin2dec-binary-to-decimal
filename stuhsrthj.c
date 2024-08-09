#include <stdio.h>
#include <math.h>
#include <string.h>

int bin2dec(const char *bin_str, int *neg_position) {
    int decimal = 0, i = 0;
    int len = strlen(bin_str);

    for (int j = len - 1; j >= 0; j--) {
        if (bin_str[j] != '0' && bin_str[j] != '1') {
            return -1; // Error for Invalid binary number..
        }
        decimal += (bin_str[j] - '0') * pow(2, i);
        i++;
    }

    *neg_position = len; // Position of the first digit for a negative number.
    return decimal;
}

int main() {
    char bin_str[32];
    char is_neg_str[2];
    int is_negative = 0;
    int dec, neg_binary, neg_position = 0;

    //Input
    printf("Enter a binary number: ");
    scanf("%s", bin_str);

    // Check if the input is a valid binary number
    for (int i = 0; i < strlen(bin_str); i++) {
        if (bin_str[i] != '0' && bin_str[i] != '1') {
            printf("Invalid binary number. Enter only 1/0 digit.\n");
            return 0;
        }
    }

    if (bin_str[0] == '1') {
        printf("Is the binary number negative? (y/n): ");
        scanf("%s", is_neg_str);

        if (is_neg_str[0] == 'y' || is_neg_str[0] == 'Y') {
            is_negative = 1;
        }
    }
    
    //Negative number loop.

    if (is_negative) {
        // Remove the first '1' for the positive part
        char positive_part[32];
        strcpy(positive_part, bin_str + 1);

        dec = bin2dec(positive_part, &neg_position);

        if (dec == -1) {
            printf("Invalid binary number. Enter only 1/0 digit.\n");
            return 0;
        }

        // Calculate negative binary
        neg_binary = dec - pow(2, neg_position);
        printf("The decimal equivalent (negative): %d\n", neg_binary);

    } else {
        dec = bin2dec(bin_str, &neg_position);

        if (dec == -1) {
            printf("Invalid binary number. Enter only 1/0 digit in digit.\n");
        } else {
            printf("The decimal equivalent: %d\n", dec);
        }
    }

    return 0;
}