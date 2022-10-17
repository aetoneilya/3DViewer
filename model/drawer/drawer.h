#ifndef SRC_MODEL_DRAWER_DRAWER_H_
#define SRC_MODEL_DRAWER_DRAWER_H_

#define GL_SILENCE_DEPRECATION

#include <QColor>
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLExtraFunctions>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QVector>

#include "../settings/settings.h"
#include "figure/figure.h"
#include "matrix_builder/matrix_builder.h"

namespace s21 {
class Drawer : protected QOpenGLFunctions {
 public:
    explicit Drawer(Settings const& settings)
        : vertex_buffer_(QOpenGLBuffer::VertexBuffer),
          index_buffer_(QOpenGLBuffer::IndexBuffer),
          settings_(settings) {
        initializeOpenGLFunctions();
    }
    ~Drawer() = default;

    void Draw(QOpenGLShaderProgram* program);
    void SetFigure(std::shared_ptr<Figure const> figure) {
        figure_ = figure;

        figure_changed_ = true;

        SetMoveLength();
    }

    void SetMoveLength() {
        float height = (figure_->GetMaxY() - figure_->GetMinY());
        float width = (figure_->GetMaxX() - figure_->GetMinX());
        float deep = (figure_->GetMaxZ() - figure_->GetMinZ());

        move_length_ = 0.05 * (height + width + deep) / 3;
    }

    void SetResolution(int w, int h) {
        MatrixBuilder::SetResolution(w, h);
    }

    void MoveCamera(float x, float y, float z) {
        MatrixBuilder::MoveCamera(x, y, z);
    }

    void MoveModel(float x, float y, float z) {
        MatrixBuilder::MoveModel(x, y, z);
    }

    void SetModelPosition(float x, float y, float z) {
        MatrixBuilder::SetModelPosition(x, y, z);
    }

    void RotateModel(float angle, float x, float y, float z) {
        MatrixBuilder::RotateModel(angle, x, y, z);
    }

    void RotateModel(QQuaternion quaternion) {
        MatrixBuilder::RotateModel(quaternion);
    }

    void SetRotation(float pitch, float yaw, float roll) {
        MatrixBuilder::SetRotation(pitch, yaw, roll);
    }

    void ScaleModel(float x, float y, float z) {
        MatrixBuilder::ScaleModel(x, y, z);
    }

    void SetModelScale(float x, float y, float z) {
        MatrixBuilder::SetModelScale(x, y, z);
    }

    void ResetModelMatrix() {
        MatrixBuilder::ResetModelMatrix();
    }

    void CenterFigure() {
        float x_center = (figure_->GetMaxX() + figure_->GetMinX()) / 2;
        float y_center = (figure_->GetMaxY() + figure_->GetMinY()) / 2;
        float z_center = (figure_->GetMaxZ() + figure_->GetMinZ()) / 2;

        MatrixBuilder::CenterFigure(x_center, y_center, z_center);
    }

    void AdjustCamera() {
        float height = (figure_->GetMaxY() - figure_->GetMinY());
        float width = (figure_->GetMaxX() - figure_->GetMinX());
        float deep = (figure_->GetMaxZ() - figure_->GetMinZ());

        MatrixBuilder::AdjustCamera(height, width, deep);
    }

    float GetMoveLength() {
        return move_length_;
    }

 private:
    void InitOpengl();

    QOpenGLBuffer vertex_buffer_;
    QOpenGLBuffer index_buffer_;

    std::shared_ptr<Figure const> figure_ = nullptr;
    bool figure_changed_ = false;

    float move_length_ = 0.1;

    Settings const& settings_;
};
}  // namespace s21

#endif  // SRC_MODEL_DRAWER_DRAWER_H_
