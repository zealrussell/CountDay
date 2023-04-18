#include "widget.h"
#include <QApplication>
#include <QScreen>


/**
 *
 * by
 * zealllllllllll
 *
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("clock ");
    w.setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);//去掉标题栏
    // w.setAttribute(Qt::WA_TranslucentBackground);//设置透明-窗体标题栏不透明,背景透明
    // 显示在最前面
    w.setWindowFlags(w.windowFlags() | Qt::WindowStaysOnTopHint);
    w.setStyleSheet("background-color:black;");
   // QDesktopWidget* desktop=QApplication::desktop();//获取屏幕尺寸

    // w.move((desktop->width() - w.width()),(desktop->height() - w.height())*0.9);//移到右下角
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    // double devicePixelRatio = QGuiApplication::primaryScreen()->devicePixelRatio();
    // int width = screenRect.width();
    // int height = screenRect.height();
    w.move(screenRect.left(), screenRect.top());
    w.show();
    return a.exec();
}
