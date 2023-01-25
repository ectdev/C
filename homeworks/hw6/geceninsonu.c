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

int main() {
  Ingredient meal;
  printf("What is the meal?:\n");
  scanf("%s", meal.name);
  get_ingredients(&meal);

  printf("Total calories is %d in %dg %s. %d%% calories from carbs, %d%% from proteins, %d%% from fats.\n",
         meal.calories, meal.weight, meal.name, meal.carbs, meal.proteins, meal.fats);

  return 0;
}

void calculate_macros(Ingredient* ingr) {
  char input[200];
  printf("What is %s?\n", ingr->name);
  fgets(input, 200, stdin);

  /* Split the input into individual ingredients */
  char* token = strtok(input, ", ");
  int num_ingredients = 0;
  Ingredient ingredients[MAX_INGREDIENTS];

  /* Parse the ingredients and weights */
  while (token != NULL) {
    /* Check if the token is an ingredient or a weight */
    int weight = 0;
    if (sscanf(token, "%s (%dg)", ingredients[num_ingredients].name, &weight) == 2) {
      ingredients[num_ingredients].weight = weight;
      num_ingredients++;
    } else {
      /* The token is an ingredient, so calculate its macro nutrient values */
      calculate_macros(&ingredients[num_ingredients]);
      num_ingredients++;
    }
    token = strtok(NULL, ", ");
  }

  for (int i = 0; i < num_ingredients; i++) {
    ingr->weight += ingredients[i].weight;
    ingr->calories += ingredients[i].calories;
    ingr->carbs += ingredients[i].carbs;
    ingr->proteins += ingredients[i].proteins;
    ingr->fats += ingredients[i].fats;
  }

  if (num_ingredients == 0) {
    printf("List the amount macro nutrients in %s:\n", ingr->name);
    scanf(" C:%%%d, P:%%%d, F:%%%d", &ingr->carbs, &ingr->proteins, &ingr->fats);
    int water = 100 - ingr->carbs - ingr->proteins - ingr->fats;
    ingr->calories = (ingr->carbs * CARB_CAL_1G + ingr->proteins * PROTEIN_CAL_1G
                      + ingr->fats * FAT_CAL_1G + water * WATER_CAL_1G) * ingr->weight / 100;
  }
}
