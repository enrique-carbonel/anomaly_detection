# anomaly_detection
anomaly detection program that models a linear relationship between two sets of data and then tests for anomalies in a separate dataset. This project was made for my introduction to computer programming.

DATA LOADING FOR TRAINING: The program reads training data for the X-axis and Y-axis from separate files (traindata_x.txt and traindata_y.txt).

MODELING: The program calculates coefficients calc1 and calc2 for a linear model using the least squares method.

DATA LOADING FOR TESTING: The program reads testing data for the X-axis and Y-axis from separate files (testdata_x.txt and testdata_y.txt).

TESTING AND ANOMALY DETECTION: The program applies the linear model to the testing data and calculates the absolute difference between the predicted Y values and the actual Y values. If this difference exceeds a predefined threshold (threshold), it is considered an anomaly.

RESULTS DISPLAY: The program prints the results of the testing, including the number of detected anomalies and the percentage of anomalous data points in the test sample set.

This program reads training data, models a linear relationship, reads testing data, tests for anomalies, and then prints the results of the anomaly detection process. The linear model and anomaly detection are based on predefined coefficients and a threshold.
