// Room: square.c
#include <ansi.h>
inherit ROOM;


void create()
{
	set("short", CYN"大广场"NOR);
	set("long", @LONG
这里是一个大广场，再往北就是皇宫了。皇宫正门前是金水桥，护城河
绕城而过。越过金水桥向北望去，紫禁城的轮廓益发显得雄伟高大。一条笔
直的大道横贯东西，十里长街果然名不虚传。西边边是一个驿站，东边是一
些民房。广场上热闹非凡，是个逍遥的好去处。
LONG
	);

	set("exits", ([
		"south" : "/d/road/jingdu",
		"north" : __DIR__"changjie2",
		"west" : __DIR__"yizhan",
//		"east" : __DIR__"minzhai",
	]));
	set("objects", ([
//		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "bj");
	setup();
	replace_program(ROOM);
}

