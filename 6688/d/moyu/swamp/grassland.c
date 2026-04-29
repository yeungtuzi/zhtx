// grassland.c
// by meteoric
inherit "/ldg/std/dyna_room.c";
void create()
{
	set("short", "草坪");
	set("long", @LONG
一片草坪出现在你的面前，四周灰蒙蒙的一片，你只感到两眼发疼什么也看不清
四周阴森森的，不时传来一阵阴笑，令人感到心惊胆战，你不禁深深的吸了一口
气，猛一低头发现草坪上一片血红。
LONG );
	set("objects", ([
		__DIR__"npc/black_wushi": 2+random(2),
	]));
	set("exits",   ([
		"west":"/d/moyu/swamproad2",
	]));
	setup();
}
