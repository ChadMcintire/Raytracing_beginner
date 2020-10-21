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
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            //static cast is a compile time cast, in this case from float to int
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::cerr << "\nDone.";
}
