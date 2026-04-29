//RJQTING.C

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这是烈火旗的议事大厅，厅中布满了各式各样的火器、机关，掌旗使
满头大汗地在其间也不知道在忙活什么。
LONG
	);

	set("exits", ([
		"out" : __DIR__"tolhq3",
	]));

        set("objects",([
			__DIR__"npc/xinran":1,
			__DIR__"npc/zhangzhong":1,
	]));
	
	setup();

}