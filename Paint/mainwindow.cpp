#include "mainwindow.h"
#include "scene.h"
#include "ui_mainwindow.h"


/*  ------------------------------------------------------------------  *
 *  --------------------------- CONSTRUCTOR --------------------------- *
 *  ------------------------------------------------------------------  */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*
 * Selection of the buttons colors for the buttons which help the user to select a color.
*/

    ui->button_blue->setStyleSheet("background-color: blue;");
    ui->button_violet->setStyleSheet("background-color: violet;");
    ui->button_green->setStyleSheet("background-color: green;");
    ui->button_yellow->setStyleSheet("background-color: yellow;");
    ui->button_red->setStyleSheet("background-color: red;");
    ui->button_orange->setStyleSheet("background-color: orange;");
    ui->button_gray->setStyleSheet("background-color: gray;");
    ui->button_brown->setStyleSheet("background-color: brown;");
    ui->button_black->setStyleSheet("background-color: black;");
    ui->button_white->setStyleSheet("background-color: white;");
    ui->drawWindow->setStyleSheet("background-color: white;");

/*
 * Initialisation of the default interface (the interface which appears when we run the application)
 * Some buttons are visible and other are not thanks to the command setVisible(false).
 * When running the application the cursor button is pushed thanks to setEnabled(false).
 * The default cursor is of ArowCursor type.
*/

    ui->button_cursor->setEnabled(false);
    ui->button_ok->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->label_explain->setVisible(false);
    ui->button_fullscreen->setVisible(false);
    QApplication::setOverrideCursor(Qt::ArrowCursor);

/*
 * Creation of the scene this is where the user is going to draw,
 * it is a QGraphicsView type.
*/

    scene = new Scene (this);
    ui->drawWindow->setScene(scene);
    scene->setSceneRect(-150,-150,300,300);

/*
 * Creation of the indicator, it shows to the user the color selected.
 * The default color is Black so we initialise the indicator in black.
*/

    indicator = new Scene (this);
    ui->display_widget->setScene(indicator);
    indicator->addRect(10,0,50,50,QPen(Qt::black),QBrush(Qt::black));

/*
 * Initialization of our static variables, (accessible from the Scene class)
 * it is the default values
*/

    Scene :: button_pressed = 8;
    Scene :: color_around_pen = QPen(Qt::black);
    Scene :: color_pen = QBrush(Qt::black);
    Scene :: thickness = 1;
    Scene :: edit = "";
    Scene :: save = false;

/*
 * The following lines are for linking each button to an icon located in the ressource file
 * We use create a Qpixmap for each icon, and we link it to the button with setIcon command.
*/

    QPixmap pix_pen(":/Paint/Icons/pen_icon.png");
    ui->button_pen->setIcon(pix_pen);

    QPixmap pix_paint(":/Paint/Icons/paint_icon.png");
    ui->button_paint->setIcon(pix_paint);

    QPixmap pix_erase(":/Paint/Icons/erase_icon.png");
    ui->button_erase->setIcon(pix_erase);

    QPixmap pix_line(":/Paint/Icons/line_icon.png");
    ui->button_line->setIcon(pix_line);

    QPixmap pix_rectangle(":/Paint/Icons/rectangle_icon.png");
    ui->button_rectangle->setIcon(pix_rectangle);

    QPixmap pix_circle(":/Paint/Icons/circle_icon.png");
    ui->button_circle->setIcon(pix_circle);

    QPixmap pix_ellipse(":/Paint/Icons/ellispe_icon.png");
    ui->button_ellipse->setIcon(pix_ellipse);

    QPixmap pix_write(":/Paint/Icons/write_icon.png");
    ui->button_write->setIcon(pix_write);

    QPixmap pix_fullscreen(":/Paint/Icons/fullscreen_icon.png");
    ui->button_fullscreen->setIcon(pix_fullscreen);

    QPixmap pix_cursor(":/Paint/Icons/cursor_icon.png");
    ui->button_cursor->setIcon(pix_cursor);

    QPixmap pix_cat(":/Paint/Icons/cat_icon.png");
    ui->button_cat->setIcon(pix_cat);

}



/*  ------------------------------------------------------------------  *
 *  -------------------------- DESTRUCTOR ----------------------------- *
 *  ------------------------------------------------------------------  */

/* Destruction of the dynamics values created during the execution*/

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete indicator;
    delete widget;
    delete version;
    delete creator;
}





/* ------------------------------------------------------------------- *
 * ------------------- COLOR BUTTONS FUNCTIONS ----------------------- *
 * ------------------------------------------------------------------- */

/* We have to declare a static value like this, out of a function */

QPen Scene :: color_around_pen = QPen(Qt::black);
QBrush Scene :: color_pen = QBrush(Qt::black);

/*
 * Each function for applying a color on the pen and the indicator is basically the same,
 * We create a QColor for each color which doesn't exist in QPen, with it's RGB cordinates
 * We put the wanted color on the color_around_pen, color_pen and color_text variable.
 * The user can now draw or write with the desirated color.
 * Finally we put the wanted color in the indicator by adding a Rectangle of it's dimension in it.
*/

void MainWindow::on_button_green_clicked()
{
    QColor green (0,128,0);
    Scene::color_around_pen=QPen(green);
    Scene::color_pen=QBrush(green);
    color_text=green;
    indicator->addRect(10,0,50,50,green,green);
}

void MainWindow::on_button_red_clicked()
{
    Scene::color_around_pen=QPen(Qt::red);
    Scene::color_pen=QBrush(Qt::red);
    color_text=Qt::red;
    indicator->addRect(10,0,50,50,QPen(Qt::red),QBrush(Qt::red));
}

void MainWindow::on_button_blue_clicked()
{
    Scene::color_around_pen=QPen(Qt::blue);
    Scene::color_pen=QBrush(Qt::blue);
    color_text=Qt::blue;
    indicator->addRect(10,0,50,50,QPen(Qt::blue),QBrush(Qt::blue));
}

void MainWindow::on_button_violet_clicked()
{
    QColor violet(238,130,238);
    Scene::color_around_pen=QPen(violet);
    Scene::color_pen=QBrush(violet);
    color_text=violet;
    indicator->addRect(10,0,50,50,violet,violet);
}

void MainWindow::on_button_yellow_clicked()
{
    Scene::color_around_pen=QPen(Qt::yellow);
    Scene::color_pen=QBrush(Qt::yellow);
    color_text=Qt::yellow;
    indicator->addRect(10,0,50,50,QPen(Qt::yellow),QBrush(Qt::yellow));
}

void MainWindow::on_button_orange_clicked()
{
    QColor orange(255,165,0);
    Scene::color_around_pen=QPen(orange);
    Scene::color_pen=QBrush(orange);
    color_text=orange;
    indicator->addRect(10,0,50,50,orange,orange);
}

void MainWindow::on_button_gray_clicked()
{
    Scene::color_around_pen=QPen(Qt::gray);
    Scene::color_pen=QBrush(Qt::gray);
    color_text=Qt::gray;
    indicator->addRect(10,0,50,50,QPen(Qt::gray),QBrush(Qt::gray));
}

void MainWindow::on_button_brown_clicked()
{
    QColor brown(165,42,42);
    Scene::color_around_pen=QPen(brown);
    Scene::color_pen=QBrush(brown);
    color_text=brown;
    indicator->addRect(10,0,50,50,brown,brown);
}

void MainWindow::on_button_black_clicked()
{
    Scene::color_around_pen=QPen(Qt::black);
    Scene::color_pen=QBrush(Qt::black);
    color_text=Qt::black;
    indicator->addRect(10,0,50,50,QPen(Qt::black),QBrush(Qt::black));
}

void MainWindow::on_button_white_clicked()
{
    Scene::color_around_pen=QPen(Qt::white);
    Scene::color_pen=QBrush(Qt::white);
    color_text=Qt::white;
    indicator->addRect(10,0,50,50,QPen(Qt::white),QBrush(Qt::white));
}



/* ------------------------------------------------------------------  *
 * ------------------ SLIDER THICKNESS FUNCTIONS --------------------- *
 * ------------------------------------------------------------------- */


/* We have to declare a static value like this, out of the function */

int Scene :: thickness=1;

/*
 * The thickness variable will take the position of the slider value in case the user slides the slider.
 * In case the user directly click to move the slider, the thickness variable will take the value of the slider.
*/

void MainWindow::on_slider_thickness_sliderMoved(int position)
{
    Scene::thickness=position;
}

void MainWindow::on_slider_thickness_valueChanged(int value)
{   
    Scene::thickness=value;
}





/* ------------------------------------------------------------------  *
 * ------------------------- MODE FUNCTIONS -------------------------- *
 * ------------------------------------------------------------------- */

/* We have to declare a static value like this, out of the function */

int Scene :: button_pressed=0;

/*
 * Once again each function is basically the same:
 * For each one we choose the button (depending on what the user clicked) which will not be enabled (all the other ones are Enabled)
 * For that we use the setEnabled() function
 * Some other buttons, depending on what the user clicked have to be visible or not, and for that we use the setVisible() function
 * We associate to each button a cursor with the QApplication::setOverrideCursor(...) line
 * Finally for each button we associate a different value of button_pressed (from 0 to 8)
 * This will be used in the scene.cpp file to write each button's code.
*/

void MainWindow::buttonisEnabled()
{
    ui->button_paint->setEnabled(true);
    ui->button_pen->setEnabled(true);
    ui->button_circle->setEnabled(true);
    ui->button_rectangle->setEnabled(true);
    ui->button_line->setEnabled(true);
    ui->button_write->setEnabled(true);
    ui->button_erase->setEnabled(true);
    ui->button_ellipse->setEnabled(true);
    ui->button_cursor->setEnabled(true);
    ui->actionMore_colors->setEnabled(true);
}

void MainWindow::buttonisVisible()
{
    ui->button_ok->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->label_explain->setVisible(false);
}

void MainWindow::on_button_pen_clicked()
{
    buttonisEnabled();
    buttonisVisible();
    ui->button_pen->setEnabled(false);
    QApplication::setOverrideCursor(Qt::CrossCursor);

    Scene::button_pressed=0;
}

void MainWindow::on_button_paint_clicked()
{
    buttonisEnabled();
    buttonisVisible();
    ui->button_paint->setEnabled(false);
    QApplication::setOverrideCursor(Qt::PointingHandCursor);

    Scene::button_pressed=1;
}

void MainWindow::on_button_circle_clicked()
{
    buttonisEnabled();
    buttonisVisible();
    ui->button_circle->setEnabled(false);
    QApplication::setOverrideCursor(Qt::OpenHandCursor);

    Scene::button_pressed=2;
}

void MainWindow::on_button_rectangle_clicked()
{
    buttonisEnabled();
    buttonisVisible();
    ui->button_rectangle->setEnabled(false);
    QApplication::setOverrideCursor(Qt::OpenHandCursor);

    Scene::button_pressed=3;
}

void MainWindow::on_button_line_clicked()
{
    buttonisEnabled();
    buttonisVisible();
    ui->button_line->setEnabled(false);
    QApplication::setOverrideCursor(Qt::OpenHandCursor);

    Scene::button_pressed=4;
}

void MainWindow::on_button_write_clicked()
{
    buttonisEnabled();
    ui->button_write->setEnabled(false);
    ui->button_ok->setVisible(true);
    ui->textEdit->setVisible(true);
    ui->label_explain->setVisible(true);
    QApplication::setOverrideCursor(Qt::ArrowCursor);

    Scene::button_pressed=5;
}

void MainWindow::on_button_ellipse_clicked()
{
    buttonisEnabled();
    buttonisVisible();
    ui->button_ellipse->setEnabled(false);
    QApplication::setOverrideCursor(Qt::OpenHandCursor);

    Scene::button_pressed=6;
}

void MainWindow::on_button_cursor_clicked()
{
    buttonisEnabled();
    buttonisVisible();
    ui->button_cursor->setEnabled(false);
    QApplication::setOverrideCursor(Qt::ArrowCursor);

    Scene::button_pressed=7;
}

void MainWindow::on_button_erase_clicked()
{
    buttonisEnabled();
    buttonisVisible();
    ui->button_erase->setEnabled(false);
    QApplication::setOverrideCursor(Qt::PointingHandCursor);

    Scene::button_pressed=8;
}


/*
 * BUTTON FULLSCREEN FUNCTION
 * This function is linked to the fullscreen button enabled only if you open an image.
 * By clicking on this button, you will create a new window "view" displaying what appears on the scene.
 * We use a layout to addapt the image to our view and a widget using the layout to resize as we want the window
 * and of course put it in fullscreen
*/

void MainWindow::on_button_fullscreen_clicked()
{
    QLayout * layout = new QVBoxLayout();
    QGraphicsView * view = new QGraphicsView(scene);
    layout->addWidget(view);
    QWidget * widget = new QWidget();
    widget->setLayout(layout);
    widget->adjustSize();
    widget->showFullScreen();
}

/*
 * BUTTON CAT FUNCTION
 * This is a function that allows us to upload an image representing a cat.
 * First of all we clear the scene and put the background in white
 * Then we upload the image located in the resoucres by using its path.
 * We block the scene proportion by using the setSceneRect and add the image
 * Then we use the bounds with "Qt::KeepAspectRatioByExpanding" that will put
 * the all image in the scene by adatapting the proportion
 * Finally we block the action paint which is useless with an uploaded image
 * by put its button invisble and do the opposite for the fullscreen
*/

void MainWindow::on_button_cat_clicked()
{
    scene->setBackgroundBrush(Qt::white);
    scene->clear();
    image.load(":/Paint/Icons/chat_paint.jpg");
    scene->setSceneRect(0,0, image.width(), image.height());
    scene->addPixmap(image);
    QRectF bounds = scene->itemsBoundingRect();
    bounds.setWidth(bounds.width());
    bounds.setHeight(bounds.height());
    ui->drawWindow->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
    ui->button_paint->setVisible(false);
    ui->button_fullscreen->setVisible(true);
    Scene::clean=true;
}



/* ------------------------------------------------------------------  *
 * ----------------------- TEXT INPUT FUNCTION ----------------------- *
 * ------------------------------------------------------------------- */

/* We have to declare a static value like this, out of the function. */

QString Scene :: edit = "";

/*
 * When the user first clicked on the write_button to write something, some buttons become visible.
 * The textEdit object (which is a QPlainTextEdit type) and the button_ok are visible.
 * The user can write his edit (text) on the textEdit object and this is attached to the edit
 * variable which is static in order to be used with the same text in the Scene class.
 * After this we just have to add the edit (text) on the scene by clickling where we want to see the text.
*/

void MainWindow::on_button_ok_clicked()
{
    Scene::edit=ui->textEdit->toPlainText();
}




/* ------------------------------------------------------------------  *
 * ---------------------- MENU FUNCTION: EDIT ------------------------ *
 * ------------------------------------------------------------------- */

bool Scene :: save = false;
bool Scene :: clean = false;

/* ----------------------------------------------------------------- *
 * ---------------------- MENU FUNCTION: FILE ---------------------- *
 * ----------------------------------------------------------------- */

/*
 * This function is linked to actionNew located in the file menu, it is used to create a new window.
 * We create a new Window of type MainWindow, we add the main icon and we show the new window.
 * It's will use the all same function including the destructor which ensures the destruction of all
 * the dynamic duplication.
*/

void MainWindow::on_actionNew_triggered()
{
    MainWindow *newFenetre = new MainWindow();
    QPixmap pix_main(":/Paint/Icons/myPaint_icon.png");
    newFenetre->setWindowIcon(pix_main);
    newFenetre->show();
}

/*
 * This function is linked to actionSave located in the file menu, it is used to save what the user drawed
 * in the scene (and also the images)
 * We create an image of QImage type which is the size of the scene, and a oainter of QPainter type.
 * We also create a QString to save the image path the user will select on the QFileDialog, it could
 * be saved in JPEG and PNG format.
 * Render is for capture the painter which represents also the image and then, our scene.
 * Finally we save the image (which is in fact what is in the scene) at the image path the user wanted
*/

void MainWindow::on_actionSave_triggered()
{
    QImage img(scene->sceneRect().size().toSize(), QImage::Format_RGB32);
    QPainter painter(&img);
    painter.setRenderHint(QPainter::Antialiasing);
    scene->render(&painter);
    QString ImagePath = QFileDialog::getSaveFileName(this,tr("Save File"),"",tr("JPEG(*.jpg *.jpeg);;PNG (*.png)"));
    img.save(ImagePath);
    Scene::save=true;
}

/*
 * The idea is more or less the same here. We use a QFileDialog from Qt to reach the pdf exportation.
 * The QPdfWriter is for generate PDF.
 * Then we use 2 QPainter (painter for adaptating to a PDF file and painter2 to take all information from
 * the scene).
 * Our static booleen save is put to true. Explain after
*/

void MainWindow::on_actionExport_As_PDF_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporte As PDF",QString(), "*.pdf");
    QPdfWriter writer(fileName);
    QPainter painter(&writer);
    QImage img(scene->sceneRect().size().toSize(), QImage::Format_RGB32);
    QPainter painter2(&img);
    painter2.setRenderHint(QPainter::Antialiasing);
    scene->render(&painter2);
    writer.setPageSize(QPagedPaintDevice::A4);
    painter.drawImage(QRect(0,0,writer.logicalDpiX()*8.3,writer.logicalDpiY()*11.7),img);
    painter.end();
    Scene::save=true;
}

/*
 * This function is linked to actionOpen located in the File menu, it is used to open an image of JPEG,
 * PNG or PDF format.
 * We first clear the scene to make it empty and we create a QString for the image path.
 * The imagePath variable will take the image path the user selected in the QFileDialog
 * We load the image located at the imagePath, and we add it to the scene. Then we adapt the image size
 * by using bound and put it in the center of our scene in order to be more visible.
 * if no image is selected, we display a QMessageBox to the user, otherwise, we set the fullscreen button
 * visible if the user want to see it in fullscreen
*/

void MainWindow::on_actionOpen_triggered()
{
    QString imagePath = QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("JPEG(*.jpg *.jpeg);;PNG (*.png);;PDF (*.pdf)"));
    image.load(imagePath);

    if(image.isNull())
    {
        QMessageBox::warning(this, "title", "Your image has not been added") ;
    }

    else
    {
        scene->clear();
        scene->setBackgroundBrush(Qt::white);
        ui->button_fullscreen->setVisible(true);
        ui->button_paint->setVisible(false);
        scene->setSceneRect(0,0, image.width(), image.height());
        scene->addPixmap(image);

        QRectF bounds = scene->itemsBoundingRect();
        bounds.setWidth(bounds.width());
        bounds.setHeight(bounds.height());
        ui->drawWindow->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
        ui->drawWindow->centerOn(0, 0);

        Scene :: clean = true;
    }
}

/*
 * This function is linked to actionPrint located in the File menu, it is used to print what is in the scene.
 * We create a printer variable of type QPrinter (printer), then we set it's size to A4 format with setPageSize()
 * and to porttrait format with setOrientation.
 * We also create a dlg variable which is a QPrintDialog.
 * We associate the painter p to our scene which represents the printer.
*/

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    QPrintDialog dlg(&printer);
    if(dlg.exec()==QDialog::Accepted)
    {
        QPainter p(&printer);
        scene->render(&p);
        p.end();
    }
}

/*
 * If the variable save is true (which is passed to false each time an action is done in Scene)
 * the file is directly closed.
 * Else we create a message box proposing to returning to the function save by clicking on the
 * "save" button generated. To close the message box by clicking on "cancel" or directly close
 * the application without save it by clicking on "discard".
*/

void MainWindow::on_actionClose_triggered()
{
    if (Scene::save==true)
    {
       Scene::save=false;
       close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Save:
              on_actionSave_triggered();
              break;
          case QMessageBox::Discard:
              close();
              break;
          case QMessageBox::Cancel:
              break;
          default:
              break;
        }
    }
}

/*
 * This function is linked to actionClose located in the File menu, it is used to close the Window.
 * It is the red cross.
*/

void MainWindow::closeEvent (QCloseEvent *event)
{
    if (Scene::save==true)
    {
       Scene::save=false;
       close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Save:
              on_actionSave_triggered();
              break;
          case QMessageBox::Discard:
              close();
              break;
          case QMessageBox::Cancel:
            event->ignore();
              break;
          default:
              break;
        }
    }
}

/* ------------------------------------------------------------------  *
 * ---------------------- MENU FUNCTION: EDIT ------------------------ *
 * ------------------------------------------------------------------- */

/*
 * The following function is linked to the More colors action in the Edit menu
 * This function is used if the user want more colors than the one proposed in the GUI
 * We first create a color, of QColor type which will be the color selected in the QColorDialog by the user
 * After, we put the color variable in the color_around_pen, color_pen, color_text varibles, so the user can draw
 * with the selected color.
 * Finally we put the selected color in the indicator by adding a rectangle of the selected color in it.
*/

void MainWindow::on_actionMore_colors_triggered()
{
    QColor more_color = QColorDialog::getColor(Qt::white, this);
    Scene::color_around_pen=QPen(more_color);
    Scene::color_pen=QBrush(more_color);
    indicator->addRect(10,0,50,50,more_color,more_color);
    color_text=more_color;
}

/*
 * This is an action which permit us to increase/decrease the value of the thickness.
 * Each time you click on check, its value move from true to false or from false to true.
 * The thickness changes because we change the scale (setMinimum & setMaximum) depending
 * of the value of check. You can see during the run if the action is checked or not.
*/

void MainWindow::on_actionIncrease_the_thickness_toggled(bool check)
{
    if (check==true)
    {
        ui->slider_thickness->setMinimum(20);
        ui->slider_thickness->setMaximum(40);
    }
    else
    {
        ui->slider_thickness->setMinimum(1);
        ui->slider_thickness->setMaximum(20);
    }
}

/*
 * Here we clear all the scene by using the function clear and put the backgroundcolor to white.
 * We consider it as a change of our scene, then "save" become false.
*/


void MainWindow::on_actionClear_triggered()
{
    scene->clear();
    scene->setBackgroundBrush(Qt::white);
    Scene::save=false;
    Scene::clean=true;
}

/* ----------------------------------------------------------------- *
 * ---------------------- MENU FUNCTION: HELP ---------------------- *
 * ----------------------------------------------------------------- */

/*
 * The following function is linked to the action_Version located in the Help menu, and display informations about the application
 * We create a new QWidget, we set it's dimension with setFixedSize command, then we add labels on this widget
*/

void MainWindow::on_action_Version_triggered()
{
    QWidget *widget = new QWidget;
    widget->setFixedSize(200,200);
    QLabel *version = new QLabel(widget);
    version->setText("Version 1.0");
    version->move(60,70);
    QLabel *creator = new QLabel(widget);
    creator->setText(" Clément Tailleur    Rémi Ferreira");
    creator->move(0,150);
    widget->show();
}
