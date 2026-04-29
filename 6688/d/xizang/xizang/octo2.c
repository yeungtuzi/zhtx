// /d/xizang/octo2.c

inherit ROOM;

void create()
{
        set("short", "八角街");
        set("long", @LONG
这里是八角街的东南角,远离了金碧辉煌的宫殿,这里更多看到的是
平凡的民居和淳朴善良的藏民.许多年来,一直也有一些汉人迁来此地居
住,经营盐铁杂货铺子或者酒馆客栈等等.
LONG
        );
        set("exits", ([
  "north" : __DIR__"octo1",
  "west" : __DIR__"octo3",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);

}
