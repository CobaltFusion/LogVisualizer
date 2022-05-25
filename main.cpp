#include <QtCore>
#include <QtGui>
 
int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
 
   QWidget *mainWindow = new QWidget();
   mainWindow->setMinimumSize(700, 350);
 
   QPushButton *pb = new QPushButton();
   pb->setText("Close");
 
   QHBoxLayout *layout = new QHBoxLayout(mainWindow);
   layout->addWidget(pb);
 
   QObject::connect(pb, &QPushButton::clicked, 
         mainWindow, &QWidget::close);
 
   mainWindow->show();
 
   return app.exec();
}