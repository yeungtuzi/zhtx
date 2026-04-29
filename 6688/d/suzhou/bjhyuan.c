//ROOM:/d/suzhou/bjhyuan.c
//by dwolf
//97.11.4 
//modified by tlang

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_enter(string arg);
void close_gate();
int do_close(string arg);
int do_open(string arg);
int valid_leave(object ob,string dir);

string* objects = ({
        "flower",
        "stone",
});
 
void create()
{
	int i = random(sizeof(objects));

	set("short", MAG"后花园"NOR);
	set("long", @LONG
这是镖局后花园，里面有各种花草，假山，十分惹人喜欢。突然你看见一朵玫瑰，要
是把它给你的情人，那该多好啊。假山后面好象有个洞(dong)，里面好象隐藏着什么。
在花园东南尽头，有一道大门，后面是一排建筑。西边也有一排建筑。北边尽头有一
道门，一个弟子守在那儿，似乎可以打开。	
LONG
	);
	set("outdoors", "suzhou");

	set("exits", ([
		"south" : __DIR__"bjdting", 
		"northeast" : __DIR__"dzju",
		"east" : __DIR__"chufan",
		"west" : __DIR__"s_ndzju",
	]));

        set("objects", ([
	__DIR__"npc/obj/"+objects[i] : 1,
        __DIR__"npc/xxf":1                            
	]));
	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_open", "open");
}

int do_enter(string arg)
{
	object me;
	me=this_player();

	if(arg=="dong" || arg=="洞" || arg=="山洞")
	{
	if(!me->query("biao_ju"))
		return notify_fail("你不是镖局中人，怎么可以擅自闯入禁地？\n");
	me->move("/d/suzhou/hole");
	message_vision("$N身形一动，进了山洞。\n", me);
		return 1;
	} else {
	return notify_fail("你要进什么地方？\n");
	}
}


void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"s_bjhm")) )
		room = load_object(__DIR__"s_bjhm");
	if(objectp(room))
	{
		delete("exits/north");
			message("vision", "守门弟子上前把大门关了起来。\n", this_object());
		room->delete("exits/south");
		message("vision", "乒地一声，里面有人把大门关上了。\n", room);
	}
}

int do_close(string arg)
{
	if (!query("exits/north"))
		return notify_fail("大门已经是关着的了。\n");

	if (!arg || (arg != "door" && arg != "north"))
		return notify_fail("你要关什么？\n");

	message_vision("$N朝守门弟子点了点头。\n", this_player());

	remove_call_out("close_gate");
	call_out("close_gate", 2);

	return 1;
}

int do_open(string arg)
{
	object room;

	if (query("exits/north"))
		return notify_fail("大门已经是开着了。\n");

	if (!arg || (arg != "door" && arg != "north"))
		return notify_fail("你要开什么？\n");

	if(!( room = find_object(__DIR__"s_bjhm")) )
		room = load_object(__DIR__"s_bjhm");
	if(objectp(room))
	{
		set("exits/north", __DIR__"s_bjhm");
		message_vision("$N使劲把大门打了开来。\n", this_player());
		room->set("exits/south", __FILE__);
		message("vision", "吱地一声，里面有人把大门打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

int valid_leave(object ob,string dir)
{
	if(dir=="west" && ob->query("gender")!="女性" )
	{
		tell_object(ob,"你又不是女子，去那儿干嘛？\n");
			return notify_fail("你难为情地止住了脚步。\n");
	} 
		return 1;
	return ::valid_leave(ob,dir);
}
	
	

		 
