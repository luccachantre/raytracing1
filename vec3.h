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

// Vector Utility Functions


//this function allows us to easily print the values of a vec3
//it works like this:
// vec3 v(1, 2 3);
// std::cout << v;
//and that prints:
// 1 2 3
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

//the next functions are for operations 
//here's one example and its basically the same for the rest
//vec3 u(1, 2, 3);
//vec3 v(4, 5, 6);
//vec3 w = u + v;
//so w is now (5, 7, 9)
//while u and v are unchanged
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}


//These next two functions are very common in C++
//"Why are we doing operator* twice?"
//so the compiler doesn't recognize that these two expressions are equivalent
//2.0 * v
//v * 2.0
//so we need to explicity define how to handle both. 
//but in the code, once we have the first one, we can just call it in the second one,
//which is what we do below
//and then in operator/, we also use the same t * v
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

//dot product returns a scalar (number), not another vector
//dot product is a measurement of much two vectors point in the same direction
//if two vectors are at 90 degrees, it is 0
//if they point in opposite directions, it is negative
//This is useful in computer graphics for things like determining how directly light hits a surface (dot product between light direction and surface normal)
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0] 
         + u.e[1] * v.e[1] 
         + u.e[2] * v.e[2];
}


//cross product returns another vector
//cross product gives a vector perpendicular to the original two vectors
//basically imagine two vectors pointing in random directions
//you line them up as if they're on a 2d plane, and then the vector pointing directly out of the page is the cross product, I think.
//this is useful for calculating surface normals
//also the magnitude of the cross product vector equals the area between the two vectors
//its also important to note that whether it points like out of the page of behind the page depends on the order. its uhh, how do I explain this..
//so it gives two vectors, but you always take the first one and then use your right hand to curve to the next one, and the direction your thumb points in is the correct one.
//sorry I know that makes no sense, look up cross product right hand rule for more info
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

//this function produces a normalized version of the input vector, 
//which means its length is converted to 1. 
//This is useful for consistent calculations when other functions dont want to account for differing vector magnitudes
inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif