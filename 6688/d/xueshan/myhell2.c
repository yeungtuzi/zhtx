// Room: /d/xueshan/myhell2.c
//by tlang for 旋芒宝剑

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", MAG"金龙洞"NOR);
	set("long", "这儿挺阴森的。\n");

	set("exits",([
	"down" : "/d/xueshan/myhell",
	]));

	set("objects",([
	"/d/xueshan/npc/goldend" :1,
	]));

	set("hidden_place",1);

   	setup();
}

void init()
{
	add_action("do_summon","summon");
}

int do_summon(string arg)
{

	write("这儿不允许使用这个命令的。\n");	
		return 1;
}