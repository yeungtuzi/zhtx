// Room: /d/xueshan/myhell.c
//by tlang for 混世神剑

#include <ansi.h>
#include <room.h>

inherit ROOM;

int valid_leave(object ob,string dir);

void create()
{
	set("short", MAG"金龙洞"NOR);
	set("long", "这儿挺阴森的，有一股水流，水流很急，你耳边全是水声，只能仿佛看到几个
通向外边的出口。\n");

	set("exits",([
	"down" : "/d/xueshan/lou2",
	"east" : "/d/xueshan/myhell1",
	"south" : "/d/xueshan/myhell3",
	"west" : "/d/xueshan/myhell4",
	"north" : "/d/xueshan/myhell5",
	"up" : "/d/xueshan/myhell2",
	]));
	    
    	setup();
}



int valid_leave(object who, string dir)
{
	if(dir=="up" && !who->query("can_pass2") )
		return notify_fail("一种神秘的力量阻止了你。\n");
	if(dir=="down" && who->query("can_pass1") )
	{
		tell_object(who,"你放弃了这次机会。\n");
		who->delete("can_pass1");
			return 1;
	}
	return 1;	
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
