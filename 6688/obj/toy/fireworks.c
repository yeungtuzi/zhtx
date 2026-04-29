// fireworks.c
// by yeung.

#include <ansi.h>

inherit ITEM;

int show_msg(object ob1,object ob2);

void create()
{
	set_name("礼花", ({ "fireworks" }) );
	set_weight(300);
	set("unit", "个");
	set("long",
		"这是精心制作的礼花，专门在重大庆典上施放(fire)。\n"
	);
	
	set("value", 1);
	set("type", "misc");
	set("fire_msg","砰！！！砰砰！！！");
	
}

void init()
{
	add_action("do_fire", "fire");
	set("unit", "支");
}

int do_fire(string arg)
{
	object me,ob1,ob2;
	string name1,name2;
	
	me = this_player();
	
	if( query("need_args") == 2)
	{
		if( !stringp(arg) || !sscanf(arg,"%s %s",name1,name2) )
			return notify_fail("请指定你要使用的对象. fire <id> <id>\n");
		
		ob1 = present(name1,environment(me));
		ob2 = present(name2,environment(me));
		
		if( !objectp(ob1) || !objectp(ob2) )
			return notify_fail("请指定你要使用的对象. fire <id> <id>\n");
	}
	else if( query("need_args") == 1)
	{
		if( !stringp(arg) || !sscanf(arg,"%s",name1,name2) )
			return notify_fail("请指定你要使用的对象. fire <id>\n");
		
		ob1 = present(name1,environment(me));
		
		if( !objectp(ob1) )
			return notify_fail("请指定你要使用的对象. fire <id>\n");
	}
	
	message_vision("$N取出一枚礼花,点燃了药线之后急忙捂着耳朵跳了开去.\n",me);
	remove_call_out("show_msg");
	call_out("show_msg",2,ob1,ob2);
	return 1;
}

int show_msg(object ob1,object ob2)
{
	string fire_msg,name1,name2;
	
	fire_msg = query("fire_msg");

	if( query("need_args") > 0)
	{
		name1 = ob1->query("name");
		fire_msg = replace_string(fire_msg,"$N",name1);
	}	
	if( query("need_args") > 1)
	{
		name2 = ob2->query("name");
		fire_msg = replace_string(fire_msg,"$n",name2);
	}	

	fire_msg = replace_string(fire_msg,"$P",this_player()->query("name"));
	message("system",fire_msg,users());
	destruct(this_object());
	return 1;
}
