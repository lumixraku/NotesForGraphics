#include <iostream>
#include <vector>

#include "CGL/vector2D.h"

#include "mass.h"
#include "rope.h"
#include "spring.h"

namespace CGL {

    Rope::Rope(Vector2D start, Vector2D end, int num_nodes, float node_mass, float k, vector<int> pinned_nodes)
    {
        // TODO (Part 1): Create a rope starting at `start`, ending at `end`, and containing `num_nodes` nodes.
        if(num_nodes == 0 || num_nodes == 1)
            return;
        Vector2D CurrentPosition = start;
        //treat rope as a list
        Mass * p = new Mass(start,node_mass,false);
        masses.push_back(p);
        Mass * l = nullptr;
        Spring * presentSpring = nullptr;
        for(int i = 1;i <= num_nodes - 1;i++)
        {
            std::cout << i;
            if(i == (num_nodes -1))
            {
                CurrentPosition = end;
            }
            else
            {
                CurrentPosition = start + i * (end-start) / (num_nodes - 1);
            }
            l = p;
            p = new Mass(CurrentPosition,node_mass,false);
            presentSpring = new Spring(l,p,k);

            // 在尾部加入数据
            masses.push_back(p);
            springs.push_back(presentSpring);
        }
//        Comment-in this part when you implement the constructor
        for (auto &i : pinned_nodes) {
            masses[i]->pinned = true;
        }
    }

    void Rope::simulateEuler(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // TODO (Part 2): Use Hooke's law to calculate the force on a node
            Vector2D ab = s->m2->position - s->m1->position;

            // 向量a/向量模长 得到的是单位向量
            // 向量的模长 就是向量的长度 仅有大小 没有方向
            // k 是弹性系数
            Vector2D f =  s->k *  (ab / ab.norm()) * (ab.norm() - s->rest_length);
            s->m1->forces += f;
            s->m2->forces -= f;
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                // TODO (Part 2): Add the force due to gravity, then compute the new velocity and position
                m->forces += gravity * m->mass;
                

                // TODO (Part 2): Add global damping
                // 如果没有这个阻尼 弹簧将永远震动 //因为弹簧动能和势能就在不断的转换
                // 单纯加上摩擦力并不行 因为无法描述弹簧内的力  比如当 ab 两个点相对静止的时候 此刻damping应该不存在
                if(true)
                {
                    float k_d_global = 0.01;
                    m->forces += - k_d_global * m->velocity;
                }

                Vector2D a = m->forces / m->mass;
                if(false)
                {
                    //Explicit method
                    m->position += m->velocity * delta_t;
                    m->velocity += a * delta_t;
                }
                else
                {
                    //semi-implicit method
                    m->velocity += a * delta_t;
                    m->position += m->velocity * delta_t;
                }   
            }
            // Reset all forces on each mass
            m->forces = Vector2D(0, 0);
        }
    }

    void Rope::simulateVerlet(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // TODO (Part 3): Simulate one timestep of the rope using explicit Verlet （solving constraints)
            Vector2D ab = s->m2->position - s->m1->position;
            Vector2D f = s->k *  (ab / ab.norm()) * (ab.norm() - s->rest_length);
            s->m1->forces += f;
            s->m2->forces -= f;
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                m->forces += gravity * m->mass;
                Vector2D a = m->forces / m->mass;

                // TODO (Part 3.1): Set the new position of the rope mass
                Vector2D lastposition = m->position;
                // TODO (Part 4): Add global Verlet damping
                float dampfactor = 0.00005;
                m->position = m->position +  (1 - dampfactor) * (m->position - m->last_position) + a * delta_t *delta_t;
                m->last_position = lastposition;
            }
            m->forces =  Vector2D(0,0);
        }
    }
}
