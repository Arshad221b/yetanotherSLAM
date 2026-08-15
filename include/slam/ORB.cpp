//
// Created by Arshad K on 16/07/26.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    string video_path = "/Users/michelangelo/Desktop/test_slam.mp4";

    VideoCapture video(video_path);

    if (!video.isOpened())
    {
        cout << "Error opening the video" << endl;
        return -1;
    }

    Mat frame;
    video.read(frame);
    Rect roi = selectROI("Select Object", frame);
    destroyWindow("Select Object");

    Mat object = frame(roi);

    Ptr<ORB> orb = ORB::create();
    vector<KeyPoint> objKeypoints;
    Mat objectDescriptors;

    orb-> detectAndCompute(object, noArray(), objKeypoints, objectDescriptors);


    BFMatcher matcher(NORM_HAMMING);
    while (video.read(frame))
    {
        vector<KeyPoint> frameKeypoints;
        Mat frameDiscriptors;
        orb->detectAndCompute(frame, noArray(), frameKeypoints, frameDiscriptors);

        if (frameDiscriptors.empty()) continue;

        vector<DMatch> matches;
        matcher.match(objectDescriptors, frameDiscriptors, matches);

        for (const auto& m: matches)
        {
            if (m.distance < 40)
            {
                circle(frame, frameKeypoints[m.trainIdx].pt, 5, Scalar(0,255,0), 2);
            }
        }

        imshow("Matches", frame);
        if (waitKey(30)==27) break;
    }

    return 0;
}


