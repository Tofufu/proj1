#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>

#include <vector>
#include <string>
#include <iostream>

#include "demo.h"

#include <getopt.h>


int main(int argc, char* argv[]) {


  QApplication app(argc, argv);


  Demo demo;
  demo.resize(400,400);
    demo.opengl();
  demo.show();

  return app.exec();
}
