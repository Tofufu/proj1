#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include "openglwindow.h"
#include "tiny_obj_loader.h"

#include <QWidget>
#include <QtWidgets>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QSlider>

class QOpenGLShaderProgram;
class QOpenGLBuffer;
class QOpenGLVertexArrayObject;

class QSlider; //allows us to have QSliders!


class RenderWindow : public OpenGLWindow
{
public:
    RenderWindow();

    void initialize();
    void render();
    void checkError(const QString& prefix);

private:

    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    QOpenGLShaderProgram *m_program;
    QOpenGLVertexArrayObject* m_vao;
    QOpenGLBuffer *m_vbo;
    QOpenGLBuffer *m_ibo;
    int m_frame;
    bool m_useSourceCode;

  //  void load_obj(const char* filename, vector<glm::vec4> &vertices, vector<glm::vec3> &normals, vector<GLushort> &elements);

private slots:
  //void fileDialogOpened();
};

class RenderWindowWidget : public QWidget
{

public:
 // RenderWindowWidget(QWidget* parent): QWidget(parent) {

      //renWin = new RenderWindow();

     /* QWidget* widget = QWidget::createWindowContainer(renWin);
      QHBoxLayout* layout = new QHBoxLayout(this);

      layout->addWidget(widget);


      QPushButton *OpeningFileButton = new QPushButton("Open File");
      QPushButton *OpeningObjectButton = new QPushButton("Add Object File");


     // QObject::connect(OpeningFileButton, SIGNAL(clicked()), this, SLOT(fileDialogOpened()));
      QVBoxLayout *ButtonLayout = new QVBoxLayout; //Lines up Vertically
      ButtonLayout->addWidget(OpeningFileButton);
      ButtonLayout->addWidget(OpeningObjectButton);

      layout->addLayout(ButtonLayout);*/
 // }
  RenderWindowWidget(QWidget* parent); //constructor

  RenderWindow* GetRenderWindow() {
      return renWin;
  }
private slots:
  //void fileDialogOpened(); <-- need to redo this!
private:
  RenderWindow* renWin;

  QSlider *createSlider();

  QSlider *xSlider;
  QSlider *ySlider;
  QSlider *zSlider;


};

#endif // RENDERWINDOW_H
