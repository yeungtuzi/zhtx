//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string look_center();

void create()
{
        set("short", "山溪");
	set("long", @LONG
	这儿溪流纵横，水声叮咚，透过清澈的溪水，甚至可以看见游来
游去的鱼儿。溪流到这儿后渐渐往南平缓流去，被一块巨大无比的石头挡
住，于是分成两路，把石头包围住，妙在石头中心(center)又有一条小溪
潺潺流着，里面的溪水似乎不是从此而来，清得让人忍不住要游过小溪，
去看个究竟。
LONG
        );
        set("exits", ([
	"westup"  : __DIR__"h_river", 
	"south" : __DIR__"h_hroad",
	 ]) );
	set("item_desc",([
	"center" : (: look_center :),
	]));
	
        setup();
}

string look_center()
{
	return "从这儿到中心，似乎只有游过去。\n";
}

void init()
{
	add_action("do_swim","swim");
}

int do_swim(string arg)
{
	object ob=this_player();

	if(!arg || arg!="center" )
		return notify_fail("你跳到溪水里瞎折腾一会儿后又上来了。\n");
	ob->set_temp("swimming_center",1);
	ob->move("/d/hangzhou/h_water");
	message_vision("$N跳进水中，往中心的一个小岛游去。\n",ob);
		return 1;
}

