//NPC:/d/suzhou/npc/zhangf.c
//by tlang
//98.2

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(MAG"林太平"NOR, ({"lin taiping","lin"}));
	set("title", HIW"帐房"NOR);
	set("long",
	"他是镖局的帐房。武功深藏不露，让人不知道深浅。\n");

	set("gender", "男性");
	set("attitude", "heroism");
	
	set("age", 25);
	set("shen_type", 1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	set("per", 27);
	set("max_kee", 1500);
	set("max_gin", 300);
	set("max_sen", 300);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 40);
	set("combat_exp", 500000);
	set("score", 10000);
	
	set_skill("force", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("cibei-dao", 100);
	set_skill("hunyuan-yiqi", 100);
        set_skill("strike", 100);
	set_skill("sanhua-zhang", 100);

        map_skill("strike", "sanhua-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("strike", "sanhua-zhang");

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("gold", 2);
}

void init()
{
	object ob, me;
	me=this_player();

	 ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, me); 
}

void greeting(object me)
{
	object ob=this_object();
	int my_exp;
	int ob_exp;
	
	ob_exp=ob->query("combat_exp");
	my_exp=me->query("combat_exp");	
  	if( !me || environment(me) != environment() 
|| me->query("biao_ju") || my_exp*2<=ob_exp) return;
	ob->set("combat_exp",my_exp*2);
	command("heng");
}
	

/*int accept_object(object who, object ob)
{
	
	object me=this_player();
	object obj=ob;
	
        if (!userp(ob) && (string)ob->query("id")=="biao yin" )
	 {
		if(!me->query("saver"))
			return notify_fail("这不是你的任务吧？\n");
		else {
		if(!me->query("test1")) 
			return notify_fail("这不是你自己完成的吧。\n");
		destruct(ob);
		me->add("combat_exp",5000);
		me->add("potential",500);
		tell_object(me,"你完成了任务，经验和潜能都涨了。\n");
		me->delete("test1");
		me->delete("saver");
		me->set("done1",1);
            		return 1;
		}
		return 1;
	}
	return 1;
}
*/