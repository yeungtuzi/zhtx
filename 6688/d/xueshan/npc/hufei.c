//hufei.c
//by dwolf

#include <ansi.h>
inherit NPC;
string ask_xianzi();

void create()
{
	object weap;
	
        set_name(YEL"胡斐"NOR, ({"hu fei", "hu" }));
        set("title", HIW"雪山飞狐"NOR);
        set("long",
                "他是一个个子高大，相当英俊，很吸引人。\n"
        );

        set("gender", "男性");
        set("rank_info/respect", "飞狐");

        set("attitude", "heroism");
        
        set("inquiry",([
                "苗若兰"  : "她在苏州，还是个小孩子.",
		"miaoruolan" : "她在苏州，还是个小孩子.",
		"警幻仙子" : (: ask_xianzi :), 
		"fairy" : (: ask_xianzi :),
        ]));

        set("age", 30);
        set("shen_type", -1);
        set("str", 35);
        set("int", 30);
        set("con", 30);
        set("dex", 35);
	set("per", 30);
        set("max_kee", 3000);
	set("kee",3000);
        set("max_gin", 1000);
	set("gin",1000);
	set("max_sen",1000);
	set("sen",1000);
        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 300);
        set("combat_exp", 10000000+random(5000000));
	
        set_skill("force", 200);
        set_skill("unarmed", 150);
        set_skill("blade", 250);
        set_skill("dodge", 250);
	set_skill("shortsong-blade",250);
	set_skill("qidaoforce",150);
	set_skill("fall-steps",250);
     	//删去parry的设置,免得....嘿嘿
	map_skill("force","qidaoforce");
	map_skill("dodge","fall-steps");
	map_skill("blade","shortsong-blade");
 
        setup();
      	set_temp("apply/defense",200);
        carry_object(__DIR__"obj/hublade")->wield();
        carry_object(__DIR__"obj/hupi")->wear();
        if( objectp( weap = this_object()->query_temp("weapon")) )
        	bind( (:call_other,__FILE__,"hit_ob":), weap);
}

string ask_xianzi()
{
	object ob=this_player();

	if(!ob->query("marks/小霖") || !ob->query("marks/手术"))
		return "你打听这干嘛？\n";
	ob->set("marks/fairy",1);
	ob->set("marks/hufei",1);
		return  "你要见她，先得接我三招，你同意(accept)吗？\n";
}

void init()
{
	::init();
	add_action("do_accept", "accept");
}


int do_accept()
{
	object ob=this_player();
	mapping guild;
	mapping tmp_apply;

	if( !ob->query("can_speak") || !ob->query("marks/hufei")) 
		return notify_fail("不行。\n");
	tmp_apply = ob->query_temp("apply");
	write("\n胡斐点了点头，说道：很好，这是第一招....\n\n");
	command("set attack 100");
	COMBAT_D->do_attack(this_object(), ob, query_temp("weapon"));
	if( (int)ob->query("kee") < 0 || !present(ob, environment())) 
	{
		write("胡斐叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
		command("set attack 50");
		return 1;
	}
	write("\n胡斐说道：这是第二招....\n\n");
	COMBAT_D->do_attack(this_object(), ob, query_temp("weapon"));
	if( (int)ob->query("kee") < 0 || !present(ob, environment()))
	{
		write("胡斐「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
		command("set attack 50");		                
		ob->set_temp("apply",tmp_apply);					
		return 1;
	}
	write("\n胡斐说道：第三招来了....\n\n");
	COMBAT_D->do_attack(this_object(), ob, query_temp("weapon"));
	if( (int)ob->query("kee") < 0 || !present(ob, environment())) 
	{
		write("胡斐叹道：可惜，最后一招你没通过，见不到仙子了。....\n");
		command("set attack 50");				
		ob->set_temp("apply",tmp_apply);					
		return 1;
	}
	write("\n胡斐哈哈大笑，说道：我这就带你去见仙子！\n\n");        
	ob->set_temp("apply",tmp_apply);				
//	ob->delete("marks/手术");
	ob->delete("marks/小霖");
	ob->delete("marks/hufei");
	ob->set("marks/fairy",2);
	ob->move("/d/xueshan/heaven");
	command("set attack 50");			
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if(victim == me) return;
	victim->receive_wound("kee",random(damage_bonus)/2+damage_bonus/2);
	//避免耗光npc内力的方法
	me->add("force",me->query("force_factor"));
	return random(damage_bonus);
}	

