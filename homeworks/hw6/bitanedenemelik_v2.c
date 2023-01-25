#include <stdio.h>
#include <string.h>

#define MAX_INGREDIENTS 20
#define MAX_NAME_LENGTH 30

typedef struct {
  char name[MAX_NAME_LENGTH];
  int weight;
  int calories;
  int carbs;
  int proteins;
  int fats;
} Ingredient;

#define CARB_CAL_1G   4      /* Number of calories in 1g carbohydrate */
#define PROTEIN_CAL_1G  4/* Number of calories in 1g protein */
#define FAT_CAL_1G   9         /* Number of calories in 1g fat */
#define WATER_CAL_1G 0   /* Number of calories in 1g water */

void get_ingredients(Ingredient* ingr);

int main(void) {
  Ingredient meal;
  Ingredient ingredients[MAX_INGREDIENTS];

  printf("What is the meal?:\n");
  scanf("%s", meal.name);

  get_ingredients(&meal);

  printf("Total calories is %d in %dg %s. %d%% calories from carbs, %d%% from proteins, %d%% from fats.\n",
         meal.calories, meal.weight, meal.name, meal.carbs, meal.proteins, meal.fats);

  return 0;
}

void get_ingredients(Ingredient* ingr) {
  Ingredient ingredients[MAX_INGREDIENTS];
  char input[MAX_NAME_LENGTH];
  int num_ingredients = 0;
  int i;

  printf("What is %s?:\n", ingr->name);
  scanf("%[^\n]%*c", input);

  char* token = strtok(input, ",");
  while (token != NULL) {
    sscanf(token, " %s (%dg)", ingredients[num_ingredients].name, &ingredients[num_ingredients].weight);
    num_ingredients++;
    token = strtok(NULL, ",");
  }

  for (i = 0; i < num_ingredients; i++) {
    printf("List the amount macro nutrients in %s:\n", ingredients[i].name);
    scanf(" C:%%%d.%*d, P:%%%d.%*d, F:%%%d.%*d", &ingredients[i].carbs, &ingredients[i].proteins, &ingredients[i].fats
