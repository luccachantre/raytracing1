#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public: 
        double e[3];
        //so the class has this e[] attribute which is just the array of values

        vec3() : e{0,0,0} {}
        //^this is one way to initialize a default vec3
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
        //^and this is another way to initialize that we're specifying, with given values

        //writing functions to grab any of the 3 values individually
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        //makes all values negative
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

        //At first I didn't understand these two below but I think I do now
        //this first one allows read-only access, so we can do something like this:
        //vec3 v(1, 2, 3);
        //double x = v[0];
        //it returns a copy of the value, not the actual value
        double operator[](int i) const { return e[i]; }

        //And this one allows for writable access, because of the & next to double
        //The & is to return a reference to the actual array element, not just a copy
        //so now we can do something like:
        //vec3 v(1, 2, 3);
        //v[0] = 10;
        double& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;



#endif