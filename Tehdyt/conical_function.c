#include <math.h>
#define M_PI 3.14159265358979323846


double cone_volume(double radius, double height);
    
double cone_volume(double radius, double height){
    return (1.0/3.0) * M_PI * radius * radius * height;
}