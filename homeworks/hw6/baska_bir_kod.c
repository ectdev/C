#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARB_CAL_1G   4 /* Number of calories in 1g carbohydrate */
#define PROTEIN_CAL_1G 4 /* Number of calories in 1g protein */
#define FAT_CAL_1G   9 /* Number of calories in 1g fat */
#define WATER_CAL_1G 0 /* Number of calories in 1g water */

#define MAX_COMPONENTS 20
#define MAX_NAME_LENGTH 30

typedef struct {
  char name[MAX_NAME_LENGTH];
  int weight;
  float carb_percent;
  float protein_percent;
  float fat_percent;
} Component;

typedef struct {
  char name[MAX_NAME_LENGTH];
  Component components[MAX_COMPONENTS];
  int num_components;
} Meal;

void calculate_macro_nutrients(Meal* meal) {
  int total_weight = 0;
  float total_carb_calories = 0;
  float total_protein_calories = 0;
  float total_fat_calories = 0;

  for (int i = 0; i < meal->num_components; i++) {
    Component* component = &meal->components[i];
    if (component->weight > 0) {
      total_weight += component->weight;
      total_carb_calories += component->carb_percent * component->weight * CARB_CAL_1G / 100;
      total_protein_calories += component->protein_percent * component->weight * PROTEIN_CAL_1G / 100;
      total_fat_calories += component->fat_percent * component->weight * FAT_CAL_1G / 100;
    } else {
      calculate_macro_nutrients((Meal*)component);
      total_weight += ((Meal*)component)->total_weight;
      total_carb_calories += ((Meal*)component)->total_carb_calories;
      total_protein_calories += ((Meal*)component)->total_protein_calories;
      total_fat_calories += ((Meal*)component)->total_fat_calories;
    }
  }

  meal->total_weight = total_weight;
  meal->total_carb_calories = total_carb_calories;
  meal->total_protein_calories = total_protein_calories;
  meal->total_fat_calories = total_fat_calories;
}

int main() {
  Meal meal;

  printf("What is the meal?:\n");
  scanf("%s", meal.name);

  printf("What is %s?:\n", meal.name);

  char input[1000];
  fgets(input, 1000, stdin);

  char* token = strtok(input, ", ");
  while (token != NULL) {
    char* paren_pos = strchr(token, '(');
    if (paren_pos != NULL) {
      // This is a







#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CARB_CAL_1G   4 /* Number of calories in 1g carbohydrate */
#define PROTEIN_CAL_1G 4 /* Number of calories in 1g protein */
#define FAT_CAL_1G   9 /* Number of calories in 1g fat */
#define WATER_CAL_1G 0 /* Number of calories in 1g water */
#define MAX_NAME_LEN 30
#define MAX_COMPONENTS 20
typedef struct {
  char name[MAX_NAME_LEN];
  int weight;
  float carb_percent;
  float protein_percent;
  float fat_percent;
  float water_percent;
} component_t;

void parse_input(char* input, component_t* component) {
  // Extract the component name and weight from the input string
  sscanf(input, "%[^(](%dg)", component->name, &component->weight);

  // Initialize the macro nutrient percentages to 0
  component->carb_percent = 0;
  component->protein_percent = 0;
  component->fat_percent = 0;
  component->water_percent = 0;

  // Parse the macro nutrient percentages from the input string
  char* p = strchr(input, ':');
  while (p != NULL) {
    char macro_nutrient[10];
    float percent;
    sscanf(p, ":%%%f %s", &percent, macro_nutrient);
    if (strcmp(macro_nutrient, "C") == 0) {
      component->carb_percent = percent;
    } else if (strcmp(macro_nutrient, "P") == 0) {
      component->protein_percent = percent;
    } else if (strcmp(macro_nutrient, "F") == 0) {
      component->fat_percent = percent;
    }
    p = strchr(p+1, ':');
  }

  // Calculate the water percentage as the remaining percentage
  component->water_percent = 100 - component->carb_percent - component->protein_percent - component->fat_percent;
}

float calculate_calories(component_t* component) {
  float total_calories = 0;

  // Calculate the calories from each macro nutrient
  float carb_calories = component->weight * component->carb_percent / 100 * CARB_CAL_1G;
  float protein_calories = component->weight * component->protein_percent / 100 * PROTEIN_CAL_1G;
  float fat_calories = component->weight * component->fat_percent / 100 * FAT_CAL_1G;
  float water_calories = component->weight * component->water_percent / 100 * WATER_CAL_1G;

  // Add the calories from each macro nutrient to the total calories
  total_calories += carb_calories + protein_calories + fat_calories + water_calories;
}