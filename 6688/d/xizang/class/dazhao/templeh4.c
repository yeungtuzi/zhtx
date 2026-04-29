// /d/xizang/class/dazhao/templeh4.c

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这里是大招寺内的一间禅房,是本寺弟子休息的地方.
LONG
        );
        set("exits", ([
  		"south" : __DIR__"backyard",
	]));    
	set("no_magic",1);
	set("sleep_room",1);
	set("no_faint",1);
        set("family","大招寺");	
        setup();
}


