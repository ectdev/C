#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define MAX_COMPONENTS 20

#define CARB_CAL_1G 4
#define PROTEIN_CAL_1G 4
#define FAT_CAL_1G 9
#define WATER_CAL_1G 0

struct component {
  char name[MAX_NAME_LEN + 1];
  double weight;
  double carb;
  double protein;
  double fat;
  double water;
};

void get_ingredients(struct component *meal, int *num_components){
  char input[1000];
  fgets(input, sizeof(input), stdin);

  char *token = strtok(input, ",");
  while (token != NULL) {
    char name[MAX_NAME_LEN + 1];
    double weight = 0;
    double carb = 0;
    double protein = 0;
    double fat = 0;
    double water = 100;

    sscanf(token, "%30s", name);
    char *open_paren = strchr(name, '(');
    if (open_paren != NULL) {
      sscanf(open_paren, "(%lf", &weight);
      *open_paren = '\0';
    }

    printf("What is %s?\n", name);
    struct component sub_components[MAX_COMPONENTS];
    int num_sub_components = 0;
    get_ingredients(sub_components, &num_sub_components);

    if (num_sub_components == 0) {
      printf("List the amount macro nutrients in %s:\n", name);
      char macro_input[1000];
      fgets(macro_input, sizeof(macro_input), stdin);
      sscanf(macro_input, "C:%%%lf, P:%%%lf, F:%%%lf", &carb, &protein, &fat);
      water = 100 - carb - protein - fat;
    } else {
      for (int i = 0; i < num_sub_components; i++) {
        struct component sub_component = sub_components[i];
        weight += sub_component.weight;
        carb += sub_component.carb * sub_component.weight;
        protein += sub_component.protein * sub_component.weight;
        fat += sub_component.fat * sub_component.weight;
        water += sub_component.water * sub_component.weight;
      }
      carb /= weight;
      protein /= weight;
      fat /= weight;
      water /= weight;
    }

    strcpy(meal[*num_components].name, name);
    meal[*num_components].weight = weight;
    meal[*num_components].carb = carb;
    meal[*num_components].protein = protein;
    meal[*num_components].fat = fat;

}
}




int main(void) {
  printf("What is the meal?\n");

  struct component meal[MAX_COMPONENTS];
  int num_components = 0;
  get_ingredients(meal, &num_components);

  double total_weight = 0;
  double total_calories = 0;
  double total_carb = 0;
  double total_protein = 0;
  double total_fat = 0;
  double total_water = 0;
  for (int i = 0; i < num_components; i++) {
    struct component component = meal[i];
    total_weight += component.weight;
    total_calories += component.weight * (component.carb * CARB_CAL_1G + component.protein * PROTEIN_CAL_1G + component.fat * FAT_CAL_1G + component.water * WATER_CAL_1G);
    total_carb += component.weight * component.carb;
    total_protein += component.weight * component.protein;
    total_fat += component.weight * component.fat;
    total_water += component.weight * component.water;
  }
  total_carb /= total_weight;
  total_protein /= total_weight;
  total_fat /= total_weight;
  total_water /= total_weight;

  printf("Total calories is %.0lf in %.0lfg meal. %.1lf%% calories from carbs, %.1lf%% from proteins, %.1lf%% from fats.\n", total_calories, total_weight, total_carb, total_protein, total_fat);

  return 0;
}




