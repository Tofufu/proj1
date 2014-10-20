#include "demo.h"

#include <QPushButton>
#include <QFileDialog>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#if defined(ENABLE_QTSCRIPT)
#include <QtScript>
#include <QScriptEngine>
#endif

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include "renderwindow.h"
#include "dialog.h"


Demo::Demo() {
}


Demo::~Demo() {
}

void
Demo::opengl() {
    RenderWindowWidget* widget = new RenderWindowWidget(this);
    setCentralWidget(widget);
}

