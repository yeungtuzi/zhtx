//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW"露露"NOR, ({ "lu lu","lucy"}) );
	set("gender", "女性" );
	set("age", 18);
        set("long","她看上去有许多心事。也许你和她说说话，能帮助她一些。\n");
	set("per",29);
	set("int",25);

	set("combat_exp", random(2500)); 
	set("attitude", "friendly");
	set("rank_info/respect", "美女");
		
	setup();
	carry_object(__DIR__"obj/girth.c")->wear(); 
}

void init()
{
	add_action("give_talk","talk");
}

int give_talk(string arg)
{
	object me=this_object();
	object ob=this_player();

	if(!arg || arg!=me->query("id"))
	{
		tell_object(ob,"你要和谁说话？\n");
		return 1;
	}	
	if(!ob->query_temp("save_lucy/braver") )
	{
		tell_object(ob,"你怎么可能到这儿来？\n");
		return 1;
	}
	ob->set_temp("save_lucy/success",1);
	ob->delete_temp("save_lucy/braver");
	tell_object(ob,"你告诉露露张骥后悔了，想来找她。\n\n露露本来伤心的脸上露出了灿烂的笑容。\n");
	command("say 请你告诉他到这儿来。。。。。。\n");
		return 1;
}
