#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
    //think of this like how you make a class in java, in private is where you declare the variables
    //and the constructors are like in java where it would be this.orig = origin, etc.

    //The most important part of this class is the ray.at() function
    //this function will compute a point that is t units along the ray
    //based on the ray's origin point and direction vector
        ray() {}

        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

        const point3& origin() const { return orig; }
        const vec3& direction() const { return dir; }

        point3 at(double t) const {
            return orig + t*dir;
        }
    
        private:
            point3 orig;
            vec3 dir;
};

//Note from the book:
//For those unfamiliar with C++, the functions ray::origin() and ray::direction() both return an immutable reference to their members. allers can either just use the reference directly, or make a mutable copy depending on their needs

#endif