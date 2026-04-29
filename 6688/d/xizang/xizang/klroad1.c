// /d/xizang/klroad1.c

inherit ROOM;

void create()
{
        set("short", "昆仑山路");
        set("long", @LONG
这里是一条荒草迷漫的小路, 往南延伸到西藏草原，北边据说通往昆仑山.西
边不远就是密宗金轮派札什伦布寺.
LONG
        );
        set("exits", ([
		"northup" : "/d/road/tanggulashan",
              "southdown" : __DIR__"class/gold_wh/uroad3"
]));
        set("outdoors", "xizang");

        setup();
        replace_program(ROOM);
}
