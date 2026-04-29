// Room: /d/xixia/longmen.c

inherit ROOM;

void create()
{
	set("short", "龙门");
	set("long", @LONG
这里是宫廷广场的东侧，每年殿试高中的进士写入“黄榜”，张
挂在这里临时搭起的“龙棚”内，由状元领着新进士看榜。考取的进
士如“鲤鱼跳龙门”，“一举成名天下知”，所以这里称为龙门。 
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"esquare",
]));

	setup();
	replace_program(ROOM);
}
