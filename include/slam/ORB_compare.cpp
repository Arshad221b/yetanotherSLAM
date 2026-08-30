//
// Created by Arshad K on 30/08/26.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    string img1_path = "data/rgbd_dataset_freiburg1_desk/rgb/1305031452.791720.png";
    string img2_path = "data/rgbd_dataset_freiburg1_desk/rgb/1305031452.823674.png";
    // string img2_path = "data/rgbd_dataset_freiburg1_desk/rgb/1305031452.923715.png";

    Mat img1 = imread(img1_path);
    Mat img2 = imread(img2_path);

    Ptr<ORB> orb = ORB::create();
    vector<KeyPoint> objKeyPoints1;
    Mat objDescriptors1;
    vector<KeyPoint> objKeyPoints2;
    Mat objDescriptors2;

    orb -> detectAndCompute(img1, noArray(), objKeyPoints1, objDescriptors1);
    orb -> detectAndCompute(img2, noArray(), objKeyPoints2, objDescriptors2);


    BFMatcher matcher(NORM_HAMMING);
    vector<vector<DMatch>> knnMatches;
    matcher.knnMatch(objDescriptors1, objDescriptors2, knnMatches, 2);

    const float ratio = 0.75f;
    vector<DMatch> goodMatches;
    for (const auto& candidates : knnMatches)
    {
        if (candidates.size() < 2) continue;
        if (candidates[0].distance < ratio * candidates[1].distance)
        {
            goodMatches.push_back(candidates[0]);
        }
    }
    cout << "raw knn candidates: " << knnMatches.size()
         << ", good matches after ratio test: " << goodMatches.size() << endl;

    cv:: Mat imgMatches;
    cv:: drawMatches(
        img1, objKeyPoints1,
        img2, objKeyPoints2,
        goodMatches,
        imgMatches,
        cv::Scalar::all(-1),
         cv::Scalar::all(-1),
         std::vector<char>(),
         cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS
        );

    cv::imshow("Matches Visualization", imgMatches);
    cv::waitKey(0);

    return 0;
}