#include "tgaimage.h"
constexpr TGAColor white = {255, 255, 255, 255}; // BGRA order!!!
constexpr TGAColor green = {0, 255, 0, 255};
constexpr TGAColor red = {0, 0, 255, 255};
constexpr TGAColor blue = {255, 128, 64, 255};
constexpr TGAColor yellow = {0, 200, 255, 255};


// approach 1
// simple parametric line using barycentric coordinates
void line_1(int ax, int ay, int bx, int by, TGAImage &framebuffer, TGAColor color){
    for(float t=0; t< 1; t+=0.2){
        int x = std::round(ax + (bx-ax)*t);
        int y = std::round(ay + (by-ay)*t);
        framebuffer.set(x,y,color);
    }
}

// approach 2
// tweak to how increments are done!
void line_2(int ax, int ay, int bx, int by, TGAImage &framebuffer, TGAColor color){
    if(ax > bx){
        std::swap(ax,bx);
        std::swap(ay,by);
    }
    for(float x=ax; x<= bx; x++){
        float t = (x-ax) / static_cast<float>(bx-ax);
        int y = std::round(ay + (by-ay)*t);
        framebuffer.set(x,y,color);
    }
}

// approach 3
void line(int ax, int ay, int bx, int by, TGAImage &framebuffer, TGAColor color){
    bool steep = std::abs(ax-bx) < std::abs(ay-by);
    
    if( steep){ // when line is steep, we transpose it 
        std::swap(ax,ay);
        std::swap(bx,by);
    }

    if(ax > bx){ // Making it left to right mapped
        std::swap(ax,bx);
        std::swap(ay,by);
    }

    float y = ay;
    int ierror = 0;
    for(int x=ax; x<= bx; x++){
        float t = (x-ax) / static_cast<float>(bx-ax);
        int y = std::round(ay + (by-ay)*t);
        if(steep) // if transposed, revert it back
            framebuffer.set(y,x,color);
        else
            framebuffer.set(x,y,color);
        ierror += 2 * std::abs(by-ay);
        y += (by > ay ? 1 : -1) * (ierror > bx - ax);
        ierror -= 2 * (bx-ax)   * (ierror > bx - ax);
    }
}


int main(int argc, char** argv){
    constexpr int width = 720;
    constexpr int height = 720;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    // if(argc <2){
    //     int ax = 7*11.25, ay = 3*11.25;
    //     int bx = 12*11.25, by = 37*11.25;
    //     int cx = 62*11.25, cy = 53*11.25;

    //     line(ax, ay, bx, by, framebuffer, blue);
    //     line(bx, by, cx, cy, framebuffer, green);
    //     line(cx, cy, ax, ay, framebuffer, yellow);
    //     line(ax, ay, cx, cy, framebuffer, red);

    //     framebuffer.set(ax,ay,white);
    //     framebuffer.set(bx,by,white);
    //     framebuffer.set(cx,cy,white);
    // }else{
        // std::srand(std::time({}));
        // for (int i=0; i<(1<<24); i++) {
        //     int ax = rand()%width, ay = rand()%height;
        //     int bx = rand()%width, by = rand()%height;
        //     line(ax, ay, bx, by, framebuffer, { rand()%255, rand()%255, rand()%255, rand()%255 });
        // }
        objParser obj("/home/tintu/dev/gfx_garden/trw/diablo3_pose.obj");
        obj.processObj();
    // }

    

    framebuffer.write_tga_file("framebuffer.tga");
    return 0;
}