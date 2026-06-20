#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public: 
        double e[3];
        //so the class has this e[] attribute which is just the array of values

        vec3() : e{0,0,0} {};
        //^this is one way to initialize a default vec3
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
        //^and this is another way to initialize that we're specifying, with given values

        //writing functions to grab any of the 3 values individually
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        //makes all values negative
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

        //don't quite understand what thse two ones do to be honest.
        //is it also so we can access/modify a single value?
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }
}

#endif