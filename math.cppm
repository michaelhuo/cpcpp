#include <cmath>
#include <concepts>
export module math;
template <std::floating_point T>
export class Vector {
    public:
        T x, y, z;
        static constexpr auto zero() {
            return Vector(0, 0, 0);
        }
        static constexpr auto one() {
            return Vector(1, 1, 1);
        }   
        Vector(T x, T y, T z) : x(x), y(y), z(z) {};
        Vector() : x(0), y(0), z(0) {};
        auto operator+(const Vector& other) const {
            return Vector(x + other.x, y + other.y, z + other.z);
        }
        auto operator-(const Vector& other) const {
            return Vector(x - other.x, y - other.y, z - other.z);
        }
        auto operator*(T scalar) const {
            return Vector(x * scalar, y * scalar, z * scalar);
        }
        auto operator/(T scalar) const {
            if (scalar == 0) {
                throw std::invalid_argument("Division by zero");
            }
            return Vector(x / scalar, y / scalar, z / scalar);
        }
        bool operator<=>(const Vector& other) const = default;

        T magnitude() const {
            return sqrt(static_cast<double>(x * x + y * y + z * z));
        }
    private:
        // Private members can be added here if needed
        T x, y, z;
}