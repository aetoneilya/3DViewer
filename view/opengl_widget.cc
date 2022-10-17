#include "opengl_widget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent), controller_(nullptr) {
}

void OpenGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    controller_->SetResolution(w, h);
}

void OpenGLWidget::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    InitShaders();
}

void OpenGLWidget::InitShaders() {
    if (!program_.addShaderFromSourceFile(QOpenGLShader::Vertex, "view/shaders/vshader.glsl")) {
        close();
    }
    if (!program_.addShaderFromSourceFile(QOpenGLShader::Fragment, "view/shaders/fshader.glsl")) {
        close();
    }
    if (!program_.link()) {
        close();
    }
}

void OpenGLWidget::paintGL() {
    controller_->Draw(&program_);
    update();
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event) {
    mouse_position_ = QVector2D(event->pos());
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent *event) {
    QVector2D delta = QVector2D(event->pos()) - mouse_position_;
    mouse_position_ = QVector2D(event->pos());
    if (event->buttons() == Qt::LeftButton) {
        float angle = delta.length() / 2;
        QVector3D axis = QVector3D(delta.y(), delta.x(), 0.0);
        QQuaternion rotation = QQuaternion::fromAxisAndAngle(axis, angle);
        controller_->RotateModel(rotation);
        update();
    }
    // else if (event->buttons() == Qt::RightButton) {
    //     controller_->MoveCameraY(-delta.y() / 100);
    //     controller_->MoveCameraX(delta.x() / 100);
    // }
    update();
}

void OpenGLWidget::wheelEvent(QWheelEvent *event) {
    float angle = event->angleDelta().y();
    // controller_->MoveByZ(angle / 25.);
    controller_->MoveCameraZ(angle / 25.);

    update();
}
