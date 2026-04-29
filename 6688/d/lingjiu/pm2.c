// Room: /d/lingjiu/pm.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
山路到达这里，积雪越来越多，但已很少能看到绿草，相反地，地面
上涨出不少矮小的灌木，光秃秃的甚是难看。四周看不到一个人影，
偶有北风刮过，呼啸做响，情景甚是凄凉。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"pm",
  "southdown" : __DIR__"pm1",
]));
	set("object", ([
		__DIR__"npc/deer" : random(2),
		__DIR__"npc/rabbit" : random(2),
]));
	set("outdoors", "lingjiu");
	setup();
	replace_program(ROOM);
}
