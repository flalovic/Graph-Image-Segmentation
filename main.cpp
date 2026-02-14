#include "segmentation.h"
#include <iostream>
using namespace std;

int main() {

    srand(time(nullptr));

    const string inputPath = "images/image.png";
    Image img(inputPath);

    if (img.w == 0 || img.h == 0) {
        cerr << "Can not open image: " << inputPath << endl;
        return 1;
    }

    Segmentation seg(img);

    cout << "Running Felzenszwalb..." << endl;
    auto segments = seg.felzenszwalb(120000);

    seg.visualize(segments).saveImage("results/random.png");
    seg.visualizeBlend(segments, 0.7f).saveImage("results/blend.png");


    cout << "Classifying foreground..." << endl;
    auto mask = seg.backgroundExtraction();

    seg.visualizeBinary(mask).saveImage("results/mask.png");

    cout << "Done! Results saved in results/ folder." << endl;

    return 0;
}

