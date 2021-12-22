#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>


float answer_vector_selection(int count, float array[count]);
float vector_selection(int count, float array[count]);


void transferring_data_to_file(int count, float array[count]){

  FILE *file;
  file = fopen("Vectors.txt", "w");
  fprintf(file, "Массив чисел:\n");
  for( int index = 0; index < count; index++)
    fprintf(file, "%f\n", array[index]);
  fprintf(file, "\n");
  fclose(file);
}


float the_first_norm_of_vector(int count, float array[count]){

  int answer;
  double sum = 0;

  for (int index = 0; index < count; index++)
    sum += fabsf(array[index]);
  
  FILE *file;
  file = fopen("Vectors.txt", "a+");
  fprintf(file, "Первая норма вектора равна: %f\n\n", sum);
  fclose(file);
  
  printf("\nПервая норма вектора равна: %lf\n", sum);
  printf("\nХотите подсчитать другую норму вектора?");
  printf("\n1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);

  return 0;
}


float the_second_norm_of_vector(int count, float array[count]){

  int answer;
  double sum = 0;

  for (int index = 0; index < count; index++)
    sum += pow(fabsf(array[index]), 2);

  FILE *file;
  file = fopen("Vectors.txt", "a+");
  fprintf(file, "Вторая норма вектора равна: %f\n\n", sqrt(sum));
  fclose(file);
  
  printf("\nВторая норма вектора равна: %lf\n", sqrt(sum));
  printf("\nХотите подсчитать другую норму вектора?");
  printf("\n1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);
  
  return 0;
}


float the_Helder_norm_of_vector(int count, float array[count]){

  int answer, pow_for_number;
  double sum = 0;

  printf("\nВведите степень для числа: ");
  scanf("%d", &pow_for_number);

  for (int index = 0; index < count; index++)
    sum += pow(fabsf(array[index]), pow_for_number);

  FILE *file;
  file = fopen("Vectors.txt", "a+");
  fprintf(file, "Гельдерова норма вектора равна: %f\n\n", pow(sum, 1/count));
  fclose(file);
  
  printf("\nГельдерова норма вектора равна: %lf\n", pow(sum, 1/count));
  printf("\nХотите подсчитать другую норму вектора?");
  printf("\n1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);

  return 0;
}


float infinite_norm_of_vector(int count, float array[count]){

  float max = 0;
  int answer;

  for (int index = 0; index < count; index++)
    if(array[index] > max)
      max = fabsf(array[index]);
  
  FILE *file;
  file = fopen("Vectors.txt", "a+");
  fprintf(file, "Бесконечная норма вектора равна: %f\n\n", max);
  fclose(file);

  printf("\nБесконечная норма вектора равна: %lf\n", max);
  printf("\nХотите подсчитать другую норму вектора?");
  printf("\n1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);

  return 0;
}


float normalization_of_the_array_vector(int count, float array[count]){

  int answer;
  double sum = 0;

  for (int index = 0; index < count; index++)
    sum += pow(fabsf(array[index]), 2);
  

  FILE *file;
  file = fopen("Vectors.txt", "a+");
  fprintf(file, "Нормировка вектора:\n");

  printf("\nНормировка вектора:\n");
  for(int index = 0; index < count; index++){ 
    printf("%f\n", array[index] / sqrt(sum));
    fprintf(file, "%f\n", array[index] / sqrt(sum));
  }

  printf("\n");
  fprintf(file, "\n");
  fclose(file);

  printf("\nХотите подсчитать другую норму вектора?");
  printf("\n1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);

  return 0;
}


float vector_selection(int count, float array[count]){
  
  int answer;

  printf("\nВыберите одну из допонительных функций:");
  printf("\n1.Вычислить первую норму вектора.");
  printf("\n2.Вычислить вторую норму вектора.");
  printf("\n3.Вычислить Гельдерову норму вектора.");
  printf("\n4.Вычислить бесконечную норму вектора.");
  printf("\n5.Нормировка вектора.");
  printf("\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    the_first_norm_of_vector(count, array);
  else if (answer == 2)
    the_second_norm_of_vector(count, array);
  else if (answer == 3)
    the_Helder_norm_of_vector(count, array);
  else if (answer == 4)
    infinite_norm_of_vector(count, array);
  else if (answer == 5)
    normalization_of_the_array_vector(count, array);
  else
    return vector_selection(count, array);

  return 0;
}


float answer_vector_selection(int count, float array[count]){
  
  int answer;

  printf("\nХотите подсчитать норму вектора?\n");
  printf("1.Да\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);

  return 0;
}


int launching_the_program(){

  int answer;

  printf("\n\nХотите повторить запуск программы ");
  printf("по новой для сортировки массива?\n");
  printf("1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);
  printf("\n");

  if (answer == 1 || answer == 2)
    return answer;
  else{
    printf("Неверный ввод, введите 1 или 2.\n");
    return launching_the_program();
  }

  return 0;
}


int main(){
  
  int answer, count;
  float random_numbers[count], numbers[count], numbers_in_file[count];
  float number, random_number;
  float limit_min, limit_max;
  bool flag, user_flag;
  
  printf("\nВыберите одну из функций:\n");
  printf("1.Сгенерировать последовательность из псевдослучайных символов.\n");
  printf("2.Ввести символы самостоятельно.\n");
  printf("3.Считать числа из файла.\n");
  printf("Ваш ответ: ");
  scanf("%d", &answer);


  if (answer == 1){

    printf("\nВведите кол-во символов, которые хотите получить: ");
	  scanf("%d", &count);
    printf("Введите минимальное число для диапазона: ");
    scanf("%f", &limit_min);
    printf("Введите максимальное число для диапазона: ");
    scanf("%f", &limit_max);

    printf("Случайно сгененрированные символы:\n");
    for (int index = 0; index < count; index++){
      random_number = (float)(rand()) / RAND_MAX * (limit_max - limit_min) + limit_min;
      printf("%d. %f\n", index + 1, random_number);
      random_numbers[index] = random_number;
    }
    printf("\n");

    transferring_data_to_file(count, random_numbers);
    answer_vector_selection(count, random_numbers);
    launching_the_program();

  }
  else if (answer == 2){

    printf("\nВведите кол-во символов, которые хотите ввести: ");
		scanf("%d", &count);
	  printf("Введите символы через Enter.\n");
    for (int index = 0; index < count; index++){
      scanf("%f", &number);
      numbers[index] = number;
    }

    transferring_data_to_file(count, numbers);
    answer_vector_selection(count, numbers);
    launching_the_program();
  }
  else if (answer == 3){

    FILE *file;
    file = fopen("text.txt", "r");

    fscanf(file, "%d", &count);
    for (int index = 0; index < count; index++){
      fscanf(file, "%f", &number);
      numbers_in_file[index] = number;
    }

    transferring_data_to_file(count, numbers_in_file);
    answer_vector_selection(count, numbers_in_file);
    launching_the_program();
  }

  return 0;
}
