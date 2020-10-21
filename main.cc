#include "color.h"
#include "vec3.h"
#include <iostream>

int main() {

    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // rows go fromstart from the top of the image to the bottom
    for (int j = image_height-1; j >= 0; --j) {
        //std::flush flushes the output sequences os, basically make the output
        //appear in real time
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        // image filled in from left to right 
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(double(i)/(image_width-1), double(j)/(image_height-1), 0.25);
            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone.";
}
