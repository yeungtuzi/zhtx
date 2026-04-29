// Room: /d/lingjiu/sleeproom.c


inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是一间打扫得非常干净的房屋，屋里并排着几张床，床上也
收拾得干干净净。每张床边有一个小桌，上面放着一些茶水和点
心。真是一个休息的好地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road3",
]));
	set("no_fight", 1);
	set("no_faint", 1);
       set("sleep_room", 1);
	set("family", "灵鹫宫");

	set("objects", ([
		__DIR__"obj/cake" : 2,
		__DIR__"obj/jtea" : 1,
	]));

	set("no_clean_up", 0);

	setup();
}
