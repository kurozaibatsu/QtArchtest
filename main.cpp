#include <QApplication>
#include "archtest.h"
#include <QtWidgets>

int main(int argc, char *argv[]){

    QApplication app(argc, argv);
      QWidget window;
      window.resize(240, 40);
      window.setWindowTitle
            (QApplication::translate("childwidget", "Archtest"));
      window.show();

      QLabel *label = new QLabel(QApplication::translate("childwidget", "Fehler"), &window);
      uint8_t string[64];
      if(argc>1){
      archtest(argv[1], 64, string);
      QString qString = QString::fromUtf8((char*)string);
      label->setText(qString);
      }
      label->setStyleSheet("font: 14pt;");
      label->show();
      return app.exec();
}
