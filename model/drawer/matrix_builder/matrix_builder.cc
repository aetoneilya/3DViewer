#include "matrix_builder.h"

namespace s21 {
QQuaternion MatrixBuilder::model_rotation_ = QQuaternion();
QVector3D MatrixBuilder::model_position_ = {0, 0, 0};
QVector3D MatrixBuilder::model_scale_ = {1, 1, 1};
QVector3D MatrixBuilder::eye_ = {0, 0, -10};
QVector3D MatrixBuilder::center_ = {0, 0, 0};
QVector3D MatrixBuilder::up_ = {0, 1, 0};
float MatrixBuilder::fov_ = 45;
MatrixBuilder::Resolution MatrixBuilder::resolution_ = {1, 1};

QMatrix4x4 MatrixBuilder::make_mvp_matrix(Settings::Projection proj_type) {
    QMatrix4x4 model_matrix;
    model_matrix.translate(model_position_);
    model_matrix.rotate(model_rotation_);
    model_matrix.scale(model_scale_);

    QMatrix4x4 view_matrix;
    view_matrix.lookAt(eye_, center_, up_);
    QMatrix4x4 projection_matrix;
    switch (proj_type) {
        case Settings::Projection::kPerspective:
            projection_matrix.perspective(fov_, resolution_.width / resolution_.height, 1.0, 1250.0);
            break;
        case Settings::Projection::kOrthographic:
            projection_matrix.ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 100.0f);
            break;
    }

    QMatrix4x4 mvp_matrix = projection_matrix * view_matrix * model_matrix;
    return mvp_matrix;
}

void MatrixBuilder::SetResolution(int w, int h) {
    resolution_.width = w;
    resolution_.height = h;
}

void MatrixBuilder::MoveCamera(float x, float y, float z) {
    QVector3D add_vector(x, y, z);
    eye_ = eye_ + add_vector;
}

void MatrixBuilder::MoveModel(float x, float y, float z) {
    QVector3D add_vector(x, y, z);
    model_position_ = model_position_ + add_vector;
}

void MatrixBuilder::SetModelPosition(float x, float y, float z) {
    QVector3D new_position(x, y, z);
    model_position_ = new_position;
}

void MatrixBuilder::RotateModel(float angle, float x, float y, float z) {
    QQuaternion rotation = QQuaternion::fromAxisAndAngle(x, y, z, angle);
    model_rotation_ = rotation * model_rotation_;
}

void MatrixBuilder::RotateModel(QQuaternion quaternion) {
    model_rotation_ = quaternion * model_rotation_;
}

void MatrixBuilder::SetRotation(float pitch, float yaw, float roll) {
    QQuaternion rotation = QQuaternion::fromEulerAngles(pitch, yaw, roll);

    model_rotation_ = rotation;
}

void MatrixBuilder::ScaleModel(float x, float y, float z) {
    QVector3D add_vector(x, y, z);
    model_scale_ = model_scale_ * add_vector;
}

void MatrixBuilder::SetModelScale(float x, float y, float z) {
    model_scale_ = {x, y, z};
}

void MatrixBuilder::ResetEye() {
    eye_ = {0, 0, 0};
}

void MatrixBuilder::ResetModelMatrix() {
    model_position_ = {0, 0, 0};
    model_rotation_ = QQuaternion();
    model_scale_ = {1, 1, 1};
}

void MatrixBuilder::CenterFigure(float x_center, float y_center, float z_center) {
    eye_ += {x_center, y_center, z_center};
    center_ = {x_center, y_center, z_center};
}

void MatrixBuilder::AdjustCamera(float height, float width, float deep) {
    float distance_y = 1.5 * height / tan(fov_ / 2);
    float distance_x = 1.5 * width / tan((fov_) / 2);
    float distance_z = deep * 1.5;

    float eye_distance = std::max({distance_x, distance_y, distance_z});

    eye_ += {0, 0, eye_distance};
}
}  // namespace s21
