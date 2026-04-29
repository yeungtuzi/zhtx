//《笑傲江湖》
//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string look_outside();
void bath_player(object ob,int stage);

string *bath_msg=({
	YEL"你飞快地拖下衣服，跳进溪水中。。。。。。\n"NOR,
	YEL"真舒服啊。。。。。\n"NOR,
	HIC"你在水里泡了一会儿，感觉精神好多了。。。。。\n"NOR,
	HIC"忽然你发现脚下踩着什么东东，于是把它扔到岸上。。。。。。\n"NOR,
	HIC"然后恋恋不舍地上岸把衣服穿好。\n"NOR,
});

void create()
{
        set("short", HIC"溪中溪"NOR);
	set("long", @LONG
	这是溪流中的溪流，让人看了喜爱不已。这儿没有别的路可走，
往外边(outside)看看，也许能想到办法出去。
LONG
        );
	set("item_desc",([
	"outside" : (: look_outside :),
	]));
	set("count",2);

        setup();
}


string look_outside()
{
	return "外面到这儿由溪水阻断，要出去看来只有游水了。\n";
}

void init()
{
	add_action("do_swim","swim");
	add_action("do_bath","bath");
}

int do_swim(string arg)
{
	object ob=this_player();

	if(!arg || arg!="outside" )
	{
		tell_object(ob,"你不知道往哪个方向游才好。\n");
		return 1;
	}
	ob->set_temp("swimming_outside",1);
	ob->set_temp("swimming_center",4);
	ob->move("/d/hangzhou/h_water");
	message_vision("$N跳进水中，往岸边游去。\n",ob);
	return 1;
}

int do_bath()
{
	object ob=this_player();

	if( query("count")<1)
		return notify_fail("你洗了一个舒服的澡。\n");
	if(ob->query_temp("bath/here") )
		return notify_fail("你一天要洗几次澡啊？！\n");
	ob->start_busy(10);
	add("count",-1);
	remove_call_out("bath_player");
	call_out("bath_player",1,ob,0);
	return 1;
}

void bath_player(object ob,int stage)
{
	object obj;

	tell_object(ob,bath_msg[stage]);
        if( ++stage < sizeof(bath_msg) )
        {
        call_out("bath_player", 3, ob, stage );
                return;
        }
	obj=new("/d/hangzhou/npc/obj/book7");
	tell_object(ob,"你拣起一看，原来是一本《笑傲江湖》。\n");
	obj->move(ob);
	ob->set_temp("bath/here",1);
       	ob->set("sen",ob->query("eff_sen"));
        ob->set("gin",ob->query("eff_gin"));
       		 return;
}