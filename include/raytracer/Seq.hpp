#pragma once

#include "../RayTracer.hpp"

class SeqRayTracer : public RayTracer {
    public:
        void init() override;
        TriangleIntersection any_hit(Ray& ray) override;
        TriangleIntersection closest_hit(Ray& ray) override;
};