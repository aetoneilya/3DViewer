#ifndef SRC_VIEW_OPENGL_WIDGET_H_
#define SRC_VIEW_OPENGL_WIDGET_H_

#include <QMouseEvent>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QWheelEvent>

#include "../controller/controller.h"

class OpenGLWidget : public QOpenGLWidget {
    Q_OBJECT

 public:
    explicit OpenGLWidget(QWidget* parent = nullptr);
    ~OpenGLWidget() override {
    }

    void SetController(s21::Controller* c) {
        controller_ = c;
    }

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

 protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

 private:
    void InitShaders();

    s21::Controller* controller_;
    QOpenGLShaderProgram program_;

    QVector2D mouse_position_;
};

#endif  // SRC_VIEW_OPENGL_WIDGET_H_
