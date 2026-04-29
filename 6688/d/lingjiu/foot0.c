// Room: /d/lingjiu/foot0.c

inherit ROOM;

void create()
{
	set("short", "天山南麓");
	set("long", @LONG
这里是一望无际的大草原，草原上绿草连天，牛羊成群。你看到三三
两两牧人，骑着骏马，一边驱赶着牧群，一边放歌高吭。看他们逍遥
快活的样子，你不由想起近来武林中的腥风血雨。唉！一入江湖，身
由己！你开始羡慕起他们的生活！往北你看到一座高峰，高耸云天。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"pm_foot",
  "southeast" : "/d/road/rqhhtokl3", 
]));
	set("no_clean_up", 0);
	set("outdoors", "lingjiu");

	setup();
	replace_program(ROOM);
}
