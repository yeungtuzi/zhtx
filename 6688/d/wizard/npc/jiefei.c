inherit NPC;
#include <ansi.h>
int clone_money(int value);

void create()
{
	int i;

        set_name("独行盗", ({ "jiefei","fei", }) );
        set("gender", "男性" );
	set("title",HIR"不要惹我,小心我杀你"NOR);

	set_max_encumbrance(10000000);

        set("age", 20+random(20));
        set("str", 25+random(15));
	set("int", 15+random(15));
	set("con", 15+random(15));
        set("dex", 15+random(15));

	set("long","这是一个凶悍的强盗，专干打家劫舍的勾当。\n");

	i=1000+random(2000);
        set("max_gin", i);
        set("eff_gin", i);
        set("gin", i);
	i=1000+random(2000);
        set("max_kee", i);
        set("eff_kee", i);
        set("kee", i);
	i=1000+random(2000);
        set("max_sen", i);
        set("eff_sen", i);
        set("sen", i);
        set("max_atman", 300);
        set("atman", 300);
	i=500+random(2500);
        set("max_force", i);
        set("force", i);
        set("force_factor", 10+random(40));
        set("max_mana", 300);
        set("mana", 300);

	set("attitude","friendly");
        set("combat_exp", 100000+random(2000000));
	set("shen_type", -1);
	set("score", 1000000);

	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "kuihua" :),
		(: exert_function, "recover" :),
        }) );
	set_skill("kuihua-shengong", 50+random(1500)/10);
	set_skill("mo-zhang-jue", 50+random(1500)/10);
	set_skill("mo-jian-jue", 50+random(1500)/10);
	set_skill("force", 50+random(1000)/10);
	set_skill("dodge", 50+random(1000)/10);
	set_skill("strike", 50+random(1000)/10);
	set_skill("parry", 50+random(1000)/10);
	set_skill("sword", 50+random(1000)/10);

	map_skill("force", "kuihua-shengong");
	map_skill("strike", "mo-zhang-jue");
	map_skill("parry", "mo-jian-jue");
	map_skill("sword", "mo-jian-jue");
	map_skill("dodge", "kuihua-shengong");

	prepare_skill("strike", "mo-zhang-jue");

	setup();

	carry_object("obj/cloth/cloth")->wear();
	carry_object("obj/weapon/gangjian")->wield();
}

void init()
{
	add_action("do_hit","hit");
}

int do_hit(string arg)
{
	object me=this_player(),obj=this_object();

	if(obj->id(arg))
	{
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
		command("say 竟敢在本大爷面前动土，我看你是不想活了。");
		me->fight_ob(obj);
		obj->kill_ob(me);
		return 1;
	}
	return 0;
}

int find_money(object ob)
{
	object *inv,obj=this_object();
	int i,value=0;

	obj->add("xunhuan_amount",1);
	if(obj->query("xunhuan_amount") > 10) return 1;

	if(ob->query("money_id")) value += ob->value();

	inv=all_inventory(ob);
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query_max_encumbrance()) find_money(inv[i]);
		if(inv[i]->query("money_id")) value += inv[i]->value();
	}
	obj->add("all_value_of_player",value);

	if(obj->query("xunhuan_amount") > 10) return -100;
	else return obj->query("all_value_of_player");
}

int accept_object(object who, object ob)
{
	object *inv,obj=this_object();
	int i,value=0,temp;

	inv=all_inventory(environment(obj));
	for(i=0;i<sizeof(inv);i++)
	{
		if( living(inv[i]) || userp(inv[i]) ) continue;

		obj->set("xunhuan_amount",0);
		obj->set("all_value_of_player",0);
		temp = find_money(inv[i])*3/4;
		obj->set("all_value_of_player",0);
		obj->set("xunhuan_amount",0);

		if(temp==-100*3/4)
		{
			message_vision("$N拾起了地上的"+inv[i]->name()+"。\n",obj);
			destruct(inv[i]);
		}

		if(temp > 0)
		{
			value +=temp;
			message_vision("$N拾起了地上的"+inv[i]->name()+"。\n",obj);
			destruct(inv[i]);
		}
	}

	if(value >= 100)  clone_money(value);

	obj->set("xunhuan_amount",0);
	obj->set("all_value_of_player",0);
	value=find_money(who);
	obj->set("all_value_of_player",0);
	obj->set("xunhuan_amount",0);

	if(value==-100)
	{
		message_vision(HIR"$N的钱藏的太深了吧。\n"NOR,who);
		return 0;
	}
	if (ob->query("money_id") && ob->value() >= value*(50+random(50))/100 ) 
	{
		if(value < (who->query_temp("my_money")-ob->value()))
		{
			message_vision(HIR"$N对$n嘿嘿笑道：想把钱藏一部分？\n"NOR,obj,who);
			return 0;
		}
		message_vision("$N对$n一挥手说:“你可以过去了。”\n",obj,who);
		who->set_temp("can_pass",1);
		clone_money((int)(ob->value()*3/4));
		return 1;
	}
	return 0;
}

int clone_money(int value)
{
	object money;
	int gold,silver;

	gold = value/10000;
	silver = (value%10000)/100;

	if(gold > 0)
	{
		money=new("/obj/money/gold");
		money->set_amount(gold);
		money->move(this_object());
	}
	if(silver > 0)
	{
		money=new("/obj/money/silver");
		money->set_amount(silver);
		money->move(this_object());
	}
	return 1;
}