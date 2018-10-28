#include "render.h"

Render::Render(Display& display)
    : m_display(display)
{
    #ifdef DEBUG
        fillMap();
    #endif
}

Render::~Render()
{

}

e_std::e_bool Render::init()
{
    e_std::e_bool success = TRUE;

    return success;
}

void Render::update()
{
    drawCeil(DARK_BLUE);
    drawFloor(GRAY);
    drawWalls();
}

void Render::drawCeil(const e_std::color_t& color)
{
    m_display.fillRect(0, 0, m_display.getWidth(), m_display.getHeight()/2, &color);
}

void Render::drawFloor(const e_std::color_t& color)
{
    m_display.fillRect(0, m_display.getHeight()/2, m_display.getWidth(), m_display.getHeight()/2, &color);
}

void Render::drawWalls()
{

}

#ifdef DEBUG
void Render::fillMap()
{
    for(int y = 0; y < MAX_MAP_HEIGHT; y++)
    {
        for(int x = 0; x < MAX_MAP_WIDTH; x++)
        {
            if(x == 0) m_map[y][x] = 1; 
            if(y == 0) m_map[y][x] = 1; 
            if(x == MAX_MAP_WIDTH - 1) m_map[y][x] = 1; 
            if(y == MAX_MAP_HEIGHT - 1) m_map[y][x] = 1; 
        }
    }
}
#endif

