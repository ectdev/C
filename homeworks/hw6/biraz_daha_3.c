#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INGREDIENTS 20
#define MAX_NAME_LENGTH 30
#define CARB_CAL_1G 4    /* Number of calories in 1g carbohydrate */
#define PROTEIN_CAL_1G 4 /* Number of calories in 1g protein */
#define FAT_CAL_1G 9     /* Number of calories in 1g fat */
#define WATER_CAL_1G 0   /* Number of calories in 1g water */

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int weight;
    int calories;
    int carbs;
    int proteins;
    int fats;
} Ingredient;

int convertToGrams(char ingredient[]);
void get_ingredients(Ingredient *ingr);

int main()
{
    Ingredient meal;
    printf("What is the meal?:\n");
    fgets(meal.name, MAX_NAME_LENGTH, stdin);
    get_ingredients(&meal);
    printf("Total calories is %d in %dg %s. %d%% calories from carbs, %d%% from proteins, %d%% from fats.\n",
           meal.calories, meal.weight, meal.name, meal.carbs, meal.proteins, meal.fats);

    return 0;
}

void get_ingredients(Ingredient *ingr){
    char input[600], holder[MAX_NAME_LENGTH];
    int num_ingredients = 0, weight = 0, i, subgredient_check;
    Ingredient ingredients[MAX_INGREDIENTS];

        printf("What is %s?\n", ingr->name);
        fgets(input, 600, stdin);
        /* Split the input into individual ingredients */
        char *token = strtok(input, ", ");
        /* Parse the ingredients and weights */
        while (token != NULL){
            /* Check if the token is an ingredient or a weight */
            strcpy(holder, token);




            token = strtok(NULL, ", ");
        }













}



int convertToGrams(char ingredient[]) {
int i = 0;
while (ingredient[i] != '(' && ingredient[i] != '\0') {
i++;
}
if (ingredient[i] == '(') {
i++;
int j = 0;
int number = 0;
while (ingredient[i] != 'g' && ingredient[i] != '\0') {
number = number * 10 + (ingredient[i] - '0');
i++;
j++;
}
return number;
}
return -1;
}



