//oldtiger.c
//modified by tlang

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"吊睛白额大虫"NOR, ({ "old tiger", "tiger" }) );
        set("race", "野兽");
        set("age", 50);
        set("long", @LONG
这是一修炼多年的吊睛白额大虫，金黄的毛皮上有着黑褐色的斑纹，额头上一片
白绒隐约有一斗大的王字，湛蓝色的眼睛向斜上方吊起，眼中散发着凶猛的光芒。
LONG
);

        set("attitude", "heroism");

        set("kee", 2000);
        set("max_kee", 2000);
                
        set("gin", 1000);
        set("max_gin", 1000);
        set("sen", 1000);
	set("max_sen", 1000);
        
        set("combat_exp", 1000000);
        set("limbs", ({ "头部", "身体", "尾巴","前脚", "後脚"}) );
        set("verbs", ({ "bite","claw" }) );
	set("str",40);
	set("cor",30);
	set("corpse_ob", "/d/hua/obj/dead_tiger");
	set("chat_chance", 80);
	set("chat_msg_combat", ({
		"老虎一声长啸向你扑来!\n",
		"老虎尾巴猛的一甩，向鞭子一样啪啪作响!\n",
	}));
	set("marks/虎皮", 1);
	set_skill("dodge",100);
	set_skill("unarmed",100);        
        set_temp("apply/attack", 80);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 20);
        setup();
}

// added for hubiao by tlang
void init()
{
	remove_call_out("greeting");
	call_out("greeting",1,this_player());
}

void greeting(object me)
{            
	object ob=this_object();

	if( !me || environment(me) != environment()
 || !me->query("test2") ) return;
	command("?");
	ob->set_leader(me);
	call_out("hate",1);
}

void hate()
{
	object me=this_player();
	object ob=this_object();

	if( !present("flag",me) ) 
	{
	command("hehe");
	ob->kill_ob(me);
	} else {
	call_out("dest",5);
	}
}

void dest()
{
	command("say 看在镖旗主人的面子上，这次就算了。我去也！\n");
	destruct(this_object());
}
			