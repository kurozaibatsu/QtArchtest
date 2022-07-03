#include <QApplication>
#include "archtest.h"
#include <QtWidgets>

int main(int argc, char *argv[]){

    QApplication app(argc, argv);
      QWidget window;
      window.resize(240, 40);
      window.setWindowTitle
            (QApplication::translate("childwidget", "Archtest"));
      QVBoxLayout *layout = new QVBoxLayout();
      layout->setSpacing(0);
      layout->setContentsMargins(0, 0, 0, 0);
      window.setLayout(layout);
      window.show();

      QPushButton *button = new QPushButton("&No file selected");
      layout->addWidget(button);
      uint8_t string[64];
      if(argc>1){
      archtest(argv[1], 64, string);
      QString qString = QString::fromUtf8((char*)string);
      button->setText(qString);
      }
      button->setStyleSheet("font: 14pt;");
      QObject::connect(button, SIGNAL (clicked()), &app, SLOT (quit()));

      button->show();
      return app.exec();
}
