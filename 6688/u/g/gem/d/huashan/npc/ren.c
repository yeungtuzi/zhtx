// danqingsheng.c 任我行
#include <ansi.h>
inherit NPC;
void consider();
int checking(object me,object ob);
int escape(object me,object ob);
void create()
{
        set_name("任我行",({"ren woxing","ren","woxing"}));
        set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "教主");  
	set("nickname", HIR "天下第一" NOR);
        set("long", 	
"只见他一张长长的脸孔，脸色雪白，更无半分血色，眉目清\n"
"秀，只是脸色实在白得怕人，便如刚从坟墓中出来的僵尸一般。\n"
);
        set("gender", "男性");
        set("age", 55);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 100);
        set("int", 50);
        set("con", 56);
        set("per", 25);
        set("max_kee", 4000);
        set("max_gin", 1000);
	set("max_sen", 1000);
	set("atman", 1000);
    	set("max_atman", 1000);
    	set("mana", 1000);
    	set("max_mana", 1000);
        set("force", 12400);
        set("max_force", 2600);
        set("force_factor", 250);
        set("combat_exp", 5000000);
        set("score", 40000);
        set_temp("apply/attack",100);
        set_temp("apply/defense",100);
        set_skill("force", 200);
        set_skill("huagong-dafa", 200);
        set_skill("tianmo-dafa", 200);
        set_skill("dodge", 200);
        set_skill("mo-shan-jue", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("mo-jian-jue", 200);
        set_skill("mo-zhang-jue", 200);
        set_skill("strike", 200);
	set_skill("move",200);
        map_skill("move","mo-shan-jue");
        map_skill("strike", "mo-zhang-jue");
	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
        map_skill("parry", "mo-jian-jue");
        map_skill("sword", "mo-jian-jue");
	prepare_skill("strike", "mo-zhang-jue");
        create_family("日月神教", 14 , "教主");
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
        	(:consider:),
        	}));
        setup();
        carry_object(__DIR__"obj/wood-sword")->wield();
	carry_object("/d/huashan/obj/huishan")->wear();
        
}

void consider()
{
        object ob=this_object();

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
         {
                command("exert regenerate");
                return;
         }
         if (ob->query("sen")<ob->query("eff_gin"))
         {
         	command("exert refresh");
         	return;
       	 }
       	 return;
                
}
int accept_fight(object ob)
{
	object me  = this_object();
	object you = this_player();
		
	if(!you->query("win_danqing")
	 &&!you->query("win_tubi")
	 &&!you->query("win_heibai")
	 &&!you->query("win_huangzhong")
	 &&!you->query("marks/打赌"))
	 {
	   command("heng");
	   command("say 想跟老子打,"+RANK_D->query_rude(you)+"你还没那个资格.");
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
	me->set("force_factor",50);
        me->set("bellicosity", 1000);
        me->set("env/wimpy",0);
        remove_call_out("checking");
	call_out("checking", 1, me, you);
	remove_call_out("escape");
	call_out("escape",10,me,ob);
	return 1;
}
int checking(object me, object ob)
{

	object obj;
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
		ob->set("win_ren",1);
		return 1;
	}

	if (( (int)ob->query("kee")*100 / his_max_qi) < 50 ) 
	{
		command("sigh");
		command("say 梅庄四个家伙可真够笨的,居然还要老夫出手.");
		remove_call_out("escape");
		ob->set("save_ren_failed",1);
		return 1;
	}

	return 1;  
}

int escape(object me,object ob)
{
	
    message_vision(YEL"任我行深深地吸一囗气，真力迸发，发出一声雄狮般惊天动地的巨吼！！",me);
    tell_object(ob, "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！！n");
    me->remove_all_enemy();
    ob->remove_all_enemy();
    ob->set("save_ren_success",1);
    ob->unconcious();
    destruct(me);
    return 1;   
}