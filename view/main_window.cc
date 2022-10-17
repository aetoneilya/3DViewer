#include "main_window.h"

#include <string>

#include "ui_mainwindow.h"

namespace s21 {
MainWindow::MainWindow(Controller *c, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(c), gif_count_(0) {
    ui->setupUi(this);

    connect(&timer_, &QTimer::timeout, this, &MainWindow::gif_cycle_);

    controller_->GetFileReader()->AddObserver(this);

    ui->openGLView->SetController(controller_);

    ui->openGLView->setFocusPolicy(Qt::StrongFocus);
    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);

    controller_->LoadSettings();
    UpdateSettingsWidgets();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    double x_pos = ui->x_move_dbl_spinbox->value();
    double y_pos = ui->y_move_dbl_spinbox->value();
    double z_pos = ui->z_move_dbl_spinbox->value();
    switch (event->key()) {
        case Qt::Key_W:
            ui->y_move_dbl_spinbox->setValue(y_pos + 1);
            break;
        case Qt::Key_S:
            ui->y_move_dbl_spinbox->setValue(y_pos - 1);
            break;
        case Qt::Key_D:
            ui->x_move_dbl_spinbox->setValue(x_pos + 1);
            break;
        case Qt::Key_A:
            ui->x_move_dbl_spinbox->setValue(x_pos - 1);
            break;
        case Qt::Key_X:
            ui->z_move_dbl_spinbox->setValue(z_pos + 1);
            break;
        case Qt::Key_Z:
            ui->z_move_dbl_spinbox->setValue(z_pos - 1);
            break;
        case Qt::Key_Q:
            controller_->RotateByZ(10);
            break;
        case Qt::Key_E:
            controller_->RotateByZ(-10);
            break;
        case Qt::Key_R:
            ui->x_move_dbl_spinbox->setValue(0);
            ui->y_move_dbl_spinbox->setValue(0);
            ui->z_move_dbl_spinbox->setValue(0);
            controller_->ResetModel();
            break;
    }
}

void MainWindow::on_choose_file_btn_clicked() {
    QFileDialog fd(this);
    QString file_name = fd.getOpenFileName(this, tr("Open the file"), "", tr("Obj files (*.obj)"));

    auto els = file_name.split(QLatin1Char('/'));

    if (!file_name.isEmpty()) {
        QByteArray ba = file_name.toLocal8Bit();
        ui->filename_label->setText(els.at(els.size() - 1));
        SetFile(ba.constData());
    }
}

void MainWindow::Update(std::shared_ptr<Figure const> figure) {
    ui->vert_label->setText(QString::number(figure->GetVerticies().size()));
    ui->edge_label->setText(QString::number(figure->GetSurfaceCount()));
}

void MainWindow::UpdateModelPosition() {
    float move = controller_->GetMoveValue();
    double x_pos = move * ui->x_move_dbl_spinbox->value();
    double y_pos = move * ui->y_move_dbl_spinbox->value();
    double z_pos = move * ui->z_move_dbl_spinbox->value();
    controller_->MoveTo(x_pos, y_pos, z_pos);
}

void MainWindow::on_x_move_dbl_spinbox_valueChanged() {
    UpdateModelPosition();
}
void MainWindow::on_y_move_dbl_spinbox_valueChanged() {
    UpdateModelPosition();
}
void MainWindow::on_z_move_dbl_spinbox_valueChanged() {
    UpdateModelPosition();
}

void MainWindow::UpdateModelRotation() {
    int pitch = ui->x_rotation_slider->value();
    int yaw = ui->y_rotation_slider->value();
    int roll = ui->z_rotation_slider->value();

    controller_->SetRotation(pitch, yaw, roll);
}

void MainWindow::UpdateSettingsWidgets() {
    ui->proj_type_chooser->setCurrentIndex(
        static_cast<std::underlying_type_t<Settings::Projection>>(controller_->GetProjection()));

    ui->edge_type_ch->setCurrentIndex(
        static_cast<std::underlying_type_t<Settings::EdgeStyle>>(controller_->GetEdge().GetStyle()));
    ui->edge_thick_ch->setValue(controller_->GetEdge().GetThickness());

    ui->vert_type_ch->setCurrentIndex(
        static_cast<std::underlying_type_t<Settings::VertexStyle>>(controller_->GetVertex().GetStyle()));
    ui->vert_size_ch->setValue(controller_->GetVertex().GetSize());
}

void MainWindow::on_x_rotation_slider_valueChanged() {
    UpdateModelRotation();
}

void MainWindow::on_y_rotation_slider_valueChanged() {
    UpdateModelRotation();
}

void MainWindow::on_z_rotation_slider_valueChanged() {
    UpdateModelRotation();
}

void MainWindow::on_scale_slider_valueChanged() {
    int scale = ui->scale_slider->value();
    if (scale >= 0) {
        controller_->SetScale(1 + scale);
    } else {
        controller_->SetScale(1. / (1 - scale));
    }
}

void MainWindow::on_reset_settings_clicked() {
    controller_->ResetSettings();
    controller_->SaveSettings();
    UpdateSettingsWidgets();
}

void MainWindow::on_edge_type_ch_currentIndexChanged(int index) {
    controller_->SetEdgeStyle(static_cast<Settings::EdgeStyle>(index));
    controller_->SaveSettings();

    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);
}

void MainWindow::on_edge_color_ch_clicked() {
    QColor color = QColorDialog::getColor(controller_->GetEdge().GetColor(), this);
    if (color.isValid()) {
        controller_->SetEdgeColor(color);
        controller_->SaveSettings();
    }

    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);
}

void MainWindow::on_edge_thick_ch_valueChanged(int value) {
    controller_->SetEdgeThickness(value);
    controller_->SaveSettings();

    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);
}

void MainWindow::on_vert_type_ch_currentIndexChanged(int index) {
    controller_->SetVertexStyle(static_cast<Settings::VertexStyle>(index));
    controller_->SaveSettings();

    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);
}

void MainWindow::on_vert_color_ch_clicked() {
    QColor color = QColorDialog::getColor(controller_->GetVertex().GetColor(), this);
    if (color.isValid()) {
        controller_->SetVertexColor(color);
        controller_->SaveSettings();
    }

    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);
}

void MainWindow::on_vert_size_ch_valueChanged(int value) {
    controller_->SetVertexSize(value);
    controller_->SaveSettings();

    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);
}

void MainWindow::on_bg_color_chooser_clicked() {
    QColor color = QColorDialog::getColor(controller_->GetBackgroundColor(), this);
    if (color.isValid()) {
        controller_->SetBackgroundColor(color);
        controller_->SaveSettings();
    }

    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);
}

void MainWindow::on_proj_type_chooser_currentIndexChanged(int index) {
    controller_->SetProjection(static_cast<Settings::Projection>(index));
    controller_->SaveSettings();

    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);
}

void MainWindow::on_save_img_clicked() {
    QFileDialog fd(this);
    QString file_name = fd.getSaveFileName(this, tr("Save the screenshot"), "", tr("images (*.bmp *.jpeg)"));
    QImage image = ui->openGLView->grabFramebuffer();
    image.save(file_name);

    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);
}

void MainWindow::on_save_gif_clicked() {
    gif_ = std::make_unique<QGifImage>();
    gif_->setDefaultDelay(10);
    timer_.start(100);

    ui->openGLView->setFocus(Qt::ActiveWindowFocusReason);
}

void MainWindow::gif_cycle_() {
    if (gif_count_ < 50) {
        QImage frame = ui->openGLView->grabFramebuffer();
        gif_->addFrame(frame);
        gif_count_++;
    } else {
        timer_.stop();
        QString screenFileName =
            QFileDialog::getSaveFileName(this, tr("Save the gif"), "", tr("images (*.gif)"));
        gif_->save(screenFileName);
        gif_count_ = 0;
    }
}
}  // namespace s21
