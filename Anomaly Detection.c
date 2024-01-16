#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    FILE *archivo;
    int i = 0;
    int n = 2000;
    float calc1;
    float calc2;
    float sumX=0.0;
    float sumaX=0.0;
    float sumY=0.0;
    float sumXY=0.0;
    double x[2000];
    double y[2000];
    double m = 0.00198404;
	double c = 0.00265998;
    double temp = 0.0;
    double xArray[3000];
    double yArray[3000];
    double testArrayX[3000];
    double threshold = 0.1;
    int temporaryAnamoly = 0;
    double percentOfSum = 0.0;

    printf ("Anamoly Detection Program ....\n");
    printf ("Reading sampled sensor values (X-axis data) for training ....\n");
    
    archivo = fopen("traindata_x.txt", "r");
    
    for(int i = 0; i < 2000; i++)
    {
        fscanf (archivo, "%lf", &temp);
        x[i]= temp;
    }
    fclose(archivo);
    
    printf ("Reading sampled sensor values (Y-axis data) for training ....\n");
    
    archivo = fopen("traindata_y.txt", "r");
    
    for(int i = 0; i < 2000; i++)
    {
        fscanf (archivo, "%lf", &temp);
        y[i]= temp;
    }
    fclose(archivo);
  
  for(i = 0; i < 2000; i++)
  {
    sumX = sumX + x[i];
    sumaX = sumaX + x[i] * x[i];
    sumY = sumY + y[i];
    sumXY = sumXY + x[i] * y[i];
  }
  
  printf ("Modeling in progress ....\n");
  
  calc1 = ((sumaX * sumY - sumX * sumXY) * 1.0 / (n * sumaX - sumX * sumX) * 1.0);
  calc2 = ((n * sumXY - sumX * sumY) * 1.0 / (n * sumaX - sumX * sumX) * 1.0);
  
  printf ("Modeling complete ....\n");
  printf("The trained data is modeled using calc1  linear curve fit modeled as y = %3.6f + %3.6fx\n", calc1, calc2);
  printf ("Reading sampled sensor values (X-axis data) for testing ....\n");
  
  archivo = fopen("testdata_y.txt", "r");
  
  for(int i = 0; i < 3000; i++)
  {
    fscanf (archivo, "%lf", &temp);
    yArray[i]= temp;
  }
  fclose(archivo);
  
  printf ("Reading sampled sensor values (X-axis data) for testing ....\n");
  
  archivo = fopen("testdata_x.txt", "r");
  
  printf ("Testing in progress ....\n");
  
  for (int i = 0; i < 3000; i++)
  {   
    fscanf (archivo, "%lf", &temp);
    xArray[i]= temp;
    temp = m * xArray[i] + c;
    testArrayX[i] = fabs(temp - yArray[i]);
    if (testArrayX[i] > threshold)
    {
        temporaryAnamoly++;
    }
  }
  
  printf ("Testing complete ....\n");
  printf ("In the test sample set of 3000 points, the number of anamolous data points are %d \n", temporaryAnamoly);
  
  percentOfSum = 100.0 * (temporaryAnamoly / 3000.0);
  printf ("The percentage of anamolous data points is: %lf\n",percentOfSum);
  
return 0;
}