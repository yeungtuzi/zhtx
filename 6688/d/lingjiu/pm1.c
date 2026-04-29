// Room: /d/lingjiu/pm.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
山路渐行渐高，在这里已很少能看到行人。路两旁长着零星绿草，
上面还覆盖着未被融化的残雪，天气渐趋寒冷，看来这里的地势
已经颇高。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"pm2",
  "southdown" : __DIR__"pm_foot",
]));
	set("object", ([
		__DIR__"npc/deer" : random(2),
		__DIR__"npc/rabbit" : random(2),
]));

	set("outdoors", "lingjiu");
	setup();
	replace_program(ROOM);
}
