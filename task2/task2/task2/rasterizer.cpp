// clang-format off
//
// Created by goksu on 4/6/19.
//

#include <algorithm>
#include <vector>
#include "rasterizer.hpp"
#include <opencv2/opencv.hpp>
#include <math.h>
#include <array>

rst::pos_buf_id rst::rasterizer::load_positions(const std::vector<Eigen::Vector3f> &positions)
{
    auto id = get_next_id();
    pos_buf.emplace(id, positions);

    return {id};
}

rst::ind_buf_id rst::rasterizer::load_indices(const std::vector<Eigen::Vector3i> &indices)
{
    auto id = get_next_id();
    ind_buf.emplace(id, indices);

    return {id};
}

rst::col_buf_id rst::rasterizer::load_colors(const std::vector<Eigen::Vector3f> &cols)
{
    auto id = get_next_id();
    col_buf.emplace(id, cols);

    return {id};
}

auto to_vec4(const Eigen::Vector3f& v3, float w = 1.0f)
{
    return Vector4f(v3.x(), v3.y(), v3.z(), w);
}


static bool insideTriangle(float x, float y, const Vector3f* _v)
{
    // TODO : Implement this function to check if the point (x, y) is inside the triangle represented by _v[0], _v[1], _v[2]
    Eigen::Vector2f v1(_v[0].x(),_v[0].y());
    Eigen::Vector2f v2( _v[1].x(),_v[1].y());
    Eigen::Vector2f v3(_v[2].x(),_v[2].y());

    // 三角形 v2v1 边和 v1v3 边构成的两个向量的叉积
    float s  = (v2.x() - v1.x()) * (v3.y() - v1.y()) - (v2.y() - v1.y()) * (v3.x() - v1.x());

    // 三角形 v2v1 和 xy点构成的两个向量的叉积
    float s1 = (v2.x() - v1.x()) * (y    - v1.y()) - (v2.y() - v1.y()) * (x - v1.x());

    // 三角形 v3v1 和 xy点构成的两个向量的叉积
    float s2 = (v1.x() - v3.x()) * (y    - v3.y()) - (v1.y() - v3.y()) * (x - v3.x());

    // 三角形 v2v3 和 xy点构成的两个向量的叉积
    float s3 = (v3.x() - v2.x()) * (y    - v3.y()) - (v3.y() - v2.y()) * (x - v3.x());

    // 几个叉积应该同方向就行
    return ((s*s1) > 0 && (s*s2)>0 && (s*s3)>0);
}

static std::tuple<float, float, float> computeBarycentric2D(float x, float y, const Vector3f* v)
{
    float c1 = (x*(v[1].y() - v[2].y()) + (v[2].x() - v[1].x())*y + v[1].x()*v[2].y() - v[2].x()*v[1].y()) / (v[0].x()*(v[1].y() - v[2].y()) + (v[2].x() - v[1].x())*v[0].y() + v[1].x()*v[2].y() - v[2].x()*v[1].y());
    float c2 = (x*(v[2].y() - v[0].y()) + (v[0].x() - v[2].x())*y + v[2].x()*v[0].y() - v[0].x()*v[2].y()) / (v[1].x()*(v[2].y() - v[0].y()) + (v[0].x() - v[2].x())*v[1].y() + v[2].x()*v[0].y() - v[0].x()*v[2].y());
    float c3 = (x*(v[0].y() - v[1].y()) + (v[1].x() - v[0].x())*y + v[0].x()*v[1].y() - v[1].x()*v[0].y()) / (v[2].x()*(v[0].y() - v[1].y()) + (v[1].x() - v[0].x())*v[2].y() + v[0].x()*v[1].y() - v[1].x()*v[0].y());
    return {c1,c2,c3};
}

void rst::rasterizer::draw(pos_buf_id pos_buffer, ind_buf_id ind_buffer, col_buf_id col_buffer, Primitive type)
{   // pos_buffer 0
    // ind_buffer 1
    // col_buffer 2

    // pos_buf  ind_buf  col_buf 是 rst 的成员变量
    // 这些变量在对应的load 函数中赋值的 比如 pos_buf 在 load_positions 中得到的值


    // pos_buf ind_buf col_buf size都是1

    // buf 有6个点的信息 2个三角形
    auto& buf = pos_buf[pos_buffer.pos_id];
    // ind size = 2
    auto& ind = ind_buf[ind_buffer.ind_id];

    // col size = 6
    auto& col = col_buf[col_buffer.col_id];

    float f1 = (50 - 0.1) / 2.0;
    float f2 = (50 + 0.1) / 2.0;

    Eigen::Matrix4f mvp = projection * view * model;


    // i 是一个 vec3  loop 第一轮是 1 2 3 第二轮是 4 5 6
    for (auto& i : ind)
    {
        Triangle t;


        // 第一轮loop buf[i[0]] = {2, 0, -2}
        // 第二轮loop buf[i[0]] = {3.5, -1, -5}
        Eigen::Vector4f v[] = {
                mvp * to_vec4(buf[i[0]], 1.0f),
                mvp * to_vec4(buf[i[1]], 1.0f),
                mvp * to_vec4(buf[i[2]], 1.0f)
        };


        //Homogeneous division
        for (auto& vec : v) {
            vec /= vec.w();
        }
        //Viewport transformation
        for (auto & vert : v)
        {
            vert.x() = 0.5*width*(vert.x()+1.0);
            vert.y() = 0.5*height*(vert.y()+1.0);
            vert.z() = vert.z() * f1 + f2;
        }
        std::cout << "draw v\n" << v[0] << "\n";

        for (int i = 0; i < 3; ++i)
        {
            t.setVertex(i, v[i].head<3>());
            t.setVertex(i, v[i].head<3>());
            t.setVertex(i, v[i].head<3>());
        }
        std::cout << "draw 2\n" << i << "----\n" << t.v[0] << "\n";
        std::cout << "=============";

        auto col_x = col[i[0]];
        auto col_y = col[i[1]];
        auto col_z = col[i[2]];

        t.setColor(0, col_x[0], col_x[1], col_x[2]);
        t.setColor(1, col_y[0], col_y[1], col_y[2]);
        t.setColor(2, col_z[0], col_z[1], col_z[2]);

        rasterize_triangle(t);

    }
}

//Screen space rasterization
void rst::rasterizer::rasterize_triangle(const Triangle& t) {
    bool NotSuperSamling = false;
    if(NotSuperSamling)
    {
        auto v = t.toVector4();
        // TODO : Find out the bounding box of current triangle.
        // iterate through the pixel and find if the current pixel is inside the triangle
        int xmin = 0;
        int xmax = 0;
        int ymin = 0;
        int ymax = 0;
        float xminf = v[0].x();
        float xmaxf = v[0].x();
        float yminf= v[0].y();
        float ymaxf = v[0].y();

        for(int i =0;i<3;i++)
        {
            if(v[i].x()<xminf) xminf = v[i].x();
            if(v[i].x()>xmaxf) xmaxf = v[i].x();
            if(v[i].y()<yminf) yminf = v[i].y();
            if(v[i].y()>ymaxf) ymaxf = v[i].y();
        }
        xmin = xminf;
        xmax = xmaxf +1;
        ymin = yminf;
        ymax = ymaxf +1;

        //std::cout<<v[0].z()<<std::endl;
        // If so, use the following code to get the interpolated z value.


        Eigen::Vector3f point;
        for(int i = xmin;i<xmax;i++)
        {
            for(int j = ymin;j<ymax;j++)
            {
                // +0.5 w是为了确认是一颗像素的中心位置。
                auto[alpha, beta, gamma] = computeBarycentric2D(i+0.5, j+0.5, t.v);

                // v is vec4 array
                // reciprocal 倒数
                float w_reciprocal = 1.0/(alpha / v[0].w() + beta / v[1].w() + gamma / v[2].w());
                float z_interpolated = alpha * v[0].z() / v[0].w() + beta * v[1].z() / v[1].w() + gamma * v[2].z() / v[2].w();
                z_interpolated *= w_reciprocal;

                // 暂时不明这里 w_reciprocal 的作用 （w_reciprocal 一般是1 or 一个接近于1 的值）
                if(insideTriangle(i+0.5,j+0.5,t.v))
                {
                    point.x()= i;
                    point.y()= j;
                    if(z_interpolated < depth_buf[get_index(i,j)])
                    {
                        set_pixel(point,t.getColor());
                        depth_buf[get_index(i,j)] = z_interpolated;
                    }
                }
            }
        }
    }
    else
    {
        auto v = t.toVector4();
        // TODO : Find out the bounding box of current triangle.
        // iterate through the pixel and find if the current pixel is inside the triangle
        int xmin = 0;
        int xmax = 0;
        int ymin = 0;
        int ymax = 0;
        float xminf = v[0].x();
        float xmaxf = v[0].x();
        float yminf= v[0].y();
        float ymaxf = v[0].y();

        for(int i =0;i<3;i++)
        {
            if(v[i].x()<xminf) xminf = v[i].x();
            if(v[i].x()>xmaxf) xmaxf = v[i].x();
            if(v[i].y()<yminf) yminf = v[i].y();
            if(v[i].y()>ymaxf) ymaxf = v[i].y();
        }
        xmin = xminf;
        xmax = xmaxf +1;
        ymin = yminf;
        ymax = ymaxf +1;

        //std::cout<<v[0].z()<<std::endl;
        // If so, use the following code to get the interpolated z value.

        Eigen::Vector3f point;
        //SuperSampling data for each pixel
        float PixelDepth[4] = {0};
        int PixelCount[4] = {0};
        int colorCoef = 0;
        for(int i = xmin-1;i<=xmax;i++)
        {
            for(int j = ymin-1;j<=ymax;j++)
            {
                PixelCount[0] = 0;
                PixelCount[1] = 0;
                PixelCount[2] = 0;
                PixelCount[3] = 0;

                PixelDepth[0] = 0;
                PixelDepth[1] = 0;
                PixelDepth[2] = 0;
                PixelDepth[3] = 0;
                colorCoef = 0;
                bool Inside = false;
                if(insideTriangle(i+0.25,j+0.25,t.v))
                {
                    PixelCount[0]= 1;
                    Inside = true;
                }
                if(insideTriangle(i+0.25,j+0.75,t.v))
                {
                    PixelCount[1]= 1;
                    Inside = true;
                }
                if(insideTriangle(i+0.75,j+0.25,t.v))
                {
                    PixelCount[2]= 1;
                    Inside = true;
                }
                if(insideTriangle(i+0.75,j+0.75,t.v))
                {
                    PixelCount[3]= 1;
                    Inside = true;
                }

                if(Inside)
                {
                    auto[alpha0, beta0, gamma0] = computeBarycentric2D(i+0.5, j+0.5, t.v);
                    float w_reciprocal = 1.0/(alpha0 / v[0].w() + beta0 / v[1].w() + gamma0 / v[2].w());
                    float z_interpolated_a = alpha0 * v[0].z() / v[0].w() + beta0 * v[1].z() / v[1].w() + gamma0 * v[2].z() / v[2].w();
                    z_interpolated_a *= w_reciprocal;

                    for(int m = 0;m<4;m++)
                    {
                        float z_interpolated;
                        if(m == 0)
                        {
                            auto[alpha1, beta1, gamma1] = computeBarycentric2D(i+0.25, j+0.25, t.v);
                            w_reciprocal = 1.0/(alpha1 / v[0].w() + beta1 / v[1].w() + gamma1 / v[2].w());
                        z_interpolated = alpha1 * v[0].z() / v[0].w() + beta1 * v[1].z() / v[1].w() + gamma1 * v[2].z() / v[2].w();
                        }
                        else if (m==1)
                        {
                            auto[alpha2, beta2, gamma2] = computeBarycentric2D(i+0.25, j+0.75, t.v);
                            w_reciprocal = 1.0/(alpha2 / v[0].w() + beta2 / v[1].w() + gamma2 / v[2].w());
                        z_interpolated = alpha2 * v[0].z() / v[0].w() + beta2 * v[1].z() / v[1].w() + gamma2 * v[2].z() / v[2].w();
                        }
                        else if (m==2)
                        {
                            auto[alpha3, beta3, gamma3] = computeBarycentric2D(i+0.75, j+0.25, t.v);
                            w_reciprocal = 1.0/(alpha3 / v[0].w() + beta3 / v[1].w() + gamma3 / v[2].w());
                        z_interpolated = alpha3 * v[0].z() / v[0].w() + beta3 * v[1].z() / v[1].w() + gamma3 * v[2].z() / v[2].w();
                        }
                        else
                        {
                            auto[alpha4, beta4, gamma4] = computeBarycentric2D(i+0.75, j+0.75, t.v);
                            w_reciprocal = 1.0/(alpha4 / v[0].w() + beta4 / v[1].w() + gamma4 / v[2].w());
                        z_interpolated = alpha4 * v[0].z() / v[0].w() + beta4 * v[1].z() / v[1].w() + gamma4 * v[2].z() / v[2].w();
                        }
                        PixelDepth[m] = z_interpolated*w_reciprocal;
                    }
                    int minDepth = PixelDepth[0];
                    for(int k = 0;k<4;k++)
                    {
                        //if( PixelCount[k]==1)
                        if(PixelDepth[k]<depth_buf[get_index(i,j)] && PixelCount[k]==1)
                        colorCoef = colorCoef + PixelCount[k];
                        if(PixelDepth[k]< minDepth) minDepth = PixelDepth[k];
                    }
                    point.x()= i;
                    point.y()= j;
                    // depth_buf  length: 700 * 700
                    if(minDepth < depth_buf[get_index(i,j)])
                    {
                        Eigen::Vector3f c = (t.getColor()*colorCoef)/4 + (4-colorCoef)*frame_buf[(height-1-j)*width + i]/4;
                        set_pixel(point, c);
                        if (c.x() != 217 && c.x() != 185 && c.x() != 162.75 && c.x() != 92.5 && c.x() != 138.75) {
                            
                            Eigen::Vector3f cc = Eigen::Vector3f(222,222,222);
                            std::cout << "color222:::" << point << std::endl;
                            set_pixel(point, cc);
                        }
                        depth_buf[get_index(i,j)] = minDepth;
                    }
                }
            }
        }
    }

    // TODO : set the current pixel (use the set_pixel function) to the color of the triangle (use getColor function) if it should be painted.
}

void rst::rasterizer::set_model(const Eigen::Matrix4f& m)
{
    model = m;
}

void rst::rasterizer::set_view(const Eigen::Matrix4f& v)
{
    view = v;
}

void rst::rasterizer::set_projection(const Eigen::Matrix4f& p)
{
    projection = p;
}

void rst::rasterizer::clear(rst::Buffers buff)
{
    if ((buff & rst::Buffers::Color) == rst::Buffers::Color)
    {
        std::fill(frame_buf.begin(), frame_buf.end(), Eigen::Vector3f{0, 0, 0});
    }
    if ((buff & rst::Buffers::Depth) == rst::Buffers::Depth)
    {
        std::fill(depth_buf.begin(), depth_buf.end(), std::numeric_limits<float>::infinity());
    }
}

rst::rasterizer::rasterizer(int w, int h) : width(w), height(h)
{
    frame_buf.resize(w * h);
    depth_buf.resize(w * h);
}

int rst::rasterizer::get_index(int x, int y)
{
    return (height-1-y)*width + x;
}

void rst::rasterizer::set_pixel(const Eigen::Vector3f& point, const Eigen::Vector3f& color)
{
    //old index: auto ind = point.y() + point.x() * width;
    auto ind = (height-1-point.y())*width + point.x();
    frame_buf[ind] = color;

}

// clang-format on
