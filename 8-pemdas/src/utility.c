#include "bagofwords.h"

void remove_punct_and_make_lower_case(char *p)
{
    char *src = p, *dst = p;
    while (*src)
    {
       if (ispunct((unsigned char)*src) || isspace((unsigned char)*src))
       {
          /* Skip this character */
          src++;
       }
       else if (isupper((unsigned char)*src))
       {
          /* Make it lowercase */
          *dst++ = tolower((unsigned char)*src);
          src++;
       }
       else if (src == dst)
       {
          /* Increment both pointers without copying */
          src++;
          dst++;
       }
       else
       {
          /* Copy character */
          *dst++ = *src++;
       }
    }
    *dst = 0;
}