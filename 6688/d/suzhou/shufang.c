//by tlang

#include <ansi.h>
inherit ROOM;
inherit F_SAVE;

string do_look();

/*mapping story_name=([
	"cloud" : "/d/cloud/gstart",
	"qingcheng"  : "/d/qingcheng/gstart",
]);

mapping time=([
		"cloud" : 4,
		"qingcheng"  : 3,
]);
*/                          
void create()
{
	set("short", "书房");
        set("long", 
"   这是一个宽敞的房间，右边有个窗户，左边靠墙是一溜书架。\n"
"书架上放着一系列的书，你走近一看：哇！...是各位大虾的传记\n"
"靠窗边有一排桌子和凳子，你可以在这里休息一下,看看书(read).\n"
"旁边有书本的清单(list)。\n");
      	set("exits", ([
                "west" : __DIR__"ymzting",
      	]));

	set("item_desc",([
	"list" : (: do_look :),
	]));

	setup();
}

string do_look()
{
/*	string *story,str;
	object who=this_player();
	int i;

	story=keys(story_name);
	i=sizeof(story);
	write("现有以下故事可读:\n\n");
	while(i--)
	{
		str=sprintf("%12s   写于:%4d秒\n",story[i],time[story[i]]*5);
		tell_object(who,str);
	}
*/	return "";
}
/*
void init()
{
	add_action("do_read", "read");
	add_action("do_discard","discard");
}

int do_read(string arg)
{
	int num;
	mapping *notes, last_read_time;
	string myid;

	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("书架上目前没有任何故事可读。\n");

	if( !arg ) return notify_fail("指令格式：read <故事编号>|new|next\n");
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
			
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("你要读第几个故事？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这个故事。\n");
	num--;
	this_player()->start_more( sprintf(
"[%d] %-40s %s(%s)\n----------------------------------------------------------------------\n",
		num + 1, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
		+ notes[num]["msg"] );

	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	return 1;
}


int do_discard(string arg)
{
	mapping *notes;
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：discard <故事编号>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("没有这个故事。\n");
	num--;
	if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
		return notify_fail("只有天神才有权利毁灭故事。\n");
	notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	set("notes", notes);
	save();
	write("毁灭第 " + (num+1) + " 号故事....Ok。\n");
		return 1;
}

*/