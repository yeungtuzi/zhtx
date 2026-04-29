//hostress
//by tlang with /class/guard/npc/xiaolin.c

#include <ansi.h>
#include <localtime.h>

#define TIME_TICK (time()*60)    

inherit NPC;

void heal();
void check();
void checking();
int making();
int accept_object(object,object); 

void create()
{
	set_name(GRN"雪儿"NOR, ({ "xue er", "xue"}) );
	set("gender", "女性" );
	set("age", 18);
        set("long",
		"她是天下文明的烹调高手，据说出师于杭州三雅园。\n");
	set("combat_exp", 2999999);
	set("attitude", "peacefully");
	set("per", 30);
	set("int", 30);
	set("con", 30);
	set("str", 20);
	set("cps", 30);
	     
	set("max_kee", 3000);
	set("kee", 3000);   
	set("max_atman",3000);
	set("atman",3000);
	set("max_force", 3000);
	set("force", 5000);
	set("force_factor", 200);
	set("max_mana",3000);
	set("mana",5000);
	set("mana_factor", 50);
	
	set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));	

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "invocation" :),
                (: command("cast animate on corpse") :),
                (: command("cast animate on corpse") :),
        }) );
		
	set_skill("iron-cloth", 200);
	set_skill("dodge", 220);
	set_skill("unarmed", 200);
	set_skill("spells",200);
	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("taoism", 220);
        set_skill("necromancy", 200);
	map_skill("force", "taiji-shengong");
	map_skill("spells","necromancy");

	setup();
	carry_object("/d/suzhou/npc/obj/cloth2.c")->wear();
	call_out("check",1);
}  

void check()
{
	if( NATURE_D->game_time()!=GTIME_D->chinese_date(TIME_TICK))
		{
			command("say 时间还没有到啊。\n");
			call_out("check",120);
			command("say "+NATURE_D->game_time()+"距"
				+GTIME_D->chinese_date(TIME_TICK)+
				"，有一段时间差呢。\n");
					return;
		}
	command("say 他们也该回来过节了吧。\n"); 
	call_out("checking",10);	
}

void checking()
{
	object *ob;
        int i,obage;

	ob = users();
	command("say 欢迎大家回来过节。\n");
	command("say 你们先进去，呆会儿我来给大家做菜。\n");
	for(i=0; i<sizeof(ob); i++) {
	        if( !ob[i] || environment(ob[i]) != environment() ) continue;
       		obage=ob[i]->query("age");
		if( obage<=20 ) {
		ob[i]->move("/class/guard/yard1.c");
		call_out("making",5);
			return;	
		}
		if(obage>20 && obage<=30) {
		ob[i]->move("/class/guard/yard2.c");
		call_out("making",5);
			return;	
		}
		if(obage>30) {
		ob[i]->move("/class/guard/yard3.c");
		call_out("making",5);
			return;
		}
	}
}

int making()
{
	object obj1,obj2,obj3;
	
	command("smile");
	obj1=new("/class/guard/npc/host2.c");
	obj1->move("/class/guard/yard1.c");
	obj2=new("/class/guard/npc/host2.c");
	obj2->move("/class/guard/yard2.c");
	obj3=new("/class/guard/npc/host2.c");
	obj3->move("/class/guard/yard3.c");
	call_out("check",1000);
}                 

int accept_object(object who, object what)
{                              
        command("say 是你给我东东吗？谢谢了。");
        command("thank " + who->query("id") );
        destruct(what);
	        return 1;
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
                command("enforce 20");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}
