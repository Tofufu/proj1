#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include "openglwindow.h"

#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>

class QOpenGLShaderProgram;
class QOpenGLBuffer;
class QOpenGLVertexArrayObject;

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
};

class RenderWindowWidget : public QWidget
{
public:
  RenderWindowWidget(QWidget* parent): QWidget(parent) {

      renWin = new RenderWindow();

      QWidget* widget = QWidget::createWindowContainer(renWin);
      QHBoxLayout* layout = new QHBoxLayout(this);

      layout->addWidget(widget);
  }

  RenderWindow* GetRenderWindow() {
      return renWin;
  }

private:
  RenderWindow* renWin;
};

#endif // RENDERWINDOW_H
