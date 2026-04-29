//NPC:/d/suzhou/npc/daozei.c
//by tlang
//98.2

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(RED"盗贼"NOR, ({"dao zei", "daozei" }));
	set("title", HIW"一剑饮血"NOR);
	set("long",
	"他是江湖上出名的盗贼，功夫高低无人知道。\n"
	);

	set("gender", "男性");
	set("attitude", "heroism");
	
	set("age", 35);
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	set("per", 27);
	set("max_kee", 500);
	set("max_gin", 300);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 30);
	set("combat_exp", 150000);
	set("score", 1000);
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 60);
	set_skill("blade", 70);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("shaolin-shenfa", 60);
	set_skill("cibei-dao", 60);
	set_skill("hunyuan-yiqi", 60);
        set_skill("strike", 60);
	set_skill("sanhua-zhang", 60);

        map_skill("strike", "sanhua-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("strike", "sanhua-zhang");

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
	object ob, me;
	me=this_player();

	 ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, me); 
}

void greeting()
{
	object ob=this_object();
	object me=this_player();
	int my_exp;

	if( !me || environment(me) != environment() || !me->query("sender") ) 
		return;
	my_exp=me->query("combat_exp");
	ob->set("combat_exp",my_exp);
       	command("say 你的死期到了，嘿嘿。。。。。\n");
	ob->kill_ob(me);
}

void die()
{
        object ob,me;
        me=this_player();
	
	ob=new("/d/suzhou/npc/obj/jitui");
	ob->move(environment(me));
	me->set("test3",1);        
     ::die();
}
