#include <iostream>

int main() {

    // Function selection and user number
    int user_answer;
    int user_number;

    // 1 function.Generate the Fibonacci sequence up to the entered number
    int sequence_more_num[10000];
    int control_number = 0, index_of_num_1 = 0;
    int last_number_2, last_number_1;

    // 2 function.Generate the Fibonacci sequence up to the n-th number
    int sequence_do_n[10000];
    int index_of_num_2 = 0;
    int last_num_2, last_num_1;

    // Requesting information from the user
    printf("Hello!\nHere are the functions that I can perform:\n");
    printf("1. Generate the Fibonacci sequence up to the entered number.\n");
    printf("2. Generate the Fibonacci sequence up to the n-th number.\n");
    printf("Enter the number of the function you need: ");
    scanf_s("%d", &user_answer);

    printf("\nEnter a number: ");
    scanf_s("%d", &user_number);

    // The main part
    switch (user_answer)
    {

    // If the user has selected 1-st function
    case 1:
        while (control_number <= user_number)
        {
            switch (index_of_num_1)
            {
            case 0:

                // Adding the first number (0) to the array of Fibonacci numbers
                sequence_more_num[index_of_num_1] = control_number;
                printf("%d\n", sequence_more_num[index_of_num_1]);

                /* Increasing the index by 1 and assign the Fibonacci number to the control number
                to check the condition in the loop */
                control_number++;
                index_of_num_1++;

            case 1:

                // Adding the second number (1) to the array of Fibonacci numbers
                sequence_more_num[index_of_num_1] = control_number;
                printf("%d\n", sequence_more_num[index_of_num_1]);

                /* Increasing the index by 1 and assign the Fibonacci number to the control number 
                to check the condition in the loop */
                control_number++;
                index_of_num_1++;

            default:

                // Calculate the Fibonacci number and add all the Fibonacci numbers to the array
                last_number_2 = sequence_more_num[index_of_num_1 - 2];
                last_number_1 = sequence_more_num[index_of_num_1 - 1];
                sequence_more_num[index_of_num_1] = last_number_2 + last_number_1;
                printf("%d\n", sequence_more_num[index_of_num_1]);

                /* Increasing the index by 1 and assign the Fibonacci number to the control number
                to check the condition in the loop */
                control_number = sequence_more_num[index_of_num_1] = last_number_2 + last_number_1;
                index_of_num_1++;
            }
        }
        break;

    // If the user has selected 2-nd function
    case 2:
        while (index_of_num_2 <= user_number)
        {
            switch (index_of_num_2)
            {
            case 0:

                // Adding the first number (0) to the array of Fibonacci numbers
                sequence_more_num[index_of_num_2] = index_of_num_2;
                printf("%d\n", sequence_more_num[index_of_num_2]);

                // Increasing the index by 1
                index_of_num_2++;

            case 1:

                // Adding the second number (1) to the array of Fibonacci numbers
                sequence_more_num[index_of_num_2] = index_of_num_2;
                printf("%d\n", sequence_more_num[index_of_num_2]);

                // Increasing the index by 1
                index_of_num_2++;

            default:

                // Calculate the Fibonacci number and add all the Fibonacci numbers to the array
                last_number_2 = sequence_more_num[index_of_num_2 - 2];
                last_number_1 = sequence_more_num[index_of_num_2 - 1];
                sequence_more_num[index_of_num_2] = last_number_2 + last_number_1;
                printf("%d\n", sequence_more_num[index_of_num_2]);

                // Increasing the index by 1
                index_of_num_2++;
            }
        }
        break;
    }
    return 0;
}
