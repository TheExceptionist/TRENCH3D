#ifndef OBJECTS_H
#define OBJECTS_H

#include "defs.h"

using namespace e_std;

class Object
{
    public:
        Object(const char* name);
        Object(const char* name, float x, float y);
        virtual ~Object();

        e_bool init(e_math::vec3f*);
        e_math::vec3f* getPos() const { return m_pos;}
    protected:
        const char* m_name;
        e_math::vec3f* m_pos;

};

class Entity : public Object
{
    public:
        Entity(const char* name);
        Entity(const char* name, float x, float y);
        virtual ~Entity();

        e_math::vec3f* getDir() const { return m_dir;}

        void move(const int forward, const int rotation);// { (*m_pos)[0] += x; (*m_pos)[1] += y;}
    protected:
        e_math::vec3f* m_dir;
        //e_math::vec3f* m_vel;
};

#endif