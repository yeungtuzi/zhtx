// /d/xizang/xueshan0.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
从这里往西,山势越行越高,气候也越来越冷,远远望去,山顶上积满了白雪,正是
由川入藏必经的大雪山.从这里向东北是通往成都的山路,南边有条小路绕山而行,据
说可以通到雪山寺.
LONG
        );
        set("exits", ([
                "east" : "/d/road/jsdukoux",
                "westup"    : __DIR__"xueshan1",
                "south"     : __DIR__"class/snow_mnt/s_road",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
