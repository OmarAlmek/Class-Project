#include "enemy.h"

Enemy1::Enemy1(int boardData[12][12])
{
    timerenemy= new QTimer(this);
       connect(timerenemy,SIGNAL(timeout()), this,SLOT(Enemy1::movingenemy()));
       timerenemy->start(500);
    // Set Image
    QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/enemy.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    row = 10;
    column = 6;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];
    //set health
    health = 2;
}
void Enemy1::movingenemy ()
{
        int n = rand()%4;

        if (n==0 && data[row-1][column]>=0)
        {
            row--;// this is not setting a position
             setPos(50+(50*column),50+(50*row));
            // connect(timertom,SIGNAL(timeout()), this,SLOT(dt()) );
        }
            else if (n==1 && data[row+1][column]>=0)
        {
            row++;
              setPos(50+(50*column),50+(50*row));
                 //connect(timertom,SIGNAL(timeout()), this,SLOT(ut()) );
        }
        else if ((n==2 )&& (data[row][column+1]>=0))
     {
            column++;
           setPos(50+(50*column),50+(50*row));
              //connect(timertom,SIGNAL(timeout()), this,SLOT(rt()) );
     }
     else if ( n ==3 &&data[row][column-1]>=0)
    {
         column--;
          setPos(50+(50*column),50+(50*row));
             //connect(timertom,SIGNAL(timeout()), this,SLOT(lt()) );
    }}
void Enemy1::losehealth(){
    health--;
}
int Enemy1::gethealth(){
    return health;
}
