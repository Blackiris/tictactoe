#pragma once

class Vector2D
{
public:
    Vector2D();
    Vector2D(const int &x, const int &y);
    int x = 0, y = 0;

    float length() const;
    float length_squared() const;
    Vector2D get_unit_vector() const;
    Vector2D& normalize();

    float dot(const Vector2D &vec2d) const;
    Vector2D operator-() const;
    Vector2D operator+(const Vector2D &vec2d) const;
    Vector2D operator-(const Vector2D &vec2d) const;
    Vector2D operator*(const double &coeff) const;
    // This friend function does the magic of float * vector
    friend Vector2D operator*(float scalar, const Vector2D& v) {
        return v * scalar;
    }

    Vector2D operator/(const double &coeff) const;

    Vector2D& operator+=(const Vector2D& vec2d);
    Vector2D& operator-=(const Vector2D& vec2d);
};

