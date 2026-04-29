//by tlang
//97.12
//tieshui.c

#include <ansi.h>
inherit NPC;
int dest();

void create()
{
	set_name(RED"铁水"NOR, ({"tie shui", "monk"}) );
	set("long", "一条彪形大汉，全身肌肉突起，钢铁一样。\n");
	set("per", 10);
	set("int", 20);
	set("str", 50);
	set("gender", "男性");
	set("age", 40);
	set("combat_exp", 500000+random(200000));
	set("max_force", 1500);
	set("force", 1500);
	set("force_factor", 100);
	
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("strike", 100);
	set_skill("force", 100);
	set_skill("shaolin-shenfa",80);
	set_skill("banruo-zhang", 120);
	set_skill("hunyuan-yiqi", 100);
	set_skill("fumo-jian", 65);
	map_skill("force","hunyuan-yiqi");
	map_skill("dodge","shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("sword", "fumo-jian");			
	
	add_money("gold", 1);
	setup();
       set("duanyu",1);
	carry_object("d/suzhou/npc/obj/cloth")->wear();
	carry_object("/d/suzhou/npc/obj/gangjian")->wield();
	carry_object("/d/hangzhou/npc/obj/fuzhu");
}
	
void init()
{
	add_action("do_talk", "talk");
}

int do_talk(string arg)
{
	object me, obj1, obj2, obj3;
	me=this_player();
	obj1=this_object();
		
    if( !query("duanyu") )
    {
                write("今天已经有人来过了,明天吧.\n");
                   return 1;
     }


	if( arg!=obj1->query("id") || !me->query("mark/goon") || me->query("marks/save_duan")>=3 
|| !present("biyu dao", me) )
		return notify_fail("铁水颇有深意地看了你一眼。\n");  
	if( me->query("duan/cant_save") )
	{
		command("say 没什么事请不要到这儿来！\n");
			return 1;	
	}
	if( me->query_temp("marks/talked") )
	{
		command("heng "+me->query("id"));
		kill_ob(me);
		me->delete_temp("marks/talked");
		return 1;
	}
	obj2=new("/d/hangzhou/npc/duan2");
	obj3=new("/d/hangzhou/npc/hylai2");
	obj2->move("/d/hangzhou/temple");
	obj3->move("/d/hangzhou/temple");
	obj1->kill_ob(obj2);
	obj3->kill_ob(obj2);
      delete("duanyu");
	tell_object(me,"铁水狞笑两声，只见梁上落下两个人，铁水从上去对着一\n"
"个就下杀手。\n");
	me->set_temp("marks/talked",1);
		return 1;
}

void die()
{
        object ob, player,me,killer;
	me=this_object();
//	ob=new("/d/hangzhou/npc/obj/fuzhu");
//	ob->move(environment(this_object()));
        message_vision("$N凄惨地叫了一声，死了！\n", this_object());
        if( objectp(killer = query_temp("last_damage_from")) ) 
	{
		killer->set_temp("duan/kill_tieshui",1);
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, me);
        }
//	me->die();
	destruct(me);
}
