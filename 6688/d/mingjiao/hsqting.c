//HSQTING.C

inherit ROOM;

void create()
{
	set("short", "洪水旗大厅");
	set("long", @LONG
	这里是洪水旗的大厅，掌旗使在此处理本旗的事务。 
旁边的人是教主派来“帮助”五行旗事务的五散人之一。
LONG
	);

	set("exits", ([

		"south" : __DIR__"hsqchanglang",
	]));

        set("objects",([
		__DIR__"npc/tangyang":1,
		__DIR__"npc/lengqian":1,
	]));

	setup();

}