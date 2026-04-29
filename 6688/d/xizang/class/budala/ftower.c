// /d/xizang/class/budala/ftower.c

inherit ROOM;

void create()
{
        set("short","了望楼");
        set("long", @LONG
这里是布达拉宫门前的了望楼,守卫站在楼顶可以掌握周围情况,发
现火警及宵小活动.
LONG
        );
        set("exits", ([
           "west" : __DIR__"foregate",
             "up" : __DIR__"watch",
]));
        setup();
        replace_program(ROOM);
}
