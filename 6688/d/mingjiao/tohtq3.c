
inherit ROOM;

void create()
{
        set("short", "秘道");
        set("long", @LONG
这是一条阴暗的地道，在黑暗之中，秘道似乎永无尽头。
LONG
        );
        set("exits", ([ 
  	"up" : __DIR__"tohtq2",
  	"south" : __DIR__"tohtq4",
	]));
        
//	set("objects", ([
//        __DIR__"npc/redbeast" : 1,
//                        ]) );


        setup();
        replace_program(ROOM);
}

