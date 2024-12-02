#include "bagofwords.h"

void remove_punct_and_make_lower_case(char *p) {
    char *src = p, *dst = p;
    while (*src) {
        if (ispunct((unsigned char)*src) || isspace((unsigned char)*src)) {
            src++;  // Skip punctuation or whitespace
        } else if (isupper((unsigned char)*src)) {
            *dst++ = tolower((unsigned char)*src);  // Convert to lowercase
            src++;
        } else {
            *dst++ = *src++;  // Copy character as-is
        }
    }
    *dst = '\0';  // Null-terminate the string
}
