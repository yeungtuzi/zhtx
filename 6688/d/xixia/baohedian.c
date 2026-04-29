// Room: /d/xixia/baohedian.c

inherit ROOM;

void create()
{
	set("short", "保和殿");
	set("long", @LONG
这是一座重檐歇山式建筑，为宴请王公大臣的所在。今天
皇上招拿驸马，也是在这里宴请来自四方的贵客嘉宾。不过现
在宴席已散，看来你来晚了。往北经乾清门通向后宫，那里可
不是一般人可以去的哟！
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhonghedian",
]));

	setup();
	replace_program(ROOM);
}
