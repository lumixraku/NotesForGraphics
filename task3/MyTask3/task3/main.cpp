#include <iostream>
#include <opencv2/opencv.hpp>

#include "global.hpp"
#include "rasterizer.hpp"
#include "Triangle.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "OBJ_Loader.h"

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1,0,0,-eye_pos[0],
                 0,1,0,-eye_pos[1],
                 0,0,1,-eye_pos[2],
                 0,0,0,1;

    view = translate*view;
    //  array = {
    //   [0] = 1
    //   [1] = 0
    //   [2] = 0
    //   [3] = 0
    //   [4] = 0
    //   [5] = 1
    //   [6] = 0
    //   [7] = 0
    //   [8] = 0
    //   [9] = 0
    //   [10] = 1
    //   [11] = 0
    //   [12] = 0
    //   [13] = 0
    //   [14] = -10
    //   [15] = 1

    return view;
}

Eigen::Matrix4f get_model_matrix(float angle,float scalecoef)
{
    Eigen::Matrix4f rotation;
    angle = angle * MY_PI / 180.f;
    rotation << cos(angle), 0, sin(angle), 0,
                0, 1, 0, 0,
                -sin(angle), 0, cos(angle), 0,
                0, 0, 0, 1;

    Eigen::Matrix4f scale;
    scale << scalecoef, 0, 0, 0,
              0, scalecoef, 0, 0,
              0, 0, scalecoef, 0,
              0, 0, 0, 1;

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;

    return translate * rotation * scale;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio, float zNear, float zFar)
{
    // TODO: Use the same projection matrix from the previous assignments
// TODO: Copy-paste your implementation from the previous assignment.
    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();
    // TODO: Implement this function/;""
    // Create the projection matrix for the given parameters.
    // Then return it.
    float eye_angle = eye_fov *MY_PI / 180;
    float t,b,l,r;

    // 原本是 -zNear * tan(eye_angle /2);
    t = abs(zNear) * tan(eye_angle /2);//------
    r = t * aspect_ratio;
    l = -r;
    b = -t;
    //Eigen::Matrix4f PersToOrth = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f m1;
    Eigen::Matrix4f m2;
    Eigen::Matrix4f m3;

    // 透视投影矩阵
    m1<< zNear,0,0,0,
        0,zNear,0,0,
        0,0,zNear + zFar,-zNear*zFar,
        0,0,1,0;

    // 位移矩阵
    m2<<1,0,0,0,
        0,1,0,0,
        0,0,1,-(zNear+ zFar)/2,
        0,0,0,1;

    // 缩放矩阵
    m3<<2/(r-l),0,0,0,
        0,2/(t-b),0,0,
        0,0,2/(zNear -zFar),0,
        0,0,0,1;
    projection = m3 * m2 * m1 * projection;
    return projection;

}

Eigen::Vector3f vertex_shader(const vertex_shader_payload& payload)
{
    return payload.position;
}

// 这里就相当于图形学中过得 fragment_shader 程序  有多少像素点就调用多少次
// payload 包含 color normal texture viewpos texture_coord
Eigen::Vector3f normal_fragment_shader(const fragment_shader_payload& payload)
{
    Eigen::Vector3f return_color = (payload.normal.head<3>().normalized() + Eigen::Vector3f(1.0f, 1.0f, 1.0f)) / 2.f;
    Eigen::Vector3f result;
    result << return_color.x() * 255, return_color.y() * 255, return_color.z() * 255;
    return result;
}

static Eigen::Vector3f reflect(const Eigen::Vector3f& vec, const Eigen::Vector3f& axis)
{
    auto costheta = vec.dot(axis);
    return (2 * costheta * axis - vec).normalized();
}
float mymax(float a,float b)
{
    if(a>b)return a;
    else return b;
}

struct light
{
    Eigen::Vector3f position;
    Eigen::Vector3f intensity;
};

Eigen::Vector3f texture_fragment_shader(const fragment_shader_payload& payload)
{
    Eigen::Vector3f return_color = {0, 0, 0};
    if (payload.texture)
    {
        // TODO: Get the texture value at the texture coordinates of the current fragment
        return_color = payload.texture->getColor(payload.tex_coords.x(),payload.tex_coords.y());
    }
    Eigen::Vector3f texture_color;
    texture_color << return_color.x(), return_color.y(), return_color.z();

    Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = texture_color / 255.f;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);

    auto l1 = light{{20, 20, -20}, {500, 500, 500}};
    auto l2 = light{{20, 20, 0}, {500, 500, 500}};

    std::vector<light> lights = {l1, l2};
    Eigen::Vector3f amb_light_intensity{100, 100, 100};
    Eigen::Vector3f eye_pos{0, 0, 0};

    float p = 150;

    Eigen::Vector3f color = texture_color;
    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal;

    Eigen::Vector3f result_color = {0, 0, 0};
    Eigen::Vector3f ambient = ka * amb_light_intensity[0];

    for (auto& light : lights)
    {
        // TODO: For each light source in the code, calculate what the *ambient*, *diffuse*, and *specular*
        // components are. Then, accumulate that result on the *result_color* object.
        float r2 = (light.position - point).dot((light.position - point));
        Eigen::Vector3f l = (light.position - point).normalized();
        Eigen::Vector3f n = normal.normalized();
        Eigen::Vector3f v = (eye_pos - point).normalized();
        Eigen::Vector3f h = (l+v).normalized();

        // Lambertian (Diffuse) Shading  Kd是漫反射扩散系数（物体本身的颜色）
        Eigen::Vector3f diffuse =  (kd * light.intensity[0]/r2) * std::max(0.0f,n.dot(l));
        // Specular Shading  n 法向量 h 半程向量  p 是柔和衰减系数  h是观察方向和入射光方向的中间向量
        Eigen::Vector3f specular = (ks * light.intensity[0]/r2) * std::pow(std::max(0.f,(n.dot(h))),p);

        result_color+=(diffuse+specular);

    }

    result_color+=ambient;
    return result_color * 255.f;
}

Eigen::Vector3f phong_fragment_shader(const fragment_shader_payload& payload)
{
    Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = payload.color;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);
    
    
    
    auto l1 = light{{20, 20, -20}, {500, 500, 500}};
    auto l2 = light{{-20, 20, 0}, {500, 500, 500}};

    std::vector<light> lights = {l1, l2};
    Eigen::Vector3f amb_light_intensity{30, 30, 30};
    Eigen::Vector3f eye_pos{0, 0, -10};

    float p = 150;

    Eigen::Vector3f color = payload.color;
    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal;

    Eigen::Vector3f result_color = {0, 0, 0};
    for (auto& light : lights)
    {
        // TODO: For each light source in the code, calculate what the *ambient*, *diffuse*, and *specular*
        // components are. Then, accumulate that result on the *result_color* object.
        float r2 = (light.position - point).dot((light.position - point));
        Eigen::Vector3f l = (light.position - point).normalized();
        Eigen::Vector3f n = normal.normalized();
        Eigen::Vector3f v = (eye_pos - point).normalized();
        Eigen::Vector3f h = (l+v).normalized();
        Eigen::Vector3f ambient = ka * amb_light_intensity[0];
        Eigen::Vector3f diffuse =  (kd * light.intensity[0]/r2) * std::max(0.0f,n.dot(l));
        Eigen::Vector3f specular = (ks * light.intensity[0]/r2) * std::pow(std::max(0.f,(n.dot(h))),p);

        result_color+=(ambient+diffuse+specular);

    }
    return result_color * 255.f;
}



Eigen::Vector3f displacement_fragment_shader(const fragment_shader_payload& payload)
{

Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = payload.color;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);

    auto l1 = light{{20, 20, 20}, {500, 500, 500}};
    auto l2 = light{{-20, 20, 0}, {500, 500, 500}};

    std::vector<light> lights = {l1, l2};
    Eigen::Vector3f amb_light_intensity{10, 10, 10};
    Eigen::Vector3f eye_pos{0, 0, 10};

    float p = 150;

    Eigen::Vector3f color = payload.color;
    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal;

    float kh = 0.2, kn = 0.1;

    // TODO: Implement displacement mapping here
    // Let n = normal = (x, y, z)
    // Vector t = (x*y/sqrt(x*x+z*z),sqrt(x*x+z*z),z*y/sqrt(x*x+z*z))
    // Vector b = n cross product t
    // Matrix TBN = [t b n]
    // dU = kh * kn * (h(u+1/w,v)-h(u,v))
    // dV = kh * kn * (h(u,v+1/h)-h(u,v))
    // Vector ln = (-dU, -dV, 1)
    // Position p = p + kn * n * h(u,v)
    // Normal n = normalize(TBN * ln)

    Eigen::Vector3f n = normal;
    float x = n[0];
    float y = n[1];
    float z = n[2];
    Eigen::Vector3f t = Eigen::Vector3f(x*y/sqrt(x*x+z*z),sqrt(x*x+z*z),z*y/sqrt(x*x+z*z)) ;
    Eigen::Vector3f b = n.cross(t);
    Eigen::Matrix3f tbn;
    tbn<<t,b,n;
    float u = payload.tex_coords.x();
    float v = payload.tex_coords.y();
    float w = payload.texture->width;
    float h = payload.texture->height;
    //std::cout<<u<<"---"<<v<<'\n';
    float dU,dV;

    // 当位移采样在纹理内
    if((u+1.0/w)<=1 && (v+1/h)<=1)
    {
         dU = kh * kn * (payload.texture->getColor(u+1.0/w,v).norm()-payload.texture->getColor(u,v).norm());
         dV = kh * kn * (payload.texture->getColor(u,v+1/h).norm()-payload.texture->getColor(u,v).norm());
    }

    // 当位移采样超过纹理的时候
    else if ((u+1.0/w)>1)
    {
         dU = kh * kn * (payload.texture->getColor(1,v).norm()-payload.texture->getColor(u,v).norm());
         dV = kh * kn * (payload.texture->getColor(u,v+1/h).norm()-payload.texture->getColor(u,v).norm());
    }
    else
    {
         dU = kh * kn * (payload.texture->getColor(u+1.0/w,v).norm()-payload.texture->getColor(u,v).norm());
         dV = kh * kn * (payload.texture->getColor(u,1).norm()-payload.texture->getColor(u,v).norm());
    }

    Eigen::Vector3f ln(-dU, -dV, 1); // -dU -dV 是切线的方向 所以加个负号 法线和切线垂直
    // Position p = p + kh * n * h(u,v)
    // Normal n = TBN * ln
    if(u<=1 && v<=1)
    {
    point = point + kn * n * (payload.texture->getColor(u,v)).norm();
    }
    else if(u>1)
    {
        point = point + kn * n * (payload.texture->getColor(1,v)).norm();
    }
    else
    {
        point = point + kn * n * (payload.texture->getColor(u,1)).norm();
    }


    normal = tbn * ln;
    normal = normal.normalized();
    Eigen::Vector3f result_color = {0, 0, 0};

    for (auto& light : lights)
    {
        // TODO: For each light source in the code, calculate what the *ambient*, *diffuse*, and *specular*
        // components are. Then, accumulate that result on the *result_color* object.
        float r2 = (light.position - point).dot((light.position - point));
        Eigen::Vector3f l = (light.position - point).normalized();
        Eigen::Vector3f n = normal;
        Eigen::Vector3f v = (eye_pos - point).normalized();
        Eigen::Vector3f h = (l+v).normalized();
        Eigen::Vector3f ambient = ka * amb_light_intensity[0];
        Eigen::Vector3f diffuse =  kd * light.intensity.z()/r2 * mymax(n.dot(l),0.0);
        Eigen::Vector3f specular = ks * light.intensity.z()/r2 * std::pow(mymax(0.0,(n.dot(h))),p);
        result_color += (ambient+ diffuse+specular);
    }
    
    return result_color * 255.f;
}

// bump fragment 略微移动法线 
// bump 的时候 texture 是 hmap.jpg
Eigen::Vector3f bump_fragment_shader(const fragment_shader_payload& payload)
{

    Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = payload.color;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);

    auto l1 = light{{20, 20, 20}, {500, 500, 500}};
    auto l2 = light{{-20, 20, 0}, {500, 500, 500}};

    std::vector<light> lights = {l1, l2};
    Eigen::Vector3f amb_light_intensity{10, 10, 10};
    Eigen::Vector3f eye_pos{0, 0, 10};

    float p = 150;

    Eigen::Vector3f color = payload.color;
    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal;


    float kh = 0.2f, kn = 0.1f;

    // TODO: Implement bump mapping here
    // Let n = normal = (x, y, z)
    // Vector t = (x*y/sqrt(x*x+z*z),sqrt(x*x+z*z),z*y/sqrt(x*x+z*z))
    // Vector b = n cross product t
    // Matrix TBN = [t b n]
    // dU = kh * kn * (h(u+1/w,v)-h(u,v))
    // dV = kh * kn * (h(u,v+1/h)-h(u,v))
    // Vector ln = (-dU, -dV, 1)
    // Normal nd = TBN * ln

    Eigen::Vector3f n = normal;
    float x = normal.x();
    float y = normal.y();
    float z = normal.z();
    // Eigen::Vector3f t = {x*y/sqrt(x*x+z*z),sqrt(x*x+z*z),z*y/sqrt(x*x+z*z)};

    // 这里的 TBN 是在当前这个点这里构造一个坐标系（标准正交基）(其中N是法线 T是切线 B是副切线·)
    // 我不理解 task 中给出的方法，但是有另外一种从一个向量出发，构造出一组标准正交基的方法
    // https://www.qiujiawei.com/pbrt-chapter2/
    Eigen::Vector3f t;
    if (x > y) 
    {
        t = Eigen::Vector3f(-z, 0, x) / std::sqrt(x * x + z * z);
    }
    else
    {
        t = Eigen::Vector3f(0, -z, y) / std::sqrt(y * y + z * z);
    }


    Eigen::Vector3f b = normal.cross(t);
    Eigen::Matrix3f tbn;
    tbn<<t,b,n;
    float u = payload.tex_coords.x();
    float v = payload.tex_coords.y();
    float w = payload.texture->width; // 800
    float h = payload.texture->height; // 800
    //std::cout<<u<<"---"<<v<<'\n';
    float dU,dV;
    
    // uv的范围是 [0,1]
    // uv坐标+1像素 仍在贴图中 (1像素要转为uv坐标中的尺度 )
    if((u+1.0/w)<=1 && (v+1/h)<=1)
    {
         dU = kh * kn * (payload.texture->getColor(u+1.0/w,v).norm()-payload.texture->getColor(u,v).norm());
         dV = kh * kn * (payload.texture->getColor(u,v+1/h).norm()-payload.texture->getColor(u,v).norm());
    }
    else if ((u+1.0/w)>1)  // u+1像素超出贴图了
    {
         dU = kh * kn * (payload.texture->getColor(1,v).norm()-payload.texture->getColor(u,v).norm());
         dV = kh * kn * (payload.texture->getColor(u,v+1/h).norm()-payload.texture->getColor(u,v).norm());
    }
    else
    {
         dU = kh * kn * (payload.texture->getColor(u+1.0/w,v).norm()-payload.texture->getColor(u,v).norm());
         dV = kh * kn * (payload.texture->getColor(u,1).norm()-payload.texture->getColor(u,v).norm());
    }

    Eigen::Vector3f ln(-dU,-dV,1);
    normal = tbn * ln;
    Eigen::Vector3f result_color = {0, 0, 0};
    result_color = normal.normalized();

    return result_color * 255.f;
}

int main(int argc, const char** argv)
{
    std::vector<Triangle*> TriangleList;

    float angle = 90.0;
    bool command_line = false;

    std::string filename = "output.png";
    objl::Loader Loader;
    std::string obj_path = "./models/spot/";

    // Load .obj File
    bool loadout = Loader.LoadFile("./models/spot/spot_triangulated_good.obj");

    //bunny
//    bool loadout = Loader.LoadFile("./models/bunny/bunny.obj");

    //cube
    //obj_path = "../models/cube/";
    //if(Loader.LoadFile("../models/cube/cube.obj"))
    //std::cout<<"hello"<<'\n';

    //rock
    //std::string obj_path = "../models/rock/";
    //if(Loader.LoadFile("../models/rock/rock.obj"))
    //std::cout<<"hello"<<'\n';

    //rock

    //


    for(auto mesh:Loader.LoadedMeshes)
    {
        for(int i=0;i<mesh.Vertices.size();i+=3)
        {
            Triangle* t = new Triangle();
            for(int j=0;j<3;j++)
            {
                t->setVertex(j,Vector4f(mesh.Vertices[i+j].Position.X,mesh.Vertices[i+j].Position.Y,mesh.Vertices[i+j].Position.Z,1.0));
                t->setNormal(j,Vector3f(mesh.Vertices[i+j].Normal.X,mesh.Vertices[i+j].Normal.Y,mesh.Vertices[i+j].Normal.Z));
                t->setTexCoord(j,Vector2f(mesh.Vertices[i+j].TextureCoordinate.X, mesh.Vertices[i+j].TextureCoordinate.Y));
            }
            TriangleList.push_back(t);
        }
    }

    rst::rasterizer r(700, 700);

    auto texture_path = "hmap.jpg";
    r.set_texture(Texture(obj_path + texture_path));

    std::function<Eigen::Vector3f(fragment_shader_payload)> active_shader = phong_fragment_shader;

    if (argc >= 2)
    {
        command_line = true;
        filename = std::string(argv[1]);

        if (argc == 3 && std::string(argv[2]) == "texture")
        {
            std::cout << "Rasterizing using the texture shader\n";
            active_shader = texture_fragment_shader;
            texture_path = "spot_texture.png";
            r.set_texture(Texture(obj_path + texture_path));

            //cube
            //auto texture_path = "wall1.tif";
            //r.set_texture(Texture(obj_path + texture_path));

            //rock
            //auto texture_path = "rock.png";
            //r.set_texture(Texture(obj_path + texture_path));


        }
        else if (argc == 3 && std::string(argv[2]) == "normal")
        {
            std::cout << "Rasterizing using the normal shader\n";
            active_shader = normal_fragment_shader;
        }
        else if (argc == 3 && std::string(argv[2]) == "phong")
        {
            std::cout << "Rasterizing using the phong shader\n";
            active_shader = phong_fragment_shader;
        }
        else if (argc == 3 && std::string(argv[2]) == "bump")
        {
            std::cout << "Rasterizing using the bump shader\n";
            active_shader = bump_fragment_shader;
        }
        else if (argc == 3 && std::string(argv[2]) == "displacement")
        {
            std::cout << "Rasterizing using the displacement shader\n";
            active_shader = displacement_fragment_shader;
        }
    }

    Eigen::Vector3f eye_pos = {0,0,10};

    r.set_vertex_shader(vertex_shader);
    r.set_fragment_shader(active_shader);

    int key = 0;
    int frame_count = 0;

//    if (command_line)
//    {
//        r.clear(rst::Buffers::Color | rst::Buffers::Depth);
//        r.set_model(get_model_matrix(angle,2.5));
//        r.set_view(get_view_matrix(eye_pos));
//
//        // 原本是 get_projection_matrix(45.0, 1, 0.1, 50)
//        // 但是我不太理解，因为说过相机看往 -Z 方向
//        // 所以我改成了 get_projection_matrix(45.0, 1, -0.1, -50)
//        // 相应的get_projection_matrix 关于 t 的值也改为 t = abs(zNear) * tan(eye_angle /2);
//        r.set_projection(get_projection_matrix(45.0, 1, -0.1, -50));
//
//        r.draw(TriangleList);
//        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
//        image.convertTo(image, CV_8UC3, 1.0f);
//        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
//
//        cv::imwrite(filename, image);
////        return 0;
//    }

    while(key != 27)
    {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle,2.5));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45.0, 1, -0.1, -50));

        //r.draw(pos_id, ind_id, col_id, rst::Primitive::Triangle);
        r.draw(TriangleList);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);

        cv::imshow("image", image);
        cv::imwrite(filename, image);
        key = cv::waitKey(10);
        
        angle += 30;
        std::cout << "angle" << angle << std::endl;
//        if (key == 'a' )
//        {
//            angle -= 0.1;
//        }
//        else if (key == 'd')
//        {
//            angle += 0.1;
//        }

    }
    return 0;
}
