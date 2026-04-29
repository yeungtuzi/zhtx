//RJQTING.C

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这是巨木旗的大厅，厅中央摆有茶几，掌旗使闻苍松正在和别人聊天。
LONG
	);

	set("exits", ([
		"out" : __DIR__"bamboo3",
		"west" : __DIR__"jmqrest",
	]));

        set("objects",([
			__DIR__"npc/wensong":1,
			__DIR__"npc/shuobude":1,
	]));
	
	setup();

}