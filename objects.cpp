#include "objects.h"

using namespace e_std;

Object::Object(const char* name)
{
    m_name = name;
    m_pos = new e_math::vec3f();
}

Object::Object(const char* name, float x, float y)
{
    m_name = name;
    m_pos = new e_math::vec3f(x, y, 0);
}

Object::~Object()
{
    delete m_pos;
}

e_bool Object::init(e_math::vec3f* new_pos)
{
    e_bool success = TRUE;

    m_pos = new_pos;

    return success;
}

Entity::Entity(const char* name)
    : Object(name)
{
    m_dir = new e_math::vec3f(1, 1, 0);
}

Entity::Entity(const char* name, float x, float y)
    : Object(name, x, y)
{
    m_dir = new e_math::vec3f(1, 1, 0);
}

Entity::~Entity()
{
    delete m_dir;
}