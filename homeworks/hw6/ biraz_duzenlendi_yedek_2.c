#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARB_CAL_1G 4      /* Number of calories in 1g carbohydrate */
#define PROTEIN_CAL_1G 4    /* Number of calories in 1g protein */
#define FAT_CAL_1G 9       /* Number of calories in 1g fat */
#define WATER_CAL_1G 4       /* Number of calories in 1g water */

typedef struct Ingredient {
  char name[256];
  float weight;
  float carbs;
  float protein;
  float fat;
} Ingredient;


void calculate_calories(Ingredient *ingredient) {
  ingredient->carbs *= CARB_CAL_1G;
  ingredient->protein *= PROTEIN_CAL_1G;
  ingredient->fat *= FAT_CAL_1G;

  printf("List the weight and macro nutrients in %s:\n", ingredient->name);
  scanf("%f%f%f%f", &ingredient->weight, &ingredient->carbs, &ingredient->protein, &ingredient->fat);
  ingredient->carbs *= ingredient->weight;
  ingredient->protein *= ingredient->weight;
  ingredient->fat *= ingredient->weight;

  char input[256];
  printf("What is %s:\n", ingredient->name);
  fgets(input, 256, stdin);
  char *p = strtok(input, ", ");
  while (p != NULL) {
    Ingredient sub_ingredient;
    strcpy(sub_ingredient.name, p);
    calculate_calories(&sub_ingredient);
    ingredient->carbs += sub_ingredient.carbs;
    ingredient->protein += sub_ingredient.protein;
    ingredient->fat += sub_ingredient.fat;
    p = strtok(NULL, ", ");
  }
}

int main() {
  printf("What is the meal?:\n");
  char meal_name[256];
  scanf("%s", meal_name);

  Ingredient meal;
  strcpy(meal.name, meal_name);
  meal.weight = 0;
  meal.carbs = 0;
  meal.protein = 0;
  meal.fat = 0;
  calculate_calories(&meal);

  printf("Total calories in %.1f g %s: %.1f\n", meal.weight, meal.name, meal.carbs + meal.protein + meal.fat);
  printf("%.1f%% calories from carbs, %.1f%% from proteins, %.1f%% from fats.\n", meal.carbs / (meal.carbs + meal.protein + meal.fat) * 100, meal.protein / (meal.carbs + meal.protein + meal.fat) * 100, meal.fat / (meal.carbs + meal.protein + meal.fat) * 100);

  return 0;
}


/* 
The calculate_calories function is a recursive function that is used to calculate the total calories of an ingredient and its sub-ingredients. 
It takes a pointer to an Ingredient structure as input and prompts the user to input the weight and macro nutrient values of the ingredient. 
It then calculates the total calories of the ingredient based on the weight and macro nutrients.

Next, it prompts the user to input the sub-ingredients of the ingredient, and uses the strtok function to split the input string into individual 
sub-ingredient names. For each sub-ingredient name, it creates a new Ingredient structure and calls itself recursively to calculate the total calories of 
the sub-ingredient. Finally, it adds up the calories of all sub-ingredients to get the total calories of the ingredient.

The main function first prompts the user to input the name of the meal. It initializes an Ingredient structure with the name provided by the user, and sets the 
weight, carbs, protein, and fat values to 0. It then calls the calculate_calories function to calculate the total calories of the meal. Finally, it prints out the 
total calories, weight, and percentages of calories coming from each.

*/