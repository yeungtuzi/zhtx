// Room: /d/lingjiu/pm.c

inherit ROOM;

void create()
{
	set("short", "缥缈峰山腰");
	set("long", @LONG
这里已经是半山腰了，四周白雪皑皑，灌木丛生，然而却是一尘不染，
显见很少有人出没。北风在耳边呼呼响个不停，吹得人浑身发抖，牙齿
咬得咯咯乱响。雪地上不时奔出几只野兔和野鹿，偶尔也会看见凶禽猛
兽。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cliff",
  "southdown" : __DIR__"pm2",
]));
	set("objects", ([
		__DIR__"npc/deer" : random(2),
		__DIR__"npc/pig" : random(2),
]));
	set("outdoors", "lingjiu");

	setup();
	replace_program(ROOM);
}
