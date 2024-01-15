#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RouteGenerator.h"
#include "OpenGLWindow.h"
#include <Point3D.h>

class RouteGenerator : public QMainWindow
{
    Q_OBJECT

public:
    RouteGenerator(QWidget* parent = nullptr);
    ~RouteGenerator();
    void setupUi();

private slots:
    void readOBJ();
    void sceneStatic();
    void UpperMove();
   
    void DownMove();
    void LeftMove();
    void RightMove();
    void stop();

private:
    //Ui::RouteGeneratorClass ui;

    OpenGLWindow* mRenderer;
    QWidget* centralWidget;
    QWidget* gridLayoutWidget;
    QGridLayout* gridLayout_2;
    QVBoxLayout* verticalLayout_2;
    QOpenGLWidget* openGLWidget;
    QWidget* horizontalLayoutWidget;
    QHBoxLayout* horizontalLayout_3;
    QHBoxLayout* horizontalLayout_4;
    QPushButton* pushButton_2;
    QPushButton* pushButton_4;
    QPushButton* pushButton_3;
    QPushButton* pushButton;
    QPushButton* pushButton5,* pushButton6;
    QMenuBar* menuBar;
    QToolBar* mainToolBar;
    QStatusBar* statusBar;
    std::vector<Point3D> mPoints;
    QVector<GLfloat> mVertices;
    QVector<GLfloat> mColors;
    std::vector<Point3D> translatedPoints;
};
