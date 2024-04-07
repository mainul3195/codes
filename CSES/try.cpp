#include <stdio.h>
#include <string.h>

int main() {
    char input[21];
    printf("Enter a phrase: ");
    fgets(input, 21, stdin);

    if (strcmp (input, "her eyes\n") == 0) {
        printf("an endless ocean in which I wanna drown away.\n");
    }
    else if (strcmp(input, "her lips\n") == 0) {
        printf("the sharpest thing which is torning me every day.\n");
    }
    else if (strcmp(input, "her smile\n") == 0) {
        printf("the most soothing thing which I can easily die for.\n");
    }
    else if (strcmp(input, "her words\n") == 0) {
        printf("a fragrance that calms my soul.\n");
    }
    else if (strcmp(input, "her hair\n") == 0) {
        printf("a dark cloudy sky.\n");
    }
    else {
        printf("Invalid input.\n");
    }

    return 0;
}