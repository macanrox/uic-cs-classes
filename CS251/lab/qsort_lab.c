#include <stdio.h>
#include <stdlib.h>

/** Put your typedef for Point here **/
typedef struct Point
{
    double x;
    double y;
    struct Point *pts;
}Point, *pts;



/** utility function for printing array of points **/
void print_points(Point *pts, int n){
int i;

    for(i=0; i<n; i++){
        printf("(%f, %f)\n", pts[i].x, pts[i].y);
    }
}
/**
  For reference:  the parameters to qsort.

  void qsort(void *base, size_t nmemb, size_t size,
             int (*compar)(const void *, const void *));

**/

/** Write your comparison functions here **/

/* This will test the x-coordinates. */
void coordX(Point *pts, int j)
{
    int i;

    for(i = 0; i < j; i++)
    {
        /** If the first point is smaller than the
        second, print a negative. **/
        if(pts[i].x < pts[i+1].x)
        {
            printf("-1");
        }
        /** If the first point is equal to the
        second, print 0. **/
        else if(pts[i].x == pts[i+1].x)
        {
            printf("0");
        }
        /** If the first point is larger than the
        second, print a positive. **/
        else if(pts[i].x > pts[i+1].x)
        {
            printf("1");
        }
    }
}//end void compare...

/* This will test the y-coordinates */
void coordY(Point *pts, int j)
{
    int i;

    for(i = 0; i < j; i++)
    {
        /** If the first point is smaller than the
        second, print a negative. **/
        if(pts[i].y < pts[i+1].y)
        {
            printf("-1");
        }
        /** If the first point is equal to the
        second, print 0. **/
        else if(pts[i].y == pts[i+1].y)
        {
            printf("0");
        }
        /** If the first point is larger than the
        second, print a positive. **/
        else if(pts[i].y > pts[i+1].y)
        {
            printf("1");
        }
    }

}//end









int main()
{
    Point p[] = {{2,3}, {4,-1}, {9, -9}, {-7, 7}, {8,8}};

    /** below:  call qsort to sort by x
                print resulting sequence
                then sort by y
                print resulting sequence.
    **/

    coordX(*pts, j);    //sorts by x
    print_points(*pts, j);     //prints the sequence
    coordY(*pts, j);    //sorts by y
    print_points(*pts, j);

    return 1;

}

