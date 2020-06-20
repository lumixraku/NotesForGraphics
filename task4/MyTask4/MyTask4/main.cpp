#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>

std::vector<cv::Point2f> control_points;

void mouse_handler(int event, int x, int y, int flags, void *userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN && control_points.size() < 4)
    {
        std::cout << "Left button of the mouse is clicked - position (" << x << ", "
        << y << ")" << '\n';
        control_points.emplace_back(x, y);
    }
}

void naive_bezier(const std::vector<cv::Point2f> &points, cv::Mat &window)
{
    auto &p_0 = points[0];
    auto &p_1 = points[1];
    auto &p_2 = points[2];
    auto &p_3 = points[3];

    for (double t = 0.0; t <= 1.0; t += 0.001)
    {
        auto point = std::pow(1 - t, 3) * p_0 + 3 * t * std::pow(1 - t, 2) * p_1 +
                 3 * std::pow(t, 2) * (1 - t) * p_2 + std::pow(t, 3) * p_3;

        window.at<cv::Vec3b>(point.y, point.x)[2] = 255;
    }
}

cv::Point2f recursive_bezier(const std::vector<cv::Point2f> &control_points, float t)
{
    // TODO: Implement de Casteljau's algorithm
    if(control_points.size() ==1 ) return control_points[0];
    std::vector<cv::Point2f> NextRecursive;
    for(int i = 0;i<control_points.size() - 1 ;i++)
    {
        NextRecursive.push_back(cv::Point2f(
            control_points.at(i).x * (1-t) + t * control_points.at(i+1).x,
            control_points.at(i).y * (1-t) + t * control_points.at(i+1).y
            ));
    }
    return recursive_bezier(NextRecursive,t);
    //return cv::Point2f();
}

void bezier(const std::vector<cv::Point2f> &control_points, cv::Mat &window)
{
    // TODO: Iterate through all t = 0 to t = 1 with small steps, and call de Casteljau's
    // recursive Bezier algorithm.
    for(double t = 0.0;t <= 1.0;t+= 0.001)
    {
        auto point = recursive_bezier(control_points,t);
        int xmin = std::floor(point.x);
        int ymin = std::floor(point.y);

        //solution - 0
        //window.at<cv::Vec3b>(point.y, point.x)[1] = 255;//set the color to green

        //solution-1
        //int colorValue = 255* 2 * std::sqrt((point.x - xmin - 0.5f)* (point.x - xmin - 0.5f) + (point.y -0.5f - ymin)*(point.y -ymin - 0.5f) ) / 1.41421356;
        //window.at<cv::Vec3b>(point.y, point.x)[1] = std::min(255,colorValue + window.at<cv::Vec3b>(point.y, point.x)[1]);//set the color to green
        
        //solution2
        float maxDis = 1.06066017f;
        float color0 = 0;
        float color1 = 0;
        float color2 = 0;
        float color3 = 0;
        int colorValue = 0;
        color0 = 255 *  (maxDis - std::sqrt( std::pow(point.x-xmin-0.25f,2)+std::pow(point.y-ymin-0.25f,2) )) / maxDis;
        color1 = 255 *  (maxDis - std::sqrt( std::pow(point.x-xmin-0.25f,2)+std::pow(point.y-ymin-0.75f,2) )) / maxDis;
        color2 = 255 *  (maxDis - std::sqrt( std::pow(point.x-xmin-0.75f,2)+std::pow(point.y-ymin-0.25f,2) )) / maxDis;
        color3 = 255 *  (maxDis - std::sqrt( std::pow(point.x-xmin-0.75f,2)+std::pow(point.y-ymin-0.75f,2) )) / maxDis;
        colorValue = (color0 + color1+color2+color3 )/4.0f;
        window.at<cv::Vec3b>(point.y, point.x)[1] = std::min(255,100 + window.at<cv::Vec3b>(point.y, point.x)[1]);//set the color to green
    }

}

int main()
{
    cv::Mat window = cv::Mat(700, 700, CV_8UC3, cv::Scalar(0));
    cv::cvtColor(window, window, cv::COLOR_BGR2RGB);
    cv::namedWindow("Bezier Curve", cv::WINDOW_AUTOSIZE);

    cv::setMouseCallback("Bezier Curve", mouse_handler, nullptr);

    int key = -1;
    while (key != 27)
    {
        for (auto &point : control_points)
        {
            cv::circle(window, point, 3, {255, 255, 255}, 3);
        }

        if (control_points.size() == 4)
        {
            naive_bezier(control_points, window);
            bezier(control_points, window);

            cv::imshow("Bezier Curve", window);
            cv::imwrite("my_bezier_curve.png", window);
            key = cv::waitKey(0);

            return 0;
        }

        cv::imshow("Bezier Curve", window);
        key = cv::waitKey(20);
    }

return 0;
}
