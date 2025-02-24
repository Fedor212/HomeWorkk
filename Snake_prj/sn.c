#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <ncurses.h>
#include <ncurses/ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
#define COLPAIR  1

#define YELLOW 4
#define RED 5
#define MAGENTA 3

#define HEADCOLOR 2
#define TAILCOLOR 2
#define FOODCOLOR 4
//attron(COLOR_PAIR(RED));

//double DELAY = 0.08;
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10, };
int SEED_NUMBER = 3;
int START_TAIL_SIZE = 6;
int  TAIL_LIM = 15; //Длина хвоста при которой засчитывается победа.

// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

                                                                                           //Раскладка     должна быть ENG!!!
struct control_buttons default_controls[3] = {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT}, {'s', 'w', 'a', 'd'}, {'S', 'W', 'A', 'D'}};
//struct control_buttons default_controls = {s, w, a, d};
/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */

// Цветовые пары
void InitColors() {
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);  // Стандартный цвет
    init_pair(2, COLOR_CYAN, COLOR_BLACK);   // Дополнительные цвета
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLUE);
}
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
    int color_pairr;  //Цвет змейки
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;
/*
 Еда — это массив точек, состоящий из координат x,y, времени,
 когда данная точка была установлена, и поля, сигнализирующего,
 была ли данная точка съедена.

Чтобы обратиться к полю enable в структуре struct food,
нужно использовать оператор доступа к полю структуры (.).
Поскольку food — это массив из 3 [MAX_FOOD_SIZE] элементов типа struct food,
вам нужно указать индекс элемента массива, а затем обратиться к полю enable.
например food[0].enable */
struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}
/*
 Обновить/разместить текущее зерно на поле
 */
int putFoodSeed(struct food *fp)
{
    attron(COLOR_PAIR(FOODCOLOR));
    int max_x=0, max_y=0;
    int diff = 0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    diff = ((fp->y)-(fp->x));
    //mvprintw(2, 1, "%d", diff);
    mvprintw(fp->y, fp->x, "%s", spoint);
    attroff(COLOR_PAIR(FOODCOLOR));

    return diff;
}

/*
 Разместить еду на поле
 */
void putFood(struct food f[], size_t number_seeds) // Используется 1 раз!!!
{
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}

void refreshFood(struct food f[], int nfood)  //nfood = SEED_NUMBER = 3
{
    for(size_t i=0; i<nfood; i++) //nfood = 3
    {
        if( f[i].put_time )
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
            {

                putFoodSeed(&f[i]);

                //~ mvprintw(i+1, 1, "%d", food[i].x);  // Отображать координаты еды
                //~ mvprintw(i+1, 10, "%d", food[i].y);


            }
        }
    }
}
void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t= {0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

void initSnake(snake_t *head, size_t size, int x, int y, int color)
{
    tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
    head->controls = default_controls[3];
}

/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head)
{
    attron(COLOR_PAIR(HEADCOLOR));  //Задаем цвет головы!!!
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
    case LEFT:
        if(head->x <= 0) // Циклическое движение, чтобы не уходить за пределы экрана
            head->x = max_x;
        mvprintw(head->y, --(head->x), "%c", ch);
        break;
    case RIGHT:
        if(head->x>=max_x )
            head->x = 0;
        mvprintw(head->y, ++(head->x), "%c", ch);
        break;
    case UP:
        if(head->y <= 0)
            head->y = max_y;
        mvprintw(--(head->y), head->x, "%c", ch);
        break;
    case DOWN:
        if(head->y>=max_y )
            head->y = 0;
        mvprintw(++(head->y), head->x, "%c", ch);
        break;
    default:
        break;
    }
    attroff(COLOR_PAIR(HEADCOLOR));
    refresh();
}

void changeDirection(struct snake_t* snake, const int32_t key)

{
    for (int i = 0; i < 3; i++)
    {
        snake->controls = default_controls[i];
        if ((key == snake->controls.down) && (snake->direction != UP))
            snake->direction = DOWN;
        else if ((key == snake->controls.up) && (snake->direction != DOWN))
            snake->direction = UP;
        else if ((key == snake->controls.right) && (snake->direction != LEFT))
            snake->direction = RIGHT;
        else if ((key == snake->controls.left) && (snake->direction != RIGHT))
            snake->direction = LEFT;
    }
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    attron(COLOR_PAIR(TAILCOLOR));  //Задаем цвет хвоста!!!
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    attroff(COLOR_PAIR(TAILCOLOR));
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

//========================================================================
//Проверка того, является ли какое-то из зерен съеденным,
_Bool haveEat(struct snake_t *head, struct food f[])
{
        for (int i = 0; i < SEED_NUMBER; i++)
    {
        if ((food[i].x == head->x) && (food[i].y == head->y))
        {
            return 1;
        }
    }
    //...нужно написать код...//
    return 0;
}

/*
 Увеличение хвоста на 1 элемент
 */

void addTail (void)//(struct snake_t * sn) // был head
{
    START_TAIL_SIZE++;
    //printf ("You ate a seed");
    //...нужно написать код...//
}
//========================================================================
int checkDirection(snake_t* snake, int32_t key)
{
    //...нужно написать код...//
    // И так все работает, не знаю почему)
    return 1;
}

//Вынести тело цикла while из int main() в отдельную функцию update
//и посмотреть, как изменится профилирование

void update(struct snake_t *head, struct food f[], const int32_t key, double DEL)
{
    clock_t begin = clock();
    go(head);
    //~ mvprintw(2, 30, "head x: %d", head->x);  //Отображать координаты головы и размер хвоста
    //~ mvprintw(3, 30, "head x: %d", head->y);
    //~ mvprintw(4, 30, "tail is: %d", START_TAIL_SIZE);
    goTail(head);
    if (checkDirection(head,key))
    {
        changeDirection(head, key);
    }
    refreshFood(food, SEED_NUMBER);// Обновляем еду
    if (haveEat(head,food))
    {
        addTail(); //был head
    }
    refresh();//Обновление экрана, вывели кадр анимации

    while ((double)(clock() - begin)/CLOCKS_PER_SEC<DEL)
    {}

}
//========================================================================
//Код врезания головы в хвост
int isCrush(struct snake_t * snakee)
{
    int crushed = 0;
    for (size_t i = 1; i < MAX_TAIL_SIZE; i++)
    {
        if ((snakee->tail[i].x == snakee->x) && (snakee->tail[i].y == snakee->y))
        {
            crushed = 1;
            //attron(COLOR_PAIR(MAGENTA));
            //mvprintw (2, 2, "Game over: You ate your tail");
            //attroff(COLOR_PAIR(MAGENTA));
            printf ("Game over: You ate your tail");
        }
    }
    return crushed;
}

void repairSeed(struct food f[], size_t nfood, struct snake_t *head)
{
    for( size_t i=0; i<head->tsize; i++ )
        for( size_t j=0; j<nfood; j++ )
        {
/* Если хвост совпадает с зерном */
    //...нужно написать код...//
        }
    for( size_t i=0; i<nfood; i++ )
        for( size_t j=0; j<nfood; j++ )
        {
/* Если два зерна на одной точке */
    //...нужно написать код...//
        }
}


int main()
{
    //initscr();
    int speed = 0;
    printf ("Enter the speed of The Snake 1 to 20 km/h: ");
    //mvaddch(10, 10, "Enter the speed of The Snake 1 to 20 km/h: ");
    scanf ("%d", &speed);
    //initscr();
    double DELAY = (21 - speed) * 0.01;
    snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    //чтобы начать работу с библиотекой ncurses необходимо её проинициализировать.
    //Для этого нужно вызвать функцию initscr().
    initscr(); //Инициализируем ncurses и только потом Цвета
    InitColors(); //Инициализируем цвета
    initSnake(snake,START_TAIL_SIZE,10,10,1);
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    attron(COLOR_PAIR(MAGENTA));
    mvprintw(0, 3,"Use arrows for control. Press 'F10' for EXIT");
    attroff(COLOR_PAIR(MAGENTA));
    //mvprintw(2, 3,"Has_Colors: %d", has_colors());
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна
    int key_pressed=0;
    //int debug = 0;
    while( key_pressed != STOP_GAME )
    {
        key_pressed = getch(); // Считываем клавишу
        //mvprintw(3, 3, "Key pressed: %d", key_pressed);
        update(snake, food, key_pressed, DELAY);
        snake->tsize = START_TAIL_SIZE;
        if(START_TAIL_SIZE > TAIL_LIM)
        {
            printf ("You won!");
            break;
        }
        if(isCrush(snake))
        {
            break;
        }
        repairSeed(food, SEED_NUMBER, snake);

    }
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
}
