#include <iostream>
#include "color.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    int image_height = 256;
    int image_width = 256;

    // render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;
            color c(r, g, b);
            write_color(std::cout, c);
        }
    }
    std::clog << "\rDone.                        \n" << std::flush;

    return 0;
}