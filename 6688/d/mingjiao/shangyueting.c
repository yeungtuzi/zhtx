inherit ROOM;

void create()
{
        set("short", "赏月亭");
        set("long", @LONG
  这是一个精致的小亭，亭中放着一张石桌，桌旁摆着几个石墩。
LONG
        );
        set("exits", ([
		"south" : __DIR__"chitang",
		 "east" : __DIR__"yueliangmen",
	]));

        set("no_clean_up", 0);
        set("valid_startroom", 1);
	set("objects",([
                "/class/mingjiao/zhaomin":1,
        ]));
        
        setup();

}
