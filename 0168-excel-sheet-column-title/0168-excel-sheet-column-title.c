#include <stdlib.h>

char* convertToTitle(int columnNumber) {
    char *result = (char*)malloc(20 * sizeof(char));
    int index = 0;

    while (columnNumber > 0) {
        columnNumber--;

        result[index++] = (columnNumber % 26) + 'A';

        columnNumber /= 26;
    }

    result[index] = '\0';

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    return result;
}