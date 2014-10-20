#ifndef DEMO_H
#define DEMO_H

#include <QMainWindow>
#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>
#include <QJsonDocument>



class Demo : public QMainWindow {
    Q_OBJECT //must be included to add qt meta information
public:
    Demo();
    ~Demo();


     void opengl();

};

#endif
