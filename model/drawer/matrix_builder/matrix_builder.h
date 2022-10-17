#ifndef SRC_MODEL_DRAWER_MATRIX_BUILDER_MATRIX_BUILDER_H_
#define SRC_MODEL_DRAWER_MATRIX_BUILDER_MATRIX_BUILDER_H_

#include <QMatrix4x4>
#include <QVector>
#include <cmath>

#include "../../settings/settings.h"

namespace s21 {
class MatrixBuilder {
 public:
    static QMatrix4x4 make_mvp_matrix(Settings::Projection proj_type);

    static void SetResolution(int w, int h);
    static void MoveCamera(float x, float y, float z);
    static void MoveModel(float x, float y, float z);
    static void SetModelPosition(float x, float y, float z);
    static void RotateModel(float angle, float x, float y, float z);
    static void RotateModel(QQuaternion quaternion);
    static void SetRotation(float pitch, float yaw, float roll);
    static void ScaleModel(float x, float y, float z);
    static void SetModelScale(float x, float y, float z);
    static void ResetEye();
    static void ResetModelMatrix();
    static void CenterFigure(float x_center, float y_center, float z_center);
    static void AdjustCamera(float height, float width, float deep);

 private:
    static QQuaternion model_rotation_;
    static QVector3D model_position_;
    static QVector3D model_scale_;
    static QVector3D eye_;
    static QVector3D center_;
    static QVector3D up_;
    static float fov_;

    struct Resolution {
        float width = 1;
        float height = 1;
    };

    static Resolution resolution_;
};
}  // namespace s21

#endif  // SRC_MODEL_DRAWER_MATRIX_BUILDER_MATRIX_BUILDER_H_
