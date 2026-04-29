// /d/xizang/class/budala/sj1.c

inherit ROOM;

void create()
{
        set("short", "诵经室");
        set("long", @LONG
这里是供僧人诵经参禅的房间.北边有个小门通往供客人休息的禅房.西边
是高僧打坐的房间.到这里来请保持安静,切勿喧哗!
LONG
        );
        set("exits", ([
           "east" : __DIR__"wpath1",
	   "west" : __DIR__"canchan",
	  "north" : __DIR__"guest",
]));
        setup();
//        replace_program(ROOM);
}

