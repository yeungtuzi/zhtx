// Room: /d/jingcheng/tamgch.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[31m广场[2;37;0m");
	set("long", @LONG
这里是京城的中心，四条大街交汇于此。巍峨高大的钟楼耸立眼前
每当清晨与傍晚，淳朴的钟声便会由此传向四面八方。这里车水马
隆，往来人潮不断。这是一个很大的广场，青石地面，常青的松柏，
营造出了一种和谐，幽雅的气氛。广场上稀稀拉拉地有几个人，北
面就是皇城了。南面是宽敞的南大街。东西两面是长安街, 东北是
驿站，不时有车出入 。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
               "/class/shaolin/tuoboseng" : 2,
//        __DIR__"npc/libai" : 1,
         "/u/m/masterall/npc/libai" : 1,
	__DIR__"npc/girl" : 2,
	"/ldg/npc/zhijizi":1,
//        "/d/jingcheng/npc/jiliang":1,
        "/u/m/masterall/npc/jiliang":1,
	"/obj/npc/paimaishi":1,
]));
	set("outdoors", "city");

	set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"xchjie5",
	"north" : __DIR__"bdj1",
	"south" : __DIR__"ndj1",
	"east" : __DIR__"dchjie1",
]));

	setup();
//	replace_program(ROOM);
}

void init()
{
	object ob;

	if(!(ob=find_living("xunbu 007")) || userp(ob) )
	{
		remove_call_out("coming");
		call_out("coming",1,0);
	}
	return;
}

void coming(int i)
{
	i++;
	new("/d/wizard/npc/xunbu")->move(this_object());
	tell_room(this_object(),HIY "一位巡捕急匆匆走来。\n"NOR);
	if(i<2) call_out("coming",200,i);
	return;
}
