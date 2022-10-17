/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../view/opengl_widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QPushButton *choose_file_btn;
    QGroupBox *info_gp;
    QVBoxLayout *verticalLayout_7;
    QLabel *filename_label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *edges_info_label;
    QLabel *edge_label;
    QVBoxLayout *verticalLayout_3;
    QLabel *vert_info_label;
    QLabel *vert_label;
    QGroupBox *move_gb;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QDoubleSpinBox *x_move_dbl_spinbox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QDoubleSpinBox *y_move_dbl_spinbox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QDoubleSpinBox *z_move_dbl_spinbox;
    QGroupBox *rotate_gp;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QSlider *x_rotation_slider;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QSlider *y_rotation_slider;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QSlider *z_rotation_slider;
    QGroupBox *scale_gp;
    QHBoxLayout *horizontalLayout_3;
    QSlider *scale_slider;
    QSpacerItem *verticalSpacer;
    OpenGLWidget *openGLView;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *save_img;
    QPushButton *save_gif;
    QGroupBox *groupBox_5;
    QFormLayout *formLayout_5;
    QPushButton *bg_color_chooser;
    QComboBox *proj_type_chooser;
    QLabel *bg_color_label;
    QLabel *project_type_label;
    QGroupBox *edges_gb;
    QFormLayout *formLayout;
    QLabel *edges_type_label;
    QComboBox *edge_type_ch;
    QPushButton *edge_color_ch;
    QLabel *edges_color_label;
    QLabel *edges_thick_label;
    QSlider *edge_thick_ch;
    QGroupBox *vertices_gb;
    QFormLayout *formLayout_2;
    QLabel *vert_type_label;
    QComboBox *vert_type_ch;
    QLabel *vert_color_label;
    QPushButton *vert_color_ch;
    QLabel *vert_size_label;
    QSlider *vert_size_ch;
    QSpacerItem *verticalSpacer_2;
    QPushButton *reset_settings;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1382, 704);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, 5, -1);
        choose_file_btn = new QPushButton(centralwidget);
        choose_file_btn->setObjectName(QString::fromUtf8("choose_file_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(choose_file_btn->sizePolicy().hasHeightForWidth());
        choose_file_btn->setSizePolicy(sizePolicy);
        choose_file_btn->setMinimumSize(QSize(325, 0));
        QFont font;
        font.setPointSize(11);
        choose_file_btn->setFont(font);

        verticalLayout->addWidget(choose_file_btn);

        info_gp = new QGroupBox(centralwidget);
        info_gp->setObjectName(QString::fromUtf8("info_gp"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(info_gp->sizePolicy().hasHeightForWidth());
        info_gp->setSizePolicy(sizePolicy1);
        info_gp->setMinimumSize(QSize(325, 0));
        info_gp->setFont(font);
        verticalLayout_7 = new QVBoxLayout(info_gp);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        filename_label = new QLabel(info_gp);
        filename_label->setObjectName(QString::fromUtf8("filename_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(filename_label->sizePolicy().hasHeightForWidth());
        filename_label->setSizePolicy(sizePolicy2);
        filename_label->setMinimumSize(QSize(300, 0));

        verticalLayout_7->addWidget(filename_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        edges_info_label = new QLabel(info_gp);
        edges_info_label->setObjectName(QString::fromUtf8("edges_info_label"));

        verticalLayout_4->addWidget(edges_info_label);

        edge_label = new QLabel(info_gp);
        edge_label->setObjectName(QString::fromUtf8("edge_label"));

        verticalLayout_4->addWidget(edge_label);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        vert_info_label = new QLabel(info_gp);
        vert_info_label->setObjectName(QString::fromUtf8("vert_info_label"));

        verticalLayout_3->addWidget(vert_info_label);

        vert_label = new QLabel(info_gp);
        vert_label->setObjectName(QString::fromUtf8("vert_label"));

        verticalLayout_3->addWidget(vert_label);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_7->addLayout(horizontalLayout);


        verticalLayout->addWidget(info_gp);

        move_gb = new QGroupBox(centralwidget);
        move_gb->setObjectName(QString::fromUtf8("move_gb"));
        sizePolicy1.setHeightForWidth(move_gb->sizePolicy().hasHeightForWidth());
        move_gb->setSizePolicy(sizePolicy1);
        move_gb->setMinimumSize(QSize(325, 0));
        move_gb->setFont(font);
        verticalLayout_5 = new QVBoxLayout(move_gb);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_6 = new QLabel(move_gb);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(25, 0));

        horizontalLayout_10->addWidget(label_6);

        x_move_dbl_spinbox = new QDoubleSpinBox(move_gb);
        x_move_dbl_spinbox->setObjectName(QString::fromUtf8("x_move_dbl_spinbox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(x_move_dbl_spinbox->sizePolicy().hasHeightForWidth());
        x_move_dbl_spinbox->setSizePolicy(sizePolicy3);
        x_move_dbl_spinbox->setStyleSheet(QString::fromUtf8(""));
        x_move_dbl_spinbox->setMinimum(-99.000000000000000);

        horizontalLayout_10->addWidget(x_move_dbl_spinbox);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_5 = new QLabel(move_gb);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(25, 0));

        horizontalLayout_9->addWidget(label_5);

        y_move_dbl_spinbox = new QDoubleSpinBox(move_gb);
        y_move_dbl_spinbox->setObjectName(QString::fromUtf8("y_move_dbl_spinbox"));
        sizePolicy3.setHeightForWidth(y_move_dbl_spinbox->sizePolicy().hasHeightForWidth());
        y_move_dbl_spinbox->setSizePolicy(sizePolicy3);
        y_move_dbl_spinbox->setMinimum(-99.000000000000000);

        horizontalLayout_9->addWidget(y_move_dbl_spinbox);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(move_gb);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(25, 0));

        horizontalLayout_2->addWidget(label_4);

        z_move_dbl_spinbox = new QDoubleSpinBox(move_gb);
        z_move_dbl_spinbox->setObjectName(QString::fromUtf8("z_move_dbl_spinbox"));
        sizePolicy3.setHeightForWidth(z_move_dbl_spinbox->sizePolicy().hasHeightForWidth());
        z_move_dbl_spinbox->setSizePolicy(sizePolicy3);
        z_move_dbl_spinbox->setMinimum(-99.000000000000000);

        horizontalLayout_2->addWidget(z_move_dbl_spinbox);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(move_gb);

        rotate_gp = new QGroupBox(centralwidget);
        rotate_gp->setObjectName(QString::fromUtf8("rotate_gp"));
        sizePolicy1.setHeightForWidth(rotate_gp->sizePolicy().hasHeightForWidth());
        rotate_gp->setSizePolicy(sizePolicy1);
        rotate_gp->setMinimumSize(QSize(325, 0));
        rotate_gp->setFont(font);
        verticalLayout_6 = new QVBoxLayout(rotate_gp);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(rotate_gp);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        x_rotation_slider = new QSlider(rotate_gp);
        x_rotation_slider->setObjectName(QString::fromUtf8("x_rotation_slider"));
        sizePolicy.setHeightForWidth(x_rotation_slider->sizePolicy().hasHeightForWidth());
        x_rotation_slider->setSizePolicy(sizePolicy);
        x_rotation_slider->setMinimumSize(QSize(275, 0));
        x_rotation_slider->setMaximum(360);
        x_rotation_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(x_rotation_slider);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(rotate_gp);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_7->addWidget(label_2);

        y_rotation_slider = new QSlider(rotate_gp);
        y_rotation_slider->setObjectName(QString::fromUtf8("y_rotation_slider"));
        sizePolicy.setHeightForWidth(y_rotation_slider->sizePolicy().hasHeightForWidth());
        y_rotation_slider->setSizePolicy(sizePolicy);
        y_rotation_slider->setMinimumSize(QSize(275, 0));
        y_rotation_slider->setMaximum(360);
        y_rotation_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(y_rotation_slider);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(rotate_gp);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_8->addWidget(label_3);

        z_rotation_slider = new QSlider(rotate_gp);
        z_rotation_slider->setObjectName(QString::fromUtf8("z_rotation_slider"));
        sizePolicy.setHeightForWidth(z_rotation_slider->sizePolicy().hasHeightForWidth());
        z_rotation_slider->setSizePolicy(sizePolicy);
        z_rotation_slider->setMinimumSize(QSize(275, 0));
        z_rotation_slider->setMaximum(360);
        z_rotation_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(z_rotation_slider);


        verticalLayout_6->addLayout(horizontalLayout_8);


        verticalLayout->addWidget(rotate_gp);

        scale_gp = new QGroupBox(centralwidget);
        scale_gp->setObjectName(QString::fromUtf8("scale_gp"));
        sizePolicy1.setHeightForWidth(scale_gp->sizePolicy().hasHeightForWidth());
        scale_gp->setSizePolicy(sizePolicy1);
        scale_gp->setMinimumSize(QSize(325, 0));
        scale_gp->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(scale_gp);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scale_slider = new QSlider(scale_gp);
        scale_slider->setObjectName(QString::fromUtf8("scale_slider"));
        scale_slider->setMinimum(-5);
        scale_slider->setMaximum(5);
        scale_slider->setOrientation(Qt::Horizontal);
        scale_slider->setTickPosition(QSlider::TicksAbove);

        horizontalLayout_3->addWidget(scale_slider);


        verticalLayout->addWidget(scale_gp);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addLayout(verticalLayout);

        openGLView = new OpenGLWidget(centralwidget);
        openGLView->setObjectName(QString::fromUtf8("openGLView"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(openGLView->sizePolicy().hasHeightForWidth());
        openGLView->setSizePolicy(sizePolicy4);
        openGLView->setMinimumSize(QSize(500, 400));
        openGLView->setBaseSize(QSize(400, 400));

        horizontalLayout_5->addWidget(openGLView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, -1, -1, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        save_img = new QPushButton(centralwidget);
        save_img->setObjectName(QString::fromUtf8("save_img"));
        sizePolicy.setHeightForWidth(save_img->sizePolicy().hasHeightForWidth());
        save_img->setSizePolicy(sizePolicy);
        save_img->setMinimumSize(QSize(150, 0));
        save_img->setFont(font);

        horizontalLayout_4->addWidget(save_img);

        save_gif = new QPushButton(centralwidget);
        save_gif->setObjectName(QString::fromUtf8("save_gif"));
        sizePolicy.setHeightForWidth(save_gif->sizePolicy().hasHeightForWidth());
        save_gif->setSizePolicy(sizePolicy);
        save_gif->setMinimumSize(QSize(150, 0));
        save_gif->setFont(font);

        horizontalLayout_4->addWidget(save_gif);


        verticalLayout_2->addLayout(horizontalLayout_4);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        groupBox_5->setMinimumSize(QSize(300, 100));
        groupBox_5->setFont(font);
        formLayout_5 = new QFormLayout(groupBox_5);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        bg_color_chooser = new QPushButton(groupBox_5);
        bg_color_chooser->setObjectName(QString::fromUtf8("bg_color_chooser"));
        sizePolicy.setHeightForWidth(bg_color_chooser->sizePolicy().hasHeightForWidth());
        bg_color_chooser->setSizePolicy(sizePolicy);
        bg_color_chooser->setMinimumSize(QSize(100, 25));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, bg_color_chooser);

        proj_type_chooser = new QComboBox(groupBox_5);
        proj_type_chooser->addItem(QString());
        proj_type_chooser->addItem(QString());
        proj_type_chooser->setObjectName(QString::fromUtf8("proj_type_chooser"));
        sizePolicy.setHeightForWidth(proj_type_chooser->sizePolicy().hasHeightForWidth());
        proj_type_chooser->setSizePolicy(sizePolicy);
        proj_type_chooser->setMinimumSize(QSize(100, 25));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, proj_type_chooser);

        bg_color_label = new QLabel(groupBox_5);
        bg_color_label->setObjectName(QString::fromUtf8("bg_color_label"));
        sizePolicy1.setHeightForWidth(bg_color_label->sizePolicy().hasHeightForWidth());
        bg_color_label->setSizePolicy(sizePolicy1);
        bg_color_label->setMinimumSize(QSize(150, 0));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, bg_color_label);

        project_type_label = new QLabel(groupBox_5);
        project_type_label->setObjectName(QString::fromUtf8("project_type_label"));
        sizePolicy1.setHeightForWidth(project_type_label->sizePolicy().hasHeightForWidth());
        project_type_label->setSizePolicy(sizePolicy1);
        project_type_label->setMinimumSize(QSize(150, 0));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, project_type_label);


        verticalLayout_2->addWidget(groupBox_5);

        edges_gb = new QGroupBox(centralwidget);
        edges_gb->setObjectName(QString::fromUtf8("edges_gb"));
        sizePolicy.setHeightForWidth(edges_gb->sizePolicy().hasHeightForWidth());
        edges_gb->setSizePolicy(sizePolicy);
        edges_gb->setMinimumSize(QSize(300, 124));
        edges_gb->setFont(font);
        formLayout = new QFormLayout(edges_gb);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        edges_type_label = new QLabel(edges_gb);
        edges_type_label->setObjectName(QString::fromUtf8("edges_type_label"));
        edges_type_label->setMinimumSize(QSize(75, 25));

        formLayout->setWidget(0, QFormLayout::LabelRole, edges_type_label);

        edge_type_ch = new QComboBox(edges_gb);
        edge_type_ch->addItem(QString());
        edge_type_ch->addItem(QString());
        edge_type_ch->setObjectName(QString::fromUtf8("edge_type_ch"));
        edge_type_ch->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(0, QFormLayout::FieldRole, edge_type_ch);

        edge_color_ch = new QPushButton(edges_gb);
        edge_color_ch->setObjectName(QString::fromUtf8("edge_color_ch"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(edge_color_ch->sizePolicy().hasHeightForWidth());
        edge_color_ch->setSizePolicy(sizePolicy5);
        edge_color_ch->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(1, QFormLayout::FieldRole, edge_color_ch);

        edges_color_label = new QLabel(edges_gb);
        edges_color_label->setObjectName(QString::fromUtf8("edges_color_label"));
        edges_color_label->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(1, QFormLayout::LabelRole, edges_color_label);

        edges_thick_label = new QLabel(edges_gb);
        edges_thick_label->setObjectName(QString::fromUtf8("edges_thick_label"));
        edges_thick_label->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(2, QFormLayout::LabelRole, edges_thick_label);

        edge_thick_ch = new QSlider(edges_gb);
        edge_thick_ch->setObjectName(QString::fromUtf8("edge_thick_ch"));
        edge_thick_ch->setMinimumSize(QSize(0, 25));
        edge_thick_ch->setMinimum(1);
        edge_thick_ch->setMaximum(16);
        edge_thick_ch->setOrientation(Qt::Horizontal);
        edge_thick_ch->setTickInterval(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, edge_thick_ch);


        verticalLayout_2->addWidget(edges_gb);

        vertices_gb = new QGroupBox(centralwidget);
        vertices_gb->setObjectName(QString::fromUtf8("vertices_gb"));
        sizePolicy.setHeightForWidth(vertices_gb->sizePolicy().hasHeightForWidth());
        vertices_gb->setSizePolicy(sizePolicy);
        vertices_gb->setMinimumSize(QSize(300, 124));
        vertices_gb->setFont(font);
        formLayout_2 = new QFormLayout(vertices_gb);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        vert_type_label = new QLabel(vertices_gb);
        vert_type_label->setObjectName(QString::fromUtf8("vert_type_label"));
        vert_type_label->setMinimumSize(QSize(75, 25));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, vert_type_label);

        vert_type_ch = new QComboBox(vertices_gb);
        vert_type_ch->addItem(QString());
        vert_type_ch->addItem(QString());
        vert_type_ch->addItem(QString());
        vert_type_ch->setObjectName(QString::fromUtf8("vert_type_ch"));
        vert_type_ch->setMinimumSize(QSize(0, 25));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, vert_type_ch);

        vert_color_label = new QLabel(vertices_gb);
        vert_color_label->setObjectName(QString::fromUtf8("vert_color_label"));
        vert_color_label->setMinimumSize(QSize(0, 25));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, vert_color_label);

        vert_color_ch = new QPushButton(vertices_gb);
        vert_color_ch->setObjectName(QString::fromUtf8("vert_color_ch"));
        sizePolicy5.setHeightForWidth(vert_color_ch->sizePolicy().hasHeightForWidth());
        vert_color_ch->setSizePolicy(sizePolicy5);
        vert_color_ch->setMinimumSize(QSize(0, 25));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, vert_color_ch);

        vert_size_label = new QLabel(vertices_gb);
        vert_size_label->setObjectName(QString::fromUtf8("vert_size_label"));
        vert_size_label->setMinimumSize(QSize(0, 25));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, vert_size_label);

        vert_size_ch = new QSlider(vertices_gb);
        vert_size_ch->setObjectName(QString::fromUtf8("vert_size_ch"));
        vert_size_ch->setMinimumSize(QSize(0, 25));
        vert_size_ch->setMinimum(1);
        vert_size_ch->setMaximum(16);
        vert_size_ch->setOrientation(Qt::Horizontal);
        vert_size_ch->setTickInterval(1);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, vert_size_ch);


        verticalLayout_2->addWidget(vertices_gb);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        reset_settings = new QPushButton(centralwidget);
        reset_settings->setObjectName(QString::fromUtf8("reset_settings"));
        reset_settings->setFont(font);

        verticalLayout_2->addWidget(reset_settings);


        horizontalLayout_5->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1382, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3DViewer v2.0", nullptr));
        choose_file_btn->setText(QCoreApplication::translate("MainWindow", "Choose file", nullptr));
        info_gp->setTitle(QCoreApplication::translate("MainWindow", "Info:", nullptr));
        filename_label->setText(QCoreApplication::translate("MainWindow", "File name", nullptr));
        edges_info_label->setText(QCoreApplication::translate("MainWindow", "Edges:", nullptr));
        edge_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        vert_info_label->setText(QCoreApplication::translate("MainWindow", "Verticies:", nullptr));
        vert_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        move_gb->setTitle(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Z:", nullptr));
        rotate_gp->setTitle(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Z:", nullptr));
        scale_gp->setTitle(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        save_img->setText(QCoreApplication::translate("MainWindow", "Save image", nullptr));
        save_gif->setText(QCoreApplication::translate("MainWindow", "Save gif", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Other settings", nullptr));
        bg_color_chooser->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        proj_type_chooser->setItemText(0, QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        proj_type_chooser->setItemText(1, QCoreApplication::translate("MainWindow", "Central", nullptr));

        bg_color_label->setText(QCoreApplication::translate("MainWindow", "Background color", nullptr));
        project_type_label->setText(QCoreApplication::translate("MainWindow", "Projection type", nullptr));
        edges_gb->setTitle(QCoreApplication::translate("MainWindow", "Edges settings", nullptr));
        edges_type_label->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        edge_type_ch->setItemText(0, QCoreApplication::translate("MainWindow", "Solid", nullptr));
        edge_type_ch->setItemText(1, QCoreApplication::translate("MainWindow", "Dotted", nullptr));

        edge_color_ch->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        edges_color_label->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        edges_thick_label->setText(QCoreApplication::translate("MainWindow", "Thickness", nullptr));
        vertices_gb->setTitle(QCoreApplication::translate("MainWindow", "Vertices settings", nullptr));
        vert_type_label->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        vert_type_ch->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        vert_type_ch->setItemText(1, QCoreApplication::translate("MainWindow", "Circle", nullptr));
        vert_type_ch->setItemText(2, QCoreApplication::translate("MainWindow", "Square", nullptr));

        vert_color_label->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        vert_color_ch->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        vert_size_label->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        reset_settings->setText(QCoreApplication::translate("MainWindow", "Reset Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
