// /d/xizang/class/budala/sj2.c

inherit ROOM;

void create()
{
        set("short", "诵经室");
        set("long", @LONG
这里是供僧人诵经参禅的房间.北边有个小门通往抄写佛经的房间,有许多青
年弟子在这里帮助抄经.东边的几个房间里整齐排放着布达拉宫保存的各种佛经.
到这里来请保持安静,切勿喧哗!
LONG
        );
        set("exits", ([
           "east" : __DIR__"storage1",
	   "west" : __DIR__"epath1",
	  "north" : __DIR__"copyroom",
]));
        setup();
        replace_program(ROOM);
}

