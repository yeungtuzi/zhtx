
inherit ROOM;

void create()
{
        set("short", "幽林");
        set("long", @LONG
	竹林和花草又遮住了你的视线，蝴蝶在你的身边上下盘旋。
一位白衣小童正在浇花。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"hdg2",
  "south" : __DIR__"bridge",
]));
        set("outdoors", "mingjiao");
        set("objects", ([
                __DIR__"npc/jintong" : 1,
        ]) );

        setup();
        replace_program(ROOM);
}

