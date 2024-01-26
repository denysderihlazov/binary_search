#include <stdio.h>
#include <stdlib.h>

#define HELP_INFO \
"\n--- Binary search ---\n" \
"Program to search throug sorted array\n" \
"Usage instruction:\n\n" \
"   Run: ./main <searchable num>\n" \
"   Example: ./main 5\n" \
"\nAttention: \n\n" \
"The searchable number must be an integer!\n" \

void printHelpInfo()
{
    printf(HELP_INFO);
}

int parseCharToNum(char *num)
{
    char *args;
    int answer = 0;
    for(args = num; *args != '\0'; ++args) {
        if(((int)*args - (int)'0') < 0 || ((int)*args - (int)'0') > 9) {
            printf("Error not a digit!\n");
            printHelpInfo();
            exit(1);
        }
        
        if(answer == 0) {
            answer = (int)*args - (int)'0';
        } else {
            answer = answer * 10 + ((int)*args - (int)'0');
        }
    }

    return answer;
}

int strCompare(char *str1, char *str2) {
    int i = 0;
    while(*(str1+i) != '\0' && *(str2+i) != '\0') {
        if((int)*(str1+i) == (int)*(str2+i) && (int)*(str1+i+1) == (int)*(str2+i+1)) {
            i++;
        } else {
            return 0;
        }
    }
    return 1; // In contrast to strcmp(), my function returns 1 when strings are identical.
}

int binarySearch(int *numbers, int arrSize, int searchable)
{
    
    if(arrSize == 0 || searchable < numbers[0] || searchable > numbers[arrSize-1]) {
        return -1;
    }

    int rangeStart = 0;
    int rangeEnd = arrSize-1;
    int mid;

    while(rangeStart <= rangeEnd) {
        mid = rangeStart + (rangeEnd - rangeStart) / 2;

        if(numbers[mid] == searchable) {
            return mid;
        }

        if(searchable > numbers[mid]) {
            rangeStart = mid+1;
        } else {
            rangeEnd = mid -1;
        }
    }

    return -1; // -1 means out of array
}

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("Too few arguments");
        printHelpInfo();
        exit(0);
    } else if (strCompare(argv[1], "-h") || strCompare(argv[1], "--help")) {
        printHelpInfo();
        exit(2);
    }

    int numbers[] = {1, 2, 5, 8, 23, 25, 30, 34, 37};
    int arrSize = sizeof(numbers) / sizeof(numbers[0]);

    int searchable = parseCharToNum(argv[1]);

    printf("Your searchable index is: %d\n", binarySearch(numbers, arrSize, searchable));

    return 0;
}
