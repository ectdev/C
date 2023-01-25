#include <stdio.h>
#include <stdlib.h>

#define maxSequence 1000   /*defining all constant values for calculations*/
#define maxChunk 101
#define p1 0.5
#define p2 20.0

int main() {    
double sequence_array[maxSequence];   /*Declaring an array to store the values from input.txt document*/
double chunks_array[maxChunk][maxChunk];    /*declaring an array to split it into chunks and writing to the output.txt document */
double chunk_holder[maxChunk];      /*declaring a 1d array to store a chunk for bubble sort by averages of each chunk*/

int i = 0, j = 0, k = 0, sequenceCounter = 0, chunkMember = 0, total_used = 0, remaining , chunk_average = 0, chunk_counter;
double num, b, a, n, chunktotal = 0;

FILE* inputfile;
FILE* outputfile;
inputfile = fopen("input.txt", "r");    /*opening the files and taking the values from it to store in the "sequence_array"*/
outputfile = fopen("output.txt", "w");

while (fscanf(inputfile, "%lf", &num)!= EOF)
{
    sequence_array[i] = num;
    i++;
    sequenceCounter = sequenceCounter + 1;      /*counting the values that the program reads to use it later for limiting the loops*/
}

remaining = sequenceCounter;            /*remaining values to be read and calculated*/

for(i = 0; i< maxChunk; i++)
{
    for(j=0; j < maxChunk; j++)
        chunks_array[i][j] = -9999.9999;            /*assigning a garbage value to each index of array which will be used to store chunks*/
}

    n = sequence_array[0];                                            
for(i = 0; total_used < sequenceCounter ; i++)
{      
    for (j=0 ; j < remaining ; j++)
    {   
        if(chunkMember == 0)     /*if the chunk has no members, assigning the next value to it*/
        {   
            chunks_array[i][chunkMember] = n;
            chunktotal = chunktotal + n;
            chunkMember++;
            total_used++;
            printf("\nburaya girildi chunkmember 0 kısmı: %d. adım \n chunktotal %f \n ", total_used, chunktotal);
        }
        /*calculating the values according to given task*/
        n = sequence_array[total_used+1];
        a = chunktotal/(chunkMember);
        b = (n + chunktotal)/(chunkMember+1);


            if((b <= (a*(1+p1))) && (b >= (a*(1-p1))) && (a <= (n * p2)) && (a >= (n/p2))) /*checking the given condition*/
                {
                    if(chunkMember != 0)                                                       /*and if the line has value already, if the checked condition is true, add the value as the chunk member*/ 
                    {
                        chunks_array[i][chunkMember] = n; 
                        chunktotal = chunktotal + n;
                        chunkMember++;          
                        total_used++;       
                                    printf("buraya girildi sonraki chunkmemberlar %d. adım\n chunktotal : %f", total_used, chunktotal);    /*total used nunber from given sequence*/
                    }                     
                }
                
                else break;
    }   
        chunk_counter++;
        chunk_average = chunktotal / chunkMember;
        chunks_array[i][100] = chunk_average;
        chunkMember = 0;
        chunktotal = 0;
        remaining = sequenceCounter - total_used;
}

for(i=0; i<chunk_counter; i++)
    {
            if(chunks_array[i][100]>chunks_array[i+1][100])
                {
                    for(k = 0; chunks_array[i+1][k] != -9999.9999; k++)     /*sorting the chunks according to their average*/
                    {
                        chunk_holder[k] = chunks_array[i+1][k];
                        chunks_array[i+1][k] = chunks_array[i][k];
                        chunks_array[i][k] = chunk_holder[k]; 
                    }
                }
    }

for (i = 0; i <= chunk_counter -1; i++)
{
    for(j=0; j<100; j++)
        {
            if(chunks_array[i][j] != -9999.9999)
            fprintf(outputfile, "%.4f ", chunks_array[i][j]);
        }
        fprintf(outputfile, "\n");

}

fclose(inputfile);
fclose(outputfile);
    return 0;
}