//
// Created by Benjamin Lee on 8/17/24.
//

#ifndef VEX_PATH_PLANNER_CLOTHOID_H
#define VEX_PATH_PLANNER_CLOTHOID_H

#include <vector>
#include "MathUtils.h"
#include "Curve.h"

namespace path {
    /**
     * @brief represents a clothoid.
     */
    class Clothoid: public Curve {
    public:
        /**
         * @param length arc length parameter
         * @param initialPosition (optional) starting position
         * @param initialHeading (optional) heading of starting tangent vector
         * @param sharpness (optional) rate of change in maxCurvature
         * @param initialCurvature (optional) starting maxCurvature
         * @param reversed (optional) whether to start the waypoints at the end of the clothoid
         * @param visible (optional) whether the clothoid is visible
         * @return points on the clothoid
         */
        explicit Clothoid(Vector2 initialPosition = {0, 0}, double initialHeading = 0, double length = 1,
                          double sharpness = M_PI, double initialCurvature = 0, bool reversed = false, bool visible = true);

        /**
         * get point at arc length t
         * @param t
         * @return a point on the clothoid
         */
        [[nodiscard]] Vector2 get_point(double t) const override;

        /**
         * @param numWaypoints number of waypoints
         * @return list of waypoints
         */
        void get_waypoints(std::vector<path::Vector2>& output, int numWaypoints) const override;

        /**
         * @param ds step size
         * @return list of waypoints
         */
        void get_waypoints_spaced(std::vector<path::Vector2>& output, double ds) const override;

        [[nodiscard]] double get_length() const override;
        [[nodiscard]] double get_sharpness() const;
        [[nodiscard]] double get_initial_curvature() const;
        [[nodiscard]] double get_initial_heading() const;
        [[nodiscard]] Vector2 get_initial_position() const;

        void set_length(double length);
        void set_sharpness(double sharpness);
        void set_initial_curvature(double curvature);
        void set_initial_heading(double heading);
        void set_initial_position(Vector2 position);
        void configure(Vector2 initialPosition = {0, 0}, double initialHeading = 0, double length = 1,
                       double sharpness = M_PI, double initialCurvature = 0, bool reversed = false);

    private:
        double s;
        double sigma_2;  // sharpness
        double kappa0; // initial maxCurvature
        double theta0; // initial heading
        Vector2 p0;     // initial position

        bool reversed;
    };

} // path

#endif //VEX_PATH_PLANNER_CLOTHOID_H
