#include "draw.h"
#include "ui.h"

/*
 * This is Base Code for Making Rectangle Made by T.H Kim
 * Make start x , y -> end x , y Rectange 
 * �ʿ��ѱ��  -> �Է¹��� ���� ó�� ���� ���ϰ�� start x, y�� ����
 *             -> �ƴҰ�� end�� x,y��ǥ�� ����Ͽ� �����Ͽ��ݴϴ�.
 *             -> ���������� ������ �׷��� Box�� �����ݴϴ� (�����ҋ� �����ָ� �ɵ�?)
 *             -> ( �� ����� �ٽ����� ) 
 */
void DrawRectangle(TLCD tlcdInfo, Shape shape)
{
    int i, tmp, offset;

    if (shape.start.x > shape.end.x)
    {
        tmp = shape.start.x;
        shape.start.x = shape.end.x;
        shape.end.x = tmp;
    }

    if (shape.start.y > shape.end.y)
    {
        tmp = shape.start.y;
        shape.start.y = shape.end.y;
        shape.end.y = tmp;
    }

    for (i = shape.start.x; i < shape.end.x; i++)
    {
        offset = shape.start.y * 320 + i;
        *(tlcdInfo.pfbdata + offset) = shape.outColor;
        offset = shape.end.y * 320 + i;
        *(tlcdInfo.pfbdata + offset) = shape.outColor;
    }

    for (i = shape.start.y; i < shape.end.y; i++)
    {
        offset = i * 320 + shape.start.x;
        *(tlcdInfo.pfbdata + offset) = shape.outColor;
        offset = i * 320 + shape.end.x;
        *(tlcdInfo.pfbdata + offset) = shape.outColor;
    }
}


/*
 * This is Base Code for Making Rectangle Made by D.S Kim
 * Make start x , y -> end x , y Rectange
 * �ʿ��ѱ��  -> �Է¹��� ���� ó�� ���� ���ϰ�� start x, y�� ����
 *             -> �ƴҰ�� end�� x,y��ǥ�� ����Ͽ� �����Ͽ��ݴϴ�.
 *             -> ���������� ������ �׷��� Line�� ��ǥ�� Ư���Ͽ� �����ݴϴ� (�����ҋ� �����ָ� �ɵ�?)
 *             -> ( �� ����� �ٽ����� )
 */
void DrawLine(TLCD tlcdInfo, Shape shape)
{
    /* TODO: Draw line */
}

/*
 * This is Base Code for Making Rectangle Made by D.E Kime
 * Make start x , y -> end x , y Rectange
 * �ʿ��ѱ��  -> �Է¹��� ���� ó�� ���� ���ϰ�� start x, y�� ����
 *             -> �ƴҰ�� end�� x,y��ǥ�� ����Ͽ� �����Ͽ��ݴϴ�.
 *             -> ���������� ������ �׷��� Oval�� �����ݴϴ� (�����ҋ� �����ָ� �ɵ�?)
 *             -> ( �� ����� �ٽ����� )
 */
void DrawOval(TLCD tlcdInfo, Shape shape)
{
    /* TODO: Draw Oval */
}