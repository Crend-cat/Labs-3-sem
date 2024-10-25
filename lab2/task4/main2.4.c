#include "head2.4.h"

int main()
{
    puts("\nTest 4.1\n");
    int ans;
    point p1 = (point){0, 0};
    point p2 = (point){1, 0};
    point p3 = (point){1, 1};
    point p4 = (point){0, 1};
    printf("\ttest 1\n{{0,0}, {1, 0}, {1, 1}, {0, 1}}\nexpected answer: yes\n");
    ans = Is_convex(4, p1, p2, p3, p4);
    if (ans)
    {
        printf("\t answer: yes\n");
    }
    else
    {
        printf("\t answer: no\n");
    }

    p1 = (point){0, 0};
    p2 = (point){1, 0};
    p3 = (point){0, 1};
    p4 = (point){1, 1};
    printf("\ttest 2\n{{0,0}, {1, 0}, {0, 1}, {1, 1}}\nexpected answer: no\n");
    ans = Is_convex(4, p1, p2, p3, p4);
    if (ans)
    {
        printf("\t answer: yes\n");
    }
    else
    {
        printf("\t answer: no\n");
    }


    p1 = (point){0, 0};
    p2 = (point){1, 0};
    p3 = (point){0, 1};
    printf("\ttest 3\n{{0,0}, {1, 0}, {0, 1}}\nexpected answer: yes\n");
    ans = Is_convex(3, p1, p2, p3);
    if (ans)
    {
        printf("\t answer: yes\n");
    }
    else
    {
        printf("\t answer: no\n");
    }


    p1 = (point){0, 0};
    p2 = (point){1, 0};
    printf("\ttest 4\n{{0,0}, {1, 0}}\nexpected answer: yes\n");
    ans = Is_convex(2, p1, p2);
    if (ans)
    {
        printf("\t answer: yes\n");
    }
    else
    {
        printf("\t answer: no\n");
    }


    p1 = (point){0, 0};
    printf("\ttest 5\n{{0,0}}\nexpected answer: yes\n");
    ans = Is_convex(1, p1);
    if (ans)
    {
        printf("\t answer: yes\n");
    }
    else
    {
        printf("\t answer: no\n");
    }


    puts("\nTest 4.2\n");

    double result;

    printf("\ttest 1\n2x^2 + 3x + 4 at x = 1\nexpected result: 9\n");
    switch (Find_polynom(&result, 1.0, 2, 2.0, 3.0, 4.0))
    {
        case INVALID_INPUT:
            printf("Input error\n");
            return INVALID_INPUT;
            break;
        case OVERFLOW_ERROR:
            printf("Overflow error\n");
            return OVERFLOW_ERROR;
            break;

        case OK:
            printf("\t result: %f\n", result);
            break;
        case INVALID_MEMORY:
            break;
    }


    printf("\n\ttest 2\n1x^3 + 2x^2 + 3x + 4 at x = 2\nexpected result: 26\n");
    switch (Find_polynom(&result, 2.0, 3, 1.0, 2.0, 3.0, 4.0))
    {
        case INVALID_INPUT:
            printf("Input error\n");
            return INVALID_INPUT;
            break;
        case OVERFLOW_ERROR:
            printf("Overflow error\n");
            return OVERFLOW_ERROR;
            break;

        case OK:
            printf("\t result: %f\n", result);
            break;
        case INVALID_MEMORY:
            break;
    }


    printf("\n\ttest 3\n1x^4 + 2x^3 + 3x^2 + 4x + 5 at x = 2\nexpected result: 57\n");
    switch (Find_polynom(&result, 2.0, 4, 1.0, 2.0, 3.0, 4.0, 5.0))
    {
        case INVALID_INPUT:
            printf("Input error\n");
            return INVALID_INPUT;
            break;
        case OVERFLOW_ERROR:
            printf("Overflow error\n");
            return OVERFLOW_ERROR;
            break;

        case OK:
            printf("\t result: %f\n", result);
            break;
        case INVALID_MEMORY:
            break;
    }


    puts("\nTest 4.3\n");

    char answer[100];
    int count = 5;
    printf("\n\ttest 1\n16CC 1 AB 4ED 7E0 FA4\nexpected result: YES YES YES YES NO\n");
    if (Kaprekar(count, answer, 16, "1", "AB", "4ED", "7E0", "FA4") != OK)
    {
        printf("Input error\n");
        return INVALID_INPUT;
    }
    else
        printf("\t result:");
    {
        for (int i = 0; i < count; ++i)
        {
            if (answer[i] == '+')
                printf(" YES");
            else
                printf(" NO");
        }
    }

    count = 4;
    printf("\n\ttest 2\n10CC 1 33 55 17344\nexpected result: YES NO YES YES \n");
    if (Kaprekar(count, answer, 10, "1", "33", "55", "17344") != OK)
    {
        printf("Input error\n");
        return INVALID_INPUT;
    }
    else
        printf("\t result:");
    {
        for (int i = 0; i < count; ++i)
        {
            if (answer[i] == '+')
                printf(" YES");
            else
                printf(" NO");
        }
    }

    count = 6;
    printf("\n\ttest 3\n12CC 1 B 66 444 BB 10000\nexpected result: YES YES YES YES YES NO\n");
    if (Kaprekar(count, answer, 12, "1", "B", "66", "444", "BB", "10000") != OK)
    {
        printf("Input error\n");
        return INVALID_INPUT;
    }
    else
        printf("\t result:");
    {
        for (int i = 0; i < count; ++i)
        {
            if (answer[i] == '+')
                printf(" YES");
            else
                printf(" NO");
        }
        printf("\n");
    }

    return 0;
}