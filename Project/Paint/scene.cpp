#include "scene.h"
#include "mainwindow.h"
#include "mainwindow.cpp"
#include "ui_mainwindow.h"


/* ------------------------------------------------------- *
 * -------------------- CONSTRUCTOR ---------------------- *
 * ------------------------------------------------------- */

/*
 * We initialize all the values representing the indice of the tables at 0
 * The background of the scene at white
 * And 3 attributes that we will discuss after.
*/

Scene::Scene(QObject* parent): QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::white);
    back_color_pen=QBrush(QColor(255, 0, 0, 0));
    click=false;
    clean=false;
    step=0;
    e=0;
    c=0;
    r=0;
    l=0;
    t=0;
}




/* ---------------------------------------------------- *
 * -------------------- DESTRUCTOR -------------------- *
 * ---------------------------------------------------- */

/*
 * Each time you create a shape, its indice is incremented (s++)
 * Each time you undo it, its indice is decremented (s--)
 * Here, we delete the difference between both of them (it is the actual indice
 * representing also the number of shapes which are still dynamically drawn).
*/

Scene::~Scene()
{
    if (l>=1)
    {
        for (int i=1;i==l;i++)
        {
           delete line [l];
        }
    }

    if (r>=1)
    {
        for (int i=1;i==r;i++)
        {
           delete rectangle [r];
        }
    }

    if(e>=1)
    {
        for (int i=1;i==e;i++)
        {
           delete ellipse [e];
        }
    }

    if(c>=1)
    {
        for (int i=1;i==c;i++)
        {
           delete circle [c];
        }
    }

    if (t>=1)
    {
        for (int i=1;i==t;i++)
        {
           delete text [t];
        }
    }
}




/* --------------------------------------------------------- *
 * -------------------- MOUSE FUNCTIONS -------------------- *
 * --------------------------------------------------------- */

/*
 * The mouse functions are those which switch the things the user do when drawing on the scene.
 * They are called by the button_pressed variable which has a value for each mode.
 * Some modes are used just by clicking in the scene, others by releasing or moving  the cursor on the scene.
 * But most of them are used by doing both things (clicking then moviong the cursor then releasing it for example)
*/

QColor MainWindow::color_text=Qt::black;

/*
 * The following function shows actions when the user click on the scene after selecting a mode.
*/

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* -------------------------------------------------------------------------- *
     * ----------------- button_pressed=0 : PEN MODE ---------------------------- *
     * -------------------------------------------------------------------------- */
/*
 * We created a click variable in the scene.h, when clicking in the scene it becomes true.
 * We use it because we want the movepressevent works only when the user press the click (when click=true)
 * If we press, save become false become it become different immediatly.
 * The cursor is a CrossCursor for drawing in the scene.
 * After each click in pen mode, the variable pt, which is a QPointF type becomes the click position thanks.
 * to the function event->scenePos().
 * Finally we add an ellipse with addEllipse command at the click position coordinates.
 * The ellipse is a point so there is no w and h component in addEllipse except thickness (that the user choose)
 * We add an ellipse only if thickness >= 12 for esthetic raisons.
 * The color of the ellipse is the color selected by the user in MainWindow: color_pen and color_around_pen.
*/

    if(button_pressed==0)
    {
        QApplication::setOverrideCursor(Qt::CrossCursor);
        click=true;
        save=false;
        if (thickness>=12)
        {
            QPointF pt = event->scenePos();
            this->addEllipse(pt.x()-thickness,pt.y()-thickness,thickness,thickness,color_around_pen,color_pen);
        }
    }

    /* ------------------------------------------------------------ *
     * ---------- button_pressed=1: BACKGROUND PAINT MODE --------- *
     * ------------------------------------------------------------ */
 /*
  * The cursor in background paint mode is a PointingHandCursor.
  * We use setBackgroundBrush() command to paint the scene in the color selected (color_pen).
  * Once again, if we press, save become false become it become different immediatly.
*/

    if(button_pressed==1)
    {
        QApplication::setOverrideCursor(Qt::PointingHandCursor);
        this->setBackgroundBrush(color_pen);
        save = false;
    }

    /* ------------------------------------------------------------ *
     * -------------- button_pressed=2: CIRCLE MODE --------------- *
     * ------------------------------------------------------------ */
/*
 * The cursor in circle mode is a ClosedHandCursor when the user click.
 * When the user clicks, we get the coordinates with the event->scenePos() command.
 * We add those coordinates in m_x and m_y attributes (kept in memory) for the x and y components.
 * Save becomes false because this results a changement.
 * The integer/attribute c is initialized at 0 in the constructor.
 * Each time we create an item "circle", c increment itself, and finally we create an item circle[c]->
 * But not when c >100 because of the size of our table initialized at 100 in the header. In this case,
 * c=1 and all the circles created before will be fixed. And not when clean=true because we have to
 * delete all the circle and rebuild all from the first. cricle : at c=1 -> circle[1].
 * The size of the table represents the number of a specific shape we could undo.
 * If the user creates 105 circles, he will be able to undo only 5 of them because 100 will be fixed
 * definitively. But if he creates 199, he will be able to undo 99 of them.
 * Then we create a item circle, which is a QGraphicsEllipseItem.
*/

    if(button_pressed==2)
    {
        QApplication::setOverrideCursor(Qt::ClosedHandCursor);
        click=true;
        if (c<100 && clean==false)
        {
            c++;
            save = false;
            point_1 = event->scenePos();
            m_x=point_1.x();
            m_y=point_1.y();
            circle [c] = new QGraphicsEllipseItem;
        }
        else
        {
            if (clean==true)
            {
                clean=false;
            }
            c=1;
            save = false;
            point_1 = event->scenePos();
            m_x=point_1.x();
            m_y=point_1.y();
            circle [c] = new QGraphicsEllipseItem;
        }
    }

    /* --------------------------------------------------------------- *
     * -------------- button_pressed=3: RECTANGLE MODE --------------- *
     * --------------------------------------------------------------- */
/*
 * The cursor in rectangle mode is a ClosedHandCursor when the user click.
 * When the user clicks, we get the coordinates with the event->scenePos() command.
 * We add those coordinates in m_x and m_y for the x and y components.
 * Then we create a rectangle r, which is a QGraphicsRectItem.
 * The rest of method is about the same than for the circle.
*/

    if(button_pressed==3)
    {
        QApplication::setOverrideCursor(Qt::ClosedHandCursor);
        click=true;
        if (r<100 && clean==false)
        {
            r++;
            save = false;
            point_1 = event->scenePos();
            m_x=point_1.x();
            m_y=point_1.y();
            rectangle [r] = new QGraphicsRectItem;
        }
        else
        {
            if (clean==true)
            {
                clean=false;
            }
            r=1;
            save = false;
            point_1 = event->scenePos();
            m_x=point_1.x();
            m_y=point_1.y();
            rectangle [r] = new QGraphicsRectItem;
        }
    }

    /* --------------------------------------------------------------- *
     * ---------------- button_pressed=4: LINE MODE ------------------ *
     * --------------------------------------------------------------- */
/*
 * The cursor in line mode is a ClosedHandCursor when the user click.
 * When the user clicks, we get the coordinates with the event->scenePos() command.
 * We add those coordinates in m_x and m_y for the x and y components.
 * Then we create a line l, which is a QGraphicsLineItem.
 * The rest of the method is about the same than for the circle and the rectangle.
*/

    if(button_pressed==4)
    {
        QApplication::setOverrideCursor(Qt::ClosedHandCursor);
        click=true;
        if (l<100 && clean==false)
        {
            l++;
            save = false;
            point_1 = event->scenePos();
            m_x=point_1.x();
            m_y=point_1.y();
            line[l] = new QGraphicsLineItem;
        }
        else
        {
            if (clean==true)
            {
                clean=false;
            }
            l=1;
            save = false;
            point_1 = event->scenePos();
            m_x=point_1.x();
            m_y=point_1.y();
            line[l] = new QGraphicsLineItem;
        }
    }

    /* --------------------------------------------------------------- *
     * ----------------- button_pressed=5: TEXT MODE ----------------- *
     * --------------------------------------------------------------- */
/*
 * The cursor in text mode is an ArrowCursor when the user click.
 * When the user clicks, we get the coordinates with the event->scenePos() command.
 * We add those coordinates in m_x and m_y for the x and y components.
 * Then we create a text t, which is a QGraphicsTextItem.
 * After we create a font of QFont type which will define how the text will look (police, size, type)
 * and we add it in text.
 * Then we set the color of the text and the position (which is where the user is going to click)
 * We use the function setPlainText in order to recore the text (edit) wrote in the mainwindow.
 * Finally we add the text on the scene.
 * The rest of the method is about the same than for the circle, the rectangle and the line.
*/

    if(button_pressed==5)
    {
        QApplication::setOverrideCursor(Qt::ArrowCursor);
        if (t<100 && clean==false)
        {
            t++;
            save=false;
            point_1 = event->scenePos();
            m_x=point_1.x();
            m_y=point_1.y();
            text [t] = new QGraphicsTextItem;
            QFont font ("Comics", thickness+4, QFont::Bold);
            text[t]->setFont(font);
            text[t]->setPlainText(edit);
            text[t]->setDefaultTextColor(MainWindow::color_text);
            text[t]->setPos(m_x,m_y-thickness);
            this->addItem(text[t]);
        }
        else
        {
            if (clean==true)
            {
                clean=false;
            }
            t=1;
            save=false;
            point_1 = event->scenePos();
            m_x=point_1.x();
            m_y=point_1.y();
            text [t] = new QGraphicsTextItem;
            QFont font ("Comics", thickness+4, QFont::Bold);
            text[t]->setFont(font);
            text[t]->setPlainText(edit);
            text[t]->setDefaultTextColor(MainWindow::color_text);
            text[t]->setPos(m_x,m_y-thickness);
            this->addItem(text[t]);

        }
    }

    /* --------------------------------------------------------------- *
     * -------------- button_pressed=6: ELLIPSE MODE ----------------- *
     * --------------------------------------------------------------- */
/*
 * The cursor in ellipse mode is a ClosedHandCursor when the user click.
 * When the user clicks, we get the coordinates with the event->scenePos() command.
 * We add those coordinates in m_x and m_y for the x and y components.
 * Then we create an ellipse e, which is a QGraphicsEllipseItem.
 * The rest of the method is about the same than for the circle, the rectangle and the line.
*/

    if(button_pressed==6)
    {
        QApplication::setOverrideCursor(Qt::ClosedHandCursor);
        click=true;
        if (e<100 && clean==false)
        {
            e++;
            save = false;
            point_1 = event->scenePos();
            m_x=point_1.x();
            m_y=point_1.y();
            ellipse [e] = new QGraphicsEllipseItem;
        }
        else
        {
            if (clean==true)
            {
                clean=false;
            }
            e=1;
            save = false;
            point_1 = event->scenePos();
            m_x=point_1.x();
            m_y=point_1.y();
            ellipse [e] = new QGraphicsEllipseItem;
        }
    }

    /* --------------------------------------------------------------- *
     * ------------------ button_pressed=7: CLICK MODE --------------- *
     * --------------------------------------------------------------- */
/*
 * The cursor in click mode is an ArrowCursor when the user click.
*/

    if(button_pressed==7)
    {
        QApplication::setOverrideCursor(Qt::ArrowCursor);
    }

    /* --------------------------------------------------------------- *
     * -------------- button_pressed=8: ERASE MODE ------------------- *
     * --------------------------------------------------------------- */
/*
 * The cursor in erase mode is a PointingHandCursor when the user click.
 * The Erase function is basically the same as the Pen function.
 * but the color is always white.
*/

    if(button_pressed==8)
    {
        click=true;
        save = false;
        QApplication::setOverrideCursor(Qt::PointingHandCursor);
        if (thickness>=12)
        {
            QPointF pt = event->scenePos();
            QPen pen=QPen(Qt::white);
            QBrush brush=QBrush(Qt::white);
            pen.setWidth(thickness);
            this->addEllipse(pt.x()-thickness,pt.y()-thickness,thickness,thickness,pen,brush);
        }
    }
}




void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)

/* ------------------------------------------------------------ *
 * -------------- button_pressed=0: PEN MODE ------------------ *
 * ------------------------------------------------------------ */

/*
 * Then pen mode is activated only if the button pressed is 0 and click is true (if you press the mouse)
 * Then either the thickness is less than 12 and the pen is a succession of line or the thickness is
 * more than 12 and the pen will be a succession of ellipse.
 * Succession of line: We created a QPoint as attribute named "last" and an other directly in the function
 * representing the position of the mouse "pos". If nothing was created before (first point) "last" is null
 * and is equal to the position of our cursor "pos". Then each time you move, the function is called and
 * add a line between "last" and "pos". After, "last" take the value of "pos" and redraw a line between "last"
 * which is the last pos, and pos which is the new pos.
*/

{
    if((button_pressed==0) && (click==true))
    {
        color_around_pen.setWidth(thickness);
        if (thickness<=12)
        {
            QPoint pos = event->scenePos().toPoint();
                if(last.isNull())
                {
                    last = pos;
                }
                else
                {
                    addLine(QLine(last,pos),QPen(color_around_pen));
                    last = pos;
                }
        }
        else
        {
            QPointF pt = event->scenePos();
            this->addEllipse(pt.x()-thickness,pt.y()-thickness,thickness,thickness,color_around_pen,color_pen);
        }
    }

    /* ------------------------------------------------------------ *
     * -------------- button_pressed=2: CIRCLE MODE --------------- *
     * ------------------------------------------------------------ */
/*
 * The variable click=true means the click is holded while the user move the cursor.
 * We first set the color and the width of the circle.
 * Initially the step is 0 so we add an item here, which is the circle c.
 * Then the step become 1, it will be 0 again when the click will be released.
 * We did that because we want to avoid to creat another shape each time we move the cursor.
 * When the user move the cursor, we get the location of the cursor with point_2 and we
 * put x and y coordinates in the variables.
 * Then the variables x and y which are int type became the coordinates of the release location (x and y)
 * Depending on which way the user is drawing the circle, we have 4 cases depending on m_x, x, m_y and y values.
 * For each case we use setRect command where x and y of the comand are the tiniest between m_x and x and
 * between m_y and y, the w and h component of the setRect() are the same because it is a circle.
 * It is always the biggest x component minus the tiniest.
*/

    if(button_pressed==2 && (click==true))
    {
        circle[c]->setPen(color_around_pen);
        color_around_pen.setWidth(thickness);

        if (step==0)
        {
            this->addItem(circle[c]);
            step=1;
        }

        if (step==1)
        {
            point_2 = event->scenePos();
            int x = point_2.x();
            int y = point_2.y();

            if(m_x<x && m_y<y)
            {
                circle[c]->setRect(m_x,m_y,x-m_x,x-m_x);
            }

            if(m_x>x && m_y<y)
            {
                circle[c]->setRect(x,m_y,m_x-x,m_x-x);
            }

            if(m_x<x && m_y>y)
            {
                circle[c]->setRect(m_x,y,x-m_x,x-m_x);
            }

            if(m_x>x && m_y>y)
            {
                circle[c]->setRect(x,y,m_x-x,m_x-x);
            }
        }
    }

    /* --------------------------------------------------------------- *
     * -------------- button_pressed=3: RECTANGLE MODE --------------- *
     * --------------------------------------------------------------- */

/*
 * The variable click=true means the click is holded while the user move the cursor
 * We first set the color and the width of the rectangle
 * initially the step is 0 so we add an item here, which is the rectangle r
 * Then the step become 1, it will be 0 again when the click will be released.
 * When the user move the cursor, we get the location of the cursor with point_2 and we put x and y coordinates in the variables.
 * then the variables x and y which are int type became the coordinates of the release location (x and y)
 * m_x and m_y are our attributes saved in the memory and fixed when we pressed the mouse.
 * Depending on which way the user is drawing the rectangle, we have 4 cases depending on m_x, x, m_y and y values
 * For each case we use setRect command where x and y of the comand are the tiniest between m_x and x and between m_y and y,
 * the w component of the setRect function is always the biggest x (between m_w and x) minus the other.
 * Same thing for the h component but this time with the biggest y (between m_y and y) minus the other
*/


    if(button_pressed==3 && (click==true))
    {
        rectangle[r]->setPen(color_around_pen);
        color_around_pen.setWidth(thickness);

        if (step==0)
        {
            this->addItem(rectangle[r]);
            step=1;
        }

        if (step==1)
        {
            point_2 = event->scenePos();
            int x = point_2.x();
            int y = point_2.y();

            if(m_x<x && m_y<y)
            {
                rectangle[r]->setRect(m_x,m_y,x-m_x,y-m_y);
            }

            if(m_x>x && m_y<y)
            {
                rectangle[r]->setRect(x,m_y,m_x-x,y-m_y);
            }

            if(m_x<x && m_y>y)
            {
                rectangle[r]->setRect(m_x,y,x-m_x,m_y-y);
            }

            if(m_x>x && m_y>y)
            {
                rectangle[r]->setRect(x,y,m_x-x,m_y-y);
            }
        }
    }

    /* --------------------------------------------------------------- *
     * ----------------- button_pressed=4: LINE MODE ----------------- *
     * --------------------------------------------------------------- */
/*
 * The variable click=true means the click is holded while the user move the cursor
 * We first set the color and the width of the line
 * initially the step is 0 so we add an item here, which is the line l
 * Then the step become 1, it will be 0 again when the click will be released.
 * The method used with step and the attributes m_x and m_y is about the same than for a circle.
 * When the user move the cursor, we get the location of the cursor with point_2 and we put x and y coordinates in the variables.
 * then the variables x and y which are int type became the coordinates of the release location (x and y)
 * Setline function will move the item created in step 0.
*/

    if (button_pressed==4 && (click==true))
    {
        line[l]->setPen(color_around_pen);
        color_around_pen.setWidth(thickness);

        if (step==0)
        {
            this->addItem(line[l]);
            step=1;
        }

        if(step==1)
        {
            point_2 = event->scenePos();
            int x=point_2.x();
            int y=point_2.y();
            line[l]->setLine(m_x,m_y,x,y);
        }


    }

    /* --------------------------------------------------------------- *
     * -------------- button_pressed=6: ELLIPSE MODE ----------------- *
     * --------------------------------------------------------------- */
/*
 * The method is about the same than for the rectangle.
*/

    if(button_pressed==6 && (click==true))
    {
        ellipse[e]->setPen(color_around_pen);
        color_around_pen.setWidth(thickness);

        if (step==0)
        {
            this->addItem(ellipse[e]);
            step=1;
        }

        if (step==1)
        {
            point_2 = event->scenePos();
            int x = point_2.x();
            int y = point_2.y();

            if(m_x<x && m_y<y)
            {
                ellipse[e]->setRect(m_x,m_y,x-m_x,y-m_y);
            }

            if(m_x>x && m_y<y)
            {
                ellipse[e]->setRect(x,m_y,m_x-x,y-m_y);
            }

            if(m_x<x && m_y>y)
            {
                ellipse[e]->setRect(m_x,y,x-m_x,m_y-y);
            }

            if(m_x>x && m_y>y)
            {
                ellipse[e]->setRect(x,y,m_x-x,m_y-y);
            }
        }
    }

    /* ------------------------------------------------------------ *
     * -------------- button_pressed=8: ERASE MODE ---------------- *
     * ------------------------------------------------------------ */
/*
 * The Erase fuction is the same than the pen function but color attributes are this time
 * initialized at white.
*/

    if((button_pressed==8) && (click==true))
    {
        QPen pen = QPen(Qt::white);
        QBrush brush = QBrush(Qt::white);
        pen.setWidth(thickness);
        if (thickness<=12)
        {
            QPoint pos = event->scenePos().toPoint();
                if(last.isNull())
                {
                    last = pos;
                }
                else
                {
                    addLine(QLine(last,pos),pen);
                    last = pos;
                }
        }
        else
        {
            QPointF pt = event->scenePos();
            this->addEllipse(pt.x()-thickness,pt.y()-thickness,thickness,thickness,pen,brush);
        }
    }
}




void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* --------------------------------------------------------------------- *
     * ---------------------------- PEN ERASE ------------------------------ *
     * --------------------------------------------------------------------- */
/*
 * Here we pass the valu of click at false in order to avoid to draw if we move the mouse on the scene.
 * And we set the parameters of last at 0 in order to avec a last=NULL for recreate a new brush.
*/

    if(button_pressed==0 || button_pressed==8)
    {
        QApplication::setOverrideCursor(Qt::ArrowCursor);
        click=false;
        last.setX(0);
        last.setY(0);
    }

    /* --------------------------------------------------------------------- *
     * -------------- CIRCLE, RECTANGLE, LINE, ELLIPSE, MODE --------------- *
     * --------------------------------------------------------------------- */
/*
* When the click is released, we put the value of step back to 0 and the value of click to false.
* Step is 0 because the click is released, then, in the moveevent you will a to recreate a shape
* Click is false because you want the mouse can move without draw anything if you don't press on it.
* The cursor is now an OpenHandCursor
*/

    if(button_pressed==2 || button_pressed==3 || button_pressed==4 || button_pressed==6)
    {
        step=0;
        click=false;
        QApplication::setOverrideCursor(Qt::OpenHandCursor);
    }

/*
 * We use this function in order to use the parameter event, it doesn't have any effect on our function
 * and it is proper.
*/

    event->accept();
}

/* --------------------------------------------------------------------- *
 * --------------------------- KEY FUNCTION ---------------------------- *
 * --------------------------------------------------------------------- */

/*
 * We use 5 letters L for line,R for rectangle,E for ellipse,C for circle and T for text to undo
 * each shape created before.
 * For Line, if your created 17 lines, your indice l will be equal to 17. By clicking on 'L' you will definitively
 * delete line 17 and the indice 17 wil be dicrimented to 16. Then you could delete the line 16 ect...
 * The method is about the same for each shape.
*/

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_L)
    {
        if (l>=1)
        {
            delete line [l];
            l--;
        }
    }

    if(event->key() == Qt::Key_R)
    {
        if (r>=1)
        {
            delete rectangle[r];
            r--;
        }
    }

    if(event->key() == Qt::Key_E)
    {
        if (e>=1)
        {
            delete ellipse[e];
            e--;
        }
    }

    if(event->key() == Qt::Key_C)
    {
        if (c>=1)
        {
            delete circle[c];
            c--;
        }
    }

    if(event->key() == Qt::Key_T)
    {
        if (t>=1)
        {
            delete text[t];
            t--;
        }
    }

}
