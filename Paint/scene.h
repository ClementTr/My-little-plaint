#ifndef SCENE
#define SCENE

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QAction>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QPushButton>
#include <QKeyEvent>
#include <QLabel>
#include <QAbstractScrollArea>



class Scene : public QGraphicsScene
{
public:
    Scene(QObject* parent = 0);
    ~Scene();
    /* --------------------------------------------------------- *
     * -------------------- ATTRIBUTES SHARED ------------------ *
     * --------------------------------------------------------- */
    static QPen color_around_pen; /* color_around_pen is used in addEllipse and addRect command as the color around thos shapes */
    static QBrush color_pen; /* color_pen is the color the user select in the GUI, it will be used to put color on designated objects. */
    static QString edit; /* edit is the text writted by the user when he want to add text on the scene. */
    static int button_pressed; /* button_pressed is used for detecting which button the user pressed, and which function is linked to this button */
    static int thickness; /* thickness is used for changing the thickness of the objects (pen, rectangle) and the size of the text.  */
    static bool save; /* save is used to check if the user saved his work, if it is false, it will display a window to ask him to save when closing the application */
    static bool clean; /*clean is used as static to inform the scene.cpp that an event clear was used and repass all shape indices to 0.*/
    /*static attributes are used to be called in each function without be changed*/

protected:
    /* --------------------------------------------------------- *
     * -------------------- MOUSE FUNCTIONS -------------------- *
     * --------------------------------------------------------- */

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    /* --------------------------------------------------------- *
     * --------------------- KEY FUNCTION ---------------------- *
     * --------------------------------------------------------- */

    void keyPressEvent(QKeyEvent *event);

private:
    int l,r,c,e,t; /* those variables are the indices of each shape 'l'ine, 'r'ectangle...*/
    int m_x; /* m_x is the x coordinate of the cursor location when the user clicks. It will be used to draw shape. It is a private attribute in order to be keeping in memory when we pass from press to move event*/
    int m_y; /*Same thing but for y position/coordinate*/
    int step; /* Step is for differenciate 2 states in the MoveEvent, it will be explained in scene.cpp (circle) */
    bool click; /* Click is used to see if the user is clicking or not it will be used in MoveEvent to see if the user is both clicking and moving the cursor */
    QPointF point_1; /* point_1 is the point where the user click, it have the cursor's location coordinates. */
    QPointF point_2; /* point_2 is a point when the user moves the cursor after having clicked, it have the cursor's location coordinates. */
    QPoint last; /* last is used as an attribute to be kept in memory as the last position of the cursor to draw a line between last and the position where the mouse is, when drawing with the pen/erase function */
    QBrush back_color_pen; /* is initialized in the constructor, it is always transluscid, with it we are able to draw shapes without modifying the background */

/*
 * Those tables are used to keep in memory the multiple shapes the user drawed, to be able to remove them.
 * There is 100 of each item that can be kept in memory at the same time
*/
    QGraphicsTextItem *text[100];
    QGraphicsLineItem *line [100];
    QGraphicsRectItem *rectangle [100];
    QGraphicsEllipseItem *circle [100];
    QGraphicsEllipseItem *ellipse [100];
};

#endif // SCENE
