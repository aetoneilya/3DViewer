#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include <memory>

#include "drawer/drawer.h"
#include "drawer/figure/figure.h"
#include "filereader/filereader.h"
#include "filereader/observer.h"
#include "settings/settings.h"

namespace s21 {
class Model : public BaseFileReaderObserver {
 public:
    Model() {
        filereader_->AddObserver(this);
    }
    ~Model() {
    }

    void Draw(QOpenGLShaderProgram* program) {
        if (!drawer_) {
            drawer_ = std::make_unique<Drawer>(settings_);
        }
        drawer_->Draw(program);
    }

    void SetResolution(int w, int h) {
        if (!drawer_) {
            drawer_ = std::make_unique<Drawer>(settings_);
        }
        drawer_->SetResolution(w, h);
    }

    auto const& GetFileReader() {
        return filereader_;
    }

    void Parse(std::string const& filename) {
        filereader_->Parse(filename);
    }

    void Update(std::shared_ptr<Figure const> figure) override {
        if (drawer_) {
            drawer_->SetFigure(figure);
        }
    }

    void MoveCamera(float x, float y, float z) {
        drawer_->MoveCamera(x, y, z);
    }

    void MoveModel(float x, float y, float z) {
        drawer_->MoveModel(x, y, z);
    }

    void MoveModelTo(float x, float y, float z) {
        drawer_->SetModelPosition(x, y, z);
    }

    void SetRotation(float pitch, float yaw, float roll) {
        drawer_->SetRotation(pitch, yaw, roll);
    }

    void RotateModel(float angle, float x, float y, float z) {
        drawer_->RotateModel(angle, x, y, z);
    }

    void RotateModel(QQuaternion quaternion) {
        drawer_->RotateModel(quaternion);
    }

    void ScaleModel(float x, float y, float z) {
        drawer_->ScaleModel(x, y, z);
    }

    void SetModelScale(float x, float y, float z) {
        drawer_->SetModelScale(x, y, z);
    }

    float GetMoveValue() {
        float move = 0;
        if (drawer_) {
            move = drawer_->GetMoveLength();
        }
        return move;
    }

    auto const& GetProjection() const {
        return settings_.GetProjection();
    }
    void SetProjection(Settings::Projection const& projection) {
        settings_.SetProjection(projection);
    }

    auto const& GetEdge() const {
        return settings_.GetEdge();
    }
    void SetEdgeStyle(Settings::EdgeStyle const& style) {
        settings_.GetEdge().SetStyle(style);
    }
    void SetEdgeColor(QColor const& color) {
        settings_.GetEdge().SetColor(color);
    }
    void SetEdgeThickness(std::size_t thickness) {
        settings_.GetEdge().SetThickness(thickness);
    }

    auto const& GetVertex() const {
        return settings_.GetVertex();
    }
    void SetVertexStyle(Settings::VertexStyle const& style) {
        settings_.GetVertex().SetStyle(style);
    }
    void SetVertexColor(QColor const& color) {
        settings_.GetVertex().SetColor(color);
    }
    void SetVertexSize(std::size_t const& size) {
        settings_.GetVertex().SetSize(size);
    }

    auto const& GetBackgroundColor() const {
        return settings_.GetBackgroundColor();
    }
    void SetBackgroundColor(QColor const& color) {
        settings_.SetBackgroundColor(color);
    }

    void SaveSettings() {
        settings_.Save();
    }
    void LoadSettings() {
        settings_.Load();
    }
    void ResetSettings() {
        settings_.SetDefault();
    }

    void ResetModel() {
        if (drawer_) {
            drawer_->ResetModelMatrix();
            // drawer_->CenterFigure();
        }
    }

 private:
    std::unique_ptr<BaseFileReader> filereader_ = std::make_unique<FileReader>();
    std::unique_ptr<Drawer> drawer_ = nullptr;
    Settings settings_;
};
}  // namespace s21

#endif  //  SRC_MODEL_MODEL_H_
