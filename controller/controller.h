#ifndef SRC_CONTROLLER_CONTROLLER_H_
#define SRC_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
    explicit Controller(Model* m) : model_(m) {
    }
    ~Controller() {
    }

    void Draw(QOpenGLShaderProgram* program) {
        model_->Draw(program);
    }
    auto const& GetFileReader() {
        return model_->GetFileReader();
    }
    void SetFile(std::string const& filename) {
        model_->Parse(filename);
    }
    void SetResolution(int w, int h) {
        model_->SetResolution(w, h);
    }

    void MoveCameraX(float x) {
        model_->MoveCamera(x, 0, 0);
    }

    void MoveCameraY(float y) {
        model_->MoveCamera(0, y, 0);
    }

    void MoveCameraZ(float z) {
        model_->MoveCamera(0, 0, z);
    }

    void MoveTo(float x, float y, float z) {
        model_->MoveModelTo(x, y, z);
    }

    void Move(float x, float y, float z) {
        model_->MoveModel(x, y, z);
    }

    void MoveByX(float x) {
        model_->MoveModel(x, 0, 0);
    }
    void MoveByY(float y) {
        model_->MoveModel(0, y, 0);
    }
    void MoveByZ(float z) {
        model_->MoveModel(0, 0, z);
    }

    void SetRotation(float pitch, float yaw, float roll) {
        model_->SetRotation(pitch, yaw, roll);
    }

    void RotateByX(float angle) {
        model_->RotateModel(angle, 0, 1, 0);
    }
    void RotateByY(float angle) {
        model_->RotateModel(angle, 1, 0, 0);
    }
    void RotateByZ(float angle) {
        model_->RotateModel(angle, 0, 0, 1);
    }

    void Rotate(float angle, float x, float y, float z) {
        model_->RotateModel(angle, x, y, z);
    }

    void RotateModel(QQuaternion quaternion) {
        model_->RotateModel(quaternion);
    }

    void Scale(float factor) {
        model_->ScaleModel(factor, factor, factor);
    }

    void SetScale(float factor) {
        model_->SetModelScale(factor, factor, factor);
    }

    void ResetModel() {
        model_->ResetModel();
    }

    auto const& GetProjection() const {
        return model_->GetProjection();
    }
    void SetProjection(Settings::Projection const& projection) {
        model_->SetProjection(projection);
    }

    auto const& GetEdge() const {
        return model_->GetEdge();
    }
    void SetEdgeStyle(Settings::EdgeStyle const& style) {
        model_->SetEdgeStyle(style);
    }
    void SetEdgeColor(QColor const& color) {
        model_->SetEdgeColor(color);
    }
    void SetEdgeThickness(std::size_t thickness) {
        model_->SetEdgeThickness(thickness);
    }

    auto const& GetVertex() const {
        return model_->GetVertex();
    }
    void SetVertexStyle(Settings::VertexStyle const& style) {
        model_->SetVertexStyle(style);
    }
    void SetVertexColor(QColor const& color) {
        model_->SetVertexColor(color);
    }
    void SetVertexSize(std::size_t const& size) {
        model_->SetVertexSize(size);
    }

    auto const& GetBackgroundColor() const {
        return model_->GetBackgroundColor();
    }
    void SetBackgroundColor(QColor const& color) {
        model_->SetBackgroundColor(color);
    }

    void SaveSettings() {
        model_->SaveSettings();
    }
    void LoadSettings() {
        model_->LoadSettings();
    }
    void ResetSettings() {
        model_->ResetSettings();
    }

    float GetMoveValue() {
        return model_->GetMoveValue();
    }

 private:
    Model* model_;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_CONTROLLER_H_
