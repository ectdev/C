#include <stdio.h>
#include <string.h>

#define CARB_CAL_1G   4 /* Number of calories in 1g carbohydrate */
#define PROTEIN_CAL_1G 4 /* Number of calories in 1g protein */
#define FAT_CAL_1G   9 /* Number of calories in 1g fat */
#define WATER_CAL_1G 0 /* Number of calories in 1g water */

struct Ingredient {
  char name[30];
  int weight;
  int calories;
  int carbs;
  int proteins;
  int fats;
};
  void get_ingredients(struct Ingredient *ingr) {
  char input[100];
  int i = 0;
  int num_ingredients = 0;
  struct Ingredient ingredients[20];

  printf("What is %s?\n", ingr->name);
  fgets(input, 100, stdin);

  char *token = strtok(input, ",\n");
  while (token != NULL) {
    sscanf(token, "%s (%dg)", ingredients[i].name, &ingredients[i].weight);
    i++;
    token = strtok(NULL, ",\n");
  }
  num_ingredients = i;
  for (i = 0; i < num_ingredients; i++) {
    printf("List the amount macro nutrients in %s:\n", ingredients[i].name);
    scanf(" C:%%%d.%*d, P:%%%d.%*d, F:%%%d.%*d", &ingredients[i].carbs, &ingredients[i].proteins, &ingredients[i].fats);

    ingredients[i].calories = ingredients[i].carbs * CARB_CAL_1G + ingredients[i].proteins * PROTEIN_CAL_1G + ingredients[i].fats * FAT_CAL_1G;
    if (ingredients[i].carbs + ingredients[i].proteins + ingredients[i].fats < 100) {
      int water = 100 - (ingredients[i].carbs + ingredients[i].proteins + ingredients[i].fats);
      ingredients[i].calories += water * WATER_CAL_1G;
    }
  }

  ingr->calories = 0;
  ingr->carbs = 0;
  ingr->proteins = 0;
  ingr->fats = 0;
  ingr->weight = 0;
  for (i = 0; i < num_ingredients; i++) {
    ingr->calories += ingredients[i].calories;
    ingr->carbs += ingredients[i].carbs;
    ingr->proteins += ingredients[i].proteins;
    ingr->fats += ingredients[i].fats;
    ingr->weight += ingredients[i].weight;

    if (num_ingredients > 1) {
      get_ingredients(&ingredients[i]);
    }
  }
}
