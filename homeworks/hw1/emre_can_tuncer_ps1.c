#include <stdio.h>
#define CLASS_MAX 3                                                                     /*Predefined macro to take number of points' coordinates*/

int main()
{
    int i;
    double x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0;                                          /*to calculate the x and y points separately, initial value should be 0*/
    double class1x, class1y, class2x, class2y;                                          /*to hold the x and y coordinates for points*/
    double average_x1, average_y1, average_x2, average_y2;                              /*average x and y values for each class*/
    double m_of_averageline, m_of_separatingline, mid_x, mid_y,                         /*'m' means slope of the line, mid means midpoint of aver. line */    
            testpoint_x, testpoint_y, equal_x;                                          /*equal x holds value to compare the x coordinate of the line and point and classify them*/

    printf("\nPlease enter the coordinates of %d points for class 1. ", CLASS_MAX);
        for(i = 0; i< CLASS_MAX ; i++ )                                                 /*taking number of point for class 1 and class 2 and calculating the...*/
        {                                                                               /*...average coordinates of x,y for each class.*/ 
                scanf("%lf" , &class1x);
                scanf("%lf" , &class1y);
                x_1 = x_1 + class1x;
                y_1 = y_1 + class1y;
            printf("\n");
        }
    average_x1 = x_1/CLASS_MAX;
    average_y1 = y_1/CLASS_MAX;
      
    printf("Please enter the coordinates of %d points for class 2. ", CLASS_MAX);

        for(i = 0; i< CLASS_MAX ; i++ )
        {
                scanf("%lf" , &class2x);
                scanf("%lf" , &class2y);
                x_2 = x_2 + class2x;
                y_2 = y_2 + class2y;
            printf("\n");
        }
    average_x2 = x_2/CLASS_MAX;
    average_y2 = y_2/CLASS_MAX;

m_of_averageline = (y_2 - y_1)/(x_2 - x_1 + 0.00001) + 0.0000001;                       /*calculating the slope of average line and midpoint of it*/
   mid_x = (x_1 + x_2)/2;
   mid_y = (y_1 + y_2)/2; 

m_of_separatingline = (-1 / m_of_averageline + 0.00001)+0.0000001;                      /*calculating the slope of separating line using average line's slope*/
    equal_x = testpoint_y/m_of_separatingline;                                          

   printf("Please enter the test point, if you want to exit insert a character. \n");   
   while(scanf("%lf %lf", &testpoint_x, &testpoint_y))
    {
        if(testpoint_x > (m_of_separatingline * equal_x))
            printf("class1\n\n");
            else
            printf("class2\n\n");
    }
return 0;
}