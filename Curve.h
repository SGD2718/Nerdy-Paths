//
// Created by Benjamin Lee on 8/17/24.
//

#ifndef VEX_PATH_PLANNER_CURVE_H
#define VEX_PATH_PLANNER_CURVE_H

#include <cmath>
#include <vector>
#include "Vector2.h"
#include "MathUtils.h"

namespace path {

    class Curve {
    public:
        explicit Curve(bool visible = true);

        [[nodiscard]] virtual Vector2 get_point(double s) const;
        [[nodiscard]] virtual double get_length() const;

        virtual void get_waypoints(std::vector<Vector2>& output, int numPoints) const;
        virtual void get_waypoints_spaced(std::vector<Vector2>& output, double ds) const;

        [[nodiscard]] std::vector<Vector2> get_waypoints(int numPoints) const;
        [[nodiscard]] std::vector<Vector2> get_waypoints_spaced(double ds) const;

        [[nodiscard]] bool is_visible() const;

        void set_visibility(bool visibility);

    private:
        bool visible;
    };
} // path

#endif //VEX_PATH_PLANNER_CURVE_H
