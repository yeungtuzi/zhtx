inherit NPC;
#include <ansi.h>;
string name1,name2;

void create()
{
	set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
	set("combat_exp",60000);
        set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_kee", 800);
	set("max_gin", 800);
	set("max_force", 800);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);

	set("no_get",1);

	setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/changjian")->wield();
}


void init()
{
        ::init();	
        add_action("do_bihua", "bihua");
        add_action("do_halt", "halt");

}

int do_bihua(string arg)
{     
	object ob1, ob2;
        object old_target;

	ob1 = this_player();
        
	if( !arg || arg=="" ) return 0;  

	if ( this_object()->query_temp("busy") ) 
		return notify_fail("每次只能有两人参加比武。\n");

        if (!ob2 = present(arg,environment(ob1)) ) 
		return notify_fail("你想跟谁比划？\n");
	if( !userp(ob2)) return notify_fail("你只能跟玩家比武。\n");
        if (ob1 == ob2)    return notify_fail("你不能攻击自己。\n");


	if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
		message_vision("\n$N对着$n说道��" 
			+ RANK_D->query_self(ob1) 
			+ ob1->name() + "��领教"
			+ RANK_D->query_respect(ob2) + "的高招。\n\n", ob1, ob2);
		if( objectp(old_target = ob1->query_temp("pending/fight")) )
			tell_object(old_target, YEL + ob1->name() + "取消了和你比试的念头。\n" NOR);
		ob1->set_temp("pending/fight", ob2);
		tell_object(ob2, YEL "如果你愿意和对方进行比试��请你也对" + ob1->name() + "("+(string)ob1->query("id")+")"+ "下一次 bihua 指令。\n" NOR);

		write(YEL "由於对方是由玩家控制的人物��你必须等对方同意才能进行比试。\n" NOR);
		return 1;
	}

	this_object()->set_temp("busy",1);
	command("chat " + ob1->query("name") 
		+ "与" + ob2->query("name") + "，现在泰山绝顶上开始比武论剑！\n");
	remove_call_out("check");
	call_out("check",1,ob1,ob2);

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");
	ob1->delete_temp("be_defeated");
	ob2->delete_temp("be_defeated");

	name1=ob1->query("name");
	name2=ob2->query("name");

	ob1->bihua_ob(ob2);
	ob2->bihua_ob(ob1);

	return 1;
}

int check(object ob1,object ob2)
{
	if(!objectp(ob1) && !objectp(ob2) )
	{
		command("chat  "+name1+"和"+name2+"双双退线，比赛被迫终止。");
		this_object()->delete_temp("busy");
		return 1;
	}

	if(!objectp(ob1))
	{
		command("chat " + name1 + "退线了！\n");
		this_object()->delete_temp("busy");
        	ob2->delete_temp("pending/fight");
		return 1;
	}

	if(!objectp(ob2))
	{
		command("chat " + name2 + "退线了！\n");
		this_object()->delete_temp("busy");
        	ob1->delete_temp("pending/fight");
		return 1;
	}

	if( (ob1->is_killing() || ob1->is_fighting()) 
	&& (ob2->is_killing() || ob2->is_fighting())
	&& present(ob1,environment()) && present(ob2,environment()) )
	{
		call_out("check",1,ob1,ob2);
		return 1;
	}

	this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

	if ( !present(ob1, environment()) ) 
	{
		command("chat " + ob1->query("name") + "落荒而逃了！\n");
		return 1;
	}

	if ( !present(ob2, environment()) ) 
	{
		command("chat " + ob2->query("name") + "落荒而逃了！\n");
		return 1;
	}
           
        if (ob1->query_temp("halted"))
         {
	       ob1->delete_temp("halted");
               command("chat " + ob1->query("name") + 
                       "中途放弃比武！\n");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("chat " + ob2->query("name") + 
                       "中途放弃比武！\n");
                return 1;
         }

	if (ob2->query_temp("be_defeated")) 
	{
		command("chat " + ob1->query("name") 
			+ "比武战胜" + ob2->query("name") + "！\n");
		ob2->delete_temp("be_defeated");
		return 1;
	}
	if ( ob1->query_temp("be_defeated") )
	{
		command("chat " + ob2->query("name") 
			+ "比武战胜" + ob1->query("name") + "！\n");
		ob1->delete_temp("be_defeated");
		return 1;
	}
	
	return 1;
}

int do_halt()
{
	object me = this_player();
	if (me->is_fighting() || me->is_killing())
	{
		me->set_temp("halted",1);
		me->remove_all_killer();
		message_vision("$N向後一跃，离开战圈罢手不斗了。\n", me);
	}
	return 1;
}
