// /d/xizang/class/budala/westhall.c

inherit ROOM;

void create()
{
        set("short", "西殿");
	set("long", @LONG
这里是布达拉宫西殿,丹玛女活佛在这里讲经说法.
LONG
        );
        set("exits", ([
          "west" : __DIR__"girl",
	 "south" : __DIR__"lamp1",
	]));
	set("objects",([__DIR__"npc/danma":1,
	]));
        setup();
        replace_program(ROOM);
}
