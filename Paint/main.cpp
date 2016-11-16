#include "mainwindow.h"


/* --------------------------------------------------- *
 * --------------------- MAIN.CPP -------------------- *
 * --------------------------------------------------- */

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow fenetre;
/*
 * We create a Qpixmap object, pix_main which is an image located in the ressource file,
 * it will be the icon of the application thanks to setWindowIcon `
*/
    QPixmap pix_main(":/Paint/Icons/myPaint_icon.png");
    fenetre.setWindowIcon(pix_main);
    fenetre.show();

    return app.exec();
}
