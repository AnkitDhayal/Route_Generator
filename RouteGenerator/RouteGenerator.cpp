#include "stdafx.h"
#include "RouteGenerator.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include <Pipe.h>
#include <Transformations.h>

RouteGenerator::RouteGenerator(QWidget* parent)
    : QMainWindow(parent)
{
    setupUi();
    connect(pushButton_2, &QPushButton::clicked, this, &RouteGenerator::readOBJ);
    connect(pushButton_4, &QPushButton::clicked, this, &RouteGenerator::UpperMove);
    connect(pushButton_3, &QPushButton::clicked, this, &RouteGenerator::DownMove);
    connect(pushButton, &QPushButton::clicked, this, &RouteGenerator::LeftMove);
    connect(pushButton5, &QPushButton::clicked, this, &RouteGenerator::RightMove);
    connect(pushButton6, &QPushButton::clicked, this, &RouteGenerator::stop);

    connect(mRenderer, SIGNAL(shapeUpdate()), mRenderer, SLOT(update()));
}

RouteGenerator::~RouteGenerator()
{}
void RouteGenerator::setupUi()
{

    resize(944, 895);
    centralWidget = new QWidget(this);
    centralWidget->setObjectName("centralWidget");
    gridLayoutWidget = new QWidget(centralWidget);
    gridLayoutWidget->setObjectName("gridLayoutWidget");
    gridLayoutWidget->setGeometry(QRect(-1, -1, 1541, 800));
    gridLayout_2 = new QGridLayout(gridLayoutWidget);
    gridLayout_2->setSpacing(6);
    gridLayout_2->setContentsMargins(11, 11, 11, 11);
    gridLayout_2->setObjectName("gridLayout_2");
    gridLayout_2->setContentsMargins(0, 0, 0, 0);
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setObjectName("verticalLayout_2");
    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setObjectName("openGLWidget");
    verticalLayout_2->addWidget(mRenderer, 3);

    gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

    horizontalLayoutWidget = new QWidget(centralWidget);
    horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
    horizontalLayoutWidget->setGeometry(QRect(0, 360, 541, 1000));
    horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
    horizontalLayout_3->setSpacing(6);
    horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
    horizontalLayout_3->setObjectName("horizontalLayout_3");
    horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setSpacing(6);
    horizontalLayout_4->setObjectName("horizontalLayout_4");
    pushButton_2 = new QPushButton(horizontalLayoutWidget);
    pushButton_2->setObjectName("pushButton_2");
    pushButton_2->setText("Start");

    horizontalLayout_4->addWidget(pushButton_2);

    pushButton_4 = new QPushButton(horizontalLayoutWidget);
    pushButton_4->setObjectName("pushButton_4");
    pushButton_4->setText("Up");
    horizontalLayout_4->addWidget(pushButton_4);

    pushButton_3 = new QPushButton(horizontalLayoutWidget);
    pushButton_3->setObjectName("pushButton_3");
    pushButton_3->setText("Down");
    horizontalLayout_4->addWidget(pushButton_3);

    pushButton = new QPushButton(horizontalLayoutWidget);
    pushButton->setObjectName("pushButton");
    pushButton->setText("Left");
    horizontalLayout_4->addWidget(pushButton);
    pushButton5 = new QPushButton(horizontalLayoutWidget);
    pushButton5->setObjectName("pushButton");
    pushButton5->setText("Right");
    horizontalLayout_4->addWidget(pushButton5);





    horizontalLayout_3->addLayout(horizontalLayout_4);

    setCentralWidget(centralWidget);
    menuBar = new QMenuBar(this);
    menuBar->setObjectName("menuBar");
    menuBar->setGeometry(QRect(0, 0, 644, 22));
    setMenuBar(menuBar);
    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName("mainToolBar");
    addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(this);
    statusBar->setObjectName("statusBar");
    setStatusBar(statusBar);

    QMetaObject::connectSlotsByName(this);
}
void RouteGenerator::sceneStatic() {
    std::vector<float> vertices;
    std::vector<float> color;
    //Grid grid(vertices, color, 8);

    for (int i = 0; i < vertices.size(); i += 3) {
        mVertices << vertices[i] << vertices[i + 1] << vertices[i + 2];
        mColors << 1 << 0 << 1;
    }


    mVertices.clear();
    mColors.clear();
    std::vector<float>PipeVertices;
    std::vector<float>PipeColor;
    PipeVertices.push_back(-1);
   

    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);
    mVertices.clear();
    mColors.clear();
}
void RouteGenerator::readOBJ() {

    std::string filePath = "D:\\Ankit_Workspace\\Cube.obj";
    std::ifstream dataFile;
    dataFile.open(filePath);
    if (!dataFile.is_open()) {
        std::cout << "File not exit" << std::endl;
        return;
    }
    std::vector<float> objVertices;
    std::vector<float> objColors;
    std::string line;
    while (std::getline(dataFile, line)) {
        std::istringstream iss(line);
        std::string token;
        iss >> token;
        if (token == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            Point3D p(x, y, z);
            mPoints.push_back(p);
            objColors.push_back(1.0);
            objColors.push_back(1.0);
            objColors.push_back(1.0);

        }
    }
   
    for (int i = 0; i < mPoints.size(); i++) {
        mVertices << 0.1*mPoints[i].X() << 0.1*mPoints[i].Y() << 0.1*mPoints[i].Z();
       
    }
    for (int i = 0; i < objColors.size(); i+=3) {
        mColors << 1.0 << 1.0 << 1.0;
    }
    
    objColors.clear();
    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);



}
void RouteGenerator::LeftMove() {
    

    float scaleFactor = 0.3;

    for (int i = 0; i < mVertices.size(); i += 3) {
        // Apply scaling to each coordinate
        mVertices[i] -= scaleFactor;
    }

    mRenderer->setVectorOfLines(mVertices);
}

void RouteGenerator::RightMove() {
    // You can adjust the scaling factor as needed
    float scaleFactor = 0.3;

    for (int i = 0; i < mVertices.size(); i += 3) {
        // Apply scaling to each coordinate
        mVertices[i] += scaleFactor;
    }

    mRenderer->setVectorOfLines(mVertices);

}




void RouteGenerator::UpperMove() {
    // You can adjust the scaling factor as needed
    float scaleFactor = 0.3;

    for (int i = 0; i < mVertices.size(); i += 3) {
        // Apply scaling to each coordinate
        mVertices[i + 1] += scaleFactor;
    }

    mRenderer->setVectorOfLines(mVertices);

}

void RouteGenerator::DownMove() {
    // You can adjust the scaling factor as needed
  
    float scaleFactor = 0.3 ;

    for (int i = 0; i < mVertices.size(); i += 3) {
        // Apply scaling to each coordinate
        mVertices[i + 1] -= scaleFactor;
    }

    mRenderer->setVectorOfLines(mVertices);

}

void RouteGenerator::stop() {
    mVertices.clear();
    mColors.clear();
    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);
}