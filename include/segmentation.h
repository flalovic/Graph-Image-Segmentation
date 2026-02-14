#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include "image.h"
#include <vector>
#include <unordered_map>


struct Edge {
    int u, v;
    float w;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU{
    std::vector<int> parent, size;
    std::vector<float> internal;

    DSU(int n);
    int find(int x);
    void unite(int a, int b, float w);
};

class Segmentation{
public:
    Image img;

    Segmentation(const Image&);

    std::vector<int> felzenszwalb(float k = 120000);
    std::vector<int> backgroundExtraction();

    // visualizations
    Image visualize(const std::vector<int>& label);
    Image visualizeBlend(const std::vector<int>& label, float alpha = 0.7f);
    Image visualizeBinary(const std::vector<int>& label);

private:
    Image blur(const Image&);
};

#endif

