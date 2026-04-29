// Room: /class/qingcheng/shanlu.c

inherit ROOM;

void create()
{
	set("short", "[35m山路[2;37;0m");
	set("long", @LONG
你来到了青城山脚下。山路一直往南通去，这里离青城著名的松风观
虽然还有一定距离，但你已经能感受到它那独特的武术名家的气氛了。山
路两旁的树木长得非常的郁郁葱葱，使人一眼看不透。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"southup" : __DIR__"shanlu2",
            "east" : __DIR__"dujianyan",
]));

	setup();
	replace_program(ROOM);
}
