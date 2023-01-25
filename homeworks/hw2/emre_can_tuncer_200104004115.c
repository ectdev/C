#include <stdio.h>

int main()
{
    int i = 0, counter = 0, k = 0;
    int num;
    int numbers[100];
    int repeat[100];
    FILE *inputfile;
    FILE *outputfile;

    inputfile = fopen("input.txt", "r");
    outputfile = fopen("output.txt", "w");


    while (fscanf(inputfile, "%d", &num) != EOF)
    {  
        for(k = 0; k <= i; k++)
        {
            if(numbers[k] == num)
            {
                break;
            }

            if((numbers[k] != num) && (k == i))
            {
                numbers[i] = num;
                i++;
                k = i;
                break;
            }
        } 
    }

    for (k = 0; k<i; k++)
    {printf("%d \n", numbers[k]);}
    

fclose(inputfile);
fclose(outputfile);
return 0;
}




























































/*            if (counter == 0 && k < 1)
            {  
                                        printf("\n asdasd %d %d %d", num, i, counter);
                numbers[i] = num;
                i++;
                k = i;
                break;
            }    
                else if (numbers[k] != num)
                {
                    k--;
                }
                    else if((k<1) && (counter !=0))
                    {

                        numbers[i] = num;
                        fprintf(outputfile, "%d ", numbers[i]);
                        i++;
                        counter++;
                        k = i;
                        break;
                    }
            else continue;*/



