#ifndef SRC_MODEL_SETTINGS_SETTINGS_H_
#define SRC_MODEL_SETTINGS_SETTINGS_H_

#include <QColor>
#include <fstream>
#include <string>

namespace s21 {
class Settings {
 public:
    enum class Projection { kOrthographic, kPerspective };
    enum class EdgeStyle { kSolid, kDotted };
    enum class VertexStyle { kNone, kCircle, kSquare };

    class Edge {
     public:
        Edge() : Edge(EdgeStyle::kSolid, "#FAFAFA", 1) {
        }
        Edge(EdgeStyle const& style, QColor const& color, std::size_t thickness)
            : style_(style), color_(color), thickness_(thickness) {
        }
        Edge(Edge const& other) = default;
        Edge(Edge&& other) = default;
        Edge& operator=(Edge const& other) = default;
        Edge& operator=(Edge&& other) = default;

        auto const& GetStyle() const {
            return style_;
        }
        auto const& GetColor() const {
            return color_;
        }
        auto const& GetThickness() const {
            return thickness_;
        }

        void SetStyle(EdgeStyle const& style) {
            style_ = style;
        }
        void SetColor(QColor const& color) {
            color_ = color;
        }
        void SetThickness(std::size_t thickness) {
            thickness_ = thickness;
        }

     private:
        EdgeStyle style_;
        QColor color_;
        std::size_t thickness_;
    };

    struct Vertex {
     public:
        Vertex() : Vertex(VertexStyle::kNone, "#63A0E1", 1) {
        }
        Vertex(VertexStyle const& style, QColor const& color, std::size_t size)
            : style_(style), color_(color), size_(size) {
        }
        Vertex(Vertex const& other) = default;
        Vertex(Vertex&& other) = default;
        Vertex& operator=(Vertex const& other) = default;
        Vertex& operator=(Vertex&& other) = default;

        auto const& GetStyle() const {
            return style_;
        }
        auto const& GetColor() const {
            return color_;
        }
        auto const& GetSize() const {
            return size_;
        }

        void SetStyle(VertexStyle const& style) {
            style_ = style;
        }
        void SetColor(QColor const& color) {
            color_ = color;
        }
        void SetSize(std::size_t const& size) {
            size_ = size;
        }

     private:
        VertexStyle style_;
        QColor color_;
        std::size_t size_;
    };

    Settings() {
    }
    Settings(Settings const& other) = delete;
    Settings(Settings&& other) = delete;
    Settings& operator=(Settings const& other) = delete;
    Settings& operator=(Settings&& other) = delete;

    auto const& GetProjection() const {
        return data_.projection;
    }
    auto const& GetEdge() const {
        return data_.edge;
    }
    auto& GetEdge() {
        return data_.edge;
    }
    auto const& GetVertex() const {
        return data_.vertex;
    }
    auto& GetVertex() {
        return data_.vertex;
    }
    auto const& GetBackgroundColor() const {
        return data_.background_color;
    }

    void SetProjection(Projection const& projection) {
        data_.projection = projection;
    }
    void SetEdge(Edge const& edge) {
        data_.edge = edge;
    }
    void SetVertex(Vertex const& vertex) {
        data_.vertex = vertex;
    }
    void SetBackgroundColor(QColor const& color) {
        data_.background_color = color;
    }

    void SetDefault() {
        data_ = Data();
    }

    void Save(std::string const& filename = filename_);
    void Load(std::string const& filename = filename_);

 private:
    struct Data {
        Projection projection = Projection::kPerspective;
        Edge edge;
        Vertex vertex;
        QColor background_color = "#0D335C";
    };

    inline static std::string const filename_ = "config.bin";

    Data data_;
};
}  // namespace s21

#endif  // SRC_MODEL_SETTINGS_SETTINGS_H_
