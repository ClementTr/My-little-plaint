/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionPrint;
    QAction *actionMore_colors;
    QAction *actionExport_As_PDF;
    QAction *action_Version;
    QAction *actionCancel_line;
    QAction *actionCancel_rectangle;
    QAction *actionCancel_ellipse;
    QAction *actionCancel_circle;
    QAction *actionClear;
    QAction *actionIncrease_the_thickness;
    QWidget *centralwidget;
    QPushButton *button_blue;
    QPushButton *button_violet;
    QPushButton *button_green;
    QPushButton *button_gray;
    QPushButton *button_orange;
    QPushButton *button_yellow;
    QPushButton *button_brown;
    QPushButton *button_red;
    QPushButton *button_white;
    QPushButton *button_black;
    QPushButton *button_erase;
    QPushButton *button_circle;
    QPushButton *button_pen;
    QPushButton *button_paint;
    QPushButton *button_rectangle;
    QGraphicsView *drawWindow;
    QPushButton *button_write;
    QPushButton *button_line;
    QSlider *slider_thickness;
    QPushButton *button_ok;
    QPlainTextEdit *textEdit;
    QLabel *label_explain;
    QPushButton *button_ellipse;
    QGraphicsView *display_widget;
    QPushButton *button_fullscreen;
    QPushButton *button_cursor;
    QLabel *label_thickness;
    QPushButton *button_cat;
    QLabel *label_undo_line;
    QLabel *label_undo_rectangle;
    QLabel *label_undo_ellipse;
    QLabel *label_undo_circle;
    QLabel *label_undo_text;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(770, 694);
        MainWindow->setMouseTracking(true);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Paint/Icons/save_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Paint/Icons/close_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon1);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Paint/Icons/new_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon2);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Paint/Icons/open_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon3);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Paint/Icons/print_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon4);
        actionMore_colors = new QAction(MainWindow);
        actionMore_colors->setObjectName(QString::fromUtf8("actionMore_colors"));
        actionMore_colors->setCheckable(false);
        actionMore_colors->setEnabled(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Paint/Icons/colors_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMore_colors->setIcon(icon5);
        actionExport_As_PDF = new QAction(MainWindow);
        actionExport_As_PDF->setObjectName(QString::fromUtf8("actionExport_As_PDF"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Paint/Icons/pdf_icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_As_PDF->setIcon(icon6);
        action_Version = new QAction(MainWindow);
        action_Version->setObjectName(QString::fromUtf8("action_Version"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Paint/Icons/about_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Version->setIcon(icon7);
        actionCancel_line = new QAction(MainWindow);
        actionCancel_line->setObjectName(QString::fromUtf8("actionCancel_line"));
        actionCancel_rectangle = new QAction(MainWindow);
        actionCancel_rectangle->setObjectName(QString::fromUtf8("actionCancel_rectangle"));
        actionCancel_ellipse = new QAction(MainWindow);
        actionCancel_ellipse->setObjectName(QString::fromUtf8("actionCancel_ellipse"));
        actionCancel_circle = new QAction(MainWindow);
        actionCancel_circle->setObjectName(QString::fromUtf8("actionCancel_circle"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Paint/Icons/clear_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon8);
        actionIncrease_the_thickness = new QAction(MainWindow);
        actionIncrease_the_thickness->setObjectName(QString::fromUtf8("actionIncrease_the_thickness"));
        actionIncrease_the_thickness->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Paint/Icons/bigger_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIncrease_the_thickness->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        button_blue = new QPushButton(centralwidget);
        button_blue->setObjectName(QString::fromUtf8("button_blue"));
        button_blue->setGeometry(QRect(10, 60, 41, 32));
        button_violet = new QPushButton(centralwidget);
        button_violet->setObjectName(QString::fromUtf8("button_violet"));
        button_violet->setGeometry(QRect(70, 60, 41, 32));
        button_green = new QPushButton(centralwidget);
        button_green->setObjectName(QString::fromUtf8("button_green"));
        button_green->setGeometry(QRect(10, 100, 41, 32));
        button_gray = new QPushButton(centralwidget);
        button_gray->setObjectName(QString::fromUtf8("button_gray"));
        button_gray->setGeometry(QRect(10, 180, 41, 32));
        button_orange = new QPushButton(centralwidget);
        button_orange->setObjectName(QString::fromUtf8("button_orange"));
        button_orange->setGeometry(QRect(70, 140, 41, 32));
        button_yellow = new QPushButton(centralwidget);
        button_yellow->setObjectName(QString::fromUtf8("button_yellow"));
        button_yellow->setGeometry(QRect(70, 100, 41, 32));
        button_brown = new QPushButton(centralwidget);
        button_brown->setObjectName(QString::fromUtf8("button_brown"));
        button_brown->setGeometry(QRect(70, 180, 41, 32));
        button_red = new QPushButton(centralwidget);
        button_red->setObjectName(QString::fromUtf8("button_red"));
        button_red->setGeometry(QRect(10, 140, 41, 32));
        button_white = new QPushButton(centralwidget);
        button_white->setObjectName(QString::fromUtf8("button_white"));
        button_white->setEnabled(true);
        button_white->setGeometry(QRect(70, 220, 41, 32));
        button_black = new QPushButton(centralwidget);
        button_black->setObjectName(QString::fromUtf8("button_black"));
        button_black->setGeometry(QRect(10, 220, 41, 32));
        button_erase = new QPushButton(centralwidget);
        button_erase->setObjectName(QString::fromUtf8("button_erase"));
        button_erase->setGeometry(QRect(10, 430, 41, 32));
        button_circle = new QPushButton(centralwidget);
        button_circle->setObjectName(QString::fromUtf8("button_circle"));
        button_circle->setGeometry(QRect(70, 470, 41, 32));
        button_pen = new QPushButton(centralwidget);
        button_pen->setObjectName(QString::fromUtf8("button_pen"));
        button_pen->setGeometry(QRect(70, 390, 41, 32));
        button_paint = new QPushButton(centralwidget);
        button_paint->setObjectName(QString::fromUtf8("button_paint"));
        button_paint->setGeometry(QRect(70, 550, 41, 32));
        button_paint->setMouseTracking(false);
        button_rectangle = new QPushButton(centralwidget);
        button_rectangle->setObjectName(QString::fromUtf8("button_rectangle"));
        button_rectangle->setGeometry(QRect(10, 470, 41, 32));
        drawWindow = new QGraphicsView(centralwidget);
        drawWindow->setObjectName(QString::fromUtf8("drawWindow"));
        drawWindow->setGeometry(QRect(130, 50, 621, 411));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(drawWindow->sizePolicy().hasHeightForWidth());
        drawWindow->setSizePolicy(sizePolicy);
        drawWindow->setMinimumSize(QSize(431, 291));
        drawWindow->setMidLineWidth(0);
        drawWindow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        drawWindow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        drawWindow->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        drawWindow->setBackgroundBrush(brush);
        drawWindow->setSceneRect(QRectF(0, 0, 0, 0));
        drawWindow->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        button_write = new QPushButton(centralwidget);
        button_write->setObjectName(QString::fromUtf8("button_write"));
        button_write->setGeometry(QRect(70, 430, 41, 32));
        button_line = new QPushButton(centralwidget);
        button_line->setObjectName(QString::fromUtf8("button_line"));
        button_line->setGeometry(QRect(10, 510, 41, 32));
        slider_thickness = new QSlider(centralwidget);
        slider_thickness->setObjectName(QString::fromUtf8("slider_thickness"));
        slider_thickness->setGeometry(QRect(10, 320, 101, 21));
        slider_thickness->setMinimum(1);
        slider_thickness->setMaximum(40);
        slider_thickness->setOrientation(Qt::Horizontal);
        button_ok = new QPushButton(centralwidget);
        button_ok->setObjectName(QString::fromUtf8("button_ok"));
        button_ok->setEnabled(true);
        button_ok->setGeometry(QRect(250, 470, 41, 32));
        textEdit = new QPlainTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(130, 470, 111, 31));
        label_explain = new QLabel(centralwidget);
        label_explain->setObjectName(QString::fromUtf8("label_explain"));
        label_explain->setGeometry(QRect(140, 510, 451, 6));
        QFont font;
        font.setPointSize(8);
        font.setItalic(true);
        label_explain->setFont(font);
        button_ellipse = new QPushButton(centralwidget);
        button_ellipse->setObjectName(QString::fromUtf8("button_ellipse"));
        button_ellipse->setGeometry(QRect(70, 510, 41, 32));
        display_widget = new QGraphicsView(centralwidget);
        display_widget->setObjectName(QString::fromUtf8("display_widget"));
        display_widget->setGeometry(QRect(40, 20, 41, 32));
        display_widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        display_widget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        button_fullscreen = new QPushButton(centralwidget);
        button_fullscreen->setObjectName(QString::fromUtf8("button_fullscreen"));
        button_fullscreen->setGeometry(QRect(700, 470, 41, 32));
        button_cursor = new QPushButton(centralwidget);
        button_cursor->setObjectName(QString::fromUtf8("button_cursor"));
        button_cursor->setGeometry(QRect(10, 390, 41, 32));
        label_thickness = new QLabel(centralwidget);
        label_thickness->setObjectName(QString::fromUtf8("label_thickness"));
        label_thickness->setGeometry(QRect(10, 260, 101, 71));
        label_thickness->setPixmap(QPixmap(QString::fromUtf8(":/Paint/Icons/slider_icon.png")));
        button_cat = new QPushButton(centralwidget);
        button_cat->setObjectName(QString::fromUtf8("button_cat"));
        button_cat->setGeometry(QRect(10, 550, 41, 32));
        label_undo_line = new QLabel(centralwidget);
        label_undo_line->setObjectName(QString::fromUtf8("label_undo_line"));
        label_undo_line->setGeometry(QRect(130, 530, 181, 16));
        label_undo_line->setFont(font);
        label_undo_rectangle = new QLabel(centralwidget);
        label_undo_rectangle->setObjectName(QString::fromUtf8("label_undo_rectangle"));
        label_undo_rectangle->setGeometry(QRect(130, 540, 151, 16));
        label_undo_rectangle->setFont(font);
        label_undo_ellipse = new QLabel(centralwidget);
        label_undo_ellipse->setObjectName(QString::fromUtf8("label_undo_ellipse"));
        label_undo_ellipse->setGeometry(QRect(130, 560, 131, 16));
        label_undo_ellipse->setFont(font);
        label_undo_circle = new QLabel(centralwidget);
        label_undo_circle->setObjectName(QString::fromUtf8("label_undo_circle"));
        label_undo_circle->setGeometry(QRect(130, 550, 151, 16));
        label_undo_circle->setFont(font);
        label_undo_text = new QLabel(centralwidget);
        label_undo_text->setObjectName(QString::fromUtf8("label_undo_text"));
        label_undo_text->setGeometry(QRect(130, 570, 151, 16));
        label_undo_text->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 770, 22));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menubar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuEdition->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFichier->addAction(actionNew);
        menuFichier->addAction(actionOpen);
        menuFichier->addSeparator();
        menuFichier->addAction(actionSave);
        menuFichier->addAction(actionExport_As_PDF);
        menuFichier->addAction(actionPrint);
        menuFichier->addSeparator();
        menuFichier->addAction(actionClose);
        menuEdition->addAction(actionMore_colors);
        menuEdition->addAction(actionIncrease_the_thickness);
        menuEdition->addSeparator();
        menuEdition->addAction(actionClear);
        menuHelp->addAction(action_Version);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Paint", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
        actionMore_colors->setText(QApplication::translate("MainWindow", "More colors", 0, QApplication::UnicodeUTF8));
        actionExport_As_PDF->setText(QApplication::translate("MainWindow", "Export As PDF", 0, QApplication::UnicodeUTF8));
        action_Version->setText(QApplication::translate("MainWindow", "Version", 0, QApplication::UnicodeUTF8));
        actionCancel_line->setText(QApplication::translate("MainWindow", "Cancel line", 0, QApplication::UnicodeUTF8));
        actionCancel_rectangle->setText(QApplication::translate("MainWindow", "Cancel rectangle", 0, QApplication::UnicodeUTF8));
        actionCancel_ellipse->setText(QApplication::translate("MainWindow", "Cancel ellipse", 0, QApplication::UnicodeUTF8));
        actionCancel_circle->setText(QApplication::translate("MainWindow", "Cancel circle", 0, QApplication::UnicodeUTF8));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        actionIncrease_the_thickness->setText(QApplication::translate("MainWindow", "Increase the thickness", 0, QApplication::UnicodeUTF8));
        button_blue->setText(QString());
        button_violet->setText(QString());
        button_green->setText(QString());
        button_gray->setText(QString());
        button_orange->setText(QString());
        button_yellow->setText(QString());
        button_brown->setText(QString());
        button_red->setText(QString());
        button_white->setText(QString());
        button_black->setText(QString());
        button_erase->setText(QString());
        button_circle->setText(QString());
        button_pen->setText(QString());
        button_paint->setText(QString());
        button_rectangle->setText(QString());
        button_write->setText(QString());
        button_line->setText(QString());
        button_ok->setText(QApplication::translate("MainWindow", "OK", 0, QApplication::UnicodeUTF8));
        label_explain->setText(QApplication::translate("MainWindow", "Please click on OK and put the mouse where you want to see your text", 0, QApplication::UnicodeUTF8));
        button_ellipse->setText(QString());
        button_fullscreen->setText(QString());
        button_cursor->setText(QString());
        label_thickness->setText(QString());
        button_cat->setText(QString());
        label_undo_line->setText(QApplication::translate("MainWindow", "Press L: undo line", 0, QApplication::UnicodeUTF8));
        label_undo_rectangle->setText(QApplication::translate("MainWindow", "Press R: undo rectangle", 0, QApplication::UnicodeUTF8));
        label_undo_ellipse->setText(QApplication::translate("MainWindow", "Press E: undo ellipse", 0, QApplication::UnicodeUTF8));
        label_undo_circle->setText(QApplication::translate("MainWindow", "Press C: undo circle", 0, QApplication::UnicodeUTF8));
        label_undo_text->setText(QApplication::translate("MainWindow", "Press T: undo text", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
