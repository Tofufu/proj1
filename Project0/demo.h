#ifndef DEMO_H
#define DEMO_H

#include <QMainWindow>
#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>
#include <QJsonDocument>


/// a simple scene
struct Node {
    QString type;
    QVector<Node*> children;
};

struct Model : public Node
{
    QString name;
    QString fileName;
    QMatrix4x4 transform;
};

struct Scene
{
    QString name;
    QString description;
    QVector<Node*> root;
};

#if defined(ENABLE_QTSCRIPT)
class SimpleMath : public QObject
{
    Q_OBJECT

public:
    SimpleMath() {}
    ~SimpleMath() {}

public slots:

    QVector<QVector4D> mult_vec_mat(const QVector<QVector3D> &v, const QMatrix4x4 &mat);
};
#endif

/*!
 * \brief A simple widget to demonstrate Qt widgets
 * 
 */
class Demo : public QMainWindow {
    Q_OBJECT //must be included to add qt meta information
public:
    Demo();
    ~Demo();


     void opengl();
#if defined(ENABLE_QTSCRIPT)
     /*!
      * \brief a demo highlight QtScripting functionality.
      */
    void qtscript();
#endif

    /*!
     * \brief a simple scene json reader and writer
     */
    void scenedemo();
    Model* parseModel(const QJsonObject& model);
    Node* parseNode(const QJsonObject& parentNode) ;
    void scenedemoRead(const QString& filename, QVector<Scene *> &scenes);

    QJsonObject writeNode(Node* node);
    void scenedemoWrite(const QString& filename, QVector<Scene *> &scenes);

};

#endif
