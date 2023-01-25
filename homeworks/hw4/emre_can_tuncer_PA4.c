#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
====================================================================================
==============================SEARCHING FUNCTIONS===================================
=========THE ALGORITHM ALREADY INCLUDES THE SOLUTION FOR BONUS PROBLEM==============
====================================================================================
*/


int search0(FILE* output, char array[][252], char word_holder[], int length , int i, int j)     /*The parameters are readed from main function*/
{                                                                                               /*output is the txt file to be written with coordinates*/
        int k;                                                                                  /*char array is the input_2 file to store puzzle board*/
        int row_holder = i;                                                                     /*length is the length of wanted word to limit loops*/
        int column_holder = j;                                                                  /*k is the step parameter to compare puzzle's letter and word's step by step*/
                                                                                                /*we have column and row holders because i and j will be changed*/
    while(i>1 && j>1)                                                                           /*we jave while loop to limit going Northwest direction, if we want to go NW, we need reduce i and j together*/
    {                                                                                          
        for(k = 1; k < length; k++)
        {
            if(array[i-1][j] == word_holder[k])
            {
                i--;
                j--;
            }
                else
                {
                    return 0;                                                                       /*if any step doesn't match, for breaking the function's running, returns a value*/
                }
            
            if (k == length - 1)
            {
               fprintf(output, "%s (%d, %d) 'NW'\n", word_holder, row_holder, column_holder);   /*writing founded word and its coordinates to output file which is already taken as function parameter*/
                return 1;                                                                         /*if written, finish the function*/
            }
        }
    }
    return 0;                                                                                    /*all instructions are valid for also other searching methods etc. (1-2-3-4-5-6-7)*/
}


int search1(FILE* output, char array[][252], char word_holder[], int length , int i, int j)
{    
    int k;
        int row_holder = i;
    int column_holder = j;
    while(i>1 && j<252)
    {
    
        for(k = 1; k < length; k++)
        {
            if(array[i-1][j] == word_holder[k])
            {
                i--;
                j++;
            }
            else
            {
                return 0;
            }
            
            if (k == length - 1)
            {
                fprintf(output, "%s (%d, %d) 'NE'\n", word_holder, row_holder, column_holder);
                return 1;
            }
        }
    }
    return 0;
}


int search2(FILE* output, char array[][252], char word_holder[], int length , int i, int j)
{    
    int k;
        int row_holder = i;
    int column_holder = j;

    while(i<101 && j>1)
    {
    
        for(k = 1; k < length; k++)
        {
            if(array[i+1][j] == word_holder[k])
            {
                i++;
                j--;
            }      
                else
                {   
                    return 0;
                }
            
            if (k == length - 1)
            {
               fprintf(output, "%s (%d, %d) 'SW' \n", word_holder, row_holder, column_holder+2);
                return 1;
            }
        }
    }
    return 0;
}

int search3(FILE* output, char array[][252], char word_holder[], int length , int i, int j)
{    
    int k;
        int row_holder = i;
    int column_holder = j;
  
    while(i<101 && j<252)
    {
    
        for(k = 1; k < length; k++)
        {
            if(array[i-1][j] == word_holder[k])
            {
                i++;
                j++;
            }
      
            else
            {
                return 0;
            }
            
            if (k == length - 1)
            {
                fprintf(output, "%s (%d, %d) 'SE'\n", word_holder, row_holder-2, column_holder);
                return 1;
            }
        }
    }
    return 0;
}

int search4(FILE* output, char array[][252], char word_holder[], int length , int i, int j)
{    
    int k;
    int row_holder = i;
    int column_holder = j;
  
    while(i>1)
    {
    
        for(k = 1; k < length; k++)
        {
            if(array[i][j-1] == word_holder[k-1])
            {
                i--;
            }
      
            else
            {
                return 0;
            }
            
            if (k == length - 1)
            {
                fprintf(output, "%s : (%d, %d) 'N' \n", word_holder, row_holder, column_holder);
                return 1;
            }
        }
    }
return 0;
}

int search5(FILE* output, char array[][252], char word_holder[], int length , int i, int j)
{    
    int k;
        int row_holder = i;
    int column_holder = j;
  
    while(i<101)
    {
    
        for(k = 1; k < length; k++)
        {
            if(array[i-1][j-1] == word_holder[k])
            {
                i++;
            }
      
            else
            {
                return 0;
            }
            
            if (k == length - 1)
            {

              fprintf(output, "%s (%d, %d) 'S'\n", word_holder, row_holder-2, column_holder);
                return 1;
            }
        }
    }
return 0;
}

int search6(FILE* output, char array[][252], char word_holder[], int length , int i, int j)
{    
    int k;
        int row_holder = i;
    int column_holder = j;
  
    while(j>1)
    {
        for(k = 1; k < length; k++)
        {
            if(array[i][j] == word_holder[k])
            {
                j--;
            }
      
            else
            {
                return 0;
            }
            
            if (k == (length - 1))
            {
               fprintf(output, "%s (%d, %d) 'W'\n", word_holder, row_holder, column_holder+2);
                return 1;
            }
        }
    }
return 0;
}


int search7(FILE* output, char array[][252], char word_holder[], int length , int i, int j)
{    
    int k;
    int row_holder = i;
    int column_holder = j;
  
    while(j<252)
    {
        for(k = 1; k < length; k++)
        {
            if(array[i][j] == word_holder[k])
            {
                j++;
            }
      
            else
            {
                return 0;
            }
            
            if (k == length - 1)
            {
            fprintf(output, "%s (%d, %d) 'E'\n", word_holder, row_holder, column_holder);
             return 1;
            }
        }
    }
return 0;
}


int main(){
    int i = 1, j = 1, k = 1, length_of_word = 0, row_counter = 0, number_of_words = 0, row = 0, column = 0 , t = 0;
    char input_2[101][252];     /*to hold puzzle table*/
    char input_1[251][12];      /*to hold wanted words*/
    char word_holder[12];       /*to store the wanted word into a separate array in each steps*/
    char line[252];             /*to store each line of the board with fgets*/
    FILE *input2;
    FILE *input1;
    FILE *output;                                           
    input2 = fopen("input2.txt", "r");
    input1 = fopen("input1.txt", "r");
    output = fopen("output.txt", "w");

        
    while(!feof(input2))
    {
        fscanf(input2, "%s", input_2[i]);   /*reading strings from files and store them into arrays*/
        i++;
        row_counter++;                     /*we increase row counter to limit loops*/
    }   
        i = 1;
        column = 1;

    while(!feof(input1))
    {
        fscanf(input1, "%s", input_1[i]);
        i++;
        number_of_words++;            /*we increase 'reading numbers' value to limit loops*/
    }
    


        while(k <= number_of_words)
            {
            strcpy(word_holder, input_1[k]);                                /*we store the wanted word into a separate array to send it as a parameter to function*/
            length_of_word = strlen(word_holder);                           /*we get this value to limit loops in searching functions by sending it as a parameter*/
  
                for(i = 1; i < row_counter+1; i++)                                         /*the program runs until the last row and each rows last character to check each letter till the end*/
                {
                    for(j = 1; input_2[i][j] != '\0'; j++)
                    {
                        t = search0(output, input_2, word_holder, length_of_word, i, j);   /*if some of the directions matched, the word is printed to output.txt file and passing through to the next word till the last word*/
                        if (t == 1)
                            break;
                        t = search1(output, input_2, word_holder, length_of_word, i, j);
                        if (t == 1)
                            break;
                        t = search2(output, input_2, word_holder, length_of_word, i, j);
                        if (t == 1)
                            break;
                        t = search3(output, input_2, word_holder, length_of_word, i, j);
                        if (t == 1)
                            break;
                        t = search4(output, input_2, word_holder, length_of_word, i, j);
                        if (t == 1)
                            break;
                        t = search5(output, input_2, word_holder, length_of_word, i, j);
                        if (t == 1)
                            break;
                        t = search6(output, input_2, word_holder, length_of_word, i, j);
                        if (t == 1)
                            break;
                        t = search7(output, input_2, word_holder, length_of_word, i, j);
                        if (t == 1)
                            break;

                    }
                    if (t == 1)
                        break;
                }   
                t = 0;             /*The program resets t value to find other words*/
                k++;               /*k is searched word number*/
            }



    fclose(input2);                 /*closing files*/
    fclose(input1);
    fclose(output);

    return 0;
}

/*THANK YOU*/
