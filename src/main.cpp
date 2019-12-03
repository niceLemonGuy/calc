#include <QApplication>
#include "mywindow.h"
#include <QDesktopWidget>


int main(int argc, char **argv)
{
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("sqldrivers");
    QCoreApplication::setLibraryPaths(paths);

    QApplication a(argc, argv);

    MyWindow *w = new MyWindow();
    //w->showMinimized();
    w->showMaximized();
    w->setFixedSize(250,250);
    //w->move(QApplication::desktop()->screen()->rect().center() - w->rect().center());
    w->show();

    return a.exec();
}
