// sheshen.c
inherit ROOM;

#define MAXNUMBER 20

string *watchroom=({
		__DIR__"kantai0",
		__DIR__"kantai1",
		__DIR__"kantai2",
		__DIR__"kantai3",
		__DIR__"kantai4",
		__DIR__"kantai5",
		__DIR__"kantai6",
		__DIR__"kantai7",
		__DIR__"kantai8",
		__DIR__"kantai9",
	});

void create()
{
        set("short", "舍身崖");
	set("long", @LONG
这是一段极窄极险的山崖，四周云雾飞绕，下面渊深无底。如不小心
，一失足掉下去，只怕连骨头都找不到。每年一次的比武大会在此举行。
一块巨石上刻着一些字迹(ziji)。边上有一些看台，中央是一个擂台。
比武的时候可以到看台上观看(watch)比武。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "eastdown" : __DIR__"canglong",
	]));

        set("item_desc", ([
                "ziji"      : @LONG
                比武大会介绍：

巫师可以召集(zhaoji)参加比武人员，然后开始正式举行(start),
并可以加入(add)比赛名额。查看(list)比武名单。
另外，也可以手工举办比武(biwu)。

玩家可以要求巫师退出(retreat)比赛,挑战的时候如果觉得水平
不行可以(halt),不管怎样都不会死。

为了比赛公平，请用大会提供(qu)的武器，若用其他武器，
巫师保留惩罚的权利。

可以取(qu)的兵器如下：

        剑(sword)       刀(blade)       鞭(whip)
        锤(hammer)      匕(dagger)      枪(spear)
        杖(staff)       棍(gun)         戟(ji)
        琴(qin)         镖(dart)
LONG

        ]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}

void init()
{
	add_action("do_watch","watch");
	add_action("do_biwu","biwu");
	add_action("do_cancel","cancel");
}

int do_biwu(string arg)
{

	if(!wizardp(this_player())) return notify_fail("你没权确认比武。\n");
	set("in_race",1);
	write("ok\n");
	return 1;
}

int do_cancel(string arg)
{

	if(!wizardp(this_player())) return notify_fail("你没权取消比武。\n");
	delete("in_race");
	write("ok\n");
	return 1;
}

int do_watch(string arg)
{
	int i=0;
	object *watcher,me=this_player();
	string str;

	if(!query("in_race")) return notify_fail("现在还没进行比武大会。\n");
	while(1)
	{
		if(!find_object(watchroom[i])) clone_object(watchroom[i]);
		watcher=all_inventory(find_object(watchroom[i]));
		watcher=filter_array( watcher, (: userp($1) :) );
		if(sizeof(watcher)<MAXNUMBER) break;
		i++;
		if(i>(sizeof(watchroom)-1))
			return notify_fail("看台不够。\n");
	}
	str=sprintf("你被分到%d号看台。\n",i);
	tell_object(me,str);
	message_vision("$N去看比赛啦。\n",me);
	me->move(find_object(watchroom[i]));
	return 1;
}
