#include <stdio.h>


// 1. Generate the Fibonacci sequence up to the entered number.
void the_entered_number(int user_number){

  // 1 function.Generate the Fibonacci sequence up to the entered number
  long long sequence_more_num[10000];
  long long control_number = 0, index_of_num_1 = 0;
  long long last_number_2, last_number_1;

  while (control_number <= user_number){
    switch (index_of_num_1){
      
      case 0:{ 

        // Adding the first number (0) to the array of Fibonacci numbers
        sequence_more_num[index_of_num_1] = control_number;
        printf("%llu ", sequence_more_num[index_of_num_1]);

        /* Increasing the index by 1 and assign the Fibonacci number to the control number
        to check the condition in the loop */
        control_number++;
        index_of_num_1++;

        break;
      }

      case 1:{ 

        // Adding the second number (1) to the array of Fibonacci numbers
        sequence_more_num[index_of_num_1] = control_number;
        printf("%llu ", sequence_more_num[index_of_num_1]);

        /* Increasing the index by 1 and assign the Fibonacci number to the control number 
        to check the condition in the loop */
        control_number++;
        index_of_num_1++;

        break;
      }

      default:{ 

        // Calculate the Fibonacci number and add all the Fibonacci numbers to the array
        last_number_2 = sequence_more_num[index_of_num_1 - 2];
        last_number_1 = sequence_more_num[index_of_num_1 - 1];
        sequence_more_num[index_of_num_1] = last_number_2 + last_number_1;
        printf("%llu ", sequence_more_num[index_of_num_1]);

        /* Increasing the index by 1 and assign the Fibonacci number to the control number
        to check the condition in the loop */
        control_number = sequence_more_num[index_of_num_1] = last_number_2 + last_number_1;
        
        index_of_num_1++;

        break;
      }
    }
  }
}


// 2. Generate the Fibonacci sequence up to the n-th number
void the_nth_number(int user_number){

  // 2 function.Generate the Fibonacci sequence up to the n-th number
  long long sequence_do_n[10000];
  long long index_of_num_2 = 0;
  long long last_number_2, last_number_1;

  while (index_of_num_2 <= user_number && sequence_do_n[index_of_num_2 - 1] < 9223372036854775807){
    switch (index_of_num_2){
      
      case 0:{ 
        
        // Adding the first number (0) to the array of Fibonacci numbers
        sequence_do_n[index_of_num_2] = index_of_num_2;
        printf("%llu ", sequence_do_n[index_of_num_2]);

        // Increasing the index by 1
        index_of_num_2++;

        break;
      }

      case 1:{
        
        // Adding the second number (1) to the array of Fibonacci numbers
        sequence_do_n[index_of_num_2] = index_of_num_2;
        printf("%llu ", sequence_do_n[index_of_num_2]);

        // Increasing the index by 1
        index_of_num_2++;

        break;
      }

      default:{
        
        // Calculate the Fibonacci number and add all the Fibonacci numbers to the array
        last_number_2 = sequence_do_n[index_of_num_2 - 2];
        last_number_1 = sequence_do_n[index_of_num_2 - 1];
        sequence_do_n[index_of_num_2] = last_number_2 + last_number_1;printf("%llu ", sequence_do_n[index_of_num_2]);
        
        // Increasing the index by 1
        index_of_num_2++;

        break;
      }
    }
  }
}


int restart();


int main(){

  // Function selection and user number
  int user_answer;
  int user_number;

  // Requesting information from the user
  printf("Hello!\nHere are the functions that I can perform:\n");
  printf("1. Generate the Fibonacci sequence up to the entered number.\n");
  printf("2. Generate the Fibonacci sequence up to the n-th number.\n");
  printf("Enter the number of the function you need: ");
  scanf("%d", &user_answer);

  printf("\nEnter a number: ");
  scanf("%d", &user_number);

  // The main part
  switch (user_answer){

    // If the user has selected 1-st function
    case 1:{ 

      printf("\nThe Fibonacci sequence up to the entered number:\n");
      the_entered_number(user_number);
      restart();
      break;
    }

    // If the user has selected 2-nd function
    case 2:{ 

      printf("\nThe Fibonacci sequence up to the n-th number:\n");
      the_nth_number(user_number);
      restart();
      break;
    }
  }

  return 0;
}


int restart(){

  int answer;

  printf("\n\nDo you want to generate a new Fibonacci sequence?\n");
  printf("1.Yes.\n2.No.\nYour answer: ");
  scanf("%d", &answer);

  if (answer == 1){ 
    
    printf("\n");
    return main();
  }
  else if (answer == 2)
    printf("\nThe program is stopped.");
  else
    return restart();

  return 0;
}
