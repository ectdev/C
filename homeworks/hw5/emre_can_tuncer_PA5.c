#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/******************************************************************************************************/
void zeromaker(int* board_n[][27]){         /*For reassigning values to zero*/
    int i, j;
    for(i = 0 ; i < 27; i++)
    {
        for (j = 0 ; j < 27 ; j++)
        {
            board_n[i][j] = 0;
        }
    }
}
/******************************************************************************************************/
double abs_calculator(double x){        /*Double type, absolute value returner*/
    if(x < 0)
    return x * -1;
    else
    return x;
}

/******************************************************************************************************/
int index_calculator(double board[][27]) {      /*Language's total bigram calculator*/
    int i, j, total = 0;
    for(i = 0 ; i < 27; i++)
    {
        for (j = 0 ; j < 27 ; j++)
        {
            if(board[i][j]>0)
            {
                total = total + board[i][j];
            }
        }
    }   return total;
}
/******************************************************************************************************/
double diss_calculator(int board_x[][27],int board_n[][27]) { /*Using functions which is created above, dissimilarity is calculated and returned as 'total' variable*/
    int i, j;
    double total = 0;
    int counter_x , counter_n;
    double holder_board_x[50][50];
    double holder_board_n[50][50];

    for(i = 0; i< 27; i++)
    {
        for(j = 0; j< 27; j++)
        {
            holder_board_x[i][j] = board_x[i][j];
            holder_board_n[i][j] = board_n[i][j];
            }
    }

    counter_x = index_calculator(holder_board_n);
    counter_n = index_calculator(holder_board_n);

    for(i = 0 ; i < 27; i++)
    {
        for (j = 0 ; j < 27 ; j++)
        {
            total += abs_calculator((holder_board_x[i][j] / counter_x) - (holder_board_n[i][j] / counter_n));
        }
    }
return total;
}
/******************************************************************************************************/
void bigram_calc(int c1, int c2, int* board_x[][27], int* counter) {        /*Using some conditions, bigrams are calculated*/
    int i, j, holder_c1, holder_c2, row_holder, column_holder;
    int row, column;

    if (counter == 0)
    {
        holder_c1 = ' ';
        holder_c2 = ' ';
    }

    if(c1 != ' ')       /*fgetc returns an integer value as the ascii value of the character, and 'a' starts from index 0 and it's asci value is 97*/
    {row = c1 - 97;
    }
    else
    {row = 26;
    }
    if(c2 != ' ')
    {
        column = c2 - 97;
    }
    else
    {
        column = 26;
    }


    if((c1 == ' ') && (c2 == ' ') && (holder_c2 == ' '))
    {
    ;
    }
        else if((c1 != ' ') && (c2 == ' ') && (holder_c2 == ' '))
        {
        board_x[row][column]++;
        counter++;
        }
            else if((c1 != ' ') && (c2 != ' ') && ((holder_c2 == ' ')))
                {
                board_x[row][26]++;
                board_x[row][column]++;
                counter+=2;
                }
                    else if((c1 != ' ') && (c2 != ' ') && (holder_c2 != ' '))
                    {
                    board_x[column_holder][row]++;
                    board_x[row][column]++;
                    counter+=2;
                    }
                        else if((c1 == ' ') && (c2 != ' ')&& (holder_c2 == ' '))
                        {
                        board_x[column][row]++;
                        counter++;
                        }
                            else if((c1 == ' ') && (c2 != ' ') && (holder_c2 != ' '))
                            {
                            board_x[column_holder][row]++;   
                            board_x[column][row]++;
                            printf("%d", board_x[column_holder][row]);
                            counter+=2;
                            }
                                else if((c1 == ' ') && (c2 == ' ') && (holder_c2 != ' '))
                                {
                                board_x[column_holder][row]++;
                                counter++;
                                }
                                    else if((c1 != ' ') && (c2 == ' ') && (holder_c2 != ' '))
                                    {
                                    board_x[row][column]++;
                                    board_x[column_holder][row]++;
                                    counter+=2;
                                    }
    holder_c1 = c1;
    holder_c2 = c2;
    row_holder = row;
    column_holder = column;
}
/******************************************************************************************************/

int main() {
  int row, column, c1, c2, holder_c2, row_holder, column_holder, *counter_x = 0, *counter_n = 0, i, j;  
  double total = 0;
    int* board_x[27][27];
    int* board_nth[27][27];
    FILE* language_x;
    FILE* language_1;
    FILE* language_2;
    FILE* language_3;
    FILE* language_4;
    FILE* language_5;

    zeromaker(board_x);

    language_x = fopen("language_x.txt", "r");
    language_1 = fopen("language_1.txt", "r");
    language_2 = fopen("language_2.txt", "r");
    language_3 = fopen("language_3.txt", "r");
    language_4 = fopen("language_4.txt", "r");
    language_5 = fopen("language_5.txt", "r");

    if(language_x == NULL)
    {
        printf("\n--LANGUAGE X COULDN'T BE FIGURED OUT--\n");
        fclose(language_x);
        return 1;
    }

    while(!feof(language_x))
    {
    c1= fgetc(language_x);
    c2= fgetc(language_x);
    bigram_calc(c1, c2, board_x, counter_x);
    }
    fclose(language_x);

    while(!feof(language_1))
    {
    c1= fgetc(language_1);
    c2= fgetc(language_1);
    bigram_calc(c1, c2, board_nth, counter_n);
    }
    total = diss_calculator(board_x, board_nth)/100;
    printf("\n Dissimilarity between Language_x and Language_1 is %f", total);
    total = 0;
    counter_n = 0;
    zeromaker(board_nth);
    fclose(language_1);

    while(!feof(language_2))
    {
    c1= fgetc(language_2);
    c2= fgetc(language_2);
    bigram_calc(c1, c2, board_nth, counter_n);
    }
    total = diss_calculator(board_x, board_nth);
    printf("\n Dissimilarity between Language_x and Language_2 is %f", total);
    total = 0;
    counter_n = 0;
    zeromaker(board_nth);
    fclose(language_2);

    while(!feof(language_3))
    {
    c1= fgetc(language_3);
    c2= fgetc(language_3);
    bigram_calc(c1, c2, board_nth, counter_n);
    }
    total = diss_calculator(board_x, board_nth);
    printf("\n Dissimilarity between Language_x and Language_3 is %f", total);
    total = 0;
    counter_n = 0;
    zeromaker(board_nth);
    fclose(language_3);

    while(!feof(language_4))
    {
    c1= fgetc(language_4);
    c2= fgetc(language_4);
    bigram_calc(c1, c2, board_nth, counter_n);
    }
    total = diss_calculator(board_x, board_nth);
    printf("\n Dissimilarity between Language_x and Language_4 is %f", total);
    total = 0;
    counter_n = 0;
    zeromaker(board_nth);
    fclose(language_4);

    while(!feof(language_5))
    {
    c1= fgetc(language_5);
    c2= fgetc(language_5);
    bigram_calc(c1, c2, board_nth, counter_n);
    }
    total = diss_calculator(board_x, board_nth);
    printf("\n Dissimilarity between Language_x and Language_5 is %f", total);
    fclose(language_5);

  return 0;
}
