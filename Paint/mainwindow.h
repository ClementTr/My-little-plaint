#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QtWidgets>
#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPixmap>
#include <QPoint>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QPen>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include <QGraphicsEllipseItem>
#include "scene.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Scene *scene;  /* Create a scene (type Scene) included in our MainWindow */
    Scene *indicator; /* Create an indicator (type Scene) in our MainWindow displaying which color is selected */
    QGraphicsView view; /* Create a view, will be used in mainwindow.cpp in the fullscreen mode function */
    static QColor color_text; /* Create a color of type QColor will be used to conserve the color selected by the user in moreColors function */
    void buttonisEnabled(); /*Employed to be easier/faster for developer because used in each mode button*/
    void buttonisVisible(); /*Employed to be easier/faster for developer because used in each mode button*/


private:
    Ui::MainWindow *ui;
    QPixmap image;
    QWidget *widget;
    QLabel *version;
    QLabel *creator;

protected:
    void closeEvent (QCloseEvent *event);

private slots:

    /* ------------------------------------------------------------------- *
     * ---------------------- COLOR BUTTONS FUNCTIONS -------------------- *
     * ------------------------------------------------------------------- */

    void on_button_green_clicked();
    void on_button_red_clicked();
    void on_button_blue_clicked();
    void on_button_violet_clicked();
    void on_button_yellow_clicked();
    void on_button_orange_clicked();
    void on_button_gray_clicked();
    void on_button_brown_clicked();
    void on_button_black_clicked();
    void on_button_white_clicked();
    void on_button_erase_clicked();

    /* ------------------------------------------------------------------- *
     * ---------------------- SLIDER FUNCTIONS --------------------------- *
     * ------------------------------------------------------------------- */

    void on_slider_thickness_sliderMoved(int position);
    void on_slider_thickness_valueChanged(int value);


    /* ------------------------------------------------------------------- *
     * ---------------------- MODE BUTTONS FUNCTIONS --------------------- *
     * ------------------------------------------------------------------- */

    void on_button_paint_clicked();
    void on_button_pen_clicked();
    void on_button_circle_clicked();
    void on_button_rectangle_clicked();
    void on_button_line_clicked();
    void on_button_write_clicked();
    void on_button_ellipse_clicked();
    void on_button_ok_clicked();
    void on_button_fullscreen_clicked();
    void on_button_cursor_clicked();
    void on_button_cat_clicked();

    /* ------------------------------------------------------------------- *
     * ---------------------- MENU BUTTONS FUNCTIONS --------------------- *
     * ------------------------------------------------------------------- */

    /* ----------------------- *
     * ------- 1/ FILE ------- *
     * ----------------------- */

    void on_actionNew_triggered();
    void on_actionClose_triggered();
    void on_actionSave_triggered();
    void on_actionPrint_triggered();
    void on_actionOpen_triggered();
    void on_actionExport_As_PDF_triggered();

    /* ----------------------- *
     * ------- 2/ EDIT ------- *
     * ----------------------- */

    void on_actionMore_colors_triggered();
    void on_actionIncrease_the_thickness_toggled(bool check);
    void on_actionClear_triggered();

    /* ----------------------- *
     * ------- 3/ HELP ------- *
     * ----------------------- */

    void on_action_Version_triggered();
};



#endif // MAINWINDOW_H
