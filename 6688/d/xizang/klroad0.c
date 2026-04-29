// /d/xizang/klroad0.c

inherit ROOM;

void create()
{
        set("short", "昆仑山路");
        set("long", @LONG
这里是一条荒草迷漫的小路, 往南延伸到西藏草原，北边据说通往昆仑山.
LONG
        );
        set("exits", ([
                "northup" : __DIR__"class/gold_wh/uroad1",
                  "south" : __DIR__"grassland0"
]));
        set("outdoors", "xizang");

        setup();
        replace_program(ROOM);
}
