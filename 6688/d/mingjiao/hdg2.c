
inherit ROOM;

void create()
{
        set("short", "凉亭");
        set("long", @LONG
	峰回路转之间，你来到了一座小小的凉亭，此时清风拂面，亭外水声潺潺。
使人胸襟为之一畅。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"hdg4",
  "west" : __DIR__"hdg1",
  "north": __DIR__"hdg3",
]));
        set("outdoors", "mingjiao");
//        set("objects", ([
//                __DIR__"npc/jintong" : 1,
//        ]) );

        setup();
        replace_program(ROOM);
}

