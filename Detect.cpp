//#include <opencv2/imgcodecs.hpp>
//#include<opencv2/highgui.hpp>
//#include<opencv2/imgproc.hpp>
//#include<opencv2/objdetect.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//void main() {
//	VideoCapture cap(1);
//	
//	CascadeClassifier faceCascade;
//	faceCascade.load("haarcascade_frontalface_default.xml");
//
//	if (faceCascade.empty()) {
//		cout << "XML file is not loaded properly" << endl;
//	}
//	vector<Rect>faces;
//	Mat img;
//	while (true) {
//		cap.read(img);
//		imshow("Image", img);
//	}
//	try {
//		faceCascade.detectMultiScale(img, faces, 1.1, 10);
//	}
//	catch (cv::Exception& e) {
//		cout << "OpenCV Exception: " << e.what() << endl;
//		
//	}
//	for (const Rect& face : faces)
//	{
//		rectangle(img, faces.tl(), faces.br(), Scalar(255, 0, 255), 3);
//	}
//	imshow("Face Detection", img);
//
//	if (waitKey(1) == 27) 
//	{ // Exit when the 'Esc' key is pressed
//		break;
//	}
//}
//
//cap.release();
//destroyAllWindows();
//
//
//	
//}

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main9() {

    //creating code for car number plate detection from img using web cam;
    //web cam initialization;

    VideoCapture cap(0);  

    if (!cap.isOpened()) {
        cerr << "Error: Could not open camera." << endl;
        return 1;
    }

    CascadeClassifier plateCascade;
    if (!plateCascade.load("haarcascade_russian_plate_number.xml")) {
        cout << "Error: XML file is not loaded properly." << endl;
        return 1;
    }

    Mat img;
    while (true) {
        if (!cap.read(img)) {
            cerr << "Error: Could not read a frame." << endl;
            break;  
        }

        vector<Rect> plate;
        plateCascade.detectMultiScale(img, plate, 1.1, 10);

        for (const Rect& plate : plate) {
            rectangle(img, plate.tl(), plate.br(), Scalar(255, 0, 255), 3);
        }

        imshow("Plate Num Detection", img);

        if (waitKey(1) == 27)
        { 
            break;
        }
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
