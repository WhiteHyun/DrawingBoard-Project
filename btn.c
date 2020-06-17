#include "btn.h"

int GetBtn(TLCD tlcdInfo, int xpos, int ypos)
{
    int inputBtnFlag = 0x00000;

    // line flag Up
    if ((xpos >= 270 && xpos <= 320) && (ypos >= 175 && ypos <= 205))
    {
        inputBtnFlag = 1; // 00 0000 0000 0000 0001 Pen
    }
    else if ((xpos >= 270 && xpos <= 320) && (ypos >= 210 && ypos <= 240))
    {
        inputBtnFlag = (1 << 1); // 00 0000 0000 0000 0010 Fill
    }
    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 0 && ypos <= 30))
    {
        inputBtnFlag = (1 << 2); // 00 0000 0000 0000 0100 Line
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 35 && ypos <= 65))
    {
        inputBtnFlag = (1 << 3); // 00 0000 0000 0000 1000 Rectangle
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 70 && ypos <= 100))
    {
        inputBtnFlag = (1 << 4); // 00 0000 0000 0001 0000 Oval
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 105 && ypos <= 135))
    {
        inputBtnFlag = (1 << 5); // 00 0000 0000 0010 0000 Free Draw
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 140 && ypos <= 170))
    {
        inputBtnFlag = (1 << 6); // 00 0000 0000 0100 0000 Select
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 175 && ypos <= 205))
    {
        inputBtnFlag = (1 << 7); // 00 0000 0000 1000 0000 Erase
    }

    else if ((xpos >= 0 && xpos <= 50) && (ypos >= 210 && ypos <= 240))
    {
        inputBtnFlag = (1 << 8); // 00 0000 0001 0000 0000 Clear
    }

    else if ((xpos >= 272 && xpos <= 295) && (ypos >= 0 && ypos <= 42))
    {
        inputBtnFlag = (1 << 9); // 00 0000 0010 0000 0000 WhiteColor
    }

    else if ((xpos >= 297 && xpos <= 320) && (ypos >= 0 && ypos <= 42))
    {
        inputBtnFlag = (1 << 10); // 00 0000 0100 0000 0000 OrangeColor
    }

    else if ((xpos >= 272 && xpos <= 295) && (ypos >= 44 && ypos <= 86))
    {
        inputBtnFlag = (1 << 11); // 00 0000 1000 0000 0000 RedColor
    }

    else if ((xpos >= 297 && xpos <= 320) && (ypos >= 44 && ypos <= 86))
    {
        inputBtnFlag = (1 << 12); // 00 0001 0000 0000 0000 GreenColor
    }

    else if ((xpos >= 272 && xpos <= 295) && (ypos >= 88 && ypos <= 130))
    {
        inputBtnFlag = (1 << 13); // 00 0010 0000 0000 0000 YellowColor
    }

    else if ((xpos >= 297 && xpos <= 320) && (ypos >= 88 && ypos <= 130))
    {
        inputBtnFlag = (1 << 14); // 00 0100 0000 0000 0000 NavyColor
    }

    else if ((xpos >= 272 && xpos <= 295) && (ypos >= 132 && ypos <= 174))
    {
        inputBtnFlag = (1 << 15); // 00 1000 0000 0000 0000 BlueColor
    }

    else if ((xpos >= 297 && xpos <= 320) && (ypos >= 132 && ypos <= 174))
    {
        inputBtnFlag = (1 << 16); // 00 0000 0100 0000 0000 BlackColor
    }

    else if ((xpos >= 60 && xpos <= 260) && (ypos >= 10 && ypos <= 230))
    {
        inputBtnFlag = (1 << 17); // 10 0000 0000 0000 0000 DrawScreen
    }

    return inputBtnFlag;
}

void SensingTouch(TLCD tlcdInfo)
{
    int x, y, pressure;
    int xpos, ypos, ret;

    read(tlcdInfo.fd, &ie, sizeof(struct input_event));

    if (ie.type == 3)
    {
        if (ie.code == 0)
        {
            x = ie.value;
        }
        else if (ie.code == 1)
        {
            y = ie.value;
        }
        else if (ie.code == 24)
        {
            pressure = ie.value;
        }
    }

    // 보정을 넣은 lcd상의 x , y의 포지션
    xpos = a * x + b * y + c;
    ypos = d * x + e * y + f;

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
            printf("TODO LINE\n");
            break;
        // TODO RECTANGLE
        case TOUCH_RECT:
            printf("TODO RECTANGLE\n");
            break;
        // TODO Oval
        case TOUCH_OVAL:
            printf("TODO Oval\n");
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