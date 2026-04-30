//tubi.c  秃笔翁
#include <ansi.h>
inherit NPC;
int checking(object me,object ob);
void create()
{
    set_name("秃笔翁",({"tubi weng","weng"}));
    set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "弟子");
    set("gender","男性");
    set("attitude","peaceful");
    set("age",42);
    set("shen_type",-1);
    set("str",50);
    set("per",20);
    set("max_kee", 2000);
    set("force", 2000);
    set("max_force", 1000);
    set("force_factor", 100);
    set("combat_exp", 1000000);
    set_skill("force", 150);
    set_skill("tianmo-dafa", 150);
    set_skill("dodge", 150);
    set_skill("mo-shan-jue", 150);
    set_skill("parry", 150);
    set_skill("mo-gou-jue",150);
    set_skill("hook",150);
    map_skill("dodge","mo-shan-jue");
    map_skill("parry","mo-chui-jue");
    map_skill("hook","mo-gou-jue");
    map_skill("force","tianmo-dafa");     
    create_family("日月神教", 15 , "弟子");
    setup();
    carry_object(__DIR__"obj/panguanbi")->wield();
    carry_object(__DIR__"obj/panguanbi")->wield();
    carry_object("/d/huashan/obj/baishan")->wear();
}
int accept_fight(object ob)
{
	object me  = this_object();
	object you = this_player();
		
	if(!you->query("win_danqing")
	 &&!you->query("marks/打赌"))
	 {
	   command("sigh");
	   command("say 老夫生平不与人意气相争,这位"+RANK_D->query_respect(you)+"还是请回吧.");
	   return 0;	
	 }
	if(you->query("save_ren_failed"))
	{
	   command("sigh");
	   command("say 你真是自不量力,老夫没功夫陪你磨蹭.");
	   return 0;
	}
	me->set("eff_kee", me->query("max_kee"));
	me->set("kee",     me->query("max_kee"));
	me->set("sen",     me->query("max_sen"));
	me->set("force",  me->query("max_force"));
        me->set("mana",   me->query("max_mana"));
        me->set("atman",  me->query("max_atman")); 
	me->set("gin", me->query("max_gin"));
        me->set("bellicosity", 1000);
        me->set("env/wimpy",0);
        remove_call_out("checking");
	call_out("checking", 1, me, you);
	
	return 1;
}
int checking(object me, object ob)
{

	// 2026-04-30: unused variable commented out
	// object obj;
	int my_max_qi, his_max_qi;

    
	my_max_qi  = me->query("max_kee");
	his_max_qi = ob->query("max_kee");

	if (me->is_fighting()) {
		if ( (me->query("kee")*100 / my_max_qi) <= 80 )
			command("exert recover");

		call_out("checking", 1, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("kee")*100 / my_max_qi) <= 50 ) 
	{
		command("say 果然厉害！佩服佩服.");
		ob->set("win_tubi",1);
		return 1;
	}

	if (( (int)ob->query("kee")*100 / his_max_qi) < 50 ) 
	{
		command("sigh");
		command("say 这位"+RANK_D->query_respect(ob)+"还是算了吧,我梅庄人才辈出,不是以一人之力就可以打垮的.");
		ob->set("save_ren_failed",1);
		return 1;
	}

	return 1;  
}
