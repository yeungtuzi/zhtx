// /d/xizang/class/budala/prison.c

inherit ROOM;

void create()
{
        set("short","羁押室");
        set("long", @LONG
这里是暂时羁押擅闯宫门者的牢房.东边是守卫室.
LONG
        );
        set("exits", ([
           "east" : __DIR__"guard",
]));
        setup();
        replace_program(ROOM);
}
