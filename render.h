#ifndef RENDER_H
#define RENDER_H

#include "defs.h"
#include "display.h"

#define MAX_MAP_WIDTH 40
#define MAX_MAP_HEIGHT 40

class Render
{
    public:
        Render(Display& display);
        virtual ~Render();

        e_std::e_bool init();
        void update();
    private:
        Display& m_display;

        void drawCeil(const e_std::color_t& color);
        void drawFloor(const e_std::color_t& color);
        void drawWalls();

        #ifdef DEBUG
            int m_map[MAX_MAP_WIDTH][MAX_MAP_HEIGHT];

            void fillMap();
        #endif
};

#endif