#ifndef SRC_VIEW_MAIN_WINDOW_H_
#define SRC_VIEW_MAIN_WINDOW_H_

#include <QColorDialog>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>
#include <QVector>

#include "../QtGifImage/src/gifimage/qgifimage.h"
#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow, public BaseFileReaderObserver {
    Q_OBJECT

 public:
    explicit MainWindow(Controller *c, QWidget *parent = nullptr);
    ~MainWindow();

    void SetFile(std::string const &filename) {
        controller_->SetFile(filename);
    }
    void Update(std::shared_ptr<Figure const> figure) override;

 protected:
    void keyPressEvent(QKeyEvent *event) override;

 private:
    Ui::MainWindow *ui;
    Controller *controller_;

    QTimer timer_;
    std::unique_ptr<QGifImage> gif_;
    int gif_count_;

    void gif_cycle_();
    void UpdateModelPosition();
    void UpdateModelRotation();
    void UpdateSettingsWidgets();

 private slots:
    //  Main
    void on_choose_file_btn_clicked();
    void on_x_move_dbl_spinbox_valueChanged();
    void on_y_move_dbl_spinbox_valueChanged();
    void on_z_move_dbl_spinbox_valueChanged();
    void on_x_rotation_slider_valueChanged();
    void on_y_rotation_slider_valueChanged();
    void on_z_rotation_slider_valueChanged();
    void on_scale_slider_valueChanged();
    void on_reset_settings_clicked();
    //  Bonus 1
    void on_edge_type_ch_currentIndexChanged(int index);
    void on_edge_color_ch_clicked();
    void on_edge_thick_ch_valueChanged(int value);
    void on_vert_type_ch_currentIndexChanged(int index);
    void on_vert_color_ch_clicked();
    void on_vert_size_ch_valueChanged(int value);
    void on_bg_color_chooser_clicked();
    void on_proj_type_chooser_currentIndexChanged(int index);
    //  Bonus 2
    void on_save_img_clicked();
    void on_save_gif_clicked();
};
}  // namespace s21

#endif  // SRC_VIEW_MAIN_WINDOW_H_
