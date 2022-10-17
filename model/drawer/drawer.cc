#include "drawer.h"

namespace s21 {
void Drawer::Draw(QOpenGLShaderProgram* program) {
  // setSceneRadius(10000.0);

  auto bgcolor = settings_.GetBackgroundColor();
  glClearColor(bgcolor.redF(), bgcolor.greenF(), bgcolor.blueF(),
               bgcolor.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (figure_) {
    if (figure_changed_) {
      MatrixBuilder::ResetEye();
      ResetModelMatrix();
      CenterFigure();
      AdjustCamera();
      InitOpengl();

      figure_changed_ = false;
    }

    QMatrix4x4 mvp_matrix =
        MatrixBuilder::make_mvp_matrix(settings_.GetProjection());

    program->bind();
    program->setUniformValue("qt_ModelViewProjectionMatrix", mvp_matrix);

    vertex_buffer_.bind();
    index_buffer_.bind();

    int vert_location_ = program->attributeLocation("qt_Vertex");
    program->enableAttributeArray(vert_location_);
    program->setAttributeBuffer(vert_location_, GL_FLOAT, 0, 3, sizeof(Point));

    auto edge_color = settings_.GetEdge().GetColor();
    float edge_rgba[4] = {edge_color.redF(), edge_color.greenF(),
                          edge_color.blueF(), edge_color.alphaF()};
    program->setUniformValueArray(program->uniformLocation("color"), edge_rgba,
                                  1, 4);

    switch (settings_.GetEdge().GetStyle()) {
      case Settings::EdgeStyle::kSolid:
        glDisable(GL_LINE_STIPPLE);
        break;
      case Settings::EdgeStyle::kDotted:
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00F0);
        break;
    }

    glLineWidth(settings_.GetEdge().GetThickness());

    glDrawElements(GL_LINES, figure_->GetSurfaces().size(), GL_UNSIGNED_INT,
                   nullptr);

    auto vertex_color = settings_.GetVertex().GetColor();
    float vertex_rgba[4] = {vertex_color.redF(), vertex_color.greenF(),
                            vertex_color.blueF(), vertex_color.alphaF()};
    program->setUniformValueArray(program->uniformLocation("color"),
                                  vertex_rgba, 1, 4);

    if (settings_.GetVertex().GetStyle() != Settings::VertexStyle::kNone) {
      glPointSize(settings_.GetVertex().GetSize());

      switch (settings_.GetVertex().GetStyle()) {
        case Settings::VertexStyle::kCircle:
          glEnable(GL_POINT_SMOOTH);
          break;
        case Settings::VertexStyle::kSquare:
          glDisable(GL_POINT_SMOOTH);
          break;
        default:
          break;
      }

      glDrawArrays(GL_POINTS, 0, figure_->GetVerticies().size());
    }
  }
}

void Drawer::InitOpengl() {
  if (vertex_buffer_.isCreated()) {
    vertex_buffer_.destroy();
  }
  if (index_buffer_.isCreated()) {
    index_buffer_.destroy();
  }

  vertex_buffer_.create();
  vertex_buffer_.bind();
  vertex_buffer_.allocate(figure_->GetVerticies().data(),
                          figure_->GetVerticies().size() * sizeof(Vertex));
  vertex_buffer_.release();

  index_buffer_.create();
  index_buffer_.bind();
  index_buffer_.allocate(figure_->GetSurfaces().data(),
                         figure_->GetSurfaces().size() * sizeof(GLuint));
  vertex_buffer_.release();
}
}  // namespace s21
