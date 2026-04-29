// Room: /d/leigu/hut1.c
#include <ansi.h>

inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
	set("short", "小屋");
	set("long", @LONG
这是一间十分简陋的小屋，也就勉强能住人吧！
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"floor",
]));
	set("objects", ([
		__DIR__"npc/servant" : 1,
                __DIR__"obj/qi-jing" : 1,
                __DIR__"obj/qu-pu" : 1,
                __DIR__"obj/tu" : 1,
]));
	set("no_fight", 1);
	set("no_faint", 1);
        set("sleep_room", 1);
        set("family", "聋哑门");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_sleep", "sleep");
}

int do_sleep()
{
	object ob = this_player();
	int i = random(10);

	if( ob->query("mark/su_chushi") == 3
	&& ob->query("mark/zhenlong") == 1 && i>4){
		tell_object(ob, "你躺在床上，脑海中回想着珍珑棋局，辗转反侧，无法入睡。\n");
		return 1;
	}
	if( ob->query("mark/su_chushi") == 3
	&& ob->query("mark/zhenlong") == 1 && i==0){
		tell_object(ob, "\n\n你脑里想着珍珑棋局，越来越困，终于迷迷糊糊地沉睡过去。。。。。。\n");
		tell_object(ob, HIC"\n\n\n\n你的眼前逐渐出现一片暗淡的灯光。\n"NOR);
		ob->move(__DIR__"hut");
		return 1;
	}
}
