#include <stdio.h>
#include "ft_convert_base.c"

int main() {
    char *nbr = "1010";  // Binary number
    char *base_from = "01";  // Base 2
    char *base_to = "0123456789";  // Decimal

    char *result = ft_convert_base(nbr, base_from, base_to);
    if (result != NULL) {
        printf("Converted number: %s\n", result);
        free(result);
    } else {
        printf("Conversion failed.\n");
    }

    return 0;
}

