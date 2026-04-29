//lindy.c
//by tlang
#include <ansi.h>
inherit NPC;
int dest();

void create()
{
	set_name(MAG"林黛玉"NOR, ({ "lin daiyu","lin" }) );
	set("long", "A beautiful girl who cant be found in our world.\n");
	set("gender","女性");
	set("age", 18);
	set("per", 35);
	set("int", 35);
	set("combat_exp", 1000000+random(500000));
	set("shen_type",1);
	set("title","绛珠仙子");
	set("respect_rank","仙子");
	set("inquiry", ([
	"baoyu" : "I cant see him now,i must go back heaven.\n",
	]));

	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("finger", 150);
	set_skill("xiaoyaoyou", 120);
	set_skill("nianhua-zhi", 120);

	map_skill("dodge","xiaoyaoyou");
	map_skill("finger","nianhua-zhi");
	prepare_skill("finger","nianhua-zhi");

	setup();
	carry_object("/d/suzhou/npc/obj/cloth2")->wear();
	call_out("dest",60);
}

void init()
{
	add_action("do_talk","talk");
}

int do_talk(string arg)
{
	object me,ob,env;
	int my_exp;
	me=this_player();
	ob=this_object();
	env=environment(me);
	my_exp=me->query("combat_exp");
	
	if(!arg || arg!="lin daiyu")
		return notify_fail("Lin daiyu looks at you puzzledly.\n");
	else 
	{
	if(!me->query("helper"))
		return notify_fail("You talk to lin daiyu,but she ingore you.\n");
	tell_room(env,"Lin tells "+RANK_D->query_respect(me)+"something and disappeared.\n");
	if(me->query("lindaiyu"))
	{
	tell_object(me,"You have save me once.This time i will give you some exp.\n");
	me->add("combat_exp",my_exp*1/1000);
	destruct(ob);
	} else {
	if(me->query("shen")>=500000)
	{
	tell_object(me,"You are a good person,i can change you borns.\n");
	me->add("max_gin",1);
	me->add("max_kee",1);
	me->add("max_sen",1);
	me->add("potential",500);
	me->add("shen",10000);
	me->add("combat_exp",my_exp*1/1000);
	me->delete("helper");
	me->set("lindaiyu",1);
	destruct(ob);
	}
	if(me->query("shen")<500000)
	{
	tell_object(me,"You saved my life.And i will teach you some skills.\n");
	me->add("potential",500);
	me->add("combat_exp",my_exp*1/2000);
	me->set_skill("literate",150);
	me->add("shen",10000);
	me->delete("helper");
	destruct(ob);
	} 
		return 1;
	}
		return 1;
	}
}

int dest()
{
	command("say 我得走了。\n");
	destruct(this_object());
}
