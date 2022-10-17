#ifndef SRC_MODEL_DRAWER_FIGURE_FIGURE_H_
#define SRC_MODEL_DRAWER_FIGURE_FIGURE_H_

#include <vector>

namespace s21 {
struct Point {
    Point(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {
    }
    Point(Point const& other) = default;
    Point(Point&& other) = default;

    float x;
    float y;
    float z;

 protected:
    Point& operator=(Point const& other);
    Point& operator=(Point&& other);
};

class Vertex {
 public:
    Vertex(float x, float y, float z) : position_(x, y, z) {
    }
    Vertex(Vertex const& other) = default;
    Vertex(Vertex&& other) = default;

    auto const& GetPosition() const {
        return position_;
    }

 protected:
    Vertex& operator=(Vertex const& other);
    Vertex& operator=(Vertex&& other);

 private:
    Point position_;
};

class Figure {
 public:
    float GetMaxX() const {
        return x_max_;
    }
    float GetMinX() const {
        return x_min_;
    }
    float GetMaxY() const {
        return y_max_;
    }
    float GetMinY() const {
        return y_min_;
    }
    float GetMaxZ() const {
        return z_max_;
    }
    float GetMinZ() const {
        return z_min_;
    }

    auto const& GetVerticies() const {
        return verticies_;
    }

    auto const& GetSurfaces() const {
        return surfaces_;
    }

    auto const& GetSurfaceCount() const {
        return surface_count_;
    }

 private:
    friend class FileReader;

    void SetMaxX(float f) {
        x_max_ = f;
    }
    void SetMinX(float f) {
        x_min_ = f;
    }
    void SetMaxY(float f) {
        y_max_ = f;
    }
    void SetMinY(float f) {
        y_min_ = f;
    }
    void SetMaxZ(float f) {
        z_max_ = f;
    }
    void SetMinZ(float f) {
        z_min_ = f;
    }

    void AddVertex(Vertex const& vertex) {
        if (vertex.GetPosition().x > GetMaxX()) {
            SetMaxX(vertex.GetPosition().x);
        }
        if (vertex.GetPosition().x < GetMinX()) {
            SetMinX(vertex.GetPosition().x);
        }

        if (vertex.GetPosition().y > GetMaxY()) {
            SetMaxY(vertex.GetPosition().y);
        }
        if (vertex.GetPosition().y < GetMinY()) {
            SetMinY(vertex.GetPosition().y);
        }

        if (vertex.GetPosition().z > GetMaxZ()) {
            SetMaxZ(vertex.GetPosition().z);
        }
        if (vertex.GetPosition().z < GetMinZ()) {
            SetMinZ(vertex.GetPosition().z);
        }

        verticies_.push_back(vertex);
    }

    void AddSurface(std::vector<unsigned int> const& surface) {
        surfaces_.insert(surfaces_.end(), surface.begin(), surface.end());

        surface_count_++;
    }

    float x_max_ = 0;
    float x_min_ = 0;
    float y_max_ = 0;
    float y_min_ = 0;
    float z_max_ = 0;
    float z_min_ = 0;

    std::vector<Vertex> verticies_;
    std::vector<unsigned int> surfaces_;

    std::size_t surface_count_ = 0;
};
}  // namespace s21

#endif  // SRC_MODEL_DRAWER_FIGURE_FIGURE_H_
