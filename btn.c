#include "btn.h"
#include "draw.h"
int GetBtn(TLCD tlcdInfo, int xpos, int ypos)
{
    int inputBtnFlag = 0;

    if ((xpos >= 270 && xpos <= 320) && (ypos >= 175 && ypos <= 205))
    {
        inputBtnFlag = TOUCH_PEN;
    }
    else if ((xpos >= 270 && xpos <= 320) && (ypos >= 210 && ypos <= 240))
    {
        inputBtnFlag = TOUCH_FILL;
    }
    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 0 && ypos <= 30))
    {
        inputBtnFlag = TOUCH_LINE;
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 35 && ypos <= 65))
    {
        inputBtnFlag = TOUCH_RECT;
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 70 && ypos <= 100))
    {
        inputBtnFlag = TOUCH_OVAL;
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 105 && ypos <= 135))
    {
        inputBtnFlag = TOUCH_FREEDRAW;
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 140 && ypos <= 170))
    {
        inputBtnFlag = TOUCH_SEL;
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 175 && ypos <= 205))
    {
        inputBtnFlag = TOUCH_ERASE;
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 210 && ypos <= 240))
    {
        inputBtnFlag = TOUCH_CLEAR;
    }

    else if ((xpos >= 272 && xpos <= 295) && (ypos >= 0 && ypos <= 42))
    {
        inputBtnFlag = TOUCH_WHITE;
    }

    else if ((xpos >= 297 && xpos <= 320) && (ypos >= 0 && ypos <= 42))
    {
        inputBtnFlag = TOUCH_ORANGE;
    }

    else if ((xpos >= 272 && xpos <= 295) && (ypos >= 44 && ypos <= 86))
    {
        inputBtnFlag = TOUCH_RED;
    }

    else if ((xpos >= 297 && xpos <= 320) && (ypos >= 44 && ypos <= 86))
    {
        inputBtnFlag = TOUCH_GREEN;
    }

    else if ((xpos >= 272 && xpos <= 295) && (ypos >= 88 && ypos <= 130))
    {
        inputBtnFlag = TOUCH_YELLOW;
    }

    else if ((xpos >= 297 && xpos <= 320) && (ypos >= 88 && ypos <= 130))
    {
        inputBtnFlag = TOUCH_NAVY;
    }

    else if ((xpos >= 272 && xpos <= 295) && (ypos >= 132 && ypos <= 174))
    {
        inputBtnFlag = TOUCH_BLUE;
    }

    else if ((xpos >= 297 && xpos <= 320) && (ypos >= 132 && ypos <= 174))
    {
        inputBtnFlag = TOUCH_BLACK;
    }

    else if ((xpos >= 60 && xpos <= 260) && (ypos >= 10 && ypos <= 230))
    {
        inputBtnFlag = TOUCH_CANVAS;
    }

    return inputBtnFlag;
}

void SensingTouch(TLCD tlcdInfo)
{
    int x, y, pressure;
    int xpos, ypos, ret;

    read(tlcdInfo.fd, &tlcdInfo.ie, sizeof(struct input_event));

    if (tlcdInfo.ie.type == 3)
    {
        if (tlcdInfo.ie.code == 0)
        {
            x = tlcdInfo.ie.value;
        }
        else if (tlcdInfo.ie.code == 1)
        {
            y = tlcdInfo.ie.value;
        }
        else if (tlcdInfo.ie.code == 24)
        {
            pressure = tlcdInfo.ie.value;
        }
    }

    // 보정을 넣은 lcd상의 x , y의 포지션
    xpos = tlcdInfo.a * x + tlcdInfo.b * y + tlcdInfo.c;
    ypos = tlcdInfo.d * x + tlcdInfo.e * y + tlcdInfo.f;

    // 터치가 된곳의 위치에 따라달라짐
    if (pressure >= 180)
    {
        ret = GetBtn(tlcdInfo, xpos, ypos);
    }
    else
    {
        ret = 0;
    }

    switch (ret)
    {
    case TOUCH_PEN:
        state = 1;
        break;
    case TOUCH_FILL:
        state = 2;
        break;
    case TOUCH_LINE:
        state = 3;
        break;
    case TOUCH_RECT:
        state = 4;
        break;
    case TOUCH_OVAL:
        state = 5;
        break;
    case TOUCH_FREEDRAW:
        state = 6;
        break;
    case TOUCH_SEL:
        state = 7;
        break;
    case TOUCH_ERASE:
        state = 8;
        break;
    case TOUCH_CLEAR:
        printf("todo Clear\n");
        break;
    case TOUCH_WHITE:
        printf("todo WhiteColor\n");
        break;
    case TOUCH_ORANGE:
        printf("todo OrangeColor\n");
        break;
    case TOUCH_RED:
        printf("todo RedColor\n");
        break;
    case TOUCH_GREEN:
        printf("todo GreenColor\n");
        break;
    case TOUCH_YELLOW:
        printf("todo YellowColor\n");
        break;
    case TOUCH_NAVY:
        printf("todo NavyColor\n");
        break;
    case TOUCH_BLUE:
        printf("todo BlueColor\n");
        break;
    case TOUCH_BLACK:
        printf("todo BlackColor\n");
        break;
    case TOUCH_CANVAS:
        printf("touching screen %d %d\n", xpos, ypos);

        switch (state)
        {
        // TODO PEN
        case TOUCH_PEN:
            printf("dot screen %d %d\n", xpos, ypos);
            break;
        // TODO Fill
        case TOUCH_FILL:
            printf("TODO Fill\n");
            break;
        // TODO LINE
        case TOUCH_LINE:
            //DrawLine(tlcdInfo, /* Shape 구조체 넣어야 함 */);
            break;
        // TODO RECTANGLE
        case TOUCH_RECT:
            //DrawRectangle(tlcdInfo, /* Shape 구조체 넣어야 함 */);
            break;
        // TODO Oval
        case TOUCH_OVAL:
            //DrawOval(tlcdInfo, /* Shape 구조체 넣어야 함 */);
            break;
        // TODO Oval
        case TOUCH_FREEDRAW:
            printf("TODO FreeDraw\n");
            break;
        // TODO Select
        case TOUCH_SEL:
            printf("TODO Select\n");
            break;
        // TODO Erase
        case TOUCH_ERASE:
            printf("TODO Erase\n");
            break;
        default:
            break;
        }

        break;
    default:
        break;
    }
}
