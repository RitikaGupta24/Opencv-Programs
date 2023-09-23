#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cstdlib> 
using namespace std;
using namespace cv;

int main()
{
    // Clear the console screen
    system("cls"); // For Windows

    Mat img(512, 512, CV_8UC3, Scalar(128, 128, 128));
    // Create shapes on the blank image

    // Circle
    circle(img, Point(256, 256), 155, Scalar(0, 69, 250), FILLED);

    // Rectangle
    rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);

    // Line
    line(img, Point(130, 296), Point(382, 296), Scalar(0, 0, 0), 3);

    // Text
    putText(img, "ParkMate", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.80, Scalar(0, 0, 128), 2);

    // Ellipse
    ellipse(img, Point(256, 400), Size(100, 50), 0, 0, 360, Scalar(0, 255, 0), FILLED);

    // Show the image
    imshow("Shapes and Text", img);

    // Wait for a key press
    waitKey(0);

    return 0;
}
